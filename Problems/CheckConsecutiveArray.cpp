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

void CheckConsecutiveInt(vector<int> &arr){
    map<int,int> hashmap;
    map<int,int>::iterator itr;
    for(int i=0;i<arr.size();i++){
        if(hashmap.find(arr[i]) != hashmap.end()){
            cout << "The integer is repeated." << endl;
            return;
        }else{
            hashmap[arr[i]] = arr[i];
        }
    }
    
    int num = hashmap.begin()->second;
    for(itr = hashmap.begin(); itr!=hashmap.end();++itr){
        if(itr->second != num){
            cout << "it is not consecutive" << endl;
            return;
        }
        num ++;
    }
    cout << "It is a consecutive array" <<endl;
}
int main(int argc, const char * argv[]) {
    
    
    int arr[] = {1,2,4,0,-1,6,3,5};
   
    
    vector<int> arrV(arr, arr+sizeof(arr)/sizeof(int));
    CheckConsecutiveInt(arrV);
  
    return 0;
}
