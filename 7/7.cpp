#include <iostream>
#include <string>
using namespace std;

class person {
protected:
    string name;
    float salary;
public:
    void setData() {
        cout << "Введите имя: ";
        cin >> name;
        cout << "Введите зарплату: ";
        cin >> salary;
    }

    void printData() {
        cout << "Имя: " << name << ", Зарплата: " << salary << endl;
    }

    string getName() {
        return name;
    }

    float getSalary() {
        return salary;
    }
};

void salsort(person** pp, int n) {
    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) {
                person* tempptr = *(pp + j);
                *(pp + j) = *(pp + k);
                *(pp + k) = tempptr;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    person* persPtr[100];
    int n = 0;
    char choice;
    do {
        persPtr[n] = new person;
        persPtr[n]->setData();
        n++;
        cout << "Продолжаем ввод? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    cout << "\nНеотсортированный список:" << endl;
    for (int j = 0; j < n; j++) {
        persPtr[j]->printData();
    }

    salsort(persPtr, n); 

    cout << "\nОтсортированный список:" << endl;
    for (int j = 0; j < n; j++) {
        persPtr[j]->printData();
    }

    return 0;
}