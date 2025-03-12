#include <iostream>
#include <string>
using namespace std;

class Mahasiswa{
    private:
        string nama;
        string npm;
        float ipk;
    
    public:
        Mahasiswa(string n, string p, float i){
            nama = n;
            npm = p;
            ipk = i;
        }
        string getNama(){
            return nama;
        }
        string getNPM(){
            return npm;
        }
        float getIPK(){
            return ipk;
        }
        void setNama(string n){
            nama = n;
        }
        void setNPM(string p){
            npm = p;
        }
        void setIPK(float i){
            if(i >= 0 && i <= 4){
                ipk = i;
            }else{
                cout << "IPK harus diantara 0 sampai 4" << endl;
            }
        }
        void tampilkaninfo(){
            cout << endl << "Data Mahasiswa:" << endl;
            cout << "Nama: " << nama << ", NPM: " << npm << ", IPK: " << ipk << endl;
        }

};

int main(){
    string nama, npm;
    float ipk;

    cout << "Masukkan nama: ";
    getline(cin, nama);
    cout << "Masukkan npm: ";
    cin >> npm;
    cout << "Masukkan ipk: ";
    cin >> ipk;

    Mahasiswa mhs1(nama, npm, ipk);
    mhs1.tampilkaninfo();

    return 0;
}