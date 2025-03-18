#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<class T>
class Stack;
template<class T>
class Node 
{
	friend Stack<T>;
	T value;
	Node* next;
public:
	Node(T value) 
	{
		this->value = value;
		next = nullptr;
	}
};
template<class T>
class Stack 
{
	Node<T>* sTop;
	int size;
public:
	Stack()
	{
		size = 0;
		sTop = nullptr;
	}
	~Stack() 
	{
		int size = getSize();
		for (size_t i = 0; i < size; i++)
		{
			pop();
		}
	}
	int getSize() 
	{
		return size;
	}
	bool empty() 
	{
		return size == 0;
	}
	T peek()
	{
		if (empty())
		{
			throw std::runtime_error("Stack is empty");
		}
		return sTop->value;
	}
	void push(T value) 
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = sTop;
		sTop = newNode;
		size++;
	}
	T pop() 
	{
		T val = peek();
		Node<T>* removed = sTop;
		sTop = sTop->next;
		//free the memory
		delete removed;
		size--;
		return val;
	}
	vector<T> toVector() 
	{
		vector<T> res;
		Node<T>* node = sTop;
		res.resize(size);
		int size = this->size;
		for (int i=size-1;i>=0;i--)
		{
			res[i] = node->value;
			node = node->next;
		}
		return res;
	}
};
//create stack through dynamic array
template<class T>
class VectorStack 
{
	vector<T> vec;
public:
	bool isEmpty() 
	{
		return vec.size() == 0;
	}
	int getSize() 
	{
		return vec.size();
	}
	void push(T val) 
	{
		vec.push_back(val);
	}
	T pop() 
	{
		T val = vec.back();
		vec.pop_back();
		return val;
	}
	T peek() 
	{
		return vec.back();
	}
	vector<T> toVector() 
	{
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
int main() 
{
	/*Stack<int> stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);
	vector<int> res= stk.toVector();
	*/
	VectorStack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	cout << stk.peek()<<endl;
	cout << stk.getSize() << endl;
	vector<int> res = stk.toVector();
	int size = stk.getSize();
	for (size_t i = 0; i < size; i++)
	{
		cout << stk.pop() << endl;
	}
	cout << stk.getSize() << endl;;
	return 0;
}