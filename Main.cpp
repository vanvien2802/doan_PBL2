#include <iostream>
#include <conio.h> // getch()
#include "mylib.h" // đồ họa
#include <fcntl.h> // sử dụng tiếng việt với console tiếng việt
#include <io.h>    // sử dụng tiếng việt với console tiếng việt
#include <string>
#include <locale>  // Để chỉnh sửa phông chữ
#include <codecvt> // Để chỉnh sửa phông chữ
#include "ChiNhanh.h"
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

void noidung(int x, int y)
{
    for (int i = 1; i <= 8; i++)
    {
        y = i * 4;
        if (y == 4)
        {
            gotoXY(x + 17, y + 2);
            wcout << L"Đọc Thông Tin Nhân Viên";
        }
        else if (y == 8)
        {
            gotoXY(x + 17, y + 3);
            wcout << L"Xuất Thông Tin Vào File";
        }
        else if (y == 12)
        {
            gotoXY(x + 17, y + 4);
            wcout << L"Xuất Thông Tin Nhân Viên";
        }
        else if (y == 16)
        {
            gotoXY(x + 15, y + 5);
            wcout << L"Thêm Nhân Viên Vào Danh Sách";
        }
        else if (y == 20)
        {
            gotoXY(x + 23, y + 6);
            wcout << L"Xóa Nhân Viên";
        }
        else if (y == 24)
        {
            gotoXY(x + 22, y + 7);
            wcout << L"Update Nhân Viên";
        }
        else if (y == 28)
        {
            gotoXY(x + 21, y + 8);
            wcout << L"Tìm Kiếm Nhân Viên";
        }
        else if (y == 32)
        {
            gotoXY(x + 22, y + 9);
            wcout << L"Sắp Xếp Nhân Viên";
        }
    }
}

void BOX(int x, int y, int w, int h, int t_color, int b_color)
{
    //màu nền
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    for (int iy = y + 1; iy <= y + h; iy++)
    {
        for (int ix = x + 1; ix <= x + 1; ix++)
        {
            gotoXY(ix, iy);
            wcout << L"                                                           ";
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    SetColor(t_color);
    if (h <= 1 || w <= 1)
        return;
    gotoXY(x, y);
    wcout << L"╔══════════════════════════════════════════════════════════╗";
    for (int iy = y; iy <= y + h; iy++)
    {
        gotoXY(x, iy + 1);
        wcout << L"║";
        gotoXY(x + w - 1, iy + 1);
        wcout << L"║";
    }
    gotoXY(x, y + h + 1);
    wcout << L"╚══════════════════════════════════════════════════════════╝";
}

void N_BOX(int x, int y, int w, int h, int t_color, int b_color, int sl)
{
    SetColor(12);
    gotoXY(x - 4, 0);
    wcout << L"╔══════════════════════════════════════════════════════════════════╗";
    gotoXY(x - 4, 1);
    wcout << L"║";
    gotoXY(x + w + 3, 1);
    wcout << L"║";
    gotoXY(x - 4, 2);
    wcout << L"╚══════════════════════════════════════════════════════════════════╝";
    SetColor(11);
    gotoXY(x + 17, 1);
    wcout << L"HỆ THỐNG QUẢN LÍ NHÂN VIÊN";

    SetColor(10);
    gotoXY(x - 1, y - 1);
    wcout << L"╔════════════════════════════════════════════════════════════╗";
    for (int iy = y; iy <= sl + 35; iy++)
    {
        gotoXY(x - 1, iy);
        wcout << L"║";
        gotoXY(x + w, iy);
        wcout << L"║";
    }
    gotoXY(x - 1, y + 40);
    wcout << L"╚════════════════════════════════════════════════════════════╝";
    for (int i = 0; i < sl; i++)
    {
        BOX(x, y + (i * 4), w, h, t_color, b_color);
        y++;
    }
    noidung(x, y);
}

void thanhsang(int x, int y, int w, int h, int t_color, int b_color_sang)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), b_color_sang);
    for (int iy = y + 1; iy <= y + h; iy++)
    {
        for (int ix = x + 1; ix <= x + 1; ix++)
        {
            gotoXY(ix, iy);
            wcout << L"                                                          ";
        }
    }
    if (y == 4)
    {
        gotoXY(x + 17, y + 2);
        wcout << L"Đọc Thông Tin Nhân Viên";
    }
    if (y == 9)
    {
        gotoXY(x + 17, y + 2);
        wcout << L"Xuất Thông Tin Vào File";
    }
    if (y == 14)
    {
        gotoXY(x + 17, y + 2);
        wcout << L"Xuất Thông Tin Nhân Viên";
    }
    if (y == 19)
    {
        gotoXY(x + 15, y + 2);
        wcout << L"Thêm Nhân Viên Vào danh sách";
    }
    if (y == 24)
    {
        gotoXY(x + 23, y + 2);
        wcout << L"Xóa Nhân Viên";
    }
    if (y == 29)
    {
        gotoXY(x + 22, y + 2);
        wcout << L"Update Nhân Viên";
    }
    if (y == 34)
    {
        gotoXY(x + 21, y + 2);
        wcout << L"Tìm Kiếm Nhân Viên";
    }
    if (y == 39)
    {
        gotoXY(x + 22, y + 2);
        wcout << L"Sắp Xếp Nhân Viên";
    }
}
//=============== Khung danh sách ================//

void khungds()
{
    textcolor(2);
    gotoXY(60, 0);
    wcout << L"╔═══════════════════════════════════════════════════════╗";
    gotoXY(60, 1);
    wcout << L"║";
    gotoXY(116, 1);
    wcout << L"║";
    gotoXY(60, 2);
    wcout << L"╚═══════════════════════════════════════════════════════╝";
    gotoXY(60, 3);
    wcout << L"╔═══════════════════════════════════════════════════════╗";
    for (int i = 4; i <= 16; i++)
    {
        gotoXY(60, i);
        wcout << L"║";
        gotoXY(116, i);
        wcout << L"║";
    }
    gotoXY(60, 16);
    wcout << L"╚═══════════════════════════════════════════════════════╝";
    gotoXY(75, 1);
    wcout << L"CHỌN LOẠI NHÂN VIÊN MUỐN THÊM";

    gotoXY(70, 4);
    wcout << L"1. NHÂN VIÊN VĂN PHÒNG ";
    gotoXY(70, 6);
    wcout << L"2. NHÂN VIÊN SẢN XUẤT ";
    gotoXY(70, 8);
    wcout << L"3. NHÂN VIÊN MARKETING ";
    gotoXY(70, 10);
    wcout << L"4. NHÂN VIÊN KINH DOANH ";
    gotoXY(70, 12);
    wcout << L"5. Trở Về MENU";
}

void muiten(int xm, int ym)
{
    gotoXY(xm, ym);
    wcout << L"⤇";
    gotoXY(xm + 30, ym);
    wcout << L"⤆";
}

void ghidemuiten(int x, int y)
{
    gotoXY(x, y);
    wcout << L"  ";
}

//=============== *************** ================//

// danh sách tìm kiếm

void ds_search(int x)
{
    x += 20;
    textcolor(2);
    gotoXY(x + 40, 0);
    wcout << L"╔═══════════════════════════════════════════════════════╗";
    gotoXY(x + 40, 1);
    wcout << L"║";
    gotoXY(x + 96, 1);
    wcout << L"║";
    gotoXY(x + 40, 2);
    wcout << L"╚═══════════════════════════════════════════════════════╝";
    gotoXY(x + 40, 3);
    wcout << L"╔═══════════════════════════════════════════════════════╗";
    for (int i = 4; i <= 12; i++)
    {
        gotoXY(x + 40, i);
        wcout << L"║";
        gotoXY(x + 96, i);
        wcout << L"║";
    }
    gotoXY(x + 40, 12);
    wcout << L"╚═══════════════════════════════════════════════════════╝";
    gotoXY(x + 55, 1);
    wcout << L"CÁC CÁCH TÌM KIẾM NHÂN VIÊN";

    gotoXY(x + 50, 5);
    wcout << L"1. Tìm Kiếm Theo Mã Số";
    gotoXY(x + 50, 7);
    wcout << L"2. Tìm Kiếm Theo Tên ";
    gotoXY(x + 50, 9);
    wcout << L"3. Trở Về MENU ";
}
//khung danh sách sắp xếp //

void ds_sapxep(int x)
{
    textcolor(2);
    gotoXY(x + 40, 0);
    wcout << L"╔═══════════════════════════════════════════════════════╗";
    gotoXY(x + 40, 1);
    wcout << L"║";
    gotoXY(x + 96, 1);
    wcout << L"║";
    gotoXY(x + 40, 2);
    wcout << L"╚═══════════════════════════════════════════════════════╝";
    gotoXY(x + 40, 3);
    wcout << L"╔═══════════════════════════════════════════════════════╗";
    for (int i = 4; i <= 12; i++)
    {
        gotoXY(x + 40, i);
        wcout << L"║";
        gotoXY(x + 96, i);
        wcout << L"║";
    }
    gotoXY(x + 40, 12);
    wcout << L"╚═══════════════════════════════════════════════════════╝";
    gotoXY(x + 55, 1);
    wcout << L"CÁC CÁCH SẮP XẾP NHÂN VIÊN";

    gotoXY(x + 50, 5);
    wcout << L"1. Sắp Xếp Theo Lương";
    gotoXY(x + 50, 7);
    wcout << L"2. Sắp Xếp Theo Tên ";
    gotoXY(x + 50, 9);
    wcout << L"3. Trở Về MENU ";
}

void khungupdate(int x, wstring maso)
{
    SetColor(3);

    gotoXY(x, 0);
    wcout << L"╔═════════════════════════════════════════════════╗";
    for (int i = 1; i <= 22; i++)
    {
        gotoXY(x, i);
        wcout << L"║";
        gotoXY(x + 50, i);
        wcout << L"║";
    }
    gotoXY(x, 22);
    wcout << L"╚═════════════════════════════════════════════════╝";
    gotoXY(x + 5, 2);
    wcout << L" Chọn Thuộc Tính Bạn Muốn Sửa : ";
    gotoXY(x + 5, 4);
    wcout << L"1. Mã Số ";
    gotoXY(x + 5, 6);
    wcout << L"2. Họ Và Tên ";
    gotoXY(x + 5, 8);
    wcout << L"3. Ngày Sinh  ";
    gotoXY(x + 5, 10);
    wcout << L"4. Địa Chỉ ";
    gotoXY(x + 5, 12);
    wcout << L"5. Số Điện Thoại ";
    gotoXY(x + 5, 14);
    wcout << L"6. Lương Cơ Bản ";
    if (maso[0] == 'V')
    {
        gotoXY(x + 5, 16);
        wcout << L"7. DAYWORKING";
    }
    else if (maso[0] == 'S')
    {
        gotoXY(x + 5, 16);
        wcout << L"7. Số Sản Phẩm ";
    }
    else if (maso[0] == 'M')
    {
        gotoXY(x + 5, 16);
        wcout << L"7. Hệ Số KPI ";
    }
    else if (maso[0] == 'K')
    {
        gotoXY(x + 5, 16);
        wcout << L"7. Số Hợp Đồng ";
    }
    gotoXY(x + 5, 18);
    wcout << L"8. Chi Nhánh ";
    gotoXY(x + 5, 20);
    wcout << L"9. Thoát ";
}
//===============================//
void ds_delete(int x)
{
    textcolor(2);
    gotoXY(x + 40, 0);
    wcout << L"╔═══════════════════════════════════════════════════════╗";
    gotoXY(x + 40, 1);
    wcout << L"║";
    gotoXY(x + 96, 1);
    wcout << L"║";
    gotoXY(x + 40, 2);
    wcout << L"╚═══════════════════════════════════════════════════════╝";
    gotoXY(x + 40, 3);
    wcout << L"╔═══════════════════════════════════════════════════════╗";
    for (int i = 4; i <= 12; i++)
    {
        gotoXY(x + 40, i);
        wcout << L"║";
        gotoXY(x + 96, i);
        wcout << L"║";
    }
    gotoXY(x + 40, 12);
    wcout << L"╚═══════════════════════════════════════════════════════╝";
    gotoXY(x + 55, 1);
    wcout << L"CÁC CÁCH XOÁ NHÂN VIÊN";

    gotoXY(x + 50, 5);
    wcout << L"1. XÓA THEO MÃ SỐ";
    gotoXY(x + 50, 7);
    wcout << L"2. XÓA THEO TÊN ";
    gotoXY(x + 50, 9);
    wcout << L"3. TRỞ VỀ MENU ";
}
//================================================//
void khung_st(int x, int i)
{
    clrscr();
    wstring s1 = L"ĐỒ ÁN CƠ SỞ LẬP TRÌNH";
    wstring s2 = L"NGƯỜI THỰC HIỆN";
    wstring s3 = L"LÊ ĐỨC TÀI";
    wstring s4 = L"NGUYỄN VĂN VIÊN";
    wstring s5 = L"GIẢNG VIÊN HƯỚNG DẪN";
    wstring s6 = L"ĐẶNG HOÀI PHƯƠNG";

    for (int z = x - 1; z <= x + 113; z++)
    {
        textcolor(43);
        gotoXY(z, i - 1);
        wcout << L" ";
    }
    for (int z = x - 1; z <= x + 113; z++)
    {
        textcolor(43);
        gotoXY(z, i + 13);
        wcout << L" ";
    }
    for (int j = i; j <= i + 12; j++)
    {
        textcolor(43);
        gotoXY(x - 1, j);
        wcout << L" ";
        gotoXY(x + 112, j);
        wcout << L" ";
        textcolor(1);
    }
    SetColor(5);
    textcolor(224);
    gotoXY(x - 2, i - 2);
    wcout << L"╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗";
    for (int j = i - 1; j <= i + 13; j++)
    {
        gotoXY(x - 2, j);
        wcout << L"║";
        gotoXY(x + 113, j);
        wcout << L"║";
    }
    gotoXY(x - 2, i + 14);
    wcout << L"╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝";
    gotoXY(x, i);
    wcout << L"┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────┐";
    gotoXY(x, i + 1);
    wcout << setw(1) << left << L"│" << setw(110) << " " << setw(1) << right << L"│";
    gotoXY(x, i + 2);
    wcout << setw(1) << left << L"│" << setw(44) << left << " " << s1 << setw(45) << right << " " << setw(1) << right << L"│";
    for (int j = i + 3; j <= i + 12; j++)
    {
        gotoXY(x, j);
        wcout << setw(1) << left << L"│" << setw(110) << " " << setw(1) << right << L"│";
    }
    gotoXY(x, i + 4);
    wcout << setw(1) << left << L"│" << setw(15) << left << " " << s2 << setw(45) << right << " " << setw(20) << left << s5 << setw(15) << right << " " << setw(1) << right << L"│";
    gotoXY(x, i + 6);
    wcout << setw(1) << left << L"│" << setw(10) << left << " " << s3 << setw(6) << " " << setw(10) << ": 20TCLC_DT4" << setw(39) << right << " " << setw(16) << left << s6 << setw(7) << right << " ";
    gotoXY(x, i + 7);
    wcout << setw(1) << left << L"│" << setw(10) << left << " " << s4 << setw(1) << " " << setw(10) << ": 20TCLC_DT4" << setw(72) << right << " ";

    gotoXY(x, i + 12);
    wcout << L"└──────────────────────────────────────────────────────────────────────────────────────────────────────────────┘";
}

//================================================//

void tiltle()
{
    clrscr();
    ShowCur(0);
    SetColor(3);
    wcout << endl;
    gotoXY(41, 2);
    wcout << L"─────" << endl;
    gotoXY(41, 3);
    wcout << L"|██▀▀∎▄" << endl;
    SetColor(13);
    gotoXY(41, 4);
    wcout << L"|██|  |█" << endl;
    SetColor(10);
    gotoXY(41, 5);
    wcout << L"|██|  |█" << endl;
    SetColor(14);
    gotoXY(41, 6);
    wcout << L"|██|  |█" << endl;
    SetColor(4);
    gotoXY(41, 7);
    wcout << L"|██▄▄∎▀" << endl;
    gotoXY(41, 8);
    wcout << L"─────" << endl;

    gotoXY(50, 2);
    wcout << L"    ───" << endl;
    gotoXY(50, 3);
    wcout << L"    ☗☗" << endl;
    SetColor(14);
    gotoXY(50, 4);
    wcout << L"   █▌|█▌" << endl;
    SetColor(10);
    gotoXY(50, 5);
    wcout << L"  █▌▌◛◛|█▌" << endl;
    SetColor(13);
    gotoXY(50, 6);
    wcout << L" █▌|    |█▌" << endl;
    SetColor(3);
    gotoXY(50, 7);
    wcout << L"█▌|      |█▌" << endl;
    gotoXY(50, 8);
    wcout << L"───      ───" << endl;

    gotoXY(61, 2);
    wcout << L"  ───     ──" << endl;
    gotoXY(61, 3);
    wcout << L"  █|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(61, 4);
    wcout << L"  █| ▀▄|  |█" << endl;
    SetColor(10);
    gotoXY(61, 5);
    wcout << L"  █|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(61, 6);
    wcout << L"  █|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(61, 7);
    wcout << L"  █|     ▀|█" << endl;
    gotoXY(61, 8);
    wcout << L"  ──     ───" << endl;

    gotoXY(73, 2);
    wcout << L"  ───      ───" << endl;
    gotoXY(73, 3);
    wcout << L"  |█|      |█|" << endl;
    SetColor(14);
    gotoXY(73, 4);
    wcout << L"  |█|      |█|" << endl;
    SetColor(10);
    gotoXY(73, 5);
    wcout << L"  |█|██████|█|" << endl;
    SetColor(13);
    gotoXY(73, 6);
    wcout << L"  |█|      |█|" << endl;
    SetColor(3);
    gotoXY(73, 7);
    wcout << L"  |█|      |█|" << endl;
    gotoXY(73, 8);
    wcout << L"  ───      ───" << endl;

    SetColor(14);
    gotoXY(95, 2);
    wcout << L"   ───────" << endl;
    gotoXY(95, 3);
    wcout << L"|▆███████|" << endl;
    SetColor(11);
    gotoXY(95, 4);
    wcout << L"|███|        " << endl;
    SetColor(10);
    gotoXY(95, 5);
    wcout << L" |█████▆|" << endl;
    SetColor(12);
    gotoXY(95, 6);
    wcout << L"     |███|              " << endl;
    SetColor(13);
    gotoXY(95, 7);
    wcout << L"|████████|" << endl;
    gotoXY(95, 8);
    wcout << L" ────────" << endl;

    SetColor(13);
    gotoXY(106, 2);
    wcout << L"     ◢◤" << endl;
    gotoXY(106, 3);
    wcout << L"    ☗☗" << endl;
    SetColor(12);
    gotoXY(106, 4);
    wcout << L"   █▌|█▌" << endl;
    SetColor(10);
    gotoXY(106, 5);
    wcout << L"  █▌▌◛◛|█▌" << endl;
    SetColor(11);
    gotoXY(106, 6);
    wcout << L" █▌|    |█▌" << endl;
    SetColor(14);
    gotoXY(106, 7);
    wcout << L"█▌|      |█▌" << endl;
    gotoXY(106, 8);
    wcout << L"───      ───" << endl;

    SetColor(13);
    gotoXY(118, 2);
    wcout << L" ────────" << endl;
    gotoXY(118, 3);
    wcout << L"▆███████|";
    SetColor(11);
    gotoXY(118, 4);
    wcout << L"|██|";
    SetColor(14);
    gotoXY(118, 5);
    wcout << L"|██|";
    SetColor(10);
    gotoXY(118, 6);
    wcout << L"|██|";
    SetColor(12);
    gotoXY(118, 7);
    wcout << L"▀████████|";
    gotoXY(118, 8);
    wcout << L" ────────" << endl;

    SetColor(10);
    gotoXY(128, 2);
    wcout << L"  ───      ───" << endl;
    gotoXY(128, 3);
    wcout << L"  |█|      |█|" << endl;
    SetColor(14);
    gotoXY(128, 4);
    wcout << L"  |█|      |█|" << endl;
    SetColor(11);
    gotoXY(128, 5);
    wcout << L"  |█|██████|█|" << endl;
    SetColor(13);
    gotoXY(128, 6);
    wcout << L"  |█|      |█|" << endl;
    SetColor(3);
    gotoXY(128, 7);
    wcout << L"  |█|      |█|" << endl;
    gotoXY(128, 8);
    wcout << L"  ───      ───" << endl;
}

void chinhanhDN()
{
    gotoXY(8, 2);
    wcout << L"  ───     ──" << endl;
    gotoXY(8, 3);
    wcout << L"  █|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(8, 4);
    wcout << L"  █| ▀▄|  |█" << endl;
    SetColor(10);
    gotoXY(8, 5);
    wcout << L"  █|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(8, 6);
    wcout << L"  █|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(8, 7);
    wcout << L"  █|     ▀|█" << endl;
    gotoXY(8, 8);
    wcout << L"  ──     ───" << endl;

    gotoXY(20, 2);
    wcout << L"  ───      ───" << endl;
    gotoXY(20, 3);
    wcout << L"  |█|      |█|" << endl;
    SetColor(14);
    gotoXY(20, 4);
    wcout << L"  |█|      |█|" << endl;
    SetColor(10);
    gotoXY(20, 5);
    wcout << L"  |█|██████|█|" << endl;
    SetColor(13);
    gotoXY(20, 6);
    wcout << L"  |█|      |█|" << endl;
    SetColor(3);
    gotoXY(20, 7);
    wcout << L"  |█|      |█|" << endl;
    gotoXY(20, 8);
    wcout << L"  ───      ───" << endl;

    SetColor(13);
    gotoXY(35, 1);
    wcout << L"    ◤◥" << endl;
    SetColor(14);
    gotoXY(35, 2);
    wcout << L"    ───" << endl;
    gotoXY(35, 3);
    wcout << L"    ☗☗" << endl;
    SetColor(12);
    gotoXY(35, 4);
    wcout << L"   █▌|█▌" << endl;
    SetColor(10);
    gotoXY(35, 5);
    wcout << L"  █▌▌◛◛|█▌" << endl;
    SetColor(11);
    gotoXY(35, 6);
    wcout << L" █▌|    |█▌" << endl;
    SetColor(14);
    gotoXY(35, 7);
    wcout << L"█▌|      |█▌" << endl;
    gotoXY(35, 8);
    wcout << L"───      ───" << endl;

    gotoXY(47, 2);
    wcout << L"  ───     ──" << endl;
    gotoXY(47, 3);
    wcout << L"  █|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(47, 4);
    wcout << L"  █| ▀▄|  |█" << endl;
    SetColor(10);
    gotoXY(47, 5);
    wcout << L"  █|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(47, 6);
    wcout << L"  █|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(47, 7);
    wcout << L"  █|     ▀|█" << endl;
    gotoXY(47, 8);
    wcout << L"  ──     ───" << endl;

    SetColor(10);
    gotoXY(64, 2);
    wcout << L"───         ───" << endl;
    gotoXY(64, 3);
    wcout << L"▀▄|         |▄▀" << endl;
    SetColor(4);
    gotoXY(64, 4);
    wcout << L" ▀▄|       |▄▀" << endl;
    SetColor(13);
    gotoXY(64, 5);
    wcout << L"  ▀▄|     |▄▀" << endl;
    SetColor(14);
    gotoXY(64, 6);
    wcout << L"   ▀▄|   |▄▀" << endl;
    SetColor(12);
    gotoXY(64, 7);
    wcout << L"    ▀▄|_|▄▀" << endl;
    gotoXY(64, 8);
    wcout << L"      ───" << endl;

    SetColor(14);
    gotoXY(80, 1);
    wcout << L" ▄" << endl;
    SetColor(4);
    gotoXY(80, 2);
    wcout << L"───" << endl;
    gotoXY(80, 3);
    wcout << L"|█|" << endl;
    SetColor(13);
    gotoXY(80, 4);
    wcout << L"|█|" << endl;
    SetColor(10);
    gotoXY(80, 5);
    wcout << L"|█|" << endl;
    SetColor(15);
    gotoXY(80, 6);
    wcout << L"|█|" << endl;
    SetColor(14);
    gotoXY(80, 7);
    wcout << L"|█|" << endl;
    gotoXY(80, 8);
    wcout << L"───" << endl;

    SetColor(2);
    gotoXY(84, 1);
    wcout << L"  ◢◤◥◣" << endl;
    SetColor(9);
    gotoXY(84, 2);
    wcout << L" ────────" << endl;
    gotoXY(84, 3);
    wcout << L"|█|▀▀▀▀▀▀" << endl;
    SetColor(4);
    gotoXY(84, 4);
    wcout << L"|█|" << endl;
    SetColor(15);
    gotoXY(84, 5);
    wcout << L"|█|▀▀▀▀▀▀" << endl;
    SetColor(11);
    gotoXY(84, 6);
    wcout << L"|█|" << endl;
    SetColor(10);
    gotoXY(84, 7);
    wcout << L"|█|▄▄▄▄▄▄" << endl;
    gotoXY(84, 8);
    wcout << L" ────────" << endl;

    gotoXY(94, 2);
    wcout << L"───     ──" << endl;
    gotoXY(94, 3);
    wcout << L"█|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(94, 4);
    wcout << L"█| ▀▄|  |█" << endl;
    SetColor(8);
    gotoXY(94, 5);
    wcout << L"█|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(94, 6);
    wcout << L"█|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(94, 7);
    wcout << L"█|     ▀|█" << endl;
    gotoXY(94, 8);
    wcout << L"──     ───" << endl;

    gotoXY(109, 2);
    wcout << L"  ─────" << endl;
    gotoXY(109, 3);
    wcout << L"  |██▀▀∎▄" << endl;
    SetColor(13);
    gotoXY(109, 4);
    wcout << L"  |██|  |█" << endl;
    SetColor(10);
    gotoXY(109, 5);
    wcout << L"▰|██|▰  |█" << endl;
    SetColor(14);
    gotoXY(109, 6);
    wcout << L"  |██|  |█" << endl;
    SetColor(4);
    gotoXY(109, 7);
    wcout << L"  |██▄▄∎▀" << endl;
    gotoXY(109, 8);
    wcout << L"  ─────" << endl;

    SetColor(10);
    gotoXY(120, 1);
    wcout << L"    ◥◣" << endl;
    SetColor(13);
    gotoXY(120, 2);
    wcout << L"     ───" << endl;
    gotoXY(120, 3);
    wcout << L"     ☗☗" << endl;
    SetColor(12);
    gotoXY(120, 4);
    wcout << L"   █▌|| █▌" << endl;
    SetColor(10);
    gotoXY(120, 5);
    wcout << L"  █▌▌◛◛|█▌" << endl;
    SetColor(11);
    gotoXY(120, 6);
    wcout << L" █▌|    |█▌" << endl;
    SetColor(14);
    gotoXY(120, 7);
    wcout << L"█▌|      |█▌" << endl;
    gotoXY(120, 8);
    wcout << L"───      ───" << endl;

    gotoXY(137, 2);
    wcout << L"  ───     ──" << endl;
    gotoXY(137, 3);
    wcout << L"  █|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(137, 4);
    wcout << L"  █| ▀▄|  |█" << endl;
    SetColor(10);
    gotoXY(137, 5);
    wcout << L"  █|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(137, 6);
    wcout << L"  █|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(137, 7);
    wcout << L"  █|     ▀|█" << endl;
    gotoXY(137, 8);
    wcout << L"  ──     ───" << endl;

    SetColor(12);
    gotoXY(150, 1);
    wcout << L"   _/\\_/" << endl;
    SetColor(13);
    gotoXY(150, 2);
    wcout << L"   ◣_◢" << endl;
    gotoXY(150, 3);
    wcout << L"    ☗☗" << endl;
    SetColor(12);
    gotoXY(150, 4);
    wcout << L"   █▌|█▌" << endl;
    SetColor(10);
    gotoXY(150, 5);
    wcout << L"  █▌▌◛◛|█▌" << endl;
    SetColor(11);
    gotoXY(150, 6);
    wcout << L" █▌|    |█▌" << endl;
    SetColor(14);
    gotoXY(150, 7);
    wcout << L"█▌|      |█▌" << endl;
    gotoXY(150, 8);
    wcout << L"───      ───" << endl;

    gotoXY(163, 2);
    wcout << L"───     ──" << endl;
    gotoXY(163, 3);
    wcout << L"█|▀▄|   |█|" << endl;
    SetColor(13);
    gotoXY(163, 4);
    wcout << L"█| ▀▄|  |█|" << endl;
    SetColor(10);
    gotoXY(163, 5);
    wcout << L"█|  ▀▄| |█|" << endl;
    SetColor(14);
    gotoXY(163, 6);
    wcout << L"█|   ▀▄||█|" << endl;
    SetColor(4);
    gotoXY(163, 7);
    wcout << L"█|     ▀|█|" << endl;
    gotoXY(163, 8);
    wcout << L"──     ───" << endl;

    SetColor(13);
    gotoXY(175, 2);
    wcout << L" ────────" << endl;
    gotoXY(175, 3);
    wcout << L"▆████████|";
    SetColor(11);
    gotoXY(175, 4);
    wcout << L"|██|";
    SetColor(14);
    gotoXY(175, 5);
    wcout << L"|██| |████|";
    SetColor(10);
    gotoXY(175, 6);
    wcout << L"|██|   |██|";
    SetColor(3);
    gotoXY(175, 7);
    wcout << L"▀█████████|";
    gotoXY(175, 8);
    wcout << L" ────────" << endl;
}

void chinhanhHCM()
{
    gotoXY(0, 2);
    wcout << L"  ───     ──" << endl;
    gotoXY(0, 3);
    wcout << L"  █|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(0, 4);
    wcout << L"  █| ▀▄|  |█" << endl;
    SetColor(10);
    gotoXY(0, 5);
    wcout << L"  █|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(0, 6);
    wcout << L"  █|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(0, 7);
    wcout << L"  █|     ▀|█" << endl;
    gotoXY(0, 8);
    wcout << L"  ──     ───" << endl;

    gotoXY(12, 2);
    wcout << L"  ───      ───" << endl;
    gotoXY(12, 3);
    wcout << L"  |█|      |█|" << endl;
    SetColor(14);
    gotoXY(12, 4);
    wcout << L"  |█|      |█|" << endl;
    SetColor(10);
    gotoXY(12, 5);
    wcout << L"  |█|██████|█|" << endl;
    SetColor(13);
    gotoXY(12, 6);
    wcout << L"  |█|      |█|" << endl;
    SetColor(3);
    gotoXY(12, 7);
    wcout << L"  |█|      |█|" << endl;
    gotoXY(12, 8);
    wcout << L"  ───      ───" << endl;

    SetColor(13);
    gotoXY(27, 1);
    wcout << L"    ◤◥" << endl;
    SetColor(14);
    gotoXY(27, 2);
    wcout << L"    ───" << endl;
    gotoXY(27, 3);
    wcout << L"    ☗☗" << endl;
    SetColor(12);
    gotoXY(27, 4);
    wcout << L"   █▌|█▌" << endl;
    SetColor(10);
    gotoXY(27, 5);
    wcout << L"  █▌▌◛◛|█▌" << endl;
    SetColor(11);
    gotoXY(27, 6);
    wcout << L" █▌|    |█▌" << endl;
    SetColor(14);
    gotoXY(27, 7);
    wcout << L"█▌|      |█▌" << endl;
    gotoXY(27, 8);
    wcout << L"───      ───" << endl;

    gotoXY(39, 2);
    wcout << L"  ───     ──" << endl;
    gotoXY(39, 3);
    wcout << L"  █|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(39, 4);
    wcout << L"  █| ▀▄|  |█" << endl;
    SetColor(10);
    gotoXY(39, 5);
    wcout << L"  █|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(39, 6);
    wcout << L"  █|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(39, 7);
    wcout << L"  █|     ▀|█" << endl;
    gotoXY(39, 8);
    wcout << L"  ──     ───" << endl;

    SetColor(10);
    gotoXY(56, 2);
    wcout << L"───         ───" << endl;
    gotoXY(56, 3);
    wcout << L"▀▄|         |▄▀" << endl;
    SetColor(4);
    gotoXY(56, 4);
    wcout << L" ▀▄|       |▄▀" << endl;
    SetColor(13);
    gotoXY(56, 5);
    wcout << L"  ▀▄|     |▄▀" << endl;
    SetColor(14);
    gotoXY(56, 6);
    wcout << L"   ▀▄|   |▄▀" << endl;
    SetColor(12);
    gotoXY(56, 7);
    wcout << L"    ▀▄|_|▄▀" << endl;
    gotoXY(56, 8);
    wcout << L"      ───" << endl;

    SetColor(14);
    gotoXY(72, 1);
    wcout << L" ▄" << endl;
    SetColor(4);
    gotoXY(72, 2);
    wcout << L"───" << endl;
    gotoXY(72, 3);
    wcout << L"|█|" << endl;
    SetColor(13);
    gotoXY(72, 4);
    wcout << L"|█|" << endl;
    SetColor(10);
    gotoXY(72, 5);
    wcout << L"|█|" << endl;
    SetColor(15);
    gotoXY(72, 6);
    wcout << L"|█|" << endl;
    SetColor(14);
    gotoXY(72, 7);
    wcout << L"|█|" << endl;
    gotoXY(72, 8);
    wcout << L"───" << endl;

    SetColor(2);
    gotoXY(76, 1);
    wcout << L"  ◢◤◥◣" << endl;
    SetColor(9);
    gotoXY(76, 2);
    wcout << L" ────────" << endl;
    gotoXY(76, 3);
    wcout << L"|█|▀▀▀▀▀▀" << endl;
    SetColor(4);
    gotoXY(76, 4);
    wcout << L"|█|" << endl;
    SetColor(15);
    gotoXY(76, 5);
    wcout << L"|█|▀▀▀▀▀▀" << endl;
    SetColor(11);
    gotoXY(76, 6);
    wcout << L"|█|" << endl;
    SetColor(10);
    gotoXY(76, 7);
    wcout << L"|█|▄▄▄▄▄▄" << endl;
    gotoXY(76, 8);
    wcout << L" ────────" << endl;

    gotoXY(86, 2);
    wcout << L"───     ──" << endl;
    gotoXY(86, 3);
    wcout << L"█|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(86, 4);
    wcout << L"█| ▀▄|  |█" << endl;
    SetColor(8);
    gotoXY(86, 5);
    wcout << L"█|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(86, 6);
    wcout << L"█|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(86, 7);
    wcout << L"█|     ▀|█" << endl;
    gotoXY(86, 8);
    wcout << L"──     ───" << endl;

    gotoXY(101, 2);
    wcout << L"───      ───" << endl;
    gotoXY(101, 3);
    wcout << L"|█|      |█|" << endl;
    SetColor(14);
    gotoXY(101, 4);
    wcout << L"|█|      |█|" << endl;
    SetColor(10);
    gotoXY(101, 5);
    wcout << L"|█|██████|█|" << endl;
    SetColor(13);
    gotoXY(101, 6);
    wcout << L"|█|      |█|" << endl;
    SetColor(3);
    gotoXY(101, 7);
    wcout << L"|█|      |█|" << endl;
    gotoXY(101, 8);
    wcout << L"───      ───" << endl;

    SetColor(13);
    gotoXY(114, 1);
    wcout << L"    ◥◣" << endl;
    gotoXY(114, 2);
    wcout << L"   ◢◤◥◣" << endl;
    gotoXY(114, 3);
    wcout << L"|█████████|";
    SetColor(11);
    gotoXY(114, 4);
    wcout << L"|██|   |██|";
    SetColor(14);
    gotoXY(114, 5);
    wcout << L"|██|   |██|";
    SetColor(10);
    gotoXY(114, 6);
    wcout << L"|██|   |██|";
    SetColor(12);
    gotoXY(114, 7);
    wcout << L"|█████████|";
    gotoXY(114, 8);
    wcout << L" ─────────" << endl;

    SetColor(13);
    gotoXY(129, 2);
    wcout << L" ────────" << endl;
    gotoXY(129, 3);
    wcout << L"▆███████|";
    SetColor(11);
    gotoXY(129, 4);
    wcout << L"|██|";
    SetColor(14);
    gotoXY(129, 5);
    wcout << L"|██|";
    SetColor(10);
    gotoXY(129, 6);
    wcout << L"|██|";
    SetColor(12);
    gotoXY(129, 7);
    wcout << L"▀████████|";
    gotoXY(129, 8);

    gotoXY(140, 2);
    wcout << L"───      ───" << endl;
    gotoXY(140, 3);
    wcout << L"|█|      |█|" << endl;
    SetColor(14);
    gotoXY(140, 4);
    wcout << L"|█|      |█|" << endl;
    SetColor(10);
    gotoXY(140, 5);
    wcout << L"|█|██████|█|" << endl;
    SetColor(13);
    gotoXY(140, 6);
    wcout << L"|█|      |█|" << endl;
    SetColor(3);
    gotoXY(140, 7);
    wcout << L"|█|      |█|" << endl;
    gotoXY(140, 8);
    wcout << L"───      ───" << endl;

    SetColor(2);
    gotoXY(153, 1);
    wcout << L" ◢◤" << endl;
    SetColor(14);
    gotoXY(153, 2);
    wcout << L" ▄" << endl;
    SetColor(4);
    gotoXY(153, 3);
    wcout << L"|█|" << endl;
    SetColor(13);
    gotoXY(153, 4);
    wcout << L"|█|" << endl;
    SetColor(10);
    gotoXY(153, 5);
    wcout << L"|█|" << endl;
    SetColor(15);
    gotoXY(153, 6);
    wcout << L"|█|" << endl;
    SetColor(14);
    gotoXY(153, 7);
    wcout << L"|█|" << endl;
    gotoXY(153, 8);
    wcout << L"───" << endl;

    gotoXY(160, 2);
    wcout << L"────    ────" << endl;
    gotoXY(160, 3);
    wcout << L"█|▀▄|  |▄▀|█" << endl;
    SetColor(13);
    gotoXY(160, 4);
    wcout << L"█| ▀▄||▄▀ |█" << endl;
    SetColor(8);
    gotoXY(160, 5);
    wcout << L"█|        |█" << endl;
    SetColor(14);
    gotoXY(160, 6);
    wcout << L"█|        |█" << endl;
    SetColor(4);
    gotoXY(160, 7);
    wcout << L"█|        |█" << endl;
    gotoXY(160, 8);
    wcout << L"──        ──" << endl;

    SetColor(14);
    gotoXY(173, 1);
    wcout << L" ▄" << endl;
    SetColor(4);
    gotoXY(173, 2);
    wcout << L"───" << endl;
    gotoXY(173, 3);
    wcout << L"|█|" << endl;
    SetColor(13);
    gotoXY(173, 4);
    wcout << L"|█|" << endl;
    SetColor(10);
    gotoXY(173, 5);
    wcout << L"|█|" << endl;
    SetColor(15);
    gotoXY(173, 6);
    wcout << L"|█|" << endl;
    SetColor(14);
    gotoXY(173, 7);
    wcout << L"|█|" << endl;
    gotoXY(173, 8);
    wcout << L"───" << endl;

    gotoXY(177, 2);
    wcout << L"───     ──" << endl;
    gotoXY(177, 3);
    wcout << L"█|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(177, 4);
    wcout << L"█| ▀▄|  |█" << endl;
    SetColor(8);
    gotoXY(177, 5);
    wcout << L"█|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(177, 6);
    wcout << L"█|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(177, 7);
    wcout << L"█|     ▀|█" << endl;
    gotoXY(177, 8);
    wcout << L"──     ───" << endl;

    gotoXY(189, 2);
    wcout << L"───      ───" << endl;
    gotoXY(189, 3);
    wcout << L"|█|      |█|" << endl;
    SetColor(14);
    gotoXY(189, 4);
    wcout << L"|█|      |█|" << endl;
    SetColor(10);
    gotoXY(189, 5);
    wcout << L"|█|██████|█|" << endl;
    SetColor(13);
    gotoXY(189, 6);
    wcout << L"|█|      |█|" << endl;
    SetColor(3);
    gotoXY(189, 7);
    wcout << L"|█|      |█|" << endl;
    gotoXY(189, 8);
    wcout << L"───      ───" << endl;
}

void chinhanhHaNoi()
{
    gotoXY(14, 2);
    wcout << L"  ───     ──" << endl;
    gotoXY(14, 3);
    wcout << L"  █|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(14, 4);
    wcout << L"  █| ▀▄|  |█" << endl;
    SetColor(10);
    gotoXY(14, 5);
    wcout << L"  █|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(14, 6);
    wcout << L"  █|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(14, 7);
    wcout << L"  █|     ▀|█" << endl;
    gotoXY(14, 8);
    wcout << L"  ──     ───" << endl;

    gotoXY(26, 2);
    wcout << L"  ───      ───" << endl;
    gotoXY(26, 3);
    wcout << L"  |█|      |█|" << endl;
    SetColor(14);
    gotoXY(26, 4);
    wcout << L"  |█|      |█|" << endl;
    SetColor(10);
    gotoXY(26, 5);
    wcout << L"  |█|██████|█|" << endl;
    SetColor(13);
    gotoXY(26, 6);
    wcout << L"  |█|      |█|" << endl;
    SetColor(3);
    gotoXY(26, 7);
    wcout << L"  |█|      |█|" << endl;
    gotoXY(26, 8);
    wcout << L"  ───      ───" << endl;

    SetColor(13);
    gotoXY(41, 1);
    wcout << L"    ◤◥" << endl;
    SetColor(14);
    gotoXY(41, 2);
    wcout << L"    ───" << endl;
    gotoXY(41, 3);
    wcout << L"    ☗☗" << endl;
    SetColor(12);
    gotoXY(41, 4);
    wcout << L"   █▌|█▌" << endl;
    SetColor(10);
    gotoXY(41, 5);
    wcout << L"  █▌▌◛◛|█▌" << endl;
    SetColor(11);
    gotoXY(41, 6);
    wcout << L" █▌|    |█▌" << endl;
    SetColor(14);
    gotoXY(41, 7);
    wcout << L"█▌|      |█▌" << endl;
    gotoXY(41, 8);
    wcout << L"───      ───" << endl;

    gotoXY(53, 2);
    wcout << L"  ───     ──" << endl;
    gotoXY(53, 3);
    wcout << L"  █|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(53, 4);
    wcout << L"  █| ▀▄|  |█" << endl;
    SetColor(10);
    gotoXY(53, 5);
    wcout << L"  █|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(53, 6);
    wcout << L"  █|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(53, 7);
    wcout << L"  █|     ▀|█" << endl;
    gotoXY(53, 8);
    wcout << L"  ──     ───" << endl;

    SetColor(10);
    gotoXY(70, 2);
    wcout << L"───         ───" << endl;
    gotoXY(70, 3);
    wcout << L"▀▄|         |▄▀" << endl;
    SetColor(4);
    gotoXY(70, 4);
    wcout << L" ▀▄|       |▄▀" << endl;
    SetColor(13);
    gotoXY(70, 5);
    wcout << L"  ▀▄|     |▄▀" << endl;
    SetColor(14);
    gotoXY(70, 6);
    wcout << L"   ▀▄|   |▄▀" << endl;
    SetColor(12);
    gotoXY(70, 7);
    wcout << L"    ▀▄|_|▄▀" << endl;
    gotoXY(70, 8);
    wcout << L"      ───" << endl;

    SetColor(14);
    gotoXY(86, 1);
    wcout << L" ▄" << endl;
    SetColor(4);
    gotoXY(86, 2);
    wcout << L"───" << endl;
    gotoXY(86, 3);
    wcout << L"|█|" << endl;
    SetColor(13);
    gotoXY(86, 4);
    wcout << L"|█|" << endl;
    SetColor(10);
    gotoXY(86, 5);
    wcout << L"|█|" << endl;
    SetColor(15);
    gotoXY(86, 6);
    wcout << L"|█|" << endl;
    SetColor(14);
    gotoXY(86, 7);
    wcout << L"|█|" << endl;
    gotoXY(86, 8);
    wcout << L"───" << endl;

    SetColor(2);
    gotoXY(90, 1);
    wcout << L"  ◢◤◥◣" << endl;
    SetColor(9);
    gotoXY(90, 2);
    wcout << L" ────────" << endl;
    gotoXY(90, 3);
    wcout << L"|█|▀▀▀▀▀▀" << endl;
    SetColor(4);
    gotoXY(90, 4);
    wcout << L"|█|" << endl;
    SetColor(15);
    gotoXY(90, 5);
    wcout << L"|█|▀▀▀▀▀▀" << endl;
    SetColor(11);
    gotoXY(90, 6);
    wcout << L"|█|" << endl;
    SetColor(10);
    gotoXY(90, 7);
    wcout << L"|█|▄▄▄▄▄▄" << endl;
    gotoXY(90, 8);
    wcout << L" ────────" << endl;

    gotoXY(100, 2);
    wcout << L"───     ──" << endl;
    gotoXY(100, 3);
    wcout << L"█|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(100, 4);
    wcout << L"█| ▀▄|  |█" << endl;
    SetColor(8);
    gotoXY(100, 5);
    wcout << L"█|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(100, 6);
    wcout << L"█|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(100, 7);
    wcout << L"█|     ▀|█" << endl;
    gotoXY(100, 8);
    wcout << L"──     ───" << endl;

    gotoXY(116, 2);
    wcout << L"───      ───" << endl;
    gotoXY(116, 3);
    wcout << L"|█|      |█|" << endl;
    SetColor(14);
    gotoXY(116, 4);
    wcout << L"|█|      |█|" << endl;
    SetColor(10);
    gotoXY(116, 5);
    wcout << L"|█|██████|█|" << endl;
    SetColor(13);
    gotoXY(116, 6);
    wcout << L"|█|      |█|" << endl;
    SetColor(3);
    gotoXY(116, 7);
    wcout << L"|█|      |█|" << endl;
    gotoXY(116, 8);
    wcout << L"───      ───" << endl;

    SetColor(10);
    gotoXY(131, 1);
    wcout << L"    ◥◣" << endl;
    SetColor(14);
    gotoXY(131, 2);
    wcout << L"    ───" << endl;
    gotoXY(131, 3);
    wcout << L"    ☗☗" << endl;
    SetColor(12);
    gotoXY(131, 4);
    wcout << L"   █▌|█▌" << endl;
    SetColor(10);
    gotoXY(131, 5);
    wcout << L"  █▌▌◛◛|█▌" << endl;
    SetColor(11);
    gotoXY(131, 6);
    wcout << L" █▌|    |█▌" << endl;
    SetColor(14);
    gotoXY(131, 7);
    wcout << L"█▌|      |█▌" << endl;
    gotoXY(131, 8);
    wcout << L"───      ───" << endl;

    gotoXY(148, 2);
    wcout << L"───     ──" << endl;
    gotoXY(148, 3);
    wcout << L"█|▀▄|   |█" << endl;
    SetColor(13);
    gotoXY(148, 4);
    wcout << L"█| ▀▄|  |█" << endl;
    SetColor(8);
    gotoXY(148, 5);
    wcout << L"█|  ▀▄| |█" << endl;
    SetColor(14);
    gotoXY(148, 6);
    wcout << L"█|   ▀▄||█" << endl;
    SetColor(4);
    gotoXY(148, 7);
    wcout << L"█|     ▀|█" << endl;
    gotoXY(148, 8);
    wcout << L"──     ───" << endl;

    SetColor(13);
    gotoXY(159, 1);
    wcout << L"   ◢◤◥◣" << endl;
    SetColor(5);
    gotoXY(159, 2);
    wcout << L" ─────────" << endl;
    gotoXY(159, 3);
    wcout << L"|█████████|";
    SetColor(11);
    gotoXY(159, 4);
    wcout << L"|██|   |██|";
    SetColor(14);
    gotoXY(159, 5);
    wcout << L"|██|   |██|";
    SetColor(10);
    gotoXY(159, 6);
    wcout << L"|██|   |██|";
    SetColor(12);
    gotoXY(159, 7);
    wcout << L"|█████████|";
    gotoXY(159, 8);
    wcout << L" ─────────" << endl;
    SetColor(14);
    gotoXY(159, 9);
    wcout << L"     ▀    " << endl;

    SetColor(14);
    gotoXY(171, 1);
    wcout << L" ▄" << endl;
    SetColor(4);
    gotoXY(171, 2);
    wcout << L"───" << endl;
    gotoXY(171, 3);
    wcout << L"|█|" << endl;
    SetColor(13);
    gotoXY(171, 4);
    wcout << L"|█|" << endl;
    SetColor(10);
    gotoXY(171, 5);
    wcout << L"|█|" << endl;
    SetColor(15);
    gotoXY(171, 6);
    wcout << L"|█|" << endl;
    SetColor(3);
    gotoXY(171, 7);
    wcout << L"|█|" << endl;
    gotoXY(171, 8);
    wcout << L"───" << endl;
}
//================================================//
void khungchua()
{
    clrscr();
    for (int i = 0; i <= 45; i++)
    {
        for (int j = 0; j <= 199; j = j + 100)
        {
            textcolor(240);
            gotoXY(j, i);
            wcout << L"                                                                                                    ";
        }
    }
}

void resetbackground()
{
    clrscr();
    for (int i = 0; i <= 45; i++)
    {
        for (int j = 0; j <= 200; j = j + 100)
        {
            textcolor(1);
            gotoXY(j, i);
            wcout << L"                                                                                                    ";
        }
    }
}
//================================================//
int checkkitu(wstring a, wstring b)
{
    wstring a1 = L"aáàảạãăắằẳặẵâấầẩậẫbcdđeéèẻẹẽêếềểệễghiíìỉịĩklmnoóòỏọõôốồổộỗơớờởợỡpqrstuúùủụũưứừửữựvxyýỳỷỹỵwzjf";
    wstring a2 = L"AÁÀẢẠÃĂẮẰẲẶẴÂẤẦẨẬẪBCDĐEÉÈẺẸẼÊẾỀỂỆỄGHIÍÌỈỊĨKLMNOÓÒỎỌÕÔỐỒỔỘỖƠỚỜỞỢỠPQRSTUÚÙỦỤŨƯỨỪỬỮỰVXYÝỲỶỸỴWZJF";

    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < a1.length(); j++)
        {
            if (a[i] == a1[j])
                a[i] = a2[j];
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        for (int j = 0; j < a1.length(); j++)
        {
            if (b[i] == a1[j])
                b[i] = a2[j];
        }
    }
    if (a == b)
    {
        return 1;
    }
    else
        return 0;
}

void thanhsangkhungxuat(int x, int y, int bkg)
{
    textcolor(bkg);
    for (int i = y + 1; i <= y + 3; i++)
    {
        for (int j = x + 1; j < x + 48; j++)
        {
            gotoXY(j, i);
            wcout << L" ";
        }
    }
    textcolor(1);
}

void thanhsangchinhanh(int x, int y, int bkg)
{
    textcolor(bkg);
    for (int i = y + 1; i <= y + 3; i++)
    {
        for (int j = x + 1; j < x + 44; j++)
        {
            gotoXY(j, i);
            wcout << L" ";
        }
    }
    textcolor(1);
}
//================================================//
void chonchinhanh(ChiNhanh *ds, list2 l2)
{
    wstring s1 = L"Hồ Chí Minh";
    wstring s2 = L"Hà Nội";
    wstring s3 = L"Đà Nẵng";
    int x = 50;
    int y = 4;
    int bkg = 198;

    int ym = y;
    int bkgm = 1;
    while (true)
    {
        clrscr();

        if (ym == 4)
        {
            thanhsangchinhanh(x, ym, bkg);
            textcolor(198);
            gotoXY(x + 12, y + 2);
            wcout << L"Chi Nhánh Hồ Chí Minh" << endl;
            textcolor(1);

            gotoXY(x + 12, y + 5);
            wcout << L"Chi Nhánh Hà Nội" << endl;

            gotoXY(x + 12, y + 8);
            wcout << L"Chi Nhánh Đà Nẵng" << endl;
        }

        if (ym == 7)
        {
            gotoXY(x + 12, y + 2);
            wcout << L"Chi Nhánh Hồ Chí Minh" << endl;

            thanhsangchinhanh(x, ym, bkg);
            textcolor(198);
            gotoXY(x + 12, y + 5);
            wcout << L"Chi Nhánh Hà Nội" << endl;
            textcolor(1);

            gotoXY(x + 12, y + 8);
            wcout << L"Chi Nhánh Đà Nẵng" << endl;
        }

        if (ym == 10)
        {
            gotoXY(x + 12, y + 2);
            wcout << L"Chi Nhánh Hồ Chí Minh" << endl;

            gotoXY(x + 12, y + 5);
            wcout << L"Chi Nhánh Hà Nội" << endl;

            thanhsangchinhanh(x, ym, bkg);
            textcolor(198);
            gotoXY(x + 12, y + 8);
            wcout << L"Chi Nhánh Đà Nẵng" << endl;
            textcolor(1);
        }
        gotoXY(x, 4);
        wcout << L"╔═══════════════════════════════════════════╗";

        for (int i = 5; i <= 13; i++)
        {
            gotoXY(x, i);
            wcout << L"║";
            gotoXY(x + 44, i);
            wcout << L"║";
        }

        gotoXY(x, y + 10);
        wcout << L"╚═══════════════════════════════════════════╝";
        if (kbhit)
        {
            char c = getch();
            if (c == 72) // lên
            {
                if (ym > 4 && ym <= 10)
                {
                    thanhsangchinhanh(x, ym, bkgm);
                    ym -= 3;
                }
            }
            else if (c == 80) // xuống
            {
                if (ym >= 4 && ym < 10)
                {
                    thanhsangchinhanh(x, ym, bkgm);
                    ym += 3;
                }
            }
            else if (c == 13) // enter
            {
                if (ym == 4)
                {
                    thanhsangchinhanh(x, ym, bkgm);
                    clrscr();
                    chinhanhHCM();
                    ds->XuatTheoChiNhanh(l2, s1);
                    break;
                }

                if (ym == 7)
                {
                    thanhsangchinhanh(x, ym, bkgm);
                    clrscr();
                    chinhanhHaNoi();
                    ds->XuatTheoChiNhanh(l2, s2);
                    break;
                }

                if (ym == 10)
                {
                    thanhsangchinhanh(x, ym, bkgm);
                    clrscr();
                    chinhanhDN();
                    ds->XuatTheoChiNhanh(l2, s3);
                    break;
                }
                getch();
            }
        }
    }
}

void khungxuat(MyList *nv, list l, ChiNhanh *ds, list2 l2)
{
    int x = 50;
    int y = 4;
    int bkg = 198;

    int ym = y;
    int bkgm = 1;

    while (true)
    {
        clrscr();

        if (ym == 4)
        {
            thanhsangkhungxuat(x, ym, bkg);
            textcolor(198);
            gotoXY(x + 12, y + 2);
            wcout << L"DANH SÁCH TẤT CẢ NHÂN VIÊN" << endl;
            textcolor(1);

            gotoXY(x + 8, y + 5);
            wcout << L"DANH SÁCH NHÂN VIÊN THEO CHI NHÁNH" << endl;

            gotoXY(x + 22, y + 8);
            wcout << L"Thoát" << endl;
        }

        if (ym == 7)
        {

            gotoXY(x + 12, y + 2);
            wcout << L"DANH SÁCH TẤT CẢ NHÂN VIÊN" << endl;

            thanhsangkhungxuat(x, ym, bkg);
            textcolor(198);
            gotoXY(x + 8, y + 5);
            wcout << L"DANH SÁCH NHÂN VIÊN THEO CHI NHÁNH" << endl;
            textcolor(1);

            gotoXY(x + 22, y + 8);
            wcout << L"Thoát" << endl;
        }

        if (ym == 10)
        {

            gotoXY(x + 12, y + 2);
            wcout << L"DANH SÁCH TẤT CẢ NHÂN VIÊN" << endl;

            gotoXY(x + 8, y + 5);
            wcout << L"DANH SÁCH NHÂN VIÊN THEO CHI NHÁNH" << endl;

            thanhsangkhungxuat(x, ym, bkg);
            textcolor(198);
            gotoXY(x + 22, y + 8);
            wcout << L"Thoát" << endl;
            textcolor(1);
        }
        gotoXY(x, 4);
        wcout << L"╔═══════════════════════════════════════════════╗";

        for (int i = y + 1; i <= y + 9; i++)
        {
            gotoXY(x, i);
            wcout << L"║";
            gotoXY(x + 48, i);
            wcout << L"║";
        }

        gotoXY(x, y + 10);
        wcout << L"╚═══════════════════════════════════════════════╝";
        if (kbhit)
        {
            char c = getch();
            if (c == 72) // lên
            {
                if (ym > 4 && ym <= 10)
                {
                    thanhsangkhungxuat(x, ym, bkgm);
                    ym -= 3;
                }
            }
            else if (c == 80) // xuống
            {
                if (ym >= 4 && ym < 10)
                {
                    thanhsangkhungxuat(x, ym, bkgm);
                    ym += 3;
                }
            }
            else if (c == 13) // enter
            {
                if (ym == 4)
                {
                    thanhsangkhungxuat(x, ym, bkgm);
                    tiltle();
                    nv->XuatDanhSach(l, 2);
                    getch();
                }

                if (ym == 7)
                {
                    thanhsangkhungxuat(x, ym, bkgm);
                    clrscr();
                    while (true)
                    {
                        chonchinhanh(ds, l2);
                        wcout << L"\nNhấn ENTER để trở lại menu chọn xuất loại nhân viên!";
                        wcout << L"\nNhấn ESC để trở ra menu xuất !";
                        if (kbhit)
                        {
                            char ck = getch();
                            if (ck == 27)
                            {
                                break;
                            }
                        }
                    }
                }
                if (ym == 10)
                {
                    thanhsangkhungxuat(x, ym, bkgm);
                    gotoXY(x + 22, y + 8);
                    wcout << L"Thoát" << endl;
                    break;
                }
            }
        }
    }
}

//================================================//
//Sắp xếp tên

wchar_t VietIn(wchar_t x)
{
    wstring a1 = L"aáàảạãăắằẳặẵâấầẩậẫbcdđeéèẻẹẽêếềểệễghiíìỉịĩklmnoóòỏọõôốồổộỗơớờởợỡpqrstuúùủụũưứừửữựvxyýỳỷỹỵwzjf";
    wstring a2 = L"AÁÀẢẠÃĂẮẰẲẶẴÂẤẦẨẬẪBCDĐEÉÈẺẸẼÊẾỀỂỆỄGHIÍÌỈỊĨKLMNOÓÒỎỌÕÔỐỒỔỘỖƠỚỜỞỢỠPQRSTUÚÙỦỤŨƯỨỪỬỮỰVXYÝỲỶỸỴWZJF";
    for (int i = 0; i < a1.length(); i++)
    {
        if (a1[i] == x)
        {
            x = a2[i];
        }
    }
    return x;
}

wstring Chuyenten(wstring ten)
{
    ten[0] = VietIn(ten[0]);
    for (int i = ten.length() - 1; i >= 0; i--)
    {
        if (ten[i] == L' ')
        {
            ten[i + 1] = VietIn(ten[i + 1]);
        }
    }
    return ten;
}

wstring TachPhanTen(wstring ten)
{
    wstring a1 = L""; // phần tên
    wstring a2 = L""; // phần tên
    for (int i = ten.length() - 1; i >= 0; i--)
    {
        if (ten[i] == L' ')
        {
            break;
        }
        a1 += ten[i];
    }
    // wcout << a1 <<endl;
    for (int i = a1.length() - 1; i >= 0; i--)
    {
        a2 += a1[i];
    }
    return a2;
}

int check(wchar_t x, wchar_t y)
{
    wstring a2 = L"AÁÀẢẠÃĂẮẰẲẶẴÂẤẦẨẬẪBCDĐEÉÈẺẸẼÊẾỀỂỆỄGHIÍÌỈỊĨKLMNOÓÒỎỌÕÔỐỒỔỘỖƠỚỜỞỢỠPQRSTUÚÙỦỤŨƯỨỪỬỮỰVXYÝỲỶỸỴWZJF";

    x = VietIn(x);
    y = VietIn(y);

    int h, k;
    for (int i = 0; i < a2.length(); i++)
    {
        if (a2[i] == x)
        {
            h = i;
            break;
        }
    }
    for (int i = 0; i < a2.length(); i++)
    {

        if (a2[i] == y)
        {
            k = i;
            break;
        }
    }
    int c;
    if (h > k)
        c = 0;
    else if (h < k)
        c = 1;
    else
        c = 2;
    return c;
}

int sosanh(wstring a, wstring b)
{

    int s1 = a.length();
    int s2 = b.length();
    int len;
    if (s1 > s2)
        len = s1;
    else
        len = s2;
    int c = 0;
    for (int i = 0; i < len; i++)
    {
        if (check(a[i], b[i]) == 0)
        {
            c = 1;
            break;
        }
        else if (check(a[i], b[i]) == 1)
        {
            c = 0;
            break;
        }
        else if (check(a[i], b[i]) == 2)
        {
            if (i == s1 - 1 || i == s2 - 1)
            {
                if (s1 < s2)
                    c = 0;
                else
                    c = 1;
                break;
            }
        }
    }
    return c;
}
void sapxep(list &l)
{
    for (node *v = l.pHead; v != l.pTail; v = v->pNext)
    {
        for (node *h = v->pNext; h != NULL; h = h->pNext)
        {
            wstring a = TachPhanTen(v->data->getName());
            wstring b = TachPhanTen(h->data->getName());
            if (sosanh(a, b) == 1)
            {
                swap(v->data, h->data);
            }
        }
    }
}

//=============== *************** ================//
void MENU(list l, MyList *nv)
{
    ShowCur(0);
    clrscr();
    khungchua();
    khung_st(45, 11);
    getch();
    resetbackground();
    wifstream filein;
    wofstream fileout1;
    wofstream fileout2;
    int x = 75;
    int y = 4;
    int w = 60;
    int h = 3;
    int t_color = 11;
    int b_color = 1;
    int b_color_sang = 116;
    int sl = 8;
    int xp = x;
    int yp = y;
    int xcu = xp;
    int ycu = yp;
    bool kt = true;

    string maso;
    string fullname;
    bool check;
    while (true)
    {
        clrscr();
        N_BOX(x, y, w, h, t_color, b_color, sl);
        check = true;
        while (check = true)
        {
            if (kt == true)
            {
                gotoXY(xcu, ycu);
                thanhsang(xcu, ycu, w, h, t_color, b_color);
                xcu = xp;
                ycu = yp;
                thanhsang(xp, yp, w, h, t_color, b_color_sang);
                kt = false;
            }
            if (kbhit)
            {
                kt = true;
                char c = getch();
                if (c == 72)
                {
                    if (yp != y)
                        yp -= 5;
                    else
                    {
                        yp = y + h * (sl + 4) - 1;
                    }
                }
                else if (c == 80)
                {
                    if (yp != y + h * (sl + 4) - 1)
                        yp += 5;
                    else
                    {
                        yp = y;
                    }
                }
                else if (c == 13)
                {
                    if (yp == 4)
                    {
                        thanhsang(xp, yp, w, h, t_color, 0);
                        clrscr();
                        SetColor(3);
                        filein.open("NhanVien.txt", ios::in);
                        nv->DocDanhSachNhanVien(l, filein);
                        filein.close();
                        break;
                    }

                    if (yp == 9)
                    {
                        thanhsang(xp, yp, w, h, t_color, 0);
                        clrscr();
                        textcolor(6);
                        SetColor(5);
                        fileout1.open("NHANVIEN_out.txt", ios::out);
                        nv->XuatDanhSachVaoFile(l, fileout1);
                        fileout1.close();
                        fileout2.open("NhanVien.txt", ios::out);
                        nv->XuatDanhSachVaoFileX(l, fileout2);
                        fileout2.close();
                        wcout << L"\n\n\n\n\t\t\t\t\t\t\t\t\t\tXuất File Thành Công !";
                        wcout << L"\n\n\t\t\t\t\t\t\t\t\t\tNhấn Phím Bất Kì Để Trở Lại !";
                        getch();
                        break;
                    }

                    if (yp == 14)
                    {
                        thanhsang(xp, yp, w, h, t_color, 0);
                        clrscr();
                        textcolor(3);
                        SetColor(3);
                        list2 l2;
                        ChiNhanh *ds = new ChiNhanh();
                        ds->Khoitao(l2);
                        ds->AddNhanVien(l, l2);

                        khungxuat(nv, l, ds, l2);
                        break;
                    }

                    if (yp == 19)
                    {
                        thanhsang(xp, yp, w, h, t_color, 0);
                        clrscr();
                        textcolor(6);
                        SetColor(5);
                        bool kt_c = true;

                        int xm = 65;
                        int ym = 4;
                        int xp1 = xm;
                        int yp1 = ym;
                        khungds();
                        NhanVien *x = NULL;
                        while (kt_c)
                        {

                            khungds();
                            if (kbhit)
                            {
                                if (yp1 == 4)
                                {
                                    SetColor(15);
                                    muiten(xp1, yp1);
                                    SetColor(12);
                                    gotoXY(70, 4);
                                    wcout << L"1. NHÂN VIÊN VĂN PHÒNG ";
                                    getch();
                                }
                                else if (yp1 != 4)
                                {
                                    ghidemuiten(xp1, yp1);
                                    ghidemuiten(xp1 + 30, yp1);
                                }
                                if (yp1 == 6)
                                {
                                    SetColor(15);
                                    muiten(xp1, yp1);
                                    SetColor(12);
                                    gotoXY(70, 6);
                                    wcout << L"2. NHÂN VIÊN SẢN XUẤT ";
                                    getch();
                                }
                                else if (yp1 != 6)
                                {
                                    ghidemuiten(xp1, yp1);
                                    ghidemuiten(xp1 + 30, yp1);
                                }
                                if (yp1 == 8)
                                {
                                    SetColor(15);
                                    muiten(xp1, yp1);
                                    SetColor(12);
                                    gotoXY(70, 8);
                                    wcout << L"3. NHÂN VIÊN MARKETING ";
                                    getch();
                                }
                                else if (yp1 != 8)
                                {
                                    ghidemuiten(xp1, yp1);
                                    ghidemuiten(xp1 + 30, yp1);
                                }
                                if (yp1 == 10)
                                {
                                    SetColor(15);
                                    muiten(xp1, yp1);
                                    SetColor(12);
                                    gotoXY(70, 10);
                                    wcout << L"4. NHÂN VIÊN KINH DOANH ";
                                    getch();
                                }
                                else if (yp1 != 10)
                                {
                                    ghidemuiten(xp1, yp1);
                                    ghidemuiten(xp1 + 30, yp1);
                                }
                                if (yp1 == 12)
                                {
                                    SetColor(15);
                                    muiten(xp1, yp1);
                                    SetColor(12);
                                    gotoXY(70, 12);
                                    wcout << L"5. Trở Về MENU";
                                    getch();
                                }
                                else if (yp1 != 12)
                                {

                                    ghidemuiten(xp1, yp1);
                                    ghidemuiten(xp1 + 30, yp1);
                                }
                                char c = getch();
                                if (c == 72) //lên
                                {
                                    if (yp1 > 4 && yp1 <= 12)
                                    {
                                        if (yp1 == 12)
                                        {
                                            ghidemuiten(xp1, yp1);
                                            ghidemuiten(xp1 + 30, yp1);
                                        }
                                        yp1 -= 2;
                                    }
                                }
                                else if (c == 80) // xuống
                                {

                                    if (yp1 >= 4 && yp1 <= 10)
                                    {
                                        yp1 += 2;
                                    }
                                }
                                else if (c == 13) //phím enter
                                {
                                    SetColor(15);
                                    if (yp1 == 4)
                                    {
                                        clrscr();
                                        x = new NhanVienVanPhong();
                                        x->Nhap();
                                        nv->ThemVaoCuoi(l, x);
                                        wcout << L"\n\n\n\n\t\t\t\t\t\t\t\t Đã ADD Nhân Viên thành công !";
                                        wcout << L"\n\n\n\t\t\t\t\t\t\t\t Nhấn Phím Bất Kì Để Trở Lại !";
                                        getch();
                                    }
                                    else if (yp1 == 6)
                                    {
                                        clrscr();
                                        x = new NhanVienSanXuat();
                                        x->Nhap();
                                        nv->ThemVaoCuoi(l, x);
                                        wcout << L"\n\n\n\n\t\t\t\t\t\t\t\t Đã ADD Nhân Viên thành công !";
                                        wcout << L"\n\n\n\t\t\t\t\t\t\t\t Nhấn Phím Bất Kì Để Trở Lại !";
                                        getch();
                                    }

                                    else if (yp1 == 8)
                                    {
                                        clrscr();
                                        x = new NhanVienMarketing();
                                        x->Nhap();
                                        nv->ThemVaoCuoi(l, x);
                                        wcout << L"\n\n\n\n\t\t\t\t\t\t\t\t Đã ADD Nhân Viên thành công !";
                                        wcout << L"\n\n\n\t\t\t\t\t\t\t\t Nhấn Phím Bất Kì Để Trở Lại !";
                                        getch();
                                    }
                                    else if (yp1 == 10)
                                    {
                                        clrscr();
                                        x = new NhanVienKinhDoanh();
                                        x->Nhap();
                                        nv->ThemVaoCuoi(l, x);
                                        wcout << L"\n\n\n\n\t\t\t\t\t\t\t\t Đã ADD Nhân Viên thành công !";
                                        wcout << L"\n\n\n\t\t\t\t\t\t\t\t Nhấn Phím Bất Kì Để Trở Lại !";
                                        getch();
                                    }

                                    else if (yp1 == 12)
                                    {

                                        kt_c = false;
                                    }
                                    clrscr();
                                }
                            }
                        }
                        N_BOX(75, y, w, h, t_color, b_color, sl);
                    }

                    if (yp == 24)
                    {
                        thanhsang(xp, yp, w, h, t_color, 0);
                        clrscr();
                        textcolor(6);
                        SetColor(5);
                        while (true)
                        {
                            clrscr();
                            ds_delete(20);
                            gotoXY(60, 14);
                            wcout << L" Nhập lựa chọn của bạn : ";
                            int type;
                            NhanVien *x = NULL;
                            wcin >> type;
                            if (type == 1)
                            {
                                int check = 0;
                                while (check == 0)
                                {
                                    clrscr();
                                    ds_delete(20);
                                    gotoXY(60, 14);
                                    wcout << L" Lựa chọn của bạn : " << type << endl;
                                    fflush(stdin);
                                    wstring maso;
                                    gotoXY(61, 16);
                                    wcout << L"Nhập ID của nhân viên cần DELETE : ";
                                    getline(wcin, maso);
                                    clrscr();

                                    for (node *k = l.pHead; k != NULL; k = k->pNext)
                                    {
                                        if (k->data->getID() == maso)
                                        {
                                            ds_delete(0);
                                            SetColor(12);
                                            gotoXY(50, 5);
                                            wcout << L"1. XÓA THEO MÃ SỐ";
                                            SetColor(7);
                                            x = k->data;
                                            check = 1;
                                            break;
                                        }
                                        else
                                            check = 0;
                                    }
                                    if (check == 0)
                                    {
                                        gotoXY(50, 15);
                                        wcout << L"Không tìm thấy nhân viên cần tìm ";
                                    }
                                    else
                                    {
                                        nv->XoaNodeTheoMaSo(l, x->getID());
                                        gotoXY(50, 15);
                                        wcout << L"Đã DELETE nhân viên cần DELETE ";
                                    }
                                    gotoXY(50, 17);
                                    wcout << L"Nhấn phím bất kì để trở lại !";
                                    getch();
                                }
                            }
                            if (type == 2)
                            {
                                int _check = 0;
                                while (_check == 0)
                                {
                                    clrscr();
                                    ds_delete(20);
                                    gotoXY(60, 14);
                                    wcout << L" Lựa chọn của bạn : " << type << endl;
                                    fflush(stdin);
                                    wstring fullname;
                                    gotoXY(61, 16);
                                    wcout << L"Nhập tên của nhân viên cần tìm : ";
                                    fflush(stdin);
                                    getline(wcin, fullname);
                                    clrscr();
                                    int check = 0;
                                    for (node *k = l.pHead; k != NULL; k = k->pNext)
                                    {
                                        if (checkkitu(k->data->getName(), fullname) == 1)
                                        {
                                            ds_delete(0);
                                            SetColor(12);
                                            gotoXY(50, 7);
                                            wcout << L"2. XÓA THEO TÊN ";
                                            SetColor(7);
                                            x = k->data;
                                            _check = 1;
                                            break;
                                        }
                                        else
                                            _check == 0;
                                    }
                                    if (_check == 0)
                                    {
                                        gotoXY(50, 15);
                                        wcout << L"Không tìm thấy nhân viên cần tìm ";
                                    }
                                    else
                                    {
                                        nv->XoaNodeTheoTen(l, x->getName());
                                        gotoXY(50, 15);
                                        wcout << L"Đã DELETE nhân viên cần DELETE ";
                                        _check = 1;
                                    }
                                    gotoXY(50, 17);
                                    wcout << L"Nhấn phím bất kì để trở lại !";
                                    getch();
                                }
                            }
                            else if (type == 3)
                            {
                                clrscr();
                                break;
                            }
                        }
                        fileout2.open("NhanVien.txt", ios::out);
                        nv->XuatDanhSachVaoFileX(l, fileout2);
                        fileout2.close();
                        break;
                    }
                    if (yp == 29)
                    {
                        NhanVien *nvv = NULL;
                        thanhsang(xp, yp, w, h, t_color, 0);
                        textcolor(6);
                        SetColor(5);
                        clrscr();
                        fflush(stdin);
                        wstring maso;
                        bool check_id = false;
                        int p = 0;
                        while (check_id == false)
                        {
                            clrscr();
                            if (p != 0)
                            {
                                gotoXY(18, 12);
                                wcout << L"Không Tìm Thấy Nhân Viên Cần Sửa! Hãy Nhập Lại ID !";
                            }
                            gotoXY(20, 14);
                            wcout << L"╔═════════════════════════════════════════════════════╗";
                            for (int i = 15; i <= 16; i++)
                            {
                                gotoXY(20, i);
                                wcout << L"║";
                                gotoXY(74, i);
                                wcout << L"║";
                            }
                            gotoXY(20, 17);
                            wcout << L"╚═════════════════════════════════════════════════════╝";

                            gotoXY(22, 10);
                            SetColor(14);
                            wcout << L"\n\n\n\n\n\n \t\t\t Nhập ID Của Nhân Viên Cần Chỉnh Sửa : ";
                            getline(wcin, maso);

                            if (maso[0] == 'V')
                            {
                                nvv = new NhanVienVanPhong();
                            }
                            else if (maso[0] == 'S')
                            {
                                nvv = new NhanVienSanXuat();
                            }
                            else if (maso[0] == 'M')
                            {
                                nvv = new NhanVienMarketing();
                            }
                            else if (maso[0] == 'K')
                            {
                                nvv = new NhanVienKinhDoanh();
                            }

                            SetColor(5);

                            for (node *k = l.pHead; k != NULL; k = k->pNext)
                            {
                                if (k->data->getID() == maso)
                                {
                                    nvv = k->data;
                                    check_id = true;
                                    p = 1;
                                    break;
                                }
                                else
                                {
                                    check_id = false;
                                    p++;
                                }
                            }
                        }
                        while (true)
                        {
                            thanhsang(xp, yp, w, h, t_color, 0);
                            clrscr();
                            khungupdate(x, maso);
                            int chon;
                            do
                            {
                                wcout << L"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tNhap Lua Chon Cua Ban : ";
                                wcin >> chon;
                            } while (chon < 1 || chon > 9);

                            if (chon == 1)
                            {
                                nv->UpdateID(l, nvv);
                                wcout << L"\n\n\t\t\t\t\t\t\t\t\t\t Nhấn phím bất kì để trở lại ! ";
                                getch();
                            }
                            nvv->DoUpdate(chon);
                            if (chon == 9)
                            {
                                clrscr();
                                break;
                            }
                        }

                        thanhsang(xp, yp, w, h, t_color, 0);
                        clrscr();
                        textcolor(3);
                        SetColor(3);
                        nv->XuatDanhSach(l, 2);
                        getch();
                        fileout2.open("NhanVien.txt", ios::out);
                        nv->XuatDanhSachVaoFileX(l, fileout2);
                        fileout2.close();
                        break;
                    }

                    if (yp == 34)
                    {
                        thanhsang(xp, yp, w, h, t_color, 0);
                        clrscr();
                        textcolor(6);
                        SetColor(5);

                        while (true)
                        {
                            clrscr();
                            ds_search(20);
                            gotoXY(60, 14);
                            wcout << L" Nhập Lựa Chọn Của Bạn : ";
                            int type;

                            wcin >> type;
                            if (type == 1)
                            {
                                int check = 1;
                                fflush(stdin);
                                wstring maso;
                                gotoXY(61, 16);
                                wcout << L"Nhập ID Của Nhân Viên Cần Tìm : ";
                                getline(wcin, maso);
                                while (check != 0)
                                {
                                    for (node *k = l.pHead; k != NULL; k = k->pNext)
                                    {
                                        if (k->data->getID() == maso)
                                        {
                                            check = 0;
                                            break;
                                        }
                                        else
                                        {
                                            check++;
                                        }
                                    }
                                    if (check != 0)
                                    {
                                        clrscr();
                                        ds_search(20);
                                        gotoXY(60, 14);
                                        wcout << L" Lựa Chọn Của Bạn : " << type;
                                        gotoXY(61, 16);
                                        wcout << L"Không Tìm Thấy Nhân Viên!";
                                        gotoXY(61, 18);
                                        wcout << L"Nhập Lại ID Của Nhân Viên Cần Tìm : ";
                                        getline(wcin, maso);
                                    }
                                    if (check == 0)
                                    {
                                        for (node *k = l.pHead; k != NULL; k = k->pNext)
                                        {
                                            if (k->data->getID() == maso)
                                            {
                                                clrscr();
                                                ds_search(0);
                                                SetColor(12);
                                                gotoXY(70, 5);
                                                wcout << L"1. Tìm Kiếm Theo Mã Số";

                                                SetColor(1);
                                                int dem = 1;
                                                wcout << L"\n\n\n\n\n\n\n\n\n\n≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛";

                                                wcout << L"\n┌──────┬──────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┐";
                                                wcout << setw(1) << left << L"\n│" << setw(6) << left << L"  STT" << setw(1) << left << L"│" << setw(14) << left << L"    Mã số" << L"│" << setw(24) << left << L"      Họ và tên" << L"│" << setw(24) << left << L"      Ngày sinh" << L"│" << setw(24) << left << L"      Số điện thoại" << L"│" << setw(24) << left << L"        Địa chỉ" << L"│" << setw(24) << left << L"      Lương cơ bản" << L"│" << setw(24) << left << L"      Lương tháng" << L"│" << setw(24) << left << L"      Chi Nhánh" << L"│";
                                                for (node *p = l.pHead; p != NULL; p = p->pNext)
                                                {
                                                    if (p->data->getID() == maso)
                                                    {

                                                        wcout << L"\n├──────┼──────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┤";
                                                        wcout << setw(1) << left << L"\n│" << L"  " << setw(4) << left << dem << setw(1) << left << L"│" << L"   " << setw(11) << left << p->data->getID() << L"│" << L"    " << setw(20) << left << p->data->getName() << L"│" << L"    " << setw(20) << left << p->data->getNgaySinh() << L"│" << L"    " << setw(20) << left << p->data->getSDT() << L"│" << L"    " << setw(20) << left << p->data->getAddress() << L"│" << L"    " << setw(20) << left << p->data->getLuongCB() << L"│" << L"    " << setw(20) << left << p->data->TinhLuong() << L"│" << "    " << setw(20) << left << p->data->getChiNhanh() << L"│";

                                                        dem += 1;
                                                    }
                                                }
                                                wcout << L"\n└──────┴──────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┘";
                                                wcout << L"\n✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ";
                                                dem -= 1;
                                                wcout << L"\n\n Đã tìm thấy " << dem << L" Nhân Viên theo yêu cầu !";
                                                getch();
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            if (type == 2)
                            {
                                wstring fullname;
                                gotoXY(61, 16);
                                wcout << L"Nhập Tên Của Nhân Viên Cần Tìm : ";
                                fflush(stdin);
                                getline(wcin, fullname);
                                int check = 1;
                                wstring NAME;
                                NAME = Chuyenten(fullname);
                                while (check != 0)
                                {
                                    for (node *k = l.pHead; k != NULL; k = k->pNext)
                                    {

                                        if (checkkitu(k->data->getName(), fullname) == 1 || TachPhanTen(k->data->getName()) == TachPhanTen(NAME))
                                        {
                                            check = 0;
                                            break;
                                        }
                                        else
                                        {
                                            check++;
                                        }
                                    }
                                    if (check != 0)
                                    {
                                        clrscr();
                                        ds_search(20);
                                        gotoXY(60, 14);
                                        wcout << L" Lựa Chọn Của Bạn : " << type;
                                        gotoXY(61, 16);
                                        wcout << L"Không Tìm Thấy Nhân Viên!";
                                        gotoXY(61, 18);
                                        wcout << L"Nhập Lại Tên Của Nhân Viên Cần Tìm : ";
                                        getline(wcin, fullname);
                                        NAME = Chuyenten(fullname);
                                    }
                                    if (check == 0)
                                    {
                                        for (node *k = l.pHead; k != NULL; k = k->pNext)
                                        {
                                            if (checkkitu(k->data->getName(), fullname) == 1)
                                            {
                                                clrscr();
                                                ds_search(0);
                                                SetColor(12);
                                                gotoXY(70, 7);
                                                wcout << L"2. Tìm Kiếm Theo Tên";

                                                SetColor(1);
                                                int dem = 1;
                                                wcout << L"\n\n\n\n\n\n\n\n\n\n≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛";

                                                wcout << L"\n┌──────┬──────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┐";
                                                wcout << setw(1) << left << L"\n│" << setw(6) << left << L"  STT" << setw(1) << left << L"│" << setw(14) << left << L"    Mã số" << L"│" << setw(24) << left << L"      Họ và tên" << L"│" << setw(24) << left << L"      Ngày sinh" << L"│" << setw(24) << left << L"      Số điện thoại" << L"│" << setw(24) << left << L"        Địa chỉ" << L"│" << setw(24) << left << L"      Lương cơ bản" << L"│" << setw(24) << left << L"      Lương tháng" << L"│" << setw(24) << left << L"      Chi Nhánh" << L"│";
                                                for (node *p = l.pHead; p != NULL; p = p->pNext)
                                                {
                                                    if (checkkitu(p->data->getName(), fullname) == 1)
                                                    {

                                                        wcout << L"\n├──────┼──────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┤";
                                                        wcout << setw(1) << left << L"\n│" << L"  " << setw(4) << left << dem << setw(1) << left << L"│" << L"   " << setw(11) << left << p->data->getID() << L"│" << L"    " << setw(20) << left << p->data->getName() << L"│" << L"    " << setw(20) << left << p->data->getNgaySinh() << L"│" << L"    " << setw(20) << left << p->data->getSDT() << L"│" << L"    " << setw(20) << left << p->data->getAddress() << L"│" << L"    " << setw(20) << left << p->data->getLuongCB() << L"│" << L"    " << setw(20) << left << p->data->TinhLuong() << L"│" << "    " << setw(20) << left << p->data->getChiNhanh() << L"│";

                                                        dem += 1;
                                                    }
                                                }
                                                wcout << L"\n└──────┴──────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┘";
                                                wcout << L"\n✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ";
                                                dem -= 1;
                                                wcout << L"\n\n Đã tìm thấy " << dem << L" Nhân Viên theo yêu cầu !";
                                                getch();
                                                break;
                                            }

                                            if (TachPhanTen(k->data->getName()) == TachPhanTen(NAME))
                                            {
                                                clrscr();
                                                ds_search(0);
                                                SetColor(12);
                                                gotoXY(70, 7);
                                                wcout << L"2. Tìm Kiếm Theo Tên";

                                                SetColor(1);
                                                int dem = 1;
                                                wcout << L"\n\n\n\n\n\n\n\n\n\n≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛≛";

                                                wcout << L"\n┌──────┬──────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┬────────────────────────┐";
                                                wcout << setw(1) << left << L"\n│" << setw(6) << left << L"  STT" << setw(1) << left << L"│" << setw(14) << left << L"    Mã số" << L"│" << setw(24) << left << L"      Họ và tên" << L"│" << setw(24) << left << L"      Ngày sinh" << L"│" << setw(24) << left << L"      Số điện thoại" << L"│" << setw(24) << left << L"        Địa chỉ" << L"│" << setw(24) << left << L"      Lương cơ bản" << L"│" << setw(24) << left << L"      Lương tháng" << L"│" << setw(24) << left << L"      Chi Nhánh" << L"│";
                                                for (node *p = l.pHead; p != NULL; p = p->pNext)
                                                {
                                                    if (TachPhanTen(p->data->getName()) == TachPhanTen(NAME))
                                                    {

                                                        wcout << L"\n├──────┼──────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┼────────────────────────┤";
                                                        wcout << setw(1) << left << L"\n│" << L"  " << setw(4) << left << dem << setw(1) << left << L"│" << L"   " << setw(11) << left << p->data->getID() << L"│" << L"    " << setw(20) << left << p->data->getName() << L"│" << L"    " << setw(20) << left << p->data->getNgaySinh() << L"│" << L"    " << setw(20) << left << p->data->getSDT() << L"│" << L"    " << setw(20) << left << p->data->getAddress() << L"│" << L"    " << setw(20) << left << p->data->getLuongCB() << L"│" << L"    " << setw(20) << left << p->data->TinhLuong() << L"│" << "    " << setw(20) << left << p->data->getChiNhanh() << L"│";

                                                        dem += 1;
                                                    }
                                                }
                                                wcout << L"\n└──────┴──────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┴────────────────────────┘";
                                                wcout << L"\n✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ✪ ";
                                                dem -= 1;
                                                wcout << L"\n\n Đã tìm thấy " << dem << L" Nhân Viên theo yêu cầu !";

                                                getch();

                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            else if (type == 3)
                            {
                                clrscr();
                                break;
                            }
                        }
                        fileout2.open("NhanVien.txt", ios::out);
                        nv->XuatDanhSachVaoFileX(l, fileout2);
                        fileout2.close();
                        break;
                    }

                    if (yp == 39)
                    {
                        thanhsang(xp, yp, w, h, t_color, 0);
                        clrscr();
                        textcolor(6);
                        SetColor(5);
                        int chon;
                        // getch();
                        while (true)
                        {
                            thanhsang(xp, yp, w, h, t_color, 0);
                            clrscr();
                            textcolor(6);
                            SetColor(5);
                            clrscr();
                            ds_sapxep(20);
                            gotoXY(60, 14);
                            wcout << L" Nhập Lựa Chọn Của Bạn : ";
                            wcin >> chon;
                            if (chon == 1)
                            {
                                thanhsang(xp, yp, w, h, t_color, 0);
                                clrscr();
                                textcolor(6);
                                SetColor(5);
                                clrscr();
                                gotoXY(70, 15);
                                wcout << L"Đã sắp xếp nhân viên theo thứ tự tăng dần Lương Tháng!";
                                for (node *k = l.pHead; k != l.pTail; k = k->pNext)
                                {
                                    for (node *h = k->pNext; h != NULL; h = h->pNext)
                                    {
                                        if (k->data->TinhLuong() > h->data->TinhLuong())
                                        {
                                            swap(k->data, h->data);
                                        }
                                    }
                                }
                                gotoXY(70, 19);
                                wcout << L"Nhấn phím bất kì để hiện bảng danh sách !";
                                getch();
                                thanhsang(xp, yp, w, h, t_color, 0);
                                clrscr();
                                textcolor(3);
                                SetColor(3);
                                nv->XuatDanhSach(l, 2);
                                getch();
                            }
                            if (chon == 2)
                            {
                                thanhsang(xp, yp, w, h, t_color, 0);
                                clrscr();
                                textcolor(6);
                                SetColor(5);
                                clrscr();
                                gotoXY(70, 15);
                                wcout << L"Đã sắp xếp nhân viên theo thứ tự tăng dần theo tên!";
                                int k;
                                sapxep(l);
                                gotoXY(70, 19);
                                wcout << L"Nhấn phím bất kì để hiện bảng danh sách !";
                                getch();
                                thanhsang(xp, yp, w, h, t_color, 0);
                                clrscr();
                                textcolor(3);
                                SetColor(3);
                                nv->XuatDanhSach(l, 2);
                                getch();
                            }
                            else if (chon == 3)
                            {
                                clrscr();
                                break;
                            }
                        }
                        fileout2.open("NhanVien.txt", ios::out);
                        nv->XuatDanhSachVaoFileX(l, fileout2);
                        fileout2.close();
                        break;
                    }
                }
            }
        }
        check = false;
        textcolor(1);
    }
    getch();
}

int main()
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  //needed for input
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    list l;
    MyList *nv = new MyList();
    nv->KhoiTao(l);
    MENU(l, nv);
    return 0;
}
