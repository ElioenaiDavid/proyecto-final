/*
 * lcd.h
 *
 *  Created on: 2 nov. 2019
 *      Author: David
 */

#ifndef LCD_H_
#define LCD_H_

void LCD_init(void);
void LCD_nibble_write(unsigned char data, unsigned char control);
void LCD_data(unsigned char data);
void LCD_command(unsigned char command);
void LCD_Write(char c[32]);
void LCD_erase(void);
void LCD_line1(void);
void LCD_line2(void);
void LCD_cusoron(void);
void LCD_cursoroff(void);
void LCD_lefall(int p);
void LCD_rigthall(int p);
void LCD_coordinate(int x,int y);
void LCD_constleft(int p, int del);
void LCD_constrigth(int p,int del);
void LCD_blinkin(void);


#endif /* LCD_H_ */
