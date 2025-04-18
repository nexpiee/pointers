#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL,"Rus");
    int* x[10];

    for (int i = 0; i < 10; ++i) {
        x[i] = new int[10];
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            x[i][j] = i * 10 + j * 10;
        }
    }

    cout << "Массивы:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Массив a" << i << ": ";
        for (int j = 0; j < 10; ++j) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
