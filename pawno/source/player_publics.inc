#if !defined __PLAYER_PUBLICS__ 
#define __PLAYER_PUBLICS__

public OnPlayerRequestClass(playerid, classid)
{
    SpawnPlayer(playerid);
    TogglePlayerSpectating(playerid, 1);
    
    queryStr[0] = EOS;
	format(queryStr, sizeof(queryStr), "SELECT `pName` FROM `accounts` WHERE `pName` = '%s'", pVars[playerid][pName]);
	mysql_query(queryStr);
	
	mysql_store_result();
	
    if(mysql_num_rows() > 0) 
    {
        mysql_free_result();

        mainStr[0] = EOS;
        tmpStr[0] = EOS;
        format(tmpStr, sizeof(tmpStr), "[%i/3] Logowanie", loginAttempt[playerid]);
        format(mainStr, sizeof(mainStr), "{00FF00}Witaj na serwerze Drift! Znalezlismy juz konto %s zarejestrowane na serwerze! Wpisz haslo", pVars[playerid][pName]);
        ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, tmpStr, mainStr, "Zaloguj", "Wyjdz");
        
        


    } else 
    {
        mysql_free_result();

        mainStr[0] = EOS;
        format(mainStr, sizeof(mainStr), "{00FF00}Witaj na serwerze Drift! Nie znalezlismy konta o nicku %s. Musisz utworzyc nowe konto, wpisz haslo", pVars[playerid][pName]);
        ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Rejestracja", mainStr, "Zarejestruj", "Wyjdz");
    }

    TogglePlayerSpectating(playerid, 0);
    SpawnPlayer(playerid);
	SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraLookAt(playerid, 1958.3783, 1343.1572, 15.3746);
	return 1;
}

public OnPlayerConnect(playerid)
{
    loginAttempt[playerid] = 0;
    hasLogged[playerid] = false;
    isSpawned[playerid] = false;
    isDriftModeEnabled[playerid] = false;

    format(pVars[playerid][pName], 24, "%s", GetPlayerNick(playerid));

    // ..
    
    mainStr[0] = EOS;
    
    format(mainStr, sizeof(mainStr), "%s dolaczyl do serwera, witamy!", pVars[playerid][pName]);
    SendClientMessageToAll(0xFFFFFF, mainStr);

	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    clearPlayerData(playerid);
	return 1;
}

public OnPlayerSpawn(playerid)
{
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	return 1;
}


public OnPlayerCommandText(playerid, cmdtext[])
{
	if (strcmp("/mycommand", cmdtext, true, 10) == 0)
	{
		// Do something here
		return 1;
	}
	return 0;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnPlayerStartDrift(playerid)
{
    return 1;
}

public OnPlayerDriftUpdate(playerid, Float: drift_angle, Float: speed)
{
    return 1;
}

public OnPlayerDriftEnd(playerid, reason, Float: distance, time)
{
    switch(reason)
    {
        case DRIFT_END_REASON_TIMEOUT: 
        {

        }

        case DRIFT_END_REASON_DAMAGED: 
        {

        }

        case DRIFT_END_REASON_OTHER:
        {

        }
    }
    return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case DIALOG_REGISTER:
        {
            if(response) 
            {
                format(pVars[playerid][pPassword], 255, "%s", inputtext);
                pVars[playerid][pSkinId] = BASIC_SKIN;
                pVars[playerid][pMoney] = 10000;
                pVars[playerid][pScore] = 0;
                pVars[playerid][pRank] = PLAYER_RANK;

                queryStr[0] = EOS;
                format(queryStr, sizeof(queryStr), "INSERT INTO accounts (`pId`, `pName`, `pPassword`, `pSkinId`, `pMoney`, `pScore`, `pRank`) VALUES ('NULL', '%s', '%s', '%d', '%d', '%d', '%d')", pVars[playerid][pName], pVars[playerid][pPassword], pVars[playerid][pSkinId], pVars[playerid][pMoney], pVars[playerid][pScore], pVars[playerid][pRank]);
                mysql_query(queryStr);

                SpawnPlayer(playerid);

            } else 
            {
                Kick(playerid);
            }
            mainStr[0] = EOS;
            
        }

        case DIALOG_LOGIN:
        {
            if(loginAttempt[playerid] == 3)
            {
                Kick(playerid);
            } else 
            {
                if(response) 
                {
                    queryStr[0] = EOS;
	                format(queryStr, sizeof(queryStr), "SELECT `pPassword` FROM `accounts` WHERE `pName` = '%s'", pVars[playerid][pName]);
                    mysql_query(queryStr);

                    mysql_store_result();

                    mysql_fetch_row(queryStr, "|");
                    sscanf(queryStr, "p<|>s[255]", pVars[playerid][pPassword]);

                    mysql_free_result();

                    if(strcmp(inputtext, pVars[playerid][pPassword]) == 0)
                    {
                        loginAttempt[playerid] = 0;
                        mainStr[0] = EOS;
                        format(mainStr, sizeof(mainStr), "Zalogowano na konto %s [ID:%i]!", pVars[playerid][pName], playerid);
                        SendClientMessage(playerid, 0x0F0F0F, mainStr);   
                        TogglePlayerSpectating(playerid, 0);
                        SpawnPlayer(playerid);
                    } else 
                    {
                        loginAttempt[playerid]++;
                        mainStr[0] = EOS;
                        tmpStr[0] = EOS;
                        format(tmpStr, sizeof(tmpStr), "[%i/3] Logowanie", loginAttempt[playerid]);
                        format(mainStr, sizeof(mainStr), "{00FF00}Witaj na serwerze Drift! Znalezlismy juz konto %s zarejestrowane na serwerze! Wpisz haslo", pVars[playerid][pName]);
                        ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, tmpStr, mainStr, "Zaloguj", "Wyjdz");
        
                    }

                } else 
                {
                    Kick(playerid);
                }    
            }

           
        }
    }
	return 1;
}

#endif