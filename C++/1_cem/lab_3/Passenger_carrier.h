#pragma once
#pragma once
#include <iostream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <limits>

class Passenger_carrier
{
private:
    std::string name;   // Название транспорта 
    double distance;    // Расстояние перевозки в км
    double money_km;    // Стоимость за километр в рублях
    double speed;       // Скорость транспорта в км/ч

public:
    Passenger_carrier();                                                                                           // Конструктор по умолчанию
    Passenger_carrier(const std::string& Name, const double Distance, const double Money_km, const double Speed);  // Конструктор с параметрами
    Passenger_carrier(const Passenger_carrier& other);                                                             // Конструктор копирования
    ~Passenger_carrier();                                                                                          // Виртуальный деструктор для корректного удаления объектов наследников

    virtual void menu();
    virtual double time_in_path(); // Расчет времени в пути
    virtual double cost_path();    // Расчет стоимости поездки

    std::string GetName();    // Получить название
    double GetDistance();     // Получить расстояние
    double GetMoney_km();     // Получить стоимость за км
    double GetSpeed();        // Получить скорость

    void SetName(const std::string Name);  // Установить название
    void SetDistance(double Distance);     // Установить расстояние
    void SetMoney_km(double Money_km);     // Установить стоимость за км
    void SetSpeed(double Speed);           // Установить скорость

    friend std::istream& operator>>(std::istream& is, Passenger_carrier& ob);  // Оператор ввода
    friend std::ostream& operator<<(std::ostream& os, Passenger_carrier& ob);  // Оператор вывода
    Passenger_carrier& operator=(const Passenger_carrier& other);              // Оператор присваивания

    virtual void print_header() const;
    virtual void print_table() const;
};