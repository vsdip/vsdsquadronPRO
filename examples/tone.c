void tone(byte pin, uint16_t frequency, uint16_t duration)
{                                                             // input parameters: Arduino pin number, frequency in Hz, duration in milliseconds
  unsigned long startTime=millis();
  unsigned long halfPeriod= 1000000L/frequency/2;
  pinMode(pin,OUTPUT);
  while (millis()-startTime< duration)
  {
    digitalWrite(pin,HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(pin,LOW);
    delayMicroseconds(halfPeriod);
  }
  pinMode(pin,INPUT);
}

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  for(int i = 100; i < 5000; i+= 100)
  {
  Serial.println(i);
  tone(9,i,100); // tone on pin-9 with 1000 Hz for 100 milliseconds
  delay(10);
  }
}
