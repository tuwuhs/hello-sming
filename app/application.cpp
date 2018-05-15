#include <user_config.h>
#include <SmingCore/SmingCore.h>

#define LED_PIN 2 // GPIO2

Timer procTimer;
bool state = true;

void onData(Stream& stream, char arrivedChar, unsigned short availableCharsCount)
{
	while (stream.available())
	{
		stream.write(stream.read() + 1);
	}
}

void blink()
{
	digitalWrite(LED_PIN, state);
	state = !state;
	// Serial.printf("Hello...\r\n");
	// debugf("debug");
}

void init()
{
	Serial.begin(SERIAL_BAUD_RATE);
	Serial.systemDebugOutput(false);
	Serial.setCallback(StreamDataReceivedDelegate(onData));
	
	pinMode(LED_PIN, OUTPUT);
	procTimer.initializeMs(1000, blink).start();
}
