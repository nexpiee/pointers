#include <iostream>
using namespace std;

const int NUMARRAYS = 10;
const int MAXSIZE = 10;

class Array {
private:
    int* x[NUMARRAYS]; 

public:
    Array() {
        for (int i = 0; i < NUMARRAYS; ++i)
            x[i] = new int[MAXSIZE];
    }

    int& operator[](int index) {
        int a1 = index / MAXSIZE;
        int a2 = index % MAXSIZE;
        return x[a1][a2];
    }

    void fill() {
        for (int i = 0; i < 100; ++i) {
            (*this)[i] = i * 10;
        }
    }

    void print() {
        for (int i = 0; i < NUMARRAYS; ++i) {
            cout << "Массив a" << i << ": ";
            for (int j = 0; j < MAXSIZE; ++j) {
                cout << x[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Array a;
    a.fill();
    a.print();

    return 0;
}