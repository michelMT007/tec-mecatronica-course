//#include "D:\Curso PIC\ControlaLED\ControlaLED\bluetooth.h"
#include <16F877A.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES RESERVED                 //Used to set the reserved FUSE bits

#use delay(clock=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

 int lido=1;
 bool data_avail = FALSE;

#int_RDA
void  RDA_isr(void) 
{
  lido = getc();
  data_avail = TRUE;
}



void main()
{
   int cont=0;
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);

   // TODO: USER CODE!!
   
    while (TRUE) {
      if (data_avail){  
         data_avail = FALSE;
         if(lido=='1') {
             output_high(PIN_B1);
             printf("ligou 1");
         }
         if(lido=='2') output_high(PIN_B2);
         if(lido=='A') output_low(PIN_B1);
         if(lido=='B') output_low(PIN_B2);
         if(cont> 250) cont=0;
         printf("ligou %d",cont++);
         
         delay_ms(300);
       }
    }

}
