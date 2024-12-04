#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template <class T>

class MySet {
	class Node
	{
	private:
		T data;
		Node* next;
		Node* prev;
	public:
		Node(T data) :data(data), next(nullptr), prev(nullptr) {}
		T setData(T data) {
			data = data;
			return data;
		}
		T getData() {
			return data;
		}
		Node* getNext()
		{
			return next;
		}
		void setNext(Node* node)
		{
			next = node;
		}
		Node* getPrev()
		{
			return prev;
		}
		void setPrev(Node* node)
		{
			prev = node;
		}
	};
private:
	Node* head;
	Node* tail;
public:
	MySet() :head(nullptr), tail(nullptr) {}
	Node* getHead() {
		return head;
	}
	Node* getTail()
	{
		return tail;
	}
	//This method is used to check if the set is empty
	bool isEmpty()
	{
		return getHead() == nullptr;
	}
	//This method is used to find node by key
	Node* find(T key)
	{
		if (isEmpty())
		{
			cout << "The set is Empty" << endl;
			return nullptr;
		}
		Node* curr = getHead();
		while (curr!=nullptr) {
			if (curr->getData()==key)
			{
				return curr;
			}
			curr = curr->getNext();
		}
		return nullptr;
	}
	//This method is used to insert element to the set
	Node* insert(T key) {
		Node* node = new Node(key);
		if (isEmpty())
		{
			head = node;
			return node;
		}
		//check if the node is in the set
		Node* curr = head;
		while (curr->getNext() != nullptr)
		{
			if (node->getData() == curr->getData())
			{
				//if the node is in the set, return
				//free the memory
				delete node;
				return nullptr;
			}
			curr = curr->getNext();
		}
		//check the last element
		if (curr->getData() != node->getData())
		{
			curr->setNext(node);
			node->setPrev(curr);
		}
		else
		{
			cout << "The value is in the set already\n" << endl;
			//free the memory
			delete node;
			return nullptr;
		}
		return node;
	}
	//This method is used to traverse the set and print all element
	void traverse() {
		if (isEmpty())
		{
			cout << "The set is empty" << endl;
			return;
		}
		int i = 1;
		for (Node* curr = head; curr != nullptr; curr = curr->getNext())
		{
			cout << "The " << i << " element: " << curr->getData() << endl;
			i++;
		}
	}
	//This method is used to remove element of set
	Node* remove(T key)
	{
		//check if the set empty
		if (isEmpty())
		{
			cout << "The set is empty" << endl;
			return nullptr;
		}
		//traverse the set and match all elements
		Node* curr = getHead();
		while (curr != nullptr) {
			//match the data
			if (curr->getData() == key) {
				//if the removed element is head
				if (curr == head)
				{
					head = curr->getNext();
					//if the deleted one is not the only element
					if (head != nullptr) {
						head->setPrev(nullptr);
					}
					return curr;
				}
				//if curr is tail element
				if (curr->getNext() == nullptr)
				{
					curr->getPrev()->setNext(nullptr);
					curr->setPrev(nullptr);
					return curr;
				}
				//curr is in the middle of set
				curr->getPrev()->setNext(curr->getNext());
				curr->getNext()->setPrev(curr->getPrev());
				curr->setPrev(nullptr);
				curr->setNext(nullptr);
				return curr;
			}
			curr = curr->getNext();
		}
	}
	//This method is used to find intersection of set A and B and assign it to C
	static void intersection(MySet A,MySet B,MySet& C)
	{
		Node* curr = A.getHead();
		while (curr!=nullptr)
		{
			//if we found the same element in set B, we can make sure curr is both in A and B
			if (B.find(curr->getData()))
			{
				C.insert(curr->getData());
			}
			curr = curr->getNext();
		}
	}
	//This method is used to find the union and assign it to set C
	static void findUnion(MySet A,MySet B,MySet& C)
	{
		Node* curr = A.getHead();
		while (curr != nullptr)
		{
			C.insert(curr->getData());
			curr = curr->getNext();
		}
		Node* currB = B.getHead();
		while (currB != nullptr)
		{
			C.insert(currB->getData());
			currB = currB->getNext();
		}
	}
	//This method is used to find A-B and assign it to C
	static void setDiff(MySet A, MySet B, MySet& C)
	{
		Node* curr = A.getHead();
		while (curr != nullptr)
		{
			//if we found the same element in set B, we can make sure curr is both in A and B
			if (!B.find(curr->getData()))
			{
				C.insert(curr->getData());
			}
			curr = curr->getNext();
		}
	}
	//This method is used to find the k lagrest elements
	 void topK(int k)
	{
	//using a container to store elements
		 vector<T> elements;
		 Node* curr = getHead();
		 //adding all elements into the vector
		 while (curr!=nullptr)
		 {
			 elements.push_back(curr->getData());
			 curr = curr->getNext();
		 }
		 //sort the vector
		 sort(elements.begin(),elements.end(),greater<T>());
		 for (int i = 0; i <elements.size() && i<=k; i++)
		 {
			 cout << "The " << (i+1)<< " element " << elements[i] << endl;
		 }
	}
	
};


int main()
{
	MySet<int> set;
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(3);
	set.insert(3);
	MySet<int> set2;
	MySet<int> set3 ;
	set2.insert(1);
	set2.insert(2);
	MySet<int>::intersection(set, set2, set3);
	set3.traverse();
	cout << endl;
	set.insert(5);
	MySet<int>setC;
	MySet<int>::setDiff(set,set2,setC);
	setC.traverse();
	set.topK(1);
	return 0;
}