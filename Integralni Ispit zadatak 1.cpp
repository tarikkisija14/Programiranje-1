#include <iostream>
using namespace std;


int main()
{
	srand(time(0));
	int karta1 = 0;
	int karta2 = 0;
	int karta3 = 0;
	int brojac = 0;

	do
	{
		karta1 = rand() % 14 + 1;
		karta2= rand() % 14 + 1;
		karta3= rand() % 14 + 1;
		brojac++;
	} while (abs(karta3-karta2)!=5||abs(karta2-karta1)!=5);

	cout << "trebalo je" << brojac << " izvlacenja" << endl;
	cout << "zadnja kombinacija: " << karta1 << " " << karta2 << " " << karta3 << endl;
}
