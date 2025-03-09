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
    
    void setNama(string n) {
        nama = n;
    }
    
    void setNPM(string p) {
        npm = p;
    }
    
    void setIPK(float i) {
        if (i >= 0 && i <= 4) {
            ipk = i;
        } else {
            cout << "IPK tidak sesuai" << endl;
        }
    }
    
    string cekNilaiMutu() {
        if (ipk >= 3.5) {
            return "cumlaude";
        } else if (ipk > 3.0 && ipk < 3.5) {
            return "sangat baik";
        } else if (ipk >= 2.5 && ipk <= 3.0) {
            return "baik";
        } else {
            return "cukup";
        }
    }
    
    void tampilkanData() {
        cout << "\nInformasi Mahasiswa:\n";
        cout << "Nama: " << nama << " | NPM: " << npm << " | IPK: " << ipk;
        cout << " | Nilai Mutu: " << cekNilaiMutu() << endl;
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
