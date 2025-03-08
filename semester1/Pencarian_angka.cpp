#include <iostream>

using namespace std;

int main(){
	bool infinite = true;
	int arry[4][4];
	int cari;
	bool ditemukan = false;
	
	for(int i=0; i < 4; i++){
		for(int j=0; j < 4; j++){
			cout << "Masukkan angka pada indeks [" << i << "][" << j << "] : " ;
			cin >> arry[i][j];
		}
	}
	
	while(infinite == true){
		cout << endl << "Masukkan angka yang ingin anda cari dalam array : ";
		cin >> cari;
		for(int i=0; i < 4; i++){
			for(int j=0; j < 4; j++){
				if(cari == arry[i][j]){
					cout << "Angka yang anda cari ada pada indeks [" << i << "][" << j << "]" << endl;
					ditemukan = true;
					infinite = false;
				}
			}
		}
		
		if(ditemukan == false){
			cout << "Angka yang ingin anda cari tidak ada dalam array" << endl;
		}
	}
	
	return 0;
}
