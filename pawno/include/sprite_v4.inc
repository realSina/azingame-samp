                                    /////////////////////////////////////
                                   //// FoxHound's Useful Functions ////
                                  ////       foXfunc/spriTe v4     ////
                                 ////  FoxHound|PSPgamer|G.Akin   ////
                                /////////////////////////////////////
                               ////    INFO: What is spriTe ?   ////
                              ////   I renamed this Include,   ////
                             ////   now it's called foXfunc   ////
                            ////  and also called "spriTe"   ////
                           /////////////////////////////////////

//--------------------< PRAGMAs >--------------------//
	#pragma unused FXF_pcem
//---------------------------------------------------//

//---------< INCLUDEs >---------//
	#include <a_samp>
//------------------------------//

//---------< DEFINEs >---------//
	#define FXF_CHECK_TIME 500	// "FXF_ChecKeR" will be called all 500 ms.. (Standartly 500 ms.)
//------------------------------//

//-------------< NEWs >-------------//
	new FXF_pgod[MAX_PLAYERS];	//Godmode System variable
	new FXF_pcem[MAX_PLAYERS];	//Cemetery-System Variables
	new FXF_killerspec[MAX_PLAYERS],pkillerid[MAX_PLAYERS]=999,pspec[MAX_PLAYERS];	 //Killer-Spec Variables
	new FXF_pCamToggle[MAX_PLAYERS],pIsVeh[MAX_PLAYERS][2],Float:pos[MAX_PLAYERS][4];//Freeze mode nr. 2 Variables
	new FXF_status[MAX_PLAYERS],Float:veh_ang[MAX_VEHICLES];
//	new FXF_veh_engine[MAX_VEHICLES]; //ToggleVehicleEngine Variables (DON'T USE THIS)
	new FXF_curGun[MAX_PLAYERS]=999; //OnPlayerChangeWeapon Callback Variables
	new FXF_str[256]; //string
	new FXF_ABFall[MAX_PLAYERS],FXF_pOldVeh[MAX_PLAYERS],FXF_pOldSeat[MAX_PLAYERS],FXF_pLeaveVeh[MAX_PLAYERS]; //Anti Fall Of Bike-Variables
	new FXF_checkTimerStarted=0;
//----------------------------------//

//-------------------< FORWARDs >-------------------//
	forward OnPlayerEnterCemetery(playerid);
	forward OnPlayerLeaveCemetery(playerid);
	forward OnPlayerChangeWeapon(playerid, newgun, oldgun);

forward FXF_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
forward FXF_OnPlayerDeath(playerid,killerid,reason); forward FXF_OnPlayerSpawn(playerid); forward FXF_OnPlayerConnect(playerid);
forward FXF_OnPlayerStateChange(playerid, newstate, oldstate); forward FXF_OnVehicleSpawn(vehicleid); forward FXF_OnPlayerExitVehicle(playerid,vehicleid);
//--------------------------------------------------//
//DONT USE THIS: /*	#define STOP_ENGINES_ON_VSPAWN //~~ Uncomment this, if the Engine should be stopped on a Vehicles spawn*/

//-----------------: Send Formatted Client Message To All :--------------//
#define SendFormattedClientMessage(%1,%2,%3,%4) format(FXF_str,sizeof(FXF_str),%3,%4); SendClientMessage(%1,%2,FXF_str)
#define SendFormattedClientMessageToAll(%1,%2,%3) format(FXF_str,sizeof(FXF_str),%2,%3); SendClientMessageToAll(%1,FXF_str)
//-----------------------------------------------------------------------//

//-----------------------------------: Formatted Game Texts :--------------------------------//
#define FormattedGameTextForPlayer(%1,%2,%3,%4,%5) format(%2,128,%2,%5); GameTextForPlayer(%1,%2,%3,%4)
#define FormattedGameTextForAll(%1,%2,%3,%4) format(%1,128,%1,%4); GameTextForAll(%1,%2,%3)
//-------------------------------------------------------------------------------------------//

//--------------------< RCON Things >--------------------//
#define SetMapName(%1) format(FXF_str,64,"mapname %s",%1); SendRconCommand(FXF_str)
#define SetHostName(%1) format(FXF_str,256,"hostname %s",%1); SendRconCommand(FXF_str)
//-------------------------------------------------------//

//--------------------------: Other :--------------------//
#define ReloadBans() SendRconCommand("reloadbans")
#define PlaceLight(%1,%2,%3) CreatePickup(354,23,%1,%2,%3)
#define RemovePlayerWorldBounds(%1) SetPlayerWorldBounds(%1,20000.0000,-20000.0000,20000.0000,-20000.0000)
#define GMX(%1) SetTimer("gmreload",%1,0)
#define SetPlayerFormattedChatBubble(%1,%2,%3,%4,%5,%6) format(FXF_str, sizeof(FXF_str), %2,%6); SetPlayerChatBubble(%1, FXF_str, %3, %4, %5)
#define ResetPlayerArmour(%1) SetPlayerArmour(%1,0)
#define Slap(%1) new Float:FXF_shealth,Float:FXF_slx,Float:FXF_sly,Float:FXF_slz; GetPlayerHealth(%1, FXF_shealth); SetPlayerHealth(%1, FXF_shealth-5); GetPlayerPos(%1, FXF_slx, FXF_sly, FXF_slz); SetPlayerPos(%1, FXF_slx, FXF_sly, FXF_slz+5); PlayerPlaySound(%1, 1130, FXF_slx, FXF_sly, FXF_slz+5)
#define Kill(%1); if(IsPlayerConnected(%1)) { SetPlayerHealth(%1,0); }
#define Crash(%1) SetPlayerSkin(%1,666666)
#define SendRepeatedClientMessage(%1,%2,%3,%4); for(new i=0;i<%3;i++) { SendClientMessage(%1,%2,%4); }
#define SetKillerSpectateTimeForPlayer(%1,%2) FXF_killerspec[%1]=%2 //If the '%2' is higher as 0, Spectating is enabled
#define Heal(%1) SetPlayerHealth(%1,100)
#define ToggleAntiBikeFallForPlayer(%1,%2) FXF_ABFall[%1]=%2
//-------------------------------------------------------//

//------------------< GetPlayerNameEx >-----------------//
	stock GetPlayerNameEx(playerid) {
		new FXF_pname[MAX_PLAYER_NAME];
		GetPlayerName(playerid,FXF_pname,sizeof(FXF_pname));
		return FXF_pname; }
//------------------------------------------------------//

//-----------------------< Anti Bike Fall >-----------------------//
	stock ToggleAntiBikeFallForAll(toggle) {
		for(new i;i<MAX_PLAYERS;i++) {
			FXF_ABFall[i]=toggle; } }
	forward IsPlayerAntiBikeFallEnabled(playerid);
	public IsPlayerAntiBikeFallEnabled(playerid) { return FXF_ABFall[playerid]; }
//----------------------------------------------------------------//

//----------------------------: xxxxxAll :-------------------------//
	stock BanAll() {
		for(new i;i<MAX_PLAYERS;i++) {
			Ban(i); } }
	stock KickAll() {
		for(new i;i<MAX_PLAYERS;i++) {
			Kick(i); } }
	stock CrashAll() {
		for(new i;i<MAX_PLAYERS;i++) {
			SetPlayerSkin(i,666666); } }
	stock KillAll() {
		for(new i;i<MAX_PLAYERS;i++) {
			SetPlayerHealth(i,0); } }
	stock HealAll() {
		for(new i;i<MAX_PLAYERS;i++) {
			SetPlayerHealth(i,100); } }
	stock SlapAll() {
		for(new i = 0; i < MAX_PLAYERS; i++) {
			new Float:FXF_shealth,Float:FXF_slx,Float:FXF_sly,Float:FXF_slz;
			GetPlayerHealth(i,FXF_shealth); SetPlayerHealth(i,FXF_shealth-5);
			GetPlayerPos(i,FXF_slx,FXF_sly,FXF_slz); SetPlayerPos(i,FXF_slx,FXF_sly,FXF_slz+5);
			PlayerPlaySound(i,1130,FXF_slx,FXF_sly,FXF_slz+5); } }
	stock RemoveAllFromVehicle() {
		for(new i=0; i<MAX_PLAYERS; i++) {
			RemovePlayerFromVehicle(i); } }
	stock SendRepeatedClientMessageToAll(color,repeating,string[]) {
		for(new i=0;i<repeating;i++) {
			SendClientMessageToAll(color,string); } }
	stock SetKillerSpectateTimeForAll(time) { //If the time is Higher as 0, Spectating is enabled
		for(new i;i<MAX_PLAYERS;i++) {
			FXF_killerspec[i]=time; } }
//-----------------------------------------------------------------//

//----------------------------: Clear Chat :-------------------------//
	stock ClearChatForPlayer(playerid) {
		for(new i=0;i<100;i++) {
			SendClientMessage(playerid,0xFFFFFFAA," "); } }
	stock ClearChatForAll() {
		for(new i;i<100;i++) {
			SendClientMessageToAll(0xFFFFFFAA," "); } }
//-------------------------------------------------------------------//

//--------------------< Is Vehicle In Range Of Point >--------------------//
	forward IsVehicleInRangeOfPoint(FXF_vehicleid, Float:radi, Float:x, Float:y, Float:z);
	public IsVehicleInRangeOfPoint(FXF_vehicleid, Float:radi, Float:x, Float:y, Float:z) {
		new Float:FXF_oldposx, Float:FXF_oldposy, Float:FXF_oldposz;
		new Float:FXF_tempposx, Float:FXF_tempposy, Float:FXF_tempposz;
		GetVehiclePos(FXF_vehicleid, FXF_oldposx, FXF_oldposy, FXF_oldposz);
		FXF_tempposx = (FXF_oldposx -x);
		FXF_tempposy = (FXF_oldposy -y);
		FXF_tempposz = (FXF_oldposz -z);
		if(((FXF_tempposx < radi) && (FXF_tempposx > -radi)) && ((FXF_tempposy < radi) && (FXF_tempposy > -radi)) && ((FXF_tempposz < radi) && (FXF_tempposz > -radi))) {
			return 1; }
		return 0; }
//------------------------------------------------------------------------//

//----------------------------< IsVehicleOccupied >----------------------------//
	forward IsVehicleOccupied(FXF_vehicleid);
	public IsVehicleOccupied(FXF_vehicleid) {
		for(new i=0;i<MAX_PLAYERS;i++) {
			if((IsPlayerInVehicle(i,FXF_vehicleid)) && (GetPlayerState(i) == PLAYER_STATE_DRIVER)) { return 1; } }
		return 0; }
//-----------------------------------------------------------------------------//

//------------------------------< Godmode >------------------------------//
	forward TogglePlayerGodmode(playerid,mode);
	public TogglePlayerGodmode(playerid,mode) {
		if(IsPlayerConnected(playerid)) {
			if(mode<=0) { FXF_pgod[playerid]=0; }
			else { FXF_pgod[playerid]=1; } } }
	forward IsPlayerGod(playerid);
	public IsPlayerGod(playerid) { return FXF_pgod[playerid]; }
//---------------------------------------------------------------------------//

//------------------------------< IsPlayerInWater >------------------------------//
	forward IsPlayerInWater(playerid);
	public IsPlayerInWater(playerid)
	{
		new Float:FXF_wpos[3];
		GetPlayerPos(playerid,FXF_wpos[0],FXF_wpos[1],FXF_wpos[2]);
		if((FXF_wpos[2] > 0.00) || IsPlayerInZone(playerid,1808.2019,1424.5392,-2230.5024,-2347.7979)) { return 0; }
		else if((FXF_wpos[2] < 0.00) && (FXF_wpos[2] > -1.00)) { return 1; }
		else if(FXF_wpos[2] < -1.00) { return 2; }
		return 0;
	}
//--------------------------------------------------------------------------------//

//--------------------------------< IsPlayer(I/O)nAny... >-------------------------------//
	forward IsPlayerInAnyPlane(playerid);
	public IsPlayerInAnyPlane(playerid) {
		if(IsPlayerInAnyVehicle(playerid)) {
			new FXF_vehicle = GetVehicleModel(GetPlayerVehicleID(playerid));
			if(FXF_vehicle == 460 || FXF_vehicle == 476 || FXF_vehicle == 511 || FXF_vehicle == 512 || FXF_vehicle == 513 || FXF_vehicle == 519 || FXF_vehicle == 520 || FXF_vehicle == 553 || FXF_vehicle == 577 || FXF_vehicle == 592 || FXF_vehicle == 593) {
				return 1; } }
		return 0; }
	forward IsPlayerInAnyHelicopter(playerid);
	public IsPlayerInAnyHelicopter(playerid) {
		if(IsPlayerInAnyVehicle(playerid)) {
			new FXF_vehicle = GetVehicleModel(GetPlayerVehicleID(playerid));
			if(FXF_vehicle == 417 || FXF_vehicle == 425 || FXF_vehicle == 447 || FXF_vehicle == 469 || FXF_vehicle == 487 || FXF_vehicle == 488 || FXF_vehicle == 497 || FXF_vehicle == 548 || FXF_vehicle == 563) {
				return 1; } }
		return 0; }
	forward IsPlayerOnAnyBoat(playerid);
	public IsPlayerOnAnyBoat(playerid) {
		if(IsPlayerInAnyVehicle(playerid)) {
			new FXF_vehicle = GetVehicleModel(GetPlayerVehicleID(playerid));
			if(FXF_vehicle == 430 || FXF_vehicle == 446 || FXF_vehicle == 452 || FXF_vehicle == 453 || FXF_vehicle == 454 || FXF_vehicle == 472 || FXF_vehicle == 473 || FXF_vehicle == 484 || FXF_vehicle == 493 || FXF_vehicle == 595) {
				return 1; } }
		return 0; }
	forward IsPlayerOnAnyBike(playerid);
	public IsPlayerOnAnyBike(playerid) {
		if(IsPlayerInAnyVehicle(playerid)) {
			new FXF_vehicle = GetVehicleModel(GetPlayerVehicleID(playerid));
			if(FXF_vehicle == 448 || FXF_vehicle == 461 || FXF_vehicle == 462 || FXF_vehicle == 463 || FXF_vehicle == 468 || FXF_vehicle == 471 || FXF_vehicle == 481 || FXF_vehicle == 409 || FXF_vehicle == 510 || FXF_vehicle == 521 || FXF_vehicle == 522 || FXF_vehicle == 523 || FXF_vehicle == 581 || FXF_vehicle == 586) {
				return 1; } }
		return 0; }
//---------------------------------------------------------------------------------------//

//----------------------------------------: FilterScript :---------------------------------//
stock FilterScriptInit(fsname[]) { format(FXF_str,sizeof(FXF_str),"loadfs %s",fsname); SendRconCommand(FXF_str); }
stock FilterScriptExit(fsname[]) { format(FXF_str,sizeof(FXF_str),"unloadfs %s",fsname); SendRconCommand(FXF_str); }
stock FilterScriptReload(fsname[]) { format(FXF_str,sizeof(FXF_str),"reloadfs %s",fsname); SendRconCommand(FXF_str); }
//-----------------------------------------------------------------------------------------//

//--------------------------------< Place player into cemetery >-------------------------------//
	stock PlacePlayerIntoCemetery(playerid,time) {
		FXF_pcem[playerid] = 1;
		SetPlayerPos(playerid,823.5046,-1102.9376,25.7891);
		SetPlayerWorldBounds(playerid,953.606994,808.260070,-1071.376586,-1130.194335);
		SetPlayerVirtualWorld(playerid,1);
		ResetPlayerWeapons(playerid);
		SetWorldTime(23);
		SetPlayerWeather(playerid, 16);
		SetPlayerFacingAngle(playerid,270.0);
		SetCameraBehindPlayer(playerid);
		SetTimerEx("RemovePlayerFromCemetery",time,0,"i",playerid);
		CallLocalFunction("OnPlayerEnterCemetery","i",playerid);}

	forward IsPlayerOnCemetery(playerid);
	public IsPlayerOnCemetery(playerid) { return FXF_pcem[playerid]; }

	forward RemovePlayerFromCemetery(playerid);
	public RemovePlayerFromCemetery(playerid) {
		FXF_pcem[playerid] = 0;
		RemovePlayerWorldBounds(playerid);
		SetCameraBehindPlayer(playerid);
		SetPlayerVirtualWorld(playerid,0);
		SetPlayerWeather(playerid,0);
		CallLocalFunction("OnPlayerLeaveCemetery","i",playerid);
		SpawnPlayer(playerid); }
//---------------------------------------------------------------------------------------------//

/*-----------------------------------------< Vehicle Engine >-----------------------------------------//
	stock ToggleVehicleEngine(FXF_vehicleid,toggle)
	{
		if(toggle<1) {
			toggle=0;
		} else if(toggle>0) {
			toggle=1; }
		FXF_veh_engine[FXF_vehicleid]=toggle;
		for(new i=0;i<MAX_PLAYERS;i++) {
			if((IsPlayerInVehicle(i,FXF_vehicleid)) && (GetPlayerState(i) == PLAYER_STATE_DRIVER)) {
				new FXF_pid=i;
				TogglePlayerControllable(FXF_pid,toggle); } } }
	forward IsVehicleEngineStarted(FXF_vehicleid);
	public IsVehicleEngineStarted(FXF_vehicleid) { return FXF_veh_engine[FXF_vehicleid]; }
	forward GetVehicleEngineStatus(FXF_vehicleid);
	public GetVehicleEngineStatus(FXF_vehicleid) { return FXF_veh_engine[FXF_vehicleid]; }
//----------------------------------------------------------------------------------------------------*/

//-----------------------------------------------------: IsPlayerInZone :---------------------------------------------------//
	forward IsPlayerInZone(playerid, Float:minX, Float:minY, Float:maxX, Float:maxY);
	public IsPlayerInZone(playerid, Float:minX, Float:minY, Float:maxX, Float:maxY) {
	    new Float:FXF_ZoneX, Float:FXF_ZoneY, Float:FXF_ZoneZ;
		GetPlayerPos(playerid, FXF_ZoneX, FXF_ZoneY, FXF_ZoneZ);
		if((FXF_ZoneX >= minX && FXF_ZoneX <= maxX) && (FXF_ZoneY >= minY && FXF_ZoneY <= maxY) && FXF_ZoneZ <= 500) { return 1; }
		return 0; }
//--------------------------------------------------------------------------------------------------------------------------//

//-----------------------------------------------------------------------: Send Distanced Client Message :-----------------------------------------------------------------------//
	forward SendDistancedClientMessage(playerid, Float:radi, message[], col1,col2,col3,col4,col5);
	public SendDistancedClientMessage(playerid, Float:radi, message[], col1,col2,col3,col4,col5)
	{
		if(IsPlayerConnected(playerid))
		{
			new Float:FXF_posx, Float:FXF_posy, Float:FXF_posz;
			new Float:FXF_oldposx, Float:FXF_oldposy, Float:FXF_oldposz;
			new Float:FXF_tempposx, Float:FXF_tempposy, Float:FXF_tempposz;
			GetPlayerPos(playerid, FXF_oldposx, FXF_oldposy, FXF_oldposz);
			for(new i = 0; i < MAX_PLAYERS; i++)
			{
				if(IsPlayerConnected(i))
				{
					GetPlayerPos(i, FXF_posx, FXF_posy, FXF_posz);
					FXF_tempposx = (FXF_oldposx -FXF_posx);
					FXF_tempposy = (FXF_oldposy -FXF_posy);
					FXF_tempposz = (FXF_oldposz -FXF_posz);
					if (((FXF_tempposx < radi/16) && (FXF_tempposx > -radi/16)) && ((FXF_tempposy < radi/16) && (FXF_tempposy > -radi/16)) && ((FXF_tempposz < radi/16) && (FXF_tempposz > -radi/16)))
					{
						return SendClientMessage(i, col1, message);
					}
					else if (((FXF_tempposx < radi/8) && (FXF_tempposx > -radi/8)) && ((FXF_tempposy < radi/8) && (FXF_tempposy > -radi/8)) && ((FXF_tempposz < radi/8) && (FXF_tempposz > -radi/8)))
					{
						return SendClientMessage(i, col2, message);
					}
					else if (((FXF_tempposx < radi/4) && (FXF_tempposx > -radi/4)) && ((FXF_tempposy < radi/4) && (FXF_tempposy > -radi/4)) && ((FXF_tempposz < radi/4) && (FXF_tempposz > -radi/4)))
					{
						return SendClientMessage(i, col3, message);
					}
					else if (((FXF_tempposx < radi/2) && (FXF_tempposx > -radi/2)) && ((FXF_tempposy < radi/2) && (FXF_tempposy > -radi/2)) && ((FXF_tempposz < radi/2) && (FXF_tempposz > -radi/2)))
					{
						return SendClientMessage(i, col4, message);
					}
					else if (((FXF_tempposx < radi) && (FXF_tempposx > -radi)) && ((FXF_tempposy < radi) && (FXF_tempposy > -radi)) && ((FXF_tempposz < radi) && (FXF_tempposz > -radi)))
					{
						return SendClientMessage(i, col5, message);
					}
				}
			}
		}
		return 0; //Returns FALSE if anything's going wrong
	}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

//------------------------------------------//
stock gmreload() { SendRconCommand("gmx"); }
//------------------------------------------//

////////////////////////////////////////////////////////////////////////////
forward FXF_ChecKeR();
public FXF_ChecKeR() {
	for(new i=0;i<GetMaxPlayers();i++) {
		if(IsPlayerConnected(i)) {
		//Godmode
			if(FXF_pgod[i]) { SetPlayerHealth(i,999); }
		//TogglePlayerControllable Mode 2 Add
			if(FXF_pCamToggle[i]==1) {
				if((GetPlayerState(i) == PLAYER_STATE_DRIVER) || (pIsVeh[i][0] != 987321)) {
					PutPlayerInVehicle(i,pIsVeh[i][0],pIsVeh[i][1]);
					SetVehiclePos(pIsVeh[i][0],pos[i][0],pos[i][1],pos[i][2]); SetVehicleZAngle(pIsVeh[i][0],veh_ang[pIsVeh[i][0]]); }
				else if(GetPlayerState(i) == PLAYER_STATE_ONFOOT) {
					FXF_SetPlayerPos(i,pos[i][0],pos[i][1],pos[i][2]); FXF_SetPlayerFacingAngle(i,pos[i][3]); } }
		//OnPlayerChangeWeapon
			if(FXF_curGun[i]==999) { FXF_curGun[i]=GetPlayerWeapon(i); }
			if(FXF_curGun[i]!=GetPlayerWeapon(i)) {
				CallLocalFunction("OnPlayerChangeWeapon","idd",i,GetPlayerWeapon(i),FXF_curGun[i]);
				FXF_curGun[i]=GetPlayerWeapon(i); } } } }
///////////////////////////////////////////////////////////////////////////
public OnPlayerDeath(playerid,killerid,reason) {
	pkillerid[playerid]=killerid; if(FXF_killerspec[playerid]>0){
		pspec[playerid]=1;}
	CallLocalFunction("FXF_OnPlayerDeath","iid",playerid,killerid,reason); }
public OnPlayerSpawn(playerid) {
	if(pspec[playerid] == 1) {
		pspec[playerid] = 0; TogglePlayerSpectating(playerid,1); PlayerSpectatePlayer(playerid,pkillerid[playerid]); SetTimerEx("killerspectate_stop",FXF_killerspec[playerid],0,"i",playerid); return 1; }
	return CallLocalFunction("FXF_OnPlayerSpawn","i",playerid); }
public OnPlayerConnect(playerid) {
//Checktimer must be started if it isn't started already
	if(!FXF_checkTimerStarted) { SetTimer("FXF_ChecKeR",FXF_CHECK_TIME,1); FXF_checkTimerStarted=1; }
//Godmode disable on OnPlayerConnect
	FXF_pgod[playerid]=0;
//other
	pos[playerid][0]=987321; pos[playerid][1]=987321; pos[playerid][2]=987321; pos[playerid][3]=987321;
	pIsVeh[playerid][0]=987321; pIsVeh[playerid][1]=987321; FXF_status[playerid]=0;
	CallLocalFunction("FXF_OnPlayerConnect","i",playerid); }
public OnPlayerStateChange(playerid, newstate, oldstate) {
	if((newstate == PLAYER_STATE_DRIVER) || (newstate == PLAYER_STATE_PASSENGER)) { FXF_pOldVeh[playerid]=GetPlayerVehicleID(playerid); FXF_pOldSeat[playerid]=GetPlayerVehicleSeat(playerid); }
	/*if((newstate == PLAYER_STATE_DRIVER) && (FXF_veh_engine[GetPlayerVehicleID(playerid)] == 0)) { TogglePlayerControllable(playerid, 0); }*/
	if(((oldstate == PLAYER_STATE_DRIVER) || (oldstate == PLAYER_STATE_PASSENGER)) && (newstate == PLAYER_STATE_ONFOOT)) {
		if((FXF_ABFall[playerid]==1) && (FXF_pLeaveVeh[playerid]==0)) {
			PutPlayerInVehicle(playerid,FXF_pOldVeh[playerid],FXF_pOldSeat[playerid]); }else{ FXF_pLeaveVeh[playerid]=0; } }
	CallLocalFunction("FXF_OnPlayerStateChange","idd",playerid,newstate,oldstate); }
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	/*if(IsPlayerInAnyVehicle(playerid) && (GetPlayerState(playerid)==PLAYER_STATE_DRIVER) && (FXF_veh_engine[GetPlayerVehicleID(playerid)]==0) && (newkeys & KEY_SECONDARY_ATTACK)) {
		RemovePlayerFromVehicle(playerid); TogglePlayerControllable(playerid,1); }*/
	CallLocalFunction("FXF_OnPlayerKeyStateChange","idd",playerid,newkeys,oldkeys); }
public OnVehicleSpawn(vehicleid) {
/*	#if !defined STOP_ENGINE_ON_VSPAWN
		ToggleVehicleEngine(vehicleid,1);
	#endif
	if(vehicleid == 441 || vehicleid == 464 || vehicleid == 465 || vehicleid == 501 || vehicleid == 564 || vehicleid == 594 || vehicle == 509 || vehicle == 481 || vehicle == 510) {
		ToggleVehicleEngine(vehicleid,1); }*/
	CallLocalFunction("FXF_OnVehicleSpawn","d",vehicleid); }
public OnPlayerExitVehicle(playerid, vehicleid) {
	if(FXF_ABFall[playerid]==1) { FXF_pLeaveVeh[playerid] = 1; }
	CallLocalFunction("FXF_OnPlayerExitVehicle","id",playerid,vehicleid); }

forward killerspectate_stop(playerid);
public killerspectate_stop(playerid) { pspec[playerid]=0; TogglePlayerSpectating(playerid,0); SpawnPlayer(playerid); }

forward FXF_TogglePlayerControllable(playerid,mode);
public FXF_TogglePlayerControllable(playerid,mode) {
	if(mode == 0 || mode == 1) {
		pos[playerid][0]=987321;
		pos[playerid][1]=987321;
		pos[playerid][2]=987321;
		pos[playerid][3]=987321;
		pIsVeh[playerid][0]=987321;
		pIsVeh[playerid][1]=987321;
		FXF_status[playerid]=0;
		FXF_pCamToggle[playerid]=0;
		TogglePlayerControllable(playerid,mode); }
	else if(mode >= 2) {
	    if(IsPlayerInAnyVehicle(playerid)) {
			pIsVeh[playerid][0]=GetPlayerVehicleID(playerid);
			pIsVeh[playerid][1]=GetPlayerVehicleSeat(playerid);
			GetVehicleZAngle(pIsVeh[playerid][0],veh_ang[pIsVeh[playerid][0]]); }
	    GetPlayerPos(playerid,pos[playerid][0],pos[playerid][1],pos[playerid][2]);
	    GetPlayerFacingAngle(playerid,pos[playerid][3]);
		TogglePlayerControllable(playerid,1);
		FXF_pCamToggle[playerid] = 1;
		/*return 1;*/ }
	/*return 0;*/ }

forward FXF_SetPlayerPos(playerid,Float:x,Float:y,Float:z);
public FXF_SetPlayerPos(playerid,Float:x,Float:y,Float:z) { pos[playerid][0]=x; pos[playerid][1]=y; pos[playerid][2]=z; SetPlayerPos(playerid,x,y,z); }

forward FXF_SetPlayerFacingAngle(playerid,Float:ang);
public FXF_SetPlayerFacingAngle(playerid,Float:ang) { pos[playerid][3]=ang; SetPlayerFacingAngle(playerid,ang); }

forward FXF_SetVehicleZAngle(FXF_vehicleid,Float:ang);
public FXF_SetVehicleZAngle(FXF_vehicleid,Float:ang) { veh_ang[FXF_vehicleid]=ang; SetVehicleZAngle(FXF_vehicleid,ang); }

forward FXF_RemovePlayerFromVehicle(playerid);
public FXF_RemovePlayerFromVehicle(playerid) { FXF_pLeaveVeh[playerid]=1; return RemovePlayerFromVehicle(playerid); }

#define OnPlayerDeath FXF_OnPlayerDeath
#define OnPlayerSpawn FXF_OnPlayerSpawn
#define OnPlayerConnect FXF_OnPlayerConnect
#define OnPlayerStateChange FXF_OnPlayerStateChange
#define OnPlayerKeyStateChange FXF_OnPlayerKeyStateChange
#define OnVehicleSpawn FXF_OnVehicleSpawn
#define OnPlayerExitVehicle FXF_OnPlayerExitVehicle
#define IsPlayerAbfEnabled IsPlayerAntiBikeFallEnabled
#define TogglePlayerControllable FXF_TogglePlayerControllable
#define SetPlayerPos FXF_SetPlayerPos
#define SetPlayerFacingAngle FXF_SetPlayerFacingAngle
#define SetVehicleZAngle FXF_SetVehicleZAngle
#define RemovePlayerFromVehicle FXF_RemovePlayerFromVehicle