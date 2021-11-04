#include "NhanVien.h"
#pragma once

class NhanVienMarketing : public NhanVien
{
private:
    long LuongBonus;
public:
    // NhanVienMarketing();
    // ~NhanVienMarketing();
    void Nhap();
	void DocFile(wifstream &);
	void Xuat();
	void Xuatfile(wofstream &);
    void Update();
    void DoUpdate(int);
    void setLuongBonus(long);
	long TinhLuong();
};
