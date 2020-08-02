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

void MergeNSortedLists(vector<int> arr[], int M){

    priority_queue<Item, vector<Item>, Comp> q;
    vector<int> sortedList;
    
    int total = 0;
    for(int i=0;i<M;i++){
        q.push({i,0,arr[i][0]});
        total += arr[i].size();
    }

    while(sortedList.size() < total){
        int min = q.top().val;
        int vNum = q.top().vNum;
        int idx = q.top().idx;

        sortedList.push_back(min);
        q.pop();

        idx++;

        if(idx < arr[vNum].size()){
            q.push({vNum, idx, arr[vNum][idx]});
        }


    }

    for(int i=0;i<sortedList.size();i++){
        cout << sortedList[i] <<endl;
    }

    cout << "total item in sortedList: " << sortedList.size() << endl;

}
int main(int argc, const char * argv[]) {
    
    
    
    vector<int> arr[] = {{10,20,30,40,50}, {15,25,35}, {27,29,37,60},{32,39,52},{16,38}};
    int M = sizeof(arr)/sizeof(arr[0]);

    MergeNSortedLists(arr, M);
    return 0;
}
