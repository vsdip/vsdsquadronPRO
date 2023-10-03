void servo_write(int pin, int deg) //this function is used to run the servo motor 
{                                  //the syntax to call the function is  -  "servo_write(pin,deg);"
  int time = 0;                    //where "pin" is the pin number of the gpio conneted to the output of the servo.
  pinMode(pin, OUTPUT);            //and "deg" is the rotation angle required  
  time = map(deg,0,180,544,2200);
  digitalWrite(pin,HIGH);
  delayMicroseconds(time);
  digitalWrite(pin,LOW);
  delay(20);
}
