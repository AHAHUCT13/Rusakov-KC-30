#include <iostream>
#include <ctime>
using namespace std;

#define N 10
int main()
{
    int array[N][N];
    int summTop;
    int summBot;
    srand(time(0));
    int i = 0;
    int j = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            array[i][j] = rand() % 11;
            cout << array[i][j]<< " ";
        }
        cout << endl;
    }
    cout << endl;
    summTop = 0;
    summBot = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i < j) {
                summTop += array[i][j];
            }
            if (i > j) {
                summBot += array[i][j];
            }
        }
    }
    cout << endl;
    cout << "Summ top = " << summTop << endl;
    cout << "Summ bot = " << summBot << endl;
    if (summTop < summBot) {
        cout << summTop << " < " << summBot;
    }
    else {
        if (summTop > summBot) {
            cout << summTop << " > " << summBot;
        }
        else {
            cout << summTop << " = " << summBot;
        }
    }
}