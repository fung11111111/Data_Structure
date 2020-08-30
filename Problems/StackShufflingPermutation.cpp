#include <iostream>
#include <vector>
#include <stack>
using namespace std;

        
void findPermutation(vector<int>per, vector<int> arr){
    stack<int> s, a, b;
    bool result = true;
    for(int i=0;i<arr.size();i++){
        a.push(arr[i]);
    }

    int idx =0;
    while (!a.empty()) {
        s.push(a.top());
        a.pop();
        if(s.top() == per[idx]){
            b.push(s.top());
            s.pop();
            idx++;
        }
    }
   
    while (!s.empty()) {
        b.push(s.top());
        s.pop();
    }
    
    idx = per.size()-1;
    while (!b.empty()) {
        if(b.top() != per[idx]){
            result = false;
            break;
        }else{
            result = true;
        }
        idx--;
        b.pop();
    }
    if(result){
        cout << "Aye" <<endl;
    }else{
        cout << "Impossible" <<endl;
    }
}

int main(int argc, const char * argv[]) {
    
    int t = 0;
    int n = 0;
    int m = 0;
    int data = 0;
    vector<vector<int>> per;
    vector<vector<int>> arr;
    cin >> t;
    cin >> n;
    arr.resize(t);
    
    for(int i=0;i<t;i++){
        for(int j=0;j<n;j++){
            cin >> data;
            arr[i].push_back(data);
        }
    }
    cin >> m;
    per.resize(m);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> data;
            per[i].push_back(data);
        }
    }


    for(int i=0;i<arr.size();i++){
        for(int j=0; j<per.size();j++){
            findPermutation(per[j], arr[i]);
        }
    }
  

    return 0;
}
