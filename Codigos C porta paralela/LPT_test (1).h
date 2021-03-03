#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define LPT1 0x378
int main(void)
{
    unsigned char Valor=128; //Em binário: 10000000
    while( Valor > 0 )
   {   
              outportb(LPT1, Valor); // Envia para a Porta LPT1
              printf("\nPressione uma tecla para ascender o próximo LED...");
              getch( );
              Valor = Valor >> 1; //A cada passagem, o bit 1 é movido para a direita
    }
}