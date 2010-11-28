#ifndef __NETWORK_H__
#define	__NETWORK_H__

enum NETWORK_EVENT
{
	CERT_CONNECTED,			
	CERT_CONNECT_FAIL,		
	CERT_SRVR_LIST,			
	CERT_ERROR,				
	LOGIN_CONNECTED,		
	LOGIN_CONNECT_FAIL,		
	LOGIN_PLAYER_LIST,		
	LOGIN_AUTHKEY_ERROR,	
	LOGIN_CACHE_ADDR,		
	CACHE_CONNECTED,		
	CACHE_CONNECT_FAIL,		
	LOGIN_REQ_PREJOIN,		
	LOGIN_ACK_PREJOIN,		
	CACHE_ACK_JOIN,			
	LOGIN_ERROR,			
	CERT_DISCONNECT,		
	LOGIN_DISCONNECT,		
	CACHE_DISCONNECT,		
	CACHE_ERROR,		
	LOGIN_CONNECT_STEP_ERROR,
	CACHE_CONNECT_STEP_ERROR,
};


class CNetwork
{
public:
	~CNetwork();
	static CNetwork& GetInstance();

	void	StartLog();
	void	OnEvent( NETWORK_EVENT event );

private:
	void	Log( LPCTSTR lpszFormat, ... );
	CNetwork();
};

#endif // __NETWORK_H__