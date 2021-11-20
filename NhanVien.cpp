#include "NhanVien.h"
// NhanVien::NhanVien(long LuongCoBan, long LuongThang, string ID, string Name, string Address, string NgaySinh, string SoDienThoai)
// {
//     this->LuongCoBan = LuongCoBan;
//     this->LuongThang = LuongThang;
//     this->ID = ID;
//     this->Name = Name;
//     this->Address = Address;
//     this->NgaySinh = NgaySinh;
//     this->SoDienThoai = SoDienThoai;
// }

// NhanVien ::~NhanVien(){
// }

void NhanVien ::setID(wstring ID)
{
    this->ID = ID;
}
wstring NhanVien ::getID()
{
    return this->ID;
}

void NhanVien ::setName(wstring Name)
{
    this->Name = Name;
}
wstring NhanVien ::getName()
{
    return this->Name;
}

void NhanVien::setNgaySinh(wstring NgaySinh)
{
    this->NgaySinh = NgaySinh;
}

wstring NhanVien::getNgaySinh()
{
    return this->NgaySinh;
}

void NhanVien::setAddress(wstring Address)
{
    this->Address = Address;
}

wstring NhanVien::getAddress()
{
    return this->Address;
}

void NhanVien::setSDT(wstring SoDienThoai)
{
    this->SoDienThoai = SoDienThoai;
}

wstring NhanVien::getSDT()
{
    return this->SoDienThoai;
}

void NhanVien::setLuongCB(long luong)
{
    this->LuongCoBan = luong;
}

long NhanVien::getLuongCB()
{
    return this->LuongCoBan;
}

wstring NhanVien::getChiNhanh()
{
    return this->ChiNhanh;
}

void NhanVien::Update()
{
}
void NhanVien::DoUpdate(int chon)
{
    if (chon == 1)
    {
        wstring id;
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhập ID sửa đổi : ";
        fflush(stdin);
        getline(wcin, id);
        system("cls");
        this->setID(id);
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t Nhấn phím bất kì để trở lại ! ";
        getch();
    }
    if (chon == 2)
    {
        wstring id;
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhập tên sửa đổi : ";
        fflush(stdin);
        getline(wcin, id);
        system("cls");
        this->setName(id);
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t Nhấn phím bất kì để trở lại ! ";
        getch();
    }
    if (chon == 3)
    {
        wstring id;
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhap ngày sinh sửa đổi : ";
        fflush(stdin);
        getline(wcin, id);
        system("cls");
        this->setNgaySinh(id);
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t Nhấn phím bất kì để trở lại ! ";
        getch();
    }
    if (chon == 4)
    {
        wstring id;
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhập ADDRESS sửa đổi : ";
        fflush(stdin);
        getline(wcin, id);
        system("cls");
        this->setAddress(id);
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t Nhấn phím bất kì để trở lại ! ";
        getch();
    }
    if (chon == 5)
    {
        wstring id;
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhập SODIENTHOAI sửa đổi  : ";
        fflush(stdin);
        getline(wcin, id);
        system("cls");
        this->setSDT(id);
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t Nhấn phím bất kì để trở lại ! ";
        getch();
    }
    if (chon == 6)
    {
        long luong;
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhập LUONGCOBAN sửa đổi : ";
        wcin >> luong;
        system("cls");
        this->setLuongCB(luong);
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t Nhấn phím bất kì để trở lại ! ";
        getch();
    }
}

void NhanVien ::Nhap()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    fflush(stdin);
    wcout << L"\n\n\n\n\n\n\t\t\t\t\t\t⪢⪢⪢════════════════════════════════⪢ NHẬP THÔNG TIN NHÂN VIÊN ⪡═══════════════════════════════⪡⪡⪡"<<endl;
    
    wcout << L"\t\t\t\t\t\t╔════════════════════════════════════════════════════════════════════════════════════════════════╗"<<endl;
    wcout << L"\t\t\t\t\t\t║                                                                                                ║"<<endl;
    wcout << L"\t\t\t\t\t\t⇩                                                                                                ⇩"<<endl;

    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập mã số : ";
    getline(wcin, this->ID);
    fflush(stdin);
    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập họ và tên : ";
    getline(wcin, this->Name);
    fflush(stdin);
    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập ngày sinh : ";
    getline(wcin, this->NgaySinh);
    fflush(stdin);
    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập số điện thoại : ";
    getline(wcin, this->SoDienThoai);
    fflush(stdin);
    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập địa chỉ : ";
    getline(wcin, this->Address);
    fflush(stdin);
    wcout << L"\n\t\t\t\t\t\t\t\t\t|☘ ༒ ☘|᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁᠁|☘ ༒ ☘|\n";
    wcout << L"\n\t\t\t\t\t\t\t\t\t\tNhập lương cơ bản : ";
    wcin >> this->LuongCoBan;
}

void NhanVien ::DocFile(wifstream &filein)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    filein.imbue(loc);
    getline(filein, ID, L',');
    filein.seekg(0, ios::cur);
    getline(filein, Name, L',');
    filein.seekg(0, ios::cur);
    getline(filein, NgaySinh, L',');
    filein.seekg(0, ios::cur);
    getline(filein, SoDienThoai, L',');
    filein.seekg(0, ios::cur);
    getline(filein, Address, L',');
    filein.seekg(0, ios::cur);
    getline(filein, ChiNhanh, L',');
    filein.seekg(0, ios::cur);
    filein >> LuongCoBan;

    wchar_t x;
    filein >> x;
}

void NhanVien ::Xuat()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    wcout << L"ID: " << this->ID << endl;
    wcout << L"Name: " << this->Name << endl;
    wcout << L"NgaySinh: " << this->NgaySinh << endl;
    wcout << L"SoDienThoai: " << this->SoDienThoai << endl;
    wcout << L"Address: " << this->Address << endl;
    wcout << L"LuongCoBan: " << this->LuongCoBan << endl;
}

void NhanVien ::Xuatfile(wofstream &fileout)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    fileout.imbue(loc);
    fileout << L"Mã số : " << this->ID << endl;
    fileout << L"Họ và tên : " << this->Name << endl;
    fileout << L"Ngày sinh : " << this->NgaySinh << endl;
    fileout << L"Số điện thoại : " << this->SoDienThoai << endl;
    fileout << L"Địa chỉ : " << this->Address << endl;
    fileout << L"Chi Nhánh : " << this->ChiNhanh << endl;
    fileout << L"Lương cơ bản : " << this->LuongCoBan << endl;
}
