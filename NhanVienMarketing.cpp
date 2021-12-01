#include "NhanVienMarketing.h"

// NhanVienMarketing:: NhanVienMarketing () 
// :NhanVien(LuongCoBan, LuongThang, ID, Name, Address,NgaySinh, SoDienThoai) 
// {
//     this->LuongBonus= LuongBonus;
// }

// NhanVienMarketing::~NhanVienMarketing(){}

void NhanVienMarketing ::Nhap()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Nhap();
     wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Hệ Số KPI : ";
    wcin >> this->HeSoKPI;
    wcout << L"\t\t\t\t\t\t ════════════════════════════════════════════════════════════════════════════════════════════════ "<<endl;

}
void NhanVienMarketing::DocFile(wifstream &filein)
{
    NhanVien::DocFile(filein);
    filein >> this->HeSoKPI;
}

void NhanVienMarketing::setHeSoKPI(float kpi) {
    this->HeSoKPI = kpi;
}
void NhanVienMarketing::Update() {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Update();
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t7. Hệ Số KPI : ";
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t8. Trở lại MENU : ";
}
void NhanVienMarketing::DoUpdate(int chon) {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::DoUpdate(chon);
    if(chon == 7) {
        float kpi;
        wcout << L"\nNhập Hệ Số KPI mới : ";
        wcin >> kpi;
        system("cls");
        this->setHeSoKPI(kpi);
        wcout << L"\n\nNhấn phím bất kỳ để trở lại !";
        getch();
    }
}

long NhanVienMarketing::TinhLuong()
{
    return this->LuongCoBan *this->HeSoKPI;
}
void NhanVienMarketing::Xuat()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Xuat();
    wcout << L"Hệ Số KPI : " << this->HeSoKPI << endl;
    wcout << L"Lương nhân viên sau 1 tháng : " << NhanVienMarketing::TinhLuong() << endl;
}
void NhanVienMarketing::Xuatfile(wofstream &fileout)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for inputs
    NhanVien::Xuatfile(fileout);
    fileout << L"Hệ Số KPI : " << this->HeSoKPI << endl;
    fileout << L"Lương nhân viên sau 1 tháng : " << NhanVienMarketing::TinhLuong()<< endl;
}