/**
 * Reading node to test FlexCAN implementation
 * This teensy will dump all received frames to the serial interface, not piecing
 * them together to a message again.
 * Adapted from pawelsky's FlexCAN library examples
 *
 * @author fwindolf - florianwindolf@gmail.com
 */

#include <FlexCAN.h>
#include <Arduino.h>

// Create FlexCAN driver with 500000 bauds and id 3
FlexCAN CANbus(500000, 3);

// Create a struct for the message that is getting read
static CAN_message_t msg;

// Define the port of the builtin LED
int led = 13;

void setup(void)
{
  // Init CAN bus
  CANbus.begin();

  // Init LED and set on
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);

  delay(1000);
  Serial.println(F("Teensy 3.2 Can Test Reading Node"));
}


void loop(void)
{
  // Number of read frames
  int rxCount = 0;

  // LED on to indicate bus reading
  digitalWrite(led, 1);

  // Wait until there is a frame on the bus
  if(CANbus.available())
  {
    // Print the frame(s) to serial
    Serial.write("Received Frame: ");
    while ( CANbus.read(msg) )
    {
      Serial.write(msg.buf[0]);
      rxCount++;
    }
    // Append the number of frames
    Serial.write(" (");
    Serial.write(rxCount);
    Serial.println(")");
    digitalWrite(led, 0);
  }


}
