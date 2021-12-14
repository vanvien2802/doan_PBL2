#pragma once

#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <fstream> // làm việc với file
#include <locale>
// #include <Windows.h>
#include <codecvt>
#include <conio.h>

using namespace std;


class NhanVien
{
protected:
    long LuongCoBan;
	wstring ID;
	wstring Name, Address, NgaySinh, SoDienThoai;
	wstring ChiNhanh;
public:
    virtual void Nhap();
	virtual void DocFile(wifstream &);
	virtual void Xuatfile(wofstream &,int);
	virtual long TinhLuong() = 0;
	virtual void Update();
	virtual void DoUpdate(int);
	virtual void DoUpdateID() = 0;
	virtual bool checkID(wstring) = 0;

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
	wstring getChiNhanh();
	void setChiNhanh(wstring ChiNhanh);
};