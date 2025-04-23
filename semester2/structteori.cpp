#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul;
    string penulis;
    int tahunTerbit;
};

void inputBuku(Buku& buku) {
    cout << "Masukkan judul buku: ";
    getline(cin, buku.judul);
    cout << "Masukkan penulis buku: ";
    getline(cin, buku.penulis);
    cout << "Masukkan tahun terbit: ";
    cin >> buku.tahunTerbit;
    cin.ignore();
}

void tampilkanBuku(const Buku& buku) {
    cout << "\nInformasi Buku:" << endl;
    cout << "Judul       : " << buku.judul << endl;
    cout << "Penulis     : " << buku.penulis << endl;
    cout << "Tahun Terbit: " << buku.tahunTerbit << endl;
}

int main() {
    Buku buku;

    inputBuku(buku);

    tampilkanBuku(buku);

    return 0;
}
