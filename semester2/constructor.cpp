#include <iostream>
using namespace std;

class PersegiPanjang {
	public :
		int panjang, lebar;
	PersegiPanjang(int p, int l){
		panjang = p;
		lebar = l;
	};
	int getLuas(){
		return panjang * lebar;
	};
	
	~PersegiPanjang(){
		cout<<"\n PersegiPanjang memmory released";
	};
};

main(){
	int p, l;
	cout<<"Masukan Nilai Panjang \t: ";
	cin>>p;
	cout<<"Masikan Nilai Lebar \t: ";
	cin>>l;
	
	PersegiPanjang pPanjang(p, l);
	cout<<"Hasilnya adalah : "<< pPanjang.getLuas();
	getchar();
		
}
