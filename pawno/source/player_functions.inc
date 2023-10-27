#if !defined __PLAYER_FUNCTIONS__
#define __PLAYER_FUNCTIONS__

stock clearPlayerData(playerid)
{
    format(pVars[playerid][pName], 24, "%s", NULL);
    format(pVars[playerid][pPassword], 255, "%s", NULL);
    pVars[playerid][pSkinId] = -1;
    pVars[playerid][pMoney] = 0;
    pVars[playerid][pScore] = 0;
    pVars[playerid][pRank] = PLAYER_RANK;

    loginAttempt[playerid] = 0;
    hasLogged[playerid] = false;
    canRelog[playerid] = false;
    return 1;
}

#endif