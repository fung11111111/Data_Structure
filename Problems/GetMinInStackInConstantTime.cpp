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

class Stack{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int val);
    void pop();
    int getMin();
};

void Stack::push(int val){
    s1.push(val);
    if(!s2.empty()){
        if(val < s2.top()){
            s2.push(val);
        }
    }else{
        s2.push(val);
    }
}
int Stack::getMin(){
    return s2.top();
}
void Stack::pop(){
    if(s1.top() == s2.top()){
        s1.pop();
        s2.pop();
    }else{
        s1.pop();
    }
}

int main(int argc, const char * argv[]) {
    Stack s;
    s.push(6);
    cout << "the min is " << s.getMin() << endl;
    s.push(7);
    cout << "the min is " << s.getMin() << endl;
    s.push(8);
    cout << "the min is " << s.getMin() << endl;
    s.push(5);
    cout << "the min is " << s.getMin() << endl;
    s.push(3);
    cout << "the min is " << s.getMin() << endl;
    s.pop();
    s.push(10);
    cout << "the min is " << s.getMin() << endl;
    s.pop();
    s.pop();
    cout << "the min is " << s.getMin() << endl;
    
    return 0;
}
