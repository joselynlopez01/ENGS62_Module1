///*
// * blinky.c -- working with Serial I/O and GPIO
// *
// * Assumes the LED's are connected to AXI_GPIO_0, on channel 1
// *
// * Terminal Settings:
// *  -Baud: 115200
// *  -Data bits: 8
// *  -Parity: no
// *  -Stop bits: 1
// */
//#include <stdio.h>							/* printf(), getchar() */
//#include "xil_types.h"					/* u32, u16 etc */
//#include "platform.h"						/* ZYBOboard interface */
//#include <xgpio.h>							/* Xilinx GPIO functions */
//#include "xparameters.h"				/* constants used by the hardware */
//#include <string.h>
//#include <stdlib.h>
//#include <led.h>
//
//#define OUTPUT 0x0							/* setting GPIO direction to output */
//#define CHANNEL1 1							/* channel 1 of the GPIO port */
//
//void getLine (char *str);
//
//int main() {
//   XGpio port;									/* GPIO port connected to the leds */
//
//   init_platform();							/* initialize the hardware platform */
//
//   int buff = 80;
//   char str[buff];
//
//	 /*
//		* set stdin unbuffered, forcing getchar to return immediately when
//		* a character is typed.
//		*/
//	 setvbuf(stdin,NULL,_IONBF,0);
//
//	 printf("[Hello]\n");
//
//   XGpio_Initialize(&port, XPAR_AXI_GPIO_0_DEVICE_ID);	/* initialize device AXI_GPIO_0 */
//   XGpio_SetDataDirection(&port, CHANNEL1, OUTPUT);	    /* set tristate buffer to output */
//	 XGpio_DiscreteWrite(&port, CHANNEL1, 0x1);						/* turn on led0 */
//
//
//	 int value = 0;
//	 u32 reg_value;
//
//	 do {
//		 if (strcmp(str, "0") == 0 || strcmp(str, "1") == 0 || strcmp(str, "2") == 0 || strcmp(str, "3") == 0){
//			 printf("[%s]\n\r", str);
//			 if (strcmp(str, "0") == 0){
//				 reg_value = XGpio_DiscreteRead(&port, CHANNEL1);
//				 if (reg_value == 0){
//					 XGpio_DiscreteWrite(&port, CHANNEL1, 0x1);
//				 } else if (reg_value == 1){
//					 XGpio_DiscreteWrite(&port, CHANNEL1, 0x0);
//				 }
//			 }
//		 }
//		 printf(">");
//		 fflush(stdout);
//		 getLine(str);
//		 printf("\n");
//		 fflush(stdout);
//		 value = strcmp(str, "q");
//	 } while (value != 0);
//
//	 XGpio_DiscreteWrite(&port, CHANNEL1, 0x0);
//   cleanup_platform();					/* cleanup the hardware platform */
//   return 0;
//}
//
//void getLine(char * str){
//	char c;
//	int i = 0;
//
//	c = getchar();
//	printf("%c", c);
//	fflush(stdout);
//
//	while ( c != 13 ){
//		str[i] = c;
//		i++;
//		c = getchar();
//		printf("%c", c);
//		fflush(stdout);
//	}
//	str[i] = '\0';
//}
