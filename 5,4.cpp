// Лабораторна робота № 5.4
// Варіант 26

#include <iostream>
#include <cmath>

using namespace std;

double f(const int j)
{
    return sqrt(1.0 * j * j / (1 + exp(-j)));
}

// Ітераційний спосіб
double S0(const int K, const int N)
{
    double s = 1;
    for (int i = K; i <= N; i++)
        s *= f(i);
    return s;
}

// Рекурсивний спуск, параметр зростає
double S1(const int K, const int N, const int i)
{
    if (i > N)
        return 1;
    else
        return f(i) * S1(K, N, i + 1);
}

// Рекурсивний спуск, параметр спадає
double S2(const int K, const int N, const int i)
{
    if (i < K)
        return 1;
    else
        return f(i) * S2(K, N, i - 1);
}

// Рекурсивний підйом, параметр зростає
double S3(const int K, const int N, const int i, double t)
{
    t *= f(i);
    if (i >= N)
        return t;
    else
        return S3(K, N, i + 1, t);
}

// Рекурсивний підйом, параметр спадає
double S4(const int K, const int N, const int i, double t)
{
    t *= f(i);
    if (i <= K)
        return t;
    else
        return S4(K, N, i - 1, t);
}

int main()
{
    const int K = 1;
    const int N = 15;

    cout << "(iter)        S0 = " << S0(K, N) << endl;
    cout << "(rec down ++) S1 = " << S1(K, N, K) << endl;
    cout << "(rec down --) S2 = " << S2(K, N, N) << endl;
    cout << "(rec up ++)   S3 = " << S3(K, N, K, 1) << endl;
    cout << "(rec up --)   S4 = " << S4(K, N, N, 1) << endl;

    return 0;
}