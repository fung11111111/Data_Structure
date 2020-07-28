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

void FindGivenSum(vector<int> &arr, int givenSum){
    map<int,int> list;
    
    for(int i=0;i<arr.size();i++){
        if(list.find(givenSum-arr[i]) != list.end()){
            cout << givenSum-arr[i] << " and " << arr[i] << endl;
        }else{
            list[arr[i]] = arr[i];
        }
        
    }
  
    
    
   
}
int main(int argc, const char * argv[]) {
    
    
    int arr[] = {8,7,2,5,3,1,4};
    int sum = 10;
    
    vector<int> arrV(arr, arr+sizeof(arr)/sizeof(int));
    FindGivenSum(arrV, sum);
 
    return 0;
}
