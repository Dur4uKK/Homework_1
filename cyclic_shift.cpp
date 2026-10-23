#include <iostream>

void reverse(int* arr, int l, int r) {
    while (l < r) {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}

int main(int cnt, char* vctr[]) {
    if (cnt != 2) {
        return 1;
    }

    int n = 0;

    for (int i = 0; vctr[1][i] != '\0'; i++) {
        if (vctr[1][i] < '0' || vctr[1][i] > '9') {
            return 1;
        }
        n = n * 10 + vctr[1][i] - '0';
    }

    if (n <= 0) {
        return 1;
    }

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        if (!(std::cin >> arr[i])) {
            delete[] arr;
            return 1;
        }
    }

    long long k;

    if (!(std::cin >> k)) {
        delete[] arr;
        return 1;
    }

    int shift = k % n;

    if (shift < 0) {
        shift += n;
    }

    reverse(arr, 0, n - 1);
    reverse(arr, 0, shift - 1);
    reverse(arr, shift, n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << arr[i];
    }

    std::cout << std::endl;

    delete[] arr;

    return 0;
}