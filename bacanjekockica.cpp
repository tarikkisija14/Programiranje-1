int main()
{
	int brojac = 0;
	int brojac_uzastopniih = 0;
	do
	{
		int kocka1= rand() % 6 + 1;
		int kocka2= rand() % 6 + 1;
		int kocka3= rand() % 6 + 1;
		if (kocka1 == kocka2 && kocka1 == kocka3)
			brojac_uzastopniih++;
		else
			brojac_uzastopniih = 0;
		brojac++;


	} while (brojac_uzastopniih<2);
	cout << "trebalo je " << brojac << " bacanja" << endl;


	return 0;
}
