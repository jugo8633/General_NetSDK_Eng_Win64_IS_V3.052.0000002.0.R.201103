#if !defined(_DEVICE_)
#define _DEVICE_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum EM_DEVICE_ERR
{
	EM_UNKNOWN_ERR,
	EM_LOGIN_FAIL,
	EM_WITHOUT_LOGIN,
	EM_OPENSTROBE_FAIL,
	EM_SNAP_FAIL,
	EM_SCRIBEPIC_FAIL,
	EM_PLAY_FAIL,
	EM_WITHOUT_SCRIBEPIC,
	EM_LISTEN_FAIL,
	EM_GET_STROBE_FAIL,
	EM_SET_STROBE_FAIL,
	EM_SET_LATTICESCREEN_FAIL,
	EM_IMPORTLIST_FAIL,
	EM_EXPORTLIST_FAIL,
	EM_SET_ENCODE_FAIL,
	EM_SET_TRANSFERMODE_FAIL,
	EM_START_RECORD_FAIL,
	EM_START_TALK_FAIL,
	EM_STOP_TALK_FAIL
};
class DeviceImpl;
class Device
{
public:
	static Device &GetInstance();
	void Destroy();

	void SetReconnect(fDisConnect cbDisConnect, fHaveReConnect cbAutoConnect, fSubDisConnect cbSubDisConnect, LDWORD dwUser);

	BOOL Login(const char *pchDVRIP, WORD wDVRPort, const char *pchUserName, const char *pchPassword);
	BOOL Logout();

	BOOL StartListenEvent(fMessCallBack cbMessage,LDWORD dwUser);
	BOOL StopListenEvent();

	//��������
	BOOL GetNetWork(CString& csIp, CString& csMask, CString& csGateway);
	BOOL SetNetWork(CString csIp, CString csMask, CString csGateway);

	BOOL GetRegisterCFG(CFG_DVRIP_INFO& stuInfo);
	BOOL SetRegisterCFG(CFG_DVRIP_INFO* stuInfo);

	BOOL GetDevTime(NET_TIME& DeviceTime);
	BOOL SetDevTime(NET_TIME* pDeviceTime);

	BOOL GetNTP(CFG_NTP_INFO& stuInfo);
	BOOL SetNTP(CFG_NTP_INFO* stuInfo);

	BOOL GetDST(AV_CFG_Locales& stuInfo);
	BOOL SetDST(AV_CFG_Locales* stuInfo);

	BOOL GetCapability(CString& csCap);
	BOOL GetVersion(CString& csVer);
	BOOL GetMAC(CString& csMAC);
	BOOL GetMCUVer(CString& csMCUVer);
	BOOL GetAccessCount(int& nCount);

	BOOL DevReboot();
	BOOL DevReset();

	BOOL ModifyPassword(CString strName, CString strOldPassword, CString strNewPassword);

	BOOL GetAutoMatrix(DHDEV_AUTOMT_CFG& stuAutoMT);
	BOOL SetAutoMatrix(DHDEV_AUTOMT_CFG* stuAutoMT);

	BOOL StartUpgrade(char *pchFileName, fUpgradeCallBack cbUpgrade, LDWORD dwUser);
	BOOL StopUpgrade();

	BOOL GetTimeSchedule(int nChannelID, CFG_ACCESS_TIMESCHEDULE_INFO& stuTimeSchedule);
	BOOL SetTimeSchedule(int nChannelID, CFG_ACCESS_TIMESCHEDULE_INFO* stuTimeSchedule);

	BOOL GetAccessEventCfg(int nChannelID, CFG_ACCESS_EVENT_INFO& stuInfo);
	BOOL SetAccessEventCfg(int nChannelID, CFG_ACCESS_EVENT_INFO* stuInfo);

	BOOL InsertHolidayRecorde(NET_RECORDSET_HOLIDAY* stuInfo, int& nRecNo);
	BOOL GetHolidayRecorde(NET_RECORDSET_HOLIDAY& stuInfo);
	BOOL UpdateHolidayRecorde(NET_RECORDSET_HOLIDAY* stuInfo);
	BOOL RemoveHolidayRecorde(NET_RECORDSET_HOLIDAY* stuInfo);
	BOOL ClearHolidayRecorde();

	BOOL InsertPWDRecorde(NET_RECORDSET_ACCESS_CTL_PWD* stuInfo, int& nRecNo);
	BOOL GetPWDRecorde(NET_RECORDSET_ACCESS_CTL_PWD& stuInfo);
	BOOL UpdatePWDRecorde(NET_RECORDSET_ACCESS_CTL_PWD* stuInfo);
	BOOL RemovePWDRecorde(NET_RECORDSET_ACCESS_CTL_PWD* stuInfo);
	BOOL ClearPWDRecorde();

	BOOL InsertCardRecorde(NET_RECORDSET_ACCESS_CTL_CARD* stuInfo, BOOL bEx, int& nRetNo);
	BOOL GetCardRecorde(NET_RECORDSET_ACCESS_CTL_CARD& stuInfo);
	BOOL UpdateCardRecorde(NET_RECORDSET_ACCESS_CTL_CARD* stuInfo, BOOL bEx, int& nRetNo);
	BOOL RemoveCardRecorde(NET_RECORDSET_ACCESS_CTL_CARD* stuInfo);
	BOOL ClearCardRecorde();

	BOOL GetOpenDoorGroup(int nChannelID, CFG_OPEN_DOOR_GROUP_INFO& stuInfo);
	BOOL SetOpenDoorGroup(int nChannelID, CFG_OPEN_DOOR_GROUP_INFO* stuInfo);

	BOOL GetAccessGeneralInfo(CFG_ACCESS_GENERAL_INFO& stuInfo);
	BOOL SetAccessGeneralInfo(CFG_ACCESS_GENERAL_INFO* stuInfo);

	BOOL GetOpenDoorRouteInfo(CFG_OPEN_DOOR_ROUTE_INFO& stuInfo);
	BOOL SetOpenDoorRouteInfo(CFG_OPEN_DOOR_ROUTE_INFO* stuInfo);

	BOOL CardRecStartFind();
	BOOL CardRecFindNext(int nMaxNum, NET_RECORDSET_ACCESS_CTL_CARDREC* pstuCardRec, int& nRecordNum);
	BOOL CardRecStopFind();
	BOOL CardRecQueryCount(int& nCount);

	BOOL AlarmStartFind();
	BOOL AlarmFindNext(int nMaxNum, NET_RECORD_ACCESS_ALARMRECORD_INFO* pstuAlarm, int& nRecordNum);
	BOOL AlarmStopFind();
	BOOL AlarmQueryCount(int& nCount);

	BOOL LogStartFind();
	BOOL LogFindNext(int nMaxNum, NET_LOG_INFO* pstuAlarm, int& nRecordNum);
	BOOL LogStopFind();
	BOOL LogQueryCount(int& nCount);

	BOOL OpenDoor(int nChanne);
	BOOL CloseDoor(int nChanne);

	BOOL OpenAlways(int nChanne);
	BOOL CloseAlways(int nChanne);

	BOOL GetDoorState(int nChanne, EM_NET_DOOR_STATUS_TYPE& emStateType);

	BOOL GetLoginState();

	EM_DEVICE_ERR GetDeviceErr();
	DWORD GetLastError();

	BOOL StartGetFingerPrint();
private:
	Device();
	~Device();
	Device(const Device& device);
	Device& operator=(const Device& device);
	static Device*	mInstance;
private:
	
	DeviceImpl*			m_pDevImpl;
};
#endif