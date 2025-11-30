/*
==============================
    FcukIt Anti-Cash-Cheat
	    Include File
      Coded By Scarface
==============================
*/

#pragma unused EZ_DeleteProperty
#pragma unused EZ_ExistProperty

new cashb[MAX_PLAYERS];

FcukIt_ResetPlayerMoney(playerid)
{
	ResetPlayerMoney(playerid);
	new gptmp[32], id[8], tmpcash[32] = "0";
	valstr(id, playerid, false);
	strins(gptmp, "c", 0, 32);
	strins(gptmp, id, 1, 32);
	EZ_SetProperty(gptmp, tmpcash);
}

FcukIt_GivePlayerMoney(playerid, amount)
{
	GivePlayerMoney(playerid, amount);
	cashb[playerid] += amount;
	new gptmp[32], id[8], tmpcash[32];
	valstr(id, playerid, false);
	strins(gptmp, "c", 0, 32);
	strins(gptmp, id, 1, 32);
	valstr(tmpcash, (strval(EZ_GetProperty(gptmp)) + amount), false);
	EZ_SetProperty(gptmp, tmpcash);
}

stock EZ_SetProperty(name[], string[])
{
	strpack(string, string, 256);
	setproperty(0, "", hash(name), string);
}

stock EZ_GetProperty(name[])
{
	new string[256];
    getproperty(0, "", hash(name), string);
    strunpack(string, string, 256);
    return string;
}

stock EZ_DeleteProperty(name[])
{
	if(existproperty(0, "", hash(name))){
    deleteproperty(0,"",hash(name));}
    else {
	printf("<EZ-GSP> Property Does Not Exist (%s)", name);
	}
}

stock EZ_ExistProperty(name[])
{
	if(existproperty(0, "", hash(name))) return 1;
	return 0;
}

stock hash(etmp[])
{
    new i;
    new s1 = 1;
    new s2 = 0;
    new length=strlen(etmp);
    for (i=0; i<length; i++)
	{
       s1 = (s1 + etmp[i]) % 65521;
       s2 = (s2 + s1)     % 65521;
 	}
    return (s2 << 16) + s1;
}