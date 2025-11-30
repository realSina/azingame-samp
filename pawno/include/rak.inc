/*
RakSamp Detector.
Jelly23
*/

#if defined _RakSamp_included
	#endinput
#endif
#define _RakSamp_included

#if ! defined PAWNRAKNET_INC_
	#error You must have Pawn.Raknet include in order to use this one.
#endif

#if ! defined SendClientCheck
	native SendClientCheck(playerid, type, arg, offset, size);
#endif

static RakSamp_DetectionPhase[MAX_PLAYERS char];

forward OnInvalidClientJoin(playerid);
forward RakSamp_Callback(playerid); //this is for internal use

/*OnPlayerConnect*/
public OnPlayerConnect(playerid)
{
	RakSamp_DetectionPhase{playerid} = 0;
	
	SendClientCheck(playerid, 0x2, 0, 0, 2); //As long as the action id is valid, it doesn't matter.
	
	#if defined RakSamp_OnPlayerConnect
		return RakSamp_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

/*OnIncomingRPC*/
public OnIncomingRPC(playerid, rpcid, BitStream:bs)
{
	if(!RakSamp_DetectionPhase{playerid} && rpcid != 0x19) //ClientJoin RPC, called before OnPlayerConnect - Needed to avoid having the callback executed two times for RakSamp users.
	{
		RakSamp_DetectionPhase{playerid} = 1;
		SetTimerEx("RakSamp_Callback", 2000, false, "i", playerid);
	}
	
	if(rpcid == 0x67)
	{
	    RakSamp_DetectionPhase{playerid} = 2;
	}
	#if defined RakSamp_OnIncomingRPC
		return RakSamp_OnIncomingRPC(playerid, rpcid, bs);
	#else
		return 1;
	#endif
}

/*RakSamp_Callback - Internal*/
public RakSamp_Callback(playerid)
{
	if(RakSamp_DetectionPhase{playerid} == 1)
	{
		OnInvalidClientJoin(playerid);
	}
	return 1;
}

/*Hooks*/
#if defined _ALS_OnIncomingRPC
#undef OnIncomingRPC
#else
#define _ALS_OnIncomingRPC
#endif
#define OnIncomingRPC RakSamp_OnIncomingRPC

#if defined RakSamp_OnIncomingRPC
forward RakSamp_OnIncomingRPC(playerid, rpcid, BitStream:bs);
#endif

#if defined _ALS_OnPlayerConnect
#undef OnPlayerConnect
#else
#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect RakSamp_OnPlayerConnect

#if defined RakSamp_OnPlayerConnect
forward RakSamp_OnPlayerConnect(playerid);
#endif
