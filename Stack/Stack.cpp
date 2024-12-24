#include "pch.h"
#include "Stack.h"
#include <stdexcept>
#include <sstream>

// Конструктор
Stack::Stack() 
{

}

// Деструктор
Stack::~Stack() 
{

}

// Добавление элемента в стек
void Stack::push(int value) 
{
    data_.push_back(value);
}

// Удаление верхнего элемента из стека, если стек не пустой
int Stack::pop() 
{
    if (data_.empty()) 
    {
        throw std::out_of_range("Стек пустой");
    }
    int val = data_.back();
    data_.pop_back();
    return val;
}

// Возврат верхнего элемента, если стек не пустой
int Stack::top() const 
{
    if (data_.empty()) 
    {
        throw std::out_of_range("Стек пустой");
    }
    return data_.back();
}

// Проверка стека на отсутствие элементов
bool Stack::empty() const 
{
    return data_.empty();
}

// Проверка стека на количество элементов
size_t Stack::size() const 
{
    return data_.size();
}


// Преобразование стека в строку
std::string Stack::toString() const 
{
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < data_.size(); ++i) 
    {
        oss << data_[i];
        if (i + 1 < data_.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

// Ввод элемента в стек из потока
std::istream& operator>>(std::istream& is, Stack& stack) 
{
    int value;
    if (is >> value) 
    {
        stack.push(value);
    }
    return is;
}
