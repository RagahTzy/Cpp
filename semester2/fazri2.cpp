#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;
    string npm;
    float ipk;

public:
    
    Mahasiswa(string a, string n, float f) {
        nama = a;
        npm = n;
        ipk = f;
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

    void setNama(string a) {
        nama = a;
    }

    void setNPM(string n) {
        npm = n;
    }

    void setIPK(float a) {
   
        if (a >= 0 && a <= 4) {
            ipk = a; 
        } else {
            cout << "IPK tidak valid, harus antara 0 dan 4." << endl;
        }
    }


    void tampilkaninfo() {
        cout << "Nama: " << nama << ", NPM: " << npm << ", IPK: " << ipk << endl;
       
        if (ipk > 3.5) {
            cout << "Cumlaude" << endl;
        } else if (ipk >= 3.0 && ipk <= 3.5) {
            cout << "Sangat baik" << endl;
        } else if (ipk >= 2.5 && ipk < 3.0) {
            cout << "Baik" << endl;
        } else if (ipk >= 0 && ipk < 2.5) {
            cout << "Cukup" << endl;
        } else {
            cout << "IPK tidak tidak bagus" << endl;
        }
    }
};

int main() {
    string nama, npm;
    float ipk;

    cout << "Masukkan nama: ";
    cin >> nama;
    cout << "Masukkan npm: ";
    cin >> npm;
    cout << "Masukkan ipk: ";
    cin >> ipk;

 
    Mahasiswa mhs1(nama, npm, ipk);
    mhs1.tampilkaninfo();

    return 0;
}
