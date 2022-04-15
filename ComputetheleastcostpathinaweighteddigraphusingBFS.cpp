#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int source, dest, weight;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int x, int n)
    {
        // resize the vector to `3×n` elements of type `vector<int>`
        adjList.resize(3*n);
 
        // add edges to the directed graph
        for (auto &edge: edges)
        {
            int v = edge.source;
            int u = edge.dest;
            int weight = edge.weight;
 
            // create two new vertices, `v+n` and `v+2×n`, if the edge's weight is `3x`
            // Also, split edge (v, u) into (v, v+n), (v+n, v+2N) and (v+2N, u),
            // each having weight `x`.
            if (weight == 3*x)
            {
                adjList[v].push_back(v + n);
                adjList[v + n].push_back(v + 2*n);
                adjList[v + 2*n].push_back(u);
            }
 
            // create one new vertex `v+n` if the weight of the edge is `2x`.
            // Also, split edge (v, u) into (v, v+n), (v+n, u) each having weight `x`
            else if (weight == 2*x)
            {
                adjList[v].push_back(v + n);
                adjList[v + n].push_back(u);
            }
 
            // no splitting is needed if the edge weight is `1x`
            else {
                adjList[v].push_back(u);
            }
        }
    }
};
 
// Recursive function to print the path of a given vertex `v` from the source vertex
void printPath(vector<int> const &predecessor, int v, int &cost, int n)
{
    if (v < 0) {
        return;
    }
 
    printPath(predecessor, predecessor[v], cost, n);
    cost++;
 
    // only consider the original nodes present in the graph
    if (v < n) {
        cout << v << " ";
    }
}
 
// Perform BFS on the graph starting from vertex source
void findLeastPathCost(Graph const &graph, int source, int dest, int n)
{
    // stores vertex is discovered in BFS traversal or not
    vector<bool> discovered(3*n, false);
 
    // mark the source vertex as discovered
    discovered[source] = true;
 
    // `predecessor[]` stores predecessor information. It is used
    // to trace a least-cost path from the destination back to the source.
    vector<int> predecessor(3*n, -1);
 
    // create a queue for doing BFS and enqueue source vertex
    queue<int> q;
    q.push(source);
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and print it
        int curr = q.front();
        q.pop();
 
        // if destination vertex is reached
        if (curr == dest)
        {
            int cost = -1;
            cout << "The least-cost path between " << source << " and " <<
                dest << " is "; printPath(predecessor, dest, cost, n);
            cout << "having cost " << cost;
        }
 
        // do for every adjacent edge of the current vertex
        for (int v: graph.adjList[curr])
        {
            if (!discovered[v])
            {
                // mark it as discovered and enqueue it
                discovered[v] = true;
                q.push(v);
 
                // set `curr` as the predecessor of vertex `v`
                predecessor[v] = curr;
            }
        }
    }
}
 
int main()
{
    int x = 1;
 
    // vector of graph edges as per the above diagram
    vector<Edge> edges =
    {
        {0, 1, 3*x}, {0, 4, 1*x}, {1, 2, 1*x}, {1, 3, 3*x},
        {1, 4, 1*x}, {4, 2, 2*x}, {4, 3, 1*x}
    };
 
    // total number of nodes in the graph
    int n = 5;
 
    // given the source and destination vertex
    int source = 0, dest = 2;
 
    // build a graph from the given edges
    Graph graph(edges, x, n);
 
    // Perform BFS traversal from the given source
    findLeastPathCost(graph, source, dest, n);
 
    return 0;
}