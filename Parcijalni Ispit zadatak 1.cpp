#include <iostream>
using namespace std;
#include <iomanip>

/*.Napisite program u kojem korisnik unosi bazu brojnog Sistema
(vrijednost izmedju 2 I 10)nakon cega se unosi broj koji mora biti
validan unutar neke baze.Program treba prevesti broj iz zadane baze u
dekadski brojni sistem.Potrebno je navesti kako uneseni
broj ne smije biti negativan.
*/

bool isvalid(int broj, int baza)
{
	int cifra = 0;
	while (broj)
	{
		int cifra = broj % 10;
		if (cifra >= baza)
			return false;
		broj /= 10;

	}
	return true;
}

int todeceimal(int broj, int baza)
{
	int dec = 0;
	int brojac = 0;
	int cifra = 0;
	while (broj)
	{
		cifra = broj % 10;
		broj /= 10;
		dec += cifra * pow(baza, brojac);
		brojac++;


	}
	return dec;
}


int main()
{
	int baza, broj;

	do
	{
		cout << "unesi bazu brojnog sistema" << endl;
		cin >> baza;
	} while (baza < 2 || baza>9);


	do
	{
		cout << "unesi broj za pretvaranje" << endl;
		cin >> broj;
		if (!isvalid(broj, baza))
			cout << "broj nije validajn po bazi molimo unesite ponovo" << endl;
	} while (!isvalid(broj, baza));

	cout << "pretvoreni broj iznosi" << todeceimal(broj, baza) << endl;



	return 0;
}
