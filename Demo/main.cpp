#include <iostream>
#include <clocale>

#include "../Domain/Circle.h"
#include "../Domain/Circle.cpp"

int main()
{
	setlocale(LC_ALL, "RUS");

	try
	{
		double radius;

		std::cout << "Введите радиус круга: ";
		std::cin >> radius;

		circle::Circle circle1(radius);

		std::cout << "Введенный радиус: " << circle1.GetRadius() << "\n";
		std::cout << "Диаметр окружности: " << circle1.GetDiameter() << "\n";
		std::cout << "Длина окружности: " << circle1.GetLength() << "\n";
		std::cout << "Площадь окружности: " << circle1.GetArea() << "\n";
	}
	catch (const std::exception& error)
	{
		std::cout << "ОШИБКА: " << error.what() << "\n";
	}

	return 0;
}