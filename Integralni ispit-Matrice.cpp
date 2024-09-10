#include <iostream>
using namespace std;
#include <iomanip>

/*Napisite program gdje korisnik unosi redove I kolone
dviju matrica pri cemu se mora ispostovati uslov prema 
kome broj redova I kolona mora biti veci od 0.Nakon sto 
se iste kreiraju potrebno je njihove elemente popuniti 
slucajnim vrijednostima iz opsega [1-15]..Zatim kreirati 
trecu matricu ciji elementi moraju biti jednaki zbiru 
prve 2 matrice.Takodjer ako matrice imaju jednak broj 
redova I kolona potrebno je prilikom ispisa u main 
funkciju provjeriti koja od njih ima vecu sumu vrijednosti 
na elementima sporedne dijagonale.*/


int getrandom(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
void setrandom(int** matrica, int red, int kolona, int from=1, int to=15)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(*(matrica + i) + j) = getrandom(from, to);
		}
	}
}
int** CreateMatrix(int red, int kolona)
{
	int** matrica = new int*[red];
	for (int i = 0; i < red; i++)
	{
		matrica[i] = new int[kolona];
	}
	return matrica;
}
void printMatrix(int** matrica, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << setw(3) << matrica[i][j];
		}
		cout << endl;
	}

}
void deleteMatrix(int** matrica, int red)
{
	for (int i = 0; i < red; i++)
	{
		delete[]matrica[i];
		matrica[i] = nullptr;
	}
	delete[]matrica;
	matrica = nullptr;
}
int** sumMatrix(int** m1, int** m2, int r1, int c1, int r2, int c2,int red,int kolona)
{
	int** m3 = CreateMatrix(red, kolona);
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			m3[i][j] = 0;
		}
	}
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			m3[i][j] += m1[i][j];
		}
	}
	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			m3[i][j] += m2[i][j];
		}
	}
	return m3;

}
int sumasporedne(int** matrica, int red, int kolona)
{
	int suma = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if ((i + j) == red - 1)
				suma += matrica[i][j];
		}
	}
	return suma;
}


int veca(int d1, int d2)
{
	if (d1 > d2)
		return 1.;
	else if (d2 > d1)
		return 2.;
	else
		return 0;

}


int main()
{
	int r1, c1, r2, c2;

	do
	{
		cout << "unesi redove prve matrice" << endl;
		cin >> r1;
		cout << "unesi kolone prve matrice" << endl;
		cin >> c1;
		cout << "unesi redove druge matrice" << endl;
		cin >> r2;
		cout << "unesi kolone druge matrice" << endl;
		cin >> c2;
	} while (r1<1||c1<0||r2<0||c2<0);

	int** m1 = CreateMatrix(r1, c1);
	int** m2 = CreateMatrix(r2, c2);

	setrandom(m1, r1, c1);
	setrandom(m2, r2, c2);

	cout << "matrica 1: " << endl;
	printMatrix(m1, r1, c1);
	cout << endl;
	cout << "matrica 2:" << endl;
	printMatrix(m2, r2, c2);
	cout << endl;

	int red = 0;
	int kolona = 0;
	if (r1 > r2)
		red = r1;
	else
		red = r2;
	if (c1 > c2)
		kolona = c1;
	else
		kolona = c2;

	int** m3 = sumMatrix(m1, m2, r1, c1, r2, c2, red, kolona);

	cout << "matrica 3 dobivenja sabiranjem: " << endl;
	printMatrix(m3, red, kolona);

	int d1 = sumasporedne(m1, r1, c1);
	int d2 = sumasporedne(m2, r2, c2);
	
	
	if (r1 == r2 && c1 == c2)
	{
		if (veca(d1, d2) != 0)
		{
			cout << "veca dijagonala je " << veca(d1, d2) <<"."<< endl;

		}


	}

	deleteMatrix(m1, r1);
	deleteMatrix(m2, r2);
	deleteMatrix(m3, red);


	return 0;
}
