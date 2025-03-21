#include<vector>
#include<iostream>
#include<queue>
#include<functional>
using namespace std;

class MaxHeap
{
	vector<int> maxHeap;
	int left(int i)
	{
		return 2 * i + 1;
	}
	int right(int i)
	{
		return 2 * i + 2;
	}
	int parent(int i)
	{
		return (i - 1) / 2;//向下取整
	}
	void siftUp(int i)
	{
		while (true)
		{
			int p = parent(i);
			if (p < 0 || maxHeap[i] <= maxHeap[p])//p beyond the index or i is at right position
				break;
			int temp = maxHeap[p];
			maxHeap[p] = maxHeap[i];
			maxHeap[i] = temp;
			i = p;
		}
	}
	void siftDown(int i)
	{
		while (true)
		{
			int max = i;
			int l = left(i);
			int r = right(i);
			if (l<maxHeap.size() && maxHeap[l] > maxHeap[max])
			{
				max = l;
			}
			if (r<maxHeap.size()&&maxHeap[r] > maxHeap[max])
			{
				max = r;
			}
			if (max == i)//to the end or i is greatest 
			{
				break;
			}
			//max is the biggest 
			int temp = maxHeap[i];
			maxHeap[i] = maxHeap[max];
			maxHeap[max] = temp;
			i = max;
		}
	}
public:
	void insert(int val)
	{
		maxHeap.push_back(val);
		siftUp(maxHeap.size() - 1);//sort from the bottom
	}
	int pop()//move the top element 
	{
		//swap the top element with the end
		int val = maxHeap[0];
		maxHeap[0] = maxHeap[maxHeap.size() - 1];
		maxHeap.pop_back();//remove the end
		siftDown(0);//sort from top
		return val;
	}
	MaxHeap() 
	{}
	MaxHeap(vector<int> vec) 
	{
		maxHeap = vec;
		//从倒数第二层开始倒叙层序遍历
		for (int i = parent(maxHeap.size() - 1);i>=0;i--)
		{
			siftDown(i);
		}
	}
	void print()
	{
		for (int i = 0;i < maxHeap.size();i++)
		{
			cout << maxHeap[i] << " ";
		}
		cout << endl;
	}
};
void test()
{
	MaxHeap maxHeap;
	maxHeap.insert(1);
	maxHeap.insert(1);
	maxHeap.insert(2);
	maxHeap.insert(3);
	maxHeap.insert(4);
	maxHeap.insert(5);
	maxHeap.print();
	cout << maxHeap.pop() << endl;
	maxHeap.print();
}
priority_queue<int,vector<int>,greater<int>> topK(vector<int> &vec,int k) 
{
	//push k elements in priority queue
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0;i < k;i++)
	{
		minHeap.push(vec[i]);
	}
	//insert the number greater than the smallest element of the vec
	for (int i=vec.size()-1;i>=k;i--) 
	{
		if (vec[i] > minHeap.top())
			minHeap.pop();
		minHeap.push(vec[i]);//replace the smallest
	}
	return minHeap;
}



int main()
{
	vector<int> vec = {1,2,3,4,5,6};
	priority_queue<int, vector<int>, greater<int>> topKQ = topK(vec,3);
	int size = topKQ.size();
	cout << "Size: " << size << endl;
	for(int i=0;i<size;i++)
	{
		cout << topKQ.top() << endl;
		topKQ.pop();
	}
	system("pause");
	return 0;
}