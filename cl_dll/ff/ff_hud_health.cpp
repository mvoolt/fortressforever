//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
//
// Health.cpp
//
// implementation of CHudHealth class
//
#include "cbase.h"
#include "hud.h"
#include "hud_macros.h"
#include "view.h"

#include "iclientmode.h"

#include <KeyValues.h>
#include <vgui/ISurface.h>
#include <vgui/ISystem.h>
#include <vgui_controls/AnimationController.h>

#include <vgui/ILocalize.h>

using namespace vgui;

#include "hudelement.h"
#include "hud_numericdisplay.h"

#include "ConVar.h"

#include "c_ff_player.h"
#include "ff_utils.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#define INIT_HEALTH -1

//-----------------------------------------------------------------------------
// Purpose: Health panel
//-----------------------------------------------------------------------------
class CHudHealth : public CHudElement, public CHudNumericDisplay
{
	DECLARE_CLASS_SIMPLE( CHudHealth, CHudNumericDisplay );

public:
	CHudHealth( const char *pElementName );
	virtual void Init( void );
	virtual void VidInit( void );
	virtual void Reset( void );
	virtual void OnThink();
			void MsgFunc_Damage( bf_read &msg );
	virtual void Paint();

private:
	// old variables
	int		m_iHealth;
	
	int		m_bitsDamage;
};	

DECLARE_HUDELEMENT( CHudHealth );
DECLARE_HUD_MESSAGE( CHudHealth, Damage );

//-----------------------------------------------------------------------------
// Purpose: Constructor
//-----------------------------------------------------------------------------
CHudHealth::CHudHealth( const char *pElementName ) : CHudElement( pElementName ), CHudNumericDisplay( NULL, "HudHealth" )
{
	SetHiddenBits( /*HIDEHUD_HEALTH |*/ HIDEHUD_PLAYERDEAD | HIDEHUD_NEEDSUIT );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudHealth::Init()
{
	HOOK_HUD_MESSAGE( CHudHealth, Damage );
	Reset();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudHealth::Reset()
{
	m_iHealth		= INIT_HEALTH;
	m_bitsDamage	= 0;

	SetLabelText( L"" );
	SetDisplayValue( m_iHealth );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudHealth::VidInit()
{
	Reset();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudHealth::OnThink()
{
	// Fix for ToFFPlayer( NULL ) being called.
	if( !engine->IsInGame() )
		return;

	int newHealth = 0;
	int maxHealth = 0;	

	C_FFPlayer *local = C_FFPlayer::GetLocalFFPlayer();
	if (!local)
		return;

	// Never below zero
	newHealth = max( local->GetHealth(), 0 );
	maxHealth = local->GetMaxHealth();

	// Hullucination
	if (local->m_iHallucinationIndex)
	{
		newHealth = local->m_iHallucinationIndex * 4;
	}

	// Only update the fade if we've changed health
	if ( newHealth == m_iHealth )
	{
		return;
	}

	// Get a health percentage
	bool bUnder25Perc = ( float )( ( ( float )newHealth / ( float )maxHealth ) * 100 ) < 25;

	// Play appropriate animation whether health has gone up or down
	if( newHealth > m_iHealth )
	{
		// Health went up

		if( bUnder25Perc )
		{
			g_pClientMode->GetViewportAnimationController()->StartAnimationSequence( "HealthIncreaseBelow25" );
		}
		else
		{
			if( ( ( float )( ( float )newHealth / ( float )maxHealth ) ) >= 1.0f )
				g_pClientMode->GetViewportAnimationController()->StartAnimationSequence( "HealthIncreaseAbove100" );
			else
				g_pClientMode->GetViewportAnimationController()->StartAnimationSequence( "HealthIncrease" );
		}		
	}
	else
	{
		// Health went down

		if( bUnder25Perc )
		{
			g_pClientMode->GetViewportAnimationController()->StartAnimationSequence( "HealthBelow25" );
		}
	}

	m_iHealth = newHealth;

	SetDisplayValue( m_iHealth );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudHealth::MsgFunc_Damage( bf_read &msg )
{

	int armor = msg.ReadByte();	// armor
	int damageTaken = msg.ReadByte();	// health
	long bitsDamage = msg.ReadLong(); // damage bits
	bitsDamage; // variable still sent but not used

	Vector vecFrom;

	vecFrom.x = msg.ReadBitCoord();
	vecFrom.y = msg.ReadBitCoord();
	vecFrom.z = msg.ReadBitCoord();

	// Actually took damage?
	if ( damageTaken > 0 || armor > 0 )
	{
		if ( damageTaken > 0 )
		{
			// start the animation
			g_pClientMode->GetViewportAnimationController()->StartAnimationSequence( "HealthDamageTaken" );
		}
	}
}

void CHudHealth::Paint()
{
	if( !engine->IsInGame() )
		return;

	C_FFPlayer *pPlayer = C_FFPlayer::GetLocalFFPlayer();

	if( !pPlayer )
		return;

	if( FF_IsPlayerSpec( pPlayer ) || !FF_HasPlayerPickedClass( pPlayer ) )
		return;

	BaseClass::Paint();
}