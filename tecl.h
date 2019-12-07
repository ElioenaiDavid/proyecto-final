/*
 * tecl.h
 *
 *  Created on: 2 nov. 2019
 *      Author: David
 */

#ifndef TECL_H_
#define TECL_H_


void keypad_init(void);

char keypad_getkey(void);
unsigned char  teclado(void);
unsigned char escribirletra(int cod,int lem);
void Write(char c[32]);
void erase(void);
void line1(void);
void line2(void);
void cusoron(void);
void cursoroff(void);
void lefall(int p);
void rigthall(int p);
void coordinate(int x,int y);
void reverse(char *str, int len);
void ftoa(float n, char *res, int afterpoint);
int intToStr(int x, char str[], int d);
#endif /* TECL_H_ */
