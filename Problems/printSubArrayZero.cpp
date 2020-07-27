//
//  main.cpp
//  test
//
//  Created by Fung Lam on 16/7/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void printAllSubArr(vector<int> &arr){
    
    vector<int> idxSet;
    
    for(int i=0; i<arr.size(); i++){
        int sum =0;
        for(int j=i; j< arr.size(); j++){
            sum += arr[j];
            if(sum ==0){
                int count = i;
                while (count <= j) {
                    idxSet.push_back(arr[count]);
                    count ++;
                }
            }
        }
        for(int k=0; k<idxSet.size();k++){
            cout << idxSet[k] << " ";
            if(k == idxSet.size()-1){
                cout << endl;
            }
        }
        idxSet.clear();
    }
}
int main(int argc, const char * argv[]) {
    
    int arr[] = {4,2,-3,-1,0,4};
    
    vector<int> arrV(arr, arr+sizeof(arr)/sizeof(int));
    printAllSubArr(arrV);
    
    
    return 0;
}
