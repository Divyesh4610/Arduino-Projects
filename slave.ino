#include<SPI.h>
char buff [50];
volatile byte indx;
volatile boolean process;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(MISO,OUTPUT);
SPCR |=_BV(SPE);
indx=0;
process=false;
SPI.attachInterrupt();
}
ISR (SPI_STC_vect)
{
  byte c = SPDR;
  if(indx<sizeof buff)
  {
    buff [indx++]=c;
    if(c=='\r')
    process=true;
  }
}
void loop(void) {
  // put your main code here, to run repeatedly:
if(process)
 { process=false;
  Serial.println(buff);
  indx=0;
 }
}
