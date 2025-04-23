#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nilai;
};

void swap(Mahasiswa &a, Mahasiswa &b) {
    Mahasiswa temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cin >> n;

    Mahasiswa data[100];

    for(int i = 0; i <= n; i++) {
        cin >> data[i].nama >> data[i].nilai;
    }

    for(int i = 0; i <= n - 1; i++) {
        for(int j = 0; j <= n - i - 1; j++) {
            if(data[j].nilai < data[j + 1].nilai) {
                swap(data[j], data[j + 1]);
            }
        }
    }

    for(int i = 0; i <= n; i++) {
        cout << data[i].nama << endl;
    }

    return 0;
}