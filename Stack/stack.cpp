//
//  main.cpp
//  Stack
//
//  Created by Fung Lam on 21/5/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
    char data;
    Node *next;
public:
    Node(): data(0), next(0){};
    Node(char data):data(data), next(0){};
    Node(char data, Node* next):data(data), next(next){};
    friend class stackList;
};
class stackList{
    Node *top;
    int size;
public:
    stackList(): top(0), size(0){};
    void push(char data);
    void pop();
    void printList();
    bool isEmpty();
    int getSize();
    void checkBalance(string exp);
    void sortCharters(string exp);
    char getTop();
    void compareList();
};
int stackList::getSize(){
    return size;
}
bool stackList::isEmpty(){
    return (size == 0);
}
void stackList::push(char data){
    Node *n = new Node(data);
    if (isEmpty()){
        top = n;
    }else{
        n->next = top;
        top = n;
    }
    size ++;
}
void stackList::pop(){
   
    if (isEmpty()){
        cout << "there is no node" << endl;
    }else{
        Node *pop;
        pop = top;
        delete pop;
        pop = 0;
        top = top->next;
        size --;
    }
}
void stackList::printList(){
    Node *current = top;
    if (isEmpty()){
        cout << "there is no node" << endl;
    }else{
        while(current !=0 ){
               cout << "node: " << current->data << endl;
               current = current->next;
           }
    }
   
}

 char stackList::getTop(){
     if(isEmpty()){
         cout << "there is no node" << endl;
         return -1;
     }
    return top->data;
}
void stackList::checkBalance(string exp){
    bool balance = true;
    if (exp.length() == 0){
        cout << "there is no nodes" << endl;
        balance = false;
    }
    for(int i=0;i<exp.length();i++){
        if(exp[i] == '[' || exp[i] == '{' || exp[i] == '('){
            push(exp[i]);
        }else{
            if(isEmpty()){
                cout << "there is no nodes" << endl;
                balance = false;
                break;
            }else{
                if (exp[i] == ')'){
                    char tmp = top->data;
                    if(tmp != '('){
                        balance = false;
                        break;
                    }else{
                        pop();
                    }
                }else if(exp[i] == ']'){
                    char tmp = top->data;
                    if(tmp != '['){
                        balance = false;
                        break;
                    }else{
                        pop();
                    }
                }else if(exp[i] == '}'){
                    char tmp = top->data;
                    if(tmp != '{'){
                        balance = false;
                        break;
                    }else{
                        pop();
                    }
                }
            }
            
        }
            
        
    }
    if(balance){
        cout << "It is balance" << endl;
    }else{
        cout << "It is not balance" << endl;
    }
    
}

void stackList::sortCharters(string exp){
    
}
int main(int argc, const char * argv[]) {
   
    stackList list, tmplist;
    string exp = "avsdbvd";
    list.push(exp[0]);
    for(int i=1;i<exp.length();i++){
        while(list.isEmpty() == false && exp[i] > list.getTop()){
            tmplist.push(list.getTop());
            list.pop();
        }
        list.push(exp[i]);
        while(tmplist.isEmpty() == false){
            list.push(tmplist.getTop());
            tmplist.pop();
        }
    }
    
    list.printList();
   
    tmplist.printList();
   
  
    return 0;
}
