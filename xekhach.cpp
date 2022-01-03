#include <iostream>
#include <iomanip>
#include <fstream>
int const MAX = 1000;
using namespace std;
class PTGT
{
	protected:
	    string HangSanXuat;
	    string NgayXuatXuong; //  dd/mm/yyyy
	    long long GiaChuaThue;
      public:
          PTGT(string HangSanXuat="xxx" , string NgayXuatXuong = "dd/mm/yyyy" , long GiaChuaThue = 1)
    	    {
          	   this->HangSanXuat = HangSanXuat;
          	   this->NgayXuatXuong = NgayXuatXuong;
          	   this->GiaChuaThue = GiaChuaThue;
          }
          ~PTGT()
    	    {
          	   HangSanXuat = NgayXuatXuong = "";
          	   GiaChuaThue = 0;
          }
          void Nhap()
          {
          	   cout<<"Nhap Hang San Xuat:";
          	   getline(cin, HangSanXuat);
          	   cout<<"Nhap Ngay Xuat Xuong:";  //  dd/mm/yyyy
          	   getline(cin, NgayXuatXuong);
          	   cout<<"Nhap Gia Chua Thue:";
          	   cin>>GiaChuaThue;
          	   cin.ignore();
          }
          void In()
          {
          	   cout<<"|"<<setw(15)<<left<<HangSanXuat<<"|"<<setw(20)<<left<<NgayXuatXuong;
               cout<<"|"<<setw(15)<<left<<GiaChuaThue<<"|"<<endl;
               cout<<"------------------------------------------------------"<<endl;
          }
          void Doc_File(ifstream &file_in)
          {
          	   getline(file_in, HangSanXuat , ',');
          	   getline(file_in, NgayXuatXuong , ',');
          	   file_in >> GiaChuaThue;
          }
          void Ghi_File(ofstream &file_out)
          {
          	   file_out<<"|"<<setw(15)<<left<<HangSanXuat<<"|"<<setw(20)<<left<<NgayXuatXuong;
               file_out<<"|"<<setw(15)<<left<<GiaChuaThue<<"|"<<endl;
               file_out<<"------------------------------------------------------"<<endl;
          }
          
};

class XEKHACH : public PTGT
{
	private:
	    string SoTuyen;
	    int SoGhe;
	    string NoiDKKinhDoanh;
      public:
          XEKHACH(string HangSanXuat = "xxx" , string NgayXuatXuong = "dd/mm/yyyy" , long GiaChuaThue = 1 ,
          string SoTuyen = "01abc" , int SoGhe = 1 , string NoiDKKinhDoanh = "city x")
    	    {
          	   this->HangSanXuat = HangSanXuat;
          	   this->NgayXuatXuong = NgayXuatXuong;
          	   this->GiaChuaThue = GiaChuaThue;
          	   this->SoTuyen = SoTuyen;
          	   this->SoGhe = SoGhe;
          	   this->NoiDKKinhDoanh = NoiDKKinhDoanh;
          }
          ~XEKHACH()
    	    {
          	   HangSanXuat = NgayXuatXuong = SoTuyen = NoiDKKinhDoanh = "";
          	   GiaChuaThue = SoGhe = 0;
          }
          friend istream &operator >>(istream &is, XEKHACH &x)
    	    {
   	         cout<<"Nhap Hang San Xuat Cua Xe Khach:";
          	   getline(is, x.HangSanXuat);
          	   cout<<"Nhap Ngay Xuat Xuong Cua Xe Khach:";   //  dd/mm/yyyy
          	   getline(is, x.NgayXuatXuong);
          	   cout<<"Nhap Gia Chua Thue Cua Xe Khach:";
          	   is>>x.GiaChuaThue;
          	   is.ignore();
          	   cout<<"Nhap So Tuyen Cua Xe Khach:";
          	   getline(is, x.SoTuyen);
          	   cout<<"Nhap So Ghe Cua Xe Khach:";
          	   is>>x.SoGhe;
          	   is.ignore();
          	   cout<<"Nhap Noi Dang Ky Kinh Doanh Cua Xe Khach:";
          	   getline(is, x.NoiDKKinhDoanh);
          	   return is;
          }
          long long GiaSauThue()
          {
          	   return GiaChuaThue + (GiaChuaThue/100)*8; 
          }
          bool operator <(int x){
     	         return (this->SoGhe < x);
          }
          friend ostream &operator <<(ostream &os, XEKHACH x)
          {
     	         os<<"|"<<setw(15)<<left<<x.HangSanXuat<<"|"<<setw(20)<<left<<x.NgayXuatXuong;
               os<<"|"<<setw(15)<<left<<x.GiaChuaThue<<"|"<<setw(15)<<left<<x.SoTuyen;
               os<<"|"<<setw(10)<<left<<x.SoGhe<<"|"<<setw(20)<<left<<x.NoiDKKinhDoanh;
		   os<<"|"<<setw(15)<<left<<x.GiaSauThue()<<"|"<<endl;
               os<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
               return os;
          }
          string getNDKKD()
          {
     	           return NoiDKKinhDoanh;
          }
          string getHSX()
          {
          	     return HangSanXuat;
          }
          string getNXS()
          {
   	           return NgayXuatXuong;
          }
          void Doc_File(ifstream &file_in)
          {
          	   PTGT::Doc_File(file_in);
          	   file_in.ignore();
          	   getline(file_in , SoTuyen , ',');
          	   file_in >> SoGhe;
          	   file_in.ignore();
          	   getline(file_in , NoiDKKinhDoanh , '.');
          	   file_in.ignore();
          }
          void Ghi_File(ofstream &file_out)
          {
          	   PTGT::Ghi_File(file_out);
          	   file_out<<"|"<<setw(15)<<left<<HangSanXuat<<"|"<<setw(20)<<left<<NgayXuatXuong;
               file_out<<"|"<<setw(15)<<left<<GiaChuaThue<<"|"<<endl;
               file_out<<"------------------------------------------------------"<<endl;
          }
};

class QUANLYXEKHACH
{
	private:
	    int n;
	    XEKHACH arr[MAX];
      public:
          void DocTep();
          void GhiTep();
          void OutPut1();
          void OutPut2();
};
void QUANLYXEKHACH::DocTep()
{
	ifstream file_in;
	file_in.open("input.txt", ios_base::in);
	file_in >> n;
	file_in.ignore();
	for(int i=0;i<n;i++){
		arr[i].Doc_File(file_in);
	}
	file_in.close();
}
void QUANLYXEKHACH::GhiTep()
{
	ofstream file_out;
	file_out.open("output.txt", ios_base::out);
	for(int i=0;i<n;i++){
		arr[i].Ghi_File(file_out);
	}
	file_out.close();
}
void QUANLYXEKHACH::OutPut1()
{
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
}
int main()
{
	QUANLYXEKHACH *x = new QUANLYXEKHACH;
	x->DocTep();
	x->GhiTep();
	return 0;
}