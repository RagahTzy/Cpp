#include <iostream>
using namespace std;

void bubbleSort(int arr[], int pjg) {
    for (int i = 0; i < pjg - 1; ++i) {
        for (int j = 0; j < pjg - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int pjg) {
    for (int i = 0; i < pjg - 1; ++i) {
        int idxMin = i;
        for (int j = i + 1; j < pjg; ++j) {
            if (arr[j] < arr[idxMin]) {
                idxMin = j;
            }
        }
        swap(arr[i], arr[idxMin]);
    }
}

void insertionSort(int arr[], int pjg) {
    for (int i = 1; i < pjg; ++i) {
        int kunci = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = kunci;
    }
}

void cetakArray(int arr[], int pjg) {
    for (int i = 0; i < pjg; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int pjg;
    cout << "Masukkan panjang array : ";
    cin >> pjg;

    int arr[pjg];
    cout << "Masukkan " << pjg << " elemen array: ";
    for (int i = 0; i < pjg; ++i) {
        cin >> arr[i];
    }

    cout << "Array sebelum sorting  : ";
    cetakArray(arr, pjg);

    int plhn;
    cout << "Pilih jenis sorting:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nPilihan: ";
    cin >> plhn;

    if (plhn == 1) {
        bubbleSort(arr, pjg);
    } else if (plhn == 2) {
        selectionSort(arr, pjg);
    } else if (plhn == 3) {
        insertionSort(arr, pjg);
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 1;
    }

    cout << "Array setelah sorting  : ";
    cetakArray(arr, pjg);

    return 0;
}
