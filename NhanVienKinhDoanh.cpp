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
        if (this->ID[0] == 'K' && this->ID[1] == 'D')
        {
            break;
        }
        else
        {
            wcout << L"\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'KD' + Số tự nhiên ! Vui lòng nhập lại ! ";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Mã Số : ";
            getline(wcin, this->ID);
            fflush(stdin);
        }
    };
    NhanVien::Nhap();
    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Số Hợp Đồng : ";
    wcin >> this->SoHopDong;
    while (true)
    {
        if (SoHopDong < 1)
        {
            wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tERROR !!!";
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập Số Hợp Đồng : ";
            wcin >> this->SoHopDong;
        }
        else
            break;
    }

    wcout << L"\n\t\t\t\t\t\t╚════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
}
void NhanVienKinhDoanh::DocFile(wifstream &filein)
{
    NhanVien::DocFile(filein);
    filein >> this->SoHopDong;
}

long NhanVienKinhDoanh::TinhLuong()
{
    return this->LuongCoBan + this->SoHopDong * 100000;
}

void NhanVienKinhDoanh::Update()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    NhanVien::Update();
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t7. Số Hợp Đồng : ";
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t8. Trở lại MENU : ";
}

bool NhanVienKinhDoanh::checkID(wstring id)
{
    if (id[0] == 'K' && id[1] == 'D')
    {
        return true;
    }
    else
    {
        wcout << L"\n\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'KD' + Số thứ tự < 10000 ! Vui lòng nhập lại ! ";
        return false;
    }
}

void NhanVienKinhDoanh::DoUpdateID()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    wstring id;
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
    fflush(stdin);
    getline(wcin, id);
    while (true)
    {
        if (id[0] == 'K' && id[1] == 'D')
        {
            break;
        }
        else if(id.length() > 6)
        {
            wcout << L"\n\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'KD' + Số thứ tự < 10000 ! Vui lòng nhập lại !";
            wcout << L"\n\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
            fflush(stdin);
            getline(wcin, id);
        }
        else
        {
            wcout << L"\n\n\t\t\t\t\t\t\t\tERROR !!! Mã số phải bắt đầu bằng kí tự 'KD' + Số thứ tự < 10000 ! Vui lòng nhập lại ! ";
            wcout << L"\n\t\t\t\t\t\t\t\tNhập Mã Số mới : ";
            fflush(stdin);
            getline(wcin, id);
        }
    }
    this->setID(id);
}
void NhanVienKinhDoanh::DoUpdate(int chon)
{
    _setmode(_fileno(stdout), _O_WTEXT); // needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  // needed for input
    NhanVien::DoUpdate(chon);
    if (chon == 7)
    {
        int hs;
        wcout << L"\nNhập Số Hợp Đồng sửa đổi : ";
        wcin >> hs;
        system("cls");
        this->setSHD(hs);
        wcout << L"\n\nNhấn phím bất kì để trở lại !";
        getch();
    }
}
void NhanVienKinhDoanh::setSHD(int skh)
{
    this->SoHopDong = skh;
}

void NhanVienKinhDoanh::Xuatfile(wofstream &fileout,int kt)
{
    NhanVien::Xuatfile(fileout,kt);
    if(kt==1)
    {
        fileout << this->SoHopDong ;
    }
    else fileout << this->SoHopDong <<endl;
}