# Cantest for Teensy 3.2

Get two Teensys to talk to each other as Listeners or Talkers respectively.
The FlexCAN library is cloned from https://github.com/pawelsky/FlexCAN_Library.git as it is more advanced than the shipped FlexCAN implementation (Custom ID, supports multiple Teensys, ...)

# Function
The sender node will write a simple "12345678" message to the bus, the reading node will read it framewise (as soon as a new frame appears).


# Build
Compile either read.cpp or send.cpp for listening or talking.
