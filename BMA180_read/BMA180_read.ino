
#include <Wire.h>
#include <bma180.h>
#define DEBUGOFF

BMA180 bma180;

volatile byte newData=0;
volatile unsigned int countISR=0;
unsigned int served=0;

void BMAISR(void)
{
   countISR++;
   //bma180.readAccel(); 
   newData=1;
}

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  bma180.SetAddress((int)BMA180_DEFAULT_ADDRESS);
  bma180.SoftReset();
  bma180.enableWrite();
  int sversion;
  int id;
  bma180.getIDs(&id,&sversion);
  bma180.SetFilter(bma180.F10HZ);
  bma180.setGSensitivty(bma180.G8);
  attachInterrupt(0, BMAISR, RISING);
  bma180.SetSMPSkip();
  bma180.SetISRMode();
  bma180.disableWrite();
  delay(2000);
}

void loop()
{
  bma180.readAccel(); 
  Serial.print(bma180.getYValFloat(),DEC);
  Serial.print(" ");
  Serial.print(bma180.getXValFloat(),DEC);
  Serial.print(" ");
  Serial.println(bma180.getZValFloat(),DEC);
    delay(1);
  }
