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
    HINSTANCE hLib; //Instância para a DLL inpout32.dll.
	//PtrInp inportb;     //Instância para a função Imp32().
   	//mPrtOutp outportb;  //Instância para a função Out32().
              // Envia para a Porta LPT1
    unsigned char Valor=128; //Em binário: 10000000
    int teste;
	while( Valor > 0 )
   {
        //outportb(LPT1,Valor);
		printf("\nPressione uma tecla para ascender o próximo LED...");
        getch( );
        teste=(int)Valor;
        printf("\n valor:%d",& teste);
        Valor = Valor >> 1; //A cada passagem, o bit 1 é movido para a direita
   }
}
