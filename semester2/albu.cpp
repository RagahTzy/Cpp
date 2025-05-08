#include <iostream>
using namespace std;

void urutSelection(int data[], int ukuran) {
    for (int a = 0; a < ukuran - 1; ++a) {
        int posisiMin = a;
        for (int b = a + 1; b < ukuran; ++b) {
            if (data[b] < data[posisiMin]) {
                posisiMin = b;
            }
        }
        swap(data[a], data[posisiMin]);
    }
}

void urutInsertion(int data[], int ukuran) {
    for (int a = 1; a < ukuran; ++a) {
        int nilai = data[a];
        int b = a - 1;
        while (b >= 0 && data[b] > nilai) {
            data[b + 1] = data[b];
            --b;
        }
        data[b + 1] = nilai;
    }
}

void urutBubble(int data[], int ukuran) {
    for (int a = 0; a < ukuran - 1; ++a) {
        for (int b = 0; b < ukuran - a - 1; ++b) {
            if (data[b] > data[b + 1]) {
                swap(data[b], data[b + 1]);
            }
        }
    }
}

void tampilkanArray(int data[], int ukuran) {
    for (int a = 0; a < ukuran; ++a) {
        cout << data[a] << " ";
    }
    cout << endl;
}

int main() {
    int ukuran;
    cout << "Masukkan ukuran array: ";
    cin >> ukuran;

    int data[ukuran];
    cout << "Masukkan " << ukuran << " elemen array: ";
    for (int a = 0; a < ukuran; ++a) {
        cin >> data[a];
    }

    cout << "Array sebelum disorting: ";
    tampilkanArray(data, ukuran);

    int opsi;
    cout << "Pilih metode sorting:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nPilihan: ";
    cin >> opsi;

    if (opsi == 1) {
        urutBubble(data, ukuran);
    } else if (opsi == 2) {
        urutSelection(data, ukuran);
    } else if (opsi == 3) {
        urutInsertion(data, ukuran);
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 1;
    }

    cout << "Array setelah disorting: ";
    tampilkanArray(data, ukuran);

    return 0;
}