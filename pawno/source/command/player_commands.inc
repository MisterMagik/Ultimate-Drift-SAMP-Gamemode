#if !defined __PLAYER_COMMANDS__ 
#define __PLAYER_COMMANDS__

CMD:relog(playerid)
{
    hasLogged[playerid] = false;
    mainStr[0] = EOS;
    tmpStr[0] = EOS;
    format(tmpStr, sizeof(tmpStr), "[%i/3] Logowanie", loginAttempt[playerid]);
    format(mainStr, sizeof(mainStr), "{00FF00}Witaj na serwerze Drift! Znalezlismy juz konto %s zarejestrowane na serwerze! Wpisz haslo", pVars[playerid][pName]);
    SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraLookAt(playerid, 1958.3783, 1343.1572, 15.3746);
    TogglePlayerSpectating(playerid, 1);
    ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, tmpStr, mainStr, "Zaloguj", "Wyjdz");
    


    return 1;
}

#endif