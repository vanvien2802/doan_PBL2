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
    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Số Hợp Đồng : ";
    wcin >> this->SoHopDong;
    wcout << L"\t\t\t\t\t\t ════════════════════════════════════════════════════════════════════════════════════════════════ "<<endl;

}
void NhanVienKinhDoanh::DocFile(wifstream &filein)
{
    NhanVien::DocFile(filein);
    filein >> this->SoHopDong;
}

long NhanVienKinhDoanh::TinhLuong()
{
    return this->LuongCoBan + this->SoHopDong*100000;
}

void NhanVienKinhDoanh::Update() {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Update();
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t7. Số Hợp Đồng : ";
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t8. Trở lại MENU : ";
}
void NhanVienKinhDoanh::DoUpdate(int chon) {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::DoUpdate(chon);
    if(chon == 7) {
        int skh;
        wcout << L"\nNhập Số Hợp Đồng mới : ";
        wcin >> skh;
        system("cls");
        this->setSHD(skh);
        wcout << L"\n\nNhấn phím bất kỳ để trở lại !";
        getch();
    }
}
void NhanVienKinhDoanh::setSHD(int skh) {
    this->SoHopDong = skh;
}

void NhanVienKinhDoanh::Xuat()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Xuat();
    wcout << L"Số Hợp Đồng : " << this->SoHopDong << endl;
    wcout << L"Lương nhân viên sau 1 tháng : " << NhanVienKinhDoanh::TinhLuong() << endl;
}
void NhanVienKinhDoanh::Xuatfile(wofstream &fileout)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for inputs
    NhanVien::Xuatfile(fileout);
    fileout << L"Số Hợp Đồng : " << this->SoHopDong << endl;
    fileout << L"Lương nhân viên sau 1 tháng : " << NhanVienKinhDoanh::TinhLuong() << endl;
}