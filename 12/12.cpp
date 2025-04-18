#include <iostream>
using namespace std;

// Размер симулированной памяти
const int MAX_MEM = 100;

// Массивы, представляющие память
float fmemory[MAX_MEM]; // "Память" для float
int pmemory[MAX_MEM];   // "Память" для указателей

// Указатели на вершины памяти
int fmem_top = 0;
int pmem_top = 0;

// Класс, представляющий переменные типа float в памяти
class Float {
private:
    int addr; // адрес в fmemory

public:
    Float(float val) {
        addr = fmem_top++;
        fmemory[addr] = val;
    }

    int getAddr() const { return addr; }

    // Перегрузка оператора &
    friend int operator&(const Float& f) {
        return f.addr;
    }
};

// Класс, представляющий указатель на float
class ptrFloat {
private:
    int addr; // адрес в pmemory (индекс "указателя")

public:
    ptrFloat(int p) {
        addr = pmem_top++;
        pmemory[addr] = p;
    }

    // Перегрузка операции разыменования
    float& operator*() {
        return fmemory[pmemory[addr]];
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Float var1 = 1.234f;
    Float var2 = 5.678f;

    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    *ptr1 = 7.123f;
    *ptr2 = 8.456f;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    return 0;
}
