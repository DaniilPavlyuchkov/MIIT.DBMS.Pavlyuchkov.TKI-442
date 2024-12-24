#pragma once
#include <iostream>

namespace circle
{
	/**
	* @brief Класс Круг
	*/
	class Circle
	{
	private:
		/**
		* @brief Радиус
		*/
		double radius;
	public:
		/*
		* @brief Вернуть радиус
		* @return Радиус
		*/
		double GetRadius() const;

		/*
		* @brief Вернуть диаметр
		* @return Диаметр
		*/
		double GetDiameter() const;

		/*
		* @brief Рассчитать длину окружности
		* @return Длина окружности
		*/
		double GetLength() const;

		/*
		* @brief Рассчитать площадь окружности
		* @return Площадь
		*/
		double GetArea() const;

		/*
		* @brief Инициализирует новый объект класса Circle
		* @param radius Радиус
		*/
		explicit Circle(const double radius);
	};

	/*
	* @brief Выводит в поток информацию о круге
	* @param output Поток вывода
	* @param object Круг
	*/
	std::ostream& operator<<(std::ostream& output, const Circle& object);
}

