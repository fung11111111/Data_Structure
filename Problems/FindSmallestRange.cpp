//
//  main.cpp
//  Solution
//
//  Created by Fung Lam on 28/7/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <climits>
using namespace std;

struct Item{
    int vNum, idx, val;
};
struct Comp{
    bool operator()(Item i1, Item i2){
        return i1.val > i2.val;
    }
};

pair<int, int> FindSmallestRange(vector<int> arr[], int k){
    
  
    int upper = INT_MIN;

    priority_queue<Item,vector<Item>,Comp> q;
    pair<int, int> p = {0,INT_MAX};

    for(int i=0;i<k;i++){
        q.push({i,0,arr[i][0]});
        upper = max(upper, arr[i][0]);
    }
    
    while(true){
        int lower = q.top().val;
        int vNum = q.top().vNum;
        int idx = q.top().idx;
        q.pop();
        
        if(upper-lower < p.second-p.first){
            p = {lower,upper};
        }
        if(idx == arr[vNum].size()-1){
            cout << "reach end of vector" <<endl;
            return p;
        }
    
        idx++;
        q.push({vNum, idx, arr[vNum][idx]});
        
        upper = max(upper, arr[vNum][idx]);
    }
    
 
}
int main(int argc, const char * argv[]) {
    
    
    
    vector<int> arr[] = {{3,6,8,10,15}, {1,5,12}, {4,8,15,16},{2,6}};
    pair<int, int> rng;
    rng = FindSmallestRange(arr, 4);
    
    cout << "the range is: " << rng.first << " to " << rng.second << endl;
    return 0;
}
