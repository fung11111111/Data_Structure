//
//  main.cpp
//  Solution
//
//  Created by Fung Lam on 28/7/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int FindKSmallest(vector<int> &arr, int k){
    
    priority_queue<int, vector<int>,less<>> q (arr.begin(), arr.begin()+k);
 
    
  
    // only 3 items in the heap every time
    for(int i=k;i<arr.size();i++){
        q.push(arr[i]);
        q.pop();
    }

    // only two items left in the heap, top will be larger than the smallest one
    return q.top();
}
int main(int argc, const char * argv[]) {
    
    int arr[] = {1,4,5,2,3,7,8,6,10,9};
    int k = 2;
    vector<int> arrV(arr, arr+sizeof(arr)/sizeof(int));
    
    
    int val = FindKSmallest(arrV, k);
    cout << val << endl;
    return 0;
}
