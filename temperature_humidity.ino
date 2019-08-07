#include<DHT.h>
#include<DHT.h>
#define DHTTYPE DHT11
#define DHT11_PIN A0
DHT dht (DHT11_PIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.begin("Test Started...");
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
float h=dht.readHumidity();
float t=dht.readTemperature();
float f=dht.readTemperature(True);

Serial.print("Temperature");
Serial.print("t");
Serial.print("*c\t");
Serial.print("Temperature");
Serial.print(f);
Serial.print("*F\t");
Serial.print("Humidity");
Serial.print(h);

Serial.print("%\n");
delay(1000);
}
