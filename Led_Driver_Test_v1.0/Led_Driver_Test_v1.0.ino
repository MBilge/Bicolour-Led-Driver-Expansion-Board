 
#include <Wire.h>
#include <Adafruit_MCP23017.h>

int t=100;

Adafruit_MCP23017 LedDriver;
 
typedef enum state_t {Green,Red,Off};

void setup()
{
  Serial.begin(9600); // set up serial
  Serial.println("Serial Started");
  Wire.begin();           // Wire must be started!
  
  LedDriver.begin(0x27);  // Address set to zero.
  AllPinOUTPUT();
}

void Led(int LedNumber,state_t state)
{
  switch (state){
    case Green : LedDriver.pinMode(LedNumber,  OUTPUT);  // Make led available
                 LedDriver.digitalWrite(LedNumber, HIGH);
                 break;
    case Red   : LedDriver.pinMode(LedNumber,  OUTPUT); // Make led available
                 LedDriver.digitalWrite(LedNumber, LOW);
                 break;            
    case Off   : LedDriver.pinMode(LedNumber,  INPUT);
                 break;
  }
}

void AllPinOUTPUT()
{
  for (int pin=0;pin<16;pin++)
  {
    LedDriver.pinMode(pin,OUTPUT);
  }
}

void AllPinINPUT() // will switch off all leds
{
  for (int pin=0;pin<16;pin++)
  {
    LedDriver.pinMode(pin,INPUT);
  }
}

 void AllLedsGreen()
 {
  for (int leds=0 ; leds<16 ; leds++) Led(leds,Green);
 }

  void AllLedsRed()
 {
  for (int leds=0 ; leds<16 ; leds++) Led(leds,Red);
 }

   void AllLedsOff()
 {
  for (int leds=0 ; leds<16 ; leds++) Led(leds,Off);
 }

 void AllLedsGreenFlashing(int t,int r)
 {
  for (int i=0 ; i<r ; i++)
  {
    AllLedsGreen(); delay(t);
    AllLedsOff();   delay(t);
  }
 }

 void AllLedsRedFlashing(int t,int r)
 {
  for (int i=0 ; i<r ; i++)
  {
    AllLedsRed(); delay(t);
    AllLedsOff(); delay(t);
  }  
 }

 void AllLedsGreenAndRedFlashing(int t,int r)
 {
  for (int i=0 ; i<r ; i++)
  { 
    AllLedsGreen(); delay(t); 
    AllLedsRed();   delay(t);
  }   
 }

void WalkingGreenToRight(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsOff();
    for (int i=0; i<16 ;i++)
    {
      Led(i,Green); delay(t);
      Led(i,Off);   //delay(t);
    }
  }
}

void WalkingGreenToLeft(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsOff();
    for (int i=15; i>=0 ;i--)
    {
      Led(i,Green); delay(t);
      Led(i,Off);   //delay(t);
    }
  }
}

void WalkingRedToRight(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsOff();
    for (int i=0; i<16 ;i++)
    {
      Led(i,Red); delay(t);
      Led(i,Off);   //delay(t);
    }
  }
}

void WalkingRedToLeft(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsOff();
    for (int i=15; i>=0 ;i--)
    {
      Led(i,Red); delay(t);
      Led(i,Off);   //delay(t);
    }
  }
}

void FillingGreenToRight(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsOff();
    for (int i=0; i<16 ;i++)
    {
      Led(i,Green); delay(t);
    }
  }
}

void FillingGreenToLeft(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsOff();
    for (int i=15; i>=0 ;i--)
    {
      Led(i,Green); delay(t);
    }
  }
}

void FillingRedToRight(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsOff();
    for (int i=0; i<16 ;i++)
    {
      Led(i,Red); delay(t);
    }
  }
}

void FillingRedToLeft(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsOff();
    for (int i=15; i>=0 ;i--)
    {
      Led(i,Red); delay(t);
    }
  }
}

void UnFillingGreenToRight(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsGreen();
    for (int i=15; i>=0 ;i--)
    {
      Led(i,Off); delay(t);
    }
  }
}

void UnFillingGreenToLeft(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsGreen();
    for (int i=0; i<16 ;i++)
    {
      Led(i,Off); delay(t);
    }
  }
}

void UnFillingRedToRight(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsRed();
    for (int i=15; i>=0 ;i--)
    {
      Led(i,Off); delay(t);
    }
  }
}

void UnFillingRedToLeft(int t,int r)
{  
  for (int n=0; n<r ; n++)
  {
    AllLedsRed();
    for (int i=0; i<16 ;i++)
    {
      Led(i,Off); delay(t);
    }
  }
}

void LedMix(word w)
{
 AllPinOUTPUT();
 
 for (int bits = 0; bits < 16; bits++) 
 {
    if (w & (1 << bits)) { Led(bits, Green); }
    else                 { Led(bits, Red  ); }
 }
}

void loop()
{
  AllLedsOff(); // switch all leds off

  AllLedsGreenFlashing(200,10);
  AllLedsRedFlashing(200,10);
  AllLedsGreenAndRedFlashing(200,10);

  WalkingGreenToRight(100,1);
  WalkingGreenToLeft(100,1);

  WalkingRedToRight(100,1);
  WalkingRedToLeft(100,1);  
  
  FillingGreenToRight(100,1);
  UnFillingGreenToRight(100,1);
  FillingGreenToLeft(100,1);
  UnFillingGreenToLeft(100,1);
  
  FillingRedToRight(100,1);
  UnFillingRedToRight(100,1);
  FillingRedToLeft(100,1);
  UnFillingRedToLeft(100,1);
 
  LedMix(0b0000111100001111); delay(200);
  LedMix(0b1100110011001100); delay(200);

}
