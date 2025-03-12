#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string npm;
    float ipk;
};

int main(){
    Mahasiswa mhs = {
        "Ragah Mujahidin",
        "123456789",
        3.75
    };
    cout << "Nama: " << mhs.nama << endl;
    cout << "NPM: " << mhs.npm << endl;
    cout << "IPK: " << mhs.ipk << endl;
    return 0;
}