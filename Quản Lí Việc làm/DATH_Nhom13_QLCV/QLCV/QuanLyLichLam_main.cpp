#include "QuanLyLichLam.h"

int main() {
    int choice, luaChonMenu;
    Nodeptr dscv;
    khoiTao(dscv);
    char ten[50];
    char ngayKetThuc[30];
    int id, trangthai;
    do {
        cout << "CHUONG TRINH QUAN LY CONG VIEC C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Luu du lieu vao file.                          **\n";
        cout << "**  2. Doc du lieu tu file.                           **\n";
        cout << "**  3. Xuat danh sach cong viec.                      **\n";
        cout << "**  4. Them cong viec.                                **\n";
        cout << "**  5. Thay doi thong tin cong viec.                  **\n";
        cout << "**  6. Xoa cong viec.                                 **\n";
        cout << "**  7. Sap xep cong viec.                             **\n";
        cout << "**  8. Tim kiem cong viec.                            **\n";    
        cout << "**  9. Tu dong cap nhat trang thai tat ca cong viec.  **\n";  
        cout << "**  10. Xoa tat ca cong viec.                         **\n";
        cout << "**  0. Thoat                                          **\n";
        cout << "********************************************************\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (ghiFile(dscv, "DanhSachCongViec.txt")) {
                cout << "Ghi file thanh cong";
                pressAnyKey();
            }
            break;
        case 2:
            xoaToanBoDanhSach(dscv);
            if (docDanhSachCongViec(dscv, "DanhSachCongViec.txt") == true) {
                cout << "Doc file thanh cong";
                pressAnyKey();
            }
            break;
        case 3:
            xuat_DanhSachCongViec(dscv);
            pressAnyKey();
            break;
        case 4:
            them_CongViecVaoDS(dscv);
            pressAnyKey();
            break;
        case 5:
            cout << "\n Chon cach sua:"
                << "\n1. Thay doi ten cua 1 cong viec."
                << "\n2. Thay doi ngay ket thuc cua 1 cong viec."
                << "\n3. Thay doi trang thai cua 1 cong viec."
                << "\n0. Thoat ra menu.";
            cout << "\nNhap lua chon: ";
            cin >> luaChonMenu;
            //xuat_DanhSachCongViec(dscv);
            sua_CV_menu(dscv, luaChonMenu);                
            //xuat_DanhSachCongViec(dscv);
            pressAnyKey();
            break;
        case 6:
            xuat_DanhSachCongViec(dscv);
            cout << "Nhap ten cong viec can xoa:";
            cin.ignore();
            cin.getline(ten, 50);
            xoa_CongViec(dscv, ten);     
            pressAnyKey();
            break;
        case 7:
            cout << "\nChon cach sap xep:"
                << "\n1. Theo ID"
                << "\n2. Theo ten"
                << "\n3. Theo ngay ket thuc"
                << "\n4. Theo trang thai"
                << "\n0. Thoat ra menu";
            cout << "\nNhap lua chon: ";
            cin >> luaChonMenu;
            sapXep_menu(dscv, luaChonMenu);
            pressAnyKey();
            break;
        case 8:
            cout << "\nChon cach tim kiem:"
                << "\n1. Theo ID"
                << "\n2. Theo Ten"
                << "\n3. Theo ngay ket thuc"
                << "\n4. Theo trang thai"
                << "\n0. Thoat ra menu";
            cout << "\nNhap lua chon: ";
            cin >> luaChonMenu;
            timKiem_menu(dscv, luaChonMenu);
            pressAnyKey();
            break;     
        case 9:
            capNhat_TrangThaiTuDong(dscv); // C?p nh?t tr?ng thái t? ??ng tr??c khi hi?n th? danh sách
            xuat_DanhSachCongViec(dscv);
            pressAnyKey();
            break;       f
        case 10:
            xoaToanBoDanhSach(dscv);
            pressAnyKey();
            break;
        case 0:
            cout << "\nBan da chon thoat khoi chuong trinh";
            cout << "\nTam biet!";
            break;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nHay chon chuc nang trong hop menu.";
            pressAnyKey();
            break;
        }
    } while (choice != 0);
    return 0;
}