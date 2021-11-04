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
    wcout << L"\n\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\tNhập lương tăng thêm : ";
    wcin >> this->LuongBonus;
}
void NhanVienMarketing::DocFile(wifstream &filein)
{
    NhanVien::DocFile(filein);
    filein >> LuongBonus;
}

void NhanVienMarketing::setLuongBonus(long luong) {
    this->LuongBonus = luong;
}
void NhanVienMarketing::Update() {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Update();
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t7. Lương Bonus : ";
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t8. Trở lại MENU : ";
}
void NhanVienMarketing::DoUpdate(int chon) {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::DoUpdate(chon);
    if(chon == 7) {
        long luong;
        wcout << L"\nNhập LUONGBONUS sửa đổi : ";
        wcin >> luong;
        system("cls");
        this->setLuongBonus(luong);
        wcout << L"\n\nNhấn phím bất kì để trở lại !";
        getch();
    }
}

long NhanVienMarketing::TinhLuong()
{
    return this->LuongCoBan +this->LuongBonus;
}
void NhanVienMarketing::Xuat()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Xuat();
    wcout << L"Lương tăng thêm: " << this->LuongBonus << endl;
    wcout << L"Lương nhận được sau 1 tháng : " << NhanVienMarketing::TinhLuong() << endl;
}
void NhanVienMarketing::Xuatfile(wofstream &fileout)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for inputs
    NhanVien::Xuatfile(fileout);
    fileout << L"Lương tăng thêm : " << this->LuongBonus << endl;
    fileout << L"Lương nhận được sau 1 tháng : " << NhanVienMarketing::TinhLuong()<< endl;
}