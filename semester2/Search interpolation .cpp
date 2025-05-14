#include<iostream>
using namespace std;

int interpolationSearch(int data[], int low, int high, int ds) {
	
   while(low <= high && ds >= data[low] && ds <= data[high]) {
   	  int up = (ds - data[low]) * (high - low);
   	  int down = (data[high] - data[low]);
      int pos = low + (up / down);
	
//	  cout<<"ds ["<<ds<<"]"<<endl;	
//	  cout<<"low["<<low<<"]"<<endl;	
//	  cout<<"dataLow["<<data[low]<<"]"<<endl;	
//	  cout<<"high["<<high<<"]"<<endl;	
//	  cout<<"dataHigh["<<data[high]<<"]"<<endl;
//	  cout<<"pos["<<pos<<"]"<<endl;	  
		
      if(data[pos] == ds){
      	return pos;
	  }
	  
	  if(data[pos] < ds){
	  	low = low + 1;
	  }else{
	  	high = pos -1;
	  }
   }
   return -1;
}

main() {   
   // dataset
   int data[20]{1,3,7,10,14,15,16,18,20,21,22,23,25,33,35,42,45,47,50,52};
   // variable yang dibutuhkan
   int n, ds, loc;
   char ulangi = 'y';
   while(ulangi == 'y'||ulangi =='Y'){
   	   system("cls");
	   for(int i = 0; i<20; i++) {
	      cout<<data[i]<<"\t";
	   }
	   cout<<endl<<endl<<"Masukan data yang ingin dicari : ";
	   cin>>ds;
	   if((loc = interpolationSearch(data, 0, 20-1, ds)) >= 0)
	      cout <<endl<<endl<< "data ditemukan pada array ke : " << loc << endl;
	   else
	      cout <<endl<<endl<< "Maaf, data tidak ditemukan." << endl;
	      
	  cout<<"--------------------------------------------------------"<<endl;    
	  cout<<"Ulangi [Y/N] :";
	  cin>>ulangi;
  }
   getchar();
}
