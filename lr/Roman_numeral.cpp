#include <iostream>
#include <windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number;

	std::cout << "¬вед≥ть арабське число: ";
	std::cin >> number;

	std::cout << "¬ведене число : " << number << std::endl;

    return 0;
}