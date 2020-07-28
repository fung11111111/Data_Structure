//
//  main.cpp
//  Solution
//
//  Created by Fung Lam on 28/7/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void LongestConsecutiveInt(vector<int> &arr){
    map<int,int> hashmap;
    map<int,int>::iterator itr;
    for(int i=0;i<arr.size();i++){
        hashmap[arr[i]] = arr[i];
    }
   
    int count = 0;
    int max = 0;
    int endIdx;
    for(itr=hashmap.begin(); itr!=hashmap.end();++itr){
        int con = itr->second+1;
        if(hashmap.find(con) != hashmap.end()){
            count++;
            if(count > max){
                max = count;
                endIdx = con;
            }
        }else{
            count = 0;
        }
        
    }
   
    int start = endIdx - max;
    cout << "The largest consecutive integer set: ";
    while(start <= endIdx){
        cout << hashmap[start] << " ";
        start++;
    }
    cout << endl;
}
int main(int argc, const char * argv[]) {
    
    
    int arr[] = {0,1,3,6,8,5,9,10,11,2,4};
    
    
    vector<int> arrV(arr, arr+sizeof(arr)/sizeof(int));
    LongestConsecutiveInt(arrV);
    
    return 0;
}
