#pragma once
#include "list.h"

template <class T>
class THeadList:public Tlist<T> {
protected:
	Tnode<T>* pHead;
public:
	THeadList() {
		pHead = new Tnode<T>;
		pHead->pNext = pHead;
		pFirst = pLast = pCurr = pPrev = pStop = pHead;
		len = 0;
	}
	~THeadList() {
		Tlist::~Tlist();
		delete pHead;

	}
	void InsFirst(T v) {
		Tlist::InsFirst(v);
		pHead->pNext = pFirst;
	}
	void DeleteFirst() {
		Tlist::DeleteFirst();
		pHead->pNext = pFirst;
	}

};