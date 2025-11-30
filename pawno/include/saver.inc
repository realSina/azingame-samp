/*---------------------------------Important-------------------------------------*/
//**INCLUDES**//
#include <A_samp>
#include <Dini>
#include <Dutils>
#include <Dudb>

//**PRAGMAS**//
#pragma tabsize 0
#pragma unused ret_memcpy

//**FORWARDS**//
forward ToD_OnPlayerDisconnect(playerid);
forward ToD_OnPlayerConnect(playerid);

//**NEWS**//
new pname[MAX_PLAYER_NAME];
new oyunism[48];
/*---------------------------------CallBacks-------------------------------------*/
public ToD_OnPlayerDisconnect(playerid){
GetPlayerName(playerid, pname, sizeof(pname));
format(oyunism, sizeof(oyunism), "/Saver/%s.ini",pname);
if(!dini_Exists(oyunism))
{
}
else
{
dini_IntSet(oyunism, "Score", GetPlayerScore(playerid));
dini_IntSet(oyunism, "Money", GetPlayerMoney(playerid));
}
}
public ToD_OnPlayerConnect(playerid){
GetPlayerName(playerid, pname, sizeof(pname));
format(oyunism, sizeof(oyunism), "/Saver/%s.ini",pname);
if(!dini_Exists(oyunism))
{
dini_Create(oyunism);
dini_IntSet(oyunism, "Score", 0);
dini_IntSet(oyunism, "Money", 0);
SetPlayerScore(playerid, dini_Int(oyunism, "Score"));
SetPlayerMoney(playerid, dini_Int(oyunism, "Money"));
}
else
{
SetPlayerScore(playerid, dini_Int(oyunism, "Score"));
SetPlayerMoney(playerid, dini_Int(oyunism, "Money"));
}
return 1;
}