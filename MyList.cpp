#include "MyList.h"
void MyList::DocDanhSachNhanVien(list &l, wifstream &filein)
{
    NhanVien *x = NULL;
    wstring IDx;
    if (filein.fail())
    {
        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tFailed to open this file!" << endl;
        getch();
        return;
    }
    while (!filein.eof())
    {
        filein >> IDx;
        if (IDx[0] == 'V')
        {
            x = new NhanVienVanPhong();
            x->setID(IDx);
            x->DocFile(filein);
        }
        else if (IDx[0] == 'S')
        {
            x = new NhanVienSanXuat();
            x->setID(IDx);
            x->DocFile(filein);
        }
        else if (IDx[0] == 'M')
        {
            x = new NhanVienMarketing();
            x->setID(IDx);
            x->DocFile(filein);
        }
        else if (IDx[0] == 'K')
        {
            x = new NhanVienKinhDoanh();
            x->setID(IDx);
            x->DocFile(filein);
        }
        ThemVaoCuoi(l, x);
    }
    wcout << L"\n\n\n\n\t\t\t\t\t\t\t\t\t\tĐọc File Thành Công !";
    wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhấn Phím Bất Kì Để Trở Lại !";
    getch();
}
void MyList::KhoiTao(list &l)
{
    l.pHead = l.pTail = NULL;
}
node *MyList::KhoitaoNode(NhanVien *x)
{
    node *p = new node;
    p->data = x;
    p->pNext = NULL;
    p->pPre = NULL;
    return p;
}

bool MyList::CheckID(list &l, wstring s)
{
    node *p = l.pHead;
    bool kq = false;
    while (p != NULL)
    {
        if (p->data->getID() == s)
        {
            kq = true;
            break;
        }
        p = p->pNext;
    }
    return kq;
}
void MyList::UpdateID(list &l, NhanVien *x)
{
    x->DoUpdateID();
    bool kq = CheckID(l, x->getID());
    while (kq == true)
    {
        wcout << L"\n\t\t\t\t\t\t\t\t\tID đã bị trùng !! Vui lòng nhập lại ID !";
        wstring id;
        do
        {
            wcout << L"\n\t\t\t\t\t\t\t\t\tNhập lại ID khác : ";
            fflush(stdin);
            getline(wcin, id);
        } while (x->checkID(id) == false);

        kq = CheckID(l, id);
        if (kq == false)
        {
            wcout << L"\n\t\t\t\t\t\t\t\t\t\tID hợp lệ !! Đã UPDATE ID thành công !";
            x->setID(id);
        }
    }
}
void MyList::ThemVaoCuoi(list &l, NhanVien *x)
{
    bool kq = CheckID(l, x->getID());
    while (kq == true)
    {
        wcout << L"\n\t\t\t\t\t\t\t\tID đã bị trùng !! Vui lòng nhập lại ID !";
        x->DoUpdateID();
        kq = CheckID(l, x->getID());
        if (kq == false)
        {
            x->setID(x->getID());
            wcout << L"\n\t\t\t\t\t\t\t\tID hợp lệ !! ";
        }
    }
    node *p = KhoitaoNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->pPre = l.pTail;
        l.pTail = p;
    }
}

void MyList::XoaNodeTheoMaSo(list &l, wstring ma)
{
    node *pDel = l.pHead;
    if (l.pHead == NULL)
    {
        wcout << L"Không có dữ liệu để xóa !!! " << endl;
    }
    else
    {
        node *pT = NULL;
        while (pDel != NULL)
        {
            if (pDel->data->getID() == ma)
            {
                break;
            }
            pT = pDel;
            pDel = pDel->pNext;
        }
        if (pDel == NULL)
        {
            wcout << L"Không tìm thấy ID của nhân viên !!! " << endl;
        }
        else
        {
            if (pDel == l.pHead)
            {
                l.pHead = l.pHead->pNext;
                l.pHead->pPre = NULL;
                pDel->pNext = NULL;
                pDel->pPre = NULL;
                delete pDel;
                pDel = NULL;
            }
            else if (pDel->pNext == NULL)
            {
                l.pTail = pT;
                pT->pNext = NULL;
                pDel->pNext = NULL;
                pDel->pPre = NULL;
                delete pDel;
                pDel = NULL;
            }
            else
            {
                pT->pNext = pDel->pNext;
                pDel->pNext->pPre = pT;
                pDel->pNext = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}
void MyList::XoaNodeTheoTen(list &l, wstring ten)
{
    node *pDel = l.pHead;
    if (l.pHead == NULL)
    {
        wcout << L"Không có dữ liệu để xóa !!! " << endl;
    }
    else
    {
        node *pT = NULL;
        while (pDel != NULL)
        {
            if (pDel->data->getName() == ten)
            {
                break;
            }
            pT = pDel;
            pDel = pDel->pNext;
        }
        if (pDel == NULL)
        {
            wcout << L"Không tìm thấy TÊN của nhân viên !!! " << endl;
        }
        else
        {
            if (pDel == l.pHead)
            {
                l.pHead = l.pHead->pNext;
                l.pHead->pPre = NULL;
                pDel->pNext = NULL;
                pDel->pPre = NULL;
                delete pDel;
                pDel = NULL;
            }
            else if (pDel->pNext == NULL)
            {
                l.pTail = pT;
                pT->pNext = NULL;
                pDel->pNext = NULL;
                pDel->pPre = NULL;
                delete pDel;
                pDel = NULL;
            }
            else
            {
                pT->pNext = pDel->pNext;
                pDel->pNext->pPre = pT;
                pDel->pNext = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}

void MyList::XuatDanhSach(list l, int x)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);

    wcout << L"┌──────┬──────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┐";
    wcout << setw(1) << left << L"\n│" << setw(6) << left << L"  STT" << setw(1) << left << L"│" << setw(14) << left << L"    Mã số" << L"│" << setw(24) << left << L"      Họ và tên" << L"│" << setw(24) << left << L"      Ngày sinh" << L"│" << setw(24) << left << L"      Số điện thoại" << L"│" << setw(24) << left << L"        Địa chỉ" << L"│" << setw(24) << left << L"      Lương cơ bản" << L"│" << setw(24) << left << L"      Lương tháng" << L"│" << setw(24) << left << L"      Chi Nhánh" << L"│";

    int dem = 1;
    node *k;
    k = l.pHead;
    while (k != NULL)
    {
        wcout << L"\n├──────┼──────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┤";
        wcout << setw(1) << left << L"\n│" << L"  " << setw(4) << left << dem << setw(1) << left << L"│" << L"   " << setw(11) << left << k->data->getID() << L"│" << L"    " << setw(20) << left << k->data->getName() << L"│" << L"    " << setw(20) << left << k->data->getNgaySinh() << L"│" << L"    " << setw(20) << left << k->data->getSDT() << L"│" << L"    " << setw(20) << left << k->data->getAddress() << L"│" << L"    " << setw(20) << left << k->data->getLuongCB() << L"│" << L"    " << setw(20) << left << k->data->TinhLuong() << L"│" << "    " << setw(20) << left << k->data->getChiNhanh() << L"│";
        dem++;
        k = k->pNext;
    }
    wcout << L"\n└──────┴──────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┘";
}

void MyList::XuatDanhSachVaoFile(list &l, wofstream &fileout1)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    fileout1.imbue(loc);
    fileout1 << L"\n                                                         __________________________Danh Sách Nhân Viên__________________________\n\n " << endl;

    fileout1 << L"┌──────┬──────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┐";
    fileout1 << setw(1) << left << L"\n│" << setw(6) << left << L"  STT" << setw(1) << left << L"│" << setw(14) << left << L"    Mã số" << L"│" << setw(24) << left << L"      Họ và tên" << L"│" << setw(24) << left << L"      Ngày sinh" << L"│" << setw(24) << left << L"      Số điện thoại" << L"│" << setw(24) << left << L"        Địa chỉ" << L"│" << setw(24) << left << L"      Lương cơ bản" << L"│" << setw(24) << left << L"      Lương tháng" << L"│" << setw(24) << left << L"      Chi Nhánh" << L"│";

    int dem = 1;
    node *k;
    k = l.pHead;
    while (k != NULL)
    {
        fileout1 << L"\n├──────┼──────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┤";
        fileout1 << setw(1) << left << L"\n│" << L"  " << setw(4) << left << dem << setw(1) << left << L"│" << L"   " << setw(11) << left << k->data->getID() << L"│" << L"    " << setw(20) << left << k->data->getName() << L"│" << L"    " << setw(20) << left << k->data->getNgaySinh() << L"│" << L"    " << setw(20) << left << k->data->getSDT() << L"│" << L"    " << setw(20) << left << k->data->getAddress() << L"│" << L"    " << setw(20) << left << k->data->getLuongCB() << L"│" << L"    " << setw(20) << left << k->data->TinhLuong() << L"│" << "    " << setw(20) << left << k->data->getChiNhanh() << L"│";
        dem++;
        k = k->pNext;
    }
    fileout1 << L"\n└──────┴──────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┘";
}
void MyList::XuatDanhSachVaoFileX(list &l, wofstream &fileout2)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    fileout2.imbue(loc);
    node *k;
    k = l.pHead;
    int kt = 0;
    while (k != NULL)
    {
        if (k == l.pTail)
        {
            kt = 1;
            k->data->Xuatfile(fileout2, kt);
            break;
        }
        k->data->Xuatfile(fileout2, kt);
        k = k->pNext;
    }
}