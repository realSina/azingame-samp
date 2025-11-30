SA-MP Forum topic: http://forum.sa-mp.com/index.php?topic=104998.0

#include <a_samp>

// * Settings for the anti-flood
// I recommend using these settings if you want to protect the server from flood attacks.
// If you want to deal with annoying spammers, lower the thresold a bit and set the mode to 2 (kick).

#define RATE_INC (500)  // The sensitivity per message, no need to modify.
#define RATE_MAX (2500) // When the flood rate reaches this value the action below will be taken

// * Action to take when the flood rate reached the thresold
// 1 - Ban
// 2 - Kick
// 3 - Give a warning (not recommended)

#define THRESOLD_ACTION 2

enum LIST_ANTIFLOOD
{
	lastCheck,
	floodRate
}

new AntiFlood_Data[MAX_PLAYERS][LIST_ANTIFLOOD];

public OnFilterScriptInit()
{
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

public OnPlayerConnect( playerid )
{
	AntiFlood_InitPlayer( playerid );
	
	return 1;
}

public OnPlayerDisconnect( playerid )
{
	return 1;
}

public OnPlayerText( playerid, text[] )
{
	assert( AntiFlood_Check( playerid ) );
	
	return 1;
}

public OnPlayerCommandText( playerid, cmdtext[] )
{
	assert( AntiFlood_Check( playerid ) );
	
	return 0;
}

public OnPlayerPrivmsg( playerid, recieverid, text[] )
{
	assert( AntiFlood_Check( playerid ) );
	
	return 1;
}

forward OnPlayerTeamPrivmsg( playerid, text[] );
public  OnPlayerTeamPrivmsg( playerid, text[] )
{
	assert( AntiFlood_Check( playerid ) );
	
	return 1;
}

public OnPlayerDeath( playerid, killerid, reason )
{
	assert( AntiFlood_Check( playerid ) );
	
	return 1;
}

AntiFlood_Check( playerid, bool:inc=true )
{
	AntiFlood_Data[playerid][floodRate] += inc ? RATE_INC : 0;
	AntiFlood_Data[playerid][floodRate]  = AntiFlood_Data[playerid][floodRate] - ( GetTickCount() - AntiFlood_Data[playerid][lastCheck] );
	AntiFlood_Data[playerid][lastCheck]  = GetTickCount();
	AntiFlood_Data[playerid][floodRate]  = AntiFlood_Data[playerid][floodRate] < 0 ? 0 : AntiFlood_Data[playerid][floodRate];
	
	if ( AntiFlood_Data[playerid][floodRate] >= RATE_MAX )
	{
		#if THRESOLD_ACTION == 1
			new msg[64], name[MAX_PLAYER_NAME];
			
			GetPlayerName( playerid, name, sizeof( name ) );
			
			format( msg, sizeof( msg ), ">> %s has been banned for flooding.", name );
			
			SendClientMessageToAll( 0xEE9911FF, msg );
			
			Ban( playerid );
		#elseif THRESOLD_ACTION == 2
			new msg[64], name[MAX_PLAYER_NAME];
			
			GetPlayerName( playerid, name, sizeof( name ) );
			
			format( msg, sizeof( msg ), ">> %s has been kicked for flooding.", name );
			
			SendClientMessageToAll( 0xEE9911FF, msg );
			
			Kick( playerid );
		#else
			SendClientMessage( playerid, 0xC00000FF, "Stop flooding." );
		#endif
		
		return false;
	}
	
	return true;
}

AntiFlood_InitPlayer( playerid )
{
	AntiFlood_Data[playerid][lastCheck] = GetTickCount();
	AntiFlood_Data[playerid][floodRate] = 0;
}