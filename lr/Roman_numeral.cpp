#include <iostream>
#include <string>
#include <windows.h>

std::string convertToRoman(int number) {
	const int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	const std::string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	std::string result;

	for (int i = 0; i < 13; ++i) {
		while (number >= values[i]) {
			result += symbols[i];
			number -= values[i];
		}
	}
	return result;
}

int convertToArabic(const std::string& roman) {
	const int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	const std::string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int result = 0;
	size_t i = 0;
	while (i < roman.length()) {
		bool matched = false;
		for (int j = 0; j < 13; ++j) {
			if (roman.substr(i, symbols[j].length()) == symbols[j]) {
				result += values[j];
				i += symbols[j].length();
				matched = true;
				break;
			}
		}
		if (!matched) {
			return -1; 
		}
	}
	return result;
}

bool isValidRoman(const std::string& roman) {
	int number = convertToArabic(roman);

	return number >= 1 && number <= 3999
		&& convertToRoman(number) == roman;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;

	std::cout << "Оберіть напрямок перетворення:\n";
	std::cout << "1. Арабське число в римське\n";
	std::cout << "2. Римське число в арабське\n";
	std::cout << "\nВаш вибір: ";
	std::cin >> choice;

	if (choice == 1) {
		int number;

		std::cout << "Введіть арабське число: ";
		std::cin >> number;

		if (number < 1 || number > 3999) {
			std::cout << "Помилка: число має бути від 1 до 3999.\n";
			return 1;
		}

		std::cout << "Римське число: "
			<< convertToRoman(number) << '\n';
	}

	else if (choice == 2) {
		std::string roman;

		std::cout << "Введіть римське число: ";
		std::cin >> roman;

		if (!isValidRoman(roman)) {
			std::cout << "Помилка: некоректний римський запис.\n";
			return 1;
		}

		std::cout << "Арабське число: "
			<< convertToArabic(roman) << '\n';
	}


    return 0;
}