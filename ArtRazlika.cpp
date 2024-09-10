
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool jelart(int niz[])
{
	int razlika1 = niz[1] - niz[0];
	
	for (int i = 2; i < 5; i++)
	{
		int razlika2 = niz[i] - niz[i - 1];
		if (razlika1 != razlika2)
		{
			return false;
		}
		else
			razlika1 = razlika2;
	}
	return true;
}
	
using namespace std;
int main()
{
	srand(time(NULL));
	int brojac = 0;
	int niz[5];
	do {
		for (int i = 0; i < 5; i++)
		{
			niz[i] = rand() % 14 + 1;
		}
		brojac++;
	} while (!jelart(niz));
	cout << "Trebalo je " << brojac << " puta " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << niz[i] << " ";
	}
	return 0;
}