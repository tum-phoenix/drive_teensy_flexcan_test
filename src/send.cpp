/**
 * Sending node to test FlexCAN implementation
 * This teensy will repeatedly write a simple message with multiple Frames
 * onto the bus
 * Adapted from pawelsky's FlexCAN library examples
 *
 * @author fwindolf - florianwindolf@gmail.com
 */

#include <FlexCAN.h>
#include <Arduino.h>

// Create FlexCAN driver with 500000 bauds and id 4
FlexCAN CANbus(500000, 4);

// Create a struct for the message that will get sent
static CAN_message_t msg;
static unsigned int msg_len = 8;

// Define the port of the builtin LED
int led = 13;

void setup(void)
{
  // Init CAN bus
  CANbus.begin();

  // Init LED and set on
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);

  // Build the message that gets sent over and over
  msg.len = msg_len;
  msg.id = 0x222;
  for ( int i = 0; i < msg_len; ++i)
  {
    msg.buf[i] = '0' + i;
  }

  // Wait some time
  delay(1000);
  Serial.println(F("Teensy 3.2 Can Test Sending Node"));
}


void loop(void)
{
  int txCount = msg_len;

  // Set LED to 1 to indicate BUS activity
  digitalWrite(led, 1);
  Serial.println("Writing Frame...");

  // Write to bus
  while ( txCount-- ) {
    CANbus.write(msg);
    msg.buf[0]++; // advance through buffer
  }

  // Set LED to 0 to indicate writing finished
  digitalWrite(led, 0);
  delay(200);
}
