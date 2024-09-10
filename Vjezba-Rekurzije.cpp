
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void napuni(int* niz, int vel, int i = 0)
{
	if (i == vel)
		return;
	cout << "unsi na "<<i << " ";
	cin >> niz[i];
	napuni(niz, vel, i + 1);
}
void ispis(int* niz, int vel, int i = 0)
{
	if (i == vel)
		return;
	cout << niz[i]<< " ";
		ispis(niz, vel, i + 1);
}

void slican(int* niz, int vel, int target, int& najblizi,int i=0)
{
	if (i == vel)
		return;
	if (abs(target - niz[i]) < abs(target - najblizi))
		najblizi = niz[i];
	slican(niz, vel, target, najblizi, i + 1);


}

int razlika(int* niz, int vel, int target, int najmanja, int i = 0)
{
	if (i == vel)
		return najmanja;

	int trenutna = abs(target - niz[i]);
	if (trenutna < najmanja)
		najmanja=trenutna;

	return razlika(niz, vel,target, najmanja, i + 1);

}



int main()
{
	int vel = 5;
	int* niz = new int[vel];
	napuni(niz, vel);
	ispis(niz, vel);
	int target = 15;
	int najblizi = niz[0];
	slican(niz, vel, target, najblizi);
	cout << endl;
	cout << "najblizi je" << najblizi << endl;

	int najmanja = abs(target - niz[0]);
	najmanja =razlika(niz, vel, target, najmanja);

	cout << "najmanja razlika je" << najmanja << endl;


	return 0;
}