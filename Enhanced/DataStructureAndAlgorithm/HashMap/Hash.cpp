#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Pair
{
public:
	int m_Key;
	string m_Value;
	Pair(int key, string value) :m_Key(key), m_Value(value) {}
};
class MyPrint
{
public:
	void operator()(Pair* pair)
	{
		cout << pair->m_Key << "->" << pair->m_Value;
	}
};
class HashMap
{
	vector<Pair*> map;
public:
	HashMap()
	{
		map.resize(100);
	}
	~HashMap()
	{
		for (int i = 0;i < map.size();i++)
		{
			if (map[i] != nullptr)
			{
				delete map[i];
			}
			map.clear();
		}
	}
	int hashFunc(int key)
	{
		int index = key % 100;
		return index;
	}
	void put(int key, string val)
	{
		Pair* input = new Pair(key, val);
		map[hashFunc(input->m_Key)] = input;
	}
	void remove(int key)
	{
		int index = hashFunc(key);
		delete map[index];
		map[index] = nullptr;
	}
	string get(int key)
	{
		int index = hashFunc(key);
		if (map[index] == nullptr)
		{
			return "";
		}
		return map[index]->m_Value;
	}
	vector<Pair*> getAll()
	{
		vector<Pair*> res;
		for (Pair* pair : map)
		{
			if (pair != nullptr)
			{
				res.push_back(pair);
			}
		}
		return res;
	}
	void printAll()
	{
		vector<Pair*> res = getAll();
		for_each(res.begin(), res.end(), MyPrint());
	}
};
/*
This class is used to solve hash collision by separate chaining
*/
class HashMapChaining
{
	int size;
	int capacity;
	int extendRatio;
	double loadThres;
	vector<vector<Pair*>> buckets;
public:
	HashMapChaining() :size(0), capacity(4), extendRatio(2), loadThres(0.75)
	{
		buckets.resize(capacity);
	}
	~HashMapChaining()
	{
		for (vector<Pair*> bucket : buckets)
		{
			for (Pair* pair : bucket)
			{
				if (pair != nullptr)
				{
					delete pair;
				}
			}
		}
		buckets.clear();
	}
	int hashFunc(int key)
	{
		return key % capacity;
	}
	string get(int key)
	{
		int index = hashFunc(key);
		for (Pair* pair : buckets[index])
		{
			if (pair != nullptr && pair->m_Key == key)
			{
				return pair->m_Value;
			}
		}
		return "";
	}
	double loadFactor()
	{
		return (double)size / (double)capacity;
	}
	void extend()
	{
		//store the data
		vector<vector<Pair*>> bucketsTemp = buckets;
		capacity *= capacity * extendRatio;
		buckets.clear();
		buckets.resize(capacity);
		size = 0;
		//Traverse the all data and input it to refreshed buckets
		for (auto& bucket : bucketsTemp)
		{
			for (Pair* pair : bucket)
			{
				put(pair->m_Key, pair->m_Value);
				//free the memory
				delete pair;
			}
		}
	}
	void put(int key, string value)
	{
		//judge if the buckets need to extend;
		if (loadFactor() > loadThres)
		{
			extend();
		}
		Pair* pair = new Pair(key, value);
		//Traverse the list to check if the key is already in itself
		for (Pair* pair : buckets[hashFunc(key)])
		{
			if (pair->m_Key == key)
			{
				//already in, refresh it
				pair->m_Value = value;
				return;
			}
		}
		//Not found, push_back it
		buckets[hashFunc(key)].push_back(new Pair(key, value));
		size++;
	}
	void remove(int key)
	{
		int index = hashFunc(key);
		for (int i = 0;i < buckets[index].size();i++)
		{
			//find and delete it
			if (buckets[index][i]->m_Key == key)
			{
				Pair* temp = buckets[index][i];
				buckets[index].erase(buckets[index].begin() + i);
				//free the memory
				delete temp;
				size--;
			}
		}
	}
	void print() {
		for (auto& bucket : buckets) {
			if (bucket.size() != 0) {
				cout << "[";
				for (Pair* pair : bucket) {
					cout << pair->m_Key << " -> " << pair->m_Value << ", ";
				}
				cout << "]\n";
			}
		}
	}
};
class HashMapOpenAddressing
{
	int size;
	int capacity = 4;
	const double loadThres = 0.75;
	const int extendRatio = 2;
	vector<Pair*> buckets;
	Pair* tombstone = new Pair(-1, "-1");
public:
	HashMapOpenAddressing() :size(0), buckets(capacity, nullptr) {}
	~HashMapOpenAddressing()
	{
		for (Pair* pair : buckets)
		{
			if (pair != nullptr && pair != tombstone)
			{
				delete pair;
			}
		}
		delete tombstone;
	}
	int hashFunc(int key)
	{
		return key % capacity;
	}
	double loadFactor()
	{
		return (double)size / capacity;
	}
	int findBucket(int key)
	{
		int index = hashFunc(key);
		int tombId = -1;
		//get the index position
		while (buckets[index] != nullptr)
		{
			//find it, return the position
			if (buckets[index]->m_Key == key)
			{
				//before return it, we exchange the tombstone and input pair, if we find tombstone before the pair
				if (tombId != -1)
				{
					buckets[tombId] = buckets[index];
					buckets[index] = tombstone;
					return tombId;
				}
				return index;
			}
			//record the first deleted position
			if (buckets[index] == tombstone && tombId == -1)
			{
				tombId = index;
			}
			//not found, move the index to next
			index = (index + 1) % capacity;
		}
		//the index is empty, return the index
		return tombId == -1 ? index : tombId;
	}
	string get(int key) 
	{
		int index = findBucket(key);
		if (buckets[index] != nullptr && buckets[index]!=tombstone) 
		{
			return buckets[index]->m_Value;
		}
		return "";
	}
	void remove(int key)
	{
		int index = findBucket(key);
		//if find the element,remove it and put tombstone in the position
		if (buckets[index] != nullptr && buckets[index] != tombstone)
		{
			delete buckets[index];
			size--;
			buckets[index] = tombstone;
		}
	}
	void put(int key, string value)
	{
		//check the loadFactor
		if (loadFactor() >= loadThres)
		{
			extend();
		}

		int index = findBucket(key);
		//if find,refresh it
		if (buckets[index] != nullptr && buckets[index] != tombstone)
		{
			buckets[index]->m_Value = value;
			return;
		}
		//not found, put it;
		buckets[index] = new Pair(key, value);
		size++;
	}
	void extend()
	{
		//record
		vector<Pair*> tmpBuckets = buckets;
		capacity *= extendRatio;
		buckets.clear();
		size = 0;
		buckets.resize(capacity, nullptr);
		for (Pair* pair : tmpBuckets)
		{
			if (pair != tombstone && pair != nullptr)
			{
				put(pair->m_Key, pair->m_Value);
			}
		}
	}
	void print()
	{
		for (Pair* pair : buckets)
		{
			if (pair == nullptr)
			{
				cout << "nullptr" << endl;
			}
			else if (pair == tombstone)
			{
				cout << "tombstone" << endl;
			}
			else
			{
				cout << pair->m_Key << "->" << pair->m_Value << endl;
			}
		}
	}
};
int main()
{
	//HashMapChaining hashmap;

	//// Test put and print
	//cout << "Inserting elements:" << endl;
	//hashmap.put(1, "Hello");
	//hashmap.put(2, "World");
	//hashmap.put(3, "Hash");
	//hashmap.put(4, "Table");
	//hashmap.put(101, "Collision");
	//hashmap.put(202, "Test");
	//hashmap.print();

	//// Test get
	//cout << "\nTesting get:" << endl;
	//cout << "Key 1: " << hashmap.get(1) << endl;
	//cout << "Key 2: " << hashmap.get(2) << endl;
	//cout << "Key 5: " << hashmap.get(5) << endl; // Non-existent key

	//// Test remove
	//cout << "\nRemoving key 2:" << endl;
	//hashmap.remove(2);
	//hashmap.print();

	//// Test update
	//cout << "\nUpdating key 1 to 'Hi':" << endl;
	//hashmap.put(1, "Hi");
	//hashmap.print();
	// 测试 HashMapChaining
	// 创建一个开放寻址哈希表
	HashMapOpenAddressing map;

	// 插入一些键值对
	cout << "Inserting key-value pairs:" << endl;
	map.put(1, "one");
	map.put(2, "two");
	map.put(5, "five");
	map.put(9, "nine");
	map.put(13, "thirteen");
	map.print();

	// 查找键值对
	cout << "\nFinding key 2: " << map.get(2) << endl;

	// 删除键值对
	cout << "\nRemoving key 2:" << endl;
	map.remove(2);
	map.print();

	// 再次查找被删除的键
	cout << "\nFinding key 2 after removal: " << map.get(2) << endl;

	// 插入更多键值对以触发扩容
	cout << "\nInserting more key-value pairs to trigger rehashing:" << endl;
	map.put(17, "seventeen");
	map.put(21, "twenty-one");
	map.print();

	return 0;
}