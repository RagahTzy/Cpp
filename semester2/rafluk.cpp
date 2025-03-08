#include <iostream>
using namespace std;
class Mahasiswa{
      private:
      string nama;
      string npm;
      float ipk;
    
 public:
        Mahasiswa(string r, string d, float m){
                 nama = r;
                 npm = d;
                 ipk = m;
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
        void setNama(string r){
                nama = r;
        }
        void setNPM(string d){
                npm = d;
        }
        void setIPK(float r){
        if(ipk >= 0 && ipk <= 4){
        ipk = ipk;
        }else{
                cout << "IPK mu berbahaya" << endl;
            }
        }
        void tampilkaninfo(){
                cout << "Nama: " << nama << ", NPM: " << npm << ", IPK: " << ipk << endl;
        }

};

int main(){
string nama, npm;
    float ipk;

cout << "Masukkan nama: ";
         cin>> nama;
cout << "Masukkan npm: ";
         cin >> npm;
cout << "Masukkan ipk: ";
         cin >> ipk;

Mahasiswa mhs1(nama, npm, ipk);
         mhs1.tampilkaninfo();

    return 0;
}