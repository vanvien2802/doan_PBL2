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
        if (this->ID[0] == 'M')
        {
            break;
        }
        else
        {
            wcout << L"\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'M' + Số thứ tự ! Vui lòng nhập lại ";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Mã Số : ";
            getline(wcin, this->ID);
            fflush(stdin);
        }
    };
    NhanVien::Nhap();
    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Hệ Số KPI : ";
    wcin >> this->HeSoKPI;
    while (true)
    {
        if (HeSoKPI < 1)
        {
            wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tERROR !!!";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Hệ Số KPI : ";
            wcin >> this->HeSoKPI;
        }
        else
            break;
    }
    wcout << L"\n\t\t\t\t\t\t╚════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
}
void NhanVienMarketing::DocFile(wifstream &filein)
{
    NhanVien::DocFile(filein);
    filein >> this->HeSoKPI;
}

void NhanVienMarketing::setHeSoKPI(float kpi)
{
    this->HeSoKPI = kpi;
}
void NhanVienMarketing::Update()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Update();
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t7. Hệ Số KPI : ";
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t8. Trở lại MENU : ";
}

bool NhanVienMarketing::checkID(wstring id)
{
    if (id[0] == 'M')
    {
        return true;
    }
    else
    {
        wcout << L"\n\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'M' + Số thứ tự < 10000 ! Vui lòng nhập lại !";
        return false;
    }
}

void NhanVienMarketing::DoUpdateID()
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
        if (id[0] == 'M')
        {
            break;
        }
        else if(id.length() > 5)
        {
            wcout << L"\n\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'M' + Số thứ tự < 10000 ! Vui lòng nhập lại !";
            wcout << L"\n\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
            fflush(stdin);
            getline(wcin, id);
        }
        else
        {
            wcout << L"\n\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'M' + Số thứ tự < 10000 ! Vui lòng nhập lại !";
            wcout << L"\n\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
            fflush(stdin);
            getline(wcin, id);
        }
    }
    this->setID(id);
}

void NhanVienMarketing::DoUpdate(int chon)
{
    _setmode(_fileno(stdout), _O_WTEXT); // needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  // needed for input
    NhanVien::DoUpdate(chon);
    if (chon == 7)
    {
        float luong;
        wcout << L"\nNhập Hệ Số KPI sửa đổi : ";
        wcin >> luong;
        system("cls");
        this->setHeSoKPI(luong);
        wcout << L"\n\nNhấn phím bất kì để trở lại !";
        getch();
    }
}

long NhanVienMarketing::TinhLuong()
{
    return this->LuongCoBan * this->HeSoKPI;
}
void NhanVienMarketing::Xuatfile(wofstream &fileout, int kt)
{
    NhanVien::Xuatfile(fileout,kt);
    if(kt==1)
    {
        fileout <<this->HeSoKPI;
    }
    else fileout <<this->HeSoKPI << endl;
}