#include "NhanVien.h"
#pragma once

class NhanVienVanPhong : public NhanVien
{
private:
    int DayWorking;
public:
    // NhanVienVanPhong();
    // ~NhanVienVanPhong();
    void Nhap();
	void DocFile(wifstream &);
	void Xuat();
	void Xuatfile(wofstream &);
    void Update();
    void DoUpdate(int);
    void setDW(int );
	long TinhLuong();
    void DoUpdateID();
    bool checkID(wstring);
};
