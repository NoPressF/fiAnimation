/*
	  E E E E E   o O O O O o   $$ $$ $$ $$
	  E           O         O   $$
	  E           O         O   $$
	  E E E E E   O         O   $$ $$ $$ $$
	  E           O         O            $$
	  E           O         O            $$
	  E E E E E   o O O O O o   $$ $$ $$ $$

*/

#if !defined isnull
	#define isnull(%0)                  	((! (%0[0])) || (((%0[0]) == '\1') && (!(%0[1]))))
#endif

enum e_FiInfo
{
	fi_PlayingAnimationid,
	fi_StartedTimeAnimation,
	fi_Timer,
	bool: fi_StatusAnimation,
	bool: fi_FinishedAnimation,
	
};

new fiInfo[MAX_PLAYERS][e_FiInfo];

forward fi_OnPlayerFinishAnimation(playerid, animationid);

stock fi_ApplyAnimation(playerid, animlibrary[], animname[], Float:fDelta, bool: loop, bool: lockx, bool: locky, bool: freeze, time, bool: forcesync = false)
{
	if(!IsPlayerConnected(playerid) || isnull(animlibrary) || IsPlayerInAnyVehicle(playerid))
	    return false;
	ApplyAnimation(playerid, animlibrary, animname, fDelta, loop, lockx, locky, freeze, time, forcesync);
	fiInfo[playerid][fi_StartedTimeAnimation] = GetTickCount();
	fiInfo[playerid][fi_PlayingAnimationid] = GetPlayerAnimationIndex(playerid);
	fiInfo[playerid][fi_StatusAnimation] = true;
	fiInfo[playerid][fi_FinishedAnimation] = false;
	while(GetPlayerAnimationIndex(playerid) != 1189)
	{
	    fiInfo[playerid][fi_PlayingAnimationid] = GetPlayerAnimationIndex(playerid);
		break;
	}
	KillTimer(fiInfo[playerid][fi_Timer]);
	fiInfo[playerid][fi_Timer] = SetTimerEx("@_OnPlayerAnimationUpdate", 10, true, "d", playerid);
	return true;
}

#if defined _ALS_ApplyAnimation
	#undef ApplyAnimation
#else
	#define _ALS_ApplyAnimation
#endif

#define ApplyAnimation fi_ApplyAnimation

@_OnPlayerAnimationUpdate(playerid);
@_OnPlayerAnimationUpdate(playerid)
{
	if(!IsPlayerConnected(playerid))
		KillTimer(fiInfo[playerid][fi_Timer]);
	if(GetPlayerAnimationIndex(playerid) != fiInfo[playerid][fi_PlayingAnimationid] && fiInfo[playerid][fi_StatusAnimation])
	{
		KillTimer(fiInfo[playerid][fi_Timer]);
	    fiInfo[playerid][fi_StatusAnimation] = false;
	    fiInfo[playerid][fi_FinishedAnimation] = true;
		CallLocalFunction("fi_OnPlayerFinishAnimation", "dd", playerid, fiInfo[playerid][fi_PlayingAnimationid]);
	}
	return true;
}

stock GetFinishAnimationTime(playerid) return GetTickCount() - fiInfo[playerid][fi_StartedTimeAnimation];