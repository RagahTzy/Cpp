#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;
    string npm;
    float ipk;

public:
Mahasiswa(string p, string q, float ip) {
    nama = p;
    npm = q;
    ipk = ip;
    }
    
string getNama() {
    return nama;
    }
string getNPM() {
    return npm;
    }
float getIPK() {
    return ipk;
    }
void setNama(string p) {
    nama = p;
    }
void setNPM(string q) {
    npm = q;
    }
void setIPK(float i) {
    if (i >= 0 && i <= 4) {
        ipk = i;
    } else {
    cout << "IPK tidak sesuai" << endl;
        }
    }
    
void tampilkanData() {
    cout << "\nInformasi Mahasiswa:\n";
    cout << "Nama: " << nama << " | NPM: " << npm << " | IPK: " << ipk << endl;
    }
};

int main() {
    string nama, npm;
    float ipk;

    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin, nama);
    cout << "Masukkan NPM: ";
    cin >> npm;
    cout << "Masukkan IPK: ";
    cin >> ipk;

    Mahasiswa mahasiswa(nama, npm, ipk);
    mahasiswa.tampilkanData();

    return 0;
}
