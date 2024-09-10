#include <iostream>
using namespace std;

const int red = 4;
const int kolona = 4;

bool crno(int i, int j)
{
	if ((i + j) % 2 != 0)
		return true;
	return false;
}

int brojaccifri(int broj)
{
	int brojac = 0;
	int cifra;
	while (broj)
	{
		cifra = broj % 10;
		brojac++;
		broj /= 10;
	}
	return brojac;
}

bool diagonal(int matrica[][kolona], int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (matrica[i][j] != matrica[j][i])
				return false;
		}
	}

	return true;

}

int indeksreda(int matrica[][kolona], int redovi, int kolona)
{
	int indeks = 0;
	int pomocni[red]{};

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			pomocni[i] += matrica[i][j];
		}
		pomocni[i] /= kolona;
		if (pomocni[i] > pomocni[indeks])
			indeks = i;
	     
	
	
	}
	cout << "najveci prosjek je " << pomocni[indeks] << endl;
	return indeks;

}

int indekskolona(int matrica[][kolona], int redovi, int kols)
{

	int indeks = 0;
	int prosjek[kolona]{};

	for (int j = 0; j < kolona; j++)
	{
		for (int i = 0; i < red; i++)
		{
			prosjek[j] += matrica[i][j];
		}
		prosjek[j] /= red;
	    
		if (prosjek[j] < prosjek[indeks])
			indeks = j;
          	
	
	}
	cout << "najmanji prosjek je " << prosjek[indeks] << endl;
	return indeks;




}

void unos(int matrica[][kolona], int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (crno(i, j))
			{
				int unos;
				do
				{
					cout << "unesi parni broj sa neparnim brojem ciafara(crno polje" << endl;
					cin >> unos;
				} while (unos%2!=0||brojaccifri(unos)%2==0);

				matrica[i][j] = unos;
			}
			else
			{
				int unos;
				do
				{
					cout << "unesi neparan broj sa parnim brojem ciafara(bijelo polje)" << endl;
					cin >> unos;
				} while (unos%2==0||brojaccifri(unos)%2 !=0);

				matrica[i][j] = unos;

			}
		}
	}
}

void ispis(int matrica[][kolona], int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}
}





int main()
{
	int matrica[red][kolona];
	unos(matrica, red, kolona);
	ispis(matrica, red, kolona);

	if (diagonal(matrica, red, kolona))
	{
		cout << "niz je simetrican po glavnoj" << endl;
		cout << "najveci indeks sa najvecim prosujekom je" << indeksreda(matrica, red, kolona) << endl;

	}
	else
	{
		cout << "niz nije simetrican po glavnoj" << endl;
		cout << "najveci indeks sa najvecim prosujekom je" << indekskolona(matrica, red, kolona) << endl;
	}
	return 0;
}