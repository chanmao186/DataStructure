#include<iostream>

#define MAX 10000
#define MIN -10000
template<class Type>
class Heap
{
public:
	Heap(int capacity) {
		this->size = 0;
		this->capacity = capacity;
		Date = new Type[capacity];
	}
	virtual bool Insert(Type Element);
	virtual Type Delete();
	bool IsFull() {
		return size == capacity;
	}
	bool IsEmputy() {
		return size == 0;
	}
protected:
	int size;
	int capacity;
	Type* Date;
};
template<class Type>
class MinHeap:public Heap<Type>
{
public:
	MinHeap(int capacity) : Heap(capacity) {
		Date[0] = MIN;
	}
	override bool Insert(Type Element) {
		if (IsFull)return;
		int i = ++size;
		for (; Date[i] < Date[i/2]; i /= 2) {
			Date[i / 2] = Date[i];
		}
		Date[i] = Element;
	}
	override Type Delete() {
		if (IsEmputy)return error;
	}
};
