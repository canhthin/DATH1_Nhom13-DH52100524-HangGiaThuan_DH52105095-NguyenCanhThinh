#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <typeinfo>
#include <conio.h>
#include<iomanip>
#include<fstream>
#include<string>
#include <cstring>
using namespace std;

// Cau tr�c luu th�ng tin cua c�ng viec
struct CongViec {
    int id;
    char ten[50];
    char ngayKetThuc[20];
    int trangthai;
};

// Cau tr�c danh s�ch c�ng viec
struct Node {
    CongViec data;
    Node* link;
};
typedef Node* Nodeptr;

void khoiTao(Nodeptr& list);

//Th�m
Nodeptr them_CongViec(Nodeptr& list, CongViec cv);
Nodeptr tao_Node_CongViec(CongViec cv);
void them_CongViecVaoDS(Nodeptr& list);
bool kiemTra_TrungTen(Nodeptr list, char* ten);
bool isValidDate(int day, int month, int year);
bool kiemTra_DinhDangNgay(CongViec cv);
int idLonNhat(Nodeptr list);

//sua
void sua_CV_menu(Nodeptr list, int luaChon);
void sua_CongViec(Nodeptr& list, char* ten);
void sua_Ten_CongViec(Nodeptr& list, char* ten);
void sua_NgayKetThuc_CongViec(Nodeptr& list);
void sua_TrangThai_CongViec(Nodeptr& list, char* ten);

//Xo�
void xoa_CongViec(Nodeptr& list, char* ten);
void xoaToanBoDanhSach(Nodeptr& list);

//Sap xep
void sapXep_menu(Nodeptr& list, int luaChon);
void sapxep_TheoTen(Nodeptr& list);        //Sap xep du lieu theo t�n
void sapxep_TheoTrangThai(Nodeptr& list);  //Sap xep du lieu theo trang th�i
void sapxep_TheoId(Nodeptr& list);         //Sap xep du lieu theo id
void sapxep_TheoNgayKetThuc(Nodeptr& list);//Sap xep du lieu theo ngay ket thuc

//Tim kiem
void timKiem_menu(Nodeptr list, int luaChon);
void tim_CongViec_TheoTen(Nodeptr list, char* ten);                //tim kiem theo ten
void tim_CongViec_TheoId(Nodeptr list, int id);                    //tim kiem theo id
void tim_CongViec_TheoNgayKetThuc(Nodeptr list, char* ngayKetThuc);//tim kiem theo ngay ket thuc
void tim_CongViec_TheoTrangThai(Nodeptr list, int trangthai);      //tim kiem theo trang thai

//Xuat danh sach
void xuat_DanhSachCongViec(Nodeptr list);

//Luu tru du lieu tr�n file(file nhi ph�n, file van ban), khi chay chuong tr�nh c� the doc duoc du lieu kh�ng can nhap lai
bool ghiFile(Nodeptr list, const char* tenfile);
bool docDanhSachCongViec(Nodeptr& list, const char* tenfile);

//Chuan hoa chuoi
void xoa(char s[], int vitrixoa);
void xoakt(char* s);
void xoaktRong(char* s);
void chuanHoaChuoi(char* str);

//Nhan phim bat ki
void pressAnyKey();

//cap nhat trang thai cong viec 
void capNhat_TrangThaiTuDong(Nodeptr& list);
