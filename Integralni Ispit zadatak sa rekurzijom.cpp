#include <iostream>
using namespace std;
#include <iomanip>

void napuni(int* niz, int vel, int i = 0)
{
	if (i == vel)
		return;
	cout << "unesi element na lokaciju" << i << endl;
	cin >> niz[i];
	napuni(niz, vel, i + 1);
}

void ispis(int* niz, int vel, int i = 0)
{
	if (i == vel)
		return;
	cout << niz[i]<<" ";
	ispis(niz, vel, i + 1);
}

void slican(int* niz, int vel, int target, int& najblizi, int i = 0)
{
	if (i == vel)
		return ;
	if (abs(target - *(niz + i)) < target - najblizi)
		najblizi = *(niz + i);
	slican(niz, vel, target, najblizi, i + 1);
}

int main()
{
	int vel,target;
	do
	{
		cout << "unesi velicinu niza" << endl;
		cin >> vel;
	} while (vel<1);

	int* niz = new int[vel];

	napuni(niz, vel);
	
	cout<<"Clanovi niza: ";
	ispis(niz, vel);
	cout << endl;
	cout << "unesi target za pronalazak" << endl;
	cin >> target;
	int najblizi = *(niz + 0);

	slican(niz, vel, target, najblizi);
	cout << "najblizi je " << najblizi << endl;


	delete[]niz;
	niz = nullptr;


}