/*
 * blinky.c -- working with Serial I/O and GPIO
 *
 * Assumes the LED's are connected to AXI_GPIO_0, on channel 1
 *
 * Terminal Settings:
 *  -Baud: 115200
 *  -Data bits: 8
 *  -Parity: no
 *  -Stop bits: 1
 */
#include <stdio.h>							/* printf(), getchar() */
#include "xil_types.h"					/* u32, u16 etc */
#include "platform.h"						/* ZYBOboard interface */
#include <xgpio.h>							/* Xilinx GPIO functions */
#include "xparameters.h"				/* constants used by the hardware */
#include <string.h>
#include <stdlib.h>
#include "led.h"

#define OUTPUT 0x0							/* setting GPIO direction to output */
#define CHANNEL1 1							/* channel 1 of the GPIO port */

/* led states */
#define LED_ON true
#define LED_OFF false

void getLine (char *str);

int main() {
	led_init();

   int buff = 80;
   char str[buff];

	 /*
		* set stdin unbuffered, forcing getchar to return immediately when
		* a character is typed.
		*/
	 setvbuf(stdin,NULL,_IONBF,0);

	 printf("[Hello]\n");

	 led_set(0, LED_ON);


	 int value = 0;
	 bool ans;

	 do {
		 if (strcmp(str, "0") == 0 || strcmp(str, "1") == 0 || strcmp(str, "2") == 0 || strcmp(str, "3") == 0){
			 //printf("[%s]\n\r", str);
			 if (strcmp(str, "0") == 0){
				 led_toggle(0);
				 ans = led_get(0);
			 } else if (strcmp(str, "1") == 0){
				 led_toggle(1);
				 ans = led_get(1);
			 } else if (strcmp(str, "2") == 0){
				 led_toggle(2);
				 ans = led_get(2);
			 } else if (strcmp(str, "3") == 0){
				 led_toggle(3);
				 ans = led_get(3);
			 }

			 if (ans == 1){
				 printf("[%s on]\n\r", str);
			 } else printf("[%s off]\n\r", str);

			 fflush(stdout);

		 }
		 printf(">");
		 fflush(stdout);
		 getLine(str);
		 printf("\n");
		 fflush(stdout);
		 value = strcmp(str, "q");
	 } while (value != 0);

	 led_set(0, LED_OFF);
   cleanup_platform();					/* cleanup the hardware platform */
   return 0;
}

void getLine(char * str){
	char c;
	int i = 0;

	c = getchar();
	printf("%c", c);
	fflush(stdout);

	while ( c != 13 ){
		str[i] = c;
		i++;
		c = getchar();
		printf("%c", c);
		fflush(stdout);
	}
	str[i] = '\0';
}
