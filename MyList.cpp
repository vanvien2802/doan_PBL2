#include "MyList.h"
void MyList::DocDanhSachNhanVien(list &l, wifstream &filein)
{
    NhanVien *x = NULL;
    wchar_t type;
    while (!filein.eof())
    {
        filein >> type;
        filein.seekg(0, ios::cur);
        if (type == 'V')
        {
            x = new NhanVienVanPhong();
            x->DocFile(filein);
        }
        else if (type == 'S')
        {
            x = new NhanVienSanXuat();
            x->DocFile(filein);
        }
        else if (type == 'M')
        {
            x = new NhanVienMarketing();
            x->DocFile(filein);
        }
        else if (type == 'K')
        {
            x = new NhanVienKinhDoanh();
            x->DocFile(filein);
        }
        ThemVaoCuoi(l, x);
    }
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
void MyList::ThemVaoCuoi(list &l, NhanVien *x)
{
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
            //wcout << L"Đã Xóa nhân viên !!! " << endl;
        }
    }
}
void MyList::XoaNodeTheoTen(list &l,wstring ten) {
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
            //wcout << L"Đã Xóa nhân viên !!! " << endl;
        }
    }
}

void MyList::XuatDanhSach(list l, int x)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    wcout << L"\n                                                         __________________________Danh Sách Nhân Viên__________________________\n\n " << endl;

    wcout << L"┌──────┬──────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┐";
    wcout << setw(1) << left << L"\n│" << setw(6) << left << L"  STT" << setw(1) << left << L"│" << setw(14) << left << L"    Mã số" << L"│" << setw(24) << left << L"      Họ và tên" << L"│" << setw(24) << left << L"      Ngày sinh" << L"│" << setw(24) << left << L"      Số điện thoại" << L"│" << setw(24) << left << L"        Địa chỉ" << L"│" << setw(24) << left << L"      Lương cơ bản" << L"│" << setw(24) << left << L"      Lương tháng" << L"│" << setw(24) << left << L"      Chi Nhánh" << L"│";

    int dem = 1;
    node *k;
    k = l.pHead;
    while (k != NULL)
    {
        wcout << L"\n├──────┼──────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┤";
        wcout << setw(1) << left << L"\n│" <<L"  "<< setw(4) << left << dem << setw(1) << left << L"│" <<L"   "<< setw(11) << left <<k->data->getID() << L"│" <<L"    "<< setw(20) << left <<k->data->getName() << L"│" <<L"    "<< setw(20) << left <<k->data->getNgaySinh() << L"│" <<L"    "<< setw(20) << left <<k->data->getSDT() << L"│" <<L"    "<< setw(20) << left <<k->data->getAddress() << L"│" <<L"    "<< setw(20) << left <<k->data->getLuongCB() << L"│" <<L"    "<< setw(20) << left<<k->data->TinhLuong() << L"│" <<"    " <<setw(20) << left<<k->data->getChiNhanh() << L"│";
        dem++;
        k = k->pNext;
    }
    wcout << L"\n└──────┴──────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┘";

}

void MyList::XuatDanhSachVaoFile(list &l, wofstream &fileout)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    fileout.imbue(loc);
    fileout << L"\n                                                         __________________________Danh Sách Nhân Viên__________________________\n\n " << endl;

    fileout << L"┌──────┬──────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┐";
    fileout << setw(1) << left << L"\n│" << setw(6) << left << L"  STT" << setw(1) << left << L"│" << setw(14) << left << L"    Mã số" << L"│" << setw(24) << left << L"      Họ và tên" << L"│" << setw(24) << left << L"      Ngày sinh" << L"│" << setw(24) << left << L"      Số điện thoại" << L"│" << setw(24) << left << L"        Địa chỉ" << L"│" << setw(24) << left << L"      Lương cơ bản" << L"│" << setw(24) << left << L"      Lương tháng" << L"│" << setw(24) << left << L"      Chi Nhánh" << L"│";

    int dem = 1;
    node *k;
    k = l.pHead;
    while (k != NULL)
    {
        fileout << L"\n├──────┼──────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┤";
        fileout << setw(1) << left << L"\n│" <<L"  "<< setw(4) << left << dem << setw(1) << left << L"│" <<L"   "<< setw(11) << left <<k->data->getID() << L"│" <<L"    "<< setw(20) << left <<k->data->getName() << L"│" <<L"    "<< setw(20) << left <<k->data->getNgaySinh() << L"│" <<L"    "<< setw(20) << left <<k->data->getSDT() << L"│" <<L"    "<< setw(20) << left <<k->data->getAddress() << L"│" <<L"    "<< setw(20) << left <<k->data->getLuongCB() << L"│" <<L"    "<< setw(20) << left<<k->data->TinhLuong() << L"│" << "    "<<setw(20) << left<<k->data->getChiNhanh() << L"│";
        dem++;
        k = k->pNext;
    }
    fileout << L"\n└──────┴──────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┘";
}