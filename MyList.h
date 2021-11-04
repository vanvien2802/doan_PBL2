#pragma once
#include "NhanVienVanPhong.h"
#include "NhanVienSanXuat.h"
#include "NhanVienMarketing.h"
#include "NhanVienKinhDoanh.h"
#include <locale>
#include <Windows.h>
#include <codecvt>


#include <fcntl.h>
#include <io.h>

struct node
{
	NhanVien *data;
	node *pNext;
	node *pPre;
};
struct list
{
	node *pHead;
	node *pTail;
};
class MyList
{
public:
	/*enum TypeNV
	{
		VP = 0,
		SX = 1,
		MKT = 2,
		KD = 3
	};*/

	void KhoiTao(list&);
	void DocDanhSachNhanVien(list &,wifstream &);
	node *KhoitaoNode(NhanVien *);
	void ThemVaoCuoi(list &, NhanVien *);
	void XoaNode (list &,wstring);
	void XuatDanhSach(list ,int);
	void XuatDanhSachVaoFile(list&, wofstream &);

	void gotoXY(int , int );
};