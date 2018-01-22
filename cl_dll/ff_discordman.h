// ff_discordman.h

// lol has stdint which vc2005 doesnt have
//#include "discord-api/discord-rpc.h"
#include <ctime>


// see ff_discordman.cpp for explaination of why all this is here
/*
// needs lib stubs which vc2005 ABI wont link against
__declspec(dllimport) void Discord_Initialize(const char* applicationId,
                                       DiscordEventHandlers* handlers,
                                       int autoRegister,
                                       const char* optionalSteamId);

__declspec(dllimport) void Discord_Shutdown(void);
__declspec(dllimport) void Discord_RunCallbacks(void);
__declspec(dllimport) void Discord_UpdatePresence(const DiscordRichPresence* presence);
*/


typedef struct DiscordRichPresence {
    const char* state;   /* max 128 bytes */
    const char* details; /* max 128 bytes */
    unsigned long long startTimestamp; // type modified from stdint
    unsigned long long endTimestamp; // type modified from stdint
    const char* largeImageKey;  /* max 32 bytes */
    const char* largeImageText; /* max 128 bytes */
    const char* smallImageKey;  /* max 32 bytes */
    const char* smallImageText; /* max 128 bytes */
    const char* partyId;        /* max 128 bytes */
    unsigned int partySize;
    unsigned int partyMax;
    const char* matchSecret;    /* max 128 bytes */
    const char* joinSecret;     /* max 128 bytes */
    const char* spectateSecret; /* max 128 bytes */
    unsigned short instance; // type modified from stdint
} DiscordRichPresence;

typedef struct DiscordJoinRequest {
    const char* userId;
    const char* username;
    const char* discriminator;
    const char* avatar;
} DiscordJoinRequest;

typedef struct DiscordEventHandlers {
    void (*ready)();
    void (*disconnected)(int errorCode, const char* message);
    void (*errored)(int errorCode, const char* message);
    void (*joinGame)(const char* joinSecret);
    void (*spectateGame)(const char* spectateSecret);
    void (*joinRequest)(const DiscordJoinRequest* request);
} DiscordEventHandlers;


class CFFDiscordManager
{
public:
	CFFDiscordManager();
	~CFFDiscordManager();

	void SetServer(const char *szName);
	void SetMapName(const char *szDetails);
	void SetPlayerCounts(int min, int cur, int max);

	void SetSmallImage(const char *szName);
	void SetLargeImage(const char *szName);
	void RunFrame();

	// these have to be static so that discord can use them
	// as callbacks :-(
	static void OnReady();
	static void OnDiscordError(int errorCode, const char* message);
private:
	
	void InitializeDiscord();

	// pulled out of here so we dont include windows.h
	// including windows.h breaks CFFPlayer with a bunch of nonsense.
	//HINSTANCE m_hDiscordDLL;

	bool m_bApiReady;
	bool m_bInitializeRequested;
	DiscordRichPresence *m_pDiscordRichPresence;
};

extern CFFDiscordManager _discord;