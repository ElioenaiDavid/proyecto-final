/*
 * servo.c
 *
 *  Created on: 27 oct. 2019
 *      Author: David
 */
#include <MKL25Z4.H>
#include "lcd.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define	RS	1
#define	RW	2
#define	EN	4

void LCD_init(void)
{
	SIM->SCGC5 |= 0x1000;
	PORTD->PCR[0] = 0x100;
	PORTD->PCR[1] = 0x100;
	PORTD->PCR[2] = 0x100;
	PORTD->PCR[4] = 0x100;
	PORTD->PCR[5] = 0x100;
	PORTD->PCR[6] = 0x100;
	PORTD->PCR[7] = 0x100;
	PTD->PDDR = 0xF7;
	delayMs(30);
	LCD_nibble_write(0x30, 0);
	delayMs(10);
	LCD_nibble_write(0x30, 0);
	delayMs(1);
	LCD_nibble_write(0x30, 0);
	delayMs(1);
	LCD_nibble_write(0x20, 0);
	delayMs(1);
	LCD_command(0x28);
	LCD_command(0x06);
	LCD_command(0x01);
	LCD_command(0x0F);
}
void LCD_nibble_write(unsigned char data, unsigned char control)
{
	data &= 0xF0;
	control &= 0x0F;
	PTD->PDOR = data | control;
	PTD->PDOR = data | control | EN;
	delayMs(0);
	PTD->PDOR = data;
	PTD->PDOR = 0;
}
void LCD_data(unsigned char data)
{
	LCD_nibble_write(data & 0xF0, RS);
	LCD_nibble_write(data << 4, RS);
	delayMs(1);
}
void LCD_command(unsigned char command)
{
	LCD_nibble_write(command & 0xF0, 0);
	LCD_nibble_write(command << 4, 0);
	if (command < 4)
		delayMs(4);
	else
		delayMs(1);
}


void LCD_Write(char c[32])
{
	int i=0;
	for(i=0;c[i] !='\0'; i++)
	{
		LCD_data(c[i]);
	}
}

void LCD_constleft(int p,int del){
	for(int i=0;i<p;i++){
		LCD_lefall(1);
		delayMs(del);
	}
}

void LCD_constrigth(int p,int del){
	for(int i=0;i<p;i++){
		LCD_rigthall(1);
		delayMs(del);
	}
}

void LCD_erase(void){
	LCD_command(1);
}
void LCD_line1(void){
	LCD_command(0x80);
}
void LCD_line2(void){
	LCD_command(0xC0);
}
void LCD_cusoron(void){
	LCD_command(0x0E);
}
void LCD_cursoroff(void){
	LCD_command(0x0C);
}
void LCD_lefall(int p){
	for(int i=0;i<p;i++){
	LCD_command(0x18);
}
}
void LCD_rigthall(int p){
	for(int i=0;i<p;i++){
	LCD_command(0x1C);
}
}
void LCD_coordinate(int x,int y){
if(y==1){ LCD_line1();
for(int i=0;i<x;i++){
	LCD_command(0x14);
}

}else if(y==2){
	LCD_line2();

for(int i=0;i<x;i++){
	LCD_command(0x14);
}

}

}
void LCD_blinkin(void){
	LCD_command(0x0F);
}

/*
 * lcd.c
 *
 *  Created on: 2 nov. 2019
 *      Author: David
 */


