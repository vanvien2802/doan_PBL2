#include "NhanVienVanPhong.h"

// NhanVienVanPhong:: NhanVienVanPhong ()
// :NhanVien(LuongCoBan, LuongThang, ID, Name, Address,NgaySinh, SoDienThoai)
// {
//     this->DayWorking= DayWorking;
// }

// NhanVienVanPhong::~NhanVienVanPhong(){}

void NhanVienVanPhong ::Nhap()
{
    _setmode(_fileno(stdout), _O_WTEXT); // needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  // needed for input
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
        if (this->ID[0] == 'V' && this->ID[1] == 'P')
        {
            break;
        }
        else
        {
            wcout << L"\n\t\t\t\t\t\t\t\tERROR!!! Mã số phải bắt đầu bằng kí tự 'VP' + Số thứ tự ! Vui lòng nhập lại !";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Mã Số : ";
            getline(wcin, this->ID);
            fflush(stdin);
        }
    };
    NhanVien::Nhap();
    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập số ngày làm : ";
    wcin >> this->DayWorking;
    while (true)
    {
        if (DayWorking < 1 && DayWorking > 31)
        {
            wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tERROR !!!";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập số ngày làm : ";
            wcin >> this->DayWorking;
        }
        else
            break;
    }

    wcout << L"\n\t\t\t\t\t\t╚════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
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

bool NhanVienVanPhong::checkID(wstring id)
{
    if (id[0] == 'V' && id[1] == 'P')
    {
        return true;
    }
    else
    {
        wcout << L"\n\n\t\t\t\t\t\t\t\tMã số phải bắt đầu bằng 'VP' + Số thứ tự < 10000 ! Vui lòng nhập lại ! ";
        return false;
    }
}

void NhanVienVanPhong::DoUpdateID()
{
    _setmode(_fileno(stdout), _O_WTEXT); // needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  // needed for input

    bool check = false;
    wstring id;
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
    fflush(stdin);
    getline(wcin, id);
    while (true)
    {
        if (id[0] == 'V' && id[1] == 'P')
        {
            break;
        }
        else if(id.length() > 6)
        {
            wcout << L"\n\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'VP' + Số thứ tự < 10000 ! Vui lòng nhập lại !";
            wcout << L"\n\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
            fflush(stdin);
            getline(wcin, id);
        }
        else
        {
            wcout << L"\n\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng 'VP' + Số thứ tự < 10000 ! Vui lòng nhập lại ! ";
            wcout << L"\n\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
            fflush(stdin);
            getline(wcin, id);
        }
    }
    this->setID(id);
}

void NhanVienVanPhong::DoUpdate(int chon)
{
    _setmode(_fileno(stdout), _O_WTEXT); // needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  // needed for input
    NhanVien::DoUpdate(chon);
    if (chon == 7)
    {
        int day;
        wcout << L"\nNhập DAYWORKING sửa đổi : ";
        wcin >> day;
        system("cls");
        this->setDW(day);
        wcout << L"\n\nNhấn phím bất kì để trở lại !";
        getch();
    }
}

long NhanVienVanPhong::TinhLuong()
{
    return this->LuongCoBan - (30 - this->DayWorking) * (this->LuongCoBan / 30);
}
void NhanVienVanPhong::Xuatfile(wofstream &fileout,int kt)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for inputS
    NhanVien::Xuatfile(fileout,kt);
    if(kt ==1)
    {
        fileout <<this->DayWorking;
    }
    else fileout <<this->DayWorking << endl;
}