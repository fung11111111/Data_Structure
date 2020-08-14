#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct edge{
    int src, des;
};
class Graph{
    vector<list<int>> adj;
    vector<bool> visited;

    int num; //num of vertex;
public:
    Graph(int n): num(n){
        adj.resize(n);
        visited.resize(n);
     
    };
    
    void addEdge(vector<edge> v);
    bool BFS(int s);
   
    
};
void Graph::addEdge(vector<edge> v){
    for(int i=0;i<v.size();i++){
        int s = v[i].src;
        int d = v[i].des;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
}
bool Graph::BFS(int s){
    visited[s] = 1;
    vector<int> level(num);
    level[s] = 0;
    list<int>::iterator itr;
    queue<int> q;
    q.push(s);
    bool isBiG = 1;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for(itr=adj[front].begin();itr!=adj[front].end();++itr){
            if(!visited[*itr]){
                visited[*itr] = 1;
                level[*itr] = level[front] +1;
                q.push(*itr);
            }else if(level[*itr] == level[front]){
                isBiG = 0;
                break;
            }
            
        }
    }
    
    
    
    return isBiG;
}



int main(int argc, const char * argv[]) {
 
    vector<edge> e = {{0,1},{0,2},{1,3},{2,4},{3,4}};
    Graph g(5);
    g.addEdge(e);
    
    if(g.BFS(0)){
        cout << "True" <<endl;
    }else{
        cout << "False" <<endl;
    }
    
    return 0;
}
