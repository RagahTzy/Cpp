#include <iostream>
using namespace std;
class LuasBangun{
	int panjang, lebar;
	public:
		void setPanjang(int nilai){
			panjang = nilai;
		};
		void setLebar(int nilai){
			lebar = nilai;
		};
		
		int getLuasBangun(){
			return panjang * lebar;
		}	
};

main(){
 LuasBangun persegi1;
 
 int panjang, lebar;
 cout<<"Masukan nilai panjang : ";
 cin>>panjang;
 cout<<"Masukan nilai lebar : ";
 cin>>lebar;
 
 persegi1.setPanjang(panjang);
 persegi1.setLebar(lebar);
 
 cout<<"Luas persegi adalah : "<<persegi1.getLuasBangun();
 
}
