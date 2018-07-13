/*----------------------------------------------------------------------*
 * simple-NTP library example sketch.                                   *
 * Self-adjusting clock from NTP server                                 *
 * aprendiendoarduino by jecrespo May 2016                              *
 *                                                                      *
 * This work is licensed under the Creative Commons Attribution-        *
 * ShareAlike 3.0 Unported License. To view a copy of this license,     *
 * visit http://creativecommons.org/licenses/by-sa/3.0/ or send a       *
 * letter to Creative Commons, 171 Second Street, Suite 300,            *
 * San Francisco, California, 94105, USA.                               *
 *----------------------------------------------------------------------*/

#include <TimeLib.h>        //Use this library https://github.com/PaulStoffregen/Time
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <simpleNTP.h>

simpleNTP ntp;	//simpleNTP object
byte mac[] = {0x90, 0xA2, 0xDA, 0x0F, 0x70, 0xEF};
byte ip[] = {192, 168, 1, 179};

void setup()
{
  Ethernet.begin(mac, ip);
  // Ethernet.begin(mac);  //For DHCP
  delay(500);
  Serial.begin(9600);
  Serial.println("Requesting Time...");
  unsigned long utc = ntp.readNTP();	//UTC time
  setTime(utc);
  Serial.println(utc);
}

void loop()
{
	Serial.println(millis());
	Serial.println(now());
	delay(1000);
}
