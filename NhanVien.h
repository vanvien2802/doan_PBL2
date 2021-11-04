#pragma once

#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <fstream>
#include <locale>
#include <Windows.h>
#include <codecvt>
#include <conio.h>

using namespace std;


class NhanVien
{
protected:
    long LuongCoBan;
	wstring ID;
	wstring Name, Address, NgaySinh, SoDienThoai;
public:
    // NhanVien(long,long, string, string, string,string,string);
    // ~NhanVien();
    virtual void Nhap();
	virtual void DocFile(wifstream &);
	virtual void Xuat();
	virtual void Xuatfile(wofstream &);
	virtual long TinhLuong() = 0;
	virtual void Update();
	virtual void DoUpdate(int);

	void setID(wstring);
	wstring getID();
	void setName(wstring);
	wstring getName();
	void setAddress (wstring);
	wstring getAddress();
    void setNgaySinh (wstring);
	wstring getNgaySinh();
    void setSDT (wstring);
	wstring getSDT();
    void setLuongCB(long);
	long getLuongCB();
};