#include "Passenger_carrier.h"
#include "Airplane.h"
#include "Train.h"
#include "Car.h"

using namespace std;

void menu_airplane(Airplane airplane)
{
	while (1)
	{
		airplane.menu();
		int choice;
		cin >> choice;
		string buffer;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice)
		{
		case 0:
			return;

		case 1:
			cout << endl <<"САМОЛЕТ" << endl;
			airplane.print_header();
			cout << airplane << endl;
			cout << endl;
			break;

		case 2:
			cout << "Введите новое название: ";
			cin >> buffer;
			airplane.SetName(buffer);
			cout << endl;
			break;

		case 3:
			cout << "Введите новое расстояние: ";
			int km;
			cin >> km;
			airplane.SetDistance(km);
			cout << endl;
			break;

		case 4:
			cout << "Введите новую стоимость за км: ";
			int money;
			cin >> money;
			airplane.SetMoney_km(money);
			cout << endl;
			break;

		case 5:
			cout << "Введите новую скорость:";
			int v;
			cin >> v;
			airplane.SetSpeed(v);
			cout << endl;
			break;

		case 6:
			cout << "Название:" << airplane.GetName() << endl;
			cout << endl;
			break;

		case 7:
			cout << "Расстояние: " << airplane.GetDistance() << endl;
			cout << endl;
			break;

		case 8:
			cout << "Стоимость за км: " << airplane.GetMoney_km() << endl;
			cout << endl;
			break;

		case 9:
			cout << "Скорость: " << airplane.GetSpeed() << endl;
			cout << endl;
			break;

		case 10:
			cout << "Введите новое количество пассажиров:";
			int count;
			cin >> count;
			airplane.SetPassengerCapacity(count);
			cout << endl;
			break;

		case 11:
			cout << "Введите ноую грузоподъемность:";
			int i;
			cin >> i;
			airplane.SetCargoCapacity(i);
			cout << endl;
			break;

		case 12:
			cout << "Введите новые сборы: ";
			int d;
			cin >> d;
			airplane.SetCollections(d);
			cout << endl;
			break;

		case 13:
			cout << "Количество пассажиров:" << airplane.GetPassengerCapacity() << endl;
			cout << endl;
			break;

		case 14:
			cout << "Грузоподъемность:" << airplane.GetCargoCapacity() << endl;
			cout << endl;
			break;

		case 15:
			cout << "Сборы:" << airplane.GetCollections() << endl;
			cout << endl;
			break;

		}
	}

}

int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251>nul");
	Airplane airplane[2];
	/*Car car;
	Train train;*/
	for (int i = 0; i < 2; i++)
	{
		cout << "Введите данные для самолета " << (i + 1) << ":" << endl;
		cin >> airplane[i];
		cout << endl;
	}
	/*cout << endl << "Введите данные машины" << endl; cin >> car;
	cout << endl << "Введите данные поезда" << endl; cin >> train;
	cout << endl<<setw(70) << "=== ИНФОРМАЦИЯ О ТРАНСПОРТАХ ===" << endl;*/
	cout << setw(70) << "=== ИНФОРМАЦИЯ О САМОЛЕТАХ ===" << endl;
	airplane[1].print_header();
	for (int i = 0; i < 2; i++)
	{
		cout << airplane[i] << endl;
	}
	/*cout << "МАШИНА:" << endl;
	car.print_header();
	car.print_table();
	cout << endl << endl;
	cout << "ПОЕЗД:" << endl;
	train.print_header();
	train.print_table();
	cout << endl << endl;*/
	cout << "=== РАСЧЕТ СТОИМОСТИ И ВРЕМЕНИ ===" << endl;
	for (int i = 0; i < 2; i++) 
	{
		cout << "Самолет " << (i + 1) << " - Время: " << airplane[i].time_in_path()
			<< " ч, Стоимость: " << airplane[i].cost_path() << " руб" << endl;
	}
		/*<< "Машина  - Время: " << car.time_in_path() << " ч, Стоимость: " << car.cost_path() << " руб" << endl
		<< "Поезд   - Время: " << train.time_in_path() << " ч, Стоимость: " << train.cost_path() << " руб" << endl;*/
	cout << endl << "=== ПРОВЕРКА СЕТТЕРОВ И ГЕТТЕРОВ ===" << endl;
	menu_airplane(airplane[1]);
	return 0;
}


