#include <iostream> 

bool binbus(int* ini, int* fin, int* &pos, int value) {
    while (ini <= fin) {
        int* mid = ini + (fin - ini) / 2;

        if (*mid == value) {
            pos = mid;
            return true;
        }
        if (value > *mid) {
            ini = mid + 1;
        } else {
            fin = mid - 1;
        }
    }

    pos = nullptr;
    return false;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12,13,14,15,16,17,18,19,20};
    int* pos;
    int value = 1;
    if (binbus(arr, arr + sizeof(arr)/sizeof(arr[0]), pos, value)) {
        std::cout << "Elemento encontrado en la posición: " << pos - arr << std::endl;
    } else {
        std::cout << "Elemento no encontrado" << std::endl;
    }
    return 0;
}

