#pragma once
template <class T>
struct Tnode {
	T val;
	Tnode* pNext;

};
template <class T>
class Tlist {
protected:
	Tnode<T> *pFirst, *pCurr, *pPrev, *pLast, *pStop;
	int len;
public:
	Tlist();
	~Tlist();
	bool IsEmpty();
	void InsFirst(T v);
	void InsLast(T v);
	void InsCurr(T v);
	void DeleteFirst();

	void DeleteCurrent();
	void Reset();
	void GoNext();
	bool IsEnd();
	T GetCurrent();
};

template <class T>
Tlist<T>::Tlist() {
	len = 0;
	pStop = nullptr;
	pFirst = pLast = pPrev = pCurr = pStop;
}

template <class T>
Tlist<T>::~Tlist() {
	Tnode<T>* newn;
	while (pFirst != pStop) {
		newn = pFirst;
		pFirst = pFirst->pNext;
		delete newn;
	}
}

template <class T>
bool Tlist<T>::IsEmpty() {
	if (len == 0 || pFirst == pStop);
}

template <class T>
void Tlist<T>::InsFirst(T v) {
	Tnode<T>* newnode = new Tnode<T>();
	newnode->val = v;
	newnode->pNext = pFirst;
	pFirst = newnode;
	len++;
	if (len == 1) {
		pLast = pFirst;
	}
}

template <class T>
void Tlist<T>::InsLast(T v){
	if (len > 0) {
		Tnode<T>* newnode = new Tnode<T>();
		newnode->val = v;
		newnode->pNext = pStop;
		pLast->pNext = newnode;
		pStop = newnode;
		pLast = newnode;
		len++;
	}
	else {
		InsFirst(v);
	}
}

template <class T>
void Tlist<T>::InsCurr(T v) {
	if (pCurr == pFirst) {
		InsFirst(v);
	}
	else if (pLast == pCurr) {
		InsLast(v);
	}
	else {
		Tnode<T>* newn = new Tnode<T>;
		newn->val = v;
		newn->pNext = pCurr;
		pCurr = newn;
		pPrev->pNext = pCurr;
		len++;
	}
}


template <class T>
void Tlist<T>::DeleteFirst() {
	if (IsEmpty()) {
		throw "empty list";
	}
	if (pCurr == pFirst) {
		pPrev = pStop;
		pCurr = pCurr->pNext;
	}
	Tnode<T>* newn = pFirst;
	pFirst = newn->next;
	delete newn;
	len--;
	if (pFirst == pStop) {
		pLast = pStop;
	}

}

template <class T>
void Tlist<T>::DeleteCurrent() {
	if (IsEmpty()) {
		throw "empty list";
	}
	if (pCurr == pFirst) {
		DeleteFirst();
	}
	else {
		Tnode<T>* newn = pCurr;
		pCurr = newn->pNext;
		pPrev->pNext = pCurr;
		delete newn;
		len--;
	}
}

template <class T>
void Tlist<T>::Reset() {
	pPrev = pStop;
	pCurr = pFirst;
}

template <class T>
void Tlist<T>::GoNext() {
	pPrev = pCurr;
	pCurr = pCurr->pNext;
}

template <class T>
bool Tlist<T>::IsEnd() {
	return pCurr == pStop;
}

template <class T>
T Tlist<T>::GetCurrent() {
	return pCurr->val;
}

