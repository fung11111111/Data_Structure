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

void NSortedArray(vector<int> &arr, int k){
    
    priority_queue<int, vector<int>,greater<int>> q (arr.begin(), arr.begin()+k+1);
 
    int idx = 0;
    for(int i=k+1;i<arr.size();i++){
        arr[idx++] = q.top();
        q.pop();
        q.push(arr[i]);
    }

    while (!q.empty()) {
        arr[idx++] = q.top();
        q.pop();
    }
   
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << endl;
    }
}
int main(int argc, const char * argv[]) {
    
    int arr[] = {1,4,5,2,3,7,8,6,10,9};
    int k = 2;
    vector<int> arrV(arr, arr+sizeof(arr)/sizeof(int));
    
    
    NSortedArray(arrV, k);
    
    return 0;
}
