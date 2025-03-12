#include <iostream>
#include <string>
using namespace std;

class Mobil{
    private:
        string namaMobil;
        string merkMobil;
        int hargaMobil;
    
    public:
        Mobil(string n, string m, int h){
            namaMobil = n;
            merkMobil = m;
            hargaMobil = h;
        }
        string getNama(){
            return namaMobil;
        }
        string getMerk(){
            return merkMobil;
        }
        float getHarga(){
            return hargaMobil;
        }
        void setNama(string n){
            namaMobil = n;
        }
        void setMerk(string p){
            merkMobil = p;
        }
        void setHarga(int i){
            if(i >= 0){
                hargaMobil = i;
            }else{
                cout << "harga mobil tidak mungkin minus" << endl;
            }
        }
        void tampilkaninfo(){
            cout << endl << "Data Mobil:" << endl;
            cout << "Nama Mobil: " << namaMobil << endl << "Merk Mobil: " << merkMobil << endl << "Harga Mobil: " << hargaMobil << endl;
        }

};

int main(){
    Mobil mobil1("Pajero Sport", "Mitsubishi", 500000000);
    mobil1.tampilkaninfo();

    mobil1.setNama("Civic RS");
    mobil1.setMerk("Honda");
    mobil1.setHarga(300000000);
    mobil1.tampilkaninfo();
    return 0;
}