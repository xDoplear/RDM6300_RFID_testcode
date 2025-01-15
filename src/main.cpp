//test program for RDM6300 RFID scanner

#include <Arduino.h>
#include <AdafruitIO.h>
#include <rdm6300.h>
#include "WiFiClientSecure.h"

#define READ_LED_PIN 13

Rdm6300 rdm6300;

void setup()
{
	Serial.begin(115200);

	pinMode(READ_LED_PIN, OUTPUT);
	digitalWrite(READ_LED_PIN, LOW);

	Serial1.begin(RDM6300_BAUDRATE); 
	rdm6300.begin(&Serial1);

	Serial.println("\nPlace RFID tag near the rdm6300...");
}

void loop() {

	if (rdm6300.get_new_tag_id())
		Serial.println(rdm6300.get_tag_id(), HEX);

	digitalWrite(READ_LED_PIN, rdm6300.get_tag_id());

	delay(10);
}