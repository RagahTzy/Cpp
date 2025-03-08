#include <iostream>

using namespace std;

int main(){
	
	int usiawarga[] = {18, 20, 15, 19, 14};
	
	int size = sizeof(usiawarga) / sizeof (int);
	
	for (int i = 0; i < size; i++){
		cout << usiawarga[i] << " ";
	}
	
	/*
	int matrix[3][3] = {{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}};
						
	int baris = sizeof(matrix) / sizeof(matrix[0]);
	int kolom = sizeof(matrix[0]) / sizeof(int);
	
	for (int i = 0; i < baris; i++){
		for (int j = 0; j <kolom; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	*/
	/*
	int jumlahsiswa = 6;
	int nilai[jumlahsiswa];
	int total = 0;
	
	for(int i=0; i < jumlahsiswa; i++){
		cout << "Masukkan nilai untuk siswa " << i + 1 << ": ";
		cin >> nilai[i];
		total += nilai[i];
	}
	
	double ratarata = total/jumlahsiswa;
	cout << "\nNilai rata-rata kelas : " << ratarata << endl;
	
	for(int i= 0; i <jumlahsiswa -1; i++){
		for(int j = 0; j < jumlahsiswa - i - 1; j++){
			if(nilai[j] >nilai[j + 1]){
				int temp = nilai[j];
				nilai[j] = nilai [j+1];
				nilai[j+1] = temp;
			}
		}
	}
	
	cout << "\nNilai siswa setelah diurutkan dari yang terendah ke tertinggi : ";
	for(int k = 0; k < jumlahsiswa; k++){
		cout << nilai[k] << " ";
	}
	*/
	return 0;
}
