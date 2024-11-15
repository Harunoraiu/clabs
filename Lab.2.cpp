#include <string.h> // Подключаем библиотеки для использования "memset"
#include <iostream>

// Создаём структуру с двумя целочисленными полями 
struct TwoInts
{
    int a;
    int b;
};

struct StructWithArray
{
    int arr[4]; // Создаём целочисленный массив из 4-х элементов 
    int* someNumber; // Создаём указатель на целое число
};

int main()
{
    // Создаём экземпляр первой структуры (TwoInts) и инициализируем нулями
    TwoInts i2 = { };
    i2.a = 5; // Присваиваем переменной "а" из структуры число 5
    i2.b = 7; // Присваиваем переменной "b" из структуры число 7

    // Выводим обе переменные экземпляра i2
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;
    
    StructWithArray s = { }; // Создаём экземпляр второй структуры (StructWithArray) и так-же инициализируем нулями
    s.arr[0] = 10; // Присваиваем первому элементу массива число 10 из данного экземпляра структуры

    StructWithArray s1 = { }; // Создаём второй экземпляр второй структуры (StructWithArray) и так-же инициализируется нулями
    s1.arr[0] = 15; // Присваиваем первому элементу массива число 15 из данного экземпляра структуры

    StructWithArray* sPointer = &s; // Создаём указатель "sPointer" который хранит в себе ссылку на экземпляр "s"
    sPointer->arr[0] = 20; // Через этот указатель изменяем значение первого элемента массива из экземпляра "s"

    std::cout << s.arr[0] << std::endl; // Выводим первый элемент массива экземпляра "s"
    s.arr[0] = 25; // Измененяем значение этого-же элемента на 25
    std::cout << s.arr[0] << std::endl; // Выводим этот самый элемент (25)
    sPointer->arr[0] = 30; // Меняем значение первого элемента массива на 30 через указатель на экземпляр "s"
    std::cout << s.arr[0] << std::endl; // Выводим этот элемент (30)

    sPointer = &s1; // Перенаправляем указатель с экземпляра "s" на экземпляр "s1" 
    sPointer->arr[0] = 35; // Изменяем первый элемент из массива в "s1" через указатель
    std::cout << s.arr[0] << std::endl; // Выводим первый элемент из массива из экземпляра "s" (30)
    std::cout << s1.arr[0] << std::endl; // Выводим первый элемент из массива из экземпляра "s1" (35"

    StructWithArray structArray[2] = { }; // Создаём массив экземпляров структуры "StructWithArray"
    structArray[0].arr[3] = 77; // Присваиваем четвёртому элементу массива первый экземпляр числа 77
    structArray[1].someNumber = &structArray[0].arr[3]; // В указатель someNumber второго экземпляра записываем адрес третьего элемента массива первого экземпляра.

    sPointer = &s; // Возвращаем указатель обратно на экземпляр "s"
    int* pointer = &sPointer->arr[3]; // Присваиваем указателю pointer адрес третьего элемента массива экземпляра "s".
    s.arr[3] = 72; // Присваиваем четвёртому элементу массива экземпляра "s" числа 72
    std::cout << *pointer; // Выводим значение на который указывает pointer - число 72

    StructWithArray memory; // Создаём экземпляр структуры StructWithArray
    memset(&memory, 0, sizeof(StructWithArray)); // При помощи функции "memset", заполняем все данные структуры нулями (Обнуляется)
    return 0;
}