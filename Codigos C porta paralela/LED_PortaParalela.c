#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define BIT0LIGALED1    3    // 0000 1010
#define BIT1LIGALED2  15    // 0000 1001
#define BIT2LIGALED3    9    // 0000 1111
#define BIT3LIGALED4  10    // 0000 0011
#define LIGATODOS        4   // 0000 0100
#define DESLIGATODOS   11   // 0000 1011

int main(void)
{
    outportb(0x37A,LIGATODOS);  //Liga todos os LEDs
    getch();
    outportb(0x37A,BIT0LIGALED1); //Liga LED 1
    getch();
    outportb(0x37A,BIT1LIGALED2);
    getch();
    outportb(0x37A,BIT2LIGALED3);
    getch();
    outportb(0x37A,BIT3LIGALED4);
    getch();
    outportb(0x37A,DESLIGATODOS);    //Desliga todos os LEDs
}