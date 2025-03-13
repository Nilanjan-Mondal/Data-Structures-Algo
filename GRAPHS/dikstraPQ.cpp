#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

vector<list<pair<int, int>>> graph;
vector<int> distArr;
int v;

void add_edge(int src, int dest, int weight, bool bi_dir = true) {
  graph[src].push_back({dest, weight});
  if (bi_dir)
    graph[dest].push_back({src, weight});
}

void dijkstra(int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  distArr.assign(v, 1e9);
  distArr[src] = 0;

  pq.push({0, src});

  while (!pq.empty()) {
    int node = pq.top().second;
    int currDist = pq.top().first;
    pq.pop();

    for (auto &neighbor : graph[node]) {
      int adjNode = neighbor.first;
      int edgeWeight = neighbor.second;

      if (currDist + edgeWeight < distArr[adjNode]) {
        distArr[adjNode] = currDist + edgeWeight;
        pq.push({distArr[adjNode], adjNode});
      }
    }
  }
}

int main() {
  cin >> v;
  graph.resize(v);

  int edges;
  cin >> edges;
  while (edges--) {
    int s, d, w;
    cin >> s >> d >> w;
    add_edge(s, d, w);
  }

  int src;
  cin >> src;

  dijkstra(src);

  for (int i = 0; i < v; i++)
    cout << distArr[i] << " ";

  return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// #define INF 1000000000

// typedef struct Node {
//     int vertex, weight;
//     struct Node* next;
// } Node;

// typedef struct {
//     Node** adjList;
//     int* dist;
//     int vertices;
// } Graph;

// typedef struct {
//     int vertex, distance;
// } MinHeapNode;

// typedef struct {
//     MinHeapNode* heapArray;
//     int size, capacity;
// } MinHeap;

// Node* createNode(int v, int w) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->vertex = v;
//     newNode->weight = w;
//     newNode->next = NULL;
//     return newNode;
// }

// Graph* createGraph(int vertices) {
//     Graph* graph = (Graph*)malloc(sizeof(Graph));
//     graph->vertices = vertices;
//     graph->adjList = (Node**)malloc(vertices * sizeof(Node*));
//     graph->dist = (int*)malloc(vertices * sizeof(int));

//     for (int i = 0; i < vertices; i++) {
//         graph->adjList[i] = NULL;
//         graph->dist[i] = INF;
//     }
//     return graph;
// }

// void addEdge(Graph* graph, int src, int dest, int weight, int bi_dir) {
//     Node* newNode = createNode(dest, weight);
//     newNode->next = graph->adjList[src];
//     graph->adjList[src] = newNode;

//     if (bi_dir) {
//         newNode = createNode(src, weight);
//         newNode->next = graph->adjList[dest];
//         graph->adjList[dest] = newNode;
//     }
// }

// MinHeap* createMinHeap(int capacity) {
//     MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
//     minHeap->size = 0;
//     minHeap->capacity = capacity;
//     minHeap->heapArray = (MinHeapNode*)malloc(capacity *
//     sizeof(MinHeapNode)); return minHeap;
// }

// void swapMinHeapNode(MinHeapNode* a, MinHeapNode* b) {
//     MinHeapNode temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void minHeapify(MinHeap* minHeap, int idx) {
//     int smallest = idx;
//     int left = 2 * idx + 1;
//     int right = 2 * idx + 2;

//     if (left < minHeap->size && minHeap->heapArray[left].distance <
//     minHeap->heapArray[smallest].distance)
//         smallest = left;

//     if (right < minHeap->size && minHeap->heapArray[right].distance <
//     minHeap->heapArray[smallest].distance)
//         smallest = right;

//     if (smallest != idx) {
//         swapMinHeapNode(&minHeap->heapArray[smallest],
//         &minHeap->heapArray[idx]); minHeapify(minHeap, smallest);
//     }
// }

// MinHeapNode extractMin(MinHeap* minHeap) {
//     MinHeapNode root = minHeap->heapArray[0];
//     minHeap->heapArray[0] = minHeap->heapArray[minHeap->size - 1];
//     minHeap->size--;
//     minHeapify(minHeap, 0);
//     return root;
// }

// void insertMinHeap(MinHeap* minHeap, int v, int dist) {
//     int i = minHeap->size++;
//     minHeap->heapArray[i].vertex = v;
//     minHeap->heapArray[i].distance = dist;

//     while (i > 0 && minHeap->heapArray[(i - 1) / 2].distance >
//     minHeap->heapArray[i].distance) {
//         swapMinHeapNode(&minHeap->heapArray[i], &minHeap->heapArray[(i - 1) /
//         2]); i = (i - 1) / 2;
//     }
// }

// void dijkstra(Graph* graph, int src) {
//     MinHeap* minHeap = createMinHeap(graph->vertices);
//     graph->dist[src] = 0;
//     insertMinHeap(minHeap, src, 0);

//     while (minHeap->size > 0) {
//         MinHeapNode minNode = extractMin(minHeap);
//         int u = minNode.vertex;

//         Node* temp = graph->adjList[u];
//         while (temp) {
//             int v = temp->vertex;
//             int weight = temp->weight;

//             if (graph->dist[u] + weight < graph->dist[v]) {
//                 graph->dist[v] = graph->dist[u] + weight;
//                 insertMinHeap(minHeap, v, graph->dist[v]);
//             }
//             temp = temp->next;
//         }
//     }
//     free(minHeap->heapArray);
//     free(minHeap);
// }

// int main() {
//     int vertices, edges;
//     printf("Enter number of vertices and edges: ");
//     scanf("%d %d", &vertices, &edges);

//     Graph* graph = createGraph(vertices);

//     printf("Enter edges (src dest weight):\n");
//     for (int i = 0; i < edges; i++) {
//         int src, dest, weight;
//         scanf("%d %d %d", &src, &dest, &weight);
//         addEdge(graph, src, dest, weight, 1);
//     }

//     int source;
//     printf("Enter source vertex: ");
//     scanf("%d", &source);

//     dijkstra(graph, source);

//     printf("Shortest distances from source %d:\n", source);
//     for (int i = 0; i < vertices; i++) {
//         printf("Node %d: %d\n", i, (graph->dist[i] == INF ? -1 :
//         graph->dist[i]));
//     }

//     free(graph->adjList);
//     free(graph->dist);
//     free(graph);
//     return 0;
// }
