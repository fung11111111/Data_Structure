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


void FindDuplicatedParenthesis(string exp){
    stack<char> expStack;
    for(int i=0;i<exp.length();i++){
        if(!expStack.empty()){
            if(exp[i] == '('){
                if(expStack.top() != ')'){
                    cout << "It is duplicated" <<endl;
                    return;
                }
            }
        }
        
        if(exp[i] == '(' || exp[i] == ')'){
            expStack.push(exp[i]);
        }
    }
    cout << "It is not duplicated" << endl;
}
int main(int argc, const char * argv[]) {
    
    
    string exp = "(a+b+(d))+(c)";
    
    FindDuplicatedParenthesis(exp);
    
    
    
    return 0;
}
