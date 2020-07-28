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

void FindRepeatMost(vector<int> &arr){
    map<int,int> hashmap;
    map<int,int>::iterator itr;
    for(int i=0;i<arr.size();i++){
        if(hashmap.find(arr[i]) != hashmap.end()){
            hashmap[arr[i]] += 1;
        }else{
            hashmap[arr[i]] = 1;
        }
    }
    
    int maxVal = 0;
    int maxEle = 0;
    for(itr = hashmap.begin(); itr!=hashmap.end(); itr++){
        if(itr->second >maxVal){
            maxVal = itr->second;
            maxEle = itr->first;
        }
    }
  
    cout << "The repeat most element is: " << maxEle << endl;
  
   
}
int main(int argc, const char * argv[]) {
    
    
    int arr[] = {2,8,7,2,2,5,3,1,4,2,8,3};
   
    
    vector<int> arrV(arr, arr+sizeof(arr)/sizeof(int));
    FindRepeatMost(arrV);
 
    return 0;
}
