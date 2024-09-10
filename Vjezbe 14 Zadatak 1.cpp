#include <iostream>
using namespace std;
#include <iomanip>


/* Napisati program za unos 𝑛 tekstova (gdje je 𝑛 ukupan broj tekstova
koji unosi korisnik). Svaki tekst mora biti kreiran kao dinamički niz
karaktera. Zatim, po mogućnosti možete koristite funkcije sa sljedećim
prototipom


isSingleword-const char* tekst-bool-Provjerava da li je
prosljedjeni tekst zapraov jedna rijec.

 Nakon korisničkog unosa tekstova (koji mogu biti različitih dužina),
 potrebno je omogućiti unos jedne riječi (statički niz karaktera
 veličine 50), uz napomenu da se unos ponavlja dokle god nije
 unesena isključivo jedna riječ.
Nakon uspješnog unosa jedne riječi, potrebno je pozvati funkciju
count i ispisati ukupan broj tekstova u kojima možemo pronaći unesenu riječ.
*/




int count(char** tekstovi, int brojtekstova, const char* rijec)
{
	int brojac = 0;
	for (int i = 0; i < brojtekstova; i++)
	{
		if (strstr(tekstovi[i], rijec) != nullptr)
			brojac++;
	}
	return brojac;
}

bool isSingleword(const char* tekst)
{
	const char* p = tekst;
	while (*p != '\0')
	{
		if (*p == ' ')
			return false;
		p++;
	}
	return true;
}



int main()
{
	int brojtekstova = 0;
	do
	{
		cout << "unesi broj tekstova" << endl;
		cin >> brojtekstova;
		cin.ignore();
	} while (brojtekstova < 1);

	char** tekstovi = new char* [brojtekstova];
	for (int i = 0; i < brojtekstova; i++)
	{
		char temp[200]{};
		cout << "unesi tekst na lokaciji " <<i<< endl;
		cin.getline(temp, size(temp));
		int vel = strlen(temp) + 1;
		tekstovi[i] = new char[vel];
		strcpy_s(tekstovi[i], vel, temp);
	}

	for (int i = 0; i < brojtekstova; i++)
	{
		cout << "tekst: " << tekstovi[i] << endl;
	}

	cout << endl;

	char rijec[50]{};
	do
	{
		cout << "unesi rijec za pretragu" << endl;
		cin.getline(rijec, size(rijec));
	} while (!isSingleword(rijec));

	cout << "pronadjenih rijeci u tekstovima ima " << count(tekstovi, brojtekstova, rijec) << endl;

	for (int i = 0; i < brojtekstova; i++)
	{
		delete[]tekstovi[i]; tekstovi[i] = nullptr;
	}
	delete[]tekstovi;
	tekstovi = nullptr;

}