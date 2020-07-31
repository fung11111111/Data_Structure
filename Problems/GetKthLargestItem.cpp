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

int GetKthLargestItem(vector<int> &arr, int k){
    
    priority_queue<int, vector<int>,greater<int>> q (arr.begin(), arr.begin()+k);
    
    for(int i=k;i<arr.size();i++){
        if(arr[i] > q.top()){
            q.pop();
            q.push(arr[i]);
        }
    }
    
    return q.top();
}
int main(int argc, const char * argv[]) {
    
    int arr[] = {6,5,7,3,1,};
    int k = 3;
    vector<int> arrV(arr, arr+sizeof(arr)/sizeof(int));
    
    int val = GetKthLargestItem(arrV, k);
    
    cout << val << endl;
    
    
    
    return 0;
}
