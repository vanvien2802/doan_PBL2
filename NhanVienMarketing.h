#include "NhanVien.h"
#pragma once

class NhanVienMarketing : public NhanVien
{
private:
    float HeSoKPI;
public:
    // NhanVienMarketing();
    // ~NhanVienMarketing();
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
    void setHeSoKPI(float);
	long TinhLuong();
};