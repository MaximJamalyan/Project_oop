#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

// 1. Конструктор по умолчанию: 0x0, память не выделяется
Matrix::Matrix() : data_(nullptr), rows_(0), cols_(0) {}

// 2. Конструктор единичной матрицы
Matrix::Matrix(int size) : data_(nullptr), rows_(size), cols_(size) {
    if (size < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (size == 0) {
        return;
    }

    // Выделяем память
    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_]{}; // Заполняем нулями
        data_[i][i] = 1;            // Главная диагональ = 1
    }
}

// 3. Конструктор с двумя параметрами (нулевая матрица)
Matrix::Matrix(int rows, int cols) : data_(nullptr), rows_(rows), cols_(cols) {
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (rows == 0 || cols == 0) {
        // Если одно из измерений 0, матрица пустая
        rows_ = 0;
        cols_ = 0;
        return;
    }

    // Построчное выделение памяти с занулением `{}`
    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_]{}; // Вариант с нулевой инициализацией через {}
    }
}

// 4. Деструктор
Matrix::~Matrix() {
    if (data_ == nullptr) return; // Для пустой матрицы (0x0) делать нечего

    // Освобождаем память в обратном порядке
    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i]; // Удаляем каждую строку
    }
    delete[] data_; // Удаляем массив указателей
}

// 5. Геттер элемента
int Matrix::get(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Индексы выходят за границы матрицы!");
    }
    return data_[i][j];
}

// 6. Сеттер элемента
void Matrix::set(int i, int j, int value) {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Индексы выходят за границы матрицы!");
    }
    data_[i][j] = value;
}

// 7. Ввод с клавиатуры
void Matrix::inputFromKeyboard() {
    std::cout << "Введите элементы матрицы " << rows_ << "x" << cols_ << ":\n";
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cin >> data_[i][j];
        }
    }
}

// 8. Заполнение случайными числами
void Matrix::fillRandom() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = std::rand() % 100; // Числа от 0 до 99
        }
    }
}

// 9. Вывод на экран
void Matrix::print() const {
    if (rows_ == 0 || cols_ == 0) {
        std::cout << "Матрица пуста (0x0)\n\n";
        return;
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << std::setw(4) << data_[i][j];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

// 10. Подсчет суммы элементов
int Matrix::sum() const {
    int total = 0;
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            total += data_[i][j];
        }
    }
    return total;
}

// 11. Геттеры размеров
int Matrix::getRows() const { return rows_; }
int Matrix::getCols() const { return cols_; }

// 12. Домашнее задание: Транспонирование
Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_); // Создаем новую матрицу с переставленными размерами
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result.set(j, i, data_[i][j]);
        }
    }
    return result;
}