/* 
 * ===============
 *  INTRODUCTION: 
 * ===============
 * 
 * fixes.inc - Community patch for buggy SA:MP functions.
 * 
 * ================
 *  LIST OF FIXES: 
 * ================
 * 
 * FIX:      GetPlayerColor
 * PROBLEM:  Returns "0" if "SetPlayerColor" has never been called.
 * SOLUTION: Call "SetPlayerColor" in "OnPlayerConnect".
 * SEE:      "OnPlayerConnect".
 * AUTHOR:   KoczkaHUN
 * 
 * FIX:      FILTERSCRIPT
 * PROBLEM:  Despite the fact that is in every new script, many people don't
 *           define "FILTERSCRIPT" where appropriate.
 * SOLUTION: Provide an "IS_FILTERSCRIPT" variable (note the naming to match
 *           the original macro).
 * AUTHOR:   Y_Less
 * SEE:      "OnFilterScriptInit" and "OnGameModeInit".
 * 
 * FIX:      SpawnPlayer
 * PROBLEM:  Kills the player if they are in a vehicle.
 * SOLUTION: Remove the from the vehicle.
 * SEE:      "FIXES_SpawnPlayer".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerName
 * PROBLEM:  Using "SetPlayerName" when the new name only differs from the old
 *           name in case does not alter the name at all.
 * SOLUTION: Change their name twice - once to "_FIXES TEMP NAME" and then to
 *           the actual required name.
 * SEE:      "OnPlayerConnect" and "FIXES_SetPlayerName".
 * AUTHOR:   Y_Less/Slice/xX_Simon_Xx
 * 
 * FIX:      GetPlayerSkin
 * PROBLEM:  Returns the new skin after "SetSpawnInfo" is called but before the
 *           player actually respawns to get the new skin.
 * SOLUTION: Record the skin in "OnPlayerSpawn" and always return that one.
 * SEE:      "OnPlayerSpawn", "FIXES_GetPlayerSkin" and "FIXES_SetPlayerSkin".
 * AUTHOR:   Y_Less
 * 
 * FIX:      GetWeaponName
 * PROBLEM:  Returns nothing for 18, 44, and 45.
 * SOLUTION: Return the correct names ("Molotov Cocktail", "Thermal Goggles",
 *           and "Night vision Goggles").
 * SEE:      "FIXES_GetWeaponName".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerWorldBounds
 * PROBLEM:  Aiming can bypass the edge.
 * SOLUTION: Check for the player leaving the area and reset them to their last
 *           good position if they leave the area (aiming or not).
 * SEE:      "OnPlayerUpdate" and "FIXES_SetPlayerWorldBounds".
 * AUTHOR:   Y_Less
 * 
 * FIX:      TogglePlayerControllable
 * PROBLEM:  Other players see you moving on the spot.
 * SOLUTION: Return 0 in OnPlayerUpdate.
 * SEE:      "FIXES_TogglePlayerControllable" and "OnPlayerUpdate".
 * AUTHOR:   Slice
 * POST:     http://forum.sa-mp.com/showpost.php?p=876854
 * 
 * FIX:      HydraSniper
 * PROBLEM:  Entering military aircraft with a sniper rifle messes up views.
 * SOLUTION: Set their armed weapon to fists.
 * SEE:      "OnPlayerStateChange", "FIXES_GivePlayerWeapon",
 *           "FIXES_SetPlayerArmedWeapon".
 * AUTHOR:   funky1234
 * POST:     http://forum.sa-mp.com/showpost.php?p=965644
 * 
 * FIX:      IsPlayerInCheckpoint
 * PROBLEM:  Function returns an undefined value if it is called before any
 *           other checkpoint functions are called to initialise the value.
 * SOLUTION: Call "DisablePlayerCheckpoint" when they connect.
 * SEE:      "OnPlayerConnect".
 * AUTHOR:   Y_Less
 * 
 * FIX:      IsPlayerInRaceCheckpoint
 * PROBLEM:  Function returns an undefined value if it is called before any
 *           other race checkpoint functions are called to initialise the value.
 * SOLUTION: Call "DisablePlayerRaceCheckpoint" when they connect.
 * SEE:      "OnPlayerConnect".
 * AUTHOR:   Y_Less
 * 
 * FIX:      GetPlayerWeapon
 * PROBLEM:  Returns the old value after using "SetPlayerArmedWeapon" when they
 *           are in a vehicle.
 * SOLUTION: If "SetPlayerArmedWeapon" is called in a vehicle, store the new
 *           value and return that instead.
 * SEE:      "OnPlayerStateChange", "FIXES_SetPlayerArmedWeapon", and
 *           "FIXES_GetPlayerWeapon".
 * AUTHOR:   Y_Less
 * 
 * FIX:      PutPlayerInVehicle
 * PROBLEM:  If this is used on a passenger the driver of their old vehicle
 *           doesn't see them in their new vehicle.
 * SOLUTION: Remove them from the vehicle first.
 * SEE:      "OnPlayerStateChange" and "FIXES_PutPlayerInVehicle".
 * AUTHOR:   leong124/Y_Less
 * POST:     http://forum.sa-mp.com/showpost.php?p=1265965
 * 
 * FIX:      KEY_AIM
 * PROBLEM:  "KEY_AIM" isn't defined by default.
 * SOLUTION: Define it.
 * SEE:      N/A.
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerCheckpoint
 * PROBLEM:  If a checkpoint is already set it will use the size of that
 *           checkpoint instead of the new one.
 * SOLUTION: Call "DisablePlayerCheckpoint" before setting the checkpoint.
 * SEE:      "FIXES_SetPlayerCheckpoint".
 * AUTHOR:   ziggi
 * 
 * FIX:      SetPlayerRaceCheckpoint
 * PROBLEM:  If a checkpoint is already set it will use the size of that
 *           checkpoint instead of the new one.
 * SOLUTION: Call "DisablePlayerRaceCheckpoint" before setting the checkpoint.
 * SEE:      "FIXES_SetPlayerRaceCheckpoint".
 * AUTHOR:   ziggi
 * 
 * FIX:      TextDrawCreate
 * PROBLEM:  Crashes on a blank string.
 * SOLUTION: Intercept blank strings.
 * SEE:      "FIXES_TextDrawCreate".
 * AUTHOR:   wups
 * 
 * FIX:      TextDrawSetString
 * PROBLEM:  Crashes on a blank string and size greater than 1024.
 * SOLUTION: Intercept blank strings and truncate long strings.
 * SEE:      "FIXES_TextDrawSetString".
 * AUTHOR:   TomTrox
 * 
 * FIX:      CreatePlayerTextDraw
 * PROBLEM:  Crashes on a blank string.
 * SOLUTION: Intercept blank strings.
 * SEE:      "FIXES_CreatePlayerTextDraw".
 * AUTHOR:   wups/Y_Less
 * 
 * FIX:      PlayerTextDrawSetString
 * PROBLEM:  Crashes on a blank string and size greater than 1024.
 * SOLUTION: Intercept blank strings and truncate long strings.
 * SEE:      "FIXES_PlayerTextDrawSetString".
 * AUTHOR:   TomTrox/Y_Less
 * 
 * FIX:      AllowInteriorWeapons
 * PROBLEM:  Does nothing.
 * SOLUTION: Set the player's weapon to fists in an interior.
 * SEE:      "FIXES_AllowInteriorWeapons", "OnGameModeInit" and
 *           "OnPlayerUpdate".
 * AUTHOR:   KoczkaHUN
 * 
 * FIX:      OnPlayerEnterVehicle
 * PROBLEM:  Crashes other players when people enter an invalid seat.
 * SOLUTION: Desync the people with invalid seats.
 * SEE:      "OnPlayerStateChange" and "OnPlayerUpdate".
 * AUTHOR:   RyDeR`/Y_Less
 * POST:     http://forum.sa-mp.com/showpost.php?p=1410296
 * 
 * FIX:      OnPlayerEnterVehicle_2
 * PROBLEM:  Crashes the server when hacks enter an invalid vehicle.
 * SOLUTION: Desync the people with invalid vehicles.
 * SEE:      "OnPlayerEnterVehicle".
 * AUTHOR:   im/Y_Less
 * 
 * FIX:      AllowTeleport
 * PROBLEM:  0.3dRC9 removed "AllowPlayerTeleport" and "AllowAdminTeleport" in
 *           favour of "OnPlayerClickMap".  Some scripts used the old code and.
 * SOLUTION: Teleport the player in "OnPlayerClickMap".
 * SEE:      "OnPlayerClickMap", "FIXES_AllowPlayerTeleport", and
 *           "FIXES_AllowAdminTeleport".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerSpecialAction
 * PROBLEM:  Removing jetpacks from players by setting their special action to 0
 *           causes the sound to stay until death.
 * SOLUTION: Call "ClearAnimations" before "SetPlayerSpecialAction".
 * SEE:      "FIXES_SetPlayerSpecialAction".
 * AUTHOR:   MP2
 * 
 * FIX:      OnDialogResponse
 * PROBLEM:  Cheaters can spoof the dialogid they are using to respond to ones
 *           they can't actually see.
 * SOLUTION: Store the displayed dialogid and use that instead.
 * SEE:      "FIXES_OnDialogResponse", "FIXES_ShowPlayerDialog".
 * AUTHOR:   Y_Less
 * FIXED IN: 0.3e RC6
 * 
 * FIX:      GetPlayerDialog
 * PROBLEM:  This function doesn't exist.  Fixed for hidden dialogs.
 * SOLUTION: Add it.  DEFAULTS TO FALSE!
 * SEE:      "FIXES_GetPlayerDialog".
 * AUTHOR:   Y_Less/xX_Simon_Xx
 * 
 * FIX:      PlayerDialogResponse
 * PROBLEM:  A player's dialog doesn't hide when the gamemode restarts, causing
 *           the server to print "Warning: PlayerDialogResponse PlayerId: 0
 *           dialog ID doesn't match last sent dialog ID".
 * SOLUTION: Hide it.
 * SEE:      "OnPlayerConnect", "OnGameModeExit".
 * AUTHOR:   xX_Simon_Xx
 * 
 * FIX:      SetSpawnInfo
 * PROBLEM:  Kicks the player if "SpawnPlayer" is called before "SetSpawnInfo".
 * SOLUTION: Call "SetSpawnInfo" at least once.
 * SEE:      "OnPlayerConnect".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerSkin
 * PROBLEM:  Breaks sitting on bikes.
 * SOLUTION: Put them back in the vehicle after setting their skin.
 * SEE:      "FIXES_SetPlayerSkin".
 * AUTHOR:   CyNiC
 * POST:     http://forum.sa-mp.com/showpost.php?p=1756094
 * 
 * FIX:      HideMenuForPlayer
 * PROBLEM:  Crashes when passed an invalid menu ID.
 * SOLUTION: Don't hide it when passed an invalid menu.
 * SEE:      "FIXES_HideMenuForPlayer".
 * AUTHOR:   Y_Less
 * POST:     http://forum.sa-mp.com/showpost.php?p=1787297
 * 
 * FIX:      valstr
 * PROBLEM:  Crashes on large numbers.
 * SOLUTION: Use "format" instead.
 * SEE:      "FIXES_valstr".
 * AUTHOR:   Slice
 * 
 * FIX:      fclose
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fclose".
 * AUTHOR:   Slice
 * 
 * FIX:      fwrite
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fwrite".
 * AUTHOR:   Slice
 * 
 * FIX:      fread
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fread".
 * AUTHOR:   Slice
 * 
 * FIX:      fputchar
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fputchar".
 * AUTHOR:   Slice
 * 
 * FIX:      fgetchar
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fgetchar".
 * AUTHOR:   Slice
 * 
 * FIX:      fblockwrite
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fblockwrite".
 * AUTHOR:   Slice
 * 
 * FIX:      fblockread
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fblockread".
 * AUTHOR:   Slice
 * 
 * FIX:      fseek
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fseek".
 * AUTHOR:   Slice
 * 
 * FIX:      flength
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_flength".
 * AUTHOR:   Slice
 * 
 * FIX:      file_inc
 * PROBLEM:  Includes or excludes all the file function fixes together (can
 *           cause major overhead).
 * SOLUTION: Optionally group them all under one define.  DEFAULTS TO FALSE!
 * SEE:      "FIX_file_inc".
 * AUTHOR:   Y_Less
 * 
 * FIX:      IsPlayerAttachedObjectSlotUsed
 * PROBLEM:  Doesn't work in OnPlayerDisconnect.
 * SOLUTION: Maintain an internal record of slots used.
 * SEE:      "FIXES_SetPlayerAttachedObject",
 *           "FIXES_RemovePlayerAttachedObject",
 *           "FIXES_IsPAttachedObjectSlotUsed", and
 *           "OnPlayerDisconnect".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerAttachedObject
 * PROBLEM:  Doesn't remove objects when the mode ends.
 * SOLUTION: Remove them.
 * SEE:      "FIXES_SetPlayerAttachedObject",
 *           "FIXES_RemovePlayerAttachedObject", and
 *           "OnPlayerDisconnect".
 * AUTHOR:   Y_Less
 * 
 * FIX:      OnPlayerDeath
 * PROBLEM:  Clients get stuck when they die with an animation applied.
 * SOLUTION: Clear their animations.
 * SEE:      "OnPlayerDeath" and "OnPlayerUpdate".
 * AUTHOR:   h02
 * POST:     http://forum.sa-mp.com/showpost.php?p=1641144
 * 
 * FIX:      strins
 * PROBLEM:  Ignores the "maxlength" parameter causing possible crashes.
 * SOLUTION: Manually check the length.
 * SEE:      "FIXES_strins".
 * AUTHOR:   Slice/Y_Less
 * 
 * FIX:      IsPlayerConnected
 * PROBLEM:  Only uses the lower two bytes of a passed ID.
 * SOLUTION: Mask the numbers.
 * SEE:      "FIXES_IsPlayerConnected".
 * AUTHOR:   Slice
 * 
 * FIX:      OnPlayerCommandText
 * PROBLEM:  Can crash ZCMD when passed a null string.
 * SOLUTION: Pass NULL if invalid inputs given.
 * SEE:      "OnPlayerCommandText".
 * AUTHOR:   Y_Less
 * POST:     http://forum.sa-mp.com/showpost.php?p=1909511
 * 
 * FIX:      TrainExit
 * PROBLEM:  When getting out of a train entered by "PutPlayerInVehicle", the
 *           camera does not reset properly.
 * SOLUTION: Reset the camera.
 * SEE:      "FIXES_PutPlayerInVehicle", "FIXES_OnPlayerStateChange".
 * AUTHOR:   Terminator3/Y_Less
 * 
 * FIX:      Kick
 * PROBLEM:  Calling "Kick" in "OnPlayerConnect" doesn't work properly.
 * SOLUTION: Defer it.
 * SEE:      "OnPlayerConnect", "FIXES_Kick".
 * AUTHOR:   Y_Less
 * POST:     http://forum.sa-mp.com/showpost.php?p=1989453
 * FIXED IN: 0.3x
 * 
 * FIX:      OnVehicleMod
 * PROBLEM:  Crashes other players when invalid mods are applied.
 * SOLUTION: Desync the player.
 * SEE:      "OnVehicleMod".
 * AUTHOR:   JernejL/Y_Less
 * POST:     http://forum.sa-mp.com/showpost.php?p=1671500
 * 
 * FIX:      random
 * PROBLEM:  Doesn't work with negative numbers.
 * SOLUTION: Invert then reinvert.  DEFAULTS TO FALSE!
 * SEE:      "FIXES_random".
 * AUTHOR:   xX_Simon_Xx
 * 
 * FIX:      sleep
 * PROBLEM:  Leaks bytes from the stack.
 * SOLUTION: Call a function to store the correct value.
 * SEE:      "FIXES_sleep".
 * AUTHOR:   Y_Less
 * 
 * FIX:      AddMenuItem
 * PROBLEM:  Crashes when passed an invalid menu ID.
 * SOLUTION: Don't hide it when passed an invalid menu.
 * SEE:      "FIXES_AddMenuItem".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetMenuColumnHeader
 * PROBLEM:  Crashes when passed an invalid menu ID.
 * SOLUTION: Don't hide it when passed an invalid menu.
 * SEE:      "FIXES_SetMenuColumnHeader".
 * AUTHOR:   Y_Less
 * 
 * FIX:      ShowMenuForPlayer
 * PROBLEM:  Crashes when passed an invalid menu ID.
 * SOLUTION: Don't hide it when passed an invalid menu.
 * SEE:      "FIXES_ShowMenuForPlayer".
 * AUTHOR:   Y_Less
 * 
 * FIX:      HideMenuForPlayer
 * PROBLEM:  Crashes when passed an invalid menu ID.
 * SOLUTION: Don't hide it when passed an invalid menu.
 * SEE:      "FIXES_HideMenuForPlayer".
 * AUTHOR:   Y_Less
 * POST:     http://forum.sa-mp.com/showpost.php?p=1787297
 * 
 * FIX:      HideMenuForPlayer_2
 * PROBLEM:  Ignores the "menuid" parameter.
 * SOLUTION: Only hide the correct menu.  DEFAULTS TO FALSE!
 * SEE:      "FIXES_HideMenuForPlayer".
 * AUTHOR:   Y_Less
 * 
 * FIX:      DisableMenu
 * PROBLEM:  Crashes when passed an invalid menu ID.
 * SOLUTION: Don't hide it when passed an invalid menu.
 * SEE:      "FIXES_DisableMenu".
 * AUTHOR:   Y_Less
 * 
 * FIX:      DisableMenuRow
 * PROBLEM:  Crashes when passed an invalid menu ID.
 * SOLUTION: Don't hide it when passed an invalid menu.
 * SEE:      "FIXES_DisableMenuRow".
 * AUTHOR:   Y_Less
 * 
 * FIX:      Menus
 * PROBLEM:  All menu function fixes are included separately for major overhead.
 * SOLUTION: Optionally group them all under one define.
 * SEE:      "FIX_Menus", "_FIX_Menus"
 * AUTHOR:   Y_Less
 * 
 * FIX:      GetPlayerMenu
 * PROBLEM:  Returns previous menu when none is displayed.
 * SOLUTION: Return the correct value.
 * SEE:      "FIXES_GetPlayerMenu", "OnPlayerSelectedMenuRow".
 * AUTHOR:   Y_Less
 * 
 * FIX:      GetPlayerInterior
 * PROBLEM:  Always returns 0 for NPCs.
 * SOLUTION: Return the correct value.
 * SEE:      "FIXES_GetPlayerInterior", "FIXES_SetPlayerInterior".
 * AUTHOR:   Y_Less/xX_Simon_Xx
 * 
 * FIX:      ClearAnimations
 * PROBLEM:  Use ClearAnimation while you are in a vehicle cause the player exit
 *           from it.
 * SOLUTION: Apply an animation instead of clear animation.
 * SEE:      "FIXES_ClearAnimations".
 * AUTHOR:   xX_Simon_Xx
 * 
 * FIX:      ClearAnimations_2
 * PROBLEM:  ClearAnimations doesn't do anything when the animation ends if we
 *           pass 1 for the freeze parameter in ApplyAnimation.
 * SOLUTION: Apply an idle animation for stop and then use ClearAnimation.
 * SEE:      "FIXES_ClearAnimations".
 * AUTHOR:   xX_Simon_Xx
 * 
 * FIX:      DriveBy
 * PROBLEM:  If you press KEY_CROUCH while you're passenger and if you are
 *           armed, the player start to aim; if you repress KEY_CROUCH the
 *           player don't return in vehicle.
 * SOLUTION: Apply the animation to return the player in the vehicle.
 * SEE:      "OnPlayerKeyStateChange".
 * AUTHOR:   xX_Simon_Xx
 * 
 * FIX:      GangZoneCreate
 * PROBLEM:  Gang zones bug on the main map for players at certain angles
 *           relative to them.
 * SOLUTION: Set a non floating value for the gang zone co-ordinate.
 * SEE:      "FIXES_GangZoneCreate".
 * AUTHOR:   xX_Simon_Xx/Y_Less
 * 
 * FIX:      SPECIAL_ACTION_PISSING
 * PROBLEM:  "SPECIAL_ACTION_PISSING" isn't defined by default.
 * SOLUTION: Define it.
 * SEE:      N/A.
 * AUTHOR:   xX_Simon_Xx
 * 
 * FIX:      IsValidVehicle
 * PROBLEM:  "IsValidVehicle" isn't defined by default.
 * SOLUTION: Define it.
 * SEE:      N/A.
 * AUTHOR:   xX_Simon_Xx
 * 
 * FIX:      ApplyAnimation
 * PROBLEM:  Passing an invalid animation library in ApplyAnimation causes a
 *           client crash for streamed in players.
 * SOLUTION: Block ApplyAnimation when an invalid library is passed.
 * SEE:      "FIXES_ApplyAnimation".
 * AUTHOR:   xX_Simon_Xx
 * 
 * FIX:      ApplyAnimation_2
 * PROBLEM:  First time a library is used, it does nothing.
 * SOLUTION: Apply animations twice when first using a library.
 * SEE:      "FIXES_ApplyAnimation".
 * AUTHOR:   xX_Simon_Xx/Lordzy/Y_Less
 * 
 * FIX:      OnPlayerSpawn
 * PROBLEM:  San Andreas deducts $100 from players.
 * SOLUTION: Give them it back.
 * SEE:      "OnPlayerSpawn".
 * AUTHOR:   Y_Less
 * 
 * FIX:      GetGravity
 * PROBLEM:  "GetGravity" isn't defined by default.
 * SOLUTION: Define it.
 * SEE:      N/A.
 * AUTHOR:   Whitetiger
 * POST:     http://forum.sa-mp.com/showpost.php?p=1706447
 * 
 * FIX:      gpci
 * PROBLEM:  "gpci" isn't defined by default.
 * SOLUTION: Define it.
 * SEE:      N/A.
 * AUTHOR:   xX_Simon_Xx
 * POST:     http://pastebin.com/VQSGpbSm
 * 
 * FIX:      Natives
 * PROBLEM:  Several natives are included by default, this enables or disables
 *           them all.  Therefore this is an umbrella fix for several fixes.
 * SOLUTION: Define them.
 * SEE:      "FIX_GetGravity", "FIX_gpci", "FIX_IsValidVehicle".
 * AUTHOR:   Y_Less
 * 
 * FIX:      OnPlayerConnect
 * PROBLEM:  This function isn't called for players when a filterscript starts.
 * SOLUTION: Call it for all connected players.
 * SEE:      "FIXES_OnFilterScriptInit".
 * AUTHOR:   Y_Less
 * 
 * FIX:      OnPlayerDisconnect
 * PROBLEM:  This function isn't called for players when a filterscript ends.
 * SOLUTION: Call it for all connected players.
 * SEE:      "FIXES_OnFilterScriptExit".
 * AUTHOR:   Y_Less
 * 
 * FIX:      GameText
 * PROBLEM:  Several styles do not display for the time specified.
 * SOLUTION: Recreate the styles in Text Draws and use those instead.
 * SEE:      "FIXES_GameTextForAll", "FIXES_GameTextForPlayer".
 * AUTHOR:   Y_Less
 * 
 * FIX:      GameTextStyles
 * PROBLEM:  San Andreas has fixed styles for area and vehicle names, but they
 *           are not included in the GameText styles list.
 * SOLUTION: Add them.  DEFAULTS TO FALSE.
 * SEE:      "FIXES_GameTextForAll", "FIXES_GameTextForPlayer".
 * AUTHOR:   Y_Less
 * 
 * FIX:      HideGameText
 * PROBLEM:  There is no "HideGameTextForXYZ" function.
 * SOLUTION: Show a single space for a game text.  DEFAULTS TO FALSE.
 * SEE:      "FIXES_HideGameTextForAll", "FIXES_HideGameTextForPlayer".
 * AUTHOR:   Y_Less
 * 
 * FIX:      BODYPARTS
 * PROBLEM:  The bodyparts to be used in OnPlayer(Take/Give)Damage are not
 *           defined by default
 * SOLUTION: Define it.
 * SEE:      N/A.
 * AUTHOR:   Whitetiger
 * 
 * FIX:      CAMERAMODES
 * PROBLEM:  The camera modes for GetPlayerCameraMode are not defined by
 *           default.
 * SOLUTION: Define it.
 * SEE:      N/A.
 * AUTHOR:   Whitetiger
 * POST:     http://forum.sa-mp.com/showpost.php?p=1309730
 * 
 * FIX:      SetPlayerCamera
 * PROBLEM:  Using the camera functions directly after enabling spectator mode
 *           doesn't work.
 * SOLUTION: Defer them.
 * SEE:      "FIXES_SetPlayerCameraPos", "FIXES_SetPlayerCameraLookAt",
 *           "FIXES_TogglePlayerSpectating".
 * AUTHOR:   Emmet_
 * 
 * FIX:      SetPlayerTime
 * PROBLEM:  Using this function under "OnPlayerConnect" doesn't work.
 * SOLUTION: Defer it.
 * SEE:      "FIXES_SetPlayerTime"
 * AUTHOR:   Emmet_
 * 
 * FIX:      OnPlayerRequestClass
 * PROBLEM:  Random blunts and bottles sometimes appear in class selection.
 * SOLUTION: Call "RemoveBuildingForPlayer".
 * SEE:      "OnPlayerRequestClass"
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerColor
 * PROBLEM:  If used under OnPlayerConnect, the affecting player will not
 *           see the color in the TAB menu.
 * SOLUTION: Defer it.
 * SEE:      "FIXES_SetPlayerColor"
 * AUTHOR:   Emmet_
 * POST:     http://forum.sa-mp.com/showthread.php?t=452407
 * 
 * FIX:      FileMaths
 * PROBLEM:  You can write gibberish like "File:a; ++a;".
 * SOLUTION: Remove the operators.
 * SEE:      "File:operator"
 * AUTHOR:   Y_Less
 * 
 * FIX:      GetPlayerWeaponData
 * PROBLEM:  Old weapons with no ammo left are still returned.
 * SOLUTION: Set "weapons" to 0.  DEFAULTS TO FALSE!
 * SEE:      "FIXES_GetPlayerWeaponData"
 * AUTHOR:   Y_Less
 * POST:     http://forum.sa-mp.com/showthread.php?t=567400
 * 
 * ==============
 *  STYLE RULES: 
 * ==============
 * 
 * All globals should be "static stock" whenever possible (so they can only be
 *     accessed from this one file).
 * 
 * Statics must start with "FIXES_gs", and all other globals with "FIXES_g".
 * 
 * All functions not overriding existing functions must start with "FIXES_".
 * 
 * Macros must be upper case, use underscores, and start "FIXES_":
 *     "FIXES_LIKE_THIS".
 * 
 * Functions should be upper camel case (as the original functions are)
 *     "FIXES_LikeThis".
 * 
 * Globals (after the prefix) should be upper camel case "LikeThis", and locals
 *     lower camel case "likeThis".
 * 
 * ALS should be used to hook functions and callbacks.  See this topic for more
 *    details:
 *    
 *        http://forum.sa-mp.com/showthread.php?t=441293
 * 
 * The ALS prefix for chaining is "FIXES_".
 * 
 * When redefining a native, add a "BAD_" external name declaration with the
 *     "_ALS_" definition so that others may use the original native if they so
 *     desire (with the caveat that it may break all fixes).  Note the "BAD_"
 *     name is meant to indicate the possibility of breaking the fix, not a
 *     comment on the original native function.
 * 
 * The ALS hook defines used here are a little different to the normal ones as
 *     this file assumes that it is always first.  The pattern is:
 *     
 *         #if defined _ALS_NameOfFixHere
 *             #error _ALS_NameOfFixHere defined
 *         #endif
 *         native BAD_NameOfFixHere(params) = NameOfFixHere;
 *         
 *         #if FIX_NameOfFixHere
 *             stock FIXES_NameOfFixHere(params)
 *             {
 *                 return 0;
 *             }
 *             
 *             #define _ALS_NameOfFixHere
 *             #define NameOfFixHere FIXES_NameOfFixHere
 *         #endif
 *    
 *    A copyable version of this pattern is at the end of the file.
 * 
 * Enums start with "E_" or "e_" depending on type, then follow rules for
 *     macros.
 * 
 * NO libraries should be included - not even the default SA:MP ones.  Let the
 *     user do it.
 * 
 * Due to the above rule, you cannot assume any third party libraries AT ALL, so
 *     do not use them.  This can lead to some code duplication, but also means
 *     that the version of the code used here can be tailored for optimisations.
 * 
 * Certain terms may be shortened when dealing with long callback names to avoid
 *     compile truncation warnings (max symbol length is 31).  Current list:
 *     
 *         "Checkpoint" -> "CP"
 *         "Update"     -> "Upd"
 *         "TextDraw"   -> "TD"
 *         "Object"     -> "Obj"
 *         "Player"     -> "P"
 * 
 * Document all fixes at the top of the file, and highlight code.
 * 
 * 4 space TABS - do not edit this file in PAWNO unless you know how to correct
 *     the indentation.
 * 
 * All rules have exceptions, but they must be justifiable.  For example
 *     "IS_FILTERSCRIPT" is a global variable, but is not called
 *     "FIXES_gIsFilterscript" to better match the "FILTERSCRIPT" macro it
 *     replaces.  Now a macro for "_FIXES_gIsFilterscript".
 * 
 * Variables which need to be fully global (i.e. not "static"), but should not
 *     actually be used by other people (e.g. appear inside a macro) should be
 *     prefixed with "_FIXES" instead of "FIXES" to indicate their private use.
 * 
 * No comments beyond the end of column 80 (where the line in "PAWNO" is).
 * 
 * If a bug is fixed in some version of the server it can be conditionally
 *     included here.  This is done by checking for the existance of a native
 *     function introduced in the same server version.  For example
 *     "TogglePlayerControllable" was fixed in 0.3eRC6, the same time as the
 *     "SetObjectMaterial" native was introduced, thus the inclusion becomes:
 *     
 *         #if !defined FIX_TogglePlayerControllable
 *             #if defined SetObjectMaterial
 *                 #define FIX_TogglePlayerControllable (0)
 *             #else
 *                 #define FIX_TogglePlayerControllable (1)
 *             #endif
 *         #elseif _FIXES_IS_UNSET(FIX_TogglePlayerControllable)
 *             #undef FIX_TogglePlayerControllable
 *             #define FIX_TogglePlayerControllable     (2)
 *         #endif
 *     
 *     This only includes this fix if that native doesn't exist.  A copyable
 *     version of this pattern is at the end of the file.
 * 
 * To reduce general memory consumption, strings in this include are stored
 *     globally in constant arrays and referenced.  This is EXACTLY as fast as
 *     using the string constants directly, but means that strings are not
 *     stored in the assembly multiple times (unless the string is only used
 *     once, in which case it's more work for no gain).  See this post for more
 *     details:
 *     
 *         http://forum.sa-mp.com/showpost.php?p=1795601
 * 
 * DO NOT EDIT THIS FILE IN PAWNO OR ON GITHUB.  Both mess up the spacing -
 *     GitHub in an almost irreversible way (except for the fact that nothing is
 *     irreversible in source control.  Pawno spacing is less tricky to solve,
 *     and can be worked around if you know when it uses spaces and tabs - in
 *     short, always write code first THEN indent and you won't have a problem
 *     (in that editor at least, that is normally a bad way to write code).
 * 
 * Documentation explanation:
 *     
 *         FIX:      <Short name>
 *         PROBLEM:  <Description of problem>
 *         SOLUTION: <Description of solution>
 *         SEE:      <List of relevant functions>
 *         AUTHOR:   <Person who wrote the fix>
 *         POST:     <Optional link to the original post where applicable>
 *         FIXED IN: <Optional server version of official fix where applicable>
 * 
 */

#if defined _INC_SAMP_Community_fixes
	#endinput
#endif
#define _INC_SAMP_Community_fixes

#if !defined _inc_fixes
	#define _inc_fixes
#endif

#define _FIXES_IS_UNSET(%0) ((2*%0-1+1)==-1)

// We can add server version compiler code here to only compile fixes that apply
// to the version of the includes for which the user is compiling.
#if !defined FIX_GetPlayerColour
	#if defined FIX_GetPlayerColor
		#if _FIXES_IS_UNSET(FIX_GetPlayerColor)
			#define FIX_GetPlayerColour   (2)
		#else
			#define FIX_GetPlayerColour   (FIX_GetPlayerColor)
		#endif
	#else
		#define FIX_GetPlayerColour       (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerColour)
	#undef FIX_GetPlayerColour
	#define FIX_GetPlayerColour           (2)
#endif

#if !defined FIX_FILTERSCRIPT
	#define FIX_FILTERSCRIPT             (1)
#elseif _FIXES_IS_UNSET(FIX_FILTERSCRIPT)
	#undef FIX_FILTERSCRIPT
	#define FIX_FILTERSCRIPT             (2)
#endif

#if !defined FIX_SpawnPlayer
	#define FIX_SpawnPlayer              (1)
#elseif _FIXES_IS_UNSET(FIX_SpawnPlayer)
	#undef FIX_SpawnPlayer
	#define FIX_SpawnPlayer              (2)
#endif

#if !defined FIX_SetPlayerName
	#define FIX_SetPlayerName            (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerName)
	#undef FIX_SetPlayerName
	#define FIX_SetPlayerName            (2)
#endif

#if !defined FIX_GetPlayerSkin
	#define FIX_GetPlayerSkin            (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerSkin)
	#undef FIX_GetPlayerSkin
	#define FIX_GetPlayerSkin            (2)
#endif

#if !defined FIX_GetWeaponName
	#define FIX_GetWeaponName            (1)
#elseif _FIXES_IS_UNSET(FIX_GetWeaponName)
	#undef FIX_GetWeaponName
	#define FIX_GetWeaponName            (2)
#endif

#if !defined FIX_SetPlayerWorldBounds
	#define FIX_SetPlayerWorldBounds     (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerWorldBounds)
	#undef FIX_SetPlayerWorldBounds
	#define FIX_SetPlayerWorldBounds     (2)
#endif

#if !defined FIX_TogglePlayerControllable
	#if defined SetObjectMaterial
		#define FIX_TogglePlayerControllable (0)
	#else
		#define FIX_TogglePlayerControllable (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_TogglePlayerControllable)
	#undef FIX_TogglePlayerControllable
	#define FIX_TogglePlayerControllable (2)
#endif

#if !defined FIX_HydraSniper
	#define FIX_HydraSniper              (1)
#elseif _FIXES_IS_UNSET(FIX_HydraSniper)
	#undef FIX_HydraSniper
	#define FIX_HydraSniper              (2)
#endif

#if !defined FIX_IsPlayerInCheckpoint
	#define FIX_IsPlayerInCheckpoint     (1)
#elseif _FIXES_IS_UNSET(FIX_IsPlayerInCheckpoint)
	#undef FIX_IsPlayerInCheckpoint
	#define FIX_IsPlayerInCheckpoint     (2)
#endif

#if !defined FIX_IsPlayerInRaceCheckpoint
	#define FIX_IsPlayerInRaceCheckpoint (1)
#elseif _FIXES_IS_UNSET(FIX_IsPlayerInRaceCheckpoint)
	#undef FIX_IsPlayerInRaceCheckpoint
	#define FIX_IsPlayerInRaceCheckpoint (2)
#endif

#if !defined FIX_GetPlayerWeapon
	#define FIX_GetPlayerWeapon          (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeapon)
	#undef FIX_GetPlayerWeapon
	#define FIX_GetPlayerWeapon          (2)
#endif

#if !defined FIX_PutPlayerInVehicle
	#define FIX_PutPlayerInVehicle       (1)
#elseif _FIXES_IS_UNSET(FIX_PutPlayerInVehicle)
	#undef FIX_PutPlayerInVehicle
	#define FIX_PutPlayerInVehicle       (2)
#endif

#if !defined FIX_KEY_AIM
	#if defined KEY_AIM
		#define FIX_KEY_AIM              (0)
	#else
		#define FIX_KEY_AIM              (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_KEY_AIM)
	#undef FIX_KEY_AIM
	#define FIX_KEY_AIM                  (2)
#endif

#if !defined FIX_SPECIAL_ACTION_PISSING
	#if defined SPECIAL_ACTION_PISSING
		#define FIX_SPECIAL_ACTION_PISSING (0)
	#else
		#define FIX_SPECIAL_ACTION_PISSING (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_SPECIAL_ACTION_PISSING)
	#undef FIX_SPECIAL_ACTION_PISSING
	#define FIX_SPECIAL_ACTION_PISSING   (2)
#endif

#if !defined FIX_Natives
	#define FIX_Natives                  (1)
#elseif _FIXES_IS_UNSET(FIX_Natives)
	#undef FIX_Natives
	#define FIX_Natives                  (2)
#endif

#if !defined FIX_IsValidVehicle
	#if defined IsValidVehicle
		#define FIX_IsValidVehicle       (0)
	#else
		#define FIX_IsValidVehicle       (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_IsValidVehicle)
	#undef FIX_IsValidVehicle
	#define FIX_IsValidVehicle           (2)
#endif

#if !defined FIX_GetGravity
	#if defined GetGravity
		#define FIX_GetGravity           (0)
	#else
		#define FIX_GetGravity           (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetGravity)
	#undef FIX_GetGravity
	#define FIX_GetGravity               (2)
#endif

#if !defined FIX_gpci
	#if defined gpci
		#define FIX_gpci                 (0)
	#else
		#define FIX_gpci                 (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_gpci)
	#undef FIX_gpci
	#define FIX_gpci                     (2)
#endif

#if !defined FIX_BODYPARTS
	#if defined BODY_PART_TORSO
		#define FIX_BODYPARTS            (0)
	#else
		#define FIX_BODYPARTS            (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_BODYPARTS)
	#undef FIX_BODYPARTS
	#define FIX_BODYPARTS                (2)
#endif

#if !defined FIX_CAMERAMODES
	#if defined CAM_MODE_NONE
		#define FIX_CAMERAMODES          (0)
	#else
		#define FIX_CAMERAMODES          (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_CAMERAMODES)
	#undef FIX_CAMERAMODES
	#define FIX_CAMERAMODES              (2)
#endif

#if !defined FIX_DriveBy
	#define FIX_DriveBy                  (1)
#elseif _FIXES_IS_UNSET(FIX_DriveBy)
	#undef FIX_DriveBy
	#define FIX_DriveBy                  (2)
#endif

#if !defined FIX_SetPlayerCheckpoint
	#define FIX_SetPlayerCheckpoint      (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerCheckpoint)
	#undef FIX_SetPlayerCheckpoint
	#define FIX_SetPlayerCheckpoint      (2)
#endif

#if !defined FIX_SetPlayerRaceCheckpoint
	#define FIX_SetPlayerRaceCheckpoint  (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerRaceCheckpoint)
	#undef FIX_SetPlayerRaceCheckpoint
	#define FIX_SetPlayerRaceCheckpoint  (2)
#endif

#if !defined FIX_TextDrawCreate
	#define FIX_TextDrawCreate           (1)
#elseif _FIXES_IS_UNSET(FIX_TextDrawCreate)
	#undef FIX_TextDrawCreate
	#define FIX_TextDrawCreate           (2)
#endif

#if !defined FIX_TextDrawSetString
	#define FIX_TextDrawSetString        (1)
#elseif _FIXES_IS_UNSET(FIX_TextDrawSetString)
	#undef FIX_TextDrawSetString
	#define FIX_TextDrawSetString        (2)
#endif

#if !defined FIX_AllowInteriorWeapons
	#define FIX_AllowInteriorWeapons     (1)
#elseif _FIXES_IS_UNSET(FIX_AllowInteriorWeapons)
	#undef FIX_AllowInteriorWeapons
	#define FIX_AllowInteriorWeapons     (2)
#endif

#if !defined FIX_OnPlayerEnterVehicle
	#if defined OnPlayerClickMap
		#define FIX_OnPlayerEnterVehicle (0)
	#else
		#define FIX_OnPlayerEnterVehicle (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle)
	#undef FIX_OnPlayerEnterVehicle
	#define FIX_OnPlayerEnterVehicle     (2)
#endif

#if !defined FIX_OnPlayerEnterVehicle_2
	#define FIX_OnPlayerEnterVehicle_2   (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle)
	#undef FIX_OnPlayerEnterVehicle_2
	#define FIX_OnPlayerEnterVehicle_2   (2)
#endif

#if !defined FIX_AllowTeleport
	#if defined OnPlayerClickMap
		#define FIX_AllowTeleport        (1)
	#else
		#define FIX_AllowTeleport        (0)
	#endif
#elseif _FIXES_IS_UNSET(FIX_AllowTeleport)
	#undef FIX_AllowTeleport
	#define FIX_AllowTeleport            (2)
#endif

#if !defined FIX_SetPlayerSpecialAction
	#define FIX_SetPlayerSpecialAction   (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerSpecialAction)
	#undef FIX_SetPlayerSpecialAction
	#define FIX_SetPlayerSpecialAction   (2)
#endif

#if !defined FIX_ClearAnimations
	#define FIX_ClearAnimations          (1)
#elseif _FIXES_IS_UNSET(FIX_ClearAnimations)
	#undef FIX_ClearAnimations
	#define FIX_ClearAnimations          (2)
#endif

#if !defined FIX_ClearAnimations_2
	#define FIX_ClearAnimations_2        (1)
#elseif _FIXES_IS_UNSET(FIX_ClearAnimations_2)
	#undef FIX_ClearAnimations_2
	#define FIX_ClearAnimations_2        (2)
#endif

#if !defined FIX_GangZoneCreate
	#define FIX_GangZoneCreate           (1)
#elseif _FIXES_IS_UNSET(FIX_GangZoneCreate)
	#undef FIX_GangZoneCreate
	#define FIX_GangZoneCreate           (2)
#endif

#if !defined FIX_OnDialogResponse
	#if defined GetVehicleModelInfo
		#define FIX_OnDialogResponse     (0)
	#else
		#define FIX_OnDialogResponse     (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_OnDialogResponse)
	#undef FIX_OnDialogResponse
	#define FIX_OnDialogResponse         (2)
#endif

#if !defined FIX_GetPlayerDialog
	#define FIX_GetPlayerDialog          (0)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerDialog)
	#undef FIX_GetPlayerDialog
	#define FIX_GetPlayerDialog          (2)
#endif

#if !defined FIX_PlayerDialogResponse
	#define FIX_PlayerDialogResponse     (1)
#elseif _FIXES_IS_UNSET(FIX_PlayerDialogResponse)
	#undef FIX_PlayerDialogResponse
	#define FIX_PlayerDialogResponse     (2)
#endif

#if !defined FIX_SetSpawnInfo
	#if defined GetPlayerVersion
		#define FIX_SetSpawnInfo         (0)
	#else
		#define FIX_SetSpawnInfo         (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_SetSpawnInfo)
	#undef FIX_SetSpawnInfo
	#define FIX_SetSpawnInfo             (2)
#endif

#if !defined FIX_SetPlayerSkin
	#define FIX_SetPlayerSkin            (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerSkin)
	#undef FIX_SetPlayerSkin
	#define FIX_SetPlayerSkin            (2)
#endif

#if !defined FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer        (1)
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer)
	#undef FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer        (2)
#endif

#if !defined FIX_valstr
	#define FIX_valstr                   (1)
#elseif _FIXES_IS_UNSET(FIX_valstr)
	#undef FIX_valstr
	#define FIX_valstr                   (2)
#endif

#if !defined FIX_file_inc
	#define FIX_file_inc                 (0)
#elseif _FIXES_IS_UNSET(FIX_file_inc)
	#undef FIX_file_inc
	#define FIX_file_inc                 (2)
#endif

#if !defined FIX_fclose
	#define FIX_fclose                   (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fclose)
	#undef FIX_fclose
	#define FIX_fclose                   (2)
#endif

#if !defined FIX_fwrite
	#define FIX_fwrite                   (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fwrite)
	#undef FIX_fwrite
	#define FIX_fwrite                   (2)
#endif

#if !defined FIX_fread
	#define FIX_fread                    (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fread)
	#undef FIX_fread
	#define FIX_fread                    (2)
#endif

#if !defined FIX_fputchar
	#define FIX_fputchar                 (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fputchar)
	#undef FIX_fputchar
	#define FIX_fputchar                 (2)
#endif

#if !defined FIX_fgetchar
	#define FIX_fgetchar                 (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fgetchar)
	#undef FIX_fgetchar
	#define FIX_fgetchar                 (2)
#endif

#if !defined FIX_fblockwrite
	#define FIX_fblockwrite              (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fblockwrite)
	#undef FIX_fblockwrite
	#define FIX_fblockwrite              (2)
#endif

#if !defined FIX_fblockread
	#define FIX_fblockread               (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fblockread)
	#undef FIX_fblockread
	#define FIX_fblockread               (2)
#endif

#if !defined FIX_fseek
	#define FIX_fseek                    (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fseek)
	#undef FIX_fseek
	#define FIX_fseek                    (2)
#endif

#if !defined FIX_flength
	#define FIX_flength                  (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_flength)
	#undef FIX_flength
	#define FIX_flength                  (2)
#endif

#if !defined FIX_IsPlayerAttachedObjSlotUsed
	#define FIX_IsPlayerAttachedObjSlotUsed (1)
#elseif _FIXES_IS_UNSET(FIX_IsPlayerAttachedObjSlotUsed)
	#undef FIX_IsPlayerAttachedObjSlotUsed
	#define FIX_IsPlayerAttachedObjSlotUsed (2)
#endif

#if !defined FIX_SetPlayerAttachedObject
	#define FIX_SetPlayerAttachedObject  (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerAttachedObject)
	#undef FIX_SetPlayerAttachedObject
	#define FIX_SetPlayerAttachedObject  (2)
#endif

#if !defined FIX_OnPlayerDeath
	#define FIX_OnPlayerDeath            (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerDeath)
	#undef FIX_OnPlayerDeath
	#define FIX_OnPlayerDeath            (2)
#endif

#if !defined FIX_strins
	#define FIX_strins                   (1)
#elseif _FIXES_IS_UNSET(FIX_strins)
	#undef FIX_strins
	#define FIX_strins                   (2)
#endif

#if !defined FIX_IsPlayerConnected
	#define FIX_IsPlayerConnected        (1)
#elseif _FIXES_IS_UNSET(FIX_IsPlayerConnected)
	#undef FIX_IsPlayerConnected
	#define FIX_IsPlayerConnected        (2)
#endif

#if !defined FIX_OnPlayerCommandText
	#define FIX_OnPlayerCommandText      (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerCommandText)
	#undef FIX_OnPlayerCommandText
	#define FIX_OnPlayerCommandText      (2)
#endif

#if !defined FIX_TrainExit
	#define FIX_TrainExit                (1)
#elseif _FIXES_IS_UNSET(FIX_TrainExit)
	#undef FIX_TrainExit
	#define FIX_TrainExit                (2)
#endif

#if !defined FIX_Kick
	#if defined EnableVehicleFriendlyFire
		#define FIX_Kick                 (0)
	#else
		#define FIX_Kick                 (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_Kick)
	#undef FIX_Kick
	#define FIX_Kick                     (2)
#endif

#if !defined FIX_OnVehicleMod
	#define FIX_OnVehicleMod             (1)
#elseif _FIXES_IS_UNSET(FIX_OnVehicleMod)
	#undef FIX_OnVehicleMod
	#define FIX_OnVehicleMod             (2)
#endif

#if !defined FIX_random
	#define FIX_random                   (0)
#elseif _FIXES_IS_UNSET(FIX_random)
	#undef FIX_random
	#define FIX_random                   (2)
#endif

#if !defined FIX_sleep
	#define FIX_sleep                    (1)
#elseif _FIXES_IS_UNSET(FIX_sleep)
	#undef FIX_sleep
	#define FIX_sleep                    (2)
#endif

#if !defined FIX_Menus
	#define FIX_Menus                    (1)
#elseif _FIXES_IS_UNSET(FIX_Menus)
	#undef FIX_Menus
	#define FIX_Menus                    (2)
#endif

#if !defined FIX_AddMenuItem
	#define FIX_AddMenuItem              (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_AddMenuItem)
	#undef FIX_AddMenuItem
	#define FIX_AddMenuItem              (2)
#endif

#if !defined FIX_SetMenuColumnHeader
	#define FIX_SetMenuColumnHeader      (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_SetMenuColumnHeader)
	#undef FIX_SetMenuColumnHeader
	#define FIX_SetMenuColumnHeader      (2)
#endif

#if !defined FIX_ShowMenuForPlayer
	#define FIX_ShowMenuForPlayer        (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_ShowMenuForPlayer)
	#undef FIX_ShowMenuForPlayer
	#define FIX_ShowMenuForPlayer        (2)
#endif

#if !defined FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer        (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer)
	#undef FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer        (2)
#endif

#if !defined FIX_GetPlayerMenu
	#define FIX_GetPlayerMenu            (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerMenu)
	#undef FIX_GetPlayerMenu
	#define FIX_GetPlayerMenu            (2)
#endif

#if !defined FIX_HideMenuForPlayer_2
	#define FIX_HideMenuForPlayer_2      (0)
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer_2)
	#undef FIX_HideMenuForPlayer_2
	#define FIX_HideMenuForPlayer_2      (2)
#elseif FIX_HideMenuForPlayer_2 && !FIX_GetPlayerMenu
	#error FIX_HideMenuForPlayer_2 requires FIX_GetPlayerMenu
#endif

#if !defined FIX_DisableMenu
	#define FIX_DisableMenu              (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_DisableMenu)
	#undef FIX_DisableMenu
	#define FIX_DisableMenu              (2)
#endif

#if !defined FIX_DisableMenuRow
	#define FIX_DisableMenuRow           (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_DisableMenuRow)
	#undef FIX_DisableMenuRow
	#define FIX_DisableMenuRow           (2)
#endif

#if FIX_Menus || FIX_AddMenuItem || FIX_SetMenuColumnHeader || FIX_ShowMenuForPlayer || FIX_HideMenuForPlayer || FIX_DisableMenu || FIX_DisableMenuRow
	#define _FIX_Menus                   (1)
#else
	#define _FIX_Menus                   (2)
#endif

#if !defined FIX_GetPlayerInterior
	#define FIX_GetPlayerInterior        (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerInterior)
	#undef FIX_GetPlayerInterior
	#define FIX_GetPlayerInterior        (2)
#endif

#if !defined FIX_ApplyAnimation
	#define FIX_ApplyAnimation           (1)
#elseif _FIXES_IS_UNSET(FIX_ApplyAnimation)
	#undef FIX_ApplyAnimation
	#define FIX_ApplyAnimation           (2)
#endif

#if !defined FIX_ApplyAnimation_2
	#define FIX_ApplyAnimation_2         (1)
#elseif _FIXES_IS_UNSET(FIX_ApplyAnimation_2)
	#undef FIX_ApplyAnimation_2
	#define FIX_ApplyAnimation_2         (2)
#endif

#if !defined FIX_OnPlayerSpawn
	#define FIX_OnPlayerSpawn            (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerSpawn)
	#undef FIX_OnPlayerSpawn
	#define FIX_OnPlayerSpawn            (2)
#endif

#if !defined FIX_GameText
	#define FIX_GameText                 (1)
#elseif _FIXES_IS_UNSET(FIX_GameText)
	#undef FIX_GameText
	#define FIX_GameText                 (2)
#endif

#if !defined FIX_HideGameText
	#define FIX_HideGameText             (0)
#elseif _FIXES_IS_UNSET(FIX_HideGameText)
	#undef FIX_HideGameText
	#define FIX_HideGameText             (2)
#endif

#if !defined FIX_GameTextStyles
	#define FIX_GameTextStyles           (0)
#elseif _FIXES_IS_UNSET(FIX_GameTextStyles)
	#undef FIX_GameTextStyles
	#define FIX_GameTextStyles           (2)
#elseif FIX_GameTextStyles && !FIX_GameText
	#error FIX_GameTextStyles requires FIX_GameText
#endif

#if !defined FIX_OnPlayerConnect
	#define FIX_OnPlayerConnect          (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerConnect)
	#undef FIX_OnPlayerConnect
	#define FIX_OnPlayerConnect          (2)
#endif

#if !defined FIX_OnPlayerDisconnect
	#define FIX_OnPlayerDisconnect       (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerDisconnect)
	#undef FIX_OnPlayerDisconnect
	#define FIX_OnPlayerDisconnect       (2)
#endif

#if !defined FIX_CreatePlayerTextDraw
	#define FIX_CreatePlayerTextDraw     (1)
#elseif _FIXES_IS_UNSET(FIX_CreatePlayerTextDraw)
	#undef FIX_CreatePlayerTextDraw
	#define FIX_CreatePlayerTextDraw     (2)
#endif

#if !defined FIX_PlayerTextDrawSetString
	#define FIX_PlayerTextDrawSetString  (1)
#elseif _FIXES_IS_UNSET(FIX_PlayerTextDrawSetString)
	#undef FIX_PlayerTextDrawSetString
	#define FIX_PlayerTextDrawSetString  (2)
#endif

#if !defined FIX_SetPlayerCamera
	#define FIX_SetPlayerCamera          (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerCamera)
	#undef FIX_SetPlayerCamera
	#define FIX_SetPlayerCamera          (2)
#endif

#if !defined FIX_SetPlayerTime
	#define FIX_SetPlayerTime            (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerTime)
	#undef FIX_SetPlayerTime
	#define FIX_SetPlayerTime            (2)
#endif

#if !defined FIX_OnPlayerRequestClass
	#define FIX_OnPlayerRequestClass     (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerRequestClass)
	#undef FIX_OnPlayerRequestClass
	#define FIX_OnPlayerRequestClass     (2)
#endif

#if !defined FIX_SetPlayerColour
	#if defined FIX_SetPlayerColor
		#if _FIXES_IS_UNSET(FIX_SetPlayerColor)
			#define FIX_SetPlayerColour  (2)
		#else
			#define FIX_SetPlayerColour   (FIX_SetPlayerColor)
		#endif
	#else
		#define FIX_SetPlayerColour      (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_SetPlayerColour)
	#undef FIX_SetPlayerColour
	#define FIX_SetPlayerColour          (2)
#endif

#if !defined FIX_FileMaths
	#define FIX_FileMaths                (1)
#elseif _FIXES_IS_UNSET(FIX_FileMaths)
	#undef FIX_FileMaths
	#define FIX_FileMaths                (2)
#endif

#if !defined FIX_GetPlayerWeaponData
	#define FIX_GetPlayerWeaponData      (0)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeaponData)
	#undef FIX_GetPlayerWeaponData
	#define FIX_GetPlayerWeaponData      (2)
#endif

/* 
 * CHAIN_ORDER
 * 
 * Allows y_hooks to call things in the correct order when it exists.
 */

#if !defined CHAIN_ORDER
	#define CHAIN_ORDER() 0
#endif

/* 
 * PRE_HOOK
 * 
 * A method of pre-hooking callbacks to still have them called before any ones
 * re-written by y_hooks.
 */

#define PRE_HOOK(%0) forward @CO_%0();public @CO_%0(){return CHAIN_ORDER()+1;}

PRE_HOOK(FIXES)
#undef CHAIN_ORDER
#define CHAIN_ORDER @CO_FIXES

/* 
 * _FIXES_IncludeStates
 * 
 * Define the "_ALS" states used by hooks.
 */

static stock _FIXES_IncludeStates() <_ALS : _ALS_x0, _ALS : _ALS_x1, _ALS : _ALS_x2, _ALS : _ALS_x3>
{
}

static stock _FIXES_IncludeStates() <_ALS : _ALS_go>
{
}

/* 
 * FIXES_GT_STYLE_COUNT
 * 
 * The number of GameText styles recreated using TextDraw functions.  This is 4
 * by default, but can be extended to 6 if you want location and vehicle styles.
 */

#if FIX_GameText
	#if FIX_GameTextStyles
		#define FIXES_GT_STYLE_COUNT (14)
	#else
		#define FIXES_GT_STYLE_COUNT (7)
	#endif
#endif

/* 
 * FIXES_SilentKick
 * 
 * If this define is set to 1, then players will not be given a message when
 * they are kicked for cheats, instead they will just loose connection to the
 * server.
 */

#if !defined FIXES_SilentKick
	#define FIXES_SilentKick 0
#elseif _FIXES_IS_UNSET(FIXES_SilentKick)
	#undef FIXES_SilentKick
	#define FIXES_SilentKick 2
#endif

/* 
 * FIXES_Debug
 * 
 * If this define is set to 1, then debug printing is turned on for any
 * functions which may use it.  Otherwise, the compiler entirely removes the
 * code to print anything, leaving 0 run-time overhead.
 */

#if defined FIXES_Debug
	#if _FIXES_IS_UNSET(FIXES_Debug)
		#undef FIXES_Debug
	#elseif FIXES_Debug == 1
		#define FIXES_PRINTF(%0); print(_FIXES_gIsFilterscript ? ("* FIXES_PRINTF (FS):") : ("* FIXES_PRINTF (GM):")),printf("*** " %0);
	#else
		#undef FIXES_Debug
	#endif
#endif

/* 
 * FIXES_UseStateHooks
 * 
 * A marker to indicate that this version of fixes.inc uses state-based hooks.
 */
#define FIXES_UseStateHooks

/* 
 * FIXES_PRINTF
 * 
 * A special "printf" function only compiled when "FIXES_Debug" is set.
 */

#if !defined FIXES_PRINTF
	#define FIXES_Debug 0
	#define FIXES_PRINTF(%0);
#endif

/* 
 * INVALID_DIALOG_ID
 * 
 * Set when a player can't see a dialog.
 */

#if !defined INVALID_DIALOG_ID
	#define INVALID_DIALOG_ID (-1)
#endif

/* 
 * FIXES_Single
 * 
 * If this define is set to 1, then the old style include is used, with no
 * support for multiple scripts running at the same time on the server (i.e. no
 * gamemodes and filter scripts at the same time).  You can only have one or the
 * other or bugs.
 */

#if !defined FIXES_Single
	#define FIXES_Single (1)
#elseif _FIXES_IS_UNSET(FIXES_Single)
	#undef FIXES_Single
	#define FIXES_Single (2)
#endif

/* 
 * _FIXES_IS_IN_CHARGE
 * 
 * Test to see if this script is in command or not (master).
 */

#if FIXES_Single
	#define _FIXES_IS_IN_CHARGE(%0)
#else
	#define _FIXES_IS_IN_CHARGE(%0) if (%0(FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE))
#endif

/* 
 * E_FIXES_WORLDBOUND_DATA
 * 
 * Store data for each player on their worldbound data.
 */
enum E_FIXES_WORLDBOUND_DATA
{
	// "Previous".
	Float:E_FIXES_WORLDBOUND_DATA_PX,
	Float:E_FIXES_WORLDBOUND_DATA_PY,
	Float:E_FIXES_WORLDBOUND_DATA_PZ,
	// "Lower".
	Float:E_FIXES_WORLDBOUND_DATA_LX,
	Float:E_FIXES_WORLDBOUND_DATA_LY,
	// "Upper".
	Float:E_FIXES_WORLDBOUND_DATA_UX,
	Float:E_FIXES_WORLDBOUND_DATA_UY
}

/* 
 * e_FIXES_BOOLS
 * 
 * Collection of boolean values for players, designed to collect multiple checks
 * in to one variable to reduce memory consumption.
 */
enum e_FIXES_BOOLS (<<= 1)
{
	// Handy definition for nothing set.
	e_FIXES_BOOLS_NONE = 0,
	// Does this player have worldbounds enabled?
	e_FIXES_BOOLS_WORLDBOUNDS = 1,
	e_FIXES_BOOLS_UNCONTROLLABLE,
	e_FIXES_BOOLS_PUT_IN_VEHICLE,
	e_FIXES_BOOLS_BLOCK,
	e_FIXES_BOOLS_TELEPORT,
	e_FIXES_BOOLS_CONNECTED,
	e_FIXES_BOOLS_INTERIOR,
	e_FIXES_BOOLS_PUT_IN_TRAIN,
	e_FIXES_BOOLS_KICKED,
	e_FIXES_BOOLS_ON_PLAYER_CONNECT,
	e_FIXES_BOOLS_DRIVE_BY,
	e_FIXES_BOOLS_FIRST_SPAWN,
	e_FIXES_BOOLS_FIRST_CLASS,
	e_FIXES_BOOLS_SPECTATING,
	e_FIXES_BOOLS_CP_DELAYED,
	e_FIXES_BOOLS_RACE_CP_DELAYED
}

/* 
 * e_FIXES_SETTINGS
 * 
 * Collection of boolean values for the script as a whole.  Stores a variety of
 * settings that are true/false.
 */
enum e_FIXES_SETTINGS (<<= 1)
{
	// Handy definition for nothing set.
	e_FIXES_SETTINGS_NONE = 0,
	e_FIXES_SETTINGS_INTERIOR = 1,
	e_FIXES_SETTINGS_ADMIN_TELEPORT,
	e_FIXES_SETTINGS_IN_CHARGE,
	e_FIXES_SETTINGS_DROP_ALL_DATA,
	e_FIXES_SETTINGS_MENU_SET,
	e_FIXES_SETTINGS_ENDING,
	e_FIXES_SETTINGS_ENDED,
	e_FIXES_SETTINGS_NO_GAME_TEXT,
	e_FIXES_SETTINGS_SECOND_USE
}

/* 
 * _FIXES_CEILDIV
 * 
 * Do a ceiling division of the first number by the second number.
 */
#define _FIXES_CEILDIV(%0,%1) (((%0) + (%1) - 1) / (%1))

/* 
 * _FIXES_INFINITY
 * 
 * IEEE 754 definition of infinity.
 */
#define _FIXES_INFINITY (Float:0x7F800000)

/* 
 * _FIXES_N_INFINITY
 * 
 * IEEE 754 definition of negative infinity.
 */
#define _FIXES_N_INFINITY (Float:0xFF800000)

/* 
 * _FIXES_ATTACHMENTS
 * 
 * The number of players whose attachment data (10-bits) can be stored in one
 * cell.
 */
#define _FIXES_ATTACHMENTS (cellbits / MAX_PLAYER_ATTACHED_OBJECTS)

/* 
 * _FIXES_FOREACH
 * 
 * A new version of "foreach", but just for this library.
 */
#define _FIXES_FOREACH(%1,%0) for (new %0 = MAX_PLAYERS; (%0 = %1[%0]) != MAX_PLAYERS; )

/* 
 * _FIXES_IN_RANGE
 * 
 * Checks if the first parameter is between the other two: %1 <= %0 < %2 (but
 * faster).
 */
#define _FIXES_IN_RANGE(%0,%1,%2) (((%0) - ((%1) + cellmin)) < ((%2) - ((%1) + cellmin)))

/* 
 * _FIXES_NO_RANGE
 * 
 * Checks if the first parameter is not between the other two: !(%1 <= %0 < %2)
 * (but faster).
 */
#define _FIXES_NO_RANGE(%0,%1,%2) (((%0) - ((%1) + cellmin)) >= ((%2) - ((%1) + cellmin)))

/* 
 * _FIXES_FORWARD
 * 
 * Forwards a hooked callbacks, and defines the default state imp