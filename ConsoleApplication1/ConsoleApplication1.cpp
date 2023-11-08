#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define N 4

// напечетать число (которое в массиве)
void print_ar(char ar[], int n)
{
    for (int i = 0; i < n; i++)
         printf("%c", ar[i]);
}


// Распихиваем цифры из числа value в массив ar
void Move2Array(int value, char ar[], int n)
{
    for (int i = N - 1; i >= 0; i--)
    {
        ar[i] = '0' + value % 10;
        value = value / 10;
    }
}
// генерируем число и записываем в массив
void rand_4(char ar[], int n)
{
    Move2Array(rand() % 9999, ar, n);
}

//создаем цикл для сравнивания одинаковых чисел
bool SameDigits(char ar[], int n)
{
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)  
        {
            if (ar[i] == ar[j])
                count++;
        }

    return (count != 0);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char mech[N];
    char ours[N];

    int raz = 0;

    // инициализация ГСЧ
    srand(time(NULL));
    for (int i = 1; i < 15; i++)
        rand();
    // **********

  // повторяем пока не будет сгенерировано число с разными цифрами
    do {
        rand_4(mech, N);
    } while (SameDigits(mech, N)); //генерируем число, проверяем нет ли одинаковых цифр тогда печатаем

    // print_ar(mech, N); //выводит ответ на экран
   //  printf("\n");

    int nOurs;

    int bools = 0; // быки
    int cows = 0;  // коровы


    do {
        //Заставляем пользователя ввести целое число из N различных цифр от 123 до 9876
        // 0 означает конец игры

    std::cout << "Введите число из " << N << " цифр";
    std::cin >>  nOurs;
    if (nOurs == 0)
    {
        std::cout << "Вам надоело играть!";
        break;
    }
    if (nOurs > 9876)
    {
        std::cout << "Вы ввели слишком большое число \n";
        continue;
    }
    if (nOurs < 123)
    {
        std::cout << "Вы ввели слишком маленькое число \n";
        continue;
    }

  
    // запихиваем введенное число в массив ours[]
        Move2Array(nOurs, ours, N);

        if (SameDigits(ours,N))
        {
            std::cout << "Нельзя вводить одинаковые цифры!";
            continue;
        }

        // пользователь ввел число 
        // которое удовлетворяет всем нашим условиям

        raz++; // количество попыток угадывания числа

        // считаем быков и коров
        bools = 0; // быки
        cows = 0;  // коровы
        for (int i = 0; i < N; i++)
        {
            if (mech[i] == ours[i])
                bools++;
            for (int j = 0; j < N; j++)
                if (mech[i] == ours[j])
                    cows++;
        }
        cows -= bools;


        std::cout << "Попытка №: " << raz << "Быков " << bools << "; Коров " << cows << std::endl;


        // если не угадали - переходим к запросу следующего числа у пользователя
 } while (bools != 4);

}