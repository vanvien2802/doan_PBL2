#pragma once
#include "MyList.h"
// struct node
// {
// 	NhanVien *data;
// 	node *pNext;
// 	node *pPre;
// };
struct list2 // chứa ds Nhân Viên thuộc chi Nhánh Đà Nẵng
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
    // ChiNhanh(/* args */);
    // ~ChiNhanh();
    void Khoitao(list2&);
    node* KhoiTaoNode (NhanVien*);
    void ThemVaocuoi(list2&,NhanVien *);
    void XuatNhanVien(list2); 
    void AddNhanVien(list&,list2 &);
    void XuatTheoChiNhanh(list2&,wstring);
    
};

