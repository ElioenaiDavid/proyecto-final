/*
 * tecl.c
 *
 *  Created on: 2 nov. 2019
 *      Author: David
 */
#include <MKL25Z4.H>
#include "tecl.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void keypad_init(void)
{
	SIM->SCGC5 |= 0x0800;
	PORTC->PCR[0] = 0x103;
	PORTC->PCR[1] = 0x103;
	PORTC->PCR[2] = 0x103;
	PORTC->PCR[3] = 0x103;
	PORTC->PCR[4] = 0x103;
	PORTC->PCR[5] = 0x103;
	PORTC->PCR[6] = 0x103;
	PORTC->PCR[7] = 0x103;
	PTC->PDDR = 0x0F;
}



char keypad_getkey(void)
{
	int row, col;
	const char row_select[] = {0x01, 0x02, 0x04, 0x08};

	PTC->PDDR |= 0x0F;
	PTC->PCOR = 0x0F;
	delayUs(2);
	col = PTC->PDIR & 0xF0;
	PTC->PDDR = 0;

	if (col == 0xF0)
		return 0;

	for (row = 0; row < 4; row++)
	{
		PTC->PDDR = 0;
		PTC->PDDR |= row_select[row];
		PTC->PCOR = row_select[row];
		delayUs(2);
		col = PTC->PDIR & 0xF0;
		if (col != 0xF0) break;
	}

	PTC->PDDR = 0;

	if (row == 4)
		return 0;

	if (col == 0x70)
	{
		switch (row)
		{
		case 0:
			return 'A';
			break;
		case 1:
			return 'B';
			break;
		case 2:
			return 'C';
			break;
		case 3:
			return 'D';
			break;
		}
	}

	if (col == 0xB0)
	{
		switch (row)
		{
		case 0:
			return '3';
			break;
		case 1:
			return '6';
			break;
		case 2:
			return '9';
			break;
		case 3:
			return '#';
			break;
		}
	}
	if (col == 0xD0)
	{
		switch (row)
		{
		case 0:
			return '2';
			break;
		case 1:
			return '5';
			break;
		case 2:
			return '8';
			break;
		case 3:
			return '0';
			break;
		}
	}
	if (col == 0xE0)
	{
		switch (row)
		{
		case 0:
			return '1';
			break;
		case 1:
			return '4';
			break;
		case 2:
			return '7';
			break;
		case 3:
			return '*';
			break;
		}
	}
	return 0;
}

unsigned char  teclado(void){
	char key,letra,print;
	int lem = 0,cod =0;
	key =0;
	while(key==0){
		while(key==0){

			key = keypad_getkey();

		}
	if  (key=='*'){
   	  cod=0;
   	  lem=0;
      		return '*';
	} else if  (key=='1'){
	    		cod = 1;
	    		lem++;
	    		if (lem >= 5){
	    			lem=1;
	    		}
	    		key = 0;

	         delayMs(100);

	    	   }else if  (key=='2'){
	       		cod = 2;
	       		lem++;
	       		if (lem >= 5){
	       			lem=1;
	       		}
	       		key = 0;

	            delayMs(100);

	       	      }else if  (key=='3'){
	             	       		cod = 3;
	             	       		lem++;
	             	       		if (lem >= 5){
	             	       			lem=1;
	             	       		}
	             	       		key = 0;

	             	        delayMs(100);

	             	      }else if  (key=='4'){
	             	       		cod = 4;
	             	       		lem++;
	             	       		if (lem >= 5){
	             	       			lem=1;
	             	       		}
	             	       		key = 0;
	             	    	delayMs(100);

	             	      }else if  (key=='5'){
	             	       		cod = 5;
	             	       		lem++;
	             	       		if (lem >= 5){
	             	       			lem=1;
	             	       		}
	             	       		key = 0;
	             	           delayMs(100);


	             	      }else if  (key=='6'){
	             	       		cod = 6;
	             	       		lem++;
	             	       		if (lem >= 5){
	             	       			lem=1;
	             	       		}
	             	       		key = 0;
	             	           delayMs(100);


	             	      }else if  (key=='7'){
	             	       		cod = 7;
	             	       		lem++;
	             	       		if (lem >= 5){
	             	       			lem=1;
	             	       		}
	             	       		key = 0;
	             	           delayMs(100);


	             	      }else if  (key=='8'){
	             	       		cod = 8;
	             	       		lem++;
	             	       		if (lem >= 5){
	             	       			lem=1;
	             	       		}
	             	       		key = 0;
	             	           delayMs(100);


	             	      }else if (key =='9'){
	             	       			cod = 9;
	             	       			lem++;
	             	       			if (lem >= 5){
	             	       				lem=1;
	             	       			}
	             	       			key = 0;
	             	       	        delayMs(100);

	             	       		      }







		if (key=='D'){if(cod!=0){
	    letra = escribirletra (cod,lem);
	    return letra;
		}
	    cod = 0;
	    lem = 0;
	 //   LCD_data(letra);

		}
	key =0;
		}
}
unsigned char escribirletra(int cod,int lem){
	char tecla;
	switch (cod)
		{

		case 1:
			switch (lem)
				{
				case 1:
					tecla = '1';
					return tecla;
					break;
				case 2:
					tecla = 'A';
					return tecla;
					break;
				case 3:
					tecla = 'B';
					return tecla;
					break;
				case 4:
					tecla = 'C';
					return tecla;
					break;
				}
				return 0;

			break;
		case 2:
			switch (lem)
				{
				case 1:
					tecla = '2';
					return tecla;
					break;
				case 2:
					tecla = 'D';
					return tecla;
					break;
				case 3:
					tecla = 'E';
					return tecla;
					break;
				case 4:
					tecla = 'F';
					return tecla;
					break;
				}
							return 0;

			break;
		case 3:
			switch (lem)
		{
		case 1:
			tecla = '3';
			return tecla;
			break;
		case 2:
			tecla = 'G';
			return tecla;
			break;
		case 3:
			tecla = 'H';
			return tecla;
			break;
		case 4:
			tecla = 'I';
			return tecla;
			break;
		}
			case 4:
						switch (lem)
					{
					case 1:
						tecla = '4';
						return tecla;
						break;
					case 2:
						tecla = 'J';
						return tecla;
						break;
					case 3:
						tecla = 'K';
						return tecla;
						break;
					case 4:
						tecla = 'L';
						return tecla;
						break;
					}
						case 5:
								switch (lem)
							{
							case 1:
								tecla = '5';
								return tecla;
								break;
							case 2:
								tecla = 'M';
								return tecla;
								break;
							case 3:
								tecla = 'N';
								return tecla;
								break;
							case 4:
								tecla = 'O';
								return tecla;
								break;
							}
								case 6:
									switch (lem)
								{
								case 1:
									tecla = '5';
									return tecla;
									break;
								case 2:
									tecla = 'P';
									return tecla;
									break;
								case 3:
									tecla = 'Q';
									return tecla;
									break;
								case 4:
									tecla = 'R';
									return tecla;
									break;
								}
									case 7:
										switch (lem)
									{
									case 1:
										tecla = '7';
										return tecla;
										break;
									case 2:
										tecla = 'S';
										return tecla;
										break;
									case 3:
										tecla = 'T';
										return tecla;
										break;
									case 4:
										tecla = 'U';
										return tecla;
										break;
									}
										case 8:
										switch (lem)
									{
									case 1:
										tecla = '8';
										return tecla;
										break;
									case 2:
										tecla = 'V';
										return tecla;
										break;
									case 3:
										tecla = 'W';
										return tecla;
										break;
									case 4:
										tecla = 'X';
										return tecla;
										break;
									}case 9:
										switch (lem)
									{
									case 1:
										tecla = '9';
										return tecla;
										break;
									case 2:
										tecla = 'Y';
										return tecla;
										break;
									case 3:
										tecla = 'Z';
										return tecla;
										break;
									case 4:
										tecla = ' ';
										return tecla;
										break;
									}
	return 0;
}

}

void Write(char c[32])
{
	int i=0;
	for(i=0;c[i] !='\0'; i++)
	{
		LCD_data(c[i]);
	}
}

void erase(void){
	LCD_command(1);
}
void line1(void){
	LCD_command(0x80);
}
void line2(void){
	LCD_command(0xC0);
}
void cusoron(void){
	LCD_command(0x0E);
}
void cursoroff(void){
	LCD_command(0x0C);
}
void lefall(int p){
	for(int i=0;i<p;i++){
	LCD_command(0x18);
}
}
void rigthall(int p){
	for(int i=0;i<p;i++){
	LCD_command(0x1C);
}
}
void coordinate(int x,int y){
	if(y==1){ line1();
	for(int i=0;i<x;i++){
		LCD_command(0x14);
	}

	}else if(y==2){
		line2();

	for(int i=0;i<x;i++){
		LCD_command(0x14);
	}

	}

	}

int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}
void ftoa(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.';  // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}
