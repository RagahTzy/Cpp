#include <iostream>
using namespace std;

class Mahasiswa{
    private:
        string Nama;
        string NPM;
        float IPK;
    
public:
    Mahasiswa(string n, string m, float k){
        Nama = n;
        NPM  = m;
        IPK  = k;
    }
    string get_Nama(){
    return Nama;
    }
    string get_NPM(){
    return NPM;
    }

    float get_IPK(){
    return IPK;
    }
    void set_NAMA(string n){
    Nama = n;
    }
    void set_NPM(string m){
    NPM = m;
    }

 void setIPK(float k){
            if(k >= 0 && k <= 4){
                IPK = k;
            }else{
                cout << "IPK tidak sesuai" << endl;
            }

    }

    void tampilkanInfo(){
    cout << "Nama: " << Nama << ", NPM: " << NPM << ", IPK: " << IPK << endl;
      if(IPK  >3.5){
            cout<<"Cumlaude";
        }else if(IPK >= 3.0 && IPK <=3.5){
            cout<< "Sangat baik";
        }else if ( IPK >= 2.5 && IPK <=3.0){
            cout<< "Baik"; 
        }else if ( IPK <=2.5){
            cout<< "Cukup";
        }else{
            cout<< "ipk anda kurang baik";
        }}

};

int main(){
    string Nama, NPM;
    float IPK;

    cout << "Masukkan Nama: ";
    cin>> Nama ;
    cout << "Masukkan NPM: ";
    cin >> NPM;
    cout << "Masukkan IPK: ";
    cin >> IPK;

    Mahasiswa mhs1(Nama, NPM, IPK);
    mhs1.tampilkanInfo();

    return 0;
}