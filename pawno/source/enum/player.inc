#if !defined __PLAYER__ 
#define __PLAYER__

enum PlayerData 
{
    pId,
    pName[MAX_PLAYER_NAME],
    pPassword[255],
    pSkinId,
    pMoney,
    pScore,
    pRank,
    Float: pX,
    Float: pY,
    Float: pZ,
    Float: pHealth,
    Float: pArmour
}

#endif