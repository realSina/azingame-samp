/*
	NoSpam by Donny 2009
	--------------------

	About:
	------
	
		A simple library to handle user spamming on features such as chat and commands.
		It can be used anywhere but some types will clash so make sure to read on.
	
	
	Usage:
	------
	
		#include <nospam>	
	
	
	Controlling protection:
	-----------------------
	
		You can control which features you want blocking and which not by using one of the four
		defines below, each one will turn off spam protection for that type.
		
		IGNORE_CHAT_PROTECTION
		IGNORE_COMMAND_PROTECTION
		IGNORE_KEY_PROTECTION
		IGNORE_UDST_PROTECTION
	
		
	Explination of types:
	---------------------
	
		A type is just the slot in the array, it has four slots so we can use the existing
		three types of spam seperately (chat, commands, keys) and then we can add additional
		ones using the UDST type.
		
		Normal types (first three) are local blocks, they only block the type of callback they
		are linked to like the chat one still allows you to use commands and vice versa but the
		user defined spam type is a global block and will stop you being able to use any of the
		callbacks it is linked to until the period of time ends. You can still use any of the first
		three types whilst being blocked by a UDST but if you have more than one callback which uses
		the UDST type then all those callbacks will be blocked (also explained below).		

		
	A user defined type example:
	----------------------------
	
		OnPlayerClickPlayer( ......
		{
			StopPlayerSpam( playerid, SPAM_PERIOD_UDST, true, SPAM_TYPE_UDST );
			
		The above would stop the player being able to register a player click until the interval
		has passed but it would also stop any other UDST from registering also as explained above.
*/

#if defined _nospam_included
	#endinput
#endif
#define _nospam_included

#if !defined _samp_included
	#error "Please include the 'a_samp' header above this one (#include <a_samp>)"
#endif
	
/*
	This is the current spam protections count, it stores how many features we block by default.
	It's currently four as we have chat, commands, keys and UDST so the array needs four slots
	and you don't have to change it really unless you modify the script to include more default
	types of protection, adding a UDST doesn't mean this has to grow as UDST types are global (one slot).
*/	

#define MAX_PROTECTION_TYPES		4	
	
/*
	These are the default periods of time the player will have to wait before using a feature again,
	it's in seconds as milliseconds are too quick IMO. 
	
	The default period is set to 3 seconds for each define and we use a quick preproc check to make 
	sure they're above zero as this would defeat the whole purpose of the system.
	
	We also add a little define in there to control if the script needs to run or not as if all forms
	of protection are being ignored then there is no point running the script any longer.
*/

#if !defined IGNORE_CHAT_PROTECTION
	#if !defined SPAM_PERIOD_CHAT 
		#define SPAM_PERIOD_CHAT		3
	#endif
	
	#if SPAM_PERIOD_CHAT < 1
		#error "The SPAM_PERIOD_CHAT value must be greater than 0"
	#endif	
	
	#if !defined CONTINUE_INPUT
		#define CONTINUE_INPUT
	#endif
#endif

#if !defined IGNORE_COMMAND_PROTECTION
	#if !defined SPAM_PERIOD_COMMAND
		#define SPAM_PERIOD_COMMAND		3
	#endif

	#if SPAM_PERIOD_COMMAND < 1
		#error "The SPAM_PERIOD_COMMAND value must be greater than 0"
	#endif
	
	#if !defined CONTINUE_INPUT
		#define CONTINUE_INPUT
	#endif
#endif

#if !defined IGNORE_KEY_PROTECTION
	#if !defined SPAM_PERIOD_KEY
		#define SPAM_PERIOD_KEY			3
	#endif
	
	#if SPAM_PERIOD_KEY < 1
		#error "The SPAM_PERIOD_KEY value must be greater than 0"
	#endif	
	
	#if !defined CONTINUE_INPUT
		#define CONTINUE_INPUT
	#endif
#endif

#if !defined IGNORE_UDST_PROTECTION
	#if !defined SPAM_PERIOD_UDST
		#define SPAM_PERIOD_UDST		3
	#endif		

	#if SPAM_PERIOD_UDST < 1
		#error "The SPAM_PERIOD_UDST value must be greater than 0"
	#endif
	
	#if !defined CONTINUE_INPUT
		#define CONTINUE_INPUT
	#endif
#endif
	
// Kill the script, no protection is being used
#if !defined CONTINUE_INPUT
	#endinput
#endif	
	
/*
	This enum is so we can use a 'type' parameter in our 'StopPlayerSpam' function without
	having to remember the type ids and it doubles as the array slot to use so we don't kill 
	all the features at once as if we just had one type then everything would be blocked at once.
	
	If you use SPAM_TYPE_UDST (user defined spam type) then this blocks all features
	it is linked to for the given period of time where as the other three types are local
	and only block the one they are named after, SPAM_TYPE_CHAT only blocks chat and so on
	because the value is the same as the slot in the array, it only uses that slot so it can
	only ever block that type of feature.
*/

enum
{
	SPAM_TYPE_CHAT = 0,
	SPAM_TYPE_COMMAND,
	SPAM_TYPE_KEY,
	SPAM_TYPE_UDST
}	
	
new
	// This is used to store the last time the player used a feature so we can check if they are spamming.
	g_NS_LastTime[ MAX_PLAYERS ][ MAX_PROTECTION_TYPES ];	
	
/* 
	This is our spam define, this is where we check against the last time the player used a feature
    then we respond accordingly by returning the passed value or storing the new time.
	
    The arguments are:
   
		%1 = playerid - the player
		%2 = interval - the period of time to block the feature for
		%3 = return value - the callbacks return, this isn't a function !
		%4 = spam type - the type of spam we are protecting against, we have four types (look above)
*/

#define StopPlayerSpam(%1,%2,%3,%4) 	if ( ( gettime() - g_NS_LastTime[ %1 ][ %4 ] ) < %2 ) return %3; \
										else g_NS_LastTime[ %1 ][ %4 ] = gettime()		
												
// Callback hooks
	
public OnPlayerConnect( playerid )
{
	// Reset the players time array to 0 as they have just connected.
	for ( new i; i < MAX_PROTECTION_TYPES; i ++ ) g_NS_LastTime[ playerid ][ i ] = 0;
	
	// Call the next OnPlayerConnect callback, in this case the "Spam_" prefix is used.
	return CallRemoteFunction( "Spam_OnPlayerConnect", "i", playerid );
}	

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect Spam_OnPlayerConnect
forward Spam_OnPlayerConnect( playerid );

public OnPlayerDisconnect( playerid, reason )
{
	// Reset the players time array to 0 as they have just disconnected.
	for ( new i; i < MAX_PROTECTION_TYPES; i ++ ) g_NS_LastTime[ playerid ][ i ] = 0;
	
	// Call the next OnPlayerDisconnect callback, in this case the "Spam_" prefix is used.
	return CallRemoteFunction( "Spam_OnPlayerDisconnect", "ii", playerid, reason );
}	

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect Spam_OnPlayerDisconnect
forward Spam_OnPlayerDisconnect( playerid, reason );

#if !defined IGNORE_CHAT_PROTECTION

public OnPlayerText( playerid, text[] )
{
	// Stop the player spamming in the chat.
	StopPlayerSpam( playerid, SPAM_PERIOD_CHAT, false, SPAM_TYPE_CHAT );

	// Call the next OnPlayerText callback, in this case the "Spam_" prefix is used.
	// This is only called if the player isn't spamming.
	return CallRemoteFunction( "Spam_OnPlayerText", "is", playerid, text );
}		

#if defined _ALS_OnPlayerText
	#undef OnPlayerText
#else
	#define _ALS_OnPlayerText
#endif

#define OnPlayerText Spam_OnPlayerText
forward Spam_OnPlayerText( playerid, text[] );

#endif

#if !defined IGNORE_COMMAND_PROTECTION

public OnPlayerCommandText( playerid, cmdtext[] )
{
	// Stop the player spamming a command, I use 'true' here so we don't get the SUC message.
	StopPlayerSpam( playerid, SPAM_PERIOD_COMMAND, true, SPAM_TYPE_COMMAND );

	// Call the next OnPlayerCommandText callback, in this case the "Spam_" prefix is used.
	// This is only called if the player isn't spamming.
	return CallRemoteFunction( "Spam_OnPlayerCommandText", "is", playerid, cmdtext );
}		

#if defined _ALS_OnPlayerCommandText
	#undef OnPlayerCommandText
#else
	#define _ALS_OnPlayerCommandText
#endif

#define OnPlayerCommandText Spam_OnPlayerCommandText
forward Spam_OnPlayerCommandText( playerid, cmdtext[] );

#endif

#if !defined IGNORE_KEY_PROTECTION

public OnPlayerKeyStateChange( playerid, newkeys, oldkeys )
{
	// Stop the player spamming keys.
	StopPlayerSpam( playerid, SPAM_PERIOD_KEY, false, SPAM_TYPE_KEY );

	// Call the next OnPlayerKeyStateChange callback, in this case the "Spam_" prefix is used.
	// This is only called if the player isn't spamming.
	return CallRemoteFunction( "Spam_OnPlayerKeyStateChange", "iii", playerid, newkeys, oldkeys );
}

#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif

#define OnPlayerKeyStateChange Spam_OnPlayerKeyStateChange
forward Spam_OnPlayerKeyStateChange( playerid, newkeys, oldkeys );

#endif