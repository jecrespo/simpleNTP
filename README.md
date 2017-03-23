# simpleNTP

The aim of **simpleNTP** is help Arduino time synchronization via NTP.

With an arduino connected to Internet or to an intranet with a NTP server, it's posible to Arduino have timekeeping ability.

Network Time Protocol NTP - https://en.wikipedia.org/wiki/Network_Time_Protocol
NTP servers give time in Coordinanted Universal Time (UTC)

Based on https://www.arduino.cc/en/Tutorial/UdpNtpClient

######aprendiendoarduino by jecrespo May 2016
######www.aprendiendoarduino.com

-----

#####TODO List:
- constructor with nameserver (DNS lookup host to connect)
- update local time using Time and Timezone
- add support for DST (Daylight saving time)
- readNTP returns local time instead of UTC
- pass DST configuration to simpleNTP object
- add DST and zones preconfigured for countries
- add NTP server lists
- leap second support?, leap year supported by Time library
- ethernet2 support?
- example with simpleNTP as sync source in Time function
- example update interval with Time library functions setSyncProvider and setSyncInterval

-----

This library is designed in conjunction with the Arduino Time Library and Arduino Timezone Library.
Arduino Time Library: http://www.pjrc.com/teensy/td_libs_Time.html
Arduino Timezone Library: https://github.com/JChristensen/Timezone

simple-NTP library relies on Time Library for timekeeping functionality and Timezone library for DST and zone adjust time functionality
