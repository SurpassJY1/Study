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
		exit(-1); // �ڴ����ʧ�ܣ��˳�����  
	}
	newNode->vertex = vertex;
	newNode->next = NULL;
	if (isEmpty(pQueue))
	{
		// �������Ϊ�գ�����front��rearָ���½ڵ�  
		pQueue->front = pQueue->rear = newNode;
	}
	else
	{
		// ������в�Ϊ�գ����½ڵ���ӵ�����β��  
		pQueue->rear->next = newNode;
		pQueue->rear = newNode; // ����rearָ��  
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
	bool visited[VERTEX_NUM] = { false };//��һ��������¼������û;
	Queue* queue = create();//�������м�¼vertex
	visited[vertex] = true;
	enQueue(queue, vertex);
	while (!isEmpty(queue))
	{
		int curr = deQueue(queue);
		printf("%d\n", curr);
		for (int i = 0; i < VERTEX_NUM; i++)
		{
			if (pGraph->matrix[curr][i] != 0 && !visited[i])//���ʵ�ǰ�ڵ�������������нڵ�
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
	//�ñ�����¼��ʲô�����·�����Լ����·����ֵ
	int path[VERTEX_NUM];
	int* d = (int*)malloc(sizeof(int));
	for (int i = 0; i < VERTEX_NUM; i++)
	{
		path[i] = -1;
		d[i] = -1;
	}
	Queue* queue = create();
	//���Լ���ʼ�Լ����Լ��ľ���Ϊ0
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
//�������������Ѱ��Ȩͼ����С·��
void DFS(AdjacencyMatrix* graph, int start, bool visited[])
{
	//����һ��bool�����¼�ڵ��Ƿ񱻷��ʹ�
	visited[start] = true;
	//��ӡ����ֵ
	printf("%d\n", start);
	//��start�ڵ㿪ʼ��Ѱ��Χ�ڵ�
	for (int i = 0; i < VERTEX_NUM; i++)
	{
		if (graph->matrix[start][i] != 0 && visited[i] == false)
		{
			//�ҵ��ܱ߽ڵ���ܱ߽ڵ�ݹ鴫��
			DFS(graph, i, visited);
		}
	}
}

// ��ӡ��src������������������·��  
void printSolution(int dist[]) {
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < VERTEX_NUM; i++) {
		printf("%d \t\t %d\n", i, dist[i]);
	}
}

// �ҵ�dist������δ���ʶ����о�����Сֵ�Ķ���  
int minDistance(int dist[], bool sptSet[]) {
	int min = INF, min_index=-1;

	for (int v = 0; v < VERTEX_NUM; v++) {
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v], min_index = v;
		}
	}

	return min_index;
}

// Dijkstra�㷨ʵ��  
void dijkstra(AdjacencyMatrix* graph, int src) {
	int dist[VERTEX_NUM]; // �洢��src��ÿ���������̾���  
	bool sptSet[VERTEX_NUM]; // sptSet[i]����Ϊtrue���������i�����·���ѱ��ҵ�  

	// ��ʼ�����о���ΪINF��sptSet[]Ϊfalse  
	for (int i = 0; i < VERTEX_NUM; i++) {
		dist[i] = INF;
		sptSet[i] = false;
	}

	// Դ���㵽����ľ���Ϊ0  
	dist[src] = 0;

	// �ҵ����·���Ķ���  
	for (int count = 0; count < VERTEX_NUM - 1; count++) {
		// ѡ��δ����Ķ����о�����С����Ķ���  
		int u = minDistance(dist, sptSet);

		// ��ѡ��Ķ�����Ϊ�Ѵ���  
		sptSet[u] = true;

		// ����dist[]ֵ  
		for (int v = 0; v < VERTEX_NUM; v++) {
			// ����dist[v]���������ͨ��u����ĸ���·��  
			//uΪ���������δ����Ķ���
			if (!sptSet[v] && graph->matrix[u][v] && dist[u] != INF && dist[u] + graph->matrix[u][v] < dist[v]) {
				dist[v] = dist[u] + graph->matrix[u][v];
			}
		}
	}

	// ��ӡ����ľ�������  
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

	// �Ӷ���0��ʼ����Dijkstra�㷨  
	dijkstra(&graph, 0);

	return 0;
}

