#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "ultri.h"
#include "lcd.h"
#include "tecl.h"
#include "matri.h"
#include "servo.h"
#include "fsl_debug_console.h"


void proyecta(void);// funcion para proyectar el valor de la distancia en lcd
int setper(void);//funcion para indicar a travez del teclado el radio del perimetro
void dispara(void);// funcion para poner en posicion los servos y ejecutar el diparo
int c=0,cont=0;
int p=0;

float duracione;
int col;
char Dis[10];
int reference=10;
float sumatoria=0;
int acu[32];
int flag=0;
int suma=0;
int count=0;
int pos;
int main (void) {


LCD_init(); // iniciamos la lcd
Matrixinit();// iniciamos la matriz
//keypad_init();
servopin(31,1000); // se coloca el servo en su posicion inicial

reference=setper(); // se introduce el valor del perimetro
// la funcion se divide en dos bucles uno que va de izquierda a derecha y otro de derecha a izquierda
// bucle infinito While (1)

while (1) {
	//primer bucle de derecha a izquierda
for(int t =1000;t<=3496;t+=78){
servopin(13,t);//setea el servo en una posicion

duracione=mide();//realiza la  medicion
ftoa (duracione, Dis, 3);// traduce la medicion a un array
proyecta();//proyecta la distacia en la lcd
// pasa a comparar la distancia establecida con la actual
if(duracione<reference){
suma+=t;
cont++;
flag=1;


}
// las suma para hacer una promediacion de donde esta el objetivo
if(duracione>reference && flag==1){


pos=suma/cont;
if(duracione<=25 ){pos-=150;}
else if(duracione>25){pos-=152;}

servopin(13,pos);
delayMs(1000);
Matrixscrollup("321");
dispara();
suma=0;
cont=0;
flag=0;

}
delayMs(100);


}

//segundo bucle de derecha  aizquierda
// repite lo mismo
for( int t =3496;t>1000;t-=78){
servopin(13,t);

duracione=mide();
ftoa (duracione, Dis, 3);
proyecta();
//proyect(t,duracion);
if(duracione<reference){
suma+=t;
cont++;
flag=1;

}
if(duracione>reference && flag==1){


pos=suma/cont;
if(duracione<=25 ){pos+=136;}
else if(duracione>25){pos+=152;}

servopin(13,pos);
delayMs(1000);
Matrixscrollup("321");
dispara();
suma=0;
cont=0;
flag=0;

}
delayMs(100);



}
}
}


void proyecta(void){
LCD_command(1);
LCD_Write("La Distancia es:");
LCD_line2;
LCD_data(Dis[0]);
LCD_data(Dis[1]);
LCD_data(Dis[2]);
if(Dis[3]!=0){
LCD_data(Dis[3]);}
if(Dis[4]!=0){
LCD_data(Dis[4]);}
LCD_Write(" CM");

}

void dispara(void){

servopin(12,1000);
if(reference<=25 ){servopin(31,2000);}
else if(reference>25 && reference<35){servopin(31,1960);}
else if(reference>=35){servopin(31,1940);}
delayMs(1500);

servopin(12,2000);
delayMs(2000);
servopin(12,1000);
servopin(31,1000);

LCD_erase;
LCD_Write("Done madafaka");
LCD_line2;
LCD_Write("regarga");
delayMs(2000);
}

int setper(void){
keypad_init();
int resultado;
char per[2];
char k=0;
int i=0;
LCD_Write("Indique el perimetro:");
LCD_line2;
while (i<2){
while (k==0){
k = keypad_getkey();
delayMs(100);
}
if(k=='*'){
LCD_erase;
LCD_Write("Indique el perimetro:");
LCD_line2;
per[0]=0;
per[1]=0;
i=0;
}else{
LCD_data(k);
per[i]=k;
i++;
}
k=0;

}
resultado=atoi(per);

return resultado;
}
