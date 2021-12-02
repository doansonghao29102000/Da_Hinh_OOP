#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
class DichVu
{
	protected:
	    float dongia;
	public:
	    void virtual nhap(){
    		   cout<<"Nhap don gia cua dich vu:";
    		   cin>>dongia;
    	    }
	    void virtual in(){
    		   cout<<dongia<<"  ";
    	    }
	    float virtual tinhtien()=0; 
};
class Giat: public DichVu
{
	private:
	    float sokg;
	    float tiendvcongthem;
      public:
          void nhap(){
          	   DichVu::nhap();
          	   cout<<"Nhap so kg quan ao can giat:";
          	   cin>>sokg;
     	         cout<<"Nhap so tien dich vu cong them:";
          	   cin>>tiendvcongthem;
               cin.ignore();
          }
          void in(){
          	   DichVu::in();
          	   cout<<sokg<<"  "<<tiendvcongthem<<"  ";
          }
          float tinhtien(){
          	   if(sokg > 5) return (sokg*dongia + tiendvcongthem)*(float(95)/100);
          	   else return (sokg*dongia + tiendvcongthem);
          }	    
};
class ThueXe: public DichVu
{
	private:
	    float sogio;
      public:
          void nhap(){
          	   DichVu::nhap();
          	   cout<<"Nhap so gio thue xe:";
          	   cin>>sogio;
          	   cin.ignore();
          }
          void in(){
          	   DichVu::in();
          	   cout<<sogio<<"  ";
          }
          float tinhtien(){
          	   if(sogio > 10) return (sogio*dongia)*(float(9)/10);
          	   else return (sogio*dongia);
          }	    
};
class HoaDon
{
	private:
	    string maHD;
	    string maKH;
	    string TenKH;
	    int n;
	    float Tien;
      public:
          void Input();
          void Output();
};
void HoaDon::Input()
{
	cout<<"Nhap ma hoa don:";
	getline(cin,maHD);
	cout<<"Nhap ma khac hang:";
	getline(cin,maKH);
	cout<<"Nhap ten khac hang:";
	getline(cin,TenKH);
	cout<<"Nhap so lan cac dich vu ma khach hang dung:";
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"=======meme======="<<endl;
		cout<<"1.chon dich vu giat"<<endl;
		cout<<"2.chon dich vu thue xe"<<endl;
		cout<<"========end======="<<endl;
		int luachon;
		cout<<"Nhap lua chon:";cin>>luachon;
		DichVu *x;
		if(luachon == 1){
			x = new Giat;
			x->nhap();
			Tien = Tien + x->tinhtien();
		}
		if(luachon == 2){
			x = new ThueXe;
			x->nhap();
			Tien = Tien + x->tinhtien();
		}
	}
	
}

void HoaDon::Output()
{
	
      cout<<"THONG TIN HOA DON CUA KHAC HANG"<<endl;
	cout<<maHD<<"  "<<maKH<<"  "<<TenKH<<"   "<<n<<"  ";
	cout<<fixed<<setprecision(3)<<Tien<<endl;
}
int main(){
	HoaDon x;
	x.Input();
	x.Output();
	return 0;
}
