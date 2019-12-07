/*
 * servo.c
 *
 *  Created on: 27 oct. 2019
 *      Author: David
 */
#include <MKL25Z4.H>
#include "servo.h"

void servopin (int pin, int duty){

	if(pin==12){
	SIM->SCGC5 |= 0x200; /* enable clock to Port D */
	PORTA->PCR[12] = 0x0300; /* PTD1 used by TPM0 */
	SIM->SCGC6 |= 0x02000000; /* enable clock to TPM0 */
	SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
	TPM1->SC = 0; /* disable timer */
	TPM1->CONTROLS[0].CnSC = 0x20 | 0x08; /* edge-aligned, pulse high */
	TPM1->MOD = 52475; /* Set up modulo register for 60 kHz */
	TPM1->CONTROLS[0].CnV = duty; /* Set up channel value for 33% dutycycle */
	TPM1->SC = 0x0C; /* enable TPM0 with prescaler /16 */
} else if(pin ==13){

	SIM->SCGC5 |= 0x200; /* enable clock to Port D */
		PORTA->PCR[13] = 0x0300; /* PTD1 used by TPM0 */
		SIM->SCGC6 |= 0x02000000; /* enable clock to TPM0 */
		SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
		TPM1->SC = 0; /* disable timer */
		TPM1->CONTROLS[1].CnSC = 0x20 | 0x08; /* edge-aligned, pulse high */
		TPM1->MOD = 52475; /* Set up modulo register for 60 kHz */
		TPM1->CONTROLS[1].CnV = duty; /* Set up channel value for 33% dutycycle */
		TPM1->SC = 0x0C; /* enable TPM0 with prescaler /16 */
}else if(pin ==31){

	SIM->SCGC5 |= 0x2000; /* enable clock to Port D */
		PORTE->PCR[31] = 0x0300; /* PTD1 used by TPM0 */
		SIM->SCGC6 |= 0x01000000; /* enable clock to TPM0 */
		SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
		TPM0->SC = 0; /* disable timer */
		TPM0->CONTROLS[4].CnSC = 0x20 | 0x08; /* edge-aligned, pulse high */
		TPM0->MOD = 52475; /* Set up modulo register for 60 kHz */
		TPM0->CONTROLS[4].CnV = duty; /* Set up channel value for 33% dutycycle */
		TPM0->SC = 0x0C; /* enable TPM0 with prescaler /16 */
}
}

