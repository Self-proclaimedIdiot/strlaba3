﻿// strlaba3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
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
        current = beginning;
        for (int i = 0; i < index; i++) {
            ++(*this);
        }
        return current;
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
        if (index <= count) {
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
                end = index == count ? elem : end;
            }
            count++;
        }
    }
    int FirstEnter(T value) {
        current = beginning;
        for (int i = 0; i < count; i++) {
            if (current->data == value)
                return i;
            ++(*this);
        }
    }
    void Delete(int position) {
        Element<T>* delElem;
        if (position == 0) {
             delElem = beginning;
            beginning = beginning->next;
        }
        else {
            delElem = Move(position);
            Element<T>* PrevElem = Move(position - 1);
            Element<T>* NextElem = Move(position + 1);
            PrevElem->next = NextElem;
            end = position == count - 1 ? PrevElem : end;
        }
        delete delElem;
        count--;
    }
    void Delete(T value) {
        int position = FirstEnter(value);
        Element<T>* delElem;
        if (position == 0) {
            delElem = beginning;
            beginning = beginning->next;
        }
        else {
            delElem = Move(position);
            Element<T>* PrevElem = Move(position - 1);
            Element<T>* NextElem = Move(position + 1);
            PrevElem->next = NextElem;
            end = position == count - 1 ? PrevElem : end;
        }
        delete delElem;
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
    void Switch(int index1, int index2) {
        T switcher = GetValue(index1);
        Move(index1)->data = GetValue(index2);
        Move(index2)->data = switcher;
    }
    void BubbleSort() {
        for (int j = 1; j < count; j++) {
            for (int i = 0; i < count - j; i++) {
                if (GetValue(i) > GetValue(i + 1))
                    Switch(i, i + 1);
            }
        }
    }
    T GetValue(int index) {return Move(index)->data;}
    Element<T>* Front() { return beginning; }
    Element<T>* Back() { return end; }
    bool Empty() { return beginning == nullptr || end == nullptr;}
    int Size() { return count; }
};
void do_magic(MyList<char>& s) {
    while (s.Front()->data == ' ') {
        s.Delete(' ');
    }
    while (s.Back()->data == ' ') {
        s.Delete(s.Size() - 1);
    }
}
int main()
{
    MyList<char> somelist;
    /*char c = ' ';
    char* s = &c;
    scanf("%s", s);*/
    somelist.Scanner("babbcd");
    somelist.BubbleSort();
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
