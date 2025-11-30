// Acest gamemode este facut de WopsS
// Buguri: -

#include <a_samp>
#include <a_mysql>
#include <saveacc>

// Gamemode
#define gamemode_version "v0.01 Beta"
#define gamemode_map "LS-LV-SF"

// MySQL
#define mysql_host "localhost"
#define mysql_user "root"
#define mysql_password ""
#define mysql_database "w3op"

forward MySQLConnect();

new handle;
//

// Colors
#define COLOR_WHITE 0xFFFFFFFF
#define COLOR_ERROR 0x5CAD5CFF
//

// Dialogs
#define DIALOG_LOGIN 1
#define DIALOG_REGISTER 2
//

// Login
new gLogged[MAX_PLAYERS];
new gAccount[MAX_PLAYERS];

forward OnPlayerRegister(playerid, password[]);
forward OnPlayerLogin(playerid, password[]);
//

main()
{
	printf(" ");
	printf(" ");
	printf(" RPG: %s %s", gamemode_version, gamemode_map);
	printf("_____________________");
}

public OnGameModeInit()
{
	// MySQL
	MySQLConnect();
	mysql_log(1);
	//
	AddPlayerClass(0, 1958.3783, 1343.1572, 15.3746, 269.1425, 0, 0, 0, 0, 0, 0);
	// Gamemode and Map text
	new gamemodetext[256];
	format(gamemodetext, sizeof(gamemodetext), "%s", gamemode_version);
	SetGameModeText(gamemodetext);

	new mapname[256];
	format(mapname, sizeof(mapname), "mapname %s", gamemode_map);
	SendRconCommand(mapname);
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraLookAt(playerid, 1958.3783, 1343.1572, 15.3746);
	return 1;
}

public OnPlayerConnect(playerid)
{
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	return 1;
}

public OnPlayerSpawn(playerid)
{
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
 	if (strcmp("/mycommand", cmdtext, true, 10) == 0)
	{
		// Do something here
		return 1;
	}
	return 0;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	return 1;
}

public OnPlayerStreamOut(playerid, forplayerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}

public MySQLConnect()
{
	handle = mysql_connect(mysql_host, mysql_user, mysql_database, mysql_password);

	if(handle)
	{
		printf("[MYSQL]: Connection to database (%s) was established!",mysql_database);
	}
	else
	{
		printf("[MYSQL]: Connection to database (%s) failed!",mysql_database);
	}

	return 1;
}
