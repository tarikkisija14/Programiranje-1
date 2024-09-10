#include <iostream>
using namespace std;
#include <iomanip>


/* Napišite program koji omogućuje korisniku unos teksta 
(preko dinamičke alokacije) i zatim pronalazi najdužu riječ 
u unesenom tekstu. Dužina riječi se može odrediti brojem slova 
(alfabetskih simbola), a riječi se međusobno odvajaju bilo kojim 
znakom koji nije slovo (npr. razmak, interpunkcijski znak 
ili slično). Program treba ispisati dužinu najduže riječi i samu riječ. 


*/







int main()
{
	char* tekst;

	char temp[200]{};
	cout << "unesi tekst" << endl;
	cin.getline(temp, size(temp));
	int vel = strlen(temp) + 1;
	tekst = new char[vel];
	strcpy_s(tekst, vel, temp);

	int trenutna = 0;
	int najduza = 0;

	char* p = nullptr;

	for (int i = 0; i < vel; i++)
	{
		if (isalpha(tekst[i]))
			trenutna++;
		else
		{
			if (trenutna > najduza)
			{
				najduza = trenutna;
				p = tekst + i - trenutna;
			}
			trenutna = 0;

		}
	}

	cout << "najduza rijec ima: " << najduza << " slova" << endl;
	cout << endl;
	cout << "najduza rijec je  ";
	for (int i = 0;  i <najduza; i++)
	{
		cout << p[i];
	}

	return  0;
}