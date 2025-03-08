#include <iostream>

using namespace std;

int main(){
    int infinite = 0;
    while(infinite < 1){
        int x;
        cout << "masukkan panjang array yang anda inginkan" << endl;
        cin >> x;
        int arry[x];

        for(int i = 0; i < x; i++){
            arry[i] = i + 1;
        }

        cout << "nilai masing masing tiap index array adalah :" << endl;
        for(int i = 0; i < x; i++){
            cout << arry[i] << " ";
        }
        char jawaban;
        cout << endl << "apakah anda ingin melanjutkan program? (y/n)" << endl;
        cin >> jawaban;
        if(jawaban == 'y' || jawaban == 'Y'){
            continue;
        }else if (jawaban == 'n' || jawaban == 'N'){
            break;
        }else{break;}
    }
    return 0;
}