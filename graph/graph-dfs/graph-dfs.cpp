#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

struct Node
{
    int dest;
    int weight;
    Node(int d, int w = 1) : dest(d), weight(w)
    {
    }
};

class Graph
{
public:
    int numVertices;
    vector<list<Node>> adjList;
    bool directed = false;

    Graph(int V) : numVertices(V), adjList(V) {}

    void addEdge(int src, int dest, int weight = 1)
    {
        adjList[src].push_back(Node(dest, weight));
        if (!directed)
        { 
            adjList[dest].push_back(Node(src, weight));
        }
    }

    void dfsHelper(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (Node node : adjList[vertex])
        {
            if (!visited[node.dest])
            {
                dfsHelper(node.dest, visited);
            }
        }
    }

    void dfs(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        dfsHelper(startVertex, visited);
    }
};

int main()
{
    Graph graph(5);

    // Graph visualization (undirected):
    //       (0)
    //      /   \
    //    (1)---(4)
    //   / │ \ / │
    // (2)─│─(3) │
    //     └─────┘

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2); 
    graph.addEdge(1, 3);
    graph.addEdge(1, 4); 
    graph.addEdge(2, 3); 
    graph.addEdge(3, 4);  

    int startNode = 0;

    cout << "DFS Traversal starting from vertex " << startNode << ": ";
    graph.dfs(startNode);
    cout << endl;

    return 0;
}
