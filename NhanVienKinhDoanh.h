#include "NhanVien.h"
#pragma once
class NhanVienKinhDoanh : public NhanVien
{
private:
    int SoHopDong;
public:
    void Nhap();
	void DocFile(wifstream &);
	void Xuatfile(wofstream &,int);
    void setSHD (int);
    void Update();
    void DoUpdate(int);
	long TinhLuong();
    void DoUpdateID();
    bool checkID(wstring);
};