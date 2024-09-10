#include <iostream>
using namespace std;
#include <iomanip>

/*..Napišite program koji omogućuje unos jednodimenzionalnog niza 
cjelobrojnih vrijednosti preko niza pokazivača (int*[]). Uraditi 
neophodne alokacije za svaki pokazivač u nizu a zatim obavezno
implementirati sljedeće funkcije: 






*/

void EnterArray(int** parray, int max, int i=0)
{
	if (i == max)
		return;
	cout << "unesi elemente niza" << endl;
	cin >> *parray[i];
	EnterArray(parray, max, i + 1);
}
void printArray(int** parray, int max, int i=0)
{
	if (i == max)
		return;
	cout  << *parray[i] << " ";
	printArray(parray, max, i + 1);
}
int sumArray(int** parray, int max, int i=0)
{
	if (i == max)
		return 0;
	return *parray[i] + sumArray(parray, max, i + 1);
}
int findElement(int** parray, int max, int target, int i = 0)
{
	if (i == max)
		return -1;
	if (*parray[i] == target)
		return i;
	return findElement(parray, max, target, i + 1);
}
int main()
{
	int vel = 0;
	cout << "unesi velicinu niza" << endl;
	cin >> vel;

	int** parray = new int* [vel];
	for (int i = 0; i < vel; i++)
	{
		parray[i] = new int; 
	}

	EnterArray(parray, vel);
	cout << "elementi niza:";
	printArray(parray, vel);
	cout << endl;
	cout << "suma elemenata niza je" << sumArray(parray, vel) << endl;
	cout << endl;
	int target = 0;
	cout << "unesi target za pretrazivanje niza" << endl;
	cin >> target;

	if (findElement(parray, vel, target) != -1)
		cout << "element je pronadjen na indeksu " << findElement(parray, vel, target) << endl;
	
	for (int i = 0; i < vel; i++)
	{
		delete[]parray[i];
		parray[i] = nullptr;
	}
	delete[]parray;
	parray = nullptr;
	return 0;

}
