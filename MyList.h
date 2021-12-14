#pragma once
#include "NhanVienVanPhong.h"
#include "NhanVienSanXuat.h"
#include "NhanVienMarketing.h"
#include "NhanVienKinhDoanh.h"
#include <locale>
// #include <Windows.h>
#include <codecvt>
#include <iomanip>

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
	void KhoiTao(list&);
	void DocDanhSachNhanVien(list &,wifstream &);
	node *KhoitaoNode(NhanVien *);
	void ThemVaoCuoi(list &, NhanVien *);
	void XoaNodeTheoMaSo (list &,wstring);
	void XoaNodeTheoTen (list &,wstring);
	void XuatDanhSach(list ,int);
	void XuatDanhSachVaoFile(list&, wofstream &);
	void XuatDanhSachVaoFileX(list&, wofstream &);
	bool CheckID(list&,wstring);
	void UpdateID(list&,NhanVien *);
};