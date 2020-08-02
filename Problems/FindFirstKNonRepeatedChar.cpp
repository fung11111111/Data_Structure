//
//  main.cpp
//  Solution
//
//  Created by Fung Lam on 28/7/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <map>
#include <queue>

using namespace std;


void FindFirstKNonRepeatedChar(string s, int k){

    map<char, pair<int, int>> m;
    map<char, pair<int, int>>::iterator itr;
    for(int i=0;i<s.length();i++){
        m[s[i]].first = i;
        m[s[i]].second++;
    }
    
    priority_queue<int,vector<int>, greater<>> q;
    for(itr = m.begin();itr!=m.end();++itr){
        int idx = itr->second.first;
        int count = itr->second.second;
        
        if(count == 1){
            q.push(idx);
        }
    }
    while (!q.empty() && k--) {
        int top = q.top();
        q.pop();
        
        
        cout << s[top] << endl;
    }


}
int main(int argc, const char * argv[]) {
    
    string str = "ABCDEBACFGHIG";
    
    FindFirstKNonRepeatedChar(str, 3);
    
    return 0;
}
