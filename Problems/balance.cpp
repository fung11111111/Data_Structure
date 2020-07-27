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


int main(int argc, const char * argv[]) {
    
    string str = "{[()][]}";
    stack<char> s;
    bool balance = true;
    for(int i=0; i<str.length(); i++){
        
        if(str[i] == '{' || str[i] == '[' || str[i] == '('){
            s.push(str[i]);
        }else if(str[i] == ')'){
            if(s.top() != '('){
                balance = false;
            }
            s.pop();
        }else if(str[i] == ']'){
            if(s.top() != '['){
                balance = false;
            }
            s.pop();
        }
        else if(str[i] == '}'){
            if(s.top() != '{'){
                balance = false;
            }
            s.pop();
        }
        
    }

    cout << balance << endl;
    return 0;
}
