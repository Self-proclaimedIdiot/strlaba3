// strlaba3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string.h>
template <class T>
struct Element {
    T data;
    Element* next;
};
template <class T>
class MyList {
    Element<T>* current = nullptr;
    Element<T>* beginning = nullptr;
    Element<T>* end = nullptr;
    int count = 0;
public:
    Element<T>* Move(int index) {
        Element<T>* ptr = beginning;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr;
    }
    void Add(T data) {
        Element<T>* elem = new Element <T>;
        elem->data = data;
        elem->next = nullptr;
        //если список пуст (как я)
        if (Empty()) {
            beginning = elem;
            end = elem;
        }
        //если че-то в нем водится
        else {
            end->next = elem;
            end = elem;
        }
        count++;
    }
    void Insert(T data, int index) {
        Element<T>* elem = new Element <T>;
        elem->data = data;
        if (index == 0) {
            elem->next = beginning;
            beginning = elem;
        }
        else {
            Element<T>* previous = Move(index - 1);
            elem->next = previous->next;
            previous->next = elem;
        }
            count++;
    }
    void Delete(int position) {
        if (position == 0) {
            Element<T>* delElem = beginning;
            beginning = beginning->next;
            delete delElem;
        }
        else {
            Element<T>* delElem = Move(position);
            Element<T>* PrevElem = Move(position - 1);
            Element<T>* NextElem = Move(position + 1);
            PrevElem->next = NextElem;
            end = position == count - 1 ? PrevElem : end;
            end->next = position == count - 1 ? PrevElem : end;
            delete delElem;
        }
        count--;
    }
    void operator++() {
        current = current->next;
    }
    void  operator--() {
        Element<T>* ptr = beginning;
        for (int i = 0; i < count; i++) {
            ptr = ptr->next;
            if (ptr->next == current) {
                current  == ptr;
                return;
            }
        }
    }
    void Printer(){
        Element<T>* ptr = beginning;
        for (int i = 0; i < count; i++) {
            printf("%c", ptr->data);
            ptr = ptr->next;
        }
    }
    void Scanner(const char* s) {
        if (Empty()) {
            for (int i = 0; s[i] != 0; i++) {
                Add(s[i]);
            }
        }
    }
    void PrinterViaCurrent() {
        current = beginning;
        for (int i = 0; i < count; i++) {
            printf("%c", current->data);
            ++(*this);
        }
    }
    Element<T>* Front() { return beginning; }
    Element<T>* Back() { return end; }
    bool Empty() { return beginning == nullptr || end == nullptr;}
    int Size() { return count; }
};

int main()
{
    MyList<char> somelist;
    somelist.Scanner("Death!");
    somelist.PrinterViaCurrent();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
