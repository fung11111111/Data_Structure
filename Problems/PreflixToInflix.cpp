//
//  main.cpp
//  test
//
//  Created by Fung Lam on 16/7/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;


bool isOperator(char o){
    if(o == '+'){
        return true;
    }else if(o == '-'){
        return true;
    }else if(o == '/'){
        return true;
    }else if(o == '*'){
        return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    string orgStr = "*+AB-CD";
    stack<string> s;
   
    for(int i=orgStr.length()-1; i >=0; i--){
        
        if(isOperator(orgStr[i])){
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            
            string tmp = "(" + op1 + orgStr[i] + op2 + ")";
            s.push(tmp);
        }else{
            s.push(string(1,orgStr[i]));
        }
        
    }
    
    cout << s.top() << endl;
    return 0;
}
