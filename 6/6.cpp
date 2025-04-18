#include <iostream>
using namespace std;

int strcmp1(char* s1, char* s2) {
    while (*s1 && *s2) {
        if (*s1 < *s2) return -1;
        if (*s1 > *s2) return 1;
        s1++;
        s2++;
    }

    if (*s1 == '\0' && *s2 == '\0') return 0;
    if (*s1 == '\0') return -1;
    return 1;
}

int main() {
    setlocale(LC_ALL, "Rus");
    char a[100], b[100];

    cout << "Введите первую строку: ";
    cin >> a;
    cout << "Введите вторую строку: ";
    cin >> b;

    cout << strcmp1(a, b) << endl;

    return 0;
}