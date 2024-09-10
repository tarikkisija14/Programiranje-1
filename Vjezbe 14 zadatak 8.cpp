#include <iostream>
using namespace std;
#include <iomanip>


/* . 
Uraditi implementaciju zadanih funkcija članica i po potrebi 
definirati i implementirati pomoćne globalne funkcije. Zatim, 
u main funkciji dodati sljedeće stavke:
•	Kreiranje objekta tipa Glumac
•	Poziv funkcije članice unos (funkcije koja radi 
alokaciju i konzolni unos)
•	Poziv funkcije članice ispis
•	Dohvaćenje niza prosječnih ocjena glumca za svakog
korisnika (koristiti dinamičku memoriju)
•	Poziv funkcije za dealokaciju objekta
•	Dealokacija niza prosječnih ocjena.


*/

struct Glumac {
	char* ime = nullptr;
	char* prezime = nullptr;
	char drzava[40] = "";
	int brojFilmova = 0; // označava broj redova u dinamičkoj matrici 
	int brojKorisnika = 0; // označava broj kolonu u dinamičkoj matrici 
	int** ocjene = nullptr; // matrica dimenzija (brojFilmova × brojKorisnika) 
	void unos()
	{
		char temp[250]{};
		cout << "unesi ime" << endl;
		cin.getline(temp, size(temp));
		int vel = strlen(temp) + 1;
		ime = new char[vel];
		strcpy_s(ime, vel, temp);

		cout << "unesi prezime" << endl;
		cin.getline(temp, size((temp)));
		int vel2 = strlen(temp) + 1;
		prezime = new char[vel2];
		strcpy_s(prezime, vel2, temp);

		cout << "unesi drzavu" << endl;
		cin.getline(drzava, size(drzava));

		do
		{
			cout << "unesi broj filmova" << endl;
			cin >> brojFilmova;
		} while (brojFilmova<1);

		do
		{
			cout << "unesi broj korisnika" << endl;
			cin >> brojKorisnika;
		} while (brojKorisnika<1);

		ocjene = new int* [brojFilmova];
		for (int i = 0; i < brojFilmova; i++)
		{
			ocjene[i] = new int[brojKorisnika];
		}
		
		cout << "unesi elemente u matricu" << endl;
		for (int i = 0; i < brojFilmova; i++)
		{
			for (int j = 0; j < brojKorisnika; j++)
			{
				cin >> ocjene[i][j];
			}
		}
		


	}
	float* getAveragesByUsers()
	{
		float* pomocni = new float[brojKorisnika] {};
		for (int j = 0; j < brojKorisnika; j++)
		{
			for (int i = 0; i < brojFilmova; i++)
			{
				pomocni[j] += ocjene[i][j];
			}
			pomocni[j] /= brojFilmova;
		}

		return pomocni;

	}
	void ispis()
	{
		cout << "ime i prezime" << ime << " " << prezime << endl;
		cout << "drzava: " << drzava << endl;
		cout << "broj filmova: "<< brojFilmova << endl;
		cout << "broj korisnika: " << brojKorisnika << endl;
		for (int i = 0; i < brojFilmova; i++)
		{
			for (int j = 0; j < brojKorisnika; j++)
			{
				cout << setw(3) << ocjene[i][j];;
				
			}
			cout << endl;
		}
    }
	void dealokacije()
	{
		delete[]ime;
		delete[]prezime;
		ime = prezime = nullptr;
		for (int i = 0; i < brojFilmova; i++)
		{
			delete[]ocjene[i];
			ocjene[i] = nullptr;

		}
		delete[]ocjene;
		ocjene = nullptr;
    }
};






int main()
{
	Glumac g;
	g.unos();
	g.ispis();

	float* docek = g.getAveragesByUsers();
	for (int i = 0; i < g.brojKorisnika; i++)
	{
		cout <<setw(3)<< docek[i]<<" ";
	}
	g.dealokacije();
	delete[]docek;
	docek = nullptr;

	return  0;
}