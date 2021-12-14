#pragma once
#include "MyList.h"
struct list2
{
	node *pHead;
	node *pTail;
};
class ChiNhanh
{
private:
    NhanVien *x;
    MyList l2;
public:
    void Khoitao(list2&);
    node* KhoiTaoNode (NhanVien*);
    void ThemVaocuoi(list2&,NhanVien *);
    void AddNhanVien(list&,list2 &);
    void XuatTheoChiNhanh(list2&,wstring);
    
};

