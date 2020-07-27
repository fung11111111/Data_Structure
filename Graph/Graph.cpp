//
//  main.cpp
//  Graph
//
//  Created by Fung Lam on 16/6/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
private:
    int num_vertex;
    vector<list<int>> AdjList;
    
    void DFSUtil(int Start, bool visited[]);
public:
    Graph():num_vertex(0){};           // default constructor
    Graph(int N):num_vertex(N){        // constructor with input: number of vertex
        // initialize Adjacency List
        AdjList.resize(num_vertex);
    };
    void AddEdgeList(int from, int to);
    void BFS(int Start);
    void DFS(int Start);
};

void Graph::AddEdgeList(int from, int to){
    AdjList[from].push_back(to);
    
}
void Graph::BFS(int Start){
    // Mark all the vertices as not visited
    bool *visited = new bool[num_vertex];
    for(int i = 0; i < num_vertex; i++)
        visited[i] = false;
    
    // Create a queue for BFS
    list<int> queue;
    
    // Mark the current node as visited and enqueue it
    visited[Start] = true;
    queue.push_back(Start);
    
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        Start = queue.front();
        cout << Start << " ";
        queue.pop_front();
        
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = AdjList[Start].begin(); i != AdjList[Start].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
        
    }
}
void Graph::DFSUtil(int Start, bool *visited){
    visited[Start] = true;
    cout << Start << " ";
    
    list<int>::iterator i;
    for (i = AdjList[Start].begin(); i != AdjList[Start].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
void Graph::DFS(int Start){
    bool *visited = new bool[Start];
       for (int i = 0; i < Start; i++)
           visited[i] = false;
     
       DFSUtil(Start, visited);
}
int main(int argc, const char * argv[]) {
    Graph g(4);
    g.AddEdgeList(0, 1);
    g.AddEdgeList(0, 2);
    g.AddEdgeList(1, 2);
    g.AddEdgeList(2, 0);
    g.AddEdgeList(2, 3);
    g.AddEdgeList(3, 3);
    
    g.DFS(3);
    
    
    return 0;
}

