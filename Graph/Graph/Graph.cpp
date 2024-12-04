#define VERTEX_NUM 9
#define INF INT_MAX
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct adjacency_matrix {
	int matrix[VERTEX_NUM][VERTEX_NUM];
}AdjacencyMatrix;
typedef struct Edge {
	int weight;
	int src;
	int dest;
}Edge;
typedef struct QueueNode {
	int vertex;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue {
	QueueNode* front;
	QueueNode* rear;
}Queue;
AdjacencyMatrix* createAdjacencyMatrix(int defaultEdgeValue);
int addEdge(AdjacencyMatrix* adjPtr, int src, int dest, int weight);
void check(AdjacencyMatrix* adjPtr);
int addEdges(AdjacencyMatrix* pMatrix, Edge edges[], int edgeNum);
AdjacencyMatrix* createAdjacencyMatrix(int defaultEdgeValue)
{
	AdjacencyMatrix* adjPtr = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
	if (adjPtr == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return NULL;
	}
	for (int i = 0; i < VERTEX_NUM; i++)
	{
		for (int j = 0;j < VERTEX_NUM;j++)
		{
			adjPtr->matrix[i][j] = defaultEdgeValue;
		}
	}
	return adjPtr;
}

int addEdge(AdjacencyMatrix* adjPtr, int src, int dest, int weight)
{
	if (src<0 || src>VERTEX_NUM || dest<0 || dest>VERTEX_NUM) {
		fprintf(stderr, "src(dest) beyonds VERTEX_NUM\n");
		return -1;
	}
	adjPtr->matrix[src][dest] = weight;
	return 0;
}

void check(AdjacencyMatrix* adjPtr)
{
	for (int i = 0; i < VERTEX_NUM; i++)
	{
		for (int j = 0; j < VERTEX_NUM;j++) {
			printf("%d ", adjPtr->matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int addEdges(AdjacencyMatrix* pMatrix, Edge edges[], int edgeNum)
{
	for (int i = 0; i < edgeNum; i++)
	{
		if (edges[i].src<0 || edges[i].src>VERTEX_NUM || edges[i].dest<0 || edges[i].dest>VERTEX_NUM)
		{
			fprintf(stderr, "Index beyonds vertices");
			return -1;
		}
	}
	for (int i = 0; i < edgeNum; i++)
	{
		pMatrix->matrix[edges[i].src][edges[i].dest] = edges[i].weight;
	}
	return 0;
}
Queue* create()
{
	Queue* pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue == NULL)
	{
		exit(-1);
	}
	pQueue->front = NULL;
	pQueue->rear = NULL;
	return pQueue;
};

bool isEmpty(Queue* pQueue)
{
	return pQueue->front == NULL;
}

void enQueue(Queue* pQueue, int vertex)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		exit(-1); // 内存分配失败，退出程序  
	}
	newNode->vertex = vertex;
	newNode->next = NULL;
	if (isEmpty(pQueue))
	{
		// 如果队列为空，设置front和rear指向新节点  
		pQueue->front = pQueue->rear = newNode;
	}
	else
	{
		// 如果队列不为空，将新节点添加到队列尾部  
		pQueue->rear->next = newNode;
		pQueue->rear = newNode; // 更新rear指针  
	}
}
int deQueue(Queue* pQueue)
{
	if (isEmpty(pQueue)) {
		printf("Queue is empty\n");
		return -1;
	}
	QueueNode* temp = pQueue->front;
	int value = temp->vertex;
	pQueue->front = pQueue->front->next;
	if (pQueue->front == NULL) {
		pQueue->rear = NULL;
	}
	free(temp);
	return value;
}

void BFS(AdjacencyMatrix* pGraph, int vertex)
{
	bool visited[VERTEX_NUM] = { false };//用一个变量记录访问了没;
	Queue* queue = create();//创建队列记录vertex
	visited[vertex] = true;
	enQueue(queue, vertex);
	while (!isEmpty(queue))
	{
		int curr = deQueue(queue);
		printf("%d\n", curr);
		for (int i = 0; i < VERTEX_NUM; i++)
		{
			if (pGraph->matrix[curr][i] != 0 && !visited[i])//访问当前节点可能相连的所有节点
			{
				visited[i] = true;
				enQueue(queue, i);
			}
		}
	}
	free(queue);
}

int* BFS_MIN_DIST(AdjacencyMatrix* graph, int start)
{
	bool visited[VERTEX_NUM] = { false };
	//用变量记录从什么到最短路径的以及最短路径的值
	int path[VERTEX_NUM];
	int* d = (int*)malloc(sizeof(int));
	for (int i = 0; i < VERTEX_NUM; i++)
	{
		path[i] = -1;
		d[i] = -1;
	}
	Queue* queue = create();
	//从自己开始自己到自己的距离为0
	d[start] = 0;
	visited[start] = true;
	enQueue(queue, start);
	while (!isEmpty(queue)) {
		int val = deQueue(queue);
		for (int i = 0; i < VERTEX_NUM; i++)
		{
			if (graph->matrix[val][i] != 0 && visited[i] != true)
			{
				visited[i] = true;
				d[i] = d[val] + 1;
				path[i] = val;
				enQueue(queue, i);
			}
		}
	}
	free(queue);
	return d;
}
//这个方法用来找寻无权图的最小路径
void DFS(AdjacencyMatrix* graph, int start, bool visited[])
{
	//生成一个bool数组记录节点是否被访问过
	visited[start] = true;
	//打印访问值
	printf("%d\n", start);
	//从start节点开始找寻周围节点
	for (int i = 0; i < VERTEX_NUM; i++)
	{
		if (graph->matrix[start][i] != 0 && visited[i] == false)
		{
			//找到周边节点后将周边节点递归传入
			DFS(graph, i, visited);
		}
	}
}

// 打印从src到所有其他顶点的最短路径  
void printSolution(int dist[]) {
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < VERTEX_NUM; i++) {
		printf("%d \t\t %d\n", i, dist[i]);
	}
}

// 找到dist数组中未访问顶点中具有最小值的顶点  
int minDistance(int dist[], bool sptSet[]) {
	int min = INF, min_index=-1;

	for (int v = 0; v < VERTEX_NUM; v++) {
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v], min_index = v;
		}
	}

	return min_index;
}

// Dijkstra算法实现  
void dijkstra(AdjacencyMatrix* graph, int src) {
	int dist[VERTEX_NUM]; // 存储从src到每个顶点的最短距离  
	bool sptSet[VERTEX_NUM]; // sptSet[i]将变为true，如果顶点i的最短路径已被找到  

	// 初始化所有距离为INF，sptSet[]为false  
	for (int i = 0; i < VERTEX_NUM; i++) {
		dist[i] = INF;
		sptSet[i] = false;
	}

	// 源顶点到自身的距离为0  
	dist[src] = 0;

	// 找到最短路径的顶点  
	for (int count = 0; count < VERTEX_NUM - 1; count++) {
		// 选择未处理的顶点中具有最小距离的顶点  
		int u = minDistance(dist, sptSet);

		// 将选择的顶点标记为已处理  
		sptSet[u] = true;

		// 更新dist[]值  
		for (int v = 0; v < VERTEX_NUM; v++) {
			// 更新dist[v]，如果它是通过u到达的更短路径  
			//u为距离最近的未处理的顶点
			if (!sptSet[v] && graph->matrix[u][v] && dist[u] != INF && dist[u] + graph->matrix[u][v] < dist[v]) {
				dist[v] = dist[u] + graph->matrix[u][v];
			}
		}
	}

	// 打印构造的距离数组  
	printSolution(dist);
}
int main()
{
	AdjacencyMatrix graph = {
		{
			{0, 4, INF, INF, INF, INF, INF, 8, INF},
			{4, 0, 8, INF, INF, INF, INF, 11, INF},
			{INF, 8, 0, 7, INF, 4, INF, INF, 2},
			{INF, INF, 7, 0, 9, 14, INF, INF, INF},
			{INF, INF, INF, 9, 0, 10, INF, INF, INF},
			{INF, INF, 4, 14, 10, 0, 2, INF, INF},
			{INF, INF, INF, INF, INF, 2, 0, 1, 6},
			{8, 11, INF, INF, INF, INF, 1, 0, 7},
			{INF, INF, 2, INF, INF, INF, 6, 7, 0}
		}
	};

	// 从顶点0开始运行Dijkstra算法  
	dijkstra(&graph, 0);

	return 0;
}

