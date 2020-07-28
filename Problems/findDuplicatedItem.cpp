#include <iostream>
#include <vector>

using namespace std;

void FindDuplicatedItem(vector<int> &arr){
    vector<bool> visited(arr.size(), false);
    for(int i=0;i<arr.size();i++){
        if(visited[arr[i]]){
            cout << arr[i] << " is duplicated" << endl;
        }
        visited[arr[i]] = true;
    }
  
}
int main(int argc, const char * argv[]) {
    
    
    int arr[] = {1,2,3,4,4,5,6,2};
    
    vector<int> arrV(arr, arr+sizeof(arr)/sizeof(int));
    FindDuplicatedItem(arrV);
    
    return 0;
}