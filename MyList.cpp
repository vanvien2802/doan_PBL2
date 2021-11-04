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

void MyList::XoaNode(list &l, wstring ma)
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
//di chuyển con trỏ chuột//

void MyList::gotoXY(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//======================//

void MyList::XuatDanhSach(list l, int x)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for inputs
    //đọc danh sách lấy số lượng node //
    int sl = 1;
    for (node *k = l.pHead; k != NULL; k = k->pNext)
    {
        sl++;
    }
    int i = 1;
    // while (i <= sl - 1)
    // {
    //     gotoXY(x + 3, i * 2 + 1);
    //     wcout << i;
    //     gotoXY(x + 3, (i + 1) * 2 + 1);
    //     wcout << i + 1;
    //     i = i + 2;
    // }

    // for (int i = 1; i <= sl-1; i = i + 2)
    // {
    //     gotoXY(x + 3, i * 2 + 1);
    //     wcout << i;
    //     gotoXY(x + 3, (i + 1) * 2 + 1);
    //     wcout << i + 1;
    // }
    //================================//
    gotoXY(x, 0);
    wcout << L"┌──────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┐";

    for (int i = 1; i <= sl * 2; i = i + 2)
    {
        gotoXY(x, i + 1);
        wcout << L"├──────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┤";
    }
    for (int i = 1; i <= sl * 2; i = i + 2)
    {
        gotoXY(x, i);
        wcout << L"│";
        gotoXY(x + 7, i);
        wcout << L"│";
        gotoXY(x + 32, i);
        wcout << L"│";
        gotoXY(x + 57, i);
        wcout << L"│";
        gotoXY(x + 82, i);
        wcout << L"│";
        gotoXY(x + 107, i);
        wcout << L"│";
        gotoXY(x + 132, i);
        wcout << L"│";
        gotoXY(x + 157, i);
        wcout << L"│";
    }
    gotoXY(x, sl * 2);
    wcout << L"└──────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┘";

    //
    gotoXY(x + 2, 1);
    wcout << L"STT";
    gotoXY(x + 12, 1);
    wcout << L"Mã Số Nhân Viên";
    gotoXY(x + 40, 1);
    wcout << L"Họ và Tên";
    gotoXY(x + 65, 1);
    wcout << L"Ngày Sinh";
    gotoXY(x + 88, 1);
    wcout << L"Số điện thoại";
    gotoXY(x + 116, 1);
    wcout << L"Địa chỉ";
    gotoXY(x + 139, 1);
    wcout << L"Lương cơ bản";
    i = 3;
    int dem=1;
    for (node *k = l.pHead; k != NULL; k = k->pNext)
    {
        //wcout << L"\n\n\t\t NHÂN VIÊN THỨ " << dem++ << endl;
        //k->data->Xuat();
        gotoXY(x + 3, i);
        wcout << dem;
        gotoXY(x + 12, i);
        wcout << k->data->getID();
        gotoXY(x + 40, i);
        wcout << k->data->getName();
        gotoXY(x + 65, i);
        wcout << k->data->getNgaySinh();
        gotoXY(x + 88, i);
        wcout << k->data->getSDT();
        gotoXY(x + 116, i);
        wcout << k->data->getAddress();
        gotoXY(x + 139, i);
        wcout << k->data->getLuongCB();
        i = i + 2;
        dem++;
    }
    gotoXY(x, sl * 2 + 2);
    wcout << L"Nhấn phím bất kì để trở lại !";
}

void MyList::XuatDanhSachVaoFile(list &l, wofstream &fileout)
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    fileout.imbue(loc);
    int dem = 1;
    fileout << L"\n              Danh Sách Nhân Viên             \n\n " << endl;
    for (node *k = l.pHead; k != NULL; k = k->pNext)
    {
        fileout << L"\nNhân Viên Thứ : " << dem++ << endl;
        k->data->Xuatfile(fileout);
    }
}