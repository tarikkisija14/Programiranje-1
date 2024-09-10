#include <iostream>
using namespace std;
#include <iomanip>

/*.

Napisati program koji će omogućiti korisniku unos broja n 
(uz uslov 10 <= n <= 1000). Zatim simulirati unos 
n slučajnih vrijednosti. Simuliranje unosa ostvariti 
funkcijom rand()% 1000 + 1. Izračunati statitičke 
podatke u kojem procentu se od n generisanih slučajnih 
vrijednosti pojavljuje savršen broj . Za neki broj se 
kaze da je savrsen ako je jednak sumi svih svojih djelilaca
(ne uključujući njega samog) . Npr. 28 je savršen broj : 
njegovi djelioci su 1 , 2 , 4 , 7 i 14 , 
a 1 + 2 + 4 + 7 + 14 = 28 Jedini savršeni brojevi 
od 1 do 100 su brojevi 6 i 28


*/
bool savrsen(int broj)
{
	int suma = 0;
	for (int i = 1; i < broj; i++)
	{
		if (broj % i == 0)
			suma += i;
	}
	if (suma == broj)
		return true;
	return false;
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
		if (savrsen(varijabla))
			brojac++;
	}

	cout << "u n generisanih brojeva pojavi se" << float(brojac / n * 100) << " %" << endl;

	return 0;
}
