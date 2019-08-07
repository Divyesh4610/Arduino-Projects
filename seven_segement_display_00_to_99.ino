void setup()
{
  for (int i = 0; i <= 13; i++)
    pinMode(i, OUTPUT); //Set all pins from 0 to 13 as OUTPUT
}
//The line below is the array containing all the binary numbers for the digits on a SSD from 0 to 9
const int number[11] = {0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};

void loop()
{
  for (int tens = 0; tens < 10; tens++)

  {
    display_tens(tens);
  }
}

void display_tens(const int tens)
{
  int pin1, a, ones;     
  //pin1 is just used to deal with pins of the 1st SSD which desplays the tens digit

  for (pin1 = 0, a = 0; pin1 < 7; pin1++, a++)
  {
    digitalWrite(pin1, bitRead(number[tens], a));
  }
  for (ones = 0; ones < 10; ones++)
  {
    display_ones(ones);
    delay(300); 
    //I have given a delay of 300 milliseconds. You can put your own Time!!
  }
}

void display_ones(const int x)
{ int pin2, b;             
//pin2 is just used to deal with pins of the 2nd SSD which desplays the ones digit

  for (pin2 = 7, b = 0; pin2 <= 13; pin2++, b++)
  {
    digitalWrite(pin2, bitRead(number[x], b));

  }

}

