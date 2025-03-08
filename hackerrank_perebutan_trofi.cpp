#include <iostream>
using namespace std;


int main() {
    int j1, j2, j3, m1, m2, m3, d1, d2, d3, selisih1, selisih2, selisihakhir;
    cin >> j1 >> m1 >> d1;
    cin >> j2 >> m2 >> d2;
    
    selisih1 = j1 * 3600 + m1 * 60 + d1;
    selisih2 = j2 * 3600 + m2 * 60 + d2;
    
    if(selisih1 > selisih2){
        selisihakhir = selisih1 - selisih2;
    }else{selisihakhir = selisih2 - selisih1;}
    
    j3 = selisihakhir / 3600;
    selisihakhir %= 3600;
    m3 = selisihakhir / 60;
    d3 = selisihakhir % 60;
    
    cout << j3 << " " << m3 << " " << d3 << endl;
    return 0;
}
