//#include "C:\Curso PIC\Setesegmento\setesegmento.h"
#include <16F877A.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //Resistor/Capacitor Osc with CLKOUT
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected

#use delay(clock=20000000)


#define n0 0b00111111
#define n1 0b00000110
#define n2 0b01011011
#define n3 0b01001111
#define n4 0b01100110
#define n5 0b01101101
#define n6 0b01111101
#define n7 0b00000111
#define n8 0b01111111
#define n9 0b01101111

void AjustaDezena(int8 valor){
    
    if(valor == 0){
       output_B(n0);
    } 
    
    if(valor == 1){ 
       output_B(n1);
    }
    
    if(valor == 2){
       output_B(n2); 
    }
    
    if(valor == 3){
      output_B(n3);
    }
    
    if(valor == 4){
      output_B(n4);
    }
    
    if(valor == 5){
     output_B(n5);
    }
     
    if(valor == 6){ 
     output_B(n6);
    }
    
    if(valor == 7){
     output_B(n7);
    }
    if(valor == 8){
     output_B(n8);
    }
    
    if(valor == 9){
     output_B(n9);
    }
  
     
     

}

void ContaUnidades(){
     output_D(n0);
     delay_ms(50);
     output_D(n1);
     delay_ms(50);
     output_D(n2); 
     delay_ms(50);
     output_D(n3);
     delay_ms(50);
     output_D(n4);
     delay_ms(50);
     output_D(n5);
     delay_ms(50);
     output_D(n6);
     delay_ms(50);
     output_D(n7);
     delay_ms(50);
     output_D(n8);
     delay_ms(50);
     output_D(n9);
     delay_ms(50);

}

void main()
{
   int8 i;
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(FALSE);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

   output_D(0);
   while(true){
    for(i=0;i<=9;i=i+1){
      AjustaDezena(i);
      ContaUnidades();
     }     
   }
}
