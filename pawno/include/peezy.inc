																							/*
																							
First of all. I will not take credit of this. The only thing I have done is
inlcude all the functions. That's it Thank You People for using this
Best Regards

																							*/






#if defined _peezy_included
	#endinput
#endif
#define _peezy_included
#pragma library functions

//#pragma unused tabsize

#pragma dynamic 1000000


new cage[MAX_PLAYERS], cage2[MAX_PLAYERS], cage3[MAX_PLAYERS], cage4[MAX_PLAYERS], caged[MAX_PLAYERS];
stock CagePlayer(playerid)
{
      if(IsPlayerConnected(playerid))
      {
      new Float:X, Float:Y, Float:Z;
      GetPlayerPos(playerid, X, Y, Z);
      cage[playerid] = CreateObject(985, X, Y+4, Z, 0.0, 0.0, 0.0);
      cage2[playerid] = CreateObject(985, X+4, Y, Z, 0.0, 0.0, 90.0);
      cage3[playerid] = CreateObject(985, X-4, Y, Z, 0.0, 0.0, 270.0);
      cage4[playerid] = CreateObject(985, X, Y-4, Z, 0.0, 0.0, 180.0);
      caged[playerid] = 1; // Use this in a /cage command to prevent being caged twice and causing the cage to be unremovable.
      PlayerPlaySound(playerid, 1137, X, Y, Z);
      }
}
stock UnCagePlayer(playerid)
{
      cage[playerid] = DestroyObject(cage[playerid]);
      cage2[playerid] = DestroyObject(cage2[playerid]);
      cage3[playerid] = DestroyObject(cage3[playerid]);
      cage4[playerid] = DestroyObject(cage4[playerid]);
      caged[playerid] = 0;
}
stock SendClientMessageToAllEx(exception, color, const message[])
{
  for(new i; i<MAX_PLAYERS; i++)
  {
    if(IsPlayerConnected(i))
 	{
	  if(i != exception)
	  {
	    SendClientMessage(i, color, message);
	  }
	}
  }
}
stock GetVehicleDriver(vehicleid)
{
  for(new i; i<MAX_PLAYERS; i++)
  {
    if (IsPlayerInVehicle(i, vehicleid))
    {
      if(GetPlayerState(i) == 2)
      {
    		return i;
      }
	}
  }
  return -1;
}

stock Admin(msg[])
{
  for(new i 0; i<GetMaxPlayers(); i++
  {
    if(IsPlayerConnected(i) && IsPlayerAdmin(i)) SendClientMessage(i,white,msg);
  }
}
stock IsPlayerInInvalidNosVehicle(playerid,vehicleid)
{
  #define MAX_INVALID_NOS_VEHICLES 29

  new InvalidNosVehicles[MAX_INVALID_NOS_VEHICLES] =
  {
    581,523,462,521,463,522,461,448,468,586,
    509,481,510,472,473,493,595,484,430,453,
    452,446,454,590,569,537,538,570,449
  };

  vehicleid = GetPlayerVehicleID(playerid);

  if(IsPlayerInVehicle(playerid,vehicleid))
  {
        for(new i = 0; i < MAX_INVALID_NOS_VEHICLES; i++)
        {
          if(GetVehicleModel(vehicleid) == InvalidNosVehicles[i])
          {
            return true;
          }
        }
  }
  return false;
}
stock CheckPlayerName(const name[]) // by Luk0r
{
    if (strlen(name) < 6) return 0;
    if (strfind(name, "_", true) == -1) return 0;
    new underscorecount, expectinguppercase = 1;
    for (new i = 0, j = strlen(name); i < j; i++)
    {
        if (expectinguppercase == 1)
        {
            if (name[i] < 'A' || name[i] > 'Z') return 0;
            expectinguppercase = 0;
            continue;
        }
        switch (name[i])
        {
            case '_':
            {
                if (underscorecount == 1) return 0;
                else
                {
                    underscorecount = 1;
                    expectinguppercase = 1;
                }
                continue;
            }
            case 'A' .. 'Z': continue;
            case 'a' .. 'z': continue;
            default: return 0;
        }
    }
    return 1;
}
stock IsABoat(carid)
{
  new Operative[] = { 472, 473, 493, 495, 484, 430, 454, 453, 452, 446 };
  for(new i = 0; i < sizeof(Operative); i++)
  {
    if(GetVehicleModel(carid) == i) return 1;
  }
  return 0;
}
stock RPName(name[],ret_first[],ret_last[])
{
	new len = strlen(name),
		point = -1,
		bool:done = false;
	for(new i = 0; i < len; i++)
	{
	  if(name[i] == '_')
	  {
	    if(point != -1) return 0;
	    else {
				if(i == 0) return 0;
				point = i + 1;
			}
	  } else if(point == -1) ret_first[i] = name[i];
	  else {
			ret_last[i - point] = name[i];
			done = true;
		}
	}
	if(!done) return 0;
	return 1;
}
new VehicleNames[][] = {
	"Landstalker","Bravura","Buffalo","Linerunner","Pereniel","Sentinel","Dumper","Firetruck","Trashmaster","Stretch","Manana","Infernus","Voodoo","Pony","Mule","Cheetah","Ambulance","Leviathan","Moonbeam","Esperanto",
	"Taxi","Washington","Bobcat","Mr Whoopee","BF Injection","Hunter","Premier","Enforcer","Securicar","Banshee","Predator","Bus","Rhino","Barracks","Hotknife","Trailer","Previon","Coach","Cabbie","Stallion",
	"Rumpo","RC Bandit","Romero","Packer","Monster","Admiral","Squalo","Seasparrow","Pizzaboy","Tram","Trailer","Turismo","Speeder","Reefer","Tropic","Flatbed","Yankee","Caddy","Solair","Berkley's RC Van",
	"Skimmer","PCJ-600","Faggio","Freeway","RC Baron","RC Raider","Glendale","Oceanic","Sanchez","Sparrow","Patriot","Quad","Coastguard","Dinghy","Hermes","Sabre","Rustler","ZR3 50","Walton","Regina",
	"Comet","BMX","Burrito","Camper","Marquis","Baggage","Dozer","Maverick","News Chopper","Rancher","FBI Rancher","Virgo","Greenwood","Jetmax","Hotring","Sandking","Blista Compact","Police Maverick","Boxville","Benson",
	"Mesa","RC Goblin","Hotring Racer","Hotring Racer","Bloodring Banger","Rancher","Super GT","Elegant","Journey","Bike","Mountain Bike","Beagle","Cropdust","Stunt","Tanker","RoadTrain","Nebula","Majestic","Buccaneer","Shamal",
	"Hydra","FCR-900","NRG-500","HPV1000","Cement Truck","Tow Truck","Fortune","Cadrona","FBI Truck","Willard","Forklift","Tractor","Combine","Feltzer","Remington","Slamvan","Blade","Freight","Streak","Vortex",
	"Vincent","Bullet","Clover","Sadler","Firetruck","Hustler","Intruder","Primo","Cargobob","Tampa","Sunrise","Merit","Utility","Nevada","Yosemite","Windsor","Monster","Monster","Uranus","Jester",
	"Sultan","Stratum","Elegy","Raindance","RC Tiger","Flash","Tahoma","Savanna","Bandito","Freight","Trailer","Kart","Mower","Duneride","Sweeper","Broadway","Tornado","AT-400","DFT-30","Huntley",
	"Stafford","BF-400","Newsvan","Tug","Trailer","Emperor","Wayfarer","Euros","Hotdog","Club","Trailer","Trailer","Andromada","Dodo","RC Cam","Launch","Police Car (LSPD)","Police Car (SFPD)","Police Car (LVPD)","Police Ranger",
	"Picador","S.W.A.T. Van","Alpha","Phoenix","Glendale","Sadler","Luggage Trailer","Luggage Trailer","Stair Trailer","Boxville","Farm Plow","Utility Trailer"
};

stock GetVehicleName(modelid,name[],namesize)
{
	if(modelid < 400 || modelid > 611) return 0;
	modelid -= 400;
	for(new i = 0, len = strlen(VehicleNames[modelid]); i < len && i < namesize; i++)
	    name[i] = VehicleNames[modelid][i];
	return 1;
}

stock GetObjectToPlayerDistance(playerid, objectid) //By me, Credits: Whoever made GetDistanceBetweenPlayers
{
    new Float:ox, Float:oy, Float:oz, Float:px, Float:py, Float:pz;
    new Float:distance;
    GetObjectPos(objectid, ox, oy, oz);
    GetPlayerPos(playerid, px, py, pz);
    distance = floatsqroot(floatpower(floatabs(floatsub(ox, px)),2)+floatpower(floatabs(floatsub(oy, py)),2)+floatpower(floatabs(floatsub(oz, pz)),2));
    return floatround(distance);
}
stock GetDistanceFromPlayerToVehicle(playerid, vehicleid)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    new Float:tmpdis;
    GetPlayerPos(playerid,x1,y1,z1);
    GetVehiclePos(vehicleid2,x2,y2,z2);
    tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
    return floatround(tmpdis);
}
stock GetVehiclePlayerID(vehicleid)
{
    for(new i=0; i<MAX_PLAYERS; i++)
    {
        if(vehicleid == GetPlayerVehicleID(i))
        {
            return vehicleid;
        }
    }
    return INVALID_PLAYER_ID;
}
stock GetDistanceBetweenVehicles(vehicleid, vehicleid2)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    new Float:tmpdis;
    GetVehiclePos(vehicleid,x1,y1,z1);
    GetVehiclePos(vehicleid2,x2,y2,z2);
    tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
    return floatround(tmpdis);
}
stock GetDistanceBetweenPlayers(playerid, playerid2)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    new Float:tmpdis;
    GetPlayerPos(playerid,x1,y1,z1);
    GetPlayerPos(playerid2,x2,y2,z2);
    tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
    return floatround(tmpdis);
}
stock GetPlayerVehicleModel(playerid)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    new model = GetVehicleModel(vehicleid);
    return model;
}
stock SafeKill(playerid)
{
  new Weapons[MAX_PLAYERS][11], Ammo[MAX_PLAYERS][11]; // news
  for(new j=0; j<11; j++)   GetPlayerWeaponData(playerid, j, Weapons[playerid][j], Ammo[playerid][j]);// loop through all weapon slots + ammo
  SpawnPlayer(playerid); //respawn the player
  for(new j=0; j<11; j++)   GivePlayerWeapon(playerid, Weapons[playerid][j], Ammo[playerid][j]);// loop through all weapon slots + ammo
}
stock RemovePlayerWeapon(playerid, weaponid)
{
    new plyWeapons[12]
    new plyAmmo[12]

    for(new slot = 0; slot != 12; slot++)
    {
        new wep, ammo
        GetPlayerWeaponData(playerid, slot, wep, ammo)

        if(wep != weaponid)
        {
            GetPlayerWeaponData(playerid, slot, plyWeapons[slot], plyAmmo[slot])
        }
    }

    ResetPlayerWeapons(playerid)
    for(new slot = 0; slot != 12; slot++)
    {
        GivePlayerWeapon(playerid, plyWeapons[slot], plyAmmo[slot])
    }
}
stock GiveAllMoneyHealthArmour(money, Float:health, Float:armour)
{
  for(new i=0; i<GetMaxPlayers(); i++)
  {
    new Float:pHealth, Float:pArmour;
    GetPlayerHealth(i, pHealth);
    GetPlayerArmour(i, pArmour);
    SetPlayerHealth(i, pHealth+health);
    SetPlayerArmour(i, pArmour+armour);
    GivePlayerMoney(i, money);
  }
  return true;
}
stock GetUserIP(playerid) { new uip[16]; GetPlayerIp(playerid, uip, 16); return uip; }
stock IsAGirlFriendSkin(skinid) { if(skinid == 195 || skinid == 190 || skinid == 191 || skinid == 192 || skinid == 193 || skinid == 194) return 1; return 0; }
stock IsAAztecaSkin(skinid) { if(skinid == 114 || skinid == 115 || skinid == 116) return 1; return 0; }
stock IsAVagosSkin(skinid) { if(skinid == 108 || skinid == 109 || skinid == 110) return 1; return 0; }
stock IsAGroveSkin(skinid) { if(skinid == 105 || skinid == 106 || skinid == 107) return 1; return 0; }
stock IsABallasSkin(skinid) { if(skinid == 102 || skinid == 103 || skinid == 104) return 1; return 0; }
stock IsAMeleeWeapon(weaponid) { if(weaponid >= 0 && weaponid < 15 }
new Text:Subtitle[MAX_PLAYERS] = Text:INVALID_TEXT_DRAW;
stock ShowSubtitle(playerid, text[], time = 5000, override = 1)
{
    if(time < 1 || !IsPlayerConnected(playerid))
      return 0;

    if(Subtitle[playerid] != Text:INVALID_TEXT_DRAW)
    {
      if(!override)
        return 0;
        else
          HideSubtitle(playerid); // Hide the current one.
    }

    new string[512];
    format(string, sizeof(string), "~w~%s", text);
    Subtitle[playerid] = TextDrawCreate(375.000000, 360.000000, string);
    TextDrawAlignment(Subtitle[playerid], 2);
    TextDrawBackgroundColor(Subtitle[playerid], 255);
    TextDrawFont(Subtitle[playerid], 1);
    TextDrawLetterSize(Subtitle[playerid], 0.480000, 2.400000);
    TextDrawColor(Subtitle[playerid], -1);
    TextDrawSetOutline(Subtitle[playerid], 0);
    TextDrawSetProportional(Subtitle[playerid], 1);
    TextDrawSetShadow(Subtitle[playerid], 2);
    TextDrawUseBox(Subtitle[playerid], 1);
    TextDrawBoxColor(Subtitle[playerid], 572661504);
    TextDrawTextSize(Subtitle[playerid], 0.000000, 438.000000);

    TextDrawShowForPlayer(playerid, Subtitle[playerid]);

    SetPVarInt(playerid, "SubtitleTimer", SetTimerEx("HideSubtitle", time, 0, "i", playerid));

    if(Subtitle[playerid] != Text:INVALID_TEXT_DRAW)
        return 1;
    else
      return 0;
}

forward HideSubtitle(playerid);
public HideSubtitle(playerid)
{
    TextDrawHideForPlayer(playerid, Subtitle[playerid]);
    TextDrawDestroy(Subtitle[playerid]);
    Subtitle[playerid] = Text:INVALID_TEXT_DRAW;

    KillTimer(GetPVarInt(playerid, "SubtitleTimer"));
    DeletePVar(playerid, "SubtitleTimer");

    return 1;
}
stock TeleportPlayerToPlayer(player, player2);
{
    new Float:pos[3];
    GetPlayerPos(player2, pos[0], pos[1], pos[2]);
    if(IsPlayerInAnyVehicle(player)) SetVehiclePos(GetPlayerVehicleID(player), pos[0], pos[1], pos[3];
    else SetPlayerPos(player, pos[0]+1, pos[1]-1, pos[3]+2);
    return 1;
}


//---------- NEW ON V2 ------------//



stock RangeBan(playerid)
{
    new pos, oldpos, ip[15], ip2[15], tmp[21];

    GetPlayerIp(playerid, ip, sizeof(ip));

    pos = strfind(ip, ".", true);
    pos++;

    for(new i = 0; i < pos; i++)
    {
        ip2[i] = ip[pos-pos+i];
    }

    pos--;

    ip[pos] = ' ';

    oldpos = pos;
    oldpos++;

    pos = strfind(ip, ".", true);
    pos++;

    for(new i = oldpos; i < pos; i++)
    {
        ip2[i] = ip[pos-pos+i];
    }

    format(ip2, sizeof(ip2), "%s*.*", ip2);
    format(tmp, sizeof(tmp), "banip %s", ip2);

    SendRconCommand(tmp);
    return ip2;
}

public IsInFourDoor(playerid)
{
	new carid = GetPlayerVehicleID(playerid);
	new vid = GetVehicleModel(carid);
	if(vid == 582 || vid == 413 || vid == 567 || vid == 566 || vid == 579 || vid == 400 || vid == 470 || vid == 438 || vid == 427 || vid == 490 || vid == 598 || vid == 596 )
	{
		return 1;
	}
	if(vid == 597 || vid == 420 || vid == 445 || vid == 507 || vid == 585 || vid == 466 || vid == 492 || vid == 546 || vid == 551 || vid == 516 || vid == 467 || vid == 426)
	{
	    return 1;
	}
	if(vid == 547 || vid == 405 || vid == 480 || vid == 560 || vid == 550 || vid == 540 || vid == 529 || vid == 421 || vid == 418 || vid == 404 || vid == 479 || vid == 458 || vid == 561)
	{
	    return 1;
	}
	return 0;
}
stock isdigit(c)
{
	if(c >= '0' && c <= '9') return 1;
	else return 0;
}
stock isspace(c)
{
	if(c == ' ') return 1;
	else return 0;
}
stock GetCentury()
{
	new century, year, month, day;

	getdate(year, month, day);
	if(year > - 1) {
		century = ((year / 100) + 1);
	}
	return century;
}
stock isprint(c)
{
	if(c >= 0x20 && c <= 0x7E) return 1;
	else return 0;
}
stock CelsiusToFahrenheit(degrees)
{
	new f;
	f = degrees + 32;
	return f;
}
stock FahrenheitToCelsius(degrees)
{
	new c;
	c = degrees - 32;
	return c;
}
stock CelsiusToKelvin(degrees)
{
	new k;
	k = degrees + 273;
	return k;
}
stock KelvinToCelsius(degrees)
{
	new c;
	c = degrees - 273;
	return c;
}
stock GetPlayerFullname(partofname[])
{
    new id = GetPlayerID(partofname), pname[MAX_PLAYER_NAME];
    if(id != INVALID_PLAYER_ID) GetPlayerName(id, pname, MAX_PLAYER_NAME);
    return pname;
}
stock SetVehicleSpeed(vehicleid, Float:Speed)
{
  new
    Float:X,
    Float:Y,
    Float:Z,
    Float:Angle;

  GetVehicleZAngle(vehicleid, Angle);
  Speed = Speed/200;
  X = Speed * floatsin(-Angle, degrees);
  Y = Speed * floatcos(-Angle, degrees);
  SetVehicleVelocity(vehicleid, X, Y, Z);
}
stock Teleport(playerid, Float:X, Float:Y, Float:Z)
{
  if(IsPlayerInAnyVehicle(playerid))
  {
    new VehicleID = GetPlayerVehicleID(playerid);
    SetVehiclePos(VehicleID, X, Y, Z);
  }
  else if(!IsPlayerInAnyVehicle(playerid))
  {
    SetPlayerPos(playerid, X, Y, Z);
  }
}
stock CrashPlayer(playerid)
{
	for(new i=0;i<=50;i++)
	{
		new temp = CreateVehicle(476,0,0,0,0,0,0,0);
		LinkVehicleToInterior(temp,1050);
		PutPlayerInVehicle(playerid,temp,4);
		SetPlayerInterior(playerid,20);
		SetPlayerVirtualWorld(playerid,17);
		SetVehicleVirtualWorld(temp,14518);
        DestroyVehicle(temp);
	}
    SetPlayerInterior(playerid,0);
    SetPlayerVirtualWorld(playerid,0);
	Kick(playerid);
	return 1;
}
stock GetAveragePing()
{
	new players,good;
	for(new i = 0; < GetMaxPlayers(); i++)
	{
		if(IsPlayerConnected(i))
		{
			good+=GetPlayerPing(i);
			players++;
		}
	}
	return floatround(good/players);
}
stock ChangeTextDrawColorForAll(Text:txtid, color) {
     TextDrawHideForAll(txtid);
     TextDrawColor(txtid,color);
     TextDrawShowForAll(txtid);
}

stock ChangeTextDrawColorForPlayer(playerid, Text:txtid, color) {
     TextDrawHideForPlayer(playerid, txtid);
     TextDrawColor(txtid,color);
     TextDrawShowForPlayer(playerid, txtid);
}
new Text:Blind;
new PlayerIsBlind[MAX_PLAYERS]; >> OnPlayerConnect should be set to 0

forward CreateTextDrawForAll(); >> put it in OnGameModeInit();
forward SetPlayerBlind(playerid,toggle);

public CreateTextDrawForAll()
{
    Blind = TextDrawCreate(0.0,0.0,"00000"); //For /blind cmd
    TextDrawUseBox(Blind,1);
    TextDrawBoxColor(Blind,0x000000FF);
    TextDrawTextSize(Blind,950,950);
    TextDrawFont(Blind,3);
    TextDrawLetterSize(Blind,5,100);
    TextDrawColor(Blind,0x000000FF);
}

public SetPlayerBlind(playerid,toggle)
{
    if(toggle == 1)
    {
        TextDrawShowForPlayer(playerid,Blind);
        PlayerIsBlind[playerid] = 1;
    }
    else if (toggle == 0)
    {
        TextDrawHideForPlayer(playerid,Blind);
        PlayerIsBlind[playerid] = 0;
    }
}
stock DoesPlayerHaveAnyWeapon(playerid)
{
    new
        iWeaponID,
        iAmmo;

    for(new i =0; i < 13; i++)
    {
        GetPlayerWeaponData(playerid, i, iWeaponID, iAmmo);

        if(iWeaponID > 0 && iAmmo > 0)
        {
            return 1;
        }
    }
    return 0;
}
stock DoesPlayerHaveWeapon(playerid, weaponid, slot)
{
    if(weaponid < 0 || weaponid > 50)
        return 0;

    static iWeaponData[2];
    // 0 = weapon
    // 1 = ammo

    GetPlayerWeaponData(playerid, slot, iWeaponData[0], iWeaponData[1]);

    if(iWeaponData[0] == weaponid && iWeaponData[1] > 0)
        {
        return 1;
    }
    return 0;
}

SetObjectFacePoint(objectid,Float:X,Float:Y)
{
    new Float:pX, Float:pY,Float: pZ,Float:ang;
    GetObjectPos(objectid, pX, pY, ang);
    if( Y > pY ) ang = (-acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 90.0);
    else if( Y < pY && X < pX ) ang = (acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 450.0);
    else if( Y < pY ) ang = (acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 90.0);
    if(X > pX) ang = (floatabs(floatabs(ang) + 180.0)); else ang = (floatabs(ang) - 180.0);
    GetObjectRot(objectid,pX,pY,pZ); SetObjectRot(objectid,pX,pY,ang);
    return 1;
} // Edited,  Tannz0rz's SetPlayerToFacePlayer function

stock SaveStringToFile(content[], filename[])
{
     new File:usfl = fopen(filename, io_append);
     fwrite(usfl, content);
     fclose(usfl);
}

LineCount(filepath[])
{
    new idx = 0;
    if(fexist(filepath))
    {
        new File:Handler, string[1028];
        Handler = fopen(filepath, io_read);
        while(fread(Handler, string)){idx++;}
        fclose(Handler);
    }
    return idx;
}

GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance)
{   // Created by Y_Less

    new Float:a;

    GetPlayerPos(playerid, x, y, a);
    GetPlayerFacingAngle(playerid, a);

    if (GetPlayerVehicleID(playerid)) {
        GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
    }

    x += (distance * floatsin(-a, degrees));
    y += (distance * floatcos(-a, degrees));
}
stock sortWords(words[][], A_to_Z, size = sizeof(words))
{
    for(new x; x != size - 1; ++x)
    {
        for(new y = x; y != size; ++y)
        {
            if((!A_to_Z) ? (strcmp(words[x], words[y]) < 0) : (strcmp(words[x], words[y]) > 0))
            {
                new
                    string[16]
                ;
                format(string, sizeof(string), words[x]);
                format(words[x], sizeof(string), words[y]);
                format(words[y], sizeof(string), string);
            }
        }
    }
    return 1;
}
stock IsPlayerOnFoot(playerid)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) return 1;
    return 0;
}

stock IsPlayerAlive(playerid)
{
    new Float:health;
    GetPlayerHealth(playerid,health);
    if (health > 0.0) return 1;
    return 0;
}
stock IsPlayerSpawned( iPlayer )
{
    new
        iState = GetPlayerState( iPlayer )
    ;

    switch ( iState )
    {
        case PLAYER_STATE_NONE, PLAYER_STATE_SPECTATING, PLAYER_STATE_WASTED:
            return false;
    }

    return true;
}
stock SpawnVehicle(playerid, vehicleid, color1, color2)
{
        new Float:x, Float:y, Float:z, Float:angle;
        if(IsPlayerInAnyVehicle(playerid)) return 0;
		else GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, angle);
		new vid = CreateVehicle(vehicleid, x, y, z+1, angle, color1, color2, 1000);
		LinkVehicleToInterior(vid, GetPlayerInterior(playerid));
		SetVehicleVirtualWorld(vid, GetPlayerVirtualWorld(playerid));
		PutPlayerInVehicle(playerid, vid, 0);
        return 1;
}

stock TeleportVehicle(vehicleid, Float:x, Float:y, Float:z, Float:a, Int, World)
{
    SetVehiclePos(vehicleid, x, y, z);
    SetVehicleZAngle(vehicleid, a);
    LinkVehicleToInterior(vehicleid, Int);
    SetVehicleVirtualWorld(vehicleid, World);
    foreach(Player, i)
    {
        if(IsPlayerInVehicle(i, vehicleid))
        {
            SetPlayerInterior(i, Int);
            SetPlayerVirtualWorld(i, World);
        }
    }
}

stock TeleportVehicleEx(vehicleid, Float:x, Float:y, Float:z, Int, World)
{
    new Float:angle;
    GetVehicleZAngle(vehicleid, angle);
    TeleportVehicle(vehicleid, x, y, z, angle, Int, World);
}
FileRename(fileorigem[],filerename[]) //by drakins [FeK]Company
{
    new string[512]; //512 Caraters
    new File:fileo = fopen(fileorigem, io_read);
    new File:filer = fopen(filerename, io_write);
    while(fread(fileo, string))
    {
        fwrite(filer,string);
    }
    fclose(filer);
    fclose(fileo);
    fremove(fileorigem);
    printf("%s for %s",fileorigem,filerename);
    format(string,sizeof string,"%s",EOS); //Change string for EOS
    return 1;
}
stock CreateQuadrateFromPos(Float:x,Float:y,Float:distance) //by drakins
{
    new Float:xmax,Float:ymax,Float:ymin,Float:xmin;
    xmax = x + distance; xmin = x - distance;
    ymax = y + distance; ymin = y - distance;
    return true;
}

