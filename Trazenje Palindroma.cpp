#include <iostream>
using namespace std;
#include <iomanip>

/*.
Napisati  program koji ostvaruje slijedece funkcionalnosti:
-	Omoguciti unos dvije integer vrijednosti a i b uz uvjete
a>200, b>a+100.
-	U rangu a – b pronaci sve parne brojeve i ispisati ih u 
obliku zbira dva palindroma. (Palindrom je broj koji je
jednak broju koji se dobije obrtanjem cifara tog broja. 
Npr. 14541 je palindrom jer mu je ista vrijednost i ako 
se napise u obrnutom poretku cifara, dok broj 123 nije 
palindrom jer u obrnutom poretku cifara se dobije broj 321 (123 != 321).



*/
bool palindrom(int broj)
{
	int cifra = 0;
	int obrnuti = 0;
	int kopija = broj;

	while (broj)
	{
		cifra = broj % 10;
		obrnuti = obrnuti * 10 + cifra;
		broj /= 10;

	}
	if (obrnuti != kopija)
		return false;
	return true;
}





int main()
{
	int a, b;
	do
	{
		cout << "unesi a" << endl;
		cin >> a;
		cout << "unesi b" << endl;
		cin >> b;
	} while (a<200||b<a+100);

	for (int i = a; i <=b ; i++)
	{
		if (i % 2 != 0)
			i++;
		bool zastava = false;
		for (int j = i/2,k=i/2; j < i; j++,k--)
		{
			if (palindrom(j) && palindrom(k))
			{
				cout << i << "=" << j << "+" << k << endl;
				zastava = true;
				break;

			}
		}
	
		if (!zastava)
			cout << "broj se ne moze ispisati kao zbir dva palindroma" << endl;
	
	}


	return 0;
}
