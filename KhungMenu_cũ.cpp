// #include <iostream>
// #include <windows.h>
// #include <conio.h> // getch()
// #include "MyList.h"
// #include "mylib.h" // đồ họa
// #include <fcntl.h> // sử dụng tiếng việt với console tiếng việt
// #include <io.h>    // sử dụng tiếng việt với console tiếng việt
// #include <string>
// #include <locale>  // Để chỉnh sửa phông chữ
// #include <codecvt> // Để chỉnh sửa phông chữ

// #pragma warning(disable : 4996)

// using namespace std;

// void noidung(int x, int y)
// {
//     for (int i = 1; i <= 8; i++)
//     {
//         y = i * 4;
//         if (y == 4)
//         {
//             gotoXY(x + 17, y + 2);
//             wcout << L"Đọc thông tin Nhân Viên";
//         }
//         else if (y == 8)
//         {
//             gotoXY(x + 17, y + 3);
//             wcout << L"Xuất thông tin vào File";
//         }
//         else if (y == 12)
//         {
//             gotoXY(x + 17, y + 4);
//             wcout << L"Xuất thông tin Nhân Viên";
//         }
//         else if (y == 16)
//         {
//             gotoXY(x + 15, y + 5);
//             wcout << L"Thêm Nhân Viên vào danh sách";
//         }
//         else if (y == 20)
//         {
//             gotoXY(x + 23, y + 6);
//             wcout << L"Xóa Nhân Viên";
//         }
//         else if (y == 24)
//         {
//             gotoXY(x + 22, y + 7);
//             wcout << L"Update Nhân Viên";
//         }
//         else if (y == 28)
//         {
//             gotoXY(x + 21, y + 8);
//             wcout << L"Tìm kiếm Nhân Viên";
//         }
//         else if (y == 32)
//         {
//             gotoXY(x + 22, y + 9);
//             wcout << L"Sắp xếp Nhân Viên";
//         }
//     }
// }

// void BOX(int x, int y, int w, int h, int t_color, int b_color)
// {
//     // màu nền
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
//     for (int iy = y + 1; iy <= y + h; iy++)
//     {
//         for (int ix = x + 1; ix <= x + 1; ix++)
//         {
//             gotoXY(ix, iy);
//             wcout << L"                                                           ";
//         }
//     }
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
//     SetColor(t_color);
//     if (h <= 1 || w <= 1)
//         return;
//     gotoXY(x, y);
//     wcout << L"╔══════════════════════════════════════════════════════════╗";
//     for (int iy = y; iy <= y + h; iy++)
//     {
//         gotoXY(x, iy + 1);
//         wcout << L"║";
//         gotoXY(x + w - 1, iy + 1);
//         wcout << L"║";
//     }
//     gotoXY(x, y + h + 1);
//     wcout << L"╚══════════════════════════════════════════════════════════╝";
// }

// void N_BOX(int x, int y, int w, int h, int t_color, int b_color, int sl)
// {
//     SetColor(12);
//     gotoXY(x - 4, 0);
//     wcout << L"╔══════════════════════════════════════════════════════════════════╗";
//     gotoXY(x - 4, 1);
//     wcout << L"║";
//     gotoXY(x + w + 3, 1);
//     wcout << L"║";
//     gotoXY(x - 4, 2);
//     wcout << L"╚══════════════════════════════════════════════════════════════════╝";
//     SetColor(11);
//     gotoXY(x + 17, 1);
//     wcout << L"HỆ THỐNG QUẢN LÍ NHÂN VIÊN";

//     SetColor(10);
//     gotoXY(x - 1, y - 1);
//     wcout << L"╔════════════════════════════════════════════════════════════╗";
//     for (int iy = y; iy <= sl + 35; iy++)
//     {
//         gotoXY(x - 1, iy);
//         wcout << L"║";
//         gotoXY(x + w, iy);
//         wcout << L"║";
//     }
//     gotoXY(x - 1, y + 40);
//     wcout << L"╚════════════════════════════════════════════════════════════╝";
//     for (int i = 0; i < sl; i++)
//     {
//         BOX(x, y + (i * 4), w, h, t_color, b_color);
//         y++;
//     }
//     noidung(x, y);
// }

// void thanhsang(int x, int y, int w, int h, int t_color, int b_color_sang)
// {
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), b_color_sang);
//     for (int iy = y + 1; iy <= y + h; iy++)
//     {
//         for (int ix = x + 1; ix <= x + 1; ix++)
//         {
//             gotoXY(ix, iy);
//             wcout << L"                                                          ";
//         }
//     }
//     if (y == 4)
//     {
//         gotoXY(x + 17, y + 2);
//         wcout << L"Đọc thông tin Nhân Viên";
//     }
//     if (y == 9)
//     {
//         gotoXY(x + 17, y + 2);
//         wcout << L"Xuất thông tin vào File";
//     }
//     if (y == 14)
//     {
//         gotoXY(x + 17, y + 2);
//         wcout << L"Xuất thông tin Nhân Viên";
//     }
//     if (y == 19)
//     {
//         gotoXY(x + 15, y + 2);
//         wcout << L"Thêm Nhân Viên vào danh sách";
//     }
//     if (y == 24)
//     {
//         gotoXY(x + 23, y + 2);
//         wcout << L"Xóa Nhân Viên";
//     }
//     if (y == 29)
//     {
//         gotoXY(x + 22, y + 2);
//         wcout << L"Update Nhân Viên";
//     }
//     if (y == 34)
//     {
//         gotoXY(x + 21, y + 2);
//         wcout << L"Tìm kiếm Nhân Viên";
//     }
//     if (y == 39)
//     {
//         gotoXY(x + 22, y + 2);
//         wcout << L"Sắp xếp Nhân Viên";
//     }
// }
// //=============== Khung danh sách ================//

// void khungds()
// {
//     textcolor(2);
//     gotoXY(50, 0);
//     wcout << L"╔═══════════════════════════════════════════════════════╗";
//     gotoXY(50, 1);
//     wcout << L"║";
//     gotoXY(106, 1);
//     wcout << L"║";
//     gotoXY(50, 2);
//     wcout << L"╚═══════════════════════════════════════════════════════╝";
//     gotoXY(50, 3);
//     wcout << L"╔═══════════════════════════════════════════════════════╗";
//     for (int i = 4; i <= 16; i++)
//     {
//         gotoXY(50, i);
//         wcout << L"║";
//         gotoXY(106, i);
//         wcout << L"║";
//     }
//     gotoXY(50, 16);
//     wcout << L"╚═══════════════════════════════════════════════════════╝";
//     gotoXY(65, 1);
//     wcout << L"CHỌN LOẠI NHÂN VIÊN MUỐN THÊM";

//     gotoXY(60, 4);
//     wcout << L"1. NHÂN VIÊN VĂN PHÒNG ";
//     gotoXY(60, 6);
//     wcout << L"2. NHÂN VIÊN SẢN XUẤT ";
//     gotoXY(60, 8);
//     wcout << L"3. NHÂN VIÊN MARKETING ";
//     gotoXY(60, 10);
//     wcout << L"4. NHÂN VIÊN KINH DOANH ";
//     gotoXY(60, 12);
//     wcout << L"5. Trở về MENU";
//     gotoXY(60, 18);
//     wcout << L"Nhập lựa chọn của bạn : ";
// }

// //=============== *************** ================//

// // danh sách tìm kiếm

// void ds_search(int x)
// {
//     textcolor(2);
//     gotoXY(x + 40, 0);
//     wcout << L"╔═══════════════════════════════════════════════════════╗";
//     gotoXY(x + 40, 1);
//     wcout << L"║";
//     gotoXY(x + 96, 1);
//     wcout << L"║";
//     gotoXY(x + 40, 2);
//     wcout << L"╚═══════════════════════════════════════════════════════╝";
//     gotoXY(x + 40, 3);
//     wcout << L"╔═══════════════════════════════════════════════════════╗";
//     for (int i = 4; i <= 12; i++)
//     {
//         gotoXY(x + 40, i);
//         wcout << L"║";
//         gotoXY(x + 96, i);
//         wcout << L"║";
//     }
//     gotoXY(x + 40, 12);
//     wcout << L"╚═══════════════════════════════════════════════════════╝";
//     gotoXY(x + 55, 1);
//     wcout << L"CÁC CÁCH TÌM KIẾM NHÂN VIÊN";

//     gotoXY(x + 50, 5);
//     wcout << L"1. TÌM KIẾM THEO MÃ SỐ";
//     gotoXY(x + 50, 7);
//     wcout << L"2. TÌM KIẾM THEO TÊN ";
//     gotoXY(x + 50, 9);
//     wcout << L"3. TRỞ VỀ MENU ";
// }
// // khung danh sách sắp xếp //
// void ds_delete(int x)
// {
//     textcolor(2);
//     gotoXY(x + 40, 0);
//     wcout << L"╔═══════════════════════════════════════════════════════╗";
//     gotoXY(x + 40, 1);
//     wcout << L"║";
//     gotoXY(x + 96, 1);
//     wcout << L"║";
//     gotoXY(x + 40, 2);
//     wcout << L"╚═══════════════════════════════════════════════════════╝";
//     gotoXY(x + 40, 3);
//     wcout << L"╔═══════════════════════════════════════════════════════╗";
//     for (int i = 4; i <= 12; i++)
//     {
//         gotoXY(x + 40, i);
//         wcout << L"║";
//         gotoXY(x + 96, i);
//         wcout << L"║";
//     }
//     gotoXY(x + 40, 12);
//     wcout << L"╚═══════════════════════════════════════════════════════╝";
//     gotoXY(x + 55, 1);
//     wcout << L"CÁC CÁCH XOÁ NHÂN VIÊN";

//     gotoXY(x + 50, 5);
//     wcout << L"1. XÓA THEO MÃ SỐ";
//     gotoXY(x + 50, 7);
//     wcout << L"2. XÓA THEO TÊN ";
//     gotoXY(x + 50, 9);
//     wcout << L"3. TRỞ VỀ MENU ";
// }
// void ds_sapxep(int x)
// {
//     textcolor(2);
//     gotoXY(x + 40, 0);
//     wcout << L"╔═══════════════════════════════════════════════════════╗";
//     gotoXY(x + 40, 1);
//     wcout << L"║";
//     gotoXY(x + 96, 1);
//     wcout << L"║";
//     gotoXY(x + 40, 2);
//     wcout << L"╚═══════════════════════════════════════════════════════╝";
//     gotoXY(x + 40, 3);
//     wcout << L"╔═══════════════════════════════════════════════════════╗";
//     for (int i = 4; i <= 12; i++)
//     {
//         gotoXY(x + 40, i);
//         wcout << L"║";
//         gotoXY(x + 96, i);
//         wcout << L"║";
//     }
//     gotoXY(x + 40, 12);
//     wcout << L"╚═══════════════════════════════════════════════════════╝";
//     gotoXY(x + 55, 1);
//     wcout << L"CÁC CÁCH SẮP XẾP NHÂN VIÊN";

//     gotoXY(x + 50, 5);
//     wcout << L"1. Sắp xếp theo lương";
//     gotoXY(x + 50, 7);
//     wcout << L"2. Sắp xếp theo tên ";
//     gotoXY(x + 50, 9);
//     wcout << L"3. Xuất danh sách đã sắp xếp ra màn hình ";
//     gotoXY(x + 50, 11);
//     wcout << L"4. Trở về MENU ";
// }

// //=========================================//

// void khunginkqsearch(int x)
// {
//     SetColor(1);

//     gotoXY(x + 30, 0);
//     wcout << L"╔═════════════════════════════════════════════════╗";
//     for (int i = 1; i <= 18; i++)
//     {
//         gotoXY(x + 30, i);
//         wcout << L"║";
//         gotoXY(x + 80, i);
//         wcout << L"║";
//     }
//     gotoXY(x + 30, 18);
//     wcout << L"╚═════════════════════════════════════════════════╝";
// }
// //=============== *************** ================//

// void khungupdate(int x)
// {
//     SetColor(3);

//     gotoXY(x, 0);
//     wcout << L"╔═════════════════════════════════════════════════╗";
//     for (int i = 1; i <= 20; i++)
//     {
//         gotoXY(x, i);
//         wcout << L"║";
//         gotoXY(x + 50, i);
//         wcout << L"║";
//     }
//     gotoXY(x, 20);
//     wcout << L"╚═════════════════════════════════════════════════╝";
//     gotoXY(x + 5, 2);
//     wcout << L" Chọn thuộc tính bạn muốn sửa : ";
//     gotoXY(x + 5, 4);
//     wcout << L"1. Mã số ";
//     gotoXY(x + 5, 6);
//     wcout << L"2. Họ và tên ";
//     gotoXY(x + 5, 8);
//     wcout << L"3. Ngày Sinh  ";
//     gotoXY(x + 5, 10);
//     wcout << L"4. Địa chỉ ";
//     gotoXY(x + 5, 12);
//     wcout << L"5. Số điện thoại ";
//     gotoXY(x + 5, 14);
//     wcout << L"6. Lương cơ bản ";
// }
// //=============== *************** ================//
// void MENU(list l, MyList *nv)
// {
//     ShowCur(0);
//     wifstream filein;
//     wofstream fileout;
//     int x = 75;
//     int y = 4;
//     int w = 60;
//     int h = 3;
//     int t_color = 11;
//     int b_color = 1;
//     int b_color_sang = 135;
//     int sl = 8;
//     int xp = x;
//     int yp = y;
//     int xcu = xp;
//     int ycu = yp;
//     bool kt = true;

//     string maso;
//     string fullname;
//     bool check;

//     while (true)
//     {
//         clrscr();
//         N_BOX(x, y, w, h, t_color, b_color, sl);
//         check = true;
//         while (check = true)
//         {
//             if (kt == true)
//             {
//                 gotoXY(xcu, ycu);
//                 thanhsang(xcu, ycu, w, h, t_color, b_color);
//                 xcu = xp;
//                 ycu = yp;
//                 thanhsang(xp, yp, w, h, t_color, b_color_sang);
//                 kt = false;
//             }
//             if (kbhit)
//             {
//                 kt = true;
//                 char c = getch();
//                 if (c == 72)
//                 {
//                     if (yp != y)
//                         yp -= 5;
//                     else
//                     {
//                         yp = y + h * (sl + 4) - 1;
//                     }
//                 }
//                 else if (c == 80)
//                 {
//                     if (yp != y + h * (sl + 4) - 1)
//                         yp += 5;
//                     else
//                     {
//                         yp = y;
//                     }
//                 }
//                 else if (c == 13)
//                 {
//                     if (yp == 4)
//                     {
//                         thanhsang(xp, yp, w, h, t_color, 0);
//                         clrscr();
//                         filein.open("NhanVien2.txt", ios::in);
//                         nv->DocDanhSachNhanVien(l, filein);
//                         filein.close();
//                         textcolor(6);
//                         SetColor(5);
//                         wcout << L"\n\n\n\n\n\t\t Đọc file thành công !";
//                         wcout << L"\n\n\n\n\t\t Nhấn phím bất kì để trở lại !";
//                         getch();
//                         break;
//                     }

//                     if (yp == 9)
//                     {
//                         thanhsang(xp, yp, w, h, t_color, 0);
//                         clrscr();
//                         textcolor(6);
//                         SetColor(5);
//                         fileout.open("NHANVIEN_out.txt", ios::out);
//                         nv->XuatDanhSachVaoFile(l, fileout);
//                         wcout << L"\n\n\n\n\n\t\t Xuất file thành công !";
//                         wcout << L"\n\n\n\n\t\t Nhấn phím bất kì để trở lại !";
//                         fileout.close();
//                         getch();
//                         break;
//                     }

//                     if (yp == 14)
//                     {
//                         thanhsang(xp, yp, w, h, t_color, 0);
//                         clrscr();
//                         textcolor(3);
//                         SetColor(3);
//                         nv->XuatDanhSach(l, 15);
//                         getch();
//                         break;
//                     }

//                     if (yp == 19)
//                     {
//                         thanhsang(xp, yp, w, h, t_color, 0);
//                         clrscr();
//                         textcolor(6);
//                         SetColor(5);
//                         while (true)
//                         {
//                             clrscr();
//                             khungds();
//                             int chon;
//                             do
//                             {
//                                 wcin >> chon;
//                             } while (chon < 1 || chon > 5);
//                             NhanVien *x = NULL;
//                             if (chon == 1)
//                             {
//                                 clrscr();
//                                 x = new NhanVienVanPhong();
//                                 x->Nhap();
//                                 nv->ThemVaoCuoi(l, x);
//                                 wcout << L"\n\n\t\t\t\t Nhấn phím bất kì để trở lại !";
//                                 getch();
//                             }
//                             else if (chon == 2)
//                             {
//                                 clrscr();
//                                 x = new NhanVienSanXuat();
//                                 x->Nhap();
//                                 nv->ThemVaoCuoi(l, x);
//                                 wcout << L"\n\n\t\t\t\t Nhấn phím bất kì để trở lại !";
//                                 getch();
//                             }
//                             else if (chon == 3)
//                             {
//                                 clrscr();
//                                 x = new NhanVienMarketing();
//                                 x->Nhap();
//                                 nv->ThemVaoCuoi(l, x);
//                                 wcout << L"\n\n\t\t\t\t Nhấn phím bất kì để trở lại !";
//                                 getch();
//                             }
//                             else if (chon == 4)
//                             {
//                                 clrscr();
//                                 x = new NhanVienKinhDoanh();
//                                 x->Nhap();
//                                 nv->ThemVaoCuoi(l, x);
//                                 wcout << L"\n\n\t\t\t\t Nhấn phím bất kì để trở lại !";
//                                 getch();
//                             }
//                             else
//                             {
//                                 clrscr();
//                                 break;
//                             }
//                         }
//                         break;
//                     }

//                     if (yp == 24)
//                     {
//                         thanhsang(xp, yp, w, h, t_color, 0);
//                         clrscr();
//                         textcolor(6);
//                         SetColor(5);
//                         // clrscr();
//                         // gotoXY(40, 15);
//                         // SetColor(14);
//                         // wcout << L"Nhập ID của nhân viên muốn xóa : ";
//                         // fflush(stdin);
//                         // wstring maso;
//                         // getline(wcin, maso);
//                         // nv->XoaNode(l, maso);
//                         while (true)
//                         {
//                             clrscr();
//                             ds_delete(20);
//                             gotoXY(60, 14);
//                             wcout << L" Nhập lựa chọn của bạn : ";
//                             int type;
//                             NhanVien *x = NULL;
//                             wcin >> type;
//                             if (type == 1)
//                             {
//                                 fflush(stdin);
//                                 wstring maso;
//                                 gotoXY(61, 16);
//                                 wcout << L"Nhập ID của nhân viên cần DELETE : ";
//                                 getline(wcin, maso);
//                                 clrscr();
//                                 int check = 0;
//                                 for (node *k = l.pHead; k != NULL; k = k->pNext)
//                                 {
//                                     if (k->data->getID() == maso)
//                                     {
//                                         ds_delete(0);
//                                         SetColor(12);
//                                         gotoXY(50, 5);
//                                         wcout << L"1. XÓA THEO MÃ SỐ";
//                                         SetColor(7);
//                                         x = k->data;
//                                         check = 1;
//                                         break;
//                                     }
//                                     else
//                                         check = 0;
//                                 }
//                                 if (check == 0)
//                                 {
//                                     gotoXY(50, 15);
//                                     wcout << L"Không tìm thấy nhân viên cần tìm ";
//                                 }
//                                 else
//                                 {
//                                     nv->XoaNodeTheoMa(l, x->getID());
//                                     gotoXY(50, 15);
//                                     wcout << L"Đã DELETE nhân viên cần DELETE ";
//                                 }
//                                 gotoXY(50, 17);
//                                 wcout << L"Nhấn phím bất kì để trở lại !";
//                                 getch();
//                             }
//                             if (type == 2)
//                             {
//                                 wstring fullname;
//                                 gotoXY(61, 16);
//                                 wcout << L"Nhập tên của nhân viên cần tìm : ";
//                                 fflush(stdin);
//                                 getline(wcin, fullname);
//                                 clrscr();
//                                 int check = 0;
//                                 for (node *k = l.pHead; k != NULL; k = k->pNext)
//                                 {
//                                     if (k->data->getName() == fullname)
//                                     {
//                                         ds_delete(0);
//                                         SetColor(12);
//                                         gotoXY(50, 7);
//                                         wcout << L"2. XÓA THEO TÊN ";
//                                         SetColor(7);
//                                         x = k->data;
//                                         check = 1;
//                                         break;
//                                     }
//                                     else
//                                         check == 0;
//                                 }
//                                 if (check == 0)
//                                 {
//                                     gotoXY(50, 15);
//                                     wcout << L"Không tìm thấy nhân viên cần tìm ";
//                                 }
//                                 else
//                                 {
//                                     nv->XoaNodeTheoTen(l, x->getName());
//                                     gotoXY(50, 15);
//                                     wcout << L"Đã DELETE nhân viên cần DELETE ";
//                                 }
//                                 gotoXY(50, 17);
//                                 wcout << L"Nhấn phím bất kì để trở lại !";
//                                 getch();
//                             }
//                             else if (type == 3)
//                             {
//                                 clrscr();
//                                 break;
//                             }
//                         }
//                         break;
//                     }
//                     if (yp == 29)
//                     {
//                         NhanVien *nvv = NULL;
//                         thanhsang(xp, yp, w, h, t_color, 0);
//                         textcolor(6);
//                         SetColor(5);
//                         clrscr();
//                         fflush(stdin);
//                         wstring maso;
//                         gotoXY(20, 10);
//                         SetColor(14);
//                         bool kq = false;
//                         while (kq == false)
//                         {
//                             wcout << L"\n\n\n\n\n\n \t\t\t Nhập ID của nhân viên cần chỉnh sửa : ";
//                             getline(wcin, maso);
//                             clrscr();
//                             wcout << L"\n\n\t\t\t KHÔNG TÌM THẤY ID .... VUI LÒNG NHẬP LẠI !!!";
//                             kq = nv->CheckID(l, maso);
//                         }
//                         SetColor(5);
//                         clrscr();
//                         if (maso[0] == 'V')
//                         {
//                             nvv = new NhanVienVanPhong();
//                         }
//                         else if (maso[0] == 'S')
//                         {
//                             nvv = new NhanVienSanXuat();
//                         }
//                         else if (maso[0] == 'M')
//                         {
//                             nvv = new NhanVienMarketing();
//                         }
//                         else if (maso[0] == 'K')
//                         {
//                             nvv = new NhanVienKinhDoanh();
//                         }
//                         for (node *k = l.pHead; k != NULL; k = k->pNext)
//                         {
//                             if (k->data->getID() == maso)
//                             {
//                                 nvv = k->data;
//                                 break;
//                             }
//                         }
//                         while (true)
//                         {
//                             clrscr();
//                             khungupdate(x);
//                             nvv->Update();
//                             int chon;
//                             do
//                             {
//                                 wcout << L"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tNHẬP LỰA CHỌN CỦA BẠN : ";
//                                 wcin >> chon;
//                             } while (chon < 1 || chon > 8);
//                             nvv->DoUpdate(chon);
//                             if (chon == 8)
//                             {
//                                 clrscr();
//                                 break;
//                             }
//                         }
//                         break;
//                     }

//                     if (yp == 34)
//                     {
//                         thanhsang(xp, yp, w, h, t_color, 0);
//                         clrscr();
//                         textcolor(6);
//                         SetColor(5);
//                         while (true)
//                         {
//                             clrscr();
//                             ds_search(20);
//                             gotoXY(60, 14);
//                             wcout << L" Nhập lựa chọn của bạn : ";
//                             int type;

//                             wcin >> type;
//                             if (type == 1)
//                             {
//                                 fflush(stdin);
//                                 wstring maso;
//                                 gotoXY(61, 16);
//                                 wcout << L"Nhập ID của nhân viên cần tìm : ";
//                                 getline(wcin, maso);
//                                 clrscr();
//                                 int check = 0;
//                                 for (node *k = l.pHead; k != NULL; k = k->pNext)
//                                 {
//                                     if (k->data->getID() == maso)
//                                     {
//                                         ds_search(0);
//                                         SetColor(12);
//                                         gotoXY(50, 5);
//                                         wcout << L"1. Tìm kiếm theo mã số";
//                                         khunginkqsearch(x);
//                                         SetColor(7);
//                                         gotoXY(x + 35, 3);
//                                         wcout << L"Mã số : " << k->data->getID();
//                                         gotoXY(x + 35, 5);
//                                         wcout << L"Họ Tên : " << k->data->getName();
//                                         gotoXY(x + 35, 7);
//                                         wcout << L"Ngày sinh :" << k->data->getNgaySinh();
//                                         gotoXY(x + 35, 9);
//                                         wcout << L"Số điện thoại : " << k->data->getSDT();
//                                         gotoXY(x + 35, 11);
//                                         wcout << L"Địa chỉ : " << k->data->getAddress();
//                                         gotoXY(x + 35, 13);
//                                         wcout << L"Lương cơ bản tháng : " << k->data->getLuongCB();
//                                         gotoXY(x + 35, 15);
//                                         wcout << L"Lương nhận được sau 1 tháng : " << k->data->TinhLuong();
//                                         check = 1;
//                                         break;
//                                     }
//                                     else
//                                         check = 0;
//                                 }
//                                 if (check == 0)
//                                 {
//                                     gotoXY(50, 15);
//                                     wcout << L"Không tìm thấy nhân viên cần tìm ";
//                                 }
//                                 gotoXY(50, 17);
//                                 wcout << L"Nhấn phím bất kì để trở lại !";
//                                 getch();
//                             }
//                             if (type == 2)
//                             {
//                                 wstring fullname;
//                                 gotoXY(61, 16);
//                                 wcout << L"Nhập tên của nhân viên cần tìm : ";
//                                 fflush(stdin);
//                                 getline(wcin, fullname);
//                                 clrscr();
//                                 int check = 0;
//                                 for (node *k = l.pHead; k != NULL; k = k->pNext)
//                                 {
//                                     if (k->data->getName() == fullname)
//                                     {
//                                         ds_search(0);
//                                         SetColor(12);
//                                         gotoXY(50, 7);
//                                         wcout << L"2. Tìm kiếm theo tên ";
//                                         khunginkqsearch(x);
//                                         SetColor(7);
//                                         gotoXY(x + 35, 3);
//                                         wcout << L"Họ Tên : " << k->data->getName();
//                                         gotoXY(x + 35, 5);
//                                         wcout << L"Mã số : " << k->data->getID();
//                                         gotoXY(x + 35, 7);
//                                         wcout << L"Ngày sinh :" << k->data->getNgaySinh();
//                                         gotoXY(x + 35, 9);
//                                         wcout << L"Số điện thoại : " << k->data->getSDT();
//                                         gotoXY(x + 35, 11);
//                                         wcout << L"Địa chỉ : " << k->data->getAddress();
//                                         gotoXY(x + 35, 13);
//                                         wcout << L"Lương cơ bản tháng : " << k->data->getLuongCB();
//                                         gotoXY(x + 35, 15);
//                                         wcout << L"Lương nhận được sau 1 tháng : " << k->data->TinhLuong();
//                                         check = 1;
//                                         break;
//                                     }
//                                     else
//                                         check == 0;
//                                 }
//                                 if (check == 0)
//                                 {
//                                     gotoXY(50, 15);
//                                     wcout << L"Không tìm thấy nhân viên cần tìm ";
//                                 }
//                                 gotoXY(50, 17);
//                                 wcout << L"Nhấn phím bất kì để trở lại !";
//                                 getch();
//                             }
//                             else if (type == 3)
//                             {
//                                 clrscr();
//                                 break;
//                             }
//                         }
//                         break;
//                     }

//                     if (yp == 39)
//                     {
//                         thanhsang(xp, yp, w, h, t_color, 0);
//                         clrscr();
//                         textcolor(6);
//                         SetColor(5);
//                         int chon;
//                         // list danhsach;
//                         // MyList *nv1 = new MyList();
//                         // nv1->KhoiTao(danhsach);
//                         // filein.open("NhanVien2.txt", ios::in);
//                         // nv1->DocDanhSachNhanVien(danhsach, filein);
//                         // filein.close();
//                         // getch();
//                         while (true)
//                         {
//                             thanhsang(xp, yp, w, h, t_color, 0);
//                             clrscr();
//                             textcolor(6);
//                             SetColor(5);
//                             clrscr();
//                             ds_sapxep(20);
//                             gotoXY(60, 14);
//                             wcout << L" Nhập lựa chọn của bạn : ";
//                             wcin >> chon;
//                             if (chon == 1)
//                             {
//                                 thanhsang(xp, yp, w, h, t_color, 0);
//                                 clrscr();
//                                 textcolor(6);
//                                 SetColor(5);
//                                 clrscr();
//                                 gotoXY(70, 15);
//                                 wcout << L"Đã sắp xếp nhân viên theo thứ tự tăng dần !";
//                                 for (node *k = l.pHead; k != l.pTail; k = k->pNext)
//                                 {
//                                     for (node *h = k->pNext; h != NULL; h = h->pNext)
//                                     {
//                                         if (k->data->TinhLuong() > h->data->TinhLuong())
//                                         {
//                                             swap(k->data, h->data);
//                                         }
//                                     }
//                                 }
//                                 gotoXY(70, 19);
//                                 wcout << L"Nhấn phím bất kì để trở lại !";
//                                 getch();
//                             }
//                             if (chon == 2)
//                             {
//                                 thanhsang(xp, yp, w, h, t_color, 0);
//                                 clrscr();
//                                 textcolor(6);
//                                 SetColor(5);
//                                 clrscr();
//                                 gotoXY(70, 15);
//                                 wcout << L"Đã sắp xếp nhân viên theo thứ tự tăng dần !";
//                                 for (node *k = l.pHead; k != l.pTail; k = k->pNext)
//                                 {
//                                     for (node *h = k->pNext; h != NULL; h = h->pNext)
//                                     {
//                                         if ((k->data->getName()) > (h->data->getName()))
//                                         {
//                                             swap(k->data, h->data);
//                                         }
//                                     }
//                                 }
//                                 gotoXY(70, 19);
//                                 wcout << L"Nhấn phím bất kì để trở lại !";
//                                 getch();
//                             }
//                             // else if (chon == 3)
//                             // {
//                             //     thanhsang(xp, yp, w, h, t_color, 0);
//                             //     clrscr();
//                             //     textcolor(6);
//                             //     SetColor(11);
//                             //     clrscr();
//                             //     nv->XuatDanhSach(danhsach, 15);
//                             //     getch();
//                             // }
//                             else if (chon == 3)
//                             {
//                                 clrscr();
//                                 break;
//                             }
//                         }
//                         break;
//                     }
//                 }
//             }
//         }
//         check = false;
//         textcolor(1);
//     }
//     getch();
// }

// int main()
// {
//     _setmode(_fileno(stdout), _O_WTEXT); // needed for output
//     _setmode(_fileno(stdin), _O_WTEXT);  // needed for input
//     locale loc(locale(), new codecvt_utf8<wchar_t>);
//     list l;
//     MyList *nv = new MyList();
//     nv->KhoiTao(l);
//     MENU(l, nv);
//     return 0;
// }