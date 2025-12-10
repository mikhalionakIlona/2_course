#include <iostream>
#include "List.h"
#include "Airplane.h"
#include "menu.h"
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251>nul");
    menu_selection();
    return 0;
}
