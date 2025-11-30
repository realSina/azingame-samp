#include <a_samp>

//native sscanf(string[], format[], {Float,_}:...);

stock SetSpawnInfoEx(playerid, team, skin, Float:X, Float:Y, Float:Z, Float:Rotation, weaponid1, ammo1, weaponid2, ammo2, weaponid3, ammo3)
{
	if(!IsPlayerConnected(playerid))return -1;
	else
	{
		CallRemoteFunction("OnPlayerSetSpawnInfo", "iiiiiii", playerid, weaponid1, ammo1, weaponid2, ammo2, weaponid3, ammo3);
		return SetSpawnInfo(playerid, team, skin, X, Y, Z, Rotation, weaponid1, ammo1, weaponid2, ammo2, weaponid3, ammo3);
	}
}
 
stock GivePlayerWeaponEx(playerid, weaponid, ammof)
{
	if(!IsPlayerConnected(playerid))return -1;
	else
	{
	    CallRemoteFunction("OnPlayerGetWeapon", "iii", playerid, weaponid, ammof);
	    return GivePlayerWeapon(playerid, weaponid, ammof);
	}
}

stock ResetPlayerWeaponsEx(playerid)
{
	if(!IsPlayerConnected(playerid))return -1;
	else
	{
	    CallRemoteFunction("OnPlayerResetWeapons", "i", playerid);
	    return ResetPlayerWeapons(playerid);
	}
}

stock GivePlayerMoneyEx(playerid, amount)
{
	if(!IsPlayerConnected(playerid))return -1;
	else
	{
	    CallRemoteFunction("OnPlayerGetMoney", "ii", playerid, amount);
	    return GivePlayerMoney(playerid, amount);
	}
}

stock CreatePickupEx(model, type, Float:X, Float:Y, Float:Z, vworld=0)
{
	if(type==2)
	{
	    CallRemoteFunction("OnPickupCall", "fff", X, Y, Z);
	    return CreatePickup(model, type, Float:X, Float:Y, Float:Z, vworld);
	}
	else return CreatePickup(model, type, Float:X, Float:Y, Float:Z, vworld=0);
}

stock AddStaticPickupEx(model, type, Float:X, Float:Y, Float:Z, vworld=0)
{
	if(type==2)
	{
	    CallRemoteFunction("OnPickupCall", "fff", X, Y, Z);
	    return AddStaticPickup(model, type, Float:X, Float:Y, Float:Z, vworld);
	}
	else return AddStaticPickup(model, type, Float:X, Float:Y, Float:Z, vworld=0);
}

/*
stock SetPVarIntEx(playerid, varname[], value)
{
	if(!IsPlayerConnected(playerid))return -1;
	else
	{
		SetPVarInt(playerid, varname, value);
	}
}*/

#if defined _ALS_GivePlayerWeapon
    #undef GivePlayerWeapon
#else
    #define _ALS_GivePlayerWeapon
#endif
#define GivePlayerWeapon GivePlayerWeaponEx

#if defined _ALS_ResetPlayerWeapons
    #undef ResetPlayerWeapons
#else
    #define _ALS_ResetPlayerWeapons
#endif
#define ResetPlayerWeapon ResetPlayerWeaponsEx

#if defined _ALS_GivePlayerMoney
    #undef GivePlayerMoney
#else
    #define _ALS_GivePlayerMoney
#endif
#define GivePlayerMoney GivePlayerMoneyEx

#if defined _ALS_SetSpawnInfo
    #undef SetSpawnInfo
#else
    #define _ALS_SetSpawnInfo
#endif
#define SetSpawnInfo SetSpawnInfoEx

#if defined _ALS_CreatePickup
    #undef CreatePickup
#else
    #define _ALS_CreatePickup
#endif
#define CreatePickup CreatePickupEx

#if defined _ALS_AddStaticPickup
    #undef AddStaticPickup
#else
    #define _ALS_AddStaticPickup
#endif
#define AddStaticPickup AddStaticPickupEx

/*
#if defined _ALS_SetPVarInt
    #undef SetPVarInt
#else
    #define _ALS_SetPVarInt
#endif
#define SetPVarInt SetPVarIntEx

#if defined _ALS_SetPVarString
    #undef SetPVarString
#else
    #define _ALS_SetPVarString
#endif
#define SetPVarString SetPVarStringEx

#if defined _ALS_SetPVarFloat
    #undef SetPVarFloat
#else
    #define _ALS_SetPVarFloat
#endif
#define SetPVarFloat SetPVarFloatEx*/
