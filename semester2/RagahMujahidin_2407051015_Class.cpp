#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
    long long nim;
    string nama;
    string jurusan;
public:
    //Setter
    void setNim(long long n) { nim = n; }
    void setNama(string nm) { nama = nm; }
    void setJurusan(string jur) { jurusan = jur; }
    //Getter
    long long getNim() const { return nim; }
    string getNama() const { return nama; }
    string getJurusan() const { return jurusan; }
};

int main(){
    cout << "CLASSTEORI" << endl;
    Mahasiswa database[100];
    int jumlah = 0;
    char lanjut;
    do {
        Mahasiswa mhs;
        long long nim;
        string nama, jurusan;
        cout << "Masukkan NIM (12 digit): ";
        cin >> nim;
        cin.ignore(); // agar getline bisa dipakai kembali
        cout << "Masukkan Nama (maks 32 karakter): ";
        getline(cin, nama);
        cout << "Masukkan Jurusan (maks 32 karakter): ";
        getline(cin, jurusan);
        mhs.setNim(nim);
        mhs.setNama(nama);
        mhs.setJurusan(jurusan);
        //dibatesin hanya 100 data, kalo lebih dari itu mah kebanyakan
        //lagian 100 geh keknya dah banyak, anak MI cuman ada 28
        if (jumlah < 100) {
            database[jumlah] = mhs;
            jumlah++;
        } else {
            cout << "Database penuh!\n";
            break;
        }
        cout << "Apakah ingin memasukkan data lagi? (y/n): ";
        cin >> lanjut;
        cin.ignore();
    } while (lanjut == 'y' || lanjut == 'Y');
    cout << "\nData Mahasiswa yang telah diinputkan:\n";
    for (int i = 0; i < jumlah; ++i) {
        cout << "Mahasiswa ke-" << i+1 << ":\n";
        cout << "NIM     : " << database[i].getNim() << endl;
        cout << "Nama    : " << database[i].getNama() << endl;
        cout << "Jurusan : " << database[i].getJurusan() << endl;
        cout << endl;
    }
    return 0;
}