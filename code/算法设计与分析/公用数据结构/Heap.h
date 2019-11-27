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
		Htype = true;
		Date[0] = MIN;
	}
	bool Insert(Type Element) {
		if (IsFull())return false;
		int i = ++size;
		for (; (Element < Date[i / 2]) == Htype; i /= 2) {
			Date[i / 2] = Date[i];
		}
		Date[i] = Element;
	}
	Type Delete() {
		//if (IsEmputy())return NULL;
		int parent = 1, child;
		Type temp = Date[size--],
			Item = Date[1];
		for (; parent * 2 < size; parent = child) {
			child = parent * 2;
			//两个子节点中选择一个合适的
			if ((Date[child] > Date[child + 1]) == Htype) {
				child++;
			}
			if (temp < Date[child] == Htype) {
				//若找到合适的位置，跳出循环
				break;
			}
			else {
				Date[parent] = Date[child];
			}
		}
		Date[parent] = temp;
		return Item;
	}
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
	//堆得属性，默认为小顶堆
	bool Htype;
};

template<class Type>
class MinHeap :public Heap<Type>
{
public:
	MinHeap(int capacity) : Heap<Type>(capacity) {
		this->Date[0] = MIN;
		this->Htype = true;
	}
protected:
};

template<class Type>
class MaxHeap :public Heap<Type>
{
public:
	MaxHeap(int capacity) : Heap<Type>(capacity) {
		this->Date[0] = MAX;
		this->Htype = false;
	}
};
