//
//  main.cpp
//  BinaryTree
//
//  Created by Fung Lam on 22/5/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class TreeNode{
    
public:
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode *parent;
    string str;
    int key;
    TreeNode(): leftChild(0),rightChild(0),parent(0),key(0), str(""){};
    TreeNode(string str, int key):leftChild(0),rightChild(0),parent(0), str(str), key(key){};
    
    int getKey(){return key;}
    string getElement(){return str;}
    friend class BinaryTree;
};
class BinaryTree{
    
public:
    TreeNode *root;
    BinaryTree(): root(0){};
    BinaryTree(TreeNode *n): root(n){};
    
    void preOderTraverse(TreeNode *current);
    void inOrderTraverse(TreeNode *current);
    void postOrderTraverse(TreeNode *current);
    
    TreeNode *leftMost(TreeNode *current);
    TreeNode *rightMost(TreeNode *current);
    TreeNode *inorderSuccessor(TreeNode *current);
    TreeNode *inorderPredecessor(TreeNode *current);
    TreeNode *search(int key);
    void byParent(TreeNode *root);
    void reverse(TreeNode *root);
    void insert(int key, string str);
    void deleteNode(int key);
};
void BinaryTree::deleteNode(int key){
    TreeNode* deleteNode = search(key);
    if(deleteNode == NULL){
        cout << "there is no node to delete!" << endl;
        return;
    }
    TreeNode* target = 0;
    TreeNode* nextChild = 0;
    if(deleteNode->leftChild == NULL || deleteNode->rightChild == NULL){
        target = deleteNode;
    }else{
        target = inorderSuccessor(deleteNode);
    }
    
    if(target->leftChild != NULL){
        nextChild = target->leftChild;
    }else{
        nextChild = target->rightChild;
    }
    
    if(nextChild != NULL){
        nextChild->parent = target->parent;
    }
    
    if(target->parent == NULL){
        this->root = nextChild;
    }else if(target == target->parent->leftChild){
        target->parent->leftChild = nextChild;
    }else{
        target->parent->rightChild = nextChild;
    }
    
    if(target!= deleteNode){
        deleteNode->key = target->key;
        deleteNode->str = target->str;
    }
    
    delete target;
    target = 0;
}
void BinaryTree:: preOderTraverse(TreeNode *current){
    if(current){
        cout << current->str << " ";
        preOderTraverse(current->leftChild);
        preOderTraverse(current->rightChild);
    }
    
}
void BinaryTree:: inOrderTraverse(TreeNode *current){
    if(current){
        inOrderTraverse(current->leftChild);
        cout<< current->str << " ";
        inOrderTraverse(current->rightChild);
    }
}
void BinaryTree:: postOrderTraverse(TreeNode *current){
    if(current){
        postOrderTraverse(current->leftChild);
        postOrderTraverse(current->rightChild);
        cout << current->str << " ";
    }
}
void BinaryTree::insert(int key, string str){
    TreeNode* newNode = new TreeNode(str, key);
    TreeNode* newParent = 0;
    TreeNode* mov = 0;
    
    mov = root;
    while(mov != NULL){
        newParent = mov;
        if(newNode->key < mov->key){
            mov = mov->leftChild;
        }else{
            mov = mov->rightChild;
        }
    }
    
    newNode->parent = newParent;
    if(newParent == NULL){
        root = newNode;
    }else if(newNode->key < newParent->key){
        newParent->leftChild = newNode;
    }else{
        newParent->rightChild = newNode;
    }
}
TreeNode* BinaryTree:: search(int key){
    TreeNode *current = root;
    
    while(current != NULL && current->key != key){
        if(key < current->key){
            current = current->leftChild;
        }else{
            current = current->rightChild;
        }
    }
    return current;
}
TreeNode* BinaryTree:: leftMost(TreeNode *current){
    while (current->leftChild != NULL) {
        current = current->leftChild;
    }
    return current;
}
TreeNode* BinaryTree:: inorderSuccessor(TreeNode *current){
    if (current->rightChild != NULL){
        return leftMost(current->rightChild);
    }
    
    // 利用兩個pointer: successor與current做traversal
    
    TreeNode *successor = current->parent;
    while (successor != NULL && current == successor->rightChild) {
        current = successor;
        successor = successor->parent;
    }
    return successor;
}
void BinaryTree:: byParent(TreeNode *root){
    TreeNode *current = new TreeNode;
    current = leftMost(root);
    
    while(current){
        cout << current->str << " ";
        current = inorderSuccessor(current);
    }
}
int main(int argc, const char * argv[]) {
    
    BinaryTree t;
    t.insert(20, "Alex");
    t.insert(17, "Mandy");
    t.insert(27, "May");
    t.insert(21, "Zoe");
    t.insert(19, "Tina");
    t.byParent(t.root);
    cout << endl;
   
    t.deleteNode(17);
    t.byParent(t.root);
    cout << endl;
    return 0;
}
