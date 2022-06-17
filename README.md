# fiAnimation
With this script you will be able to work with the OnPlayerFinishAnimation event

Example:
ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_CROUCH_IN", 4.1, false, false, false, false, 0, true, /*This parameter You must set this parameter to a boolean value true = the function works, false = no.*/);

public OnPlayerFinishAnimation(playerid, animationid, finishedMilseconds)
{
    // Animationid - return value a played animation.
    // finishedMilseconds - return value a how long the animation has been completed in milliseconds since it started.
    // Example:
    if(animationid == 165)
    {
        SendClientMessage(playerid, -1, !"Animation finished!");
        printf("Animation finished in [ %i ] milseconds!", finishedMilseconds); // Result = Animation finished in [ 850~ ] milseconds!
    }
    return true;
}
