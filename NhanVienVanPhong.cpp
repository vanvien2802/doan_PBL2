#include "NhanVienVanPhong.h"

// NhanVienVanPhong:: NhanVienVanPhong () 
// :NhanVien(LuongCoBan, LuongThang, ID, Name, Address,NgaySinh, SoDienThoai) 
// {
//     this->DayWorking= DayWorking;
// }

// NhanVienVanPhong::~NhanVienVanPhong(){}

void NhanVienVanPhong ::Nhap()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Nhap();
        wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập số ngày làm : ";
    wcin >> this->DayWorking;
    wcout << L"\t\t\t\t\t\t ════════════════════════════════════════════════════════════════════════════════════════════════ "<<endl;

}
void NhanVienVanPhong::DocFile(wifstream &filein)
{
    NhanVien::DocFile(filein);
    filein >> DayWorking;
}

void NhanVienVanPhong::setDW(int day)
{
    this->DayWorking = day;
}
void NhanVienVanPhong::Update()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Update();
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t7. DayWorking : ";
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t8. Trở lại MENU : ";
}
void NhanVienVanPhong::DoUpdate(int chon) {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::DoUpdate(chon);
    if(chon == 7) {
        int day;
        wcout << L"\nNhập DAYWORKING mới : ";
        wcin >> day;
        system("cls");
        this->setDW(day);
        wcout << L"\n\nNhấn phím bất kì để trở lại !";
        getch();
    }
}


long NhanVienVanPhong::TinhLuong()
{
    return this->LuongCoBan- (30 - this->DayWorking)*(this->LuongCoBan/30);
}
void NhanVienVanPhong::Xuat()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Xuat();
    wcout << L"Số ngày làm : " << this->DayWorking << endl;
    wcout << L"Lương nhận được sau 1 tháng : " << this->NhanVienVanPhong::TinhLuong() << endl;
}
void NhanVienVanPhong::Xuatfile(wofstream &fileout)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for inputs
    NhanVien::Xuatfile(fileout);
    fileout << L"Số ngày làm : " << this->DayWorking << endl;
    fileout << L"Lương nhận được sau 1 tháng : " << this->NhanVienVanPhong::TinhLuong() << endl;
}