//
//  main.cpp
//  Solution
//
//  Created by Fung Lam on 28/7/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Interval{
    int start, end;
};

void MergeOverLappedInterval(vector<Interval> &arr){
    stack<Interval> s1;
    
    for(int i=0;i<arr.size();i++){
        if(s1.empty() || s1.top().end < arr[i].start){
            s1.push(arr[i]);
        }else{
            if(s1.top().end < arr[i].end){
                int start = s1.top().start;
                s1.pop();
                s1.push({start,arr[i].end});
            }
            
        }
    }
    while (!s1.empty()) {
        cout << s1.top().start << " and " << s1.top().end << endl;
        s1.pop();
    }
    
    
}
int main(int argc, const char * argv[]) {
    
    vector<Interval> intervalList =  {{1,5}, {2,3}, {4,6}, {7,8}, {8,10}, {12,15}};
    
   
    MergeOverLappedInterval(intervalList);
    
    return 0;
}
