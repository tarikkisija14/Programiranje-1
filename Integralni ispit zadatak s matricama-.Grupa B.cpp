#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int getrandom(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
void setrandom(int** matrica, int red, int kolona, int from = 1, int to = 10)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			matrica[i][j] = getrandom(from, to);
		}
	}
}
int** create(int red, int kolona)
{
	int** m = new int* [red];
	for (int i = 0; i < red; i++)
	{
		m[i] = new int[kolona];
	}
	return m;
}
void print(int** matrica, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << setw(3) << matrica[i][j];
		}
		cout << endl;
	}
}

void delo(int** matrica, int red)
{
	for (int i = 0; i < red; i++)
	{
		delete[]matrica[i];
	}
	delete[]matrica;
	matrica = nullptr;
}

int** maxMatrica(int** m1, int** m2, int r1, int c1, int r2, int c2)
{
	int red = max(r1, r2);
	int kolona = max(c1, c2);
	
	int** m3 = create(red, kolona);

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (i < r1 && j < c1 && i < r2 && j < c2)
			{
				m3[i][j] = max(m1[i][j], m2[i][j]);

		    }
			else if (i < r1 && j < c1)
			{
				m3[i][j] = m1[i][j];
			}
			else if (i < r2 && j < c2)
			{
				m3[i][j] = m2[i][j];
			}

		
		
		}
	}

	return m3;



}
int main()
{
	srand(time(0));
	int r1, c1, r2, c2;
	do
	{
		cout << "unesi red1" << endl;
		cin >> r1;
		cout << "unesi kolonu1" << endl;
		cin >> c1;
		cout << "unesi red2" << endl;
		cin >> r2;
		cout << "unesi kolonu2" << endl;
		cin >> c2;
	} while (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0);
	int** m1 = create(r1, c1);
	int** m2 = create(r2, c2);
	setrandom(m1, r1, c1);
	setrandom(m2, r2, c2);
	cout << endl;
	cout << "matrica1: " << endl;
	print(m1, r1, c1);
	cout << endl;
	cout << "matrica2: " << endl;
	print(m2, r2, c2);
	cout << endl;

	int red = max(r1, r2);
	int kolona = max(c1, c2);
	int** m3 = maxMatrica(m1, m2, r1, c1, r2, c2);
	print(m3, red, kolona);

	delo(m1, r1);
	delo(m2, r2);
	delo(m3, red);
	return 0;

}