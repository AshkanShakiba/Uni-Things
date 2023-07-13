//SPI SLAVE (ARDUINO)

//SPI COMMUNICATION BETWEEN TWO ARDUINO

//CIRCUIT DIGEST

//Pramoth.T

#include <SPI.h>

#define LEDpin 7

#define buttonpin 2

volatile boolean received;

volatile byte Slavereceived, Slavesend;

int buttonvalue;

int x;

void setup()

{

    Serial.begin(115200);

    pinMode(buttonpin, INPUT); // Setting pin 2 as INPUT

    pinMode(LEDpin, OUTPUT); // Setting pin 7 as OUTPUT

    pinMode(MISO, OUTPUT); //Sets MISO as OUTPUT (Have to Send data to Master IN

    SPCR |= _BV(SPE); //Turn on SPI in Slave Mode

    received = false;

    SPI.attachInterrupt(); //Interuupt ON is set for SPI commnucation
}

ISR(SPI_STC_vect) //Inerrrput routine function

{

    Slavereceived = SPDR; // Value received from master if store in variable slavereceived

    received = true; //Sets received as True
}

void loop()

{
    if (received) //Logic to SET LED ON OR OFF depending upon the value recerived from master

    {

        if (Slavereceived == 1)

        {

            digitalWrite(LEDpin, HIGH); //Sets pin 7 as HIGH LED ON

            Serial.println("Slave LED ON");
        }
        else

        {

            digitalWrite(LEDpin, LOW); //Sets pin 7 as LOW LED OFF

            Serial.println("Slave LED OFF");
        }

        buttonvalue = digitalRead(buttonpin); // Reads the status of the pin 2

        if (buttonvalue == HIGH) //Logic to set the value of x to send to master

        {

            x = 1;
        }
        else

        {

            x = 0;
        }

        Slavesend = x;

        SPDR = Slavesend; //Sends the x value to master via SPDR

        delay(1000);
    }
}
