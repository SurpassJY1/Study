#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
template<class T>
class Queue;

template<class T>
class Node
{
	friend class Queue<T>;
	T value;
	Node* next;
public:
	Node(T val)
	{
		this->value = val;
		next = nullptr;
	}
};
template<class T>
class Queue
{
	Node<T>* qTop;
	Node<T>* qRear;
	int size;
public:
	Queue() :size(0), qTop(nullptr), qRear(nullptr) {}
	~Queue()
	{
		for (size_t i = 0; i < size; i++)
		{
			pop();
		}
	}
	int getSize()
	{
		return size;
	}
	bool isEmpty()
	{
		return size == 0;
	}
	void push(T val)
	{
		Node<T>* newNode = new Node<T>(val);
		if (size == 0)
		{
			qTop = newNode;
			qRear = newNode;
			size++;
		}
		else
		{
			qRear->next = newNode;
			qRear = newNode;
			size++;
		}
	}
	T pop()
	{
		if (size == 0)
		{
			throw std::runtime_error("The queue is empty");
		}
		//construct Node with template
		Node<T>* temp = qTop;
		qTop = qTop->next;
		T val = temp->value;
		//free the memory
		delete temp;
		size--;
		return val;
	}
	T peek()
	{
		if (size == 0)
		{
			throw runtime_error("The queue is empty");
		}
		T val = qTop->value;
		return val;
	}
	vector<T> toVec()
	{
		vector<T> res;
		res.resize(size);
		int size = this->size;
		Node<T>* node = qTop;
		for (size_t i = 0; i < size; i++)
		{
			res[i] = node->value;
			node = node->next;
		}
		return res;
	}
};
template<class T>
class MyPrint
{
public:
	void operator()(T val)
	{
		cout << val << " ";
	}
};

template<class T>
class ArrayQueue
{
	T* nums;
	int front;
	int size;
	int capacity;
public:
	int getSize()
	{
		return size;
	}
	int getCapacity()
	{
		return capacity;
	}
	ArrayQueue(int capacity) :front(0), size(0), capacity(capacity)
	{
		nums = new T(capacity);
	}
	void push(T val)
	{
		//evaluate the size and capacity
		if (size == capacity)
		{
			throw runtime_error("Size beyonds capacity");
		}
		//get the poistion of rear
		//if index of rear is greater than the size of array, move it to the head
		int rear = (front + size) % capacity;
		nums[rear] = val;
		size++;
	}
	T pop()
	{
		if (size == 0)
		{
			throw runtime_error("The queue is empty");
		}
		T temp = nums[front];
		//move the front to next position,if the front is the end of nums, move it to nums[0]
		front = (front + 1) % capacity;
		//refresh size
		size--;
		return temp;
	}
	vector<T> toVec()
	{
		vector<T> res;
		res.resize(size);
		for (size_t i = 0; i < size; i++)
		{
			res[i] = nums[i];
		}
		return res;
	}
	~ArrayQueue() 
	{
		delete[] nums;
	}
};
int main() {
	/*Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.getSize() << endl;
	cout << q.pop() << endl;
	cout << q.getSize() << endl;
	cout << endl;
	cout << q.peek() << endl;
	cout << q.getSize() << endl;
	cout << endl;
	vector<int> res = q.toVec();
	for_each(res.begin(), res.end(), MyPrint<int>());
	*/
	ArrayQueue<int> que(6);
	cout << "Size: " << que.getSize() << endl;
	cout << "Capacity: " << que.getCapacity() << endl;
	cout << endl;
	for (size_t i = 0; i < 6; i++)
	{
		que.push(i);
	}
	cout << "Size: " << que.getSize() << endl;
	vector<int> res = que.toVec();
	cout << endl;
	for (size_t i = 0; i < 6; i++)
	{
		cout <<"Element: " << que.pop()<<" Size:"<<que.getSize() << endl;
	}
	return 0;
}