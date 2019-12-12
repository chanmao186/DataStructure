#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Ĭ��Ϊ����,���������������<
template<class Type>
class HeapX {	
public:
	HeapX() {
		make_heap(data.begin(), data.end());
	}
	bool Empty() {
		return data.empty();
	}
	Type Delete() {
		Type temp = data[0];
		pop_heap(data.begin(), data.end());
		data.pop_back();
		return temp;
	}
	void Insert(Type X) {
		data.push_back(X);
		push_heap(data.begin(), data.end());
	}
protected:
	vector<Type> data;
};