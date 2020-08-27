#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d): data(d), left(0), right(0){};
    

};

Node* constructUtil(vector<int> pre, vector<int>in, int s, int e, int *preIdx){
    
    if(s > e){
        return NULL;
    }
    
    Node *root = new Node(pre[*preIdx]);
    ++*preIdx;
    
    if(s == e){
        return root;
    }
    int i;
    for(i=s;i<=e;i++){
        if(in[i] == root->data){
            break;
        }
    }
    root->left = constructUtil(pre, in, s, i-1, preIdx);
    root->right = constructUtil(pre, in, i+1, e, preIdx);
    return root;
}

void printPostOrder(Node* n){
    if(n == NULL){
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->data << " ";
}
int main(int argc, const char * argv[]) {

    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> in = {4,7,2,1,5,3,8,6};
   
    int preIdx =0;

    Node* r = constructUtil(pre, in, 0, pre.size()-1, &preIdx);
    printPostOrder(r);

    cout << endl;
    return 0;
}
