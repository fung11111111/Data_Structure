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
#include <stack>
using namespace std;

class Graph{
    int numOfV; // number of vertex
    vector<list<int>> adj;
public:
    Graph(int numOfV);
    void addEdge(int f, int t); // from to
    void BFS(int s);// s is the starting node
    void DFS(int s, vector<bool> &visited);
    void DFSChecker(int s);
    
};
Graph ::Graph(int numOfV){
    this->numOfV = numOfV;
    adj.resize(numOfV);
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSChecker(int s){
    vector<bool> visited(numOfV,false);
    int idx = s;
    for(int i=0; i<numOfV;i++){
        if(!visited[idx]){
            DFS(idx, visited);
        }
        idx = i;
    }
}
void Graph::DFS(int s, vector<bool> &visited){
   
    list<int>::iterator itr;
    stack<int> stk;
    
    stk.push(s);
    while(!stk.empty()){
        int top = stk.top();
        stk.pop();
        if(!visited[top]){
            visited[top] = true;
            cout << top << " ";
        }
        for(itr=adj[top].begin();itr!=adj[top].end();++itr){
            if(!visited[*itr]){
                stk.push(*itr);
            }
        }
    }
    
}
void Graph::BFS(int s){
    vector<bool> visited(numOfV,false);
    list<int> q;
    list<int>::iterator itr;
    q.push_back(s);
    
    while (!q.empty()) {
        int start = q.front();
        visited[start] = true;
        q.pop_front();
        cout << start << " ";
        for(itr=adj[start].begin();itr!=adj[start].end();++itr){
            if(!visited[*itr]){
                visited[*itr] = true;
                q.push_back(*itr);
            }
        }
    
    }
    
    
}

int main(int argc, const char * argv[]) {
    
    
    
    Graph g2(8);
    g2.addEdge(0, 1);g2.addEdge(0, 2);
    g2.addEdge(1, 3);
    g2.addEdge(2, 1);g2.addEdge(2, 5);
    g2.addEdge(3, 4);g2.addEdge(3, 5);
    g2.addEdge(5, 1);
    g2.addEdge(6, 4);g2.addEdge(6, 7);
    g2.addEdge(7, 6);
    
    g2.DFSChecker(0);
    
    return 0;
}
