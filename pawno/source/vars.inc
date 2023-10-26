#if !defined __VARS__
#define __VARS__

new MySQL:hMySql;
new mySqlConnect;

new loginAttempt[MAX_PLAYERS];

// bool
new bool:hasLogged[MAX_PLAYERS];
new bool:isSpawned[MAX_PLAYERS];
new bool:isFreezed[MAX_PLAYERS];
new bool:isBlockedChat[MAX_PLAYERS];
new bool:isDriftModeEnabled[MAX_PLAYERS];


#endif