#include<iostream>
#include<vector>
using namespace std;

class Graph
{
	vector<int> vertices;
	vector<vector<int>> adjMatrix;
public:
	Graph(vector<int> vertices, vector<vector<int>> edges)
	{
		for (int vertex : vertices)
		{
			addVertex(vertex);
		}
		for (vector<int> edge:edges )
		{
			addEdge(edge[0],edge[1]);
		}
	}
	int size()
	{
		return adjMatrix.size();
	}
	void addEdge(int v1, int v2)
	{
		//check the range
		if (v1 == v2 || v1 >= vertices.size() || v2 >= vertices.size())
		{
			throw out_of_range("The vertex does not exist.");
		}
		adjMatrix[v1][v2] = 1;
		adjMatrix[v2][v1] = 1;
	}
	void addVertex(int vertex)
	{
		vertices.push_back(vertex);
		//add row
		vector<int> row(adjMatrix.size(), 0);
		adjMatrix.push_back(row);
		//add column
		for (vector<int>& row : adjMatrix)
		{
			row.push_back(0);
		}
	}
	void removeVertex(int index)
	{
		if (size() == 0 || index >= size())
		{
			throw out_of_range("Out of range");
		}
		vertices.erase(vertices.begin() + index);
		adjMatrix.erase(adjMatrix.begin() + index);
		for (vector<int>& row : adjMatrix)
		{
			row.erase(row.begin() + index);
		}
	}
	void removeEdge(int v1, int v2)
	{
		if (v1 >= size() || v2 >= size() || v1 == v2 || v1 < 0 || v2 < 0)
		{
			throw out_of_range("Does not exist the vertex");
		}
		adjMatrix[v1][v2] = 0;
		adjMatrix[v2][v1] = 0;
	}
	void print() 
	{
		cout << "Vertices: " << endl;
		for (int vertex:vertices) 
		{
			cout << vertex << " ";
		}
		cout << endl;
		cout << "Matrix: " << endl;
		for (vector<int> row:adjMatrix) 
		{
			for(int point:row)
			{
				cout << point << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	try {
		// 测试用例 1：基本功能测试
		cout << "Test Case 1: Basic Functionality" << endl;
		vector<int> vertices = { 0, 1, 2 };
		vector<vector<int>> edges = { {0, 1}, {1, 2} };

		Graph graph(vertices, edges);
		graph.print();

		cout << "Adding vertex 3" << endl;
		graph.addVertex(3);
		graph.print();

		cout << "Adding edge between 2 and 3" << endl;
		graph.addEdge(2, 3);
		graph.print();

		cout << "Removing edge between 1 and 2" << endl;
		graph.removeEdge(1, 2);
		graph.print();

		cout << "Removing vertex 1" << endl;
		graph.removeVertex(1);
		graph.print();

		// 测试用例 2：异常情况测试
		cout << "\nTest Case 2: Exception Handling" << endl;
		Graph graph2(vertices, edges);

		cout << "Trying to add edge with invalid vertex index" << endl;
		try {
			graph2.addEdge(5, 6);
		}
		catch (const out_of_range& e) {
			cout << "Caught exception: " << e.what() << endl;
		}

		cout << "Trying to remove vertex with invalid index" << endl;
		try {
			graph2.removeVertex(10);
		}
		catch (const out_of_range& e) {
			cout << "Caught exception: " << e.what() << endl;
		}

		// 测试用例 3：大规模数据测试
		cout << "\nTest Case 3: Large Data" << endl;
		vector<int> largeVertices;
		for (int i = 0; i < 100; i++) {
			largeVertices.push_back(i);
		}

		vector<vector<int>> largeEdges;
		for (int i = 0; i < 100; i++) {
			for (int j = i + 1; j < 100; j++) {
				largeEdges.push_back({ i, j });
			}
		}

		Graph largeGraph(largeVertices, largeEdges);
		cout << "Large graph created with 100 vertices and " << largeEdges.size() << " edges." << endl;

		cout << "Adding vertex 100" << endl;
		largeGraph.addVertex(100);
		cout << "Adding edge between 0 and 100" << endl;
		largeGraph.addEdge(0, 100);
		cout << "Removing vertex 50" << endl;
		largeGraph.removeVertex(50);

		// 测试用例 4：空图测试
		cout << "\nTest Case 4: Empty Graph" << endl;
		vector<int> emptyVertices;
		vector<vector<int>> emptyEdges;
		Graph emptyGraph(emptyVertices, emptyEdges);
		cout << "Empty graph created." << endl;

		cout << "Trying to remove vertex from empty graph" << endl;
		try {
			emptyGraph.removeVertex(0);
		}
		catch (const out_of_range& e) {
			cout << "Caught exception: " << e.what() << endl;
		}

		cout << "Adding vertex to empty graph" << endl;
		emptyGraph.addVertex(0);
		cout << "Adding edge to single vertex graph" << endl;
		try {
			emptyGraph.addEdge(0, 1);
		}
		catch (const out_of_range& e) {
			cout << "Caught exception: " << e.what() << endl;
		}

	}
	catch (const exception& e) {
		cerr << "Exception occurred: " << e.what() << endl;
		return 1;
	}

	return 0;
}