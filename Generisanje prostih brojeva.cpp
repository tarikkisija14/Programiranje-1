#include <iostream>
using namespace std;
#include <iomanip>

/*.

Napisati program koji će omogućiti korisniku unos broja n
(uz uslov 10 <= n <= 1000). Zatim simulirati unos n slučajnih 
vrijednosti. Simuliranje unosa ostvariti funkcijom rand() % 1000 + 1
Izračunati statističke podatke u kojem procentu se od n 
generisanih slučajnih vrijednosti pojavljuje prost broj.
Npr. Ako je generisano 10 brojeva (n = 10): 5,7,4,13,17,20,25,23,30,45, 
u ovom uzorku od 10 brojeva postoji 5 prostih brojeva 
pa je procenat prostih brojeva u ovom slučaju 50%.


*/
bool prost(int broj)
{
	if (broj <= 1)
		return false;
	for (int i = 2; i < broj/2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}





int main()
{
	int n; float brojac = 0;
	float prosjek = 0.0f;
	do
	{
		cout << "unesi n" << endl;
		cin >> n;
	} while (n<10||n>1000);

	for (int i = 0; i <=n ; i++)
	{
		int varijabla = rand() % 1000 + 1;
		if (prost(varijabla))
			brojac++;
	}

	cout << "u n generisanih brojeva pojavi se" << float(brojac / n * 100) << " %" << endl;

	return 0;
}
