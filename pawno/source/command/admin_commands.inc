#if !defined __ADMIN_FUNCTION__
#define __ADMIN_FUNCTION__

CMD:spawnvehicle(playerid, params[]) 
{
    if(pVars[playerid][pRank] >= ADMIN_RANK && pVars[playerid][pRank] <= HEADADMIN_RANK)
    {

        new vehicleid;

        if(sscanf(params, "i", vehicleid))
        {
            SendClientMessage(playerid, 0xFF0000, "Uzycie komendy /spawnvehicle [vehicleid].");
            return 1;
        } else 
        {
            queryStr[0] = EOS;
            format(queryStr, sizeof(queryStr), "INSERT INTO vehicles (vehicleId, accountId, vX, vY, vZ, rotate, color1, color2, engineHealth) VALUES ('%i', '%i', '%f', '%f', '%f', '%f', '%i', '%i', '%f')", vehicleid, pVars[playerid][pId], pVars[playerid][pX], pVars[playerid][pY], pVars[playerid][pZ], 0.0, -1, -1, 1000.0);
            mysql_query(queryStr);
           
            GetPlayerPos(playerid, pVars[playerid][pX], pVars[playerid][pY], pVars[playerid][pZ]);
            CreateVehicle(vehicleid, pVars[playerid][pX], pVars[playerid][pY], pVars[playerid][pZ], 0.0, -1, -1, -1);

        }
    }
    return 1;
}

#endif