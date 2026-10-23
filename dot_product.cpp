#include <iostream>

int main(int cnt, char* vctr[])
{
    if (cnt != 2) {return 1;}
    int n = 0;

    for (int i = 0; vctr[1][i] != '\0'; i++)
    {
        if (vctr[1][i] < '0' || vctr[1][i] > '9') {return 1;}
        n = n * 10 + vctr[1][i] - '0';
    }

    if (n <= 0) {return 1;}
    double* arr = new double[n];

    for (int i = 0; i < n; i++)
    {
        if (!(std::cin >> arr[i])) {delete[] arr; return 1;}
    }

    double res = 0;
    double x;

    for (int i = 0; i < n; i++)
    {
        if (!(std::cin >> x)) {delete[] arr; return 1;}
        res += arr[i] * x;
    }

    std::cout << res << std::endl;

    delete[] arr;

    return 0;
}