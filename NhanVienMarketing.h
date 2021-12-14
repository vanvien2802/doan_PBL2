#include "NhanVien.h"
#pragma once

class NhanVienMarketing : public NhanVien
{
private:
    float HeSoKPI;
public:
    void Nhap();
	void DocFile(wifstream &);
	void Xuatfile(wofstream &,int);
    void Update();
    void DoUpdate(int);
    void setHeSoKPI(float);
	long TinhLuong();
    void DoUpdateID();
    bool checkID(wstring);
};