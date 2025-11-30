#if defined _antisurf_included
	#endinput
#endif
#define _antisurf_included

/*
	native SetVehicleSurfable(modelid, bool: set);
	native SetPlayerSurfImmunity(playerid, bool: immunity);
	native GetPlayerSurfImmunity(playerid);
	native OnPlayerCarSurf(playerid, vehicleid);
*/

#if !defined SURF_MIN_SPEED
	#define SURF_MIN_SPEED (25.0)
#endif

static
	surf_LastChecked[MAX_PLAYERS] = {0, ...},
	bool: surf_Immunity[MAX_PLAYERS] = {false, ...},
	bool: AllowedModels[212] = {false, ...};
	
stock Float: surf_GetVehicleSpeed(vehicleid)
{
	// http://forum.sa-mp.com/showpost.php?p=2646780&postcount=22
	new Float: vx, Float: vy, Float: vz, Float: vel;
	vel = GetVehicleVelocity(vehicleid, vx, vy, vz);
	vel = (floatsqroot(((vx*vx)+(vy*vy))+(vz*vz))* 181.5);
	return vel;
}

stock SetVehicleSurfable(modelid, bool: set)
{
	if(!(400 <= modelid <= 611)) return 0;
	AllowedModels[modelid-400] = set;
	return 1;
} 

stock SetPlayerSurfImmunity(playerid, bool: immunity)
{
	if(!IsPlayerConnected(playerid)) return 0;
	surf_Immunity[playerid] = immunity;
	return 1;
}

stock GetPlayerSurfImmunity(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	return surf_Immunity[playerid];
}

public OnPlayerConnect(playerid)
{
	surf_Immunity[playerid] = false;
	
	#if defined AntiSurf_OnPlayerConnect
		return AntiSurf_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

public OnPlayerUpdate(playerid)
{
	if(surf_LastChecked[playerid] < tickcount() && !surf_Immunity[playerid])
	{
		surf_LastChecked[playerid] = tickcount()+500;
		
		new vehID = GetPlayerSurfingVehicleID(playerid);
		if(vehID != INVALID_VEHICLE_ID && surf_GetVehicleSpeed(vehID) >= SURF_MIN_SPEED && !AllowedModels[ GetVehicleModel(vehID)-400 ])
		{
			if(funcidx("OnPlayerCarSurf") == -1) {
				new Float: x, Float: y, Float: z;
				GetPlayerPos(playerid, x, y, z);
				SetPlayerPos(playerid, x, y, z+3.5);
				GameTextForPlayer(playerid, "~w~CarSurfing Is ~r~Not ~w~Allowed!", 3000, 4);
			}else{
				CallLocalFunction("OnPlayerCarSurf", "dd", playerid, vehID);
			}
		}
	}
	
	#if defined AntiSurf_OnPlayerUpdate
		return AntiSurf_OnPlayerUpdate(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
 
#define OnPlayerConnect AntiSurf_OnPlayerConnect
#if defined AntiSurf_OnPlayerConnect
	forward AntiSurf_OnPlayerConnect(playerid);
#endif

#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
 
#define OnPlayerUpdate AntiSurf_OnPlayerUpdate
#if defined AntiSurf_OnPlayerUpdate
	forward AntiSurf_OnPlayerUpdate(playerid);
#endif

forward OnPlayerCarSurf(playerid, vehicleid);