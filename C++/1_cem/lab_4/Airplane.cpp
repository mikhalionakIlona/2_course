#include "Passenger_carrier.h"
#include "Airplane.h"
#include <iostream>
#include <iomanip>

Airplane::Airplane() : Passenger_carrier()
{
    collections = 0;
    passenger_capacity = 0;
    cargo_capacity = 0.0;
}

Airplane::Airplane(int Collections, int PassengerCapacity, double CargoCapacity,
    const std::string& Name, const double Distance,
    const double Money_km, const double Speed)
    : Passenger_carrier(Name, Distance, Money_km, Speed)
{
    collections = Collections;
    passenger_capacity = PassengerCapacity;
    cargo_capacity = CargoCapacity;
}

Airplane::Airplane(const Airplane& other) : Passenger_carrier(other)
{
    collections = other.collections;
    passenger_capacity = other.passenger_capacity;
    cargo_capacity = other.cargo_capacity;
}

Airplane::~Airplane()
{

}

double Airplane::time_in_path()
{
    double base_time = Passenger_carrier::time_in_path();
    return base_time + 1.5;
}

double Airplane::cost_path()
{
    double base_cost = Passenger_carrier::cost_path();
    return base_cost + collections;
}

int Airplane::GetCollections()
{
    return collections;
}

int Airplane::GetPassengerCapacity()
{
    return passenger_capacity;
}

double Airplane::GetCargoCapacity()
{
    return cargo_capacity;
}

void Airplane::SetCollections(int Collections)
{
    if (Collections > 0)
    {
        this->collections = Collections;
    }
    else
        std::cout << "Ошибка! Сборы должны быть положительным числом." << std::endl;
}

void Airplane::SetPassengerCapacity(int PassengerCapacity)
{
    if (PassengerCapacity >= 0)
    {
        this->passenger_capacity = PassengerCapacity;
    }
    else
        std::cout << "Ошибка! Вместимость пассажиров не может быть отрицательной." << std::endl;
}

void Airplane::SetCargoCapacity(double CargoCapacity)
{
    if (CargoCapacity >= 0)
    {
        this->cargo_capacity = CargoCapacity;
    }
    else
        std::cout << "Ошибка! Грузоподъемность не может быть отрицательной." << std::endl;
}

std::istream& operator>>(std::istream& is, Airplane& ob)
{
    is >> static_cast<Passenger_carrier&>(ob);
    std::cout << "Введите сборы в аэропорту ";
    is >> ob.collections;
    std::cout << "Введите вместимость пассажиров: ";
    is>>ob.passenger_capacity;
    std::cout << "Введите грузоподъемность (кг) ";
    is>>ob.cargo_capacity;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return is;
}

std::ostream& operator<<(std::ostream& out, Airplane& obj)
{
    out << static_cast<Passenger_carrier&>(obj);
    out << std::setw(15) << obj.collections << "| "
        << std::setw(15) << obj.passenger_capacity << "| "
        << std::setw(16) << obj.cargo_capacity << "| ";
    return out;
}

Airplane& Airplane::operator=(const Airplane& other)
{
    if (this != &other)
    {
        Passenger_carrier::operator=(other);
        this->SetCollections(other.collections);
        this->SetPassengerCapacity(other.passenger_capacity);
        this->SetCargoCapacity(other.cargo_capacity);
    }
    return *this;
}

void Airplane::menu()
{
    Passenger_carrier::menu();
    std::cout << "10. Изменить количество пассажиров" << std::endl;
    std::cout << "11. Изменить грузоподъемность" << std::endl;
    std::cout << "12. Изменить сборы" << std::endl;
    std::cout << "13. Получить количесвто пассажиров" << std::endl;
    std::cout << "14. Получить грузоподъемность" << std::endl;
    std::cout << "15. Получить сборы" << std::endl;
}

void Airplane::print_header()const
{
    Passenger_carrier::print_header();
    std::cout << std::left
        << std::setw(15) << "Сборы" << "| "
        << std::setw(15) << "Вместимость" << "| "
        << std::setw(16) << "Грузоподъемность" << "| " << std::endl;
}

bool Airplane::operator==(const Airplane& other) const
{
    return Passenger_carrier::operator==(other) &&
        collections == other.collections &&
        passenger_capacity == other.passenger_capacity &&
        cargo_capacity == other.cargo_capacity;
}


