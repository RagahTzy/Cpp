#include <iostream>
using namespace std;


int main() {
    double suhu, hasil;
    string satuan;
    cin >> suhu >> satuan;
    if(satuan == "r" || satuan == "R"){
        hasil = suhu * 4 / 5;
    }else if(satuan == "f" || satuan == "F"){
        hasil = suhu * 9 / 5;
    }else if(satuan == "k" || satuan == "K"){
        hasil = suhu + 273;
    }
    cout << hasil << " " << satuan;
    return 0;
}
