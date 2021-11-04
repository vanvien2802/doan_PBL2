#include "NhanVien.h"
#pragma once
class NhanVienKinhDoanh : public NhanVien
{
private:
    float HeSoLuong;
public:
    // NhanVienKinhDoanh();
    // ~NhanVienKinhDoanh();
    void Nhap();
	void DocFile(wifstream &);
	void Xuat();
	void Xuatfile(wofstream &);
    void setHSL (float);
    void Update();
    void DoUpdate(int);
	long TinhLuong();
};
