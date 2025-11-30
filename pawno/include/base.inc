//
// Created:     05.09.06
// Aurthor:    Iain Gilbert
//

#if defined _base_included
  #endinput
#endif

#define _base_included
#pragma library base

#include <a_samp>
#include <core>
#include <float>
#include "utils\dini"

#define VERSION "v0.5.9.43"

#define debug 0

#define MAX_STRING 255
#define MAX_NAME 40 // number of char's a name/password/misc_word can be
#define INACTIVE_PLAYER_ID 255
#define INVALID_QUEST_ID 0
#define MAX_QUESTS 255
#define MAX_WIN 500000 // Maximum gambling win
#define MAX_SPAWNPOINTS 50
#define MAX_COUNTDOWN 5

#define TimerTick 1000 // used for how often timer function is called

#define COLOUR_GREY 0xAFAFAFAA // grey
#define COLOUR_GREEN 0x33AA33AA // green
#define COLOUR_LIGHTGREEN 0x9ACD32AA //lightgreen
#define COLOUR_RED 0xAA3333AA // red
#define COLOUR_LIGHTRED 0xFF6347AA // lightred
#define COLOUR_YELLOW 0xFFFF00AA // yellow
#define COLOUR_WHITE 0xFFFFFFAA // white
#define COLOUR_BLUE 0x33AAFFAA // blue
#define COLOUR_LIGHTBLUE 0x33CCFFAA // LightBlue
#define COLOUR_ORANGE 0xFF9900AA //orange
#define COLOUR_PURPLE 0xC2A2DAAA //purple

// TODO: more colours
#define COLOUR_MISC 0xAFAFAFAA // Grey - Misc
#define COLOUR_CHAT 0xFFFFFFAA // White - Chat
#define COLOUR_PLAYER 0xAAAAAAAA // White - Player
#define COLOUR_XP_GOOD 0x00C7FFAA // Blue - XP
#define COLOUR_XP_BAD 0x00008BAA // Blue - XP
#define COLOUR_COMBAT_GOOD 0xAA3333AA // Red - Combat
#define COLOUR_COMBAT_BAD 0xBB3333AA // Red - Combat
#define COLOUR_MONEY_GOOD 0xFFFF00AA // Yellow - Money
#define COLOUR_MONEY_BAD 0xDAA520AA // Yellow - Money
#define COLOUR_RACE 0x005407AA // green - dark
#define COLOUR_RACE_BAD 0x545407AA // yellow-green-dark
#define COLOUR_GANG 0xFF8C00AA // orange
#define COLOUR_GANG_CHAT 0xFFA500AA // orange
#define COLOUR_DM 0xFF0066AA // red - purple
#define COLOUR_DM_BAD 0xFF0066AA // red - purple

#define MAX_XP  1400000
#define MAX_LVLXP 1350000

#define MAX_LEVEL 25
#define MIN_HEALTH 20
#define MAX_HEALTH 100
#define NUMVALUES 4	

#define SOUND_MUSIC_CLASSSELECT      1185
#define SOUND_MUSIC_RACEFINISH       1183
#define SOUND_MUSIC_RACERECORD       1097
#define SOUND_MUSIC_MISSIONCOMPLETE  1185
#define SOUND_OFF                    1184
#define SOUND_BLIP1                  1056
#define SOUND_BLIP2                  1057
#define SOUND_EXPLOSION              1159
#define SOUND_PURCHASE               1149
#define SOUND_CHECKPOINT             1058
#define SOUND_DEATH                 1057
#define SOUND_DMKILL                 1056
#define SOUND_DMDEATH                 1057

#define OUTPUTLEVEL 0 // Amount of imformation outputted to console
//              0   -   off, no output
//              1   -   + Minimal output
//              2   -   + DB saves, etc
//              3   -   + XP/Level/Money changes output

#define DBTYPE 0 //	Database type (olny flat file ATM)
//				0	-	dini - flat file
//				1	-	TODO: SQL

new ConfigDB[MAX_STRING] = "GTO/Config/GTO.Config.Base.txt";
new LevelDB[MAX_STRING] = "GTO/Config/GTO.Config.Levels.txt";
new VerboseSave=-1; // do we save extra un-needed db info like weapons, races, vehicels, deathmatches, etc
new RealTime=0;
new ForceOverwrite = 0;


// xyz coord info
enum CoordInfo {
    Float:Coord_X,
    Float:Coord_Y,
    Float:Coord_Z
}

new KickList[MAX_PLAYERS];
new WorldTime;
new DBSeperator= 124; // seperate db fields.atm for db writing im just sending a string, which is written to a file.
new nullstr[MAX_STRING];

enum LevelInfo {
	level_xp,
    level_name[MAX_NAME]
}

// level rank names by Baby Face / Cool
new LevelList[MAX_LEVEL+1][LevelInfo] = { // experience required for each level
{  0,		"Беспризорник" },
{  500,		"Салага" },
{  1000,	"Преступник Забегаловки" },
{  2000,	"Солдат Забегаловки" },
{  5000,	"Лейтенант Забегаловки" },
{  7500,	"Капитан Забегаловки" },
{  11000,	"Уличный Преступник" },
{  16000,	"Уличный Солдат" },
{  21000,	"Уличный Лейтенант" },
{  31000,	"Уличный Капитан" },
{  46000,	"Убийца спящих" },
{  70000,	"Кровожадный Маньяк" },
{  100000,	"Статский Советник" },
{  135000,	"Безбашенный Киллер" },
{  190000,	"Отморозок" },
{  225000,	"Беспредельщик" },
{  300000,	"Карманник-профессионал" },
{  380000,	"Босс хакеров" },
{  480000,	"Кандидат в Депутаты" },
{  590000,	"Депутат городской Думы" },
{  700000, 	"Продюсер Алсу" },
{  820000,	"Хозяин полуострова" },
{  950000,	"Премьер-министр Уругвая" },
{  1200000,	"Владелец фабрик, домов и пароходов" },
{  1350000,	"Президент США" },
{  1400000, 	"Администратор Мира" }
};

BaseLoadConfig()
{
	if (ForceOverwrite) return;
	new temp[MAX_STRING];
	if (!dini_Exists(ConfigDB))
	{
		dini_Create(ConfigDB);
	}
	set(temp,dini_Get(ConfigDB,"Level_DB"));
	if (strlen(temp) > 0) set(LevelDB,temp);
	
	set(temp,dini_Get(ConfigDB,"Verbose_Save"));
	if (strlen(temp) > 0) VerboseSave = strval(temp);
	
	set(temp,dini_Get(ConfigDB,"Real_Time"));
	if (strlen(temp) > 0) RealTime = strval(temp);
	
	if (!dini_Exists(LevelDB))
	{
		BaseSaveConfig();
	}
	for (new i=0;i<=MAX_LEVEL;i++)
	{
		new tempname[MAX_STRING];
	    format(tempname,sizeof(tempname),"Level%d_Rankname",i);
		set(temp,dini_Get(LevelDB,tempname));
		if (strlen(temp) > 0) set(LevelList[i][level_name],temp);
		
		format(tempname,sizeof(tempname),"Level%d_Experience",i);
		set(temp,dini_Get(LevelDB,tempname));
		if (strlen(temp) > 0) LevelList[i][level_xp] = strval(temp);
	}
	return;
}

BaseSaveConfig()
{
	new temp[MAX_STRING];
	if (dini_Exists(ConfigDB))
	{
		dini_Set(ConfigDB,"Level_DB",LevelDB);
		
		valstr(temp,VerboseSave);
		dini_Set(ConfigDB,"Verbose_Save",temp);

        valstr(temp,RealTime);
		dini_Set(ConfigDB,"Real_Time",temp);
	}
	
	if (!dini_Exists(LevelDB))
	{
		dini_Create(LevelDB);
	}
	for (new i=0;i<=MAX_LEVEL;i++)
	{
		new tempname[MAX_STRING];
	    format(tempname,sizeof(tempname),"Level%d_Rankname",i);
		dini_Set(LevelDB,tempname,LevelList[i][level_name]);
		
		format(tempname,sizeof(tempname),"Level%d_Experience",i);
		valstr(temp,LevelList[i][level_xp]);
		dini_Set(LevelDB,tempname,temp);
	}
	return;
}

GetLevelName(level)
{
	new name[MAX_NAME];
	if ((level < 0) || (level > MAX_LEVEL+1)) return name;
	set(name,LevelList[level][level_name]);
	return name;
}
