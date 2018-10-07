#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"
#include <curl/curl.h>

int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT); /* PIR SENSOR */
  pinMode(1, OUTPUT); /* GREEN LED */
  pinMode(2, OUTPUT); /* RED LED */
  while(1) {
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1)
    {
	if(digitalRead(0) == 1)
	{
		ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/123", "Recieved", "Status Update", "Alarm Triggered");
		digitalWrite(2, HIGH);
		delay(500);
		digitalWrite(2, LOW);
		delay(500);
	}
    }
    printf("Waiting for event\n");
    while(digitalRead(0) == 0)
    {   /*
	if(digitalRead(0) == 1)
	{
		digitalWrite(1, HIGH);
		delay(500);
		digitalWrite(1, LOW);
		delay(500);
	}
	*/
	if(digitalRead(0) == 0)
	{
		digitalWrite(1, HIGH);
		delay(500);
		digitalWrite(1, LOW);
		delay(500);
	}
    }
    printf("Alarm\n");
  }
  /*NOTREACHED*/
  return 0 ;
}
