//
//  main.cpp
//  ShortestPath
//
//  Created by Fung Lam on 19/7/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <utility>          // for std::pair<>
#include <iomanip>          // for std::setw()

using namespace std;
const int Max_Distance = 100;  // to pretend infiniti at the beigining
class Graph_SP{
private:
    int num_vertex;
    vector<std::list<std::pair<int,int>>> AdjList;
    vector<int> predecessor, distance;
public:
    Graph_SP():num_vertex(0){};
    Graph_SP(int n):num_vertex(n){
        AdjList.resize(num_vertex);
    }
    void AddEdge(int from, int to, int weight);
    void PrintDataArray(vector<int> array);
    
    void InitializeSingleSource(int Start);
    void Relax(int from, int to, int weight);
    bool BellmanFord(int Start = 0);
};

void Graph_SP::AddEdge(int from, int to, int weight){
    AdjList[from].push_back(make_pair(to, weight));
}

void Graph_SP::InitializeSingleSource(int Start){
    distance.resize(num_vertex);
    predecessor.resize(num_vertex);
    
    for (int i = 0; i < num_vertex; i++) {
        distance[i] = Max_Distance;
        predecessor[i] = -1;
    }
    distance[Start] = 0;
}

void Graph_SP::Relax(int from, int to, int weight){
    if(distance[to] > distance[from] + weight){
        distance[to] = distance[from] + weight;
        predecessor[to] = from;
    }
}

bool Graph_SP::BellmanFord(int Start){
    InitializeSingleSource(Start);
    
    for(int i=0;i<num_vertex-1;i++){   // according to BellmanFord max |V|-1 loop to find shortest path
        for(int j=0; j<num_vertex;j++){
            for(list<pair<int,int>>::iterator it = AdjList[j].begin(); it!=AdjList[j].end();++it){
                Relax(j, (*it).first, (*it).second);
            }
        }
    }
    
    // check negative cycle
    for (int i = 0; i < num_vertex; i++) {
           for (list<pair<int,int> >::iterator it = AdjList[i].begin();
                it != AdjList[i].end(); ++it) {
               if (distance[(*it).first] > distance[i]+(*it).second) {   // i是from, *itr是to
                   return false;
               }
           }
       }
    
    cout << "predecessor[]:\n";
    PrintDataArray(predecessor);
    cout << "distance[]:\n";
    PrintDataArray(distance);
    
    return true;
}

void Graph_SP::PrintDataArray(vector<int> array){
    for (int i = 0; i < num_vertex; i++){
         cout << "  " << i;
    }
       
    cout << endl;
    for (int i = 0; i < num_vertex; i++){
         cout << "  " << array[i];
    }
       
    cout << endl << endl;
}
int main(int argc, const char * argv[]) {
      Graph_SP g7(6);
      g7.AddEdge(0, 1, 5);
      g7.AddEdge(1, 4, -4);
      g7.AddEdge(1, 2, 6);
      g7.AddEdge(2, 4, -3);
      g7.AddEdge(2, 5, -2);
      g7.AddEdge(3, 2, 4);
      g7.AddEdge(4, 3, 1);
      g7.AddEdge(4, 5, 6);
      g7.AddEdge(5, 0, 3);
      g7.AddEdge(5, 1, 7);

      if (g7.BellmanFord(0))
          cout << "There is no negative cycle.\n";
      else
          cout << "There is negative cycle.\n";

      return 0;
}
