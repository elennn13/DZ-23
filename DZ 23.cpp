#include <iostream>
// Функция, которая возводит переменную в степень, не используя
//  встроенные функции :
void power(int* num, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= *num;
    }
    *num = result;
}

// Функция, которая находит максимальное из трех чисел и меняет 
// значения остальных на максимальное :


static void three_max(int& a, int& b, int& c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    a = max;
    b = max;
    c = max;
}


void findFirstNegativeIndex(const int* array, int length, int& index) {
    index = -1; // Инициализация переменной значением -1
    for (int i = 0; i < length; ++i) {
        if (array[i] < 0) {
            index = i; // Запись индекса первого отрицательного элемента
            break; // Выход из цикла после нахождения
        }
    }
}




void nullifyCommonElements(int* firstArray, int firstLength, int* secondArray, int secondLength) {
    for (int i = 0; i < secondLength; ++i) {
        for (int j = 0; j < firstLength; ++j) {
            if (*(secondArray + i) == *(firstArray + j)) {
                *(secondArray + i) = 0; // Обнуление элемента
                break; // Прерываем внутренний цикл, если найдено совпадение
            }
        }
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* ptr = arr; // указатель на первый элемент массива

    // Меняем местами четные и нечетные элементы
    for (int i = 0; i < 5; i++) {
        int temp = *ptr;
        *ptr = *(ptr + 1);
        *(ptr + 1) = temp;
        ptr += 2;
    }

    // Выводим измененный массив
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;




    int n = 10;
    power(&n, 3);
    std::cout << n << std::endl; // Выведет 1000
  



    int a = 3, b = 5, c = 4;
    three_max(a, b, c);
    std::cout << a << " " << b << " " << c << std::endl; // Выведет 5 5 5


    // ЗАДАЧА 2

        int array[] = { 1, 2, -3, 4, -5 }; // Пример массива
        int index;
        int length = sizeof(array) / sizeof(array[0]); // Вычисление длины массива

        findFirstNegativeIndex(array, length, index);

        std::cout << "Индекс первого отрицательного элемента: " << index << std::endl;

    // ЗАДАЧА 3
        int firstArray[] = { 3, 6, 4, 1, 4, 8, 2 };
        int secondArray[] = { 5, 3, 1, 5, 10, 8 };
        int firstLength = sizeof(firstArray) / sizeof(firstArray[0]);
        int secondLength = sizeof(secondArray) / sizeof(secondArray[0]);

        nullifyCommonElements(firstArray, firstLength, secondArray, secondLength);

        std::cout << "Массив 2 после вызова функции: { ";
        for (int i = 0; i < secondLength; ++i) {
            std::cout << secondArray[i] << (i < secondLength - 1 ? ", " : " ");
        }
        std::cout << "}" << std::endl;


        return 0;
    }
