#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

void miniMaxSum(vector<int> arr) {
    
    vector<int> v = arr;
    sort(v.begin(), v.begin()+arr.size());
   
    
    int64_t min =0;
    int64_t max = 0;
    for(int i=0;i<v.size();i++){
       
        if(i !=0){
            max += v[i];
        }
        if(i != v.size()-1){
            min += v[i];
        }
    }
    
    cout << min << " " << max;

}
        
int main(int argc, const char * argv[]) {
    
    int arr[] = {793810624,895642170,685903712,623789054,468592370};
    vector<int> arrV(arr, arr+ sizeof(arr)/sizeof(int));
    
    
    miniMaxSum(arrV);
    
    
    return 0;
}
