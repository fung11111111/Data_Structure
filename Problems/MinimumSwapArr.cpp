#include <iostream>
#include <vector>

using namespace std;

bool checkSorted(vector<int> arr){
    for(int i=0; i<arr.size();i++){
        if(arr[i] == i+1){
            continue;
        }
        return false;
    }
    return true;
}
int FindMinSwap(vector<int> arr) {
    vector<bool> visited;
    for(int i=0;i<arr.size();i++)
        visited.push_back(false);
    int count =0;
    int idx =0;
    
    int rechCount = 0;
    if(checkSorted(arr)){
        return 0;
    }
    while(rechCount < visited.size()){
        if(arr[idx] == idx+1){
            visited[idx] = true;
            for(int i= 0;i<visited.size();i++){
                if(!visited[i]){
                    idx = i;
                    break;
                }
            }
            
        }else{
            int nextIdx = arr[idx] -1;
            int nexVal = arr[nextIdx];
            arr[nextIdx] = arr[idx];
            arr[idx] = nexVal;
            visited[nextIdx] = true;
            count++;
        }
        rechCount++;
    }
    
    cout << "minimum swap " << count << endl;
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    
    return count;
    
    // better solution
//    int i,c=0,n=arr.size();
//    for(i=0;i<n;i++)
//    {
//        if(arr[i]==(i+1))
//            continue;
//
//        swap(arr[i],arr[arr[i]-1]);
//        c++;
//        i--;
//    }
//    return c;
    
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {1,3,5,2,4,6,7};
    vector<int> arrV(arr, arr+ sizeof(arr)/sizeof(int));
    
    int k = FindMinSwap(arrV);
    
    
    
    
    return 0;
}
