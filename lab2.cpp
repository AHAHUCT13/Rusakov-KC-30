#include <time.h>
#include <iostream>
#include <time.h>

void Summarize(double** array1, double** array2, double* array3, int num);
void PrintAllArrays(double** array1,int num);
void PrintAllArrays(double* array1, int num);

int main()
{
    srand(time(0));

    int N;
    std::cout << std::endl << "Input N ";
    std::cin >> N;

    double** A = new double* [N];
    double** B = new double* [N];
    double* C = new double [N];

    for (int i = 0; i < N; i++) {
        A[i] = new double[N];
        B[i] = new double[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int key = rand() % 11;
            A[i][j] = (0 + rand() % 101) * 0.1;
            B[i][j] = (0 + rand() % 101) * 0.1;
        }
    }
    
    Summarize(A, B, C, N);
    PrintAllArrays(A, N);
    PrintAllArrays(B, N);
    PrintAllArrays(C, N);

    for (int i = 0; i < N; i++) {
        delete[] A[i];
        delete[] B[i];
    }
}

void Summarize(double** array1, double** array2, double* array3, int num)
{
    double cache1, cache2;
    for (int i = 0; i < num; i++) {
        cache1 = 0;
        cache2 = 0;
        for (int j = 0; j < num; j++) {
            cache1 += array1[i][j];
            cache2 += array2[i][j];
        }
        if (cache1 >= cache2) {
            array3[i] = cache1;
        }
        else {
            array3[i] = cache2;
        }
    }
}

void PrintAllArrays(double** array1, int num)
{
    std::cout << std::endl << "array:" << std::endl;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            std::cout << array1[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void PrintAllArrays(double* array1, int num)
{
    std::cout << std::endl << "array:" << std::endl;
    for (int j = 0; j < num; j++) {
        std::cout << array1[j] << " ";
    }
    std::cout << std::endl;
}
