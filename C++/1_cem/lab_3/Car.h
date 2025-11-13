#pragma once
#include "Passenger_carrier.h"

class Car : public Passenger_carrier
{
private:
    double price_fuel;  // Цена за топливо (руб)
    int year_production;    // Год выпуска автомобиля
    std::string car_type;   // Тип автомобиля (седан, внедорожник и т.д.)

public:
    Car();                                                                                                              // Конструктор по умолчанию
    Car(double Price_fuel, const std::string& Name, const double Distance, const double Money_km, const double Speed);  // Конструктор с параметрами (наследует параметры базового класса + свои)
    Car(const Car& other);                                                                                              // Конструктор копирования
    ~Car();                                                                                                             // Деструктор

    virtual double time_in_path() override; // Расчет времени в пути
    virtual double cost_path() override;    // Расчет стоимости поездки (учитывает стоимость топлива)
    virtual void menu() override;

    double GetPrice_fuel();  // Получить цену за топливо
    int GetYear_production();           // Получить год выпуска
    std::string GetCar_type();          // Получить тип автомобиля

    void SetPrice_fuel(double Price_fuel);  // Установить цену за топливо
    void SetYear_production(int Year_production);       // Установить год выпуска
    void SetCar_type(const std::string& Car_type);      // Установить тип автомобиля

    friend std::istream& operator>>(std::istream& is, Car& ob);     // Оператор ввода для автомобиля
    friend std::ostream& operator<<(std::ostream& os, Car& ob);     // Оператор вывода для автомобиля
    Car& operator=(const Car& other);                               // Оператор присваивания для автомобиля

    void print_header() const override;
    void print_table() const override;
};