/*******************************************************************************************************************************
                                       BLOCKING FUNCTION TO READ INPUT FROM 4X4 KEYPAD 
                                      RETURNS ONLY ONCE AN INPUT FROM THE KEYPAD IS READ
*******************************************************************************************************************************/
int key[8];
char key_out[4][4] = {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'}; 

void keypad_attach(int x0,int x1,int x2,int x3,int x4,int x5,int x6,int x7)
{
  key[0] = x0;
  key[1] = x1;
  key[2] = x2;
  key[3] = x3;
  key[4] = x4;
  key[5] = x5;
  key[6] = x6;
  key[7] = x7;
  for(int i = 0 ; i <4; i++)
  {
    pinMode(key[i],OUTPUT);
    digitalWrite(key[i],HIGH);
  }
  for(int i = 4 ; i <8; i++)
  {
    pinMode(key[i],INPUT);
  }  
} 

char keypad_read( )
{
  while(1)
  {
    for(int j = 0; j<4; j++)
    {
      digitalWrite(key[j],LOW);
      for(int k = 0; k <4; k++ )
      {

        if(!digitalRead(key[k+4]))
        {
         // Serial.println("returning value");
          return key_out[j][k];  
        }

      }
      digitalWrite(key[j],HIGH);
    }
  }
}

//************************************************* END OF FUNCTIONS ****************************************************************
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  keypad_attach(9,8,7,6,5,4,3,2);
  Serial.print(keypad_read());
  Serial.println();
  delay(1000);
}
