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

// генерируем число и записываем в массив
void rand_4(char ar[], int n)
{
    int k = rand() % 9999;
//  std::cout << "k= " << k << std::endl;

    for (int i = N - 1; i >= 0; i--)
    {
        ar[i] = '0' + k % 10;
        k = k / 10;
    }
}

bool SameDigits(char ar[], int n)//создаем цикл для сравнивания одинаковых чисел
{
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)  
        {
            if (ar[i] == ar[j])
                count++;
        }

    return (count != 0);
  //  std::cout << std::endl << "count = " << count << std::endl;
}


    int main()
    {
        setlocale(LC_ALL, "Russian");

        char mech[N];

        // инициализация ГСЧ
        srand(time(NULL));
        for (int i = 1; i < 15; i++)
            rand();
        // **********
            
        // повторяем пока не будет сгенерировано число с разными цифрами
        do {
            rand_4(mech, N);
            print_ar(mech, N);
            printf("\n");
        } while (SameDigits(mech, N)); //генерируем число, проверяем нет ли одинаковых цифр тогда печатаем
                                       // если есть одинаковые цифры,цикл повторяется
  //    printf("***");
        print_ar(mech, N);
      

}

