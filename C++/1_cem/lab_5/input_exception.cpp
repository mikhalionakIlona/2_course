#include <regex> 
#include "InputException.h"
#include "input_exception.h"

std::string empty_input(std::istream& is)              //проверка на пустоту
{
    while (true) {
        try {
            std::string message;
            std::getline(is, message);
            if (message.empty())
                throw InputException("Строка не может быть пустой", 1);
            return message;
        }
        catch (const InputException& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
            std::cout << "Введите строку еще раз: ";
        }
    }
}

int number_input(std::istream& is, int min, int max)   //проверка на ввод числа int
{
    while (true) {
        try {
            std::string message = empty_input(is);
            bool isValid = true;
            size_t start = 0;

            if (message[0] == '-')
            {
                start = 1;
                if (message.length() == 1)
                {
                    isValid = false;
                }
            }

            for (size_t i = start; i < message.length(); ++i)
            {
                if (message[i] < '0' || message[i] > '9')
                {
                    isValid = false;
                    break;
                }
            }

            if (!isValid)
                throw InputException("Строка должна содержать только цифры", 2);

            int number = std::stoi(message);

            if (number > max || number < min)
                throw InputException("Значение должно быть от " + std::to_string(min) + " до " + std::to_string(max), 3);

            return number;
        }
        catch (const InputException& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
            std::cout << "Введите число еще раз: ";
        }
        catch (const std::invalid_argument&) {
            std::cerr << "Ошибка: Введено не число" << std::endl;
            std::cout << "Введите число еще раз: ";
        }
        catch (const std::out_of_range&) {
            std::cerr << "Ошибка: Число слишком большое или слишком маленькое" << std::endl;
            std::cout << "Введите число еще раз: ";
        }
    }
}

std::string word_input(std::istream& is)               //проверка на ввод слова только на английском
{
    while (true) {
        try {
            std::string message = empty_input(is);
            bool isValid = true;
            for (size_t i = 0; i < message.length(); i++)
            {
                char c = message[i];
                if (!((c >= 'A' && c <= 'Z') ||
                    (c >= 'a' && c <= 'z') ||
                    c == ' '))
                {
                    isValid = false;
                    break;
                }
            }
            if (!isValid)
            {
                throw InputException("Ввод должен содержать только латинские буквы", 4);
            }
            return message;
        }
        catch (const InputException& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
            std::cout << "Введите слово еще раз: ";
        }
    }
}

int year_input(std::istream& is)                   //проверка на ввод года
{
    while (true) {
        try {
            std::string message = empty_input(is);
            if (message.length() != 4)
                throw InputException("Год должен содержать 4 цифры", 5);
            for (size_t i = 0; i < message.length(); i++)
            {
                if (message[i] < '0' || message[i] > '9')
                {
                    throw InputException("Год должен содержать только цифры", 5);
                }
            }
            int year = std::stoi(message);

            if (year < 1800 || year > 2025)
            {
                throw InputException("Год должен быть в диапазоне от 1800 до 2025", 6);
            }
            return year;
        }
        catch (const InputException& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
            std::cout << "Введите год еще раз: ";
        }
        catch (const std::invalid_argument&) {
            std::cerr << "Ошибка: Введено не число" << std::endl;
            std::cout << "Введите год еще раз: ";
        }
        catch (const std::out_of_range&) {
            std::cerr << "Ошибка: Год вне допустимого диапазона" << std::endl;
            std::cout << "Введите год еще раз: ";
        }
    }
}

std::string single_word_input(std::istream& is)        //проверка на ввод одного слова
{
    while (true) {
        try {
            std::string word = word_input(is);

            for (size_t i = 0; i < word.length(); i++) {
                if (word[i] == ' ') {
                    throw InputException("Введите только одно слово (без пробелов)", 7);
                }
            }

            return word;
        }
        catch (const InputException& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
            std::cout << "Введите одно слово еще раз: ";
        }
    }
}

std::string time_input(std::istream& is)           //проверка на время
{
    while (true) {
        try {
            std::string message = empty_input(is);
            if (message.length() != 5)
            {
                throw InputException("Время должно быть в формате HH:MM (5 символов)", 8);
            }
            if (message[2] != ':')
            {
                throw InputException("Используйте двоеточие для разделения часов и минут", 9);
            }
            std::string hours_str = message.substr(0, 2);
            std::string minutes_str = message.substr(3, 2);
            for (char c : hours_str) {
                if (c < '0' || c > '9') {
                    throw InputException("Часы должны содержать только цифры", 10);
                }
            }
            for (char c : minutes_str) {
                if (c < '0' || c > '9') {
                    throw InputException("Минуты должны содержать только цифры", 11);
                }
            }
            int hours = std::stoi(hours_str);
            int minutes = std::stoi(minutes_str);

            if (hours < 0 || hours > 23)
            {
                throw InputException("Часы должны быть в диапазоне 00-23", 10);
            }

            if (minutes < 0 || minutes > 59)
            {
                throw InputException("Минуты должны быть в диапазоне 00-59", 11);
            }

            return message;
        }
        catch (const InputException& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
            std::cout << "Введите время еще раз (HH:MM): ";
        }
        catch (const std::invalid_argument&) {
            std::cerr << "Ошибка: Неверный формат времени" << std::endl;
            std::cout << "Введите время еще раз (HH:MM): ";
        }
        catch (const std::out_of_range&) {
            std::cerr << "Ошибка: Время вне допустимого диапазона" << std::endl;
            std::cout << "Введите время еще раз (HH:MM): ";
        }
    }
}

double double_input(std::istream& is, double min, double max)   //проверка на ввод числа double
{
    while (true) {
        try {
            std::string message = empty_input(is);
            if (message[0] == ',' || message[0] == '.') {
                throw InputException("Число не может начинаться с , или .", 14);
            }
            size_t pos;
            double number = std::stod(message, &pos);
            for (size_t i = pos; i < message.length(); i++) {
                if (message[i] != ' ' && message[i] != '\t') {
                    throw InputException("Введено не число типа double", 12);
                }
            }
            if (number < min || number > max) {
                throw InputException("Значение должно быть от " +
                    std::to_string(min) + " до " +
                    std::to_string(max), 13);
            }
            return number;
        }
        catch (const InputException& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
            std::cout << "Введите число еще раз: ";
        }
        catch (const std::invalid_argument&) {
            std::cerr << "Ошибка: Введено не число" << std::endl;
            std::cout << "Введите число еще раз: ";
        }
        catch (const std::out_of_range&) {
            std::cerr << "Ошибка: Число слишком большое или слишком маленькое" << std::endl;
            std::cout << "Введите число еще раз: ";
        }
    }
}