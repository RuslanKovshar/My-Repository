#include <iostream>
#include <thread>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

void setRandomNumbers(int **matrix, int height, int length)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            *(*(matrix + i) + j) = rand() % 99;
        }
    }
}

void printMatrix(int **matrix, int height, int length)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            cout << setw(5) << *(*(matrix + i) + j);
        }
        cout << endl;
    }
}

void Suma(int **matrix, vector<int> &sum, int length,int start,int end)
{
    for (int i = start; i < end; ++i)
    {
        //cout << this_thread::get_id() << endl;
        for (int j = 0; j < length; ++j)
        {
            sum[i] += *(*(matrix + i) + j);
        }
    }
}

int main()
{
    int length,height,ind;
    cout << "Enter height and length of matrix: " << endl;
    cin >> height >> length;
    int **matrix = new int*[height];
    for (int i = 0; i < height; ++i)
    {
        *(matrix + i) = new int[length];
    }
    setRandomNumbers(matrix,height,length);
    cout << "Show matrix? (0 - NO)" ;
    cin >> ind;
    if (ind)
    {
        printMatrix(matrix,height,length);
    }
    vector<int> sum((unsigned)height);
    clock_t start_time,end_time;

    start_time = clock();
    Suma(matrix,sum,length,0,height);
    end_time = clock();

    cout << "One thread search time = " << end_time - start_time << endl;
    cout << "Show vector? (0 - NO)" ;
    cin >> ind;
    if (ind)
    {
         for (int j = 0; j < height; ++j)
         {
            cout << sum[j] << endl;
         }
    }
    for (int j = 0; j < height; ++j)
    {
        sum[j] = 0;
    }

    start_time = clock();
    thread firstThread(Suma,matrix,ref(sum),length,0,height/2);
    Suma(matrix,sum,length,height/2,height);
    end_time = clock();

    firstThread.join();
    cout << "Two threads search time = " << end_time - start_time << endl;
    cout << "Show vector? (0 - NO)" ;
    cin >> ind;
    if (ind)
    {
        for (int j = 0; j < height; ++j)
        {
            cout << sum[j] << endl;
        }
    }

    return 0;
}