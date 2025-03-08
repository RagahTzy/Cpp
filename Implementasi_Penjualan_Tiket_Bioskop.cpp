#include <iostream>

using namespace std;

int main(){
	
	int jumlah_pelanggan, umur, jumlah_tiket, harga_tiket, total_bayar, total_jual = 0;
	string nama;
	
	cout << "Masukkan jumlah pelanggan : ";
	cin >> jumlah_pelanggan;
	for(int i = 1; i <= jumlah_pelanggan; i++){
		cout << endl << "Masukkan nama pelanggan : ";
		cin >> nama;
		cout << "Masukkan umur pelanggan : ";
		cin >> umur;
		cout << "Masukkan jumlah tiket yang ingin dibeli : ";
		cin >> jumlah_tiket;
		
		if(umur >= 18){
			harga_tiket = 50000;
		}else{
			harga_tiket = 30000;
		}
		total_bayar = jumlah_tiket * harga_tiket;
		cout << "Total pembayaran dari pelanggan " << nama << " adalah : " << total_bayar;
		total_jual += total_bayar;
		cout << endl;
	}
	cout << endl << "Total Penjualan adalah : " << total_jual;
		
	return 0;
}
