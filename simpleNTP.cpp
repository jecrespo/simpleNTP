//
// FILE: simpleNTP.cpp
// VERSION: 1.0
// PURPOSE: Update time on Arduino via NTP
// Based on https://www.arduino.cc/en/Tutorial/UdpNtpClient
// aprendiendoarduino by jecrespo May 2016
//

#include "simpleNTP.h"

//Constructor
simpleNTP::simpleNTP()
{
	IPAddress ntpServer(193, 145, 15, 15);	//Default NTP Server
	_ntpServer = ntpServer;
	
}

simpleNTP::simpleNTP(IPAddress ntpServer)
{
	_ntpServer = ntpServer;

}

// Function read
// return values: UTC unix time
unsigned long simpleNTP::readNTP()
{	
	_udp.begin(LOCALPORT);
	sendNTPpacket();
	delay(2000);
	Serial.println("Receiving NTP packet...");
	if (_udp.parsePacket()) {
		Serial.println("NTP Server Connected");
		_udp.read(_packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer
		unsigned long highWord = word(_packetBuffer[40], _packetBuffer[41]);
		unsigned long lowWord = word(_packetBuffer[42], _packetBuffer[43]);
		unsigned long epoch = highWord << 16 | lowWord;  //seconds from 1/1/1900 (32 bits) = packetBuffer[40]+packetBuffer[41]+packetBuffer[42]+packetBuffer[43]
		epoch = epoch - 2208988800UL;  //Unix time
		return epoch;
	}
	else {
		Serial.println("Error Connecting NTP Server!");
		return 0;
	}
}

void simpleNTP::sendNTPpacket(void) {
	Serial.println("Sending NTP packet...");
	// set all bytes in the buffer to 0
	memset(_packetBuffer, 0, NTP_PACKET_SIZE);
	// Initialize values needed to form NTP request
	_packetBuffer[0] = 0b11100011;
	_packetBuffer[1] = 0;
	_packetBuffer[2] = 6;
	_packetBuffer[3] = 0xEC;
	// 8 bytes of zero for Root Delay & Root Dispersion
	_packetBuffer[12]  = 49;
	_packetBuffer[13]  = 0x4E;
	_packetBuffer[14]  = 49;
	_packetBuffer[15]  = 52;
	// all NTP fields have been given values, now
	// you can send a packet requesting a timestamp
	_udp.beginPacket(_ntpServer, 123);
	_udp.write(_packetBuffer, NTP_PACKET_SIZE);
	_udp.endPacket();
}