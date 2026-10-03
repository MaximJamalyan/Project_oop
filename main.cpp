#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // 1. Создаем четыре матрицы разными конструкторами
    Matrix m1;         // 0x0
    Matrix m2(3);      // 3x3, единичная
    Matrix m3(3, 4);   // 3x4, нули
    Matrix m4(2, 3);   // 2x3, нули

    // 2. Вывод на экран m2, m3, m4
    std::cout << "=== Исходные матрицы ===\n";
    std::cout << "m2 (3x3 единичная):\n";
    m2.print();

    std::cout << "m3 (3x4 нули):\n";
    m3.print();

    std::cout << "m4 (2x3 нули):\n";
    m4.print();

    // 3. Заполнение m2 по формуле: element(i, j) = i * j
    std::cout << "=== m2 после заполнения по формуле (i * j) ===\n";
    for (int i = 0; i < m2.getRows(); ++i) {
        for (int j = 0; j < m2.getCols(); ++j) {
            m2.set(i, j, i * j);
        }
    }
    m2.print();

    // 4. Заполнение m3 случайными числами через fillRandom()
    std::cout << "=== m3 после fillRandom() ===\n";
    m3.fillRandom();
    m3.print();

    // 5. Заполнение m4 с клавиатуры через inputFromKeyboard()
    std::cout << "=== Заполнение m4 (2x3) с клавиатуры ===\n";
    m4.inputFromKeyboard();
    std::cout << "m4 после ввода:\n";
    m4.print();

    // 6. Подсчет суммы элементов m3
    std::cout << "Сумма элементов m3: " << m3.sum() << "\n\n";

    // ДЗ Часть 2: Проверка поверхностного копирования (когда нет конструктора копирования)
    std::cout << "=== Демонстрация поверхностного копирования (ДЗ) ===\n";
    Matrix mm = m3;
    std::cout << "Скопированная матрица mm:\n";
    mm.print();

    // 7. Демонстрация работы исключений
    std::cout << "=== Тестирование исключений ===\n";
    try {
        Matrix bad(-1, 5); // Отрицательная размерность
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught: " << e.what() << '\n';
    }

    try {
        m3.get(100, 100); // Выход за границы
    } catch (const std::out_of_range& e) {
        std::cout << "Caught: " << e.what() << '\n';
    }

    return 0;
}