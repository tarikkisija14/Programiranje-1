bool IsFirstDigitEven(int broj)
{
	int cifra = 0;
	int kopija = broj;
	int prva = 0;
	while (broj)
	{
		cifra = broj % 10;
		broj /= 10;
		if (broj == 0)
			prva = cifra;
		

	}
	if (prva % 2 != 0)
		return false;
	return true;

}
bool isPrime(int broj)
{
	if (broj <= 1)
		return false;
	for (int i = 2; i < broj; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}

bool isSortedDesc(int broj)
{
	int prethodna = broj % 10;
	broj /= 10;
	while (broj)
	{
		int trenutna = broj % 10;
		if (prethodna > trenutna)
			trenutna = prethodna;
		else
			return false;
		broj /= 10;

	}
	return true;
}


int main()
{
	int m, n;
	int izbor;
	do
	{
		cout << "unesi numericku opciju" << endl;
		cin >> izbor;
	} while (izbor<1||izbor>3);

	switch (izbor)
	{
	 case 1:
	 {
		 do
		 {
			 cout << "unesi m" << endl;
			 cin >> m;
			 cout << "unesi n" << endl;
			 cin >> n;
		 } while (m<0 || m>n);

		 for (int i = m; i <= n; i++)
		 {
			 if (IsFirstDigitEven(i))
				 cout << i << " ";
		 }

	 }break;
      case 2 :
	 {

		 do
		 {
			 cout << "unesi n" << endl;
			 cin >> n;
		 } while (n < 2);

		 for (int i = 2; i <= n; i++)
		 {
			 if (isPrime(i) && isSortedDesc(i))
				 cout << i << " ";
		 }

	 }break;
	 case 3:
		 return 0;







	}

	return 0;
}