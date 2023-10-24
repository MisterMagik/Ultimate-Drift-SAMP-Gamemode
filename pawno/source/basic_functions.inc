#if !defined __BASIC_FUNCTIONS__
#define __BASIC_FUNCTIONS__

stock GetPlayerNick(playerid)
{
    tmpStr[0] = EOS;
    GetPlayerName(playerid, tmpStr, sizeof(tmpStr));
    return tmpStr;
}

#endif