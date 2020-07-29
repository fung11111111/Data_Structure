//
//  main.cpp
//  Solution
//
//  Created by Fung Lam on 28/7/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;


void DecodeSequence(string exp){
    stack<char> s1;
    string str = "";
    for(int i=0;i<=exp.length();i++){
        s1.push(i+1);
        if(exp[i] == 'I' || i == exp.length()){
            while(!s1.empty()){
                str += to_string(s1.top());
                s1.pop();
            }
        }
        
    }
    cout << str << endl;
   
}
int main(int argc, const char * argv[]) {
    
    
    string exp = "IIDDDI";
    
    DecodeSequence(exp);
    
    
    
    return 0;
}
