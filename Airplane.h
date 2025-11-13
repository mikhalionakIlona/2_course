#pragma once
#include "Passenger_carrier.h"

class Airplane : public Passenger_carrier
{
private:
    int collections;                           // Дополнительные сборы в аэропорту (руб)
    int passenger_capacity;                    // Вместимость пассажиров
    double cargo_capacity;                     // Грузоподъемность (кг)

public:
    Airplane();                                                                                                            // Конструктор по умолчанию
    Airplane(int Collections, int PassengerCapacity, double CargoCapacity, const std::string& Name, const double Distance, const double Money_km, const double Speed);  // Конструктор с параметрами
    Airplane(const Airplane& other);                                                                                       // Конструктор копирования
    ~Airplane();                                                                                                           // Деструктор

    virtual double time_in_path() override; // Расчет времени в пути (учитывает особенности авиаперевозок)
    virtual double cost_path() override;    // Расчет стоимости поездки (учитывает сборы)
    void menu() override;                   //меню

    int GetCollections();                   // Получить сумму сборов в аэропорту
    int GetPassengerCapacity();             // Получить вместимость пассажиров
    double GetCargoCapacity();              // Получить грузоподъемность

    void SetCollections(int Collections);               // Установить сумму сборов в аэропорту
    void SetPassengerCapacity(int PassengerCapacity);   // Установить вместимость пассажиров
    void SetCargoCapacity(double CargoCapacity);        // Установить грузоподъемность

    friend std::istream& operator>>(std::istream& is, Airplane& ob);    // Оператор ввода для самолета
    friend std::ostream& operator<<(std::ostream& os, Airplane& ob);    // Оператор вывода для самолета
    Airplane& operator=(const Airplane& other);                         // Оператор присваивания для самолета

    void print_header() const override; 
    void print_table() const override;
};