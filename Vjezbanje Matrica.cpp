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

int** saberi(int** m1, int** m2, int r1, int c1, int r2, int c2)
{
	int red = max(r1, r2);
	int kolona = max(c1, c2);
	int** m3 = create(red, kolona);
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			m3[i][j] = 0;
		}
	}
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			m3[i][j] += m1[i][j];
		}
	}
	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			m3[i][j] += m2[i][j];
		}
	}
	return m3;
}

int** dstack(int** m1, int** m2, int r1, int c1, int r2, int c2)
{
	int red = r1 + r2;
	int kolona = c1 + c2;
	int** m3 = create(red, kolona);
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			m3[i][j] = 0;
		}
	}
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			m3[i][j] = m1[i][j];
		}
	}
	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			m3[i+r1][j+c1] = m2[i][j];
		}
	}

	return m3;
}
int** vstack(int** m1, int** m2, int r1, int c1, int r2, int c2)
{
	int red = r1 + r2;
	int kolona = max(c1,c2);
	int** m3 = create(red, kolona);
	int brojacredova=0;
		for (int i = 0; i < red; i++)
		{
			for (int j = 0; j < kolona; j++)
			{
				m3[i][j] = 0;
			}
		}
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c1; j++)
			{
				m3[brojacredova][j] = m1[i][j];
				
			}
			brojacredova++;
		}
		for (int i = 0; i < r2; i++)
		{
			for (int j = 0; j < c2; j++)
			{
				m3[brojacredova][j] = m2[i][j];
			}
			brojacredova++;
		}

		return m3;

}
int** hstack(int** m1, int** m2, int r1, int c1, int r2, int c2)
{
	int red = max(r1, r2);
	int kolona = c1 + c2;
	int** m3 = create(red, kolona);
	int brojac = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			m3[i][j] = 0;
		}
	}
	for (int j = 0; j < c1; j++)
	{
		for (int i = 0; i < r1; i++)
		{
			m3[i][brojac] = m1[i][j];
		}
		brojac++;
	}
	for (int j = 0; j < c2; j++)
	{
		for (int i = 0; i < r2; i++)
		{
			m3[i][brojac] = m2[i][j];
		}
		brojac++;
	}
	return m3;


}
bool issimetricglavna(int** m, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (m[i][j] != m[j][i])
				return false;
		}
	}
	return true;
}
bool issimetricsporedna(int** m, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if((i+j)==red-1)
			{
				if (m[i][j] != m[j][i])
					return false; 
			}
		}
	}
	return true;
}

int zbirispodglavne(int** m, int red, int kolona)
{
	int suma = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (i >j)
			{
				suma += m[i][j];
			}
		}
	}

	return suma;
}
int zbirispodsporedne(int** m, int red, int kolona)
{
	int suma = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if ((i + j)==red-1)
			{
				suma += m[i][j];
			}
		}
	}

	return suma;
}
int zbiriznadglavne(int** m, int red, int kolona)
{
	int suma = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (i < j)
			{
				suma += m[i][j];
			}
		}
	}

	return suma;
}
int zbiriznadsporedne(int** m, int red, int kolona)
{
	int suma = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if ((i + j)<red-1)
			{
				suma += m[i][j];
			}
		}
	}

	return suma;
}

float* prosjekporedovima(int** matrica, int red, int kolona)
{
	float* prosjek = new float[red] {};
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			prosjek[i] += matrica[i][j];
		}
		prosjek[i] /= kolona;
	}
	return prosjek;
}
float* prosjekpokolonama(int** matrica, int red, int kolona)
{
	float* prosjek = new float[kolona] {};
	for (int j = 0; j < kolona; j++)
	{
		for (int i = 0; i < red; i++)
		{
			prosjek[j] += matrica[i][j];
		}
		prosjek[j] /= red;
	}
	return prosjek;
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
	} while (r1<0||c1<0||r2<0||c2<0);
	
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
	if (issimetricglavna(m1, r1, c1))
		cout << "m1 je simetricna po glavnoj dijagonali" << endl;
	else
		cout << "m1 nije simetricna po glavnoj dijaognali" << endl;
	if (issimetricsporedna(m1, r1, c1))
		cout << "m1 je simetricna po sporednoj dijagonali" << endl;
	else
		cout << "m1 nije simetricna po sporednoj dijaognali" << endl;
	cout << endl;
	if (issimetricglavna(m2, r2, c2))
		cout << "m2 je simetricna po glavnoj dijagonali" << endl;
	else
		cout << "m2 nije simetricna po glavnoj dijaognali" << endl;
	if (issimetricsporedna(m2, r2, c2))
		cout << "m2 je simetricna po sporednoj dijagonali" << endl;
	else
		cout << "m2 nije simetricna po sporednoj dijaognali" << endl;
	
	cout << endl;
	
	cout << "Zbir m1 iznad glavne  " << zbiriznadglavne(m1, r1, c1)<<endl;
	cout << "Zbir m1 ispod glavne  " << zbirispodglavne(m1, r1, c1) << endl;
	cout << "Zbir m1 iznad sporedne  " << zbiriznadsporedne(m1, r1, c1) << endl;
	cout << "Zbir m1 ispod sporedne  " << zbirispodsporedne(m1, r1, c1) << endl;
	cout << endl;
	cout << "Zbir m2 iznad glavne  " << zbiriznadglavne(m2, r2, c2) << endl;
	cout << "Zbir m2 ispod glavne  " << zbirispodglavne(m2, r2, c2) << endl;
	cout << "Zbir m2 iznad sporedne  " << zbiriznadsporedne(m2, r2, c2) << endl;
	cout << "Zbir m2 ispod sporedne  " << zbirispodsporedne(m2, r2, c2) << endl;
	cout << endl;
	float* pr1 = prosjekporedovima(m1, r1, c1);
	float* pr11 = prosjekpokolonama(m1, r1, c1);
	
	float* pr2 = prosjekporedovima(m2, r2, c2);
	float* pr22 = prosjekpokolonama(m2, r2, c2);
	cout << "prosjek po redovima m1: ";
	for (int i = 0; i < r1; i++)
	{
		cout << pr1[i] << " ";
	}
	cout << endl;
	cout << "prosjek po kolonama m1:  ";
	for (int i = 0; i < c1; i++)
	{
		cout << pr11[i] << " ";
	}
	cout << endl;
	cout << "prosjek po redovima m2: ";
	for (int i = 0; i < r1; i++)
	{
		cout << pr2[i] << " ";
	}
	cout << endl;
	cout << "prosjek po kolonama m1:  ";
	for (int i = 0; i < c1; i++)
	{
		cout << pr22[i] << " ";
	}
	cout << endl;
	cout << endl << endl << endl;
	int** m3 = saberi(m1, m2, r1, c1, r2, c2);
	int red = max(r1, r2);
	int kolona = max(c1, c2);
	cout << "treca sabiranjem je: " << endl;
	print(m3, red, kolona);
	cout << endl;
	int** m4 = dstack(m1, m2, r1, c1, r2, c2);
	int red1 = r1 + r2;
	int kolona1 = c1 + c2;
	cout << "cetvrta dstackom: " << endl;
	print(m4, red1, kolona1);
	cout << endl;
	int** m5 = vstack(m1, m2, r1, c1, r2, c2);
	int red5 = r1 + r2;
	int kolona5 = max(c1, c2);
	cout << "Peta vstackom: " << endl;
	print(m5, red5, kolona5);
	cout << endl;
	int** m6 = hstack(m1, m2, r1, c1, r2, c2);
	int red6 = max(r1, r2);
	int kolona6 = c1 + c2;
	cout << "sesta hstackom: " << endl;
	print(m6, red6, kolona6);
	cout << endl;
	





	delo(m1, r1);
	delo(m2, r2);
	delo(m3, red);
	delo(m4, red1);
	delo(m5, red5);
	delo(m6, red6);
	delete[]pr1;
	delete[]pr11;
	delete[]pr2;
	delete[]pr22;
	pr1 = pr11 = pr2 = pr22 = nullptr;
	return 0;


}