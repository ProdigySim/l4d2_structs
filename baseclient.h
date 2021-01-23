#ifndef _INCLUDE_BASECLIENT_H_
#define _INCLUDE_BASECLIENT_H_



struct CBaseClient_vtable
{
	void * CBaseClient_0;
	void * CBaseClient_1;
	void * FireGameEvent;
	void * GetEventDebugID;
	void * GetPlayerSlot;
	void * GetUserID;
	void * GetNetworkID;
	void * GetClientName;
	void * GetNetChannel;
	void * GetServer;
	void * GetUserSetting;
	void * GetNetworkIDString;
	void * Connect;
	void * Inactivate;
	void * Reconnect;
	void * Disconnect;
	void * CheckConnect;
	void * SetRate;
	void * GetRate;
	void * SetUpdateRate;
	void * GetUpdateRate;
	void * Clear;
	void * DemoRestart;
	void * GetMaxAckTickCount;
	void * ExecuteStringCommand;
	void * SendNetMsg;
	void * ClientPrintf;
	void * IsConnected;
	void * IsSpawned;
	void * IsActive;
	void * IsFakeClient;
	void * IsHLTV;
	void * IsHumanPlayer;
	void * IsHearingClient;
	void * IsProximityHearingClient;
	void * IsLowViolenceClient;
	void * SetMaxRoutablePayloadSize;
	void * IsSplitScreenUser;
	void * ProcessTick;
	void * ProcessStringCmd;
	void * ProcessSetConVar;
	void * ProcessSignonState;
	void * ProcessSplitScreenUser;
	void * ProcessClientInfo;
	void * ProcessBaselineAck;
	void * ProcessListenEvents;
	void * ProcessLoadingProgress;
	void * ProcessSplitPlayerConnect;
	void * ProcessCmdKeyValues;
	void * ConnectionStart;
	void * UpdateAcknowledgedFramecount;
	void * ShouldSendMessages;
	void * UpdateSendState;
	void * FillUserInfo;
	void * UpdateUserSettings;
	void * WriteGameSounds;
	void * GetDeltaFrame;
	void * SendSnapshot;
	void * SendServerInfo;
	void * SendSignonData;
	void * SpawnPlayer;
	void * ActivatePlayer;
	void * SetName;
	void * SetUserCVar;
	void * FreeBaselines;
	void * IgnoreTempEntity;
	void * GetSplitScreenOwner;
	void * GetNumPlayers;
	void * ProcessSignonStateMsg;
	void * PerformDisconnection;
};

struct CBaseClient
{
	CBaseClient_vtable * vptr; //0
	_BYTE gap4[56];
	int field_3C;
	_BYTE gap40[116];
	int field_B4;
	_BYTE gapB8[44];
	int field_E4;
	_BYTE gapE8[4];
	int field_EC;
	int field_F0;
	_BYTE gapF4[4];
	int field_F8;
	_BYTE gapFC[272];
	int field_20C;
	char field_210;
	_BYTE gap211[15];
	int field_220;
	_BYTE gap224[39996];
	int field_9E60;
	_BYTE gap9E64[79996];
	int field_1D6E0;
	_BYTE gap1D6E4[4];
	int field_1D6E8;
};

#endif // _INCLUDE_BASECLIENT_H_