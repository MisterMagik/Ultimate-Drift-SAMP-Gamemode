#if !defined __MAIN_PUBLICS__
#define __MAIN_PUBLICS__

public OnGameModeInit()
{
    DisableInteriorEnterExits();
    EnableStuntBonusForAll(0);
    ManualVehicleEngineAndLights();
    SetGameModeText(GAMEMODE_TEXT);

    hMySql = mysql_init(LOG_ONLY_ERRORS, 1);
    mySqlConnect = mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB_NAME, hMySql, 1);

    if(mySqlConnect) 
        printf("[SERVER]: MYSQL DB Enabled!"); 
    else 
        printf("[SERVER]: MYSQL DB has not been connected!");
    
	AddPlayerClass(0, 1958.3783, 1343.1572, 15.3746, 269.1425, 0, 0, 0, 0, 0, 0);

    return 1;
}

public OnGameModeExit()
{
	return 1;
}

#endif