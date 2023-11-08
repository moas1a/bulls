#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define N 4

int main()
{
    setlocale(LC_ALL, "Russian");

    char mech[N];

    srand(time(NULL));

    for (int i = 1; i < 15; i++)
        rand();

    int n = rand() % 9999;

    std::cout << "n= " << n << std::endl;

    for (int i = 0; i < N; i++)
  
    {
        mech[i] = n % 10;
        n = n / 10;

    }
    printf("***");
    for (int i = 0; i < N; i++)
        printf("%c", mech[i]);

   // for (int i = 1; i < 20; i++)
   // std::cout << rand()% 9999 << std::endl;
 

}
