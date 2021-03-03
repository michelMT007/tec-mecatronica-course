#include <stdio.h>
#include <conio.h> 
#include <dos.h>
#define BIT0  0x01  // Não usado
#define BIT1  0x02  // Não usado
#define BIT2  0x04  // Não usado
#define BIT3  0x08  // Error
#define BIT4  0x10  // Slct out 
#define BIT5  0x20  // Paper End
#define BIT6  0x40  // Ack 
#define BIT7  0x80  // Busy 

int main(void)
{
     int x=10, y=5; //Coluna e Linha do vídeo
     unsigned char Byte; //Para armazenar o byte recebido da Porta Paralela
     clrscr();
     gotoxy(30,1);   printf("RECEBENDO SINAIS...");
     gotoxy(30,20); printf("Pressione uma tecla para sair..."); 
     gotoxy(x, y);    printf("Bit 3 - Error....:");
     gotoxy(x,y+1); printf("Bit 4 - Slct out.:"); 
     gotoxy(x,y+2); printf("Bit 5 - Paper End:"); 
     gotoxy(x,y+3); printf("Bit 6 - Ack:.....:"); 
     gotoxy(x,y+4); printf("Bit 7 - Busy.....:"); 
     while( ! kbhit() )  //Executa enquanto nenhuma tecla for pressionada.
     { 
           Byte = inportb(0x379);    //Ler um byte da Porta Paralela
           if((Byte & BIT3) == 0){     // Error: 0000-1000 
               gotoxy(x+20,y); printf("INATIVO"); 
           }else{ 
               gotoxy(x+20,y); printf("ATIVO      "); 
           }
           if((Byte & BIT4) == 0){    // Slct out: 0001-0000
               gotoxy(x+20,y+1); printf("INATIVO"); 
           }else{ 
               gotoxy(x+20,y+1); printf("ATIVO   "); 
           } 
           if((Byte & BIT5) == 0){    // Paper end: 0010-0000
               gotoxy(x+20,y+2); printf("INATIVO"); 
           }else{ 
               gotoxy(x+20,y+2); printf("ATIVO   "); 
           } 
           if((Byte & BIT6) == 0){     // Ack: 0100-0000
               gotoxy(x+20,y+3); printf("INATIVO"); 
           }else{ 
               gotoxy(x+20,y+3); printf("ATIVO   "); 
           }
           if((Byte & BIT7) == 0){     // Busy: 1000-0000
               gotoxy(x+20,y+4); printf("INATIVO"); 
           }else{ 
               gotoxy(x+20,y+4); printf("ATIVO   "); 
           } 
      } 
      clrscr(); 
}