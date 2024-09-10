#include <iostream>
using namespace std;
#include <iomanip>

/*..
Napisati program koji će omogućiti korisniku 
da unese veličinu jednodimenzionalnog dinamičkog
niza integer vrijednosti. Napisati funkciju koja će taj 
niz popuniti serijom Fibonacci brojeva počevši od broja 1. 
Za pronalazenje elemenata Fibonacci serije obavezno koristiti 
rekurzivnu funkciju. Punjenje niza se prekida kada se popuni 
cijeli niz ili kada se desi overflow na integer varijabli.
*/

void EnterArray(int* parray, int max, int i=0)
{
	if (i == max)
		return;
	if (i == 0||i==1)
		*(parray + i) = 1;
	else
    {
		if (*(parray + i - 1) + *(parray+i-2) < 0)
			return;
		else
			*(parray + i) = *(parray + i - 1) + *(parray + i - 2);
	}
	EnterArray(parray, max, i + 1);
}
void printArray(int* parray, int max, int i=0)
{
	if (i == max)
		return;
	cout  << parray[i] << " ";
	printArray(parray, max, i + 1);
}


int main()
{
	int vel = 0;
	cout << "unesi velicinu niza" << endl;
	cin >> vel;

	int* parray = new int [vel];
	

	EnterArray(parray, vel);
	cout << "elementi niza:";
	printArray(parray, vel);
	cout << endl;
	
	delete[]parray;
	parray = nullptr;
	return 0;

}
