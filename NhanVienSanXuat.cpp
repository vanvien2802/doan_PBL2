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
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    fflush(stdin);
    wcout << L"\n\n\n\n\n\n\t\t\t\t\t\t⪢⪢⪢════════════════════════════════⪢ NHẬP THÔNG TIN NHÂN VIÊN ⪡═══════════════════════════════⪡⪡⪡" << endl;

    wcout << L"\t\t\t\t\t\t╔════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    wcout << L"\t\t\t\t\t\t║                                                                                                ║" << endl;
    wcout << L"\t\t\t\t\t\t⇩                                                                                                ⇩" << endl;

    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";

    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Mã Số : ";
    getline(wcin, this->ID);
    fflush(stdin);
    while (true)
    {
        if (this->ID[0] == 'S' && this->ID[1] == 'X')
        {
            break;
        }
        else
        {
            wcout << L"\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'SX' + Số thứ tự ! Vui lòng nhập lại";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Mã Số : ";
            getline(wcin, this->ID);
            fflush(stdin);
        }
    };
    NhanVien::Nhap();
    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập số sản phẩm : ";
    wcin >> this->SoSanPham;
    while (true)
    {
        if (SoSanPham < 1)
        {
            wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tERROR !!!";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập số sản phẩm : ";
            wcin >> this->SoSanPham;
        }
        else
            break;
    }

    wcout << L"\n\t\t\t\t\t\t╚════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
}
void NhanVienSanXuat::DocFile(wifstream &filein)
{
    NhanVien::DocFile(filein);
    filein >> SoSanPham;
}

void NhanVienSanXuat::Update()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Update();
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t7. Số sản phẩm : ";
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t8. Trở lại MENU : ";
}

bool NhanVienSanXuat::checkID(wstring id)
{
    if (id[0] == 'S' && id[1] == 'X')
    {

        return true;
    }
    else
    {
        wcout << L"\n\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'SX' + Số thứ tự < 10000 ! Vui lòng nhập lại !";
        return false;
    }
}

void NhanVienSanXuat::DoUpdateID()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input

    bool check = false;
    wstring id;
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
    fflush(stdin);
    getline(wcin, id);
    while (true)
    {
        if (id[0] == 'S' && id[1] == 'X')
        {
            break;
        }
        else if (id.length() > 6)
        {
            wcout << L"\n\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'SX' + Số thứ tự < 10000 ! Vui lòng nhập lại !";
            wcout << L"\n\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
            fflush(stdin);
            getline(wcin, id);
        }
        else
        {
            wcout << L"\n\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'SX' + Số thứ tự < 10000 ! Vui lòng nhập lại !";
            wcout << L"\n\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
            fflush(stdin);
            getline(wcin, id);
        }
    }
    this->setID(id);
}
void NhanVienSanXuat::DoUpdate(int chon)
{
    _setmode(_fileno(stdout), _O_WTEXT); // needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  // needed for input
    NhanVien::DoUpdate(chon);
    if (chon == 7)
    {
        int sp;
        wcout << L"\nNhập SOSANPHAM sua doi : ";
        wcin >> sp;
        system("cls");
        this->setSSP(sp);
        wcout << L"\n\nNhấn phím bất kì để trở lại !";
        getch();
    }
}

void NhanVienSanXuat::setSSP(int ssp)
{
    this->SoSanPham = ssp;
}

long NhanVienSanXuat::TinhLuong()
{
    return this->LuongCoBan + 50000 * this->SoSanPham;
}
void NhanVienSanXuat::Xuatfile(wofstream &fileout,int kt)
{
    NhanVien::Xuatfile(fileout,kt);
    if(kt==1)
    {
        fileout << this->SoSanPham;
    }
    else fileout << this->SoSanPham << endl;
}