#pragma once
#include "List.h"
#include "Passenger_carrier.h"
#include "Airplane.h"
#include "Train.h"
#include "Car.h"
using namespace std;

template <typename T>
List<T>::List() 
{
	size = 0;
	last = nullptr;
	first = nullptr;
}

template <typename T>
List<T>::List(const List& other)
{
    List_Node<T>* temp = other.first;
    while (temp != nullptr)
    {
        push_back(temp->data);
        temp = temp->next;
    }
}

template <typename T>
List<T>::~List()
{
    clear_list();
}

template <typename T>
List<T>& List<T>::operator=(const List& other)
{
    if (this != &other) 
    {
        clear_list();
        List_Node<T>* temp = other.first;
        while (temp != nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

template<typename T>
void List<T>::clear_list()
{
    List_Node<T>* current = first;
    while (current != nullptr)
    {
        List_Node<T>* next = current->next;
        delete current;
        current = next;
    }
    first = last = nullptr;
    size = 0;
}

template<typename T>
void List<T>::push_back(T value)
{
    List_Node<T>* new_node = new List_Node<T>(value);

    if (first == nullptr)
    {
        first = last = new_node;
    }
    else
    {
        last->next=new_node;
        new_node->prev=last;
        last = new_node;
    }
    size++;
}

template<typename T>
void List<T>::push_front(T value)
{
    List_Node<T>* new_node = new List_Node<T>(value);

    if (first == nullptr)
    {
        first = last = new_node;
    }
    else
    {
        first->prev = new_node;
        new_node->next = first;
        first = new_node;
    }
    size++;
}

template<typename T>
void List<T>::delete_back()
{
    if (last == nullptr)
    {
        cout << "лист пуст" << endl;
        return;
    }
    List_Node<T>* temp = last;
    last = last->prev;
    if (last != nullptr)
    {
        last->next = nullptr;
    }
    else {
        first = nullptr;
    }
    delete temp;
    size--;
}

template<typename T>
void List<T>::delete_front()
{
    if (first == nullptr) 
    {
        cout << "лист пуст" << endl;
        return;
    }
    List_Node<T>* temp = first;
    first = first->next;
    if (first != nullptr)
    {
        first->prev = nullptr;
    }
    else
        last = nullptr;
    delete temp;
    size--;
}

template<typename T>
int List<T>::getSize() 
{
    return size;
}

template<typename T>
bool List<T>::empty()
{
    return size == 0;
}

template<typename T>
void List<T>::sort_distance()
{
    if (empty())
    {
        cout << "Лист пуст." << endl;
        return;
    }
    if (size <= 1) return;
    bool found;
    do {
        found = false;
        List_Node<T>* current = first;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->data.GetDistance() > current->next->data.GetDistance())
            {
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                found = true;
            }
            current = current->next;
        }
    } while (found);
}

template<typename T>
void List<T>::sort_speed()
{
    if (empty())
    {
        cout << "Лист пуст." << endl;
        return;
    }
    if (size <= 1) return;

    bool found;
    do {
        found = false;
        List_Node<T>* current = first;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->data.GetSpeed() > current->next->data.GetSpeed())
            {
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                found = true;
            }
            current = current->next;
        }
    } while (found);
}

template<typename T>
List<T> List<T>::search_list(int param, double value) 
{
    List<T> resultList;  
    if (this->empty())
    {
        cout << "Список пуст!" << endl;
        return resultList;
    }
    bool isFound = false;
    List_Node<T>* current = first;


    while (current != nullptr)
    {
        if (param == 1)
        {
            if (current->data.GetDistance() == value)
            {
                resultList.push_back(current->data);
                isFound = true;
            }

        }
        else if (param == 2)
        {
            if (current->data.GetMoney_km() == value)
            {
                resultList.push_back(current->data);
                isFound = true;
            }
        }
        else if (param == 3)
        {
            if (current->data.GetSpeed() == value)
            {
                resultList.push_back(current->data);
                isFound = true;
            }
        }

        current = current->next;
    }
    if (!isFound)
    {
        cout<< "\nОбъекты не найдены"<< endl;
    }
    return resultList;
}

template<typename T>
T& List<T>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Индекс вне диапазона");
    }

    List_Node<T>* current = first;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void List<T>::see_list()
{
    if (empty())
    {
        cout << "\nСписок пустой!" << endl;
        return;
    }
    else {
        List_Node<T>* buffer = first;
        cout << endl;
        if (first != nullptr)
        {
            first->data.print_header();
        }
        while (buffer != nullptr)
        {
            cout << buffer->data << endl;
            buffer = buffer->next;
        }
    }
}

