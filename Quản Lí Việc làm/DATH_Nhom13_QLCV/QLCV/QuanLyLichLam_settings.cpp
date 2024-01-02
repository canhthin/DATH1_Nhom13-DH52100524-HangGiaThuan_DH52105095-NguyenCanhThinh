#include "QuanLyLichLam.h"

void khoiTao(Nodeptr& list) {
	list = NULL;
}
//1. Thêm
Nodeptr tao_Node_CongViec(CongViec cv) {
	Nodeptr p = new Node;
	p->data = cv;
	p->link = NULL;
	return p;
}
Nodeptr them_CongViec(Nodeptr& list, CongViec cv) {
	Nodeptr p = tao_Node_CongViec(cv);
	p->link = list;
	list = p;
	return p;
}
int idLonNhat(Nodeptr list) {
	int max = 0;
	while (list != NULL) {
		if (list->data.id > max) {
			max = list->data.id;
		}
		list = list->link;
	}
	return max;
}
void them_CongViecVaoDS(Nodeptr& list) {
	CongViec cv;
	int id = 0;
	id = idLonNhat(list) + 1;
	cv.id = id;
	cout << "Them cong viec vao danh sach:";
	cout << "\nNhap ten: ";
	cin.ignore();
	cin.getline(cv.ten, 50);
	while (kiemTra_TrungTen(list, cv.ten)) {
		cout << "Ten cong viec bi trung";
		cout << "\nNhap lai ten cong viec: ";
		cin.getline(cv.ten, 50);
	}
	cout << "Nhap ngay ket thuc cv(dd/mm/yyyy): ";
	cin >> cv.ngayKetThuc;
	while (kiemTra_DinhDangNgay(cv)) {
		cout << "\nNhap lai ngay ket thuc cv(dd/mm/yyyy): ";
		cin >> cv.ngayKetThuc;
	}

	cout << "Nhap trang thai (0: hoan thanh, 1: chua hoan thanh): ";
	cin >> cv.trangthai;
	//Chuan hoá chuoi
	char str1[50];
	for (int i = 0; i < strlen(cv.ten); i++) {
		str1[i] = tolower(cv.ten[i]);
	}
	str1[strlen(cv.ten)] = '\0';
	xoaktRong(str1);
	for (int i = 0; i < strlen(cv.ten); i++) {
		cv.ten[i] = str1[i];
	}
	them_CongViec(list, cv);
}
bool kiemTra_TrungTen(Nodeptr list, char* ten) {
	Nodeptr p = list;
	while (p != NULL) {
		if (strcmp(p->data.ten, ten) == 0) return true;
		p = p->link;
	}
	return false;
}
bool kiemTra_DinhDangNgay(CongViec cv) {
	int currentDay, currentMonth, currentYear;

	// Lay thoi gian hien tai
	time_t t = time(0);
	tm* now = localtime(&t);

	currentDay = now->tm_mday;
	currentMonth = now->tm_mon + 1;  // tm_mon bat dau tu 0
	currentYear = now->tm_year + 1900;  // tm_year là so nam ke tu 1900

	int endDay, endMonth, endYear;

	if (sscanf(cv.ngayKetThuc, "%d/%d/%d", &endDay, &endMonth, &endYear) != 3) {
		cout << "Loi: Dinh dang ngay khong hop le hoac khong chuyen doi thanh cong." << endl;
		return true;
	}
	if (!isValidDate(endDay, endMonth, endYear)) {
		cout << "Ngay nhap khong hop le. Vui long nhap lai." << endl;
		return true;
	}

	// Kiem tra ngày ket thúc có bé hon ngày hien tai hay không
	if (endYear < currentYear || (endYear == currentYear && (endMonth < currentMonth || (endMonth == currentMonth && endDay <= currentDay)))) {
		cout << "Ngay ket thuc khong duoc be hon ngay hien tai. Vui long nhap lai." << endl;
		return true;
	}
	return false;
}
bool isValidDate(int day, int month, int year) {
	// Kiem tra nam
	if (year < 1000 || year > 9999) {
		return false;
	}
	// Kiem tra tháng
	if (month < 1 || month > 12) {
		return false;
	}
	// Kiem tra ngày
	if (day < 1 || day > 31) {
		return false;
	}
	// Kiem tra so ngày cua tháng
	int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
		daysInMonth[2] = 29;  // Nam nhuan
	}
	if (day > daysInMonth[month]) {
		return false;
	}
	return true;
}

// 2. Sua, Hàm sửa tên công việc, sua ngày kết thúc công việc, thay doi trang thai cong viec
void sua_CongViec(Nodeptr& list, char* ten) {
	Nodeptr p = list;
	bool isFound = false;
	//Chuan hoá chuoi
	char str1[50];
	for (int i = 0; i < strlen(ten); i++) {
		str1[i] = tolower(ten[i]);
	}
	str1[strlen(ten)] = '\0';
	xoaktRong(str1);
	for (int i = 0; i < strlen(ten); i++) {
		ten[i] = str1[i];
	}
	while (p != NULL) {
		if (strcmp(p->data.ten, ten) == 0) {
			isFound = true;
			cout << "Sua cong viec " << ten << " thanh:";
			cout << "\nNhap ten: ";
			cin.getline(p->data.ten, 50);
			while (kiemTra_TrungTen(list, ten)) {
				cout << "Ten cong viec bi trung";
				cout << "\nNhap lai ten cong viec: ";
				cin.getline(p->data.ten, 50);
			}
			cout << "Nhap ngay ket thuc cv(dd/mm/yyyy): ";
			cin >> p->data.ngayKetThuc;
			cout << "Nhap trang thai (0: hoan thanh, 1: chua hoan thanh): ";
			cin >> p->data.trangthai;
		}
		p = p->link;
	}
	if (isFound == false) cout << "Khong tim thay " << ten << " de sua";
}
void sua_Ten_CongViec(Nodeptr& list, char* ten) {
	cout << "Nhap ten cong viec can sua: ";
	cin.ignore();
	cin.getline(ten, 50);
	Nodeptr p = list;
	bool isFound = false;
	//Chuan hoá chuoi
	char str1[50];
	for (int i = 0; i < strlen(ten); i++) {
		str1[i] = tolower(ten[i]);
		}
	str1[strlen(ten)] = '\0';
	xoaktRong(str1);
	for (int i = 0; i < strlen(ten); i++) {
		ten[i] = str1[i];
	}
	while (p != NULL) {
		if (strcmp(p->data.ten, ten) == 0) {
			isFound = true;
			cout << "Sua ten cua cong viec " << ten << " thanh:";
			cout << "\nNhap ten moi: ";
			cin.getline(p->data.ten, 50);
			while (kiemTra_TrungTen(list, ten)) {
				cout << "Ten cong viec bi trung";
				cout << "\nNhap lai ten cong viec: ";
				cin.getline(p->data.ten, 50);
			}
			cout << "Sua ten thanh cong.\n";
		}
		p = p->link;
	}
	if (!isFound) {
		cout << "Khong tim thay cong viec co ten " << ten << " de sua.\n";
	}
}

void sua_NgayKetThuc_CongViec(Nodeptr& list) {
	char tenCongViec[50];
	cout << "Nhap ten cong viec can sua ngay ket thuc: ";
	cin.ignore();
	cin.getline(tenCongViec, 50);

	Nodeptr p = list;
	bool isFound = false;
	//Chuan hoá chuoi
	char str1[50];
	for (int i = 0; i < strlen(tenCongViec); i++) {
		str1[i] = tolower(tenCongViec[i]);
	}
	str1[strlen(tenCongViec)] = '\0';
	xoaktRong(str1);
	for (int i = 0; i < strlen(tenCongViec); i++) {
		tenCongViec[i] = str1[i];
	}
	while (p != NULL) {
		if (strcmp(p->data.ten, tenCongViec) == 0) {
			isFound = true;
			cout << "Sua ngay ket thuc cua cong viec " << tenCongViec << " thanh:";
			cout << "\nNhap ngay ket thuc moi (dd/mm/yyyy): ";
			cin >> p->data.ngayKetThuc;

			while (kiemTra_DinhDangNgay(p->data)) {
				cout << "\nNhap lai ngay ket thuc cv (dd/mm/yyyy): ";
				cin >> p->data.ngayKetThuc;
			}

			cout << "Sua ngay ket thuc thanh cong.\n";
		}
		p = p->link;
	}

	if (!isFound) {
		cout << "Khong tim thay cong viec co ten " << tenCongViec << " de sua.\n";
	}
}

void sua_TrangThai_CongViec(Nodeptr& list, char* ten) {
	cout << "Nhap ten cong viec can sua trang thai: ";
	cin.ignore();
	cin.getline(ten, 50);

	Nodeptr p = list;
	bool isFound = false;
	//Chuan hoá chuoi
	char str1[50];
	for (int i = 0; i < strlen(ten); i++) {
		str1[i] = tolower(ten[i]);
	}
	str1[strlen(ten)] = '\0';
	xoaktRong(str1);
	for (int i = 0; i < strlen(ten); i++) {
		ten[i] = str1[i];
	}
	while (p != NULL) {
		if (strcmp(p->data.ten, ten) == 0) {
			isFound = true;
			cout << "Sua trang thai cua cong viec " << ten << " thanh:";
			cout << "\nNhap trang thai moi (0: hoan thanh, 1: chua hoan thanh): ";
			cin >> p->data.trangthai;
			cout << "Sua trang thai thanh cong.\n";
		}
		p = p->link;
	}

	if (!isFound) {
		cout << "Khong tim thay cong viec co ten " << ten << " de sua trang thai.\n";
	}
}


// 3. Xoá
void xoa_CongViec(Nodeptr& list, char* ten) {
	if (list != NULL && list->data.ten != NULL) {
		if (strcmp(list->data.ten, ten) == 0) { //Neu tìm thay phan tu dau tiên là công viec can xoá thì xoá luôn
			Nodeptr p = list;
			list = list->link;
			delete p;
			cout << "Xoa thanh cong\n";
			xuat_DanhSachCongViec(list);
		}
	}
	else {
		Nodeptr p, before;
		p = list;
		before = list;
		while (p != NULL && strcmp(p->data.ten, ten) != 0) { //Tìm công viec can xoá ? nh?ng ph?n t? Kiem theo
			before = p;
			p = p->link;
		}
		if (p != NULL) { // Khác NULL tuc là tìm thay. 
			before->link = p->link;
			delete p;
			cout << "Xoa thanh cong\n";
			xuat_DanhSachCongViec(list);
		}
		else { //Neu bang NULL nghia là dã tìm het danh sách nhung ko thay
			cout << "Khong tim thay cong viec de xoa\n";
		}
	}
}
void xoaToanBoDanhSach(Nodeptr& list) { // Hàm xóa toàn bo danh sách
	if (list == NULL) {
		cout << "Danh sach cong viec dang rong khong co gi de xoa.\n"; // khi danh sách công việc rỗng
		return;
	}
	Nodeptr p = list;
	while (p != NULL) {
		Nodeptr temp = p;
		p = p->link;
		delete temp;
	}
	// Đặt con trỏ về NULL sau khi xóa danh sách
	list = NULL;
	cout << "Da xoa toan bo danh sach cong viec.\n";
}
//4. Sap xep du lieu
void sapxep_TheoId(Nodeptr& list) {
	for (Nodeptr i = list; i != NULL; i = i->link) {
		for (Nodeptr j = i->link; j != NULL; j = j->link) {
			if (i->data.id > j->data.id) {
				swap(i->data.id, j->data.id);
				swap(i->data.ten, j->data.ten);
				swap(i->data.ngayKetThuc, j->data.ngayKetThuc);
				swap(i->data.trangthai, j->data.trangthai);
			}
		}
	}
	xuat_DanhSachCongViec(list);
}
void sapxep_TheoTen(Nodeptr& list) { //Selection sort
	for (Nodeptr i = list; i != NULL; i = i->link) {
		for (Nodeptr j = i->link; j != NULL; j = j->link) {
			if (strcmp(i->data.ten, j->data.ten) > 0) {
				swap(i->data.ten, j->data.ten);
				swap(i->data.ngayKetThuc, j->data.ngayKetThuc);
				swap(i->data.trangthai, j->data.trangthai);
			}
		}
	}
	xuat_DanhSachCongViec(list);
}
void sapxep_TheoTrangThai(Nodeptr& list) { //Sap xep du lieu theo trang thái
	for (Nodeptr i = list; i != NULL; i = i->link) {
		for (Nodeptr j = i->link; j != NULL; j = j->link) {
			if (i->data.trangthai == j->data.trangthai) {
				swap(i->data.ten, j->data.ten);
				swap(i->data.ngayKetThuc, j->data.ngayKetThuc);
				swap(i->data.trangthai, j->data.trangthai);
			}
		}
	}
	xuat_DanhSachCongViec(list);
}
void sapxep_TheoNgayKetThuc(Nodeptr& list) { //Bubble Sort
	for (Nodeptr i = list; i != NULL; i = i->link) {
		for (Nodeptr j = i->link; j != NULL; j = j->link) {
			// Chuy?n ??nh dung ngày k?t thúc thành s? ?? so sánh
			int iNgay, iThang, iNam, jNgay, jThang, jNam;
			sscanf(i->data.ngayKetThuc, "%d/%d/%d", &iNgay, &iThang, &iNam);
			sscanf(j->data.ngayKetThuc, "%d/%d/%d", &jNgay, &jThang, &jNam);

			if (iNam > jNam || (iNam == jNam && (iThang > jThang || (iThang == jThang && iNgay > jNgay)))) {
				swap(i->data.ten, j->data.ten);
				swap(i->data.ngayKetThuc, j->data.ngayKetThuc);
				swap(i->data.trangthai, j->data.trangthai);
			}
		}
	}
	xuat_DanhSachCongViec(list);
}
//6. Tìm Kiem công viec
//Tìm tuan tu
void tim_CongViec_TheoTen(Nodeptr list, char* ten) {
	Nodeptr p = list;
	bool isFound = false;
	while (p != NULL) {
		//Lay tu dau tiên
		char str1[50];
		for (int i = 0; i < strlen(ten); i++) {
			str1[i] = p->data.ten[i];
		}
		str1[strlen(ten)] = '\0';
		if (strcmp(str1, ten) == 0) { //So sánh tu dau tiên cua công viec
			isFound = true;
			cout << "ID: " << p->data.id << ", Ten: " << p->data.ten << ", ngay ket thuc: " << p->data.ngayKetThuc << ", trang thai: " << ((p->data.trangthai == 0) ? "hoan thanh" : "chua hoan thanh") << endl;
		}
		p = p->link;
	}
	if (isFound == false) cout << "Khong tim thay cong viec co ten " << ten;
}
void tim_CongViec_TheoId(Nodeptr list, int id) {
	Nodeptr p = list;
	bool isFound = false;
	while (p != NULL) {
		if (p->data.id == id) { //So sánh tu dau tien cua cong viec
			isFound = true;
			cout << "ID: " << p->data.id << ", Ten: " << p->data.ten << ", ngay ket thuc: " << p->data.ngayKetThuc << ", trang thai: " << ((p->data.trangthai == 0) ? "hoan thanh" : "chua hoan thanh") << endl;
		}
		p = p->link;
	}
	if (isFound == false) cout << "Khong tim thay cong viec co id " << id;
}
void tim_CongViec_TheoNgayKetThuc(Nodeptr list, char* ngayKetThuc) {
	Nodeptr p = list;
	bool isFound = false;
	while (p != NULL) {
		if (strcmp(p->data.ngayKetThuc, ngayKetThuc) == 0) { //So sánh tu dau tiên cua công viec
			isFound = true;
			cout << "ID: " << p->data.id << ", Ten: " << p->data.ten << ", ngay ket thuc: " << p->data.ngayKetThuc << ", trang thai: " << ((p->data.trangthai == 0) ? "hoan thanh" : "chua hoan thanh") << endl;
		}
		p = p->link;
	}
	if (isFound == false) cout << "Khong tim thay cong viec co ngay ket thuc " << ngayKetThuc;
}
void tim_CongViec_TheoTrangThai(Nodeptr list, int trangthai) {
	Nodeptr p = list;
	bool isFound = false;
	while (p != NULL) {
		if (p->data.trangthai == trangthai) { //So sánh tu dau tien cua cong viec
			isFound = true;
			cout << "ID: " << p->data.id << ", Ten: " << p->data.ten << ", ngay ket thuc: " << p->data.ngayKetThuc << ", trang thai: " << ((p->data.trangthai == 0) ? "hoan thanh" : "chua hoan thanh") << endl;
		}
		p = p->link;
	}
	if (isFound == false) cout << "Khong tim thay cong viec co trang thai " << trangthai;
}
//10. Xuat danh sách
void xuat_DanhSachCongViec(Nodeptr list) {
	cout << "--------------------------------------------------------------" << endl;
	cout << left << setw(10) << "ID" << setw(20) << "Ten" << setw(20) << "Ngay ket thuc" << setw(20) << "Trang thai" << endl;
	cout << "--------------------------------------------------------------" << endl;
	while (list != NULL) {
		cout << left << setw(10) << list->data.id << setw(20) << list->data.ten << setw(20) << list->data.ngayKetThuc << setw(20) << ((list->data.trangthai == 0) ? "hoan thanh" : "chua hoan thanh") << setw(10) << endl;
		list = list->link;
	}
	cout << "--------------------------------------------------------------" << endl;
}
//11,12. Luu tru du lieu trên file(file nhi phân, file van ban), khi chay chuong trình có the doc duoc du lieu không can nhap lai
bool ghiFile(Nodeptr list, const char* tenfile) {
	ofstream outFile(tenfile);
	if (!outFile.is_open()) {
		cout << "\nKhong the mo duoc file";
		return false;
	}
	Nodeptr p = list;
	while (p != NULL) {
		outFile << p->data.id << "," << p->data.ten << "," << p->data.ngayKetThuc << "," << p->data.trangthai << "\n";
		p = p->link;
	}

	outFile.close();
	return true;
}
bool docDanhSachCongViec(Nodeptr& list, const char* tenfile) {
	ifstream inFile(tenfile);
	if (!inFile.is_open()) {
		cout << "\nKhong mo duoc file";
		return false;
	}
	while (inFile) {
		CongViec cv;
		char temp[20];
		char* output;
		inFile.getline(temp, 20, ','); //doc cho den dau ,
		cv.id = strtol(temp, &output, 10); //Chuyen char sang int
		inFile.getline(cv.ten, 50, ','); //doc cho denn dau ,
		inFile.getline(cv.ngayKetThuc, 20, ','); //doc cho den dau ,
		inFile >> cv.trangthai; //doc cho den dau ,
		inFile.ignore(); // doc ký tu xuong dòng

		if (!inFile.eof()) {
			them_CongViec(list, cv);
		}
	}
	inFile.close();
	return true;
}
// Chuẩn hoá chuỗi
void xoa(char s[], int vitrixoa)
{
	int n = strlen(s);//gán n= do dài cua chuoi
	for (int i = vitrixoa; i < n; i++)//duyet chuoi tu vi trí can xóa
		s[i] = s[i + 1];
	s[n - 1] = '\0'; //ket thúc
}
void xoakt(char* s)
{
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			xoa(s, i);
			i--;
		}
	if (s[0] == ' ')
		xoa(s, 0);
	if (s[strlen(s) - 1] == ' ')
		xoa(s, strlen(s) - 1);
}
void xoaktRong(char* s) {
	if (strlen(s) == 0) {
		cout << "Chuoi rong, khong co gi de xoa.";
		return;
	}
	xoakt(s);
}
// Nhấn phím bất kỳ
void pressAnyKey() {
	cout << "\n\nBam phim bat ky de tiep tuc...";
	int key = _getch();//Cho phép gõ phim b?t kì
	system("cls"); // clear màn hình
}
// Cập nhật trạng thái toàn bộ danh sách
void capNhat_TrangThaiTuDong(Nodeptr& list) {
	time_t now = time(0);
	tm* currentDate = localtime(&now);

	Nodeptr p = list;
	while (p != NULL) {
		int endDay, endMonth, endYear;
		sscanf(p->data.ngayKetThuc, "%d/%d/%d", &endDay, &endMonth, &endYear);

		if (endYear < currentDate->tm_year + 1900 ||
			(endYear == currentDate->tm_year + 1900 && (endMonth < currentDate->tm_mon + 1 ||
				(endMonth == currentDate->tm_mon + 1 && endDay < currentDate->tm_mday)))) {
			// Neu ngày ket thúc da qua, cap nhat trang thái
			p->data.trangthai = 0; // da hoàn thành
		}
		p = p->link;
	}
}

void chuanHoaChuoi(char* str) {
	xoaktRong(str);
}