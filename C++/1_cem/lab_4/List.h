#pragma once
#pragma once
#include <iostream>
#include <string>

template <typename T>
class List_Node
{
public:
    T data;
    List_Node<T>* prev;
    List_Node<T>* next;
    List_Node(const T& dat) :data(dat), prev(nullptr), next(nullptr) {}
};

template <typename T>
class List
{
private:
    List_Node<T>* first;
    List_Node<T>* last;
    int size;
public:
    List();
    List(const List& other);
    ~List();

    List& operator=(const List& other);

    void clear_list();                          //очистить лист
    void push_back(T value);                    //добавить элемент в конец списка
    void push_front(T value);                   //добавить элемент в начало списка
    void delete_back();                         //удалить элемент в конце списка
    void delete_front();                        //удалить элемент в начале списка
    int getSize();                              //размер списка
    bool empty();                               //проверка на пустоту списка
    void see_list();                            //посмотреть лист

    void sort_distance();                       //сортировка по расстоянию
    void sort_speed();                          //сортировка по скорости
    List<T>search_list(int param, double value);//поиск по параметру

    T& operator[](int index);
};


