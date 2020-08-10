//
//  main.cpp
//  problem
//
//  Created by Fung Lam on 10/8/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main(int argc, const char * argv[]) {
    int T = 0;
    int N = 0;
    int wall =0;
    
    stack<int> s;
    vector<pair<int, int>> v;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int up =0;
        int down = 0;
        cin >> N;
        for(int j=0;j<N;j++){
            cin >> wall;
            if(!s.empty()){
                if(wall > s.top()){
                    up++;
                }
                if(wall < s.top()){
                    down++;
                }
            }
            s.push(wall);
            
        }
        v.push_back({up,down});
        while (!s.empty()) {
            s.pop();
        }
    }
    for(int i=0;i<v.size();i++){
        cout << "case " << i << " :"<<v[i].first << " " << v[i].second << endl;
    }
    
    
    return 0;
}
