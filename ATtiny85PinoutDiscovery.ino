/*
 ATtinyPinoutDiscovery: verify your Arduino to ATtiny pin mapping by flashing LEDs.
 Copyright Jason Pepas (Pepas Labs, LLC)
 Released under the terms of the MIT License.
 */
 
// ATiny85 pinout:
//
//                                      +--\/--+
//        (PCINT5/!RESET/ADC0/dW) PB5  -|1    8|-  VCC
// (PCINT3/XTAL1/CLKI/!OC1B/ADC3) PB3  -|2    7|-  PB2 (SCK/USCK/SCL/ADC1/T0/INT0/PCINT2)
//  (PCINT4/XTAL2/CLKO/OC1B/ADC2) PB4  -|3    6|-  PB1 (MISO/DO/AIN1/OC0B/OC1A/PCINT1)
//                                GND  -|4    5|-  PB0 (MOSI/DI/SDA/AIN0/OC0A/!OC1A/AREF/PCINT0)
//                                      +------+

#define ARDUINO_PIN_D0 0
#define ARDUINO_PIN_D1 1
#define ARDUINO_PIN_D2 2
#define ARDUINO_PIN_D3 3
#define ARDUINO_PIN_D4 4
#define ARDUINO_PIN_D5 5

#define ATTINY_PIN_1 ARDUINO_PIN_D5
#define ATTINY_PIN_2 ARDUINO_PIN_D3
#define ATTINY_PIN_3 ARDUINO_PIN_D4
#define ATTINY_PIN_5 ARDUINO_PIN_D0
#define ATTINY_PIN_6 ARDUINO_PIN_D1
#define ATTINY_PIN_7 ARDUINO_PIN_D2

// project pinout:
//
//            +--\/--+
//  (A0) D5  -|1    8|-  Vcc
//  (A3) D3  -|2    7|-  D2 (A1)   
//  (A2) D4  -|3    6|-  D1 (PWM)  
//      GND  -|4    5|-  D0 (PWM)
//            +------+


void flashLED(int pin)
{
  digitalWrite(pin, HIGH);
  delay(200);
  digitalWrite(pin, LOW);
  delay(200);
}

void flashLEDNTimes(int pin, int times)
{
  for (int i = 0; i < times; i++)
  {
    flashLED(pin);
  }
}

void mapArduinoPinout()
{
  flashLEDNTimes(ARDUINO_PIN_D0,10);
  flashLEDNTimes(ARDUINO_PIN_D1,1);
  flashLEDNTimes(ARDUINO_PIN_D2,2);
  flashLEDNTimes(ARDUINO_PIN_D3,3);
  flashLEDNTimes(ARDUINO_PIN_D4,4);

  // be careful, this is the reset pin.
  //flashLEDNTimes(ARDUINO_PIN_D5,5);
}

void pinSetup()
{
  pinMode(ARDUINO_PIN_D0, OUTPUT);
  digitalWrite(ARDUINO_PIN_D0, LOW);
  
  pinMode(ARDUINO_PIN_D1, OUTPUT);
  digitalWrite(ARDUINO_PIN_D1, LOW);

  pinMode(ARDUINO_PIN_D2, OUTPUT);
  digitalWrite(ARDUINO_PIN_D2, LOW);

  pinMode(ARDUINO_PIN_D3, OUTPUT);
  digitalWrite(ARDUINO_PIN_D3, LOW);

  pinMode(ARDUINO_PIN_D4, OUTPUT);
  digitalWrite(ARDUINO_PIN_D4, LOW);
  
  // be careful, this is the reset pin.
  //pinMode(ARDUINO_PIN_D5, OUTPUT);
  //digitalWrite(ARDUINO_PIN_D5, LOW);
}

void setup()
{
  pinSetup();
}

void loop()
{
  mapArduinoPinout();
}

