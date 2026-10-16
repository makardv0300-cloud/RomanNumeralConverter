#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <cctype>

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
	if (roman.empty()) {
		return -1;
	}

	std::string upperRoman = roman;
	for (char& c : upperRoman) {
		c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
	}

    int result = 0;
	size_t i = 0;
	
    while (i < upperRoman.length()) {
		bool matched = false;

		for (int j = 0; j < 13; ++j) {
			if (upperRoman.substr(i, symbols[j].length()) == symbols[j]) {
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

    if (result < 1 || result > 3999 ||
        convertToRoman(result) != upperRoman) {
        return -1;
    }

	return result;
}

bool isValidRoman(const std::string& roman) {
	int number = convertToArabic(roman);

    if (number < 1 || number > 3999) {
        return false;
    }

	std::string upperRoman = roman;
	for (char& c : upperRoman) {
		c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
	}

	return convertToRoman(number) == upperRoman;
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input;
    int choice;

    std::cout << "Оберіть напрямок перетворення:\n";
    std::cout << "1. Арабське число в римське\n";
    std::cout << "2. Римське число в арабське\n";
    std::cout << "\nВаш вибір: ";

    std::getline(std::cin, input);
    std::istringstream menuStream(input);
    char extra;

    if (!(menuStream >> choice) || (menuStream >> extra) ||
        (choice != 1 && choice != 2)) {
        std::cout << "Помилка: оберіть пункт 1 або 2.\n";
        return 1;
    }

    if (choice == 1) {
        int number;

        std::cout << "Введіть арабське число: ";
        std::getline(std::cin, input);

        std::istringstream numberStream(input);

        if (!(numberStream >> number) || (numberStream >> extra)) {
            std::cout << "Помилка: введіть ціле число.\n";
            return 1;
        }

        if (number < 1 || number > 3999) {
            std::cout << "Помилка: число має бути від 1 до 3999.\n";
            return 1;
        }

        std::cout << "Римське число: "
            << convertToRoman(number) << '\n';
    }
    else {
        std::string roman;

        std::cout << "Введіть римське число: ";
        std::getline(std::cin, roman);

        if (!isValidRoman(roman)) {
            std::cout << "Помилка: некоректний римський запис.\n";
            return 1;
        }

        std::cout << "Арабське число: "
            << convertToArabic(roman) << '\n';
    }

    return 0;
}
