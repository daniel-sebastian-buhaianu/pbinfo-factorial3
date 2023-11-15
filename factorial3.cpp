// scor 100
#include <fstream>
#define MAX_N 100001
using namespace std;
int exponent[MAX_N];
void descompuneInFactoriPrimi(int);
int main()
{
	int n, i, suma;
	ifstream fin("factorial3.in");
	fin >> n;
	fin.close();
	for (i = 2; i <= n; i++)
		descompuneInFactoriPrimi(i);
	for (suma = 0, i = 2; i <= n; i++)
		suma += exponent[i];
	ofstream fout("factorial3.out");
	fout << suma;
	fout.close();
	return 0;
}
void descompuneInFactoriPrimi(int nr)
{
	for (int d = 2; d*d <= nr; d++)
	{
		int p;
		for (p = 0; nr % d == 0; nr /= d, p++);
		exponent[d] += p;
	}
	if (nr > 1)
		exponent[nr] += 1;
}
