#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

    Graph(int V) : numVertices(V), adjList(V)
    {
    }
    void addEdge(int src, int dest, int weight = 1)
    {
        adjList[src].push_back(Node(dest, weight));
        if (!directed)
        {
            adjList[dest].push_back(Node(src, weight));
        }
    }
    void visualize()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << "Vertex " << i << ":";
            for (Node node : adjList[i])
            {
                cout << node.dest << "(" << node.weight << ") ";
            }
            cout << endl;
        }
    }
    void bfs(int startVertex)
    {
        queue<int> q;
        vector<bool> visited(numVertices, false);

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (Node node : adjList[curr])
            {
                if (!visited[node.dest])
                {
                    visited[node.dest] = true;
                    q.push(node.dest);
                }
            }
        }
    }
};

int main()
{
    Graph graph(5); 
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    int startNode = 0;

    cout << "BFS Traversal starting from vertex " << startNode << ": ";
    graph.bfs(startNode);
    cout << endl;

    // Graph visualization (undirected):
    //       (0)
    //      /   \
    //    (1)---(4)
    //   / │ \ / │
    // (2)─│─(3) │
    //     └─────┘
    
    return 0;
}
