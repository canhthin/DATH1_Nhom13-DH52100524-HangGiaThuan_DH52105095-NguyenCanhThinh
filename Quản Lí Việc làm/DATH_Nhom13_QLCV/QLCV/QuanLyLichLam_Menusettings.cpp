#include "QuanLyLichLam.h"


void sua_CV_menu(Nodeptr list, int luaChon) {
	char ten[50];
	switch (luaChon) {
	case 1:
		xuat_DanhSachCongViec(list);
		sua_Ten_CongViec(list, ten);
		system("cls");
		xuat_DanhSachCongViec(list);
		break;
	case 2:
		xuat_DanhSachCongViec(list);
		sua_NgayKetThuc_CongViec(list);
		system("cls");
		xuat_DanhSachCongViec(list);
		break;
	case 3:
		xuat_DanhSachCongViec(list);
		sua_TrangThai_CongViec(list, ten);
		system("cls");
		xuat_DanhSachCongViec(list);
		break;
	case 0:
		break;
	default:
		cout << "\nLua chon khong hop le!";
		break;
	}
}


void timKiem_menu(Nodeptr list, int luaChon) {
	switch (luaChon) {
	case 1: {
		int id;
		cout << "\nNhap ID cong viec can tim: ";
		cin >> id;
		tim_CongViec_TheoId(list, id);
		break;
	}
	case 2: {
		char ten[50];
		cout << "\nNhap ten cong viec can tim: ";
		cin.ignore();
		cin.getline(ten, 50);
		tim_CongViec_TheoTen(list, ten);
		break;
	}
	case 3: {
		char ngayKetThuc[20];
		cout << "\nNhap ngay ket thuc cong viec can tim: ";
		cin >> ngayKetThuc;
		tim_CongViec_TheoNgayKetThuc(list, ngayKetThuc);
		break;
	}
	case 4: {
		int trangthai;
		cout << "\nNhap trang thai cong viec can tim: ";
		cin >> trangthai;
		tim_CongViec_TheoTrangThai(list, trangthai);
		break;
	}
	case 0: {
		break;
	}
	default:
		cout << "\nLua chon khong hop le!";
		break;
	}
}

void sapXep_menu(Nodeptr& list, int luaChon) {
	switch (luaChon) {
	case 1:
		sapxep_TheoId(list);
		break;
	case 2:
		sapxep_TheoTen(list);
		break;
	case 3:
		sapxep_TheoNgayKetThuc(list);
		break;	
	case 4:
		sapxep_TheoTrangThai(list);
	case 0:
		break;
	default:
		cout << "\nLua chon khong hop le!";
		break;
	}
}