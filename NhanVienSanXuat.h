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
    void XuatBangLuong();
    void XuatBangLuongVaoFile(wofstream &);
	void Xuatfile(wofstream &);
    void Update();
    void DoUpdate(int);
    void UpdateLuong();
    void DoUpdateLuong(int);
    void setSSP(int);
	long TinhLuong();
};