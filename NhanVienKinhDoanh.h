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
	void Xuatfile(wofstream &);
    void setSHD (int);
    void Update();
    void DoUpdate(int);
	long TinhLuong();
    void DoUpdateID();
    bool checkID(wstring);
};