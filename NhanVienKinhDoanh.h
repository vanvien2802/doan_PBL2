#include "NhanVien.h"
#pragma once
class NhanVienKinhDoanh : public NhanVien
{
private:
    int SoHopDong;
public:
    // NhanVienKinhDoanh();
    // ~NhanVienKinhDoanh();
    void Nhap();
	void DocFile(wifstream &);
	void Xuat();
    void XuatBangLuong();
    void XuatBangLuongVaoFile(wofstream &);
	void Xuatfile(wofstream &);
    void setSHD (int);
    void Update();
    void DoUpdate(int);
    void UpdateLuong();
    void DoUpdateLuong(int);
	long TinhLuong();
};