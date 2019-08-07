/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int LED = 13;
int LED = 12;
int LED = 11;
int LED = 10;
int LED = 9;
int LED = 8;



// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED13, OUTPUT); 
   pinMode(LED12, OUTPUT);
    pinMode(LED11, OUTPUT);
     pinMode(LED10, OUTPUT);
      pinMode(LED9, OUTPUT);
       pinMode(LED8, OUTPUT);
        pinMode(LED7, OUTPUT);
         pinMode(LED6, OUTPUT);    
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(LED13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
  digitalWrite(LED12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);   
  digitalWrite(LED11, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);   
  digitalWrite(LED10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);   
  digitalWrite(LED9, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);   
  digitalWrite(LED8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);   
  digitalWrite(LED7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);   
  digitalWrite(LED6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
   digitalWrite(LED13, LOW);   // turn the LED off (LOW is the voltage level)
  delay(1000);
   digitalWrite(LED12, LOW);   // turn the LED off (LOW is the voltage level)
  delay(1000);
   digitalWrite(LED11, LOW);   // turn the LED off (LOW is the voltage level)
  delay(1000);
   digitalWrite(LED10, LOW);   // turn the LED off (LOW is the voltage level)
  delay(1000);
   digitalWrite(LED9, LOW);   // turn the LED off (LOW is the voltage level)
  delay(1000);
   digitalWrite(LED8, LOW);   // turn the LED off (LOW is the voltage level)
  delay(1000);
   digitalWrite(LED7, LOW);   // turn the LED off (LOW is the voltage level)
  delay(1000);
   digitalWrite(LED6, LOW);   // turn the LED off (LOW is the voltage level)
  delay(1000);
 
}
