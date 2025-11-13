#pragma once
#include "Passenger_carrier.h"

class Train : public Passenger_carrier
{
private:
    double time_stops;     // Время, затраченное на остановки в пути (часы)
    int wagon_count;       // Количество вагонов
    std::string train_type; // Тип поезда

public:
    Train();                                                                                                               // Конструктор по умолчанию
    Train(double Time_stops, int Wagon_count, const std::string& Train_type, const std::string& Name, const double Distance, const double Money_km, const double Speed);   // Конструктор с параметрами
    Train(const Train& other);                                                                                             // Конструктор копирования
    ~Train();                                                                                                              // Деструктор

    virtual double time_in_path() override; // Расчет времени в пути (учитывает время остановок)
    virtual double cost_path() override;    // Расчет стоимости поездки
    virtual void menu() override;

    double GetTime_stops();      // Получить время, затраченное на остановки
    int GetWagon_count();        // Получить количество вагонов
    std::string GetTrain_type(); // Получить тип поезда

    void SetTime_stops(double Time_stops);           // Установить время, затраченное на остановки
    void SetWagon_count(int Wagon_count);            // Установить количество вагонов
    void SetTrain_type(const std::string& Train_type); // Установить тип поезда

    friend std::istream& operator>>(std::istream& is, Train& ob);   // Оператор ввода для поезда
    friend std::ostream& operator<<(std::ostream& os, Train& ob);   // Оператор вывода для поезда
    Train& operator=(const Train& other);                           // Оператор присваивания для поезда

    void print_header() const override;
    void print_table() const override;
};