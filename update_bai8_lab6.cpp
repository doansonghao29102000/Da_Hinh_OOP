#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
class CauThu
{
	public:
	    string soCMT;
	    string hoTen;
	    string quocTich;
	    string ngaySinh;
	    string viTriThiDau;
	    float chieuCao;
	    float canNang;
    	    void nhapTTCT()
    	    {
    	    	cout<<"nhap so chung minh thu : ";
    	    	getline(cin , soCMT);
    	    	cout<<"nhap ho ten : ";
    	    	getline(cin , hoTen);
    	    	cout<<"nhap quoc tich : ";
    	    	getline(cin , quocTich);
    	    	cout<<"nhap ngay sinh : ";
    	    	getline(cin , ngaySinh);
    	    	cout<<"nhap vi tri thi dau : ";
    	    	getline(cin , viTriThiDau);
    	    	cout<<"nhap chieu cao : ";
    	    	cin>>chieuCao;
    	    	cout<<"nhap can nang : ";
    	    	cin>>canNang;
    	    	cin.ignore();
    	    }
    	    void inTTCT()
    	    {
    	    	cout<<"so chung minh thu : "<<soCMT<<endl;
    	    	cout<<"ho ten :"<<hoTen<<endl;
    	    	cout<<"quoc tich : "<<quocTich<<endl;
    	    	cout<<"ngay sinh :"<<ngaySinh<<endl;
    	    	cout<<"vi tri thi dau : "<<viTriThiDau<<endl;
    	    	cout<<"chieu cao : "<<chieuCao<<endl;
    	    	cout<<"can nang : "<<canNang<<endl;
    	    }
    	    string getNgaySinh()
    	    {
    	    	return ngaySinh;
    	    }
    	    string getViTriThiDau()
    	    {
    	    	return viTriThiDau;
    	    }
    	    float getChieuCao()
    	    {
    	    	return chieuCao;
    	    }
    	    void setSoCMT(string z1)
    	    {
    	    	soCMT = z1;
    	    }
    	    void setHoTen(string z2)
    	    {
    	    	hoTen = z2;
    	    }
    	    void setQuocTich(string z3)
    	    {
    	    	quocTich = z3;
    	    }
    	    void setNgaySinh(string z4)
    	    {
    	    	ngaySinh = z4;
    	    }
    	    void setViTriThiDau(string z5)
    	    {
    	    	viTriThiDau = z5;
    	    }
    	    void setChieuCao(float z6)
    	    {
    	    	chieuCao = z6;
    	    }
    	    void setCanNang(float z7)
    	    {
    	    	canNang = z7;
    	    }
};
class DanhSachCacCauThu
{
	public:
	    int soLuongCauThu;
	    CauThu a[100];
          void nhapTT()
          {
          	cout<<"nhap so luong cau thu : ";
          	cin>>soLuongCauThu;
          	cin.ignore();
          	for(int i=0;i<soLuongCauThu;i++){
	          	cout<<"nhap thong tin cho cau thu thu "<<i+1<<endl;
	          	a[i].nhapTTCT();
	          }
          }
          void inTT()
          {
          	for(int i=0;i<soLuongCauThu;i++){
	          	cout<<"thong tin cau thu thu "<<i+1<<endl;
	          	a[i].inTTCT();
	          }
          }
          void themCT()
          {
          	CauThu z;
          	cout<<"nhap thong tin cho cau thu duoc them vao"<<endl;
          	z.nhapTTCT();
          	a[soLuongCauThu] = z;
          	soLuongCauThu = soLuongCauThu + 1;
          }
          void xoaCT(int vitri)
          {
          	for(int i=vitri;i<soLuongCauThu-1;i++){
          		a[i] = a[i+1];
		    }
		    soLuongCauThu = soLuongCauThu-1;
          }
          void suaCT(int vitri)
          {
          	while(true){
	          	cout<<"=====menu====="<<endl;
	          	cout<<"1.sua so cmt"<<endl;
	          	cout<<"2.sua ho ten"<<endl;
	          	cout<<"3.sua quoc tich"<<endl;
	          	cout<<"4.sua ngay sinh"<<endl;
	          	cout<<"5.sua vi tri thi dau"<<endl;
	          	cout<<"6.chieu cao"<<endl;
	          	cout<<"7.can nang"<<endl;
	          	cout<<"0.thoat"<<endl;
	          	cout<<"=====end====="<<endl;
	          	int luachon;
	          	cout<<"nhap lua chon : ";
	          	cin>>luachon;
	          	cin.ignore();
	          	if(luachon == 1){
	          		string z1;
	          		cout<<"nhap lai so chung minh thu : ";
    	    			getline(cin , z1);
    	    			a[vitri].setSoCMT(z1);
	          	}
	          	else if(luachon == 2){
	          		string z2;
         			cout<<"nhap lai ho ten : ";
    	    			getline(cin , z2);
    	    			a[vitri].setHoTen(z2);
	          	}
	          	else if(luachon == 3){
	          		string z3;
	          		cout<<"nhap lai quoc tich : ";
    	   		 	getline(cin , z3);
    	   		 	a[vitri].setQuocTich(z3);
	          	}
	          	else if(luachon == 4){
	          		string z4;
	          		cout<<"nhap lai ngay sinh : ";
	          		getline(cin , z4);
	          		a[vitri].setNgaySinh(z4);
	          	}
	          	else if(luachon == 5){
	          		string z5;
	          		cout<<"nhap lai vi tri thi dau : ";
	          		getline(cin , z5);
	          		a[vitri].setViTriThiDau(z5);
	          	}
	          	else if(luachon == 6){
	          		float z6;
	          		cout<<"nhap lai chieu cao : ";
	          		cin>>z6;
	          		a[vitri].setChieuCao(z6);
	          	}
	          	else if(luachon == 7){
	          		float z7;
	          		cout<<"nhap lai can nang : ";
	          		cin>>z7;
	          		a[vitri].setCanNang(z7);
	          	}
	          	else{
	          		break;
	          	}
    		  }
          }
      
};
class VLEAGUE2016
{
	public:
	    void virtual nhapThongTin(){};
	    void virtual inThongTin(){};
	    string virtual  getTenDoiBong(){};
	    void virtual inDanhSachCauThu(){};
	    string virtual getNgayThiDau(){};
	    int virtual getSoLuongCauThu(){};
	    DanhSachCacCauThu virtual getDanhSachCauThu(){};
	    void virtual setDanhSachCacCauThu(DanhSachCacCauThu s){};
	    void virtual setTenDoiBong(string s1){};
	    void virtual setDiaPhuong(string s2){};
	    void virtual setHuanLuyenVien(string s3){};
};
class DoiBong : public VLEAGUE2016
{
	public:
	    string tenDoiBong;
	    string diaPhuong;
	    string huanLuyenVien;
	    DanhSachCacCauThu x;
          void nhapThongTin()
	      {
    		cout<<"nhap ten doi bong : ";
    		getline(cin , tenDoiBong);
    		cout<<"nhap dia phuong : ";
    		getline(cin , diaPhuong);
    		cout<<"nhap ten huan luyen vien : ";
    		getline(cin, huanLuyenVien);
    		cout<<"nhap thong tin danh sach doi bong"<<endl;
    		x.nhapTT();
	      }
           void inThongTin()
	      {
      		cout<<"ten doi bong : "<<tenDoiBong<<endl;
	    		cout<<"dia phuong : "<<diaPhuong<<endl;
	    		cout<<"ten huan luyen vien : "<<huanLuyenVien<<endl;
	    		cout<<"danh sach thong tin doi bong : "<<endl;
	    		x.inTT();
      	}
      	string getTenDoiBong()
      	{
	      	return tenDoiBong;
	      }
	      void inDanhSachCauThu()
	      {
      		x.inTT();
      	}
      	int getSoLuongCauThu()
      	{
	      	return x.soLuongCauThu;
	      }
	      DanhSachCacCauThu getDanhSachCauThu()
	      {
      		return x;
      	}
      	void setDanhSachCacCauThu(DanhSachCacCauThu s){
	      	 x = s;
	      }
	      void setTenDoiBong(string s1)
	      {
      		tenDoiBong = s1;
      	}
      	void setDiaPhuong(string s2)
      	{
	      	diaPhuong = s2;
	      }
	      void setHuanLuyenVien(string s3)
	      {
      		huanLuyenVien = s3;
      	}
      
};
class TranDau : public VLEAGUE2016
{
	public:
	    string ngayThiDau;
	    string tenSanVanDong;
	    string tenHaiDoiBong;
	    string tiSo;
	    void nhapThongTin()
	    {
    		cout<<"nhap ngay thi dau : ";
    		getline(cin , ngayThiDau);
    		cout<<"nhap san van dong : ";
    		getline(cin , tenSanVanDong);
    		cout<<"nhap ten hai doi bong : ";
    		getline(cin, tenHaiDoiBong);
    		cout<<"nhap ti so : ";
    		getline(cin, tiSo);
	      }
	      void inThongTin()
	      {
      		cout<<"ngay thi dau : "<<ngayThiDau<<endl;
	    		cout<<"ten san van dong : "<<tenSanVanDong<<endl;
	    		cout<<"ten hai doi bong : "<<tenHaiDoiBong<<endl;
	    		cout<<"ti so : "<<tiSo<<endl;
      	}
      	string getNgayThiDau()
      	{
	      	return ngayThiDau;
	      }
};
class QuanLyGiaiDau
{
	public:
	    vector<VLEAGUE2016 *> ds_DoiBong;
	    vector<VLEAGUE2016 *> ds_TranDau;
	    int soDoiBong;
	    int soTranDau;
	    void inPut();
	    void outPut1();
	    void outPut2();
	    void outPut3();
	    void outPut4();
	    void outPut5();
	    void add();
	    void remove();
	    void fix();
};
void QuanLyGiaiDau::inPut()
{
	VLEAGUE2016 *x;
	cout<<"nhap vao so luong doi bong : ";
	cin>>soDoiBong;
	cin.ignore();
	for(int i=0;i<soDoiBong;i++){
		cout<<"nhap thong tin cho doi bong thu "<<i+1<<endl;
		x = new DoiBong;
		x->nhapThongTin();
		ds_DoiBong.push_back(x);
	}
	cout<<endl;
	VLEAGUE2016 *y;
	cout<<"nhap vao so tran dau : ";
	cin>>soTranDau;
	cin.ignore();
	for(int i=0;i<soTranDau	;i++){
		y = new TranDau;
		cout<<"nhap thong tin cho tran dau thu "<<i+1<<endl;
		y->nhapThongTin();
		ds_TranDau.push_back(y);
	}
}
void QuanLyGiaiDau::outPut1()
{
	cout<<"danh sach thong tin cac doi bong"<<endl;
	for(int i=0;i<ds_DoiBong.size();i++){
		ds_DoiBong[i]->inThongTin();
		cout<<endl;
	}
	cout<<"danh sach thong tin cac tran dau"<<endl;
	for(int i=0;i<ds_TranDau.size();i++){
		ds_TranDau[i]->inThongTin();
		cout<<endl;
	}
}

void QuanLyGiaiDau::outPut2()
{
	string s;
	cout<<"nhap ten doi bong can tim : ";
	getline(cin , s);
	cout<<"danh sach thong tin cac cau thu cua doi bong "<<s<<endl;
	for(int i=0;i<soDoiBong;i++){
		if(ds_DoiBong[i]->getTenDoiBong() == s){
			ds_DoiBong[i]->inDanhSachCauThu();
		}
	}
}
void QuanLyGiaiDau::outPut3()
{
	while(true){
		cout<<"=======menu======"<<endl;
		cout<<"1. tim kiem theo ngay"<<endl;
		cout<<"2. tim kiem theo thang"<<endl;
		cout<<"3. tim kiem thao giai dau "<<endl;
		cout<<"0. thoat"<<endl;
		cout<<"========endl======="<<endl;
		int luachon;
		cout<<"nhap lua chon : ";
		cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			string ngay; // dd mm yy
			cout<<"nhap vao ngay can tim kiem : ";
			getline(cin , ngay);
			cout<<"danh sach thong tin cac tran dau vao ngay "<<ngay<<endl;
			for(int i=0 ; i < soTranDau ; i++){
				if(ds_TranDau[i]->getNgayThiDau() == ngay){
					ds_TranDau[i]->inThongTin();
				}
			}
		}
		else if(luachon == 2){
			string thang; // mm yy
			cout<<"nhap vao thang can tim kiem : ";
			getline(cin , thang);
			cout<<"danh sach thong tin cac tran dau vao thang "<<thang<<endl;
			for(int i=0 ; i < soTranDau ; i++){
				string s = ds_TranDau[i]->getNgayThiDau();
				if(s.substr(3) == thang){
					ds_TranDau[i]->inThongTin();
				}
			}
		}
		else if(luachon == 3){
			string nam; // yy
			cout<<"nhap vao nam can tim kiem : ";
			getline(cin , nam);
			cout<<"danh sach thong tin cac tran dau vao nam "<<nam<<endl;
			for(int i=0 ; i < soTranDau ; i++){
				string s = ds_TranDau[i]->getNgayThiDau();
				if(s.substr(6) == nam){
					ds_TranDau[i]->inThongTin();
				}
			}
		}
		else if(luachon == 0){
			break;
		}
	}
}
void QuanLyGiaiDau::outPut4()
{
	while(true){
		cout<<"===============menu==============="<<endl;
		cout<<"1. tim kiem cau thu theo ngay sinh"<<endl;
		cout<<"2. tim kiem cau thu theo vi tri thi dau"<<endl;
		cout<<"0. thoat"<<endl;
		cout<<"===============end==============="<<endl;
		int luachon;
		cout<<"nhap lua chon : ";
		cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			string namSinh; // dd mm yy
			cout<<"nhap vao nam sinh cau thu : ";
			getline(cin , namSinh);
			cout<<"thong tin cac cau thu co ngay sinh "<<namSinh<<endl;
			for(int i=0 ; i < soDoiBong ; i++){
				for(int j=0 ; j < ds_DoiBong[i]->getSoLuongCauThu();j++){
					if(ds_DoiBong[i]->getDanhSachCauThu().a[j].getNgaySinh() == namSinh){
						ds_DoiBong[i]->getDanhSachCauThu().a[j].inTTCT();
					}
				}
			}
		}
		if(luachon == 2){
			string viTriTrenSan;
			cout<<"nhap vao vi tri tren san : ";
			getline(cin , viTriTrenSan);
			cout<<"thong tin cac cau thu co vi tri tren san la "<<viTriTrenSan<<endl;
			for(int i=0 ; i < soDoiBong ; i++){
				for(int j=0 ; j < ds_DoiBong[i]->getSoLuongCauThu();j++){
					if(ds_DoiBong[i]->getDanhSachCauThu().a[j].getViTriThiDau()	 == viTriTrenSan){
						ds_DoiBong[i]->getDanhSachCauThu().a[j].inTTCT();
					}
				}
			}
		}
		else if(luachon == 0){
			break;
		}
	}
}
void QuanLyGiaiDau::outPut5()
{
	while(true){
		cout<<"===============menu==============="<<endl;
		cout<<"1. tim kiem cau thu cao nhat giai"<<endl;
		cout<<"2. tim kiem cau thu thap nhat giai"<<endl;
		cout<<"3. tim kiem cau thu tre nhat giai"<<endl;
		cout<<"0. thoat"<<endl;
		cout<<"===============end==============="<<endl;
		int luachon;
		cout<<"nhap lua chon : ";
		cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			float MAX = 0;
			for(int i=0 ; i < soDoiBong ; i++){
				for(int j=0 ; j < ds_DoiBong[i]->getSoLuongCauThu();j++){
					if(ds_DoiBong[i]->getDanhSachCauThu().a[j].getChieuCao() > MAX){
						MAX = ds_DoiBong[i]->getDanhSachCauThu().a[j].getChieuCao();
					}
				}
			}
			cout<<"thong tin cac cau thu cao nhat giai "<<endl;
			for(int i=0 ; i < soDoiBong ; i++){
				for(int j=0 ; j < ds_DoiBong[i]->getSoLuongCauThu();j++){
					if(ds_DoiBong[i]->getDanhSachCauThu().a[j].getChieuCao() == MAX){
						ds_DoiBong[i]->getDanhSachCauThu().a[j].inTTCT();
					}
				}
			}
		}
		if(luachon == 2){
			float MIN = 3;
			for(int i=0 ; i < soDoiBong ; i++){
				for(int j=0 ; j < ds_DoiBong[i]->getSoLuongCauThu();j++){
					if(ds_DoiBong[i]->getDanhSachCauThu().a[j].getChieuCao() < MIN){
						MIN = ds_DoiBong[i]->getDanhSachCauThu().a[j].getChieuCao();
					}
				}
			}
			cout<<"thong tin cac cau thu thap nhat giai "<<endl;
			for(int i=0 ; i < soDoiBong ; i++){
				for(int j=0 ; j < ds_DoiBong[i]->getSoLuongCauThu();j++){
					if(ds_DoiBong[i]->getDanhSachCauThu().a[j].getChieuCao() == MIN){
						ds_DoiBong[i]->getDanhSachCauThu().a[j].inTTCT();
					}
				}
			}
		}
		if(luachon == 3){
			int MIN = 150;
			for(int i=0 ; i < soDoiBong ; i++){
				for(int j=0 ; j < ds_DoiBong[i]->getSoLuongCauThu();j++){
					string s = ds_DoiBong[i]->getDanhSachCauThu().a[j].getNgaySinh();
					string s1 = s.substr(8);
					int sum = (int(s1[0]) - 48)*10 + (int(s1[1]) - 48);
					int tuoi = 0;
					if(sum <= 22) tuoi = 22 - sum;
					else tuoi = 122 - sum;
					if(tuoi < MIN) MIN = tuoi;
					}
			}
			cout<<"thong tin cac cau thu tre nhat giai "<<endl;
			for(int i=0 ; i < soDoiBong ; i++){
				for(int j=0 ; j < ds_DoiBong[i]->getSoLuongCauThu();j++){
					string s = ds_DoiBong[i]->getDanhSachCauThu().a[j].getNgaySinh();
					string s1 = s.substr(8);
					int sum = (int(s1[0]) - 48)*10 + (int(s1[1]) - 48);
					int tuoi = 0;
					if(sum <= 22) tuoi = 22 - sum;
					else tuoi = 122 - sum;
					if(tuoi == MIN){
						ds_DoiBong[i]->getDanhSachCauThu().a[j].inTTCT();
					}
				}
			}
		}
		else if(luachon == 0){
			break;
		}
	}
}
void QuanLyGiaiDau::add()
{
	while(true){
		VLEAGUE2016 *x;
		cout<<"===============menu==============="<<endl;
		cout<<"1. them thong tin cua 1 doi bong"<<endl;
		cout<<"2. them thong tin cua 1 cau thu"<<endl;
		cout<<"0. thoat"<<endl;
		cout<<"===============end==============="<<endl;
		int luachon;
		cout<<"nhap lua chon : ";
		cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			cout<<"nhap thong tin cho doi bong can them vao danh sach "<<endl;
			x = new DoiBong;
			x->nhapThongTin();
			ds_DoiBong.push_back(x);
		}
		if(luachon == 2){
			string nameCLB;
			cout<<"nhap vao ten doi bong can them cau thu : ";
			getline(cin , nameCLB);
			for(int i=0 ; i < soDoiBong ; i++){
				if(ds_DoiBong[i]->getTenDoiBong() == nameCLB){
					DanhSachCacCauThu x = ds_DoiBong[i]->getDanhSachCauThu();
					x.themCT();
					ds_DoiBong[i]->setDanhSachCacCauThu(x);
				}
			}
		}
		else if(luachon == 0){
			break;
		}
	}
}
void QuanLyGiaiDau::remove()
{
	while(true){
		cout<<"===============menu==============="<<endl;
		cout<<"1. xoa thong tin cua 1 doi bong"<<endl;
		cout<<"2. xoa thong tin cua 1 cau thu"<<endl;
		cout<<"0. thoat"<<endl;
		cout<<"===============end==============="<<endl;
		int luachon;
		cout<<"nhap lua chon : ";
		cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			int address = 0;
			string nameCLB;
			cout<<"nhap vao ten doi bong can xoa: ";
			getline(cin , nameCLB);
			for(int i=0 ; i < soDoiBong ; i++){
				if(ds_DoiBong[i]->getTenDoiBong() == nameCLB){
					address = i;
				}
			}
			ds_DoiBong.erase(ds_DoiBong.begin() + address);
		}
		if(luachon == 2){
			string nameCLB;
			int vitri;
			cout<<"nhap vao ten doi bong can xoa cau thu : ";
			getline(cin , nameCLB);
			cout<<"nhap vao vi tri cua cau thu can xoa trong danh sach : ";
			cin>>vitri;
			for(int i=0 ; i < soDoiBong ; i++){
				if(ds_DoiBong[i]->getTenDoiBong() == nameCLB){
					DanhSachCacCauThu x = ds_DoiBong[i]->getDanhSachCauThu();
					x.xoaCT(vitri-1);
					ds_DoiBong[i]->setDanhSachCacCauThu(x);
				}
			}
		}
		else if(luachon == 0){
			break;
		}
	}
}
void QuanLyGiaiDau::fix()
{
	while(true){
		VLEAGUE2016 *x;
		cout<<"===============menu==============="<<endl;
		cout<<"1. sua thong tin cua 1 doi bong"<<endl;
		cout<<"2. sua thong tin cua 1 cau thu"<<endl;
		cout<<"0. thoat"<<endl;
		cout<<"===============end==============="<<endl;
		int luachon;
		cout<<"nhap lua chon : ";
		cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			string nameCLB;
			cout<<"nhap vao ten doi bong can sua thong tin: ";
			getline(cin , nameCLB);
			for(int i=0 ; i < soDoiBong ; i++){
				if(ds_DoiBong[i]->getTenDoiBong() == nameCLB){
					while(true){
						cout<<"======menu======"<<endl;
						cout<<"1.sua ten doi bong "<<endl;
						cout<<"2.sua ten dia phuong"<<endl;
						cout<<"3.sua ten huan luyen vien"<<endl;
						cout<<"0.thoat"<<endl;
						cout<<"=======end======"<<endl;
						int luachon1;
						cout<<"nhap lua chon : ";
						cin>>luachon1;
						cin.ignore();
						if(luachon1 == 1){
							string s1;
							cout<<"nhap lai ten doi bong : ";
							getline(cin , s1);
							ds_DoiBong[i]->setTenDoiBong(s1);
						}
						else if(luachon1 == 2){
							string s2;
							cout<<"nhap lai ten dia phuong : ";
							getline(cin , s2);
							ds_DoiBong[i]->setDiaPhuong(s2);
						}
						else if(luachon1 == 3){
							string s3;
							cout<<"nhap lai ten huan luyen vien: ";
							getline(cin , s3);
							ds_DoiBong[i]->setHuanLuyenVien(s3);
						}
						else{
							break;
						}
					}
				}
			}
		}
		else if(luachon == 2){
			string nameCLB;
			cout<<"nhap vao ten doi bong can sua thong tin cho cac cau thu cua doi bong do: ";
			getline(cin , nameCLB);
			for(int i=0 ; i < soDoiBong ; i++){
				if(ds_DoiBong[i]->getTenDoiBong() == nameCLB){
					DanhSachCacCauThu x = ds_DoiBong[i]->getDanhSachCauThu();
					int vitri;
					cout<<"nhap vao vi tri cau thu trong danh sach can sua : ";
					cin>>vitri;
					x.suaCT(vitri);
					ds_DoiBong[i]->setDanhSachCacCauThu(x);
				}
			}
		}
		else if(luachon == 0){
			break;
		}
	}
}
int main(){
	QuanLyGiaiDau x;
	while(true){
		cout<<"========================menu========================="<<endl;
		cout<<"1.nhap vao danh sach doi bong va danh sach tran dau  "<<endl;
		cout<<"2.hien thi danh sach cac cau thu trong 1 doi bong    "<<endl;
		cout<<"3.in ra danh sach doi bong va danh sach tran dau     "<<endl;
		cout<<"4.liet ke cac tran dau trong 1 ngay , 1 thang , 1 nam"<<endl;
		cout<<"5.liet ke cac cau thu theo nam sinh , vi tri thi dau "<<endl;
		cout<<"6.tim cau thu cao nhat , thap nhat , tre nhat giai   "<<endl;
		cout<<"7.them 1 cau thu hoac 1 doi bong vao danh sach       "<<endl;
		cout<<"8.xoa 1 cau thu hoac 1 doi bong vao danh sach        "<<endl;
		cout<<"9.sua 1 cau thu hoac 1 doi bong vao danh sach        "<<endl;
		cout<<"0.thoat                                              "<<endl;
		cout<<"=========================end========================="<<endl;
		int luachon;
		cout<<"nhap lua chon cua ban : ";
		cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			x.inPut();
		}
		else if(luachon == 2){
			x.outPut1();
		}
		else if(luachon == 3){
			x.outPut2();
		}
		else if(luachon == 4){
			x.outPut3();
		}
		else if(luachon == 5){
			x.outPut4();
		}
		else if(luachon == 6){
			x.outPut5();
		}
		else if(luachon == 7){
			x.add();
		}
		else if(luachon == 8){
			x.remove();
		}
		else if(luachon == 9){
			x.fix();
		}
		else{
			break;
		}
	}
	return 0;
}