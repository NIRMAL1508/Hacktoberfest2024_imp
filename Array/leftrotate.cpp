#include <iostream>

class ArrayShift {
private:
    int *arr;
    int size;

public:
    ArrayShift(int *inputArr, int inputSize) {
        size = inputSize;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = inputArr[i];
        }
    }

    void leftShift(int k) {
        k = k % size;  // adjust k if it exceeds the array size
        int *temp = new int[k];
        for (int i = 0; i < k; i++) {
            temp[i] = arr[i];
        }

        for (int i = k; i < size; i++) {
            arr[i - k] = arr[i];
        }

        for (int i = size - k; i < size; i++) {
            arr[i] = temp[i - (size - k)];
        }

        delete[] temp;
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~ArrayShift() {
        delete[] arr;
    }
};

int main() {
    int inputArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(inputArr) / sizeof(inputArr[0]);

    ArrayShift array(inputArr, size);

    int k = 3;
    std::cout << "Original Array: ";
    array.printArray();

    array.leftShift(k);

    std::cout << "Array after left shift by " << k << " positions: ";
    array.printArray();

    return 0;
}
