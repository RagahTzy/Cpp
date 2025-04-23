#include <iostream>
using namespace std;

struct mhs {
    string nama;
    int nilai;
};

int main() {
    int jumlah;
    cin >> jumlah;

    mhs daftarMahasiswa[jumlah];

    for (int i = 0; i < jumlah; i++) {
        mhs mahasiswa;
        cin >> mahasiswa.nama;
        cin >> mahasiswa.nilai;
        daftarMahasiswa[i] = mahasiswa;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << daftarMahasiswa[i].nama << ": " << daftarMahasiswa[i].nilai << endl;
    }

    return 0;
}