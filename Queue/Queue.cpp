//
//  main.cpp
//  Queue
//
//  Created by Fung Lam on 20/7/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct Queue{
    stack<int> s1, s2;
    
    void enQueue(int val){
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        
    }
    int deQueue(){
        if(s1.empty()){
            cout << "there is nothing in the queue" << endl;
            exit(0);
        }else{
            int val = s1.top();
            s1.pop();
            return val;
        }
    }
    
};
int main(int argc, const char * argv[]) {
    Queue q;
    q.enQueue(2);
    q.enQueue(4);
    q.enQueue(6);
    q.enQueue(8);
    
    cout << q.deQueue() << endl;
    return 0;
}
