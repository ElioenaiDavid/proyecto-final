/*
 * ultri.c
 *
 *  Created on: 9 nov. 2019
 *      Author: David
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "ultri.h"
#include "fsl_debug_console.h"

void ultrainit(void){

	SIM->SCGC5 |= 0x800; /* enable clock to Port B */
	PORTC-> PCR[9] = 0x100; /* make PTB19 pin as GPIO */
	GPIOC->PDDR |= 0x200; /* make PTB19 as output pin */
	SIM->SCGC5 |= 0x2000; /* enable clock to Port A */
	PORTE->PCR[1] = 0x100; /* set PTA1 pin for TPM2CH0 */
	GPIOE->PDDR &= ~0x2; /* make PTB19 as output pin */

}

void delayUs(int n)
{
	int i;
		SysTick->LOAD = 20.970 - 1;
		SysTick->CTRL = 0x5; /* Enable the timer and choose sysclk as the clock source */
		for(i = 0; i < n; i++) {
			while((SysTick->CTRL & 0x10000) == 0) /* wait until the COUTN flag is set */
			{ }
		}
		SysTick->CTRL = 0; /* Stop the timer (Enable = 0) */
	}



void delayMs(int n) {
	int i;
	int j;
	for(i = 0 ; i < n; i++)
		for(j = 0 ; j < 3500; j++) {
		}
}
float mide(void){
float sumatoria=0;
float duracion;
int c,col;

	SIM->SCGC5 |= 0x800; /* enable clock to Port B */
	PORTC-> PCR[9] = 0x100; /* make PTB19 pin as GPIO */
	GPIOC->PDDR |= 0x200; /* make PTB19 as output pin */
	SIM->SCGC5 |= 0x2000; /* enable clock to Port A */
	PORTE->PCR[1] = 0x100; /* set PTA1 pin for TPM2CH0 */
	GPIOE->PDDR &= ~0x2; /* make PTB19 as output pin */
for(int k=0;k<100;k++){
PTC->PCOR=  0x200;
delayUs(1);
PTC->PSOR= 0x200;
delayUs(10);
PTC->PCOR=  0x200;

	col=(PTE->PDIR & 0x2);
while(col !=0x2){
	col=(PTE->PDIR & 0x2);

}
while(col ==0x2){
		c++;
col=(PTE->PDIR & 0x2);
}
sumatoria +=c*0.016355;
c=0;

}

duracion=sumatoria/100;
sumatoria =0;

return duracion;



}
