#include <iostream>

using namespace std;

int main(){
	
	int arry[4][4];
	int terbesar;
	
	for(int i=0; i < 4; i++){
		for(int j=0; j < 4; j++){
			cout << "Masukkan angka pada indeks [" << i << "][" << j << "] : " ;
			cin >> arry[i][j];
		}
	}
	
	terbesar = arry[0][0];
	
	for(int i=0; i < 4; i++){
		for(int j=0; j < 4; j++){
			if(arry[i][j] > terbesar){
			terbesar = arry[i][j];	
			}
		}
	}
	
	cout << endl << "Angka terbesar pada array adalah : " << terbesar;
	
	return 0;
}
