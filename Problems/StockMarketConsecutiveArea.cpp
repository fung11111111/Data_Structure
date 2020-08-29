#include <iostream>
#include <vector>

using namespace std;


void findMaxArea(vector<long> arr){
    
    long max =0;
   
    vector<pair<long, long>> idxP;
    for(long i=0;i<arr.size();i++){
        long lIdx = -1;
        long hIdx = arr.size();
        for(long j=0; j<arr.size();j++){
            if(j < i && arr[j] < arr[i]){
                lIdx = j;
            }else if(j > i && arr[j] < arr[i]){
                hIdx = j;
                break;
            }
        }
        idxP.push_back({lIdx, hIdx});
        
    }
    
    for(int i=0;i<idxP.size();i++){
        long tmpSum = 0;
        long start = idxP[i].first+1;
        long end = idxP[i].second;
        
        tmpSum = arr[i] * (end - start);
        if(tmpSum >= max){
            max = tmpSum;
        }
    }
    cout << max << endl;
}
int main(int argc, const char * argv[]) {
    
    int t;
    long n;
    long p;
    long idx =0;
    cin >> t;
    vector<vector<long>> arr;
    arr.resize(t);
    while(t-- > 0){
        cin >> n;
        arr[idx].resize(n);
        while(n-- > 0){
            cin >> p;
            arr[idx].push_back(p);
        }
        idx++;
    }
    for(int i=0;i<arr.size();i++){
        findMaxArea(arr[i]);
    }

    

    return 0;
}
