#include "ChiNhanh.h"
void ChiNhanh::Khoitao(list2 &l2)
{
    l2.pHead = l2.pTail = NULL;
}
node *ChiNhanh::KhoiTaoNode(NhanVien *x)
{
    node *p = new node;
    p->data = x;
    p->pNext = NULL;
    p->pPre = NULL;
    return p;
}
void ChiNhanh::ThemVaocuoi(list2 &l2, NhanVien *x)
{
    node *p = KhoiTaoNode(x);
    if (l2.pHead == NULL)
    {
        l2.pHead = l2.pTail = p;
    }
    else
    {
        l2.pTail->pNext = p;
        p->pPre = l2.pTail;
        l2.pTail = p;
    }
}

void ChiNhanh::AddNhanVien(list &l, list2 &l2)
{
    node *p = l.pHead;
    while (p != NULL)
    {
        ThemVaocuoi(l2, p->data);
        p = p->pNext;
    }
}
void ChiNhanh::XuatTheoChiNhanh(list2 &l2, wstring s)
{
    node *p = l2.pHead;
    int dem = 0;
    while (p != NULL)
    {
        if (p->data->getChiNhanh() == s)
        {
            dem++;
            _setmode(_fileno(stdout), _O_WTEXT); //needed for output
            _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
            locale loc(locale(), new codecvt_utf8<wchar_t>);
            if (dem == 1)
            {
                wcout << L"┌──────┬──────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┐";
                wcout << setw(1) << left << L"\n│" << setw(6) << left << L"  STT" << setw(1) << left << L"│" << setw(14) << left << L"    Mã số" << L"│" << setw(24) << left << L"      Họ và tên" << L"│" << setw(24) << left << L"      Ngày sinh" << L"│" << setw(24) << left << L"      Số điện thoại" << L"│" << setw(24) << left << L"        Địa chỉ" << L"│" << setw(24) << left << L"      Lương cơ bản" << L"│" << setw(24) << left << L"      Lương tháng" << L"│" << setw(24) << left << L"      Chi Nhánh" << L"│";
            }
            wcout << L"\n├──────┼──────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┤";
            wcout << setw(1) << left << L"\n│" << L"  " << setw(4) << left << dem << setw(1) << left << L"│" << L"   " << setw(11) << left << p->data->getID() << L"│" << L"    " << setw(20) << left << p->data->getName() << L"│" << L"    " << setw(20) << left << p->data->getNgaySinh() << L"│" << L"    " << setw(20) << left << p->data->getSDT() << L"│" << L"    " << setw(20) << left << p->data->getAddress() << L"│" << L"    " << setw(20) << left << p->data->getLuongCB() << L"│" << L"    " << setw(20) << left << p->data->TinhLuong() << L"│" << "    " << setw(20) << left << p->data->getChiNhanh() << L"│";
        }

        p = p->pNext;
    }
    wcout << L"\n└──────┴──────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┘";
}