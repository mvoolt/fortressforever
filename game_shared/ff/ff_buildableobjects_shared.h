// =============== Fortress Forever ==============
// ======== A modification for Half-Life 2 =======
//
// @file ff_buildableobjects_shared.h
// @author Patrick O'Leary (Mulchman)
// @date 06/08/2005
// @brief Shared code for buildable objects
//
// REVISIONS
// ---------
// 06/08/2005, Mulchman: 
//		This file First created
// 22/01/2006, Mirv:
//		Rewritten a lot of this
//
//	05/10/2006,	Mulchman:
//		Adding radio tags to dispenser
//
// 9/16/2006, Mulchman:
//		Re-jigged the building process, hopefully it's a little better now
//
//	12/6/2007, Mulchman:
//		Added man cannon stuff

#ifndef FF_BUILDABLEOBJECTS_SHARED_H
#define FF_BUILDABLEOBJECTS_SHARED_H

#ifdef _WIN32
	#pragma once
#endif

#include "debugoverlay_shared.h"
#include "tier0/vprof.h"

#ifdef CLIENT_DLL
	#include "c_ff_player.h"
	#include "c_ff_team.h"

	#define CFFTeam C_FFTeam

	#define CFFBuildableInfo C_FFBuildableInfo
	#define CFFBuildableObject C_FFBuildableObject
	#define CFFDispenser C_FFDispenser
	#define CFFSentryGun C_FFSentryGun
	#define CFFDetpack C_FFDetpack
	#define CFFManCannon C_FFManCannon
#else
	#include "ff_player.h"
	#include "ff_team.h"
	#include "smoke_trail.h"
#endif

#define FF_DISPENSER_MODEL					"models/buildable/dispenser/dispenser.mdl"
#define FF_DISPENSER_GIB01_MODEL			"models/buildable/dispenser/gib1.mdl"
#define FF_DISPENSER_GIB02_MODEL			"models/buildable/dispenser/gib2.mdl"
#define FF_DISPENSER_GIB03_MODEL			"models/buildable/dispenser/gib3.mdl"
#define FF_DISPENSER_GIB04_MODEL			"models/buildable/dispenser/gib4.mdl"
#define FF_DISPENSER_GIB05_MODEL			"models/buildable/dispenser/gib5.mdl"
#define FF_DISPENSER_GIB06_MODEL			"models/buildable/dispenser/gib6.mdl"
#define FF_DISPENSER_BUILD_SOUND			"Dispenser.Build"
#define FF_DISPENSER_UNBUILD_SOUND			"Dispenser.unbuild"
#define FF_DISPENSER_EXPLODE_SOUND			"Dispenser.Explode"
#define FF_DISPENSER_OMNOMNOM_SOUND			"Dispenser.omnomnom"

#define FF_DETPACK_MODEL					"models/buildable/detpack/detpack.mdl"
#define FF_DETPACK_BUILD_SOUND				"Detpack.Build"
#define FF_DETPACK_EXPLODE_SOUND			"Detpack.Explode"

#define FF_SENTRYGUN_MODEL					"models/buildable/sg/sg_lvl1.mdl"
#define FF_SENTRYGUN_MODEL_LVL2				"models/buildable/sg/sg_lvl2.mdl"
#define FF_SENTRYGUN_MODEL_LVL3				"models/buildable/sg/sg_lvl3.mdl"
#define FF_SENTRYGUN_GIBTRIPOD_MODEL		"models/buildable/sg/gibs/tripod.mdl"
#define FF_SENTRYGUN_GIB1A_MODEL			"models/buildable/sg/gibs/1a.mdl"
#define FF_SENTRYGUN_GIB1B_MODEL			"models/buildable/sg/gibs/1b.mdl"
#define FF_SENTRYGUN_GIB1C_MODEL			"models/buildable/sg/gibs/1c.mdl"
#define FF_SENTRYGUN_GIB1D_MODEL			"models/buildable/sg/gibs/1d.mdl"
#define FF_SENTRYGUN_GIB2A_MODEL			"models/buildable/sg/gibs/2a.mdl"
#define FF_SENTRYGUN_GIB2B_MODEL			"models/buildable/sg/gibs/2b.mdl"
#define FF_SENTRYGUN_GIB2C_MODEL			"models/buildable/sg/gibs/2c.mdl"
#define FF_SENTRYGUN_GIB2D_MODEL			"models/buildable/sg/gibs/2d.mdl"
#define FF_SENTRYGUN_GIB3A_MODEL			"models/buildable/sg/gibs/3a.mdl"
#define FF_SENTRYGUN_GIB3B_MODEL			"models/buildable/sg/gibs/3b.mdl"
#define FF_SENTRYGUN_GIB3C_MODEL			"models/buildable/sg/gibs/3c.mdl"
#define FF_SENTRYGUN_GIB3D_MODEL			"models/buildable/sg/gibs/3d.mdl"
#define FF_SENTRYGUN_GIB3E_MODEL			"models/buildable/sg/gibs/3e.mdl"
#define FF_SENTRYGUN_BUILD_SOUND			"Sentry.One"
#define FF_SENTRYGUN_UNBUILD_SOUND			"Sentry.unbuild"
#define FF_SENTRYGUN_EXPLODE_SOUND			"Sentry.Explode"

#define FF_MANCANNON_MODEL					"models/items/jumppad/jumppad.mdl"
#define FF_MANCANNON_BUILD_SOUND			"JumpPad.Build"
#define FF_MANCANNON_EXPLODE_SOUND			"JumpPad.Explode"

//#define FF_SENTRYGUN_AIMSPHERE_MODEL		"models/buildable/sg/sentrygun_aimsphere.mdl"

#define FF_BUILDABLE_GENERIC_GIB_MODEL_01	"models/gibs/random/randGib1.mdl"
#define FF_BUILDABLE_GENERIC_GIB_MODEL_02	"models/gibs/random/randGib2.mdl"
#define FF_BUILDABLE_GENERIC_GIB_MODEL_03	"models/gibs/random/randGib3.mdl"
#define FF_BUILDABLE_GENERIC_GIB_MODEL_04	"models/gibs/random/randGib4.mdl"
#define FF_BUILDABLE_GENERIC_GIB_MODEL_05	"models/gibs/random/randGib5.mdl"

#define FF_BUILDABLE_TIMER_BUILD_STRING		"FF_Building"
#define FF_BUILDABLE_TIMER_DETPACK_STRING	"FF_Detpack_Primed"

#define FF_BUILD_NONE		0
#define FF_BUILD_DISPENSER	1
#define FF_BUILD_SENTRYGUN	2
#define FF_BUILD_DETPACK	3
#define FF_BUILD_MANCANNON	4

// The *_BUILD_DIST means how far in front of the player
// the object is built
#define FF_BUILD_DISP_BUILD_DIST	36.0f
#define FF_BUILD_SG_BUILD_DIST		64.0f //54.0f
#define FF_BUILD_DET_BUILD_DIST		42.0f
//#define FF_BUILD_DET_RAISE_VAL		48.0f
//#define FF_BUILD_DET_DUCKED_RAISE_VAL	24.0f

#define FF_BUILD_MC_BUILD_DIST		80.0f
//#define FF_BUILD_MC_RAISE_VAL		48.0f
//#define FF_BUILD_MC_DUCKED_RAISE_VAL	24.0f

#define FF_BUILD_DISP_STRING_LEN	256

// Using this value based off of the mins/maxs
#define FF_BUILD_DISP_HALF_WIDTH	12.0f

#define FF_DISPENSER_MINS	Vector( -12, -12, 0 )
#define FF_DISPENSER_MAXS	Vector( 12, 12, 48 )

#define FF_SENTRYGUN_MINS	Vector( -32, -32, 0 )
#define FF_SENTRYGUN_MAXS	Vector( 32, 32, 65 )

#define FF_DETPACK_MINS		Vector( -14, -14, 0 )
#define FF_DETPACK_MAXS		Vector( 14, 14, 11 )

//#define FF_MANCANNON_MINS	Vector( -14, -14, 0 )
//#define FF_MANCANNON_MAXS	Vector( 14, 14, 11 )
#define FF_MANCANNON_MINS	Vector( -54, -54, 0 )
#define FF_MANCANNON_MAXS	Vector( 54, 54, 48 )

#define FF_SOUND_BUILD		0	// Don't change these two values
#define FF_SOUND_EXPLODE	1

#define FF_BUILD_SABOTAGE_TIMEOUT 90.0f

#define FF_BUILDCOST_SENTRYGUN 130
#define FF_BUILDCOST_DISPENSER 30
#define FF_BUILDCOST_UPGRADE_SENTRYGUN 130
#define FF_REPAIRAMOUNTPERCELL_SENTRYGUN 3.5f
#define FF_REPAIRAMOUNTPERCELL_DISPENSER 5.0f

//Enum for the jumppad states - GreenMushy
enum JumpPadState_t
{ 
	JUMPPAD_INCOMBAT = 0, 
	JUMPPAD_IDLE 
};

enum BuildInfoResult_t
{
	BUILD_ALLOWED = 0,

	BUILD_NOROOM,			// No room, geometry/player/something in the way
	BUILD_NOPLAYER,			// Player pointer went invalid (?)
	BUILD_TOOSTEEP,			// Ground is too steep
	BUILD_TOOFAR,			// Ground is too far away
	BUILD_PLAYEROFFGROUND,	// player is not on the ground!
	BUILD_MOVEABLE,			// can't built on movable stuff
	BUILD_NEEDAMMO,			// Not Enough ammo to build
	BUILD_ALREADYBUILT,		// Already built

	BUILD_ERROR
};

class CFFBuildableInfo
{
private:
	CFFBuildableInfo( void ) {}

public:
	CFFBuildableInfo( CFFPlayer *pPlayer, int iBuildObject );
	~CFFBuildableInfo( void ) {}

	// Returns why you can/can't build
	BuildInfoResult_t BuildResult( void ) const { return m_BuildResult; }

	// Get final build position
	Vector	GetBuildOrigin( void ) const { return m_vecBuildGroundOrigin; }
	// Get final build angles
	QAngle	GetBuildAngles( void ) const { return m_angBuildGroundAngles; }

	// Tells the player why they couldn't build - sets an error message
	// and displays it
	void	GetBuildError( void );

protected:
	// Type of object we're trying to build
	int		m_iBuildObject;

	// How far out in front of the player are we building
	float	m_flBuildDist;

	// Player's info
	CFFPlayer *m_pPlayer;
	// Just some quick accessors instead of having to calculate
	// these over and over...
	Vector	m_vecPlayerForward;
	Vector	m_vecPlayerRight;
	Vector	m_vecPlayerOrigin;	// this is CFFPlayer::GetAbsOrigin() (so the waist!)

	// This is our origin/angles we mess with while building/trying to build
	Vector	m_vecBuildAirOrigin;
	QAngle	m_angBuildAirAngles;

	// Final position/angle on the ground of the object (if it can be built, of course)
	Vector	m_vecBuildGroundOrigin;
	QAngle	m_angBuildGroundAngles;

	// Stores the build result
	BuildInfoResult_t	m_BuildResult;

protected:
	// Checks if geometry or other objects are in the way of building
	bool				IsGeometryInTheWay( void );
	//bool				IsGroundTooSteep( void );
	// See's if the ground is suitable for building
	BuildInfoResult_t	CanOrientToGround( void );

};

// Forward declaration
#ifdef GAME_DLL
class CFFBuildableFlickerer;
#endif

//=============================================================================
//
//	class CFFBuildableObject / C_FFBuildableObject
//
//=============================================================================
class CFFBuildableObject : public CBaseAnimating
{
public:
	DECLARE_CLASS( CFFBuildableObject, CBaseAnimating )

#ifdef CLIENT_DLL
	DECLARE_CLIENTCLASS();
#else
	DECLARE_SERVERCLASS();
#endif

	// --> shared
	CFFBuildableObject();
	virtual ~CFFBuildableObject();
	
	virtual bool IsAlive( void ) { return true; }
	virtual bool IsPlayer( void ) const { return false; }
	virtual bool BlocksLOS( void ) { return true; }
	virtual int	BloodColor( void ) { return BLOOD_COLOR_MECH; } // |-- Mirv: Don't bleed
	virtual int	GetTeamNumber();	// |-- Mirv: Easy team id accessor	
	bool IsBuilt( void	) const { return m_bBuilt; }
 
	CNetworkHandle( CBaseEntity, m_hOwner );

	CFFPlayer *GetOwnerPlayer( void );
	CFFPlayer *GetPlayerOwner( void ) { return GetOwnerPlayer(); } // I always want to type it this way instead of the one that already exists
	CFFTeam *GetOwnerTeam( void );
	int GetOwnerTeamId( void );

	int GetHealthPercent( void ) const;
	unsigned int GetAmmoPercent( void ) const { return m_iAmmoPercent; }

protected:
	CNetworkVarForDerived( unsigned int, m_iAmmoPercent );
	// <-- shared

#ifdef CLIENT_DLL
public:
	virtual RenderGroup_t GetRenderGroup();
	virtual int  DrawModel( int flags );
	virtual void OnDataChanged( DataUpdateType_t updateType );
	virtual void ClientThink( void );

	virtual int	GetHealth( void ) const { return m_iHealth; }
	virtual int	GetMaxHealth( void ) const { return m_iMaxHealth; }

	bool CheckForOwner( void ) { return ( m_hOwner.Get() ); }		

	// Stuff for the "can't build" type glyphs
	virtual void SetClientSideOnly( bool bValue ) { m_bClientSideOnly = bValue; }
	virtual void SetBuildError( BuildInfoResult_t hValue ) { m_hBuildError = hValue; }
protected:
	bool				m_bClientSideOnly;
	BuildInfoResult_t	m_hBuildError;
	bool				m_bBuilt;
	float				m_flSabotageTime;
	int					m_iSaboteurTeamNumber;

#else
public:
	virtual void Spawn( void ); 
	virtual void Precache( void );
	
	virtual Vector BodyTarget( const Vector &posSrc, bool bNoisy = false ) { return WorldSpaceCenter(); }
	
	virtual void GoLive( void );
	virtual void Detonate( void );
	virtual void UpdateOnRemove( void );
	virtual void RemoveSaboteur( bool bSuppressNotification = false );
	virtual void RemoveQuietly( void );

	static CFFBuildableObject *AttackerInflictorBuildable(CBaseEntity *pAttacker, CBaseEntity *pInflictor);

	CHandle<CFFPlayer>	m_hSaboteur;
	CNetworkVar(float, m_flSabotageTime);
	bool				m_bMaliciouslySabotaged;
	CNetworkVar(int, m_iSaboteurTeamNumber);

	virtual bool CanSabotage() const;
	virtual bool IsSabotaged() const;
	virtual bool IsMaliciouslySabotaged() const;
	virtual void Sabotage( CFFPlayer *pSaboteur ) {};
	virtual void MaliciouslySabotage( CFFPlayer *pSaboteur ) { m_bMaliciouslySabotaged = true; m_flSabotageTime = gpGlobals->curtime + 8.0f; }
	
	virtual void Cancel( void ) 
	{
		// Stop the build sound
		StopSound( m_ppszSounds[ 0 ] );
		RemoveQuietly(); 
	}
	
	bool CheckForOwner( void )
	{
		if( !m_hOwner.Get() )
		{
			RemoveQuietly();
			return false;
		}

		return true;
	}

	virtual bool HasMalfunctioned( void ) const;

	// NOTE: Super class handles touch function
	// void OnObjectTouch( CBaseEntity *pOther );
	void OnObjectThink( void );

	virtual int OnTakeDamage( const CTakeDamageInfo &info );

	virtual void Event_Killed( const CTakeDamageInfo &info );

	virtual bool ShouldSavePhysics( void ) { return false; }
	virtual int TakeEmp( void ) { return 0; }

	// Mirv: Store in advance the ground position
	virtual void SetGroundAngles(const QAngle &ang) { m_angGroundAngles = ang; }
	virtual void SetGroundOrigin(const Vector &vec) { m_vecGroundOrigin = vec; }

	void SetLocation(const char *_loc);
	const char *GetLocation() const { return m_BuildableLocation; }
private:
	// NOTE: Don't call the CFFBuildableObject::Create function
	static CFFBuildableObject *Create( const Vector &vecOrigin, const QAngle &vecAngles, CBaseEntity *pentOwner = NULL );

public:
	// So weapons (like the railgun) don't effect building
	virtual int VPhysicsTakeDamage( const CTakeDamageInfo &info );

protected:
	void Explode( void );
	void SpawnGib( const char *szGibModel, bool bFlame = true, bool bDieGroundTouch = false );	
	virtual void SpawnGibs( void );
	void DoExplosion( void );
	virtual void DoExplosionDamage() { AssertMsg(0, "No DoExplosionDamage()"); }

	virtual void SendStatsToBot() {};
protected:

	// Flickerer - flickers to indicate us taking damage
	CFFBuildableFlickerer *m_pFlickerer;

	// Mirv: Store in advance the ground position
	QAngle m_angGroundAngles;
	Vector m_vecGroundOrigin;

	// Pointer to array of char *'s of model names
	const char **m_ppszModels;
	// Pointer to array of char *'s of gib model names
	const char **m_ppszGibModels;
	// Pointer to array of char *'s of sounds
	const char **m_ppszSounds;

	// For the explosion function

	// Explosion magnitude (int)
	int		m_iExplosionMagnitude;
	// Explosion magnitude (float)
	float	m_flExplosionMagnitude;
	// Explosion radius (float -> 3.5*magnitude)
	float	m_flExplosionRadius;
	// Explosion radius (int -> 3.5*magnitude)
	int		m_iExplosionRadius;
	// Explosion force
	float	m_flExplosionForce;
	// Explosion damage (for radius damage - same as flExplosion force)
	float	m_flExplosionDamage;
	// Explosion duration (duration of screen shaking)
	float	m_flExplosionDuration;
	// Explosion fireball scale
	int		m_iExplosionFireballScale;

	// Time (+ gpGlobals->curtime) that we will think (update network vars)
	float	m_flThinkTime;// = 0.2f;

	// Jiggles: Time between sending the "take damage" hints -- to avoid spamming
	float m_flOnTakeDamageHintTime;

	// Shockwave texture
	int		m_iShockwaveExplosionTexture;
	// Draw shockwaves
	bool	m_bShockWave;

	// Object is live and in color (not being built)
	CNetworkVar( bool, m_bBuilt );
	// Object takes damage once it is built
	bool	m_bTakesDamage;

	// Object has sounds associated with it
	bool	m_bHasSounds;

	// Whether or not the model is translucent
	// while building
	bool	m_bTranslucent;

	// If true we should be using physics
	bool	m_bUsePhysics;

	char	m_BuildableLocation[1024];

#endif

};

//=============================================================================
//
//	class CFFDetpack / C_FFDetpack
//
//=============================================================================
class CFFDetpack : public CFFBuildableObject
{
public:
	DECLARE_CLASS( CFFDetpack, CFFBuildableObject )

#ifdef CLIENT_DLL 
	
	DECLARE_CLIENTCLASS()
#else
	DECLARE_SERVERCLASS()
	DECLARE_DATADESC()
#endif

	// --> shared
	CFFDetpack( void );
	virtual ~CFFDetpack( void );

	virtual bool	BlocksLOS( void ) const { return false; }
	virtual Class_T Classify( void ) { return CLASS_DETPACK; }
	// <-- shared

#ifdef CLIENT_DLL
	virtual void OnDataChanged( DataUpdateType_t updateType );

	// Creates a client side ONLY detpack - used for the build slot
	static C_FFDetpack *CreateClientSideDetpack( const Vector& vecOrigin, const QAngle& vecAngles );	
#else
	virtual void Spawn( void );
	void GoLive( void );

	virtual void Detonate();

	virtual Vector EyePosition( void ) { return GetAbsOrigin() + Vector( 0, 0, 4.0f ); }

	void OnObjectTouch( CBaseEntity *pOther );
	void OnObjectThink( void );
	virtual int TakeEmp( void );
	virtual void DoExplosionDamage();

	static CFFDetpack *Create( const Vector &vecOrigin, const QAngle &vecAngles, CBaseEntity *pentOwner = NULL );

	int		m_iFuseTime;
	float	m_flDetonateTime;
	bool	m_bFiveSeconds;

	int	GetFuseTime()
	{
		return m_iFuseTime;
	}

	int GetDetonateTime()
	{
		return m_flDetonateTime;
	}

	bool LastFiveSeconds()
	{
		return m_bFiveSeconds;
	}

#endif

};

//=============================================================================
//
//	class CFFDispenser / C_FFDispenser
//
//=============================================================================
class CFFDispenser : public CFFBuildableObject
{
public:
	DECLARE_CLASS( CFFDispenser, CFFBuildableObject )

#ifdef CLIENT_DLL 
	DECLARE_CLIENTCLASS()
#else
	DECLARE_SERVERCLASS()
	DECLARE_DATADESC()
#endif

	// --> shared
	CFFDispenser( void );
	virtual ~CFFDispenser( void );

	virtual Class_T Classify( void ) { return CLASS_DISPENSER; }


public:
	// Network variables
	CNetworkVar( int, m_iCells );
	CNetworkVar( int, m_iShells );
	CNetworkVar( int, m_iNails );
	CNetworkVar( int, m_iRockets );
	CNetworkVar( int, m_iArmor );

	int GetCells( void ) const { return m_iCells; }
	int GetShells( void ) const { return m_iShells; }
	int GetNails ( void ) const { return m_iNails; }
	int GetRockets( void ) const { return m_iRockets; }
	int GetArmor( void ) const { return m_iArmor; }
	
	int NeedsHealth( void ) const { return m_iMaxHealth - m_iHealth; }
	int NeedsArmor( void ) const { return m_iMaxArmor - m_iArmor; }
	int NeedsCells( void ) const { return m_iMaxCells - m_iCells; }
	int NeedsShells( void ) const { return m_iMaxShells - m_iShells; }
	int NeedsNails( void ) const { return m_iMaxNails - m_iNails; }
	int NeedsRockets( void ) const { return m_iMaxRockets - m_iRockets; }

protected:
	int		m_iMaxCells;
	int		m_iGiveCells;
	int		m_iMaxShells;
	int		m_iGiveShells;
	int		m_iMaxNails;
	int		m_iGiveNails;
	int		m_iMaxRockets;
	int		m_iGiveRockets;
	int		m_iMaxArmor;
	int		m_iGiveArmor;
	// <-- shared

public:

#ifdef CLIENT_DLL 
	virtual void OnDataChanged( DataUpdateType_t updateType );

	// Creates a client side ONLY dispenser - used for build slot
	static C_FFDispenser *CreateClientSideDispenser( const Vector& vecOrigin, const QAngle& vecAngles );
#else
	virtual void Spawn( void );
	void GoLive( void );

	virtual Vector EyePosition( void ) { return GetAbsOrigin() + Vector( 0, 0, 48.0f ); }

	void OnObjectTouch( CBaseEntity *pOther );
	void OnObjectThink( void );
	virtual void Event_Killed( const CTakeDamageInfo &info );

	virtual void SpawnGibs( void );
	virtual void DoExplosionDamage();

	virtual void Sabotage(CFFPlayer *pSaboteur);
	virtual void MaliciouslySabotage(CFFPlayer *pSaboteur);
	virtual void Detonate();

    bool CloseEnoughToDismantle( CFFPlayer *pPlayer);
    void Dismantle( CFFPlayer *pPlayer);

	CNetworkVar( unsigned int, m_iAmmoPercent );

	void AddAmmo( int iArmor, int iCells, int iShells, int iNails, int iRockets );

	// Some functions for the custom dispenser text
	void SetText( const char *szCustomText ) { Q_strcpy( m_szCustomText, szCustomText ); }
	const char *GetText( void ) const { return m_szCustomText; }

	static CFFDispenser *Create( const Vector &vecOrigin, const QAngle &vecAngles, CBaseEntity *pentOwner = NULL );

	// These are for updating the user
	virtual void	PhysicsSimulate();
	float			m_flLastClientUpdate;
	int				m_iLastState;

protected:
	void SendStatsToBot( void );

	// Custom dispenser text string thing
	char		m_szCustomText[ FF_BUILD_DISP_STRING_LEN ];
	CFFPlayer	*m_pLastTouch;
	float		m_flLastTouch;

	// Actually give a player stuff
	void Dispense( CFFPlayer *pPlayer );

	// Calculates an adjustment to be made to the explosion
	// based on how much stuff is in the dispenser
	void CalcAdjExplosionVal( void );
	float	m_flOrigExplosionMagnitude;

	void UpdateAmmoPercentage( void );
#endif

};

//=============================================================================
//
//	class CFFSentryGun / C_FFSentryGun
//
//=============================================================================
class CFFSentryGun : public CFFBuildableObject
{
public:
	DECLARE_CLASS( CFFSentryGun, CFFBuildableObject )

#ifdef CLIENT_DLL 
	DECLARE_CLIENTCLASS()
#else
	DECLARE_SERVERCLASS()
	DECLARE_DATADESC()
#endif

	// --> shared
	CFFSentryGun( void );
	virtual ~CFFSentryGun( void );

	int GetRockets( void ) const  { return m_iRockets; };
	int GetShells( void ) const  { return m_iShells; };
	int GetHealth( void ) const { return m_iHealth; };

	int GetMaxRockets( void ) const  { return m_iMaxRockets; };
	int GetMaxShells( void ) const { return m_iMaxShells; };
	int GetMaxHealth( void ) const { return m_iMaxHealth; };

	int GetRocketsPercent( void ) const  { return (int) ((float) GetRockets() / (float) GetMaxRockets()) * 100.0f; };
	int GetShellsPercent( void ) const  { return (int) ((float) GetShells() / (float) GetMaxShells()) * 100.0f; };
	int GetHealthPercent( void ) const  { return (int) ((float) GetHealth() / (float) GetMaxHealth()) * 100.0f; };

	int NeedsRockets( void ) const { return GetMaxRockets() - GetRockets(); }
	int NeedsShells( void ) const { return GetMaxShells() - GetShells(); }
	int NeedsHealth( void ) const { return GetMaxHealth() - GetHealth(); }

	int GetLevel( void ) const { return m_iLevel; }
	bool Upgrade();

#ifdef GAME_DLL
	void Repair( int iCells = 0 );
	void AddAmmo( int iShells = 0, int iRockets = 0 );

	void SetLevel( int iLevel, bool bEmitSounds=true );
	void SetRockets(int iRockets) { m_iRockets = clamp( iRockets, 0, GetMaxRockets() ); RecalculateAmmoPercent(); }
	void SetShells(int iShells) { m_iShells = clamp( iShells, 0, GetMaxShells() ); RecalculateAmmoPercent(); }
	void SetHealth(int iHealth) { m_iHealth = clamp( iHealth, 0, GetMaxHealth() ); RecalculateAmmoPercent(); }
	void RecalculateAmmoPercent();
#endif

	virtual Class_T Classify( void ) { return CLASS_SENTRYGUN; }
	virtual bool	IsNPC( void ) { return true; }

public:
	// Network variables
	//CNetworkVar( float, m_flRange );
	CNetworkVar( int, m_iLevel );
	CNetworkVar( int, m_iShells );
	CNetworkVar( int, m_iRockets );

	CNetworkVar( int, m_iMaxShells );
	CNetworkVar( int, m_iMaxRockets );
	// <-- shared

#ifdef CLIENT_DLL 
	virtual void OnDataChanged( DataUpdateType_t updateType );

	// Creates a client side ONLY sentrygun - used for build slot
	static C_FFSentryGun *CreateClientSideSentryGun( const Vector& vecOrigin, const QAngle& vecAngles );

	int	m_iLocalHallucinationIndex;

	virtual int DrawModel(int flags);

	// Mulch: now this is in buildableobject to extend to disp & sg
	// Mirv: Just going to store the ammo percentage here, with the msb
	// holding the rocket state
	//unsigned int m_iAmmoPercent;
#else
	virtual void Precache( void );
	virtual void Spawn( void );
	virtual void UpdateOnRemove( void );
	void GoLive( void );

	int TakeEmp( void );

	void SetFocusPoint(Vector &origin);

	void OnObjectThink( void ); // NOTE: Not an actual think function but called during every think function
	void OnSearchThink( void );
	void OnActiveThink( void );

	CBaseEntity *HackFindEnemy( void );
	
	Vector GetVecAiming() 
	{
		Vector vecAiming;
		AngleVectors(m_angAiming, &vecAiming);
		return vecAiming;
	}
	Vector GetVecGoal()
	{
		Vector vecGoal;
		AngleVectors( m_angGoal, &vecGoal );
		return vecGoal;
	}

	float MaxYawSpeed( void ) const;
	float MaxPitchSpeed( void ) const;

	virtual void DoExplosionDamage();
	virtual void SpawnGibs( void );
	// These are for updating the user
	virtual void	PhysicsSimulate();
	float			m_flLastClientUpdate;
	int				m_iLastState;


private:
	bool IsTargetInAimingEllipse( const Vector& vecTarget ) const;
	bool IsTargetVisible( CBaseEntity *pTarget, int iSightDistance );
	bool IsTargetClassTValid( Class_T cT ) const;

public:
	CBaseEntity *GetEnemy( void	) const { return m_hEnemy; }
	void SetEnemy( CBaseEntity *hEnemy );
private:
	CHandle< CBaseEntity >	m_hEnemy;

public:
	void Shoot();
	void ShootRocket();

protected:
	void Shoot( const Vector &vecSrc, const Vector &vecDirToEnemy, bool bStrict = false );
	void ShootRocket( const Vector &vecSrc, const Vector &vecDirToEnemy, bool bStrict = false );
	void Ping( void );	
	void SpinUp( void );
	void SpinDown( void );
	bool UpdateFacing( void );

	void SendStatsToBot( void );

public:
	virtual void Event_Killed( const CTakeDamageInfo &info );

	const char *GetTracerType( void ) { return "AR2Tracer"; }

	virtual Vector EyePosition( void );
	Vector MuzzlePosition( void );
	Vector RocketPosition( void );
	Vector EyeOffset( Activity nActivity ) { return Vector( 0, 0, 64 ); }

	bool				m_bSendNailGrenHint;	// Only send the "kill sgs with nail grens" hint once per sg
	float				m_flNextSparkTime;
	SmokeTrail			*m_pSmokeTrail;

	float	m_flLastCloakSonarSound;
	float	m_flCloakDistance;

	virtual void Sabotage(CFFPlayer *pSaboteur);
	virtual void MaliciouslySabotage(CFFPlayer *pSaboteur);
	virtual void Detonate();

	static CFFSentryGun *Create( const Vector &vecOrigin, const QAngle &vecAngles, CBaseEntity *pentOwner = NULL );

	void DoMuzzleFlash( int iAttachment, const Vector& vecOrigin, const QAngle& vecAngles );
	void DoRocketMuzzleFlash( int iAttachment, const Vector& vecOrigin, const QAngle& vecAngles );

public:
	CNetworkVar(unsigned int, m_iAmmoPercent);


	int		m_iShellDamage;

	float	m_flRocketCycleTime;
	float	m_flShellCycleTime;

	float	m_flTurnSpeed;
	float	m_flPitchSpeed;
	float	m_flLockTime;

	float m_flBarrelRotationDelta;
	float m_flBarrelRotationValue;
	float m_flSpinDownStartTime;
	float m_flSpinUpStartTime;

	// Ammo definition for shells
	int		m_iAmmoType;
	float	m_flNextShell;
	float	m_flNextRocket;
	float	m_flShotAccumulator;

	float	m_flLastSight;
	float	m_flPingTime;
	float	m_flNextActivateSoundTime;
	float	m_flAcknowledgeSabotageTime;
	float	m_flStartLockTime;
	float	m_flEndLockTime;

	int		m_iEyeAttachment;
	int		m_iMuzzleAttachment;
	int		m_iRocketLAttachment;
	int		m_iRocketRAttachment;

	int m_iPitchPoseParameter;
	int m_iYawPoseParameter;

	//
	// Level 3 only stuff
	//
	// Which barrel to fire from (when level 3)
	bool m_bLeftBarrel;
	bool m_bRocketLeftBarrel;
	int m_iLBarrelAttachment;
	int m_iRBarrelAttachment;

	// Aiming
	QAngle	m_angGoal;
	QAngle	m_angAimBase;
	QAngle	m_angAiming;

	// caes: store angular speeds of SG
	float m_angSpeed_yaw;
	float m_angSpeed_pitch;
	// caes
#endif
};

//=============================================================================
//
//	class CFFManCannon / C_FFManCannon
//
//=============================================================================
class CFFManCannon : public CFFBuildableObject
{
public:
	DECLARE_CLASS( CFFManCannon, CFFBuildableObject )

#ifdef CLIENT_DLL 
	DECLARE_CLIENTCLASS()
#else
	DECLARE_SERVERCLASS()
	DECLARE_DATADESC()
#endif

	// --> shared
	CFFManCannon( void );
	virtual ~CFFManCannon( void );

	virtual Class_T Classify( void ) { return CLASS_MANCANNON; }
	// <-- shared

#ifdef CLIENT_DLL
	virtual void OnDataChanged( DataUpdateType_t updateType );
	virtual int DrawModel(int flags);

	// Creates a client side ONLY man cannon - used for the build slot
	static C_FFManCannon *CreateClientSideManCannon( const Vector& vecOrigin, const QAngle& vecAngles );	

	float m_flLastDamage;
#else
	virtual void Spawn( void );
	virtual void GoLive( void );

	void OnObjectTouch( CBaseEntity *pOther );
	void OnJumpPadThink( void );
	
	// These are for updating the user
	virtual void	PhysicsSimulate();
	float			m_flLastClientUpdate;
	int				m_iLastState;
	JumpPadState_t	m_iCombatState;
	float			m_flLastHeal;
	CNetworkVar( float, m_flLastDamage );

	virtual bool CanSabotage( void ) const { return false; }
	virtual bool IsSabotaged( void ) const { return false; }
	virtual bool IsMaliciouslySabotaged( void ) const { return false; }
	virtual void Sabotage( CFFPlayer *pSaboteur ) {};
	virtual void MaliciouslySabotage( CFFPlayer *pSaboteur ) { m_bMaliciouslySabotaged = true; m_flSabotageTime = gpGlobals->curtime + 8.0f; }

	virtual void Detonate( void );
	virtual void DoExplosionDamage( void );

	static CFFManCannon *Create( const Vector& vecOrigin, const QAngle& vecAngles, CBaseEntity *pentOwner = NULL );
#endif
};

#ifdef GAME_DLL
//=============================================================================
//
//	class CFFBuildableFlickerer
//
//=============================================================================
class CFFBuildableFlickerer : public CBaseAnimating
{
	DECLARE_CLASS( CFFBuildableFlickerer, CBaseAnimating );
	DECLARE_DATADESC();

public:
	virtual void	Spawn( void );

	void			OnObjectThink( void );
	void			SetBuildable( CFFBuildableObject *pBuildable ) { m_pBuildable = pBuildable; }
	void			Flicker( void );

protected:
	CFFBuildableObject *m_pBuildable;
	float				m_flFlicker;
};
#endif // GAME_DLL

//-----------------------------------------------------------------------------
// Purpose: Is the entity a buildable?
//-----------------------------------------------------------------------------
inline bool FF_IsBuildableObject( CBaseEntity *pEntity )
{
	if( !pEntity )
		return false;

	return( ( pEntity->Classify() == CLASS_DISPENSER ) ||
		( pEntity->Classify() == CLASS_SENTRYGUN ) ||
		( pEntity->Classify() == CLASS_DETPACK ) ||
		( pEntity->Classify() == CLASS_MANCANNON ) );
}

//-----------------------------------------------------------------------------
// Purpose: Is the entity a dispenser?
//-----------------------------------------------------------------------------
inline bool FF_IsDispenser( CBaseEntity *pEntity )
{
	if( !pEntity )
		return false;

	return pEntity->Classify() == CLASS_DISPENSER;
}

//-----------------------------------------------------------------------------
// Purpose: Is the entity a sentrygun?
//-----------------------------------------------------------------------------
inline bool FF_IsSentrygun( CBaseEntity *pEntity )
{
	if( !pEntity )
		return false;

	return pEntity->Classify() == CLASS_SENTRYGUN;
}

//-----------------------------------------------------------------------------
// Purpose: Is the entity a detpack?
//-----------------------------------------------------------------------------
inline bool FF_IsDetpack( CBaseEntity *pEntity )
{
	if( !pEntity )
		return false;

	return pEntity->Classify() == CLASS_DETPACK;
}

//-----------------------------------------------------------------------------
// Purpose: Is the entity a man cannon?
//-----------------------------------------------------------------------------
inline bool FF_IsManCannon( CBaseEntity *pEntity )
{
	if( !pEntity )
		return false;

	return pEntity->Classify() == CLASS_MANCANNON;
}

//-----------------------------------------------------------------------------
// Purpose: Try and convert entity to a buildable
//-----------------------------------------------------------------------------
inline CFFBuildableObject *FF_ToBuildableObject( CBaseEntity *pEntity )

{
	if( !pEntity || !FF_IsBuildableObject( pEntity ) )
		return NULL;

#ifdef _DEBUG
	Assert( dynamic_cast< CFFBuildableObject * >( pEntity ) != 0 );
#endif

	return static_cast< CFFBuildableObject * >( pEntity );
}

//-----------------------------------------------------------------------------
// Purpose: Try and convert entity to a dispenser
//-----------------------------------------------------------------------------
inline CFFDispenser *FF_ToDispenser( CBaseEntity *pEntity )
{
	if( !pEntity || !FF_IsDispenser( pEntity ) )
		return NULL;

#ifdef _DEBUG
	Assert( dynamic_cast< CFFDispenser * >( pEntity ) != 0 );
#endif

	return static_cast< CFFDispenser * >( pEntity );
}

//-----------------------------------------------------------------------------
// Purpose: Try and convert entity to a sentrygun
//-----------------------------------------------------------------------------
inline CFFSentryGun *FF_ToSentrygun( CBaseEntity *pEntity )
{
	if( !pEntity || !FF_IsSentrygun( pEntity ) )
		return NULL;

#ifdef _DEBUG
	Assert( dynamic_cast< CFFSentryGun * >( pEntity ) != 0);
#endif

	return static_cast< CFFSentryGun * >( pEntity );
}

//-----------------------------------------------------------------------------
// Purpose: Try and convert entity to a detpack
//-----------------------------------------------------------------------------
inline CFFDetpack *FF_ToDetpack( CBaseEntity *pEntity )
{
	if( !pEntity || !FF_IsDetpack( pEntity ) )
		return NULL;

#ifdef _DEBUG
	Assert( dynamic_cast< CFFDetpack * >( pEntity ) != 0 );
#endif

	return static_cast< CFFDetpack * >( pEntity );
}

//-----------------------------------------------------------------------------
// Purpose: Try and convert entity to a man cannon
//-----------------------------------------------------------------------------
inline CFFManCannon *FF_ToManCannon( CBaseEntity *pEntity )
{
	if( !pEntity || !FF_IsManCannon( pEntity ) )
		return NULL;

#ifdef _DEBUG
	Assert( dynamic_cast< CFFManCannon * >( pEntity ) != 0);
#endif

	return static_cast< CFFManCannon * >( pEntity );
}

#endif // FF_BUILDABLEOBJECTS_SHARED_H