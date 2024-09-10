void EnterArray(int* parray, int max, int i=0)
{
	if (i == max)
		return;
	if (i == 0)
		*(parray + i) = 1;
	else if (i == 1)
		*(parray + i) = 3;
	else
    {
		if (*(parray + i - 1) * *(parray + i - 2) < 0)
			return;
		else
			*(parray + i) = *(parray + i - 1) * *(parray + i - 2);
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
int sumArray(int* parray, int max, int i=0)
{
	if (i == max)
		return 0;
	return parray[i] + sumArray(parray, max, i + 1);
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
	cout << "suma elemenata niza je " << sumArray(parray, vel) << endl;
	cout << endl;
	

	
	
	
	delete[]parray;
	parray = nullptr;
	return 0;

}
