#pragma once
#include "HeadList.h"
#include <ostream>
using namespace std;

struct Monom {
	double k;
	int x, y, z;

	Monom(double _k=0, int _x=0, int _y=0, int _z=0) {
		k = _k;
		x = _x;
		y = _y;
		z = _z;
	}

	bool operator==(const Monom& m) {
		if (k == m.k && x == m.x && y == m.y && z == m.z) {
			return true;
		}
		return false;
	}
	bool operator<(const Monom& m) {
		if (x == m.x && y == m.y && z == m.z) {
			if (k < m.k) {
				return true;
			}
		}
		if ((x < m.x) || (x == m.x && y < m.y) || (x == m.x && y == m.y && z < m.z)) {
			return true;
		}

		return false;
	}
	bool operator!=(const Monom& m) {
		return !(operator==(m));
	}
	bool operator>(const Monom& m) {
		return !(operator<(m));
	}
	bool isConst() const {
		return x == 0 && y == 0 && z == 0;
	}
	Monom operator*(const Monom b) {
		Monom tmp;
		tmp.k = k * b.k;
		tmp.x = x + b.x;
		tmp.y = y + b.y;
		tmp.z = z + b.z;
		return tmp;
	}
	friend ostream& operator<<(ostream& os, Monom& m)
	{
		if (m.x != 0)
		{
			os << "x";
			if (m.x != 1)
				os << m.x;
		}
		if (m.y != 0)
		{
			os << "y";
			if (m.y != 1)
				os << m.y;
		}
		if (m.z != 0)
		{
			os << "z";
			if (m.z != 1)
				os << m.z;
		}
		return os;
	}
};

class Polynom :public THeadList<Monom> {
	Polynom();
	Polynom(Polynom& p);

	Polynom& operator=(Polynom& p);
	Polynom& operator+(Polynom& p);
	Polynom& operator-(Polynom& p);
	Polynom& operator*(Polynom& p);
	Polynom& operator*(Monom& m);
	Polynom& operator*(int a);

	bool operator==(Polynom& p);
	bool operator!=(Polynom& p);

	void AddMonom(Monom m);


};

Polynom::Polynom() {
	Monom m(0,0,-1);
	pHead->val = m;
}
Polynom::Polynom(Polynom& p) {
	Monom m(0, 0, -1);
	pHead->val = m;
	for (p.Reset(); !p.IsEnd(); p.GoNext()) {
		InsLast(p.GetCurrent());
	}
}
Polynom& Polynom::operator=(Polynom& p) {
	
}

Polynom& Polynom::operator+(Polynom& p) {

}

Polynom& Polynom::operator-(Polynom& p) {

}

Polynom& Polynom::operator*(Polynom& p) {

}

Polynom& Polynom::operator*(Monom& m) {

}

Polynom& Polynom::operator*(int a) {

}

bool Polynom::operator==(Polynom& p) {
	Polynom tmp = Polynom(p);
	tmp.Reset();
	Reset();
	while (!IsEnd()) {
		if (pCurr->val == tmp.pCurr->val && pCurr->val.k == tmp.pCurr->val.k) {
			tmp.GoNext();
			GoNext();
		}
		else {
			return false;
		}
	}
	return true;
}

bool Polynom::operator!=(Polynom& p) {
	return !operator==(p);
}
