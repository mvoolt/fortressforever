// wrapper for discord rich presence api
// they provide static libs, dlls and headers to use directly, but to no
// surprise, having to use ancient vc2005 ABI, we cant even link against
// modern DLL stub libs. Also the discord header includes stdint which vc2005 
// doesn't even have (lol), so its mostly just manually pulling in the structs
// and loading the library functions manually at runtime.

#include "cbase.h"
#include "ff_discordman.h"
#include <windows.h>
// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"


#define DISCORD_LIBRARY_DLL "discord-rpc.dll"
#define DISCORD_APP_ID "404135974801637378"
#define STEAM_ID "253530"

ConVar use_discord("cl_discord", "1", FCVAR_CLIENTDLL | FCVAR_ARCHIVE | FCVAR_USERINFO, 
				   "Enable discord rich presence integration (current, server, map etc)");

CFFDiscordManager _discord;

// runtime entry point nastiness we will hide in here
typedef void (*pDiscord_Initialize)(const char* applicationId,
                                       DiscordEventHandlers* handlers,
                                       int autoRegister,
                                       const char* optionalSteamId);

typedef void (*pDiscord_Shutdown)(void);
typedef void (*pDiscord_RunCallbacks)(void);
typedef void (*pDiscord_UpdatePresence)(const DiscordRichPresence* presence);

pDiscord_Initialize Discord_Initialize = NULL;
pDiscord_Shutdown Discord_Shutdown = NULL;
pDiscord_RunCallbacks Discord_RunCallbacks = NULL;
pDiscord_UpdatePresence Discord_UpdatePresence = NULL;

static HINSTANCE hDiscordDLL;

// NOTE: can not call discord from main menu thread. it will block

CFFDiscordManager::CFFDiscordManager()
{
	hDiscordDLL = LoadLibrary(DISCORD_LIBRARY_DLL);
	if (!hDiscordDLL)
	{
		return;
	}
	
	Discord_Initialize = (pDiscord_Initialize) GetProcAddress(hDiscordDLL, "Discord_Initialize");
	Discord_Shutdown = (pDiscord_Shutdown) GetProcAddress(hDiscordDLL, "Discord_Shutdown");
	Discord_RunCallbacks = (pDiscord_RunCallbacks) GetProcAddress(hDiscordDLL, "Discord_RunCallbacks");
	Discord_UpdatePresence = (pDiscord_UpdatePresence) GetProcAddress(hDiscordDLL, "Discord_UpdatePresence");

	// dont run this yet. it will hang client
	// InitializeDiscord();
}

CFFDiscordManager::~CFFDiscordManager()
{
	if (hDiscordDLL) 
	{
		// dont bother with clean exit, it will block. 
		// Discord_Shutdown();
		// i mean really, we could just let os handle since our dtor is called at game exit but
		FreeLibrary(hDiscordDLL);
	}
	hDiscordDLL = NULL;
}

void CFFDiscordManager::RunFrame()
{
	if (!use_discord.GetBool())
		return;

	if (!m_bApiReady)
	{
		if (!m_bInitializeRequested)
		{
			InitializeDiscord();
			m_bInitializeRequested = true;
		}
	}

	// always run this, otherwise we will chicken & egg waiting for ready
	if (Discord_RunCallbacks)
		Discord_RunCallbacks();
}

void CFFDiscordManager::OnReady()
{
	DevMsg("discord ready");
	_discord.m_bApiReady = true;
}

void CFFDiscordManager::OnDiscordError(int errorCode, const char* message)
{
	_discord.m_bApiReady = false;
	if (Q_strlen(message) < 1024)
	{
		char buff[1024];
		Q_snprintf(buff, 1024, "Discord init failed. code %d - error: %s\n", errorCode, message);
		Warning(buff);
	}
}

void CFFDiscordManager::InitializeDiscord()
{
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	handlers.ready = &CFFDiscordManager::OnReady;
	handlers.errored = &CFFDiscordManager::OnDiscordError;
//	handlers.disconnected = handleDiscordDisconnected;
//	handlers.joinGame = handleDiscordJoinGame;
//	handlers.spectateGame = handleDiscordSpectateGame;
//	handlers.joinRequest = handleDiscordJoinRequest;
	Discord_Initialize(DISCORD_APP_ID, &handlers, 1, "");// STEAM_ID);
}

void CFFDiscordManager::SetServer(const char *szName)
{
}

void CFFDiscordManager::SetMapName(const char *szDetails)
{
}

void CFFDiscordManager::SetPlayerCounts(int min, int cur, int max)
{
}

void CFFDiscordManager::SetSmallImage(const char *szName)
{
}

void CFFDiscordManager::SetLargeImage(const char *szName)
{
}