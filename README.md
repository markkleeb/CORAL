

# C.O.R.A.L.


### Cybernetic Observation and Research of Aquatic Lifeforms


C.O.R.A.L. is a project conceived by [Floating Point](http://floating.pt) and constructed by [Beam Camp](http://beamcamp.com) in July 2015. It is made up of small segments of coral made from clay, molded in silicone, and cast in clear resin. Inside each segment of coral are WS2812 addressable LED strips.

The coral is controlled by a small electrical box on shore, which receives instructions from a control bunker. To communicate between the bunker and the box, we are using two Arduino microcontrollers and sending values over RS-485 data protocol. The master Arduino is in the bunker and the slave Arduino is in the electrical box.

This code requires the [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel_) library for Arduino and the [RS-485 Protocol](http://www.gammon.com.au/forum/?id=11428) library

