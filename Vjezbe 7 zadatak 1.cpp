#include <iostream>
using namespace std;

bool isprime(int broj)
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
bool issorted(int broj)
{
	int prethodna = broj % 10;
	broj /= 10;
	while (broj)
	{
		int trenutna = broj % 10;
		if (trenutna < prethodna)
			prethodna = trenutna;
		else
			return false;
		broj /= 10;

	}
	return true;


}






int main()
{
	int n;
	do
	{
		cout << "unesi n" << endl;
		cin >> n;
	} while (n<2||n>1000);


	for (int i = 2; i <=n ; i++)
	{
		if (isprime(i) && issorted(i))
			cout << i << " ";
	}


	return 0;
}