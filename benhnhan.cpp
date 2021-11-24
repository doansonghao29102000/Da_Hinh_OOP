#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BenhNhan
{
	protected:
          string mahs;
          string hoten;
          int ngaysinh;
          string chuandoanbenh;
          bool KT;
      public:
          void virtual nhap(){
  	         cout<<"Nhap ma ho so:";
          	   getline(cin,mahs);
          	   cout<<"Nhap ho ten:";
          	   getline(cin,hoten);
          	   cout<<"Nhap ngay sinh:";
          	   cin>>ngaysinh;
          	   cin.ignore();
          	   cout<<"Nhap ten benh:";
          	   getline(cin,chuandoanbenh);
          	   
          }
          void virtual in(){
          	   cout<<mahs<<"  "<<hoten<<"  "<<ngaysinh<<"  "<<chuandoanbenh<<"  ";
          }
          bool virtual getter()=0;
          int virtual Getter(){
          	
          }
          /*
//cap nhat du lieu
          bool Setter_KT(bool kt){
          	   KT = kt;
          }
          //in ra du lieu
          bool Getter_KT(){
     	         return KT;
          }*/
};
class NoiChu: public BenhNhan
{
	private:
	    string ngaynhapvien;
	    string ngayravien;
	    string tenkhoa;
	    string soduong;
      public:
          void nhap(){ 
	         BenhNhan::nhap();
		   cout<<"Nhap ngay nhap vien:"; 
		   getline(cin,ngaynhapvien);
		   cout<<"Nhap ngay ra vien:"; 
		   getline(cin,ngayravien);
		   cout<<"Nhap ten khoa:"; 
		   getline(cin,tenkhoa);
		   cout<<"Nhap so duong:"; 
		   getline(cin,soduong);
          }
          void in(){ 
	         BenhNhan::in();
	         cout<<ngaynhapvien<<"  "<<ngayravien<<"  "<<tenkhoa<<"  "<<soduong<<endl;
          }
	    bool getter(){
    		   return true;
    	    }
    	    int Getter(){
          	  return ngaysinh;
          }
		  	   
};
class NgoaiChu: public BenhNhan
{
	private:
	    string ngaychuyen;
	    string noichuyen;
      public:
          void nhap(){
          	   BenhNhan::nhap();
          	   cout<<"Nhap ngay chuyen:"; 
		   getline(cin,ngaychuyen);
		   cout<<"Nhap noi chuyen:"; 
		   getline(cin,noichuyen);
          }
          void in(){
          	   BenhNhan::in();
          	   cout<<ngaychuyen<<"  "<<noichuyen<<endl;
          }
          bool getter(){
    		   return false;
    	    }
    	    int Getter(){
    	    	  return ngaysinh; 
    	    }
};
class BenhVien
{
	private:
	    vector<BenhNhan *> ds_BenhNhan;
      public:
          int BirthDay;
          void Input();
          void Output();
          void NhapNS();
          void Output1();
};
void BenhVien::Input(){
	int luachon;
	while(true){
		system("cls");
		cout<<"============== Benh Nhan =============="<<endl;
		cout<<"1. Benh Nhan Noi Tru"<<endl;
		cout<<"2. Benh Nhan Ngoai Tru"<<endl;
		cout<<"0. Thoat"<<endl;
		cout<<"==============    END    =============="<<endl;
		cout<<"Nhap lua chon:";
		cin>>luachon;
		cin.ignore();
		BenhNhan *x;
		if(luachon == 1){
			x = new NoiChu;
			cout<<"Nhap Thong Tin Cho Benh Nhan Noi Tru:"<<endl;
			x->nhap();
			ds_BenhNhan.push_back(x);
		}
		else if(luachon == 2){
		      x = new NgoaiChu;
			cout<<"Nhap Thong Tin Cho Benh Nhan Ngoai Tru:"<<endl;
			x->nhap(); 
			ds_BenhNhan.push_back(x);
		}
		else if(luachon == 0){
			break;
		}
	}
	
}
void BenhVien::Output(){
	cout<<"======DANH SACH BENH NHAN NOI TRU======="<<endl;
	for(int i=0;i<ds_BenhNhan.size();i++){
		if(ds_BenhNhan[i]->getter() == true){
			cout<<"Thong Tin Benh Nhan Thu "<<i+1<<endl;
		      ds_BenhNhan[i]->in();
		}
	}
	cout<<"======DANH SACH BENH NHAN NGOAI TRU======="<<endl;
	for(int i=0;i<ds_BenhNhan.size();i++){
		if(ds_BenhNhan[i]->getter() == false){
			cout<<"Thong Tin Benh Nhan Thu "<<i+1<<endl;
		      ds_BenhNhan[i]->in();
		}
	}
}
void BenhVien::NhapNS()
{
	cout<<"Nhap Ngay Sinh:";
	cin>>BirthDay;
}
void BenhVien::Output1()
{
	cout<<"So Ho So Benh Nhan Noi Tru Co Ngay Sinh Lon Hon "<<BirthDay<<" la:"<<endl;
	for(int i=0;i<ds_BenhNhan.size();i++){
		if(ds_BenhNhan[i]->getter() == true)
			if(ds_BenhNhan[i]->Getter() > BirthDay){
			cout<<"Thong Tin Benh Nhan Thu "<<i+1<<endl;
		      ds_BenhNhan[i]->in();
		}
	}
	cout<<"So Ho So Benh Nhan Ngoai Tru Co Ngay Sinh Lon Hon "<<BirthDay<<" la:"<<endl;
	for(int i=0;i<ds_BenhNhan.size();i++){
		if(ds_BenhNhan[i]->getter() == false)
			if(ds_BenhNhan[i]->Getter() > BirthDay){
			cout<<"Thong Tin Benh Nhan Thu "<<i+1<<endl;
		      ds_BenhNhan[i]->in();
		}
	}
}
int main(){
	BenhVien *x = new BenhVien;
	x->Input();
	x->Output();
	x->NhapNS();
	x->Output1();
	return 0;
}