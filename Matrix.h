#pragma once

#include <stdexcept>
#include <string>

class Matrix {
private:
    int** data_; // Указатель на массив указателей на строки
    int rows_;   // Количество строк
    int cols_;   // Количество столбцов

public:
    // 1. Конструкторы
    Matrix();                           // Конструктор по умолчанию (0x0)
    explicit Matrix(int size);          // Единичная квадратная матрица (size x size)
    Matrix(int rows, int cols);         // Матрица rows x cols, заполненная нулями

    // 2. Деструктор
    ~Matrix();

    // 3. Доступ к элементам
    int get(int i, int j) const;
    void set(int i, int j, int value);

    // 4. Методы заполнения
    void inputFromKeyboard();
    void fillRandom();

    // 5. Вывод и вычисления
    void print() const;
    int sum() const;

    // 6. Геттеры размеров
    int getRows() const;
    int getCols() const;

    // 7. Домашнее задание: транспонирование
    Matrix transpose() const;
};