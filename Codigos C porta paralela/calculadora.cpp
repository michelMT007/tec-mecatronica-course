#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
using namespace std;

int main()
{

	int n1, n2, resultado;
    //cout<< "#####Calculadora#####";
    //cout<< "Insira o valor N1.";
	char c ;
	while(c != 'x'){
		system("cls");

		printf("#####Calculadora#####\n");
	    printf("Insira o valor N1.\n");
		cin>>n1;
		printf("Insira o valor N2.\n");
		cin>>n2;
		resultado=n1+n2;
		//cout<< "A soma é: %d",resultado;
		printf("A soma e: %d\n",resultado);
		printf("Para sair digite x\nPara Continuar digite qualquer tecla\n\n");
		printf("##################################\n");
		cin>>c;
		
    }
	return 0;
}
