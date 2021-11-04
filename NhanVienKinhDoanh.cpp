#include "NhanVienKinhDoanh.h"

// NhanVienKinhDoanh:: NhanVienKinhDoanh () 
// :NhanVien(LuongCoBan, LuongThang, ID, Name, Address,NgaySinh, SoDienThoai) 
// {
//     this->HeSoLuong= HeSoLuong;
// }

// NhanVienKinhDoanh::~NhanVienKinhDoanh(){}


void NhanVienKinhDoanh ::Nhap()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Nhap();
    wcout << L"\n\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\tNhập hệ số lương : ";
    wcin >> this->HeSoLuong;
}
void NhanVienKinhDoanh::DocFile(wifstream &filein)
{
    NhanVien::DocFile(filein);
    filein >> HeSoLuong;
}

long NhanVienKinhDoanh::TinhLuong()
{
    return this->LuongCoBan * this->HeSoLuong;
}

void NhanVienKinhDoanh::Update() {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Update();
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t7. HeSoLuong : ";
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t8. Trở lại MENU : ";
}
void NhanVienKinhDoanh::DoUpdate(int chon) {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::DoUpdate(chon);
    if(chon == 7) {
        float hs;
        wcout << L"\nNhập DAYWORKING sửa đổi : ";
        wcin >> hs;
        system("cls");
        this->setHSL(hs);
        wcout << L"\n\nNhấn phím bất kì để trở lại !";
        getch();
    }
}
void NhanVienKinhDoanh::setHSL(float heso) {
    this->HeSoLuong = heso;
}

void NhanVienKinhDoanh::Xuat()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Xuat();
    wcout << L"Hệ số lương : " << this->HeSoLuong << endl;
    wcout << L"Lương nhận được sau 1 tháng : " << NhanVienKinhDoanh::TinhLuong() << endl;
}
void NhanVienKinhDoanh::Xuatfile(wofstream &fileout)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for inputs
    NhanVien::Xuatfile(fileout);
    fileout << L"Hệ số lương : " << this->HeSoLuong << endl;
    fileout << L"Lương nhận được sau 1 tháng : " << NhanVienKinhDoanh::TinhLuong() << endl;
}