#include "pch.h" 
#include "CppUnitTest.h"
#include "../Stack/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(StackTest)
    {
    public:

        // Создание стека
        TEST_METHOD(Stack_Empty_OnCreation_IsEmpty)
        {
            Stack stack;
            Assert::IsTrue(stack.empty(), L"Новый стек должен быть пустым.");
            Assert::AreEqual((size_t)0, stack.size(), L"Размер пустого стека должен быть 0.");
        }

        // Добавление элементов
        TEST_METHOD(Stack_Push_WhenOneElementPushed_SizeIsOne)
        {
            Stack stack;
            stack.push(10);
            Assert::AreEqual((size_t)1, stack.size(), L"После добавления одного элемента размер должен быть 1.");
            Assert::IsFalse(stack.empty(), L"Стек не должен быть пустым после добавления элемента.");
        }

        // Проверка верхнего элемента
        TEST_METHOD(Stack_Push_WhenMultipleElementsPushed_TopIsLastElement)
        {
            Stack stack;
            stack.push(1);
            stack.push(2);
            stack.push(3);
            Assert::AreEqual(3, stack.top(), L"top() должен возвращать последний добавленный элемент (3).");
        }

        // Удаление верхнего элемента
        TEST_METHOD(Stack_Pop_WhenCalledOnNonEmptyStack_ReturnsLastPushedElement)
        {
            Stack stack;
            stack.push(1);
            stack.push(2);
            int popped = stack.pop();
            Assert::AreEqual(2, popped, L"pop() должен вернуть последний добавленный элемент (2).");
            Assert::AreEqual((size_t)1, stack.size(), L"После pop размер должен уменьшиться на 1.");
        }

        // Исключение при удалении из пустого стека
        TEST_METHOD(Stack_Pop_WhenCalledOnEmptyStack_ThrowsOutOfRange)
        {
            Stack stack;
            bool exceptionThrown = false;
            try 
            {
                stack.pop();
            }
            catch (const std::out_of_range&) 
            {
                exceptionThrown = true;
            }
            Assert::IsTrue(exceptionThrown, L"pop() должен бросать исключение при вызове на пустом стеке.");
        }

        // Исключение при проверке верхнего элемента в пустом стеке
        TEST_METHOD(Stack_Top_WhenCalledOnEmptyStack_ThrowsOutOfRange)
        {
            Stack stack;
            bool exceptionThrown = false;
            try 
            {
                int value = stack.top();
                (void)value;
            }
            catch (const std::out_of_range&) 
            {
                exceptionThrown = true;
            }
            Assert::IsTrue(exceptionThrown, L"top() должен бросать исключение при вызове на пустом стеке.");
        }

        // Преобразование стека в строку
        TEST_METHOD(Stack_ToString_WhenMultipleElements_ReturnsCorrectFormat)
        {
            Stack stack;
            stack.push(5);
            stack.push(10);
            Assert::AreEqual(std::string("[5, 10]"), stack.toString(), L"toString() должен вернуть \"[5, 10]\".");
        }

    };
}
