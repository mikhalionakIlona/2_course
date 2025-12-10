#include "List.cpp"
#include "Airplane.h"
#include "Train.h"
#include "Car.h"


template<typename T>
void work_list() {
    List<T> transportList;
    int choice;

    do {
        cout << "\n--- МЕНЮ РАБОТЫ СО СПИСКОМ ---" << endl;
        cout << "0. Выйти из меню" << endl;
        cout << "1. Добавить транспорт в КОНЕЦ списка" << endl;
        cout << "2. Добавить трансопорт в НАЧАЛО списка" << endl;
        cout << "3. Удалить транспорт с НАЧАЛА списка" << endl;
        cout << "4. Удалить транспорт с КОНЦА списка" << endl;
        cout << "5. Удалить ВЕСЬ список" << endl;
        cout << "6. Показать весь список" << endl;
        cout << "7. Поиск в списке" << endl;
        cout << "8. Сортировка списка по расстоянию" << endl;
        cout << "9. Сортировка списка по скорости" << endl;
        cout << "10. Размер списка" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Выйти из меню" << endl;
            break;
        case 1:
        {
            T transport;
            cin >> transport;
            transportList.push_back(transport);
            cout << "Транспрот добавлен в конец списка" << endl;
            break;
        }
        case 2:
        {
            T transport;
            cin >> transport;
            transportList.push_front(transport);
            cout << "Транспрот добавлен в начало списка" << endl;
            break;
        }
        case 3:
        {
            if (transportList.empty())
            {
                cout << "Список пуст" << endl;
            }
            else
            {
                transportList.delete_front();
                cout << "Транспрот удален с начала списка" << endl;
            }
            break;
        }
        case 4:
        {
            if (transportList.empty())
            {
                cout << "Список пуст" << endl;
            }
            else
            {
                transportList.delete_back();
                cout << "Транспрот удален с конца списка" << endl;
            }
            break;
        }
        case 5:
        {
            if (transportList.empty())
            {
                cout << "Список уже пуст" << endl;
            }
            else
            {
                transportList.clear_list();
                cout << "Весь список очищен" << endl;
            }
            break;
        }
        case 6:
        {
            if (transportList.empty())
            {
                cout << "Список пуст" << endl;
            }
            else
            {
                cout << "\n=== СОДЕРЖИМОЕ СПИСКА ===" << endl;
                transportList.see_list();
            }
            break;
        }
        case 7:
        {
            if (transportList.empty())
            {
                cout << "Список пуст" << endl;
            }
            else
            {
                int param;
                int value;
                std::cout << "1. Расстоянию перевчозки" << std::endl;
                std::cout << "2. Стоимости за километр" << std::endl;
                std::cout << "3. Скорости транспорта" << std::endl;
                std::cout << "Введите по какому параметру хотите искать: ";
                std::cin >> param;
                std::cout << "Введите значение: ";
                cin >> value;
                List<T> newList = transportList.search_list(param, value);
                newList.see_list();
                newList.clear_list();
            }
            break;
        }
        case 8:
        {
            if (transportList.empty())
            {
                cout << "Список пуст" << endl;
            }
            else
            {
                transportList.sort_distance();
            }
            break;
        }
        case 9:
            if (transportList.empty())
            {
                cout << "Список пуст" << endl;
            }
            else
            {
                transportList.sort_speed();
            }
            break;
        case 10:
        {
            cout << "Размер списка: " << transportList.getSize() << " элементов" << endl;
            break;
        }
        default:
            cout << "Неверный выбор" << endl;
        }
    } while (choice != 0);
}

void menu_selection()
{
    int choice;

    do {
        cout << "=== ВЫБОР ТИПА ТРАНСПОРТА ===" << endl;
        cout << "0. Выйти из меню" << endl;
        cout << "1. Работа с самолетами" << endl;
        cout << "2. Работа с поездами" << endl;
        cout << "3. Работа с автомобилями" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n=== РАБОТА СО СПИСКОМ САМОЛЕТОВ ===" << endl;
            work_list<Airplane>();
            break;
        case 2:
            cout << "\n=== РАБОТА СО СПИСКОМ ПОЕЗДОВ ===" << endl;
            work_list<Train>();
            break;
        case 3:
            cout << "\n=== РАБОТА СО СПИСКОМ АВТОМОБИЛЕЙ ===" << endl;
            work_list<Car>();
            break;
        case 0:
            cout << "Выход из программы..." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
}

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
            cout << endl << "САМОЛЕТ" << endl;
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
            double i;
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
