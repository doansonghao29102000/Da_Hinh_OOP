#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Sach
{
	protected:
	    string MaSach;
	    int DonGia;
	    int SoLuong;
	    string NhaXB;
	    long ThanhTien;
	public:
	    void virtual Nhap(){
    		   cout<<"Nhap Ma Sach:";
		   getline(cin,MaSach);
		   cout<<"Nhap Don Gia:";
		   cin>>DonGia;
		   cout<<"Nhap So Luong:";
		   cin>>SoLuong;
		   cin.ignore();
		   cout<<"Nhap Nha Xuat Ban:";
		   getline(cin,NhaXB);  
    	    }
    	    void virtual In(){
    	    	   cout<<MaSach<<"  "<<DonGia<<"  "<<SoLuong<<"  "<<NhaXB<<"  ";
    	    }
    	    long virtual Thanh_Tien()=0;
    	    int GetDonGia(){
    	    	  return DonGia;
    	    }
    	    bool virtual Getter(){
    	    }
    	    bool operator ==(string s){
    	    	   return NhaXB == s;
    	    }
};
class SachGiaoKhoa: public Sach
{
	private:
	    string TinhTrang;
      public:
          void Nhap(){
          	   Sach::Nhap();
          	   cout<<"Nhap Tinh Trang Cua Sach:";
          	   getline(cin,TinhTrang);
          }
          long Thanh_Tien(){
          	   if(TinhTrang == "cu") return(SoLuong*DonGia)/2;
          	   else return SoLuong*DonGia;
          }
          void In(){
          	   Sach::In();
          	   cout<<TinhTrang<<"  ";
          }
          bool Getter(){
          	   return false;
          }
};
class SachThamKhao: public Sach
{
	private:
	    int Thue;
      public:
          void Nhap(){
          	   Sach::Nhap();
          	   cout<<"Nhap Thue Cua Sach:";
          	   cin>>Thue;
          	   cin.ignore();
          }
          long Thanh_Tien(){
          	   return (SoLuong*DonGia + Thue);
          }
          void In(){
          	   Sach::In();
          	   cout<<Thue<<"  ";
          }
          bool Getter(){
          	   return true;
          }
};
class ThuVien
{
	private:
	    vector<Sach *> ds_Sach;
	    string s;
      public:
          void Input();
          void Output();
          void Output1();
          void Nhap();
          void Output2();
};
void ThuVien::Input()
{
	int luachon;
	while(true){
		system("cls");
		cout<<"===============MeMe============"<<endl;
		cout<<"1.Sach Giao Khoa"<<endl;
		cout<<"2.Sach Tham Khao"<<endl;
		cout<<"0.Thoat :))"<<endl;
		cout<<"=================END============"<<endl;
		cout<<"Nhap lua chon:";
		cin>>luachon;
		cin.ignore();
		Sach *x;
		if(luachon == 1){
			cout<<"Nhap Thong Tin Cho Sach Giao Khoa:"<<endl;
			x = new SachGiaoKhoa;
			x->Nhap();
			ds_Sach.push_back(x);
		}
		else if(luachon == 2){
			cout<<"Nhap Thong Tin Cho Sach Tham Khao:"<<endl;
			x = new SachThamKhao;
			x->Nhap();
			ds_Sach.push_back(x);
		}
		else if(luachon == 0){
			break;
		}
	}
}
void ThuVien::Output()
{
	cout<<"\n======THONG TIN CUA SACH TRONG THU VIEN======="<<endl;
	for(int i=0;i<ds_Sach.size();i++){
		cout<<"Thong Tin Danh Sach Thu "<<i+1<<endl;
		ds_Sach[i]->In();
		cout<<ds_Sach[i]->Thanh_Tien()<<endl;
	}
}
void ThuVien::Output1()
{
	int cnt = 0;
	int sum = 0;
	for(int i=0;i<ds_Sach.size();i++){
		if(ds_Sach[i]->Getter() == true){
			cnt++;
			sum = sum + ds_Sach[i]->GetDonGia();
		}
	}
	cout<<"\n\nTrung Binh Cong Don Gia Cua Cach Sach Tham Khao La: "<<float(sum)/cnt<<endl;
}
void ThuVien::Nhap()
{
	cout<<"\n\nNhap Nha Xuat Ban X:";
	getline(cin,s);
}
void ThuVien::Output2()
{
	cout<<"\n\n=====Danh Sach Sach Giao Khoa Co Nha Xuat Ban X====="<<endl;
	for(int i=0;i<ds_Sach.size();i++){
		if(ds_Sach[i]->Getter() == false)
			if(*ds_Sach[i] == s){
				ds_Sach[i]->In();
				cout<<ds_Sach[i]->Thanh_Tien()<<endl;
		}
	}
}
int main(){
	ThuVien *bibliateka = new ThuVien;
	bibliateka->Input();
	bibliateka->Output();
	bibliateka->Output1();
	bibliateka->Nhap();
	bibliateka->Output2();
	return 0;
}