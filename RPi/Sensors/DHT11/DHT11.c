#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAXTIMINGS 85
#define DHTPIN 7

int dht11_dat[5] = {0, 0, 0, 0, 0};

void read_dht11_dat()
{
    uint8_t laststate = HIGH;
    uint8_t counter = 0;
    uint8_t j = 0, i;
    float f; 

    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0; //redundant?

    // pull pin down for 18 ms
    pinMode(DHTPIN, OUTPUT);
    digitalWrite(DHTPIN, LOW);
    delay(18);

    // pull pin up for 40 ms
    digitalWrite(DHTPIN, HIGH);
    delay(40);

    // prepare to read the pin
    pinMode(DHTPIN, INPUT);

    // detect changes for read data
    for(i = 0; i < MAXTIMINGS; i++)
    {
        counter = 0;

        while (digitalRead(DHTPIN) == laststate)
        {
            counter++;
            delayMicroseconds(1);

            if(counter == 255)
            {
                break;
            }
        }

        laststate = digitalRead(DHTPIN);

        if(counter == 255)
        {
            break;
        }

        // ignore first 3 transitions
        if((i >= 4) && (i % 2 == 0))
        {
            // put each bit into the storage bytes
            dht11_dat[j / 8] <<= 1;

            if(counter > 16)
            {
                dht11_dat[j / 8] |= 1;
                j++;
            }
        }

        // check we read 40 bits (8 bit x 5) + verify checksum in last byte. Print it out if data is good
        if( (j >= 40) && (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF)))
        {
            break;
        }
        else
        {
            printf("Data is currupted => skip \n");
        }

        int main(void)
        {
            if(wiringPiSetup() == -1)
            {
                exit(1);
            }

            while (1)
            {
                read_dht11_dat();
                delay(1000); //refresh after 1 s
            }
            
            return(0);

        }
        




        

    }

}
