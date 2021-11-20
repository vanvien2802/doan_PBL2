// while (check == 0)
// {
//     clrscr();
//     ds_delete(20);
//     gotoXY(60, 14);
//     wcout << L" Lựa chọn của bạn : " << type << endl;
//     if (type == 2)
//     {
//         wstring fullname;
//         gotoXY(61, 16);
//         wcout << L"Nhập tên của nhân viên cần tìm : ";
//         fflush(stdin);
//         getline(wcin, fullname);
//         clrscr();
//         int check = 0;
//         for (node *k = l.pHead; k != NULL; k = k->pNext)
//         {
//             if (k->data->getName() == fullname)
//             {
//                 ds_delete(0);
//                 SetColor(12);
//                 gotoXY(50, 7);
//                 wcout << L"2. XÓA THEO TÊN ";
//                 SetColor(7);
//                 x = k->data;
//                 check = 1;
//                 break;
//             }
//             else
//                 check == 0;
//         }
//         if (check == 0)
//         {
//             gotoXY(50, 15);
//             wcout << L"Không tìm thấy nhân viên cần tìm ";
//         }
//         else
//         {
//             nv->XoaNodeTheoTen(l, x->getName());
//             gotoXY(50, 15);
//             wcout << L"Đã DELETE nhân viên cần DELETE ";
//         }
//         gotoXY(50, 17);
//         wcout << L"Nhấn phím bất kì để trở lại !";
//         getch();
//     }
// }