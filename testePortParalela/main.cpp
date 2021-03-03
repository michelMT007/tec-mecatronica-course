
/***                                            ***/
/*** Test2.c  -- test interface to inpout32.dll ***/
/***  ( http://www.logix4u.net/inpout32.htm )   ***/
/***                                            ***/
/*** Copyright (C) 2005, Douglas Beattie Jr.    ***/
/***                                            ***/
/***    <beattidp@ieee.org>                     ***/
/***    http://www.hytherion.com/beattidp/      ***/
/***                                            ***/
/**************************************************/
/*	Last Update: 2006.05.14
 */

/*******************************************************/
/*                                                     */
/*  Builds with Borland's Command-line C Compiler      */
/*    (free for public download from Borland.com, at   */
/*  http://www.borland.com/bcppbuilder/freecompiler )  */
/*                                                     */
/*   Compile with:                                     */
/*                                                     */
/*   BCC32 -IC:\BORLAND\BCC55\INCLUDE  TEST2.C         */
/*                                                     */
/*                                                     */
/*  Be sure to change PPORT_BASE (Port Base address)   */
/*  accordingly if your LPT port is addressed          */
/*  elsewhere.                                         */
/*                                                     */
/*******************************************************/


#include <stdio.h>
#include <conio.h>
#include <windows.h>


/* Definitions in the build of inpout32.dll are:            */
/*   short _stdcall Inp32(short PortAddress);               */
/*   void _stdcall Out32(short PortAddress, short data);    */

/* prototype (function typedef) for DLL function Inp32: */

     typedef short (_stdcall *inpfuncPtr)(short portaddr);
     typedef void (_stdcall *oupfuncPtr)(short portaddr, short datum);

#define PPORT_BASE 0x378


// Prototypes for Test functions
void test_read8(void);
void test_write(void);
void test_write_datum(short datum);


/* After successful initialization, these 2 variables
   will contain function pointers.
 */
     inpfuncPtr inp32fp;
     oupfuncPtr oup32fp;
/* Wrapper functions for the function pointers
    - call these functions to perform I/O.
 */
     short  Inp32 (short portaddr)
     {
          return (inp32fp)(portaddr);
     }

     void  Out32 (short portaddr, short datum)
     {
          (oup32fp)(portaddr,datum);
     }


int main(void)
{
     HINSTANCE hLib;

     short x;
     int i;


     /* Load the library */
     hLib = LoadLibrary("inpout32.dll");

     if (hLib == NULL) {
          fprintf(stderr,"LoadLibrary Failed.\n");
          return -1;
     }

     /* get the address of the function */

     inp32fp = (inpfuncPtr) GetProcAddress(hLib, "Inp32");

     if (inp32fp == NULL) {
          fprintf(stderr,"GetProcAddress for Inp32 Failed.\n");
          return -1;
     }


     oup32fp = (oupfuncPtr) GetProcAddress(hLib, "Out32");

     if (oup32fp == NULL) {
          fprintf(stderr,"GetProcAddress for Oup32 Failed.\n");
          return -1;
     }


/*******************************************************/
/** IF WE REACHED HERE, INITIALIZED SUCCESSFUL    ******/
/*******************************************************/

     /* now test the functions */


     /***** Read 8 bytes at I/O base address */
     //test_read8();


     /*****  Write 0x75 to data register and verify */
     //test_write();



     /*****  One more time, different value */
     //test_write_datum(0xAA);


     /* finished - unload library and exit */
     FreeLibrary(hLib);
	 int teste;
	 scanf("%d",&teste);
     return 0;
}

/*
   TEST:  Read inputs of 8 registers from PORT_BASE address
 */
 /*
void test_read8(void) {

     short x;
     int i;

     //* Try to read 0x378..0x37F, LPT1:

     for (i=PPORT_BASE; (i<(PPORT_BASE+8)); i++) {

          x = Inp32(i);

          printf("Port read (%04X)= %04X\n",i,x);
     }

}*/

/*
   TEST:  Write constant 0x77 to PORT_BASE (Data register)
 */
/*void test_write(void) {
     short x;
     int i;

     //*****  Write the data register

     i=PPORT_BASE;
     x=0x75;

     //*****  Write the data register
     Out32(i,x);

     printf("Port write to 0x%X, datum=0x%2X\n" ,i ,x);

     //***** And read back to verify
     x = Inp32(i);
     printf("Port read (%04X)= %04X\n",i,x);


     //*****  Set all bits high
     x=0xFF;
     Out32(i,x);

     //****  Now, set bi-directional and read again
     Out32(PPORT_BASE+2,0x20);     // Activate bi-directional
     x = Inp32(i);
     printf("Set Input, read (%04X)= %04X\n",i,x);

     Out32(PPORT_BASE+2,0x00);     // Set Output-only again
     x = Inp32(i);
     printf("Reset Ouput, read (%04X)= %04X\n",i,x);


}*/

/*
   TEST:  Write data from parameter
 */
/*void test_write_datum(short datum) {
     short x;
     int i;

     i=PPORT_BASE;
     x = datum;

     //Write the data register
     Out32(i,x);

     printf("Port write to 0x%X, datum=0x%2X\n" ,i ,x);

     //***** And read back to verify
     x = Inp32(i);
     printf("Port read (%04X)= %04X\n",i,x);
}*/
