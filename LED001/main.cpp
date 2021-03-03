#include <windows.h>
#include <stdio.h>
#include <time.h>
int main()
{
    long contador=1;
    
	while(true){
		printf("Ciclo: %d\n",contador);
		printf("Ligar LED 1\n");
		Sleep(1000); // this will make the program pause for 1000 milliseconds
	    printf("Desligar LED 1\n");
        Sleep(1000);
        contador++;
		//int test;
	}
    //scanf("%d",&test);
	return 0;
}
