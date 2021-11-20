#include "NhanVienSanXuat.h"

// NhanVienSanXuat:: NhanVienSanXuat () 
// :NhanVien(LuongCoBan, LuongThang, ID, Name, Address,NgaySinh, SoDienThoai) 
// {
//     this->SoSanPham= SoSanPham;
// }

// NhanVienSanXuat::~NhanVienSanXuat(){}

void NhanVienSanXuat ::Nhap()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Nhap();
        wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập số sản phẩm : ";
    wcin >> this->SoSanPham;
    wcout << L"\t\t\t\t\t\t ════════════════════════════════════════════════════════════════════════════════════════════════ "<<endl;

}
void NhanVienSanXuat::DocFile(wifstream &filein)
{
    NhanVien::DocFile(filein);
    filein >> SoSanPham;
}

void NhanVienSanXuat::Update() {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Update();
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t7. Số sản phẩm : ";
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t8. Trở lại MENU : ";
}
void NhanVienSanXuat::DoUpdate(int chon) {
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::DoUpdate(chon);
    if(chon == 7) {
        int sp;
        wcout << L"\nNhập Số Sản Phẩm mới : ";
        wcin >> sp;
        system("cls");
        this->setSSP(sp);
        wcout << L"\n\nNhấn phím bất kì để trở lại !";
        getch();
    }
}
void NhanVienSanXuat::setSSP(int ssp) {
    this->SoSanPham = ssp;
}

long NhanVienSanXuat::TinhLuong()
{
    return this->LuongCoBan + 50000 * this->SoSanPham;
}
void NhanVienSanXuat::Xuat()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Xuat();
    wcout << L"Số sản phẩm : " << this->SoSanPham << endl;
    wcout << L"Lương nhận được sau 1 tháng : " << NhanVienSanXuat::TinhLuong() << endl;
}
void NhanVienSanXuat::Xuatfile(wofstream &fileout)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for inputs
    NhanVien::Xuatfile(fileout);
    fileout << L"số sản phẩm : " << this->SoSanPham << endl;
    fileout << L"Lương nhận được sau 1 tháng : " << NhanVienSanXuat::TinhLuong() << endl;
}