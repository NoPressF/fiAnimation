# fiAnimation
With this script you will be able to work with the OnPlayerFinishAnimation event

# Example:
```pawn
ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_CROUCH_IN", 4.1, false, false, false, false, 0, true, /*This parameter You must set this parameter to a boolean value true = the function works, false = no. Default false.*/);

```
```pawn
public OnPlayerFinishAnimation(playerid, animationid, finishedMilseconds)
{
    // Animationid - get value a played id animation.
    // finishedMilseconds - get value a how long the animation has been completed in milliseconds since it started.
    // Example:
    if(animationid == 165)
    {
        SendClientMessage(playerid, -1, !"Animation finished!");
        printf("Animation finished in [ %i ] milseconds!", finishedMilseconds); // Result = Animation finished in [ 850~ ] milseconds!
    }
    return true;
}
```
