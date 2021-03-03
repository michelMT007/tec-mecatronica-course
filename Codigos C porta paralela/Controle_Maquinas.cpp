#include <cstdlib>
#include<stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#include <iostream>


using namespace std;

int main(void)
{
	printf("Controle de Maquinas");
	char maquina[1];
	
	cin>>maquina;
	if(maquina == "1")
	{
        cout<<"Ligar Maquina 1";
        delay(10);
        printf("Desligar Maquina 1");
	}

    if(maquina == '2')
	{
        printf("**************************");
        printf("Ligar Maquina 2");
        sleep(500);
        printf("Desligar Maquina 2");
        printf("##########################");
	}
	
	if(maquina =='3')
	{
        printf("**************************");
        printf("Ligar Maquina 2");
        sleep(500);
        printf("Desligar Maquina 2");
        printf("**************************");
	}
	
	if(maquina =='0')
	{

	}
	
	system("pause");
	return 0;
}
