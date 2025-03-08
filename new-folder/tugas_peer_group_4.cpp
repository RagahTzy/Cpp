#include <iostream>
using namespace std;

int main(){
	char jawaban;
	int infinite=0;
	while(infinite <= 0){
		int x, n, key;
		int iterasilinear = 1;
		int iterasibinary = 1;
		bool ada = false;
		
		cout << "Tuliskan jumlah data yang ingin dimasukkan : ";
		cin >> x;
		int arry[x];
		for(int i = 0; i < x; i++){
			arry[i] = i + 1;
		}
		
		cout << endl << "Angka berapa yang ingin anda panggil?" << endl;
		cin >> key;
		
		for(int i = 0; i < x; i++){
			if(arry[i] == key){
				cout << endl << "Angka " << key << " ada di indeks ke : " << i << endl;
				cout << "Butuh " << iterasilinear << " iterasi jika menggunakan linear search" << endl;
				ada = true;
			}
			iterasilinear += 1;
		}
		
		int start = 0;
		int finish = x - 1;
		
		while(start <= finish){
			int mid = (start + finish) / 2;
			if(arry[mid] == key){
				cout << "Dan butuh " << iterasibinary << " iterasi jika menggunakan binary search" << endl << endl;
				ada = true;
				break;
			}else if(key > arry[mid]){
				start = mid + 1;
			}else{
				finish = mid - 1;
			}
			iterasibinary += 1;
		}
		
		if(ada != true){
			cout << endl << endl << "Angka yang anda panggil tidak ada di database" << endl << endl;
		}
		cout << "Apakah ingin melanjutkan program? (y/n)" << endl;
		cin >> jawaban;
		if(jawaban == 'n' || jawaban == 'N'){
			break;
		}else  if(jawaban == 'y' || jawaban == 'Y'){
			cout << endl << endl;
			continue;
		}else{
			cout << "Hanya masukkan huruf Y/N saja" << endl;
			break;
		}
	}
	return 0;
}
