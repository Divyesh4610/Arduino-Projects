void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String incomingString ="";
int startIndex = 0;
int endIndex = 0;
int led1 = 8;
int j=0;
int prev=0;
int pres=0;
int MOISTURE;
void setup() {
  // initialize serial:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print(" Soil Moisture  ");
  Serial.begin(9600);
  Serial.begin(9600);
   // prepare the digital output pins
   pinMode(led1, OUTPUT);
   // initially all are off
   digitalWrite(led1, LOW);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  //--Start: Send SMS --
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  //Serial.print("AT+CMGD=1,4\r");  // Deletes all SMS saved in SIM memory
  Serial.print("AT+CMGDA=\""); 
  Serial.println("DEL ALL\"");
  delay(1000);
  Serial.print("AT+CMGS=\"+918511868332\"\r");  //Number to which you want to send the sms
  delay(1000);
  Serial.print("Test SMS - It Started Working1..\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(10);
  /*
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  //Serial.print("AT+CMGD=1,4\r");  // Deletes all SMS saved in SIM memory
  Serial.print("AT+CMGDA=\""); 
  Serial.println("DEL ALL\"");
  delay(1000);
  
  Serial.print("AT+CMGS=\"+918905613709\"\r");  //Number to which you want to send the sms
  delay(1000);

Serial.print("Test SMS - It Started Working1..\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(10);
  //--End: SMS--*/
}
void loop() {
   j=analogRead(A0);
  j=map(j,0,982,148,0);
  pres=j;
  if(j>100)
  j=100;
  else if(j<0)
  j=0;
  lcd.setCursor(6,1);
  lcd.print(j);
  lcd.print("%  ");
  prev=j;
  delay(500);
  
  MOISTURE=analogRead(A0);
Serial.println(MOISTURE);

//////// MOISTUR IS GREATER THEN 80 ////////

  if (MOISTURE<=530)
  {
    Serial.print("AT+CMGF=1\r");    
  delay(1000);
  //Serial.print("AT+CMGD=1,4\r");  // Deletes all SMS saved in SIM memory
  Serial.print("AT+CMGDA=\""); 
  Serial.println("DEL ALL\"");
  delay(1000);
  
  Serial.print("AT+CMGS=\"+918511868332\"\r");  //Number to which you want to send the sms
  delay(1000);

Serial.print("MOISTURE VALUE IS GREATER THEN 80\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(1000);
  do {} while (1);
  }
  ////////  MOISTURE IS LESS THAN 30 ////////
  
  if(MOISTURE>=880)
  {
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  //Serial.print("AT+CMGD=1,4\r");  // Deletes all SMS saved in SIM memory
  Serial.print("AT+CMGDA=\""); 
  Serial.println("DEL ALL\"");
  delay(1000);
  
  Serial.print("AT+CMGS=\"+918511868332\"\r");  //Number to which you want to send the sms
  delay(1000);

Serial.print("MOISTURE VALUE IS LESS THAN 30\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(1000);
  do {} while (1);
  }
  // print the string when a newline arrives:
  if (stringComplete && inputString!="") {
    //Serial.print("AT+CMGL=ALL\r");
    inputString.toLowerCase();
    if(inputString=="@motor on#")

    {

      digitalWrite(led1, HIGH); 

    }

    else if(inputString=="@motor off#")

    {

      digitalWrite(led1, LOW); 

    }

   Serial.print("AT+CMGDA=\""); 

   Serial.println("DEL ALL\""); // To Delete Messages from SIM Memory

   delay(1000);

  // clear the string:

   inputString = "";

   stringComplete = false;

  }

}



void serialEvent() 

{

   if(stringComplete == false)

   { 

        incomingString = Serial.readString();

        if(incomingString!="")

        {

          startIndex = incomingString.indexOf("@");

          endIndex = incomingString.indexOf("#");



          if(startIndex>0 && endIndex>0)

          {

             inputString = incomingString.substring(startIndex,endIndex+1);

             stringComplete = true;

          }

   }
   
   }
 }
