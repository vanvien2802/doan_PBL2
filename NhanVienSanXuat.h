#include "NhanVien.h"
#pragma once

class NhanVienSanXuat : public NhanVien
{
private:
    int SoSanPham;
public:
    void Nhap();
	void DocFile(wifstream &);
	void Xuatfile(wofstream &,int);
    void Update();
    void DoUpdate(int);
    void setSSP(int);
	long TinhLuong();
    void DoUpdateID();
    bool checkID(wstring);
};