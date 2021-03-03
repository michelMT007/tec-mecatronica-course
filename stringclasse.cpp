
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main (void){
	char str1 [25], str2 [25];
	cout << "Digite uma palavra: "<<endl;
	cin >> str1;
	cout << "Digite outra palavra: "<<endl;
	cin >> str2;
	strcat (str1, str2);
	//system ("cls");
	cout << "A juncao dessas duas strings ";
	cout << " e igual a "<<str1<<endl;
	scanf("%c");

	return 0;
}
