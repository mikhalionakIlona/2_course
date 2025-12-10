#include "Passenger_carrier.h"

Passenger_carrier::Passenger_carrier()
{
	distance = 0.0;
	money_km = 0.0;
	speed = 0.0;
}

Passenger_carrier::Passenger_carrier(const std::string& Name, const double Distance, const double Money_km, const double Speed)
{
	name = Name;
	distance = Distance;
	money_km = Money_km;
	speed = Speed;
}

Passenger_carrier::Passenger_carrier(const Passenger_carrier& other)
{
	name = other.name;
	distance = other.distance;
	money_km = other.money_km;
	speed = other.speed;
}

Passenger_carrier::~Passenger_carrier()
{
}

void Passenger_carrier::menu()
{
	std::cout << "=============МЕНЮ============" << std::endl;
	std::cout << "0. Выйти" << std::endl;
	std::cout << "1. Вывести объект" << std::endl;
	std::cout << "2. Изменить название" << std::endl;
	std::cout << "3. Изменить расстояние" << std::endl;
	std::cout << "4. Изменить стоимость за км" << std::endl;
	std::cout << "5. Изменить скорость" << std::endl;
	std::cout << "6. Получить название" << std::endl;
	std::cout << "7. Получить расстояние" << std::endl;
	std::cout << "8. Получить стоимость за км" << std::endl;
	std::cout << "9. Получить скорость" << std::endl;
}

double Passenger_carrier::time_in_path()
{
	return distance / speed;
}

double Passenger_carrier::cost_path()
{
	return distance * money_km;
}

std::string Passenger_carrier::GetName()
{
	return name;
}

double Passenger_carrier::GetDistance()
{
	return distance;
}

double Passenger_carrier::GetMoney_km()
{
	return money_km;
}

double Passenger_carrier::GetSpeed()
{
	return speed;
}

void Passenger_carrier::SetName(const std::string Name)
{
	name = Name;
}

void Passenger_carrier::SetDistance(double Distance)
{
	if (Distance > 0)
	{
		distance = Distance;
	}
	else
		std::cout << "Ошибка!" << std::endl;
}

void Passenger_carrier::SetMoney_km(double Money_km)
{
	if (Money_km > 0)
	{
		money_km = Money_km;
	}
	else
		std::cout << "Ошибка!" << std::endl;
}

void Passenger_carrier::SetSpeed(double Speed)
{
	if (Speed > 0)
	{
		speed = Speed;
	}
	else
		std::cout << "Ошибка!" << std::endl;
}

std::istream& operator>>(std::istream& is, Passenger_carrier& ob)
{
	std::string name;
	std::cout << "Введите название (одно слово): ";
	is.ignore();
	ob.name= single_word_input(is);
	std::cout << "Введите расстояние (от 0,1 до 1000) : ";
	ob.distance = double_input(is,0.1,1000);
	std::cout << "Введите стоимость за км (от 0,5 до 100 ): ";
	ob.money_km = double_input(is,0.5,100);
	std::cout << "Введите скорость (от 20,0 до 200 ): ";
	ob.speed=double_input(is,20.0,200);
	return is;
}

std::ostream& operator<<(std::ostream& out, Passenger_carrier& obj)
{
	out << std::setw(15) << obj.name << "| "
		<< std::setw(15) << obj.distance << "| "
		<< std::setw(15) << obj.speed << "| "
		<< std::setw(15) << obj.money_km << "| ";
	return out;
}

Passenger_carrier& Passenger_carrier::operator=(const Passenger_carrier& other)
{
	if (this != &other)
	{
		this->SetName(other.name);
		this->SetDistance(other.distance);
		this->SetMoney_km(other.money_km);
		this->SetSpeed(other.speed);
	}
	return *this;
}

void Passenger_carrier::print_header() const
{
	std::cout << std::left
		<< std::setw(15)  << "Название" << "| "
		<< std::setw(15) << "Расстояние(км)" << "| "
		<< std::setw(15) << "Скорость(км/ч)" << "| "
		<< std::setw(15) << "Стоимость за км" << "| ";
}

bool Passenger_carrier::operator==(const Passenger_carrier& other) const
{
	return name == other.name &&
		distance == other.distance &&
		money_km == other.money_km &&
		speed == other.speed;
}