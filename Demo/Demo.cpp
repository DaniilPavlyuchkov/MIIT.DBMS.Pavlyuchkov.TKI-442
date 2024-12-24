#include <iostream>
#include "../Stack/Stack.h"

int main() 
{
    Stack stack;

    std::cout << "Стек пустой?: " << stack.empty() << "\n";

    stack.push(111);
    std::cout << "В стек добавлено:" << stack.top() << "\n";
    stack.push(222);
    std::cout << "В стек добавлено:" << stack.top() << "\n";
    stack.push(333);
    std::cout << "В стек добавлено:" << stack.top() << "\n";
    stack.push(444);
    std::cout << "В стек добавлено:" << stack.top() << "\n";
    stack.push(555);
    std::cout << "В стек добавлено:" << stack.top() << "\n";

    std::cout << "Содержимое стека: " << stack.toString() << "\n";
    std::cout << "Верхний элемент: " << stack.top() << "\n";

    std::cout << "Удалить верхний элемент: " << stack.pop() << "\n";
    std::cout << "Стек после удаления верхнего элемента: " << stack.toString() << "\n";

    std::cout << "Введите элемент для добавления в стек: ";
    std::cin >> stack;
    std::cout << "Стек после ввода: " << stack.toString() << "\n";

    std::cout << "Стек пустой?: " << stack.empty();

    return 0;
}
