#include "Car.h"

Car::Car()
{
    price_fuel = 0.0;
    year_production = 0;
    car_type = "Не указан";
}

Car::Car(double Price_fuel, const std::string& Name, const double Distance, const double Money_km, const double Speed) :Passenger_carrier(Name, Distance, Money_km, Speed)
{
    price_fuel = Price_fuel;
    year_production = 0;
    car_type = "Не указан";
}

Car::Car(const Car& other) :Passenger_carrier(other)
{
    price_fuel = other.price_fuel;
    year_production = other.year_production;
    car_type = other.car_type;
}

Car::~Car()
{
}

double Car::time_in_path()
{
    return Passenger_carrier::time_in_path();
}

double Car::cost_path()
{
    double base_cost = Passenger_carrier::cost_path();
    return base_cost + price_fuel;
}

double Car::GetPrice_fuel()
{
    return price_fuel;
}

void Car::SetPrice_fuel(double Price_fuel)
{
    if (Price_fuel > 0)
    {
        price_fuel = Price_fuel;
    }
    else
        std::cout << "Ошибка!" << std::endl;
}

int Car::GetYear_production()
{
    return year_production;
}

std::string Car::GetCar_type()
{
    return car_type;
}

void Car::SetYear_production(int Year_production)
{
    if (Year_production > 1900 && Year_production <= 2024)
    {
        year_production = Year_production;
    }
    else
    {
        std::cout << "Ошибка! Некорректный год выпуска" << std::endl;
    }
}

void Car::SetCar_type(const std::string& Car_type)
{
    if (!Car_type.empty())
    {
        car_type = Car_type;
    }
    else
    {
        std::cout << "Ошибка! Тип автомобиля не может быть пустым" << std::endl;
    }
}

std::istream& operator>>(std::istream& is, Car& ob)
{
    is >> static_cast<Passenger_carrier&>(ob);
    std::cout << "Введите цену за топливо (от 1.5 до 10 )";
    ob.price_fuel=double_input(is,1.5,10);
    std::cout << "Введите год выпуска (от 1800 до 2025 )";
    ob.year_production=year_input(is);
    std::cout << "Введите тип автомобиля (на английском)";
    ob.car_type=word_input(is);
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return is;
}

std::ostream& operator<<(std::ostream& os, Car& ob)
{
    os << static_cast<Passenger_carrier&>(ob);
    os << ob.price_fuel << "| "
        << ob.year_production << "| "
        << ob.car_type << "| ";
    return os;
}

Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        Passenger_carrier::operator=(other);
        this->SetPrice_fuel(other.price_fuel);
        this->SetYear_production(other.year_production);
        this->SetCar_type(other.car_type);
    }

    return *this;
}

void Car::menu()
{
    Passenger_carrier::menu();
    std::cout << "10.Изменить цену за топливо" << std::endl;
    std::cout << "11.Получить цену за топливо" << std::endl;
    std::cout << "12.Изменить год выпуска" << std::endl;
    std::cout << "13.Получить год выпуска" << std::endl;
    std::cout << "14.Изменить тип автомобиля" << std::endl;
    std::cout << "15.Получить тип автомобиля" << std::endl;
}

void Car::print_header()const
{
    Passenger_carrier::print_header();
    std::cout << std::left
        << std::setw(15) << "Цена топлива" << "| "
        << std::setw(15) << "Год выпуска" << "| "
        << std::setw(16) << "Тип автомобиля" << "| " << std::endl;
}

bool Car::operator==(const Car& other) const
{
    return Passenger_carrier::operator==(other) &&
        price_fuel == other.price_fuel &&
        year_production == other.year_production &&
        car_type == other.car_type;
}