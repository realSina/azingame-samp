/*
 * ----------------------------------------------------------------------------
 * ----                      The AlexPoison Anticheat                      ----
 * ----                             v1.5a                                  ----
 * ----------------------------------------------------------------------------
 * ----                           Scripter:                                ----
 * ----                          AlexPoison11                              ----
 * ----                                                                    ----
 * ----                             Idea:                                  ----
 * ----                          AlexPoison11                              ----
 * ----                                                                    ----
 * ----                          Thanks To:                                ----
 * ----                            LethaL                                  ----
 * ----------------------------------------------------------------------------
 * ----                 (c) 2010 All Rights Reserved.                      ----
 * ----------------------------------------------------------------------------
*/

/* -- [ -- [ include ] -- ] -- */
#include <a_samp>

/* -- [ -- [ define ] -- ] -- */
#define LOG_FILE "TAP/log.txt"
#define MAX_STRING 256
#define MAX_SPAMTEXT 3

#define COLOR_RED                                                     0xFF0000FF

/* -- [ -- [ enum ] -- ] -- */
enum Info
{
	bool:Jetpack,
	bool:Spectating,
	bool:Weapon,
	bool:Money,
	bool:TextSpam,
	bool:CheckRCONFail,
	bool:Health,
	bool:Armor,
	bool:Bot,
	MaxPing
};

/* -- [ -- [ new ] -- ] -- */
new Anticheat[Info];
new CurrCash[MAX_PLAYERS], Cash[MAX_PLAYERS];
new UltText[MAX_PLAYERS], SpamText[MAX_PLAYERS];

/* -- [ -- [ forward ] -- ] -- */
forward DetectCheat(playerid);

public OnFilterScriptInit()
{
	print("|--------------------------------------|");
	print("|--| ~      The AlexPoison        ~ |--|");
	print("|--| ~        Anticheat           ~ |--|");
	print("|--| ~         Loaded!            ~ |--|");
	print("|--------------------------------------|");
	Anticheat[Jetpack] = true; //Change true or false
	Anticheat[Spectating] = false; //Change true or false
	Anticheat[Weapon] = true; //Change true or false
	Anticheat[Money] = true; //Change true or false
	Anticheat[MaxPing] = 800; //Change 800 for max ping.
	Anticheat[TextSpam] = true; //Change true or false
	Anticheat[CheckRCONFail] = true; //Change true or false
	Anticheat[Health] = true; //Change true or false
	Anticheat[Armor] = true; //Change true or false
	Anticheat[Bot] = true; //Change true or false
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

public OnPlayerConnect(playerid)
{
	new pip[26];
	GetPlayerIp(playerid, pip, sizeof(pip));
	if(!strcmp(pip, "255.255.255.255", false) || GetPlayerPing(playerid) < 2)
	{
	    new str[MAX_STRING], strtofile[MAX_STRING];
	    format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been banned by System. (Reason: Bot)",PlayerName(playerid),playerid);
		format(strtofile, sizeof(strtofile), "%s (%d) has been banned by System. (Reason: Bot)",PlayerName(playerid),playerid);
		SendClientMessageToAll(COLOR_RED, str);
		SaveToFile(LOG_FILE, strtofile);
		Ban(playerid);
	}
	return 1;
}

public OnPlayerText(playerid, text[])
{
	if(Anticheat[TextSpam] == true)
	{
	    if(!strcmp(UltText[playerid], text, true))
	    {
			SpamText[playerid]++;
			if(SpamText[playerid] >= MAX_SPAMTEXT)
			{
			    new str[MAX_STRING], strtofile[MAX_STRING];
			    format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been kicked by System. (Reason: Text Spamming)",PlayerName(playerid),playerid);
				format(strtofile, sizeof(strtofile), "%s (%d) has been kicked. (Reason: Text Spamming)",PlayerName(playerid),playerid);
				SendClientMessageToAll(COLOR_RED, str);
				SaveToFile(LOG_FILE, strtofile);
				Kick(playerid);
			}
		}
		for(new i = 0; i < strlen(text); i++)
		{
			UltText[playerid] = text[i];
		}
	}
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(Anticheat[Spectating] == true)
	{
	    if(newstate == PLAYER_STATE_SPECTATING)
	    {
	        new str[MAX_STRING], strtofile[MAX_STRING];
	        format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been banned by System. (Reason: Spectating)",PlayerName(playerid),playerid);
			format(strtofile, sizeof(strtofile), "%s (%d) has been banned. (Reason: Spectating)",PlayerName(playerid),playerid);
			SendClientMessageToAll(COLOR_RED, str);
			SaveToFile(LOG_FILE, strtofile);
			Ban(playerid);
		}
	}
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	if(Anticheat[CheckRCONFail] == true)
	{
	    if(!success)
	    {
		    new strtofile[MAX_STRING];
		    format(strtofile, sizeof(strtofile), "IP: %s || RCON Password to try: %s (Reason: Fail RCON Login)",ip,password);
			SaveToFile(LOG_FILE, strtofile);
		}
	}
	return 1;
}

public DetectCheat(playerid)
{
	if(Anticheat[Jetpack] == true)
	{
	    if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
	    {
	        new str[MAX_STRING], strtofile[MAX_STRING];
	        format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been banned by System. (Reason: Jetpack)",PlayerName(playerid),playerid);
	        format(strtofile, sizeof(strtofile), "%s (%d) has been banned. (Reason: Jetpack)",PlayerName(playerid),playerid);
			SendClientMessageToAll(COLOR_RED, str);
			SaveToFile(LOG_FILE, strtofile);
			Ban(playerid);
		}
	}
	if(Anticheat[Weapon] == true)
	{
		new weapon, ammo, str[MAX_STRING], strtofile[MAX_STRING];
		GetPlayerWeaponData(playerid, 7, weapon, ammo);
		if(weapon == 38)
		{
		    format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been banned by System. (Reason: Minigun)",PlayerName(playerid),playerid);
		    format(strtofile, sizeof(strtofile), "%s (%d) has been banned. (Reason: Minigun)",PlayerName(playerid),playerid);
		    SendClientMessageToAll(COLOR_RED, str);
		    SaveToFile(LOG_FILE, strtofile);
		    Ban(playerid);
		}
		if(weapon == 36 || weapon == 35)
		{
		    format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been banned by System. (Reason: Rocket Launcher)",PlayerName(playerid),playerid);
		    format(strtofile, sizeof(strtofile), "%s (%d) has been banned. (Reason: Rocket Launcher)",PlayerName(playerid),playerid);
		    SendClientMessageToAll(COLOR_RED, str);
		    SaveToFile(LOG_FILE, strtofile);
		    Ban(playerid);
		}
		if(weapon == 39)
		{
			format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been banned by System. (Reason: Satchel Charge's)",PlayerName(playerid),playerid);
			format(strtofile, sizeof(strtofile), "%s (%d) has been banned. (Reason: Satchel Charge's)",PlayerName(playerid),playerid);
			SendClientMessageToAll(COLOR_RED, str);
			SaveToFile(LOG_FILE, strtofile);
			Ban(playerid);
		}
	}
	if(Anticheat[Money] == true)
	{
		if(CurrCash[playerid] < GetPlayerMoney(playerid))
		{
		    new str[MAX_STRING], strtofile[MAX_STRING];
		    format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been banned by System. (Reason: Money Hack)",PlayerName(playerid),playerid);
		    format(strtofile, sizeof(strtofile), "%s (%d) has been banned. (Reason: Money Hack)",PlayerName(playerid),playerid);
			SendClientMessageToAll(COLOR_RED, str);
			SaveToFile(LOG_FILE, strtofile);
			Ban(playerid);
		}
	}
	if(GetPlayerPing(playerid) > Anticheat[MaxPing])
	{
	    new str[MAX_STRING], strtofile[MAX_STRING];
	    format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been kicked by System. (Reason: Max ping is %d)",PlayerName(playerid),playerid,Anticheat[MaxPing]);
		format(strtofile, sizeof(strtofile), "%s (%d) has been kicked by System. (Reason: Your ping is %d/%d (max)",PlayerName(playerid),playerid,GetPlayerPing(playerid),Anticheat[MaxPing]);
		SendClientMessageToAll(COLOR_RED, str);
		SaveToFile(LOG_FILE, strtofile);
		Kick(playerid);
	}
	if(Anticheat[Health] == true)
	{
	    new Float:Healt;
	    GetPlayerHealth(playerid, Healt);
	    if(Healt > 100)
	    {
	        new str[MAX_STRING], strtofile[MAX_STRING];
	        format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been banned by System. (Reason: Health Hacking)",PlayerName(playerid),playerid);
			format(strtofile, sizeof(strtofile), "%s (%d) has been banned. (Reason: Health Hacking)",PlayerName(playerid),playerid);
			SendClientMessageToAll(COLOR_RED, str);
			SaveToFile(LOG_FILE, strtofile);
			Ban(playerid);
		}
	}
	if(Anticheat[Armor] == true)
	{
	    new Float:Armour;
	    GetPlayerArmour(playerid, Armour);
	    if(Armour > 100)
	    {
	        new str[MAX_STRING], strtofile[MAX_STRING];
	        format(str, sizeof(str), "[ANTICHEAT]: %s (%d) has been banned by System. (Reason: Armour Hacking)",PlayerName(playerid),playerid);
			format(strtofile, sizeof(strtofile), "%s (%d) has been banned. (Reason: Armour Hacking)",PlayerName(playerid),playerid);
			SendClientMessageToAll(COLOR_RED, str);
			SaveToFile(LOG_FILE, strtofile);
			Ban(playerid);
		}
	}
	return 1;
}

stock PlayerName(playerid)
{ //By: AlexPoison11
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	return name;
}

stock SaveToFile(filename[],text[])
{ //By: Lethal, Modified: AlexPoison11
	new File:file, filepath[256], string[256], year,month,day, hour,minute,second;
	getdate(year,month,day); gettime(hour,minute,second);

	format(filepath,sizeof(filepath),"%s.txt",filename);
	file = fopen(filepath,io_append);
	format(string,sizeof(string),"[%d.%d.%d %d:%d:%d] %s\r\n",day,month,year,hour,minute,second,text);
	fwrite(file,string);
	fclose(file);

	return 1;
}

stock Anticheat_GivePlayerMoney(playerid, money)
{
	if(!IsPlayerConnected(playerid)) return 0;
	Cash[playerid] = amount;
	GivePlayerMoney(playerid, Cash[playerid]);
	CurrCash[playerid] = GetPlayerMoney(playerid);
	return 1;
}
