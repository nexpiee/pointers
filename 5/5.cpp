#include <iostream>
using namespace std;

void addarrays(int *a,int *b,int *c, int n) {
	for (int i = 0;i < n;i++) {
		c[i] = a[i] + b[i];
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Размерность:" << endl;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int* c = new int[n];
	for (int i = 0;i < n;i++) {
		a[i] = i + 1;
		b[i] = i + 1;
	}

	addarrays(a,b,c,n);


	for (int i = 0;i < n;i++) {
		cout << "c[" << i << "]=" << c[i] << endl;
	}
}
