#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
    vector<list<int>> adj;
    vector<bool> visited;
    vector<int> arrival;
    vector<int> departure;
    int num; //num of vertex;
    int time;
public:
    Graph(int n): num(n),time(-1){
        adj.resize(n);
        visited.resize(n);
        arrival.resize(n);
        departure.resize(n);
    };
    
    void addEdge(int s, int d);
    void DFS(int s);
    void DFSChecker(int s);
    void printResult();
    
};
void Graph::addEdge(int s, int d){
    adj[s].push_back(d);
}
void Graph::DFSChecker(int s){
    int idx = s;
    for(int i=0;i<num;i++){
        if(!visited[idx]){
            DFS(idx);
        }
        idx = i;
    }
}
void Graph::DFS(int s){
    list<int>::iterator itr;
    visited[s] = 1;
    arrival[s] = ++time;
    
    for(itr = adj[s].begin(); itr!=adj[s].end();++itr){
        if(!visited[*itr]){
            visited[*itr] = 1;
            DFS(*itr);
        }
    }
    
    
    departure[s] = ++time;
    cout << "node: " << s << " arrival: " << arrival[s] << " departure: " << departure[s] << endl;
}
void Graph::printResult(){
    
}

int main(int argc, const char * argv[]) {
 
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(6, 7);
    
    g.DFSChecker(0);
    return 0;
}
