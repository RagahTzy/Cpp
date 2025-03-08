#include <iostream>
using namespace std;

int main(){
	int arr[] = {11,8,2,4,5,7,9,3,1,15};
	int n = sizeof(arr)/sizeof(int);
	int key, start = 0, finish = n;
	
	//Variabel pengecekan apakah nilai yang di check ada di dalam database atau tidak
	bool ada = false;
	
	cout << "Masukkan nilai yang akan dicari : ";
	cin >> key;
	
	//Memunculkan seluruh data sebelum diurutkan
	cout << endl << "Data awal anda adalah : " << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl << endl;

//	Linear search
//	for(int i = 0; i < n; i++){
//		if(arr[i]==key){
//			cout << "data anda ada pada indeks ke : " << i << endl;
//			ada = true;
//			break;
//		}
//	}
//
//	if(ada != true){
//		cout << "angka tidak ditemukan" << endl;
//	}

	//Mengurutkan nilai data mulai dari terkecil hingga terbesar
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	//Mencetak seluruh data setelah diurutkan
	cout << "Data anda setelah diurutkan : " << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	
	cout << endl << endl;
	
	//Binary search
	while(start <= finish){
		int mid = (start+finish)/2;
		if(arr[mid] == key){
			cout << "Data anda ada pada indeks ke : " << mid << endl;
			ada = true;
			break;
		}else if(key > arr[mid]){
			start = mid + 1;
		}else{
			finish = mid - 1;
		}
	}
	
	if(ada != true){
		cout << "Angka tidak ditemukan" << endl;
	}
	return 0;
}
