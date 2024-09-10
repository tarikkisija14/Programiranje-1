#include <iostream>
using namespace std;



char* createtextfrom(const char* izvor)
{
	if (izvor == nullptr)
		return nullptr;
	int size = strlen(izvor) + 1;
	char* tekst = new char[size];
	strcpy_s(tekst, size, izvor);
	return tekst;

}

struct Book
{
	char* imeKnjige;
	char* imeAutora;
	int brojOcjena; // velicina niza ocjena
	int* ocjena; // niz ocjena
	void unos()
	{
		cin.ignore();
		char temp[250]{};
		cout << "unesi ime knjige" << endl;
		cin.getline(temp, size(temp));
		imeKnjige = createtextfrom(temp);

		cout << "unesi ime autora" << endl;
		cin.getline(temp, size(temp));
		imeAutora = createtextfrom(temp);

		do
		{
			cout << "unesi broj ocjena" << endl;
			cin >> brojOcjena;
			cin.ignore();
		} while (brojOcjena < 1);

		ocjena = new int[brojOcjena];
		for (int i = 0; i < brojOcjena; i++)
		{
			cout << "unesite ocjene na" << i << endl;
			cin >> ocjena[i];
		}

	}

	float getaverages()
	{
		float suma = 0.0f;
		float brojac = 0.0f;
		float prosjek = 0.0f;
		for (int i = 0; i < brojOcjena; i++)
		{
			suma += ocjena[i];
			brojac++;

		}
		prosjek = suma / brojac;


		return prosjek;
	}
	void ispis()
	{
		cout << "ime knjige: " << imeKnjige << endl;
		cout << "ime autora: " << imeAutora << endl;
		cout << "broj ocjena: " << brojOcjena << endl;
		cout << "ocjene: ";
		for (int i = 0; i < brojOcjena; i++)
		{
			cout << ocjena[i] << " ";

		}
		cout << endl;
		cout << "prosjek ocjena je " << getaverages() << endl;

		cout << endl;
		cout << "-----------------------------------" << endl;

	}


	void dealokacija()
	{
		delete[]imeKnjige;
		delete[]imeAutora;
		imeKnjige = imeAutora = nullptr;
		delete[]ocjena;
		ocjena = nullptr;
	}
};

int main()
{
	int brojunosa;
	do
	{
		cout << "unesi broj unosa pisaca" << endl;
		cin >> brojunosa;
	} while (brojunosa<1);

	Book* niz = new Book[brojunosa];
	float* prosjeci = new float[brojunosa] {};
	for (int i = 0; i < brojunosa; i++)
	{
		niz[i].unos();
		prosjeci[i] = niz[i].getaverages();
	}
	int indeks = 0;
	for (int i = 0; i < brojunosa; i++)
	{
		niz[i].ispis();
		if (prosjeci[i] < prosjeci[indeks])
			indeks = i;

		cout << "najveci prosjek ocjena ima " << indeks << endl;
	}



	for (int i = 0; i < brojunosa; i++)
	{
		niz[i].dealokacija();
	}

}