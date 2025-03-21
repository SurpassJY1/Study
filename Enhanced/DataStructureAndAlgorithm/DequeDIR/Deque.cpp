#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<class T>
class Deque;
template<class T>
class Node
{
	friend class Deque<T>;
	T data;
	Node* prev;
	Node* next;
public:
	Node(T value) :data(value), prev(nullptr), next(nullptr) {}
};
template<class T>
class Deque
{
	Node<T>* rear;
	Node<T>* front;
	int size;
public:
	Deque() :rear(nullptr), front(nullptr), size(0) {}
	~Deque() {
		if (front==nullptr&&rear==nullptr)
		{
			return;
		}
		Node<T>* pre, * cur = front;
		while(cur!=nullptr)
		{
			pre = cur;
			cur = cur->next;
			delete pre;
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
	void push(T val, bool isFront)
	{
		Node<T>* node = new Node<T>(val);
		if (isEmpty())
		{
			rear = front = node;
		}
		else if (isFront)
		{
			//refresh two pointers
			front->prev = node;
			node->next = front;
			front = node;
		}
		else
		{
			rear->next = node;
			node->prev = rear;
			rear = node;
		}
		size++;
	}
	void push_front(T val) 
	{
		push(val,true);
	}
	void push_back(T val) 
	{
		push(val, false);
	}
	T pop(bool isFront) 
	{
		if (size==0)
		{
			throw out_of_range("The queue is empty");
		}
		T val;
		if (isFront)
		{
			val = front->data;
			//refresh the two pointers and free the memory
			Node<T>* fNext = front->next;
			//judge if the deque only has one element to avoid null pointer exception
			if (fNext!=nullptr)
			{
				fNext->prev = nullptr;
				front->next = nullptr;
			}
			//free front
			delete front;
			front = fNext;
			return val;
		}
		else 
		{
			val = rear->data;
			Node<T>* rPrev = rear->prev;
			//judge if the deque only has one element to avoid null pointer exception
			if (rPrev!=nullptr)
			{
				rPrev->next = nullptr;
				rear->prev = nullptr;
			}
			delete rear;
			rear = rPrev;
			return val;
		}
		size--;
	}
	T pop_back() 
	{
		return pop(false);
	}
	T pop_front() 
	{
		return pop(true);
	}
	T peek_first() 
	{
		if (size==0) 
		{
			throw out_of_range("Deque is empty");
		}
		T val = front->data;
		return val;
	}
	T peek_last()
	{
		if (size == 0)
		{
			throw out_of_range("Deque is empty");
		}
		T val = rear->data;
		return val;
	}
	vector<T> toVec() 
	{
		if (isEmpty())
		{
			throw out_of_range("The deque is empty");
		}
		vector<T> vec;
		vec.resize(size);
		Node<T>* node = front;
		for (size_t i = 0; i < size; i++)
		{
			vec[i] = node->data;
			node = node->next;
		}
		return vec;
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
class ArrayDeque 
{
	vector<T> vec;
	int size;
	int front;
	int capacity;
public:
	ArrayDeque(int cap):capacity(cap),size(0),front(0)
	{
		vec.resize(capacity);
	}
	int getSize() 
	{
		return size;
	}
	int getCapacity() 
	{
		return capacity;
	}
	bool isEmpty() 
	{
		return size == 0;
	}
	void push_back(T val)
	{
		if (size >=capacity)
		{
			throw out_of_range("The Deque is full");
		}
		//calculate the index
		int rear = (front+size) % capacity;
		vec[rear] = val;
		size++;
	}
	void push_front(T val) 
	{
		if (size >= capacity)
		{
			throw out_of_range("The Deque is full");
		}
		//calculate the front index
		front = (front - 1 + capacity) % capacity;
		vec[front] = val;
		size++;
	}
	T pop_back()
	{
		T removed = vec[(front + size - 1)%capacity];
		size--;
		return removed;
	}
	T pop_front() 
	{
		T removed = vec[front];
		//calculate the new front index
		front = (front + 1) % capacity;
		size--;
		return removed;
	}
	T peek_front() 
	{
		if (isEmpty()) 
		{
			throw out_of_range("The deque is empty");
		}
		return vec[front];
	}
	T peek_back() 
	{
		if (isEmpty())
		{
			throw out_of_range("The deque is empty");
		}
		return vec[(front+size-1)%capacity];
	}
};
int main()
{
	/*Deque<int> deque;
	for (size_t i = 0; i < 5; i++)
	{
		deque.push_back(i);
	}
	for (size_t i = 0; i < 6; i++)
	{
		deque.push_front(i);
	}
	for (size_t i = 0; i < deque.getSize(); i++)
	{
		cout << deque.pop_front() << endl;
	}*/
	//vector<int> vec = deque.toVec();
	//for_each(vec.begin(),vec.end(),MyPrint<int>());
	ArrayDeque<int> deq(6);
	deq.push_back(3);
	deq.push_back(2);
	deq.push_back(1);
	deq.push_front(1);
	deq.push_front(2);
	deq.push_front(3);
	int size = deq.getSize();
	cout << size << endl;
	cout << deq.peek_back() << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << deq.pop_back() << endl;
	}
	return 0;
}