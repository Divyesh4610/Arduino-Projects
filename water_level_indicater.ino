
Primary

Skip to content
Using Gmail with screen readers

Conversations
2.02 GB (13%) of 15 GB used
Manage
Terms · Privacy · Program Policies
Last account activity: 0 minutes ago
Details

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String incomingString ="";
int startIndex = 0;
int endIndex = 0;
int led1 = 8;
int j=0;
int prev=0;

int S1,S2,S3;
int pres=0;
void setup() {
  // put your setup code here, to run once:
pinMode(10,INPUT);
pinMode(11,INPUT);
pinMode(12,INPUT);
Serial.begin(9600);
}

void loop() { 
  // put your main code here, to run repeatedly:
S1=digitalRead(10);
S2=digitalRead(11);
S3=digitalRead(12);
if(S1==LOW&&S3==LOW)
{
  //WATER IS LESS MOTOR TURN ON.
   // Serial.print("AT+CMGF=1\r");    
 // delay(1000);
 Serial.print("AT+CMGF=1\r");    
  delay(1000);
  //Serial.print("AT+CMGD=1,4\r");  // Deletes all SMS saved in SIM memory
  Serial.print("AT+CMGDA=\""); 
  Serial.println("DEL ALL\"");
  delay(1000);
  
  Serial.print("AT+CMGS=\"+918511868332\"\r");  //Number to which you want to send the sms
  delay(1000);

Serial.print("WATER LEVEL IS LOW SO TURN ON MOTOR....\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(10);
  }
  else if (S1==HIGH && S3==LOW && S2==HIGH)
{
    //WATER IS MEDIUM...
     // Serial.print("AT+CMGF=1\r");    
 // delay(1000);
 Serial.print("AT+CMGF=1\r");    
  delay(1000);
  //Serial.print("AT+CMGD=1,4\r");  // Deletes all SMS saved in SIM memory
  Serial.print("AT+CMGDA=\""); 
  Serial.println("DEL ALL\"");
  delay(1000);
  
  Serial.print("AT+CMGS=\"+918511868332\"\r");  //Number to which you want to send the sms
  delay(1000);

Serial.print("WATER LEVEL IS MEDIUM....\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(10);
    }
else if(S1==HIGH&&S3==HIGH)
{
 // WATER IS FULL MOTOR OFF...
  // Serial.print("AT+CMGF=1\r");    
 // delay(1000);
 Serial.print("AT+CMGF=1\r");    
  delay(1000);
  //Serial.print("AT+CMGD=1,4\r");  // Deletes all SMS saved in SIM memory
  Serial.print("AT+CMGDA=\""); 
  Serial.println("DEL ALL\"");
  delay(1000);
  
  Serial.print("AT+CMGS=\"+918511868332\"\r");  //Number to which you want to send the sms
  delay(1000);

Serial.print("WATER LEVEL IS HIGH SO TURN OFF THE MOTOR....\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(10);
  }

}
WATER LEVEL INDICATORNOTEPAD.txt
Displaying Water-Level-Indicator.gif.
