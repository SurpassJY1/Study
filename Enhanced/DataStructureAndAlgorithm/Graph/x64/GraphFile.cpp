//
// Created by GlokieYu on 25-3-22.
//
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>
using namespace std;

class Graph {
    vector<int> vertices;
    vector<vector<int> > adjMatrix;

public:
    Graph(vector<int> vertices, vector<vector<int> > edges) {
        for (int vertex: vertices) {
            addVertex(vertex);
        }
        for (vector<int> edge: edges) {
            addEdge(edge[0], edge[1]);
        }
    }

    int size() {
        return adjMatrix.size();
    }

    void addEdge(int v1, int v2) {
        //check the range
        if (v1 == v2 || v1 >= vertices.size() || v2 >= vertices.size()) {
            throw out_of_range("The vertex does not exist.");
        }
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }

    void addVertex(int vertex) {
        vertices.push_back(vertex);
        //add row
        vector<int> row(adjMatrix.size(), 0);
        adjMatrix.push_back(row);
        //add column
        for (vector<int> &row: adjMatrix) {
            row.push_back(0);
        }
    }

    void removeVertex(int index) {
        if (size() == 0 || index >= size()) {
            throw out_of_range("Out of range");
        }
        vertices.erase(vertices.begin() + index);
        adjMatrix.erase(adjMatrix.begin() + index);
        for (vector<int> &row: adjMatrix) {
            row.erase(row.begin() + index);
        }
    }

    void removeEdge(int v1, int v2) {
        if (v1 >= size() || v2 >= size() || v1 == v2 || v1 < 0 || v2 < 0) {
            throw out_of_range("Does not exist the vertex");
        }
        adjMatrix[v1][v2] = 0;
        adjMatrix[v2][v1] = 0;
    }

    void print() {
        cout << "Vertices: " << endl;
        for (int vertex: vertices) {
            cout << vertex << " ";
        }
        cout << endl;
        cout << "Matrix: " << endl;
        for (vector<int> row: adjMatrix) {
            for (int point: row) {
                cout << point << " ";
            }
            cout << endl;
        }
    }
};

class Vertex {
    int data;

public:
    int getData() {
        return data;
    }

    void setData(int data) {
        this->data = data;
    }

    Vertex(int data): data(data) {
    }

    Vertex() {
    };
};

class ListGraph {
    //using Vertex class instead of index like linked matrixis to avoid the time consuming for deleting
    //if we use Vertex we can delete it directly instread of moveing elements after it to next position
    /**
    * this is a tool method to remove the edge
    * */
    void remove(vector<Vertex *> &edges, Vertex *vex) {
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i]->getData() == vex->getData()) {
                edges.erase(edges.begin() + i);
            }
        }
    }

public:
    unordered_map<Vertex *, vector<Vertex *> > adjList; //using hash map to reduce the time for searching the vertex
    ListGraph(vector<vector<Vertex *> > edges) {
        for (const auto &edge: edges) {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    int size() {
        return adjList.size();
    }

    void addVertex(Vertex *vertex) {
        //check if the vertex is in the graph
        if (adjList.count(vertex)) {
            return;
        }
        adjList.insert(make_pair(vertex, vector<Vertex *>())); //add vertex
    }

    void addEdge(Vertex *vex1, Vertex *vex2) {
        //check if they are in
        if (!adjList.count(vex1) || !adjList.count(vex2) || vex1->getData() == vex2->getData()) {
            throw out_of_range("Vertex does not exist.");
        }
        //push the edge
        adjList[vex1].push_back(vex2);
        adjList[vex2].push_back(vex1);
    }

    void removeVertex(Vertex *vex) {
        //check if the vex is in the graph
        if (!adjList.count(vex)) {
            throw out_of_range("Vertex does not exist.");
        }
        //exist
        //remove vertex
        adjList.erase(vex);
        //remove edges connecting to it
        for (auto &edges: adjList) {
            remove(edges.second, vex);
        }
    }

    void removeEdge(Vertex *vex1, Vertex *vex2) {
        //check if they are exist
        if (!adjList.count(vex1) || !adjList.count(vex2) || vex1->getData() == vex2->getData()) {
            throw out_of_range("Vertex does not exist.");
        }
        //exist, remove the edge
        remove(adjList[vex1], vex2);
        remove(adjList[vex2], vex1);
    }
    vector<Vertex*> BFS(Vertex* start) {
        if (!adjList.count(start)) {
            throw out_of_range("Vertex does not exist.");
        }
        //store if the vertex used to be traversed
        unordered_set<Vertex*> visited;//using hashset to improve performance
        queue<Vertex*> que;
        que.push(start);
        vector<Vertex*> res;
        while (!que.empty()) {
            res.push_back(que.front());
            Vertex *curr=que.front();
            visited.insert(curr);
            que.pop();
            //add the vertex connecting to curr to the queue
            for (auto edges:adjList[curr]) {
                if (!visited.count(edges)) {
                    que.push(edges);
                    visited.emplace(edges);
                }
            }
        }
        return res;
    }
    void DFSHelper(vector<Vertex*> &res,Vertex* vex,unordered_set<Vertex*> &visited) {
        res.push_back(vex);
        visited.emplace(vex);
        for (Vertex* connectedVertex: adjList[vex]) {
            if (visited.count(connectedVertex))
                continue;//pass the visited vertices
            DFSHelper(res, connectedVertex, visited);
        }
    }
    vector<Vertex*> DFS(Vertex* start) {
        if (!adjList.count(start)) {
            throw out_of_range("Vertex does not exist.");
        }
        vector<Vertex*> res;
        unordered_set<Vertex*> visited;
        visited.emplace(start);
        DFSHelper(res, start, visited);
        return res;
    }
};

int main() {
    //	try {
    //		cout << "Test Case 1: Basic Functionality" << endl;
    //		vector<int> vertices = { 0, 1, 2 };
    //		vector<vector<int>> edges = { {0, 1}, {1, 2} };
    //
    //		Graph graph(vertices, edges);
    //		graph.print();
    //
    //		cout << "Adding vertex 3" << endl;
    //		graph.addVertex(3);
    //		graph.print();
    //
    //		cout << "Adding edge between 2 and 3" << endl;
    //		graph.addEdge(2, 3);
    //		graph.print();
    //
    //		cout << "Removing edge between 1 and 2" << endl;
    //		graph.removeEdge(1, 2);
    //		graph.print();
    //
    //		cout << "Removing vertex 1" << endl;
    //		graph.removeVertex(1);
    //		graph.print();
    //
    //		cout << "\nTest Case 2: Exception Handling" << endl;
    //		Graph graph2(vertices, edges);
    //
    //		cout << "Trying to add edge with invalid vertex index" << endl;
    //		try {
    //			graph2.addEdge(5, 6);
    //		}
    //		catch (const out_of_range& e) {
    //			cout << "Caught exception: " << e.what() << endl;
    //		}
    //
    //		cout << "Trying to remove vertex with invalid index" << endl;
    //		try {
    //			graph2.removeVertex(10);
    //		}
    //		catch (const out_of_range& e) {
    //			cout << "Caught exception: " << e.what() << endl;
    //		}
    //
    //		cout << "\nTest Case 3: Large Data" << endl;
    //		vector<int> largeVertices;
    //		for (int i = 0; i < 100; i++) {
    //			largeVertices.push_back(i);
    //		}
    //
    //		vector<vector<int>> largeEdges;
    //		for (int i = 0; i < 100; i++) {
    //			for (int j = i + 1; j < 100; j++) {
    //				largeEdges.push_back({ i, j });
    //			}
    //		}
    //
    //		Graph largeGraph(largeVertices, largeEdges);
    //		cout << "Large graph created with 100 vertices and " << largeEdges.size() << " edges." << endl;
    //
    //		cout << "Adding vertex 100" << endl;
    //		largeGraph.addVertex(100);
    //		cout << "Adding edge between 0 and 100" << endl;
    //		largeGraph.addEdge(0, 100);
    //		cout << "Removing vertex 50" << endl;
    //		largeGraph.removeVertex(50);
    //
    //
    //		cout << "\nTest Case 4: Empty Graph" << endl;
    //		vector<int> emptyVertices;
    //		vector<vector<int>> emptyEdges;
    //		Graph emptyGraph(emptyVertices, emptyEdges);
    //		cout << "Empty graph created." << endl;
    //
    //		cout << "Trying to remove vertex from empty graph" << endl;
    //		try {
    //			emptyGraph.removeVertex(0);
    //		}
    //		catch (const out_of_range& e) {
    //			cout << "Caught exception: " << e.what() << endl;
    //		}
    //
    //		cout << "Adding vertex to empty graph" << endl;
    //		emptyGraph.addVertex(0);
    //		cout << "Adding edge to single vertex graph" << endl;
    //		try {
    //			emptyGraph.addEdge(0, 1);
    //		}
    //		catch (const out_of_range& e) {
    //			cout << "Caught exception: " << e.what() << endl;
    //		}
    //
    //	}
    //	catch (const exception& e) {
    //		cerr << "Exception occurred: " << e.what() << endl;
    //		return 1;
    //	}
    //
    //	return 0;
    // 创建顶点
    Vertex *v1 = new Vertex(1);
    Vertex *v2 = new Vertex(2);
    Vertex *v3 = new Vertex(3);
    Vertex *v4 = new Vertex(4);

    // 创建边的集合
    vector<vector<Vertex *> > edges = {
        {v1, v2},
        {v2, v3},
        {v3, v4},
        {v4, v1}
    };

    // 使用边的集合初始化图
    ListGraph graph(edges);

    // 打印图的邻接表
    cout << "Graph adjacency list after initialization:" << endl;
    for (const auto &entry: graph.adjList) {
        cout << "Vertex " << entry.first->getData() << ": ";
        for (const auto &neighbor: entry.second) {
            cout << neighbor->getData() << " ";
        }
        cout << endl;
    }

    // 添加新的顶点和边
    Vertex *v5 = new Vertex(5);
    try {
        graph.addVertex(v5);
        graph.addEdge(v1, v5);
        cout << "Added new vertex and edge successfully." << endl;
    } catch (const out_of_range &e) {
        cout << "Error: " << e.what() << endl;
    }

    // 打印图的邻接表
    cout << "Graph adjacency list after adding new vertex and edge:" << endl;
    for (const auto &entry: graph.adjList) {
        cout << "Vertex " << entry.first->getData() << ": ";
        for (const auto &neighbor: entry.second) {
            cout << neighbor->getData() << " ";
        }
        cout << endl;
    }
    cout<<"BFS Traversal:"<<endl;
    vector<Vertex*> vertices=graph.BFS(v1);
    for (Vertex *vertex: vertices) {
        cout << vertex->getData() << " ";
    }
    cout<<endl;
    cout<<"DFS Traversal: "<<endl;
    vector<Vertex*> res=graph.DFS(v1);
    for (Vertex *vertex: res) {
        cout << vertex->getData() << " ";
    }
    // 移除边
    try {
        graph.removeEdge(v1, v2);
        cout << "Removed edge between v1 and v2 successfully." << endl;
    } catch (const out_of_range &e) {
        cout << "Error: " << e.what() << endl;
    }

    // 移除顶点
    try {
        graph.removeVertex(v3);
        cout << "Removed vertex v3 successfully." << endl;
    } catch (const out_of_range &e) {
        cout << "Error: " << e.what() << endl;
    }

    // 打印图的邻接表
    cout << "Graph adjacency list after removals:" << endl;
    for (const auto &entry: graph.adjList) {
        cout << "Vertex " << entry.first->getData() << ": ";
        for (const auto &neighbor: entry.second) {
            cout << neighbor->getData() << " ";
        }
        cout << endl;
    }

    // 释放动态分配的内存
    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;

    return 0;
}
