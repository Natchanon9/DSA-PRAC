#include <iostream>
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
    void removeEdge(int src, int dest)
    {
        adjList[src].remove_if([dest](Node &node)
                               { return node.dest == dest; });
        if (!directed)
        {
            adjList[dest].remove_if([src](Node &node)
                                    { return node.dest == src; });
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

    cout << "Adjacency List Representation:\n";
    graph.visualize();
    cout << "Adjacency List Representation with remove src to dest:\n";
    graph.removeEdge(1, 3);
    graph.visualize();

    return 0;
}

/*
Adjacency List Representation:

Vertex 0:1(1) 4(1)
Vertex 1:0(1) 2(1) 3(1) 4(1)
Vertex 2:1(1) 3(1)
Vertex 3:1(1) 2(1) 4(1)
Vertex 4:0(1) 1(1) 3(1)

Adjacency List Representation with remove src to dest:

Vertex 0:1(1) 4(1)
Vertex 1:0(1) 2(1) 4(1)
Vertex 2:1(1) 3(1)
Vertex 3:2(1) 4(1) 
Vertex 4:0(1) 1(1) 3(1) 
*/