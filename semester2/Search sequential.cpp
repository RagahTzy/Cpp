#include<iostream>  
using namespace std;  

main(){
 int data[5]{3,6,34,7,0};   // deklarasikan set data
 int nilai;                 // deklarasikan variable yang ingin dicari
 bool ditemukan = false;    // variable untuk menandakan ditemukan/tidaknya data
 
 // masukan nilai yang ingin dicari
 cout<<"Masukan nilai yang ingin dicari : ";
 cin>>nilai;
 
 // untuk masing masing data, cek apakah sesuai dengan yang ingin dicari
 for(int i=0; i<=5 ; i++){
 	// jika data sesuai, maka tampilkan data ditemukan
 	if(data[i] == nilai){
 		cout<<endl<<"Data ditemmukan pada array["<<i<<"]"<<endl;
 		// set variable bahwa data telah ditemukan
 		ditemukan= true;
 		// hentikan perulangan
 		break;
	 }
 }	
 
 // jika data tidak ditemnukan, maka tampilkan pesan
 if(!ditemukan){
 	cout<<endl<<"Maaf data tidak ditemukan.";
 }
}



