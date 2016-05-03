// 
// FILE: simpleNTP.h
// VERSION: 1.0
// PURPOSE: Update time on Arduino via NTP
// Based on https://www.arduino.cc/en/Tutorial/UdpNtpClient
// aprendiendoarduino by jecrespo May 2016
//

#ifndef simpleNTP_h
#define simpleNTP_h

#include <Arduino.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

#define NTPDUINO_LIB_VERSION "1.0"

#define LOCALPORT 8888		// local port to listen for UDP packets
#define NTP_PACKET_SIZE 48	//NTP time stamp is in the first 48 bytes of the message

class simpleNTP
{
	public:
		simpleNTP(void);						//Constructor with default NTP server
		simpleNTP(IPAddress ntpServer);		//Constructor with selected NTP server IP
		unsigned long readNTP(void);			//get datetime from NTP server

	private:
		EthernetUDP _udp;
		IPAddress _ntpServer;	//pool.ntp.org
		byte _packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets
		void sendNTPpacket(void);

};
#endif	//simpleNTP