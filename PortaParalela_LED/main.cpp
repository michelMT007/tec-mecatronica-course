//www.rogercom.com
//rogercom@rogercom.com
//-------------------------------------------------------------------------------------------------------------
#include <windows.h> // Adiciona a livraria windows.h
#include <stdio.h> // Adiciona a livraria studio.h
#include <conio.h> // Adiciona a livraria conio.h
#include <dos.h> // Adiciona a livraria dos.h
#define LPT1 0x378  // Define que PORtA sera igual a 0x378
//#define LPT1 0x3F8  // Define que PORtA sera igual a 0x378
int main(void)
{
    HINSTANCE hLib; //Inst�ncia para a DLL inpout32.dll.
	//PtrInp inportb;     //Inst�ncia para a fun��o Imp32().
   	//mPrtOutp outportb;  //Inst�ncia para a fun��o Out32().
              // Envia para a Porta LPT1
    unsigned char Valor=128; //Em bin�rio: 10000000
    int teste;
	while( Valor > 0 )
   {
        //outportb(LPT1,Valor);
		printf("\nPressione uma tecla para ascender o pr�ximo LED...");
        getch( );
        teste=(int)Valor;
        printf("\n valor:%d",& teste);
        Valor = Valor >> 1; //A cada passagem, o bit 1 � movido para a direita
   }
}
