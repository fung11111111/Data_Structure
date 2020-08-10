//
//  main.cpp
//  problem
//
//  Created by Fung Lam on 10/8/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    int T = 0;
    int N = 0;
    int wall =0;
    
    vector<pair<int, int>> v;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int up =0;
        int down = 0;
        cin >> N;
        int top = -1;
        for(int j=0;j<N;j++){
            cin >> wall;
            
            if(top > 0){
                if(wall > top){
                    up++;
                }
                if(wall < top){
                    down++;
                }
            }
            top = wall;
            
        }
        v.push_back({up,down});
     
    }
    for(int i=0;i<v.size();i++){
        cout << "case " << i+1 << " :"<<v[i].first << " " << v[i].second << endl;
    }
    
    
    return 0;
}
