#include "NhanVien.h"
#pragma once

class NhanVienSanXuat : public NhanVien
{
private:
    int SoSanPham;
public:
    // NhanVienSanXuat();
    // ~NhanVienSanXuat();
    void Nhap();
	void DocFile(wifstream &);
	void Xuat();
	void Xuatfile(wofstream &);
    void Update();
    void DoUpdate(int);
    void setSSP(int);
	long TinhLuong();
};
