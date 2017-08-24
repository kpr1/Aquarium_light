# Aquarium_light
Aquarium light controller :  can do dark, sunrise, daylight and sun fall events
Aquarium light controller is small controller provide just this light function, is driven from external signal.
If signal is 0, then is dark, if signal is 1 then lights. If is detected change of signal 0-1 then lightup (sunrise) sequence starts. And similar situation for light off (sunfall).

Why? 
a) because fishes like it
b) in nature sun is also going from sunrise to full lightoff, and before night it is sunfall.
c) is really nice !

You need :
----------
MCU is:  Attiny85
Arduino IDE (to compile)
installed Attiny support package for Ardino
AVRDude Win (to program Attiny85)
Mosfet transistor to drive powerful LEDs
Small switch for control day/night regime, or use upward controller.
