// список 
#include <iostream> 
using namespace std;
/////////////////////////////////////////////////////////// 
struct link   // один элемент списка 
{
    int data;   // некоторые данные 
    link* next; // указатель на следующую структуру 
};
/////////////////////////////////////////////////////////// 
class linklist // список 
{
private:
    link* first;
public:
    linklist()            // конструктор без параметров 
    {
        first = NULL;
    }     // первого элемента пока нет 
    void additem(int d); // добавление элемента 
    void display();       // показ данных 
};
/////////////////////////////////////////////////////////// 
void linklist::additem(int d) // добавление элемента в конец списка
{
    link* newlink = new link;      // выделяем память для нового элемента
    newlink->data = d;             // запоминаем данные
    newlink->next = NULL;          // новый элемент будет последним, указываем на NULL

    if (first == NULL) {           // если список пустой, новый элемент будет первым
        first = newlink;
    }
    else {
        link* current = first;     // начинаем с первого элемента
        while (current->next != NULL) { // идем до последнего элемента
            current = current->next;
        }
        current->next = newlink;    // последний элемент теперь указывает на новый
    }
}
/////////////////////////////////////////////////////////// 
void linklist::display()
{
    link* current = first;           // начинаем с первого элемента 
    while (current)                 // пока есть данные 
    {
        cout << current->data << endl; // печатаем данные 
        current = current->next;       // двигаемся к следующему элементу 
    }
}
/////////////////////////////////////////////////////////// 
int main()
{
    linklist li;       // создаем переменную-список 

    li.additem(25); // добавляем туда несколько чисел 
    li.additem(36);
    li.additem(49);
    li.additem(64);

    li.display();    // показываем список 

    return 0;
}