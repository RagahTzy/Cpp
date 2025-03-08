#include <iostream>

using namespace std;

int main(){
	
	int harga_beli, harga_jual, jumlah_stok, jumlah_barang, total_nilai = 0, total_modal = 0, total_untung = 0;
	string nama_barang;
	
	cout << "Masukkan jumlah barang : "; cin >>jumlah_barang;
	
	for(int i = 1; i <= jumlah_barang; i++){
		cout << endl << "Masukkan nama barang : ";
		cin >> nama_barang;
		cout << "Masukkan harga pembelian barang per unit nya : ";
		cin >> harga_beli;
		cout << "Masukkan harga jual barang per unit nya : ";
		cin >> harga_jual;
		cout << "Masukkan jumlah stok barang nya : ";
		cin >> jumlah_stok;
		
		total_nilai += harga_beli * jumlah_stok;
		total_modal += harga_beli * jumlah_stok;
		total_untung += (harga_jual - harga_beli) * jumlah_stok;
		
		cout << endl;
	}
	
	cout << endl << "Total nilai keseluruhan barang yang ada di toko : " << total_nilai << endl;
	cout << "Total modal yang dikeluarkan : " << total_modal << endl;
	cout << "Total keuntungan dari keseluruhan barang : " << total_untung << endl;
	
	return 0;
}
