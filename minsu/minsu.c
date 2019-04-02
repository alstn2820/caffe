#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LED 0
#define buttonL 1
#define buttonR 2

int main()
{
	int LEDstate=1;
	int L,R;

	srand(time(NULL));

	wiringPiSetup();
	pinMode (LED, OUTPUT);
	pinMode (buttonL, INPUT);
	pinMode (buttonR, INPUT);

	pullUpDnControl (buttonL, PUD_UP);
	pullUpDnControl (buttonR, PUD_UP);

	while(1)
	{
		L = digitalRead(buttonL);
		R = digitalRead(buttonR);
		
		if (LEDstate ==1) 
		{	printf("                       <GAME START>\n");
			delay(1000);

			digitalWrite(LED,HIGH);
			printf("                          WAIT...\n");
			delay(rand()% 5000+2000); 

			digitalWrite(LED,LOW);
			printf("                          PUSH!!!\n");
			LEDstate=0;
		}

		else if (LEDstate == 0)
		{ 						
			if(L == LOW)
			{	printf("   LEFT PLAYER WIN!!\n");
				delay(2500);
				LEDstate = 1;
			}
	
			else if(R == LOW)
			{
				printf("                                       RIGHT PLAYER WIN!! \n");
				delay(2500);
				LEDstate = 1;
			}
		}
	}
	return 0;
}
	



