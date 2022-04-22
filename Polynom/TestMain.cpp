#include <iostream>
using namespace std;
#include "HeadList.h"
#include "list.h"

int main() {
	Tlist<int> list;
	int num, size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> num;
		list.InsLast(num);
	}
	//cout << list.GetCurr();
	for (list.Reset(); !list.IsEnd(); list.GoNext()) {
		cout << list.GetCurrent() << " ";
	}
	return 0;
}