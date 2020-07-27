//
//  main.cpp
//  C++
//
//  Created by Fung Lam on 14/5/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
using namespace::std;

class Node{
private:
    int data;
    Node * next;
    
public:
    Node():data(0), next(0){};
    Node(int data): data(data), next(0){};
    friend class LinkList;
};

class LinkList{
    Node * head;
    Node * last;
public:
    
    LinkList():head(0), last(0){};
  
    void printList();
    void countNode();
    void push(int data);
    void pushBack(int data);
    void deletion(int data);
    void reverse();
    void printCircular();
};


void LinkList::printList(){
    if (head == 0){
        cout << "there is no nodes!" << endl;
        return;
    }
    Node * current = head;
    while (current != 0) {
        cout << "node: " << current->data << endl;
        current = current->next;
    }
}
void LinkList::countNode(){
    int counter = 0;
    if (head == 0){
        counter = 0;
    }else{
        Node *current = head;
        counter++;
        while(current->next !=0){
            current = current->next;
            counter++;
        }
    }
    cout << "there is " << counter << " nodes." << endl;
}
void LinkList::push(int data){
    Node * n = new Node(data);
    
    n->next = head;
    head = n;
    
}
void LinkList::pushBack(int data){
    Node * n = new Node(data);
   
    if (head == 0){
        head = n;
        last = n;
        return;
    }
    last -> next = n;
    n ->next = head;
    last = n;
    
}
void LinkList::printCircular(){
    if (head == 0){
        cout << "there is no node;" << endl;
        return;
    }
   
    Node *current = head;
    while(current != last){
        cout << "node: " << current->data <<endl;
        current = current->next;
    }
    cout << "node: " << last->data <<endl;
    
}
void LinkList::deletion(int data){
    Node * current = head;
    Node * pre = 0;
    
    while(current->data != data && current->next != 0){
        pre = current;
        current = current->next;
    }
    if(current->next == 0 && current->data != data){
        cout << "there is no target item" << endl;
    }else if(current == head){
        head = current-> next;
        delete current;
        current = head;
    }else{
        pre->next = current->next;
        delete current;
        current = current-> next;
    }
    
}
void LinkList::reverse(){
    
    if(head == 0 || head->next ==0 ){return;}
    Node *pre = 0;
    Node *current = head;
    Node *preceding = head->next;
    
    while(preceding != 0){
        current->next = pre;
        pre = current;
        current = preceding;
        preceding = current->next;
        
    }
    current->next = pre;
    head = current;
    
}
int main(int argc, const char * argv[]) {
    
    LinkList list;
    list.pushBack(30);
    list.pushBack(20);
    list.pushBack(32);
    list.pushBack(11);
    list.pushBack(15);
    list.pushBack(2);
    list.push(1);
    list.printCircular();


    return 0;
}
