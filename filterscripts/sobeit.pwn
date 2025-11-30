#include <a_samp>

native SendClientCheck ( clientid , actionid , arg1 = 0x00000000 , arg2 = 0x0000 , bytes = 0x0004 ); // int32, int8, int32, int16, int16 
forward OnClientCheckResponse ( clientid , actionid , checksum , crc ); // int32, int8, int32, int8      


forward HackCheck(playerid);

#define FILTERSCRIPT

#if defined FILTERSCRIPT

public OnFilterScriptInit()
{
    print("Anti Sobeit loaded");
    return 1;
}

public OnFilterScriptExit()
{
    return 1;
}

#else

#endif
//==============================================================================
public OnPlayerConnect(playerid)
{
    SetTimerEx("HackCheck",500,false,"i",playerid);
    if(GetPVarInt(playerid,"CHEAT"))DeletePVar(playerid,"CHEAT");
	return 1;
}
//==============================================================================
public OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid,"CHEAT"))DeletePVar(playerid,"CHEAT");
    return 1;
}
//==============================================================================
public OnPlayerSpawn(playerid)
{
    HackCheck(playerid);
    return 1;
}
//==============================================================================
public OnClientCheckResponse ( clientid , actionid , checksum , crc ) 
{ 
    switch ( actionid ) 
    { 
        case 0x47 : SendClientCheck ( clientid , 0x02 ); // player class loaded, send query to generate checksum (action 0x02)
        case 0x02 : if ( checksum & 0x00ff0000 == 0x00300000 ) CallRemoteFunction("OnSobeitDetected","i",clientid); // mod-s0beit-sa 
    }
}
//==============================================================================
public HackCheck(playerid)
{
	SendClientCheck ( playerid , 0x47 ); 
	return 1;
}
