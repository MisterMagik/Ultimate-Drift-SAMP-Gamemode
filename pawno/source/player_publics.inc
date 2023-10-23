#if !defined __PLAYER_PUBLICS__ 
#define __PLAYER_PUBLICS__

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraLookAt(playerid, 1958.3783, 1343.1572, 15.3746);
	return 1;
}

public OnPlayerConnect(playerid)
{
    isLogged[playerid] = false;
    isSpawned[playerid] = false;
    isDriftModeEnabled[playerid] = false;

    // ..

    mainStr[0] = EOS;
    format(mainStr, sizeof(mainStr), "%s dolaczyl do serwera, witamy!");
    SendClientMessageToAll(0xFFFFFF, mainStr);



	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
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

#endif