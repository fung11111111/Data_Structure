#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

int binarySearch(vector<int> arr, int key){
    int lo = 0;
    int hi = arr.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key && key < arr[mid - 1]) {
            return mid;
        } else if (arr[mid] > key && key >= arr[mid + 1]) {
            return mid + 1;
        } else if (arr[mid] < key) {
            hi = mid - 1;
        } else if (arr[mid] > key) {
            lo = mid + 1;
        }
    }
    return -1;
    
    return key;
}
// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    
    stack<unsigned long> s1,tmps;
    vector<int> rankWithIdx;
    vector<int> rankV;
    rankWithIdx.push_back(1);
    for(int i=1;i<scores.size();i++){
        if(scores[i] == scores[i-1]){
            rankWithIdx.push_back(rankWithIdx[i-1]);
        }else{
            rankWithIdx.push_back(rankWithIdx[i-1]+1);
        }
    }
 
    
    for (int i = 0; i < alice.size(); i++) {
        int as = alice[i];
        if(as > scores[0]){
            rankV.push_back(1);
        }else if(as < scores[scores.size()-1]){
            rankV.push_back(rankWithIdx[rankWithIdx.size()-1]+1);
        }else{
            int idx = binarySearch(scores, as);
            rankV.push_back(rankWithIdx[idx]);
        }
    }
   

    return rankV;
}

// Using stack cannot handle lage input within time limit
//vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
//
//    stack<unsigned long> s1,tmps;
//
//    vector<int> rankV;
//    for(int i= scores.size()-1; i>=0;i--){
//        if(s1.empty() || scores[i] >s1.top()){
//            s1.push(scores[i]);
//        }
//    }
//    for (int i=0; i<alice.size(); i++) {
//        tmps = s1;
//        int rnk = 1;
//        while(!tmps.empty() && alice[i] <tmps.top()){
//            rnk++;
//            tmps.pop();
//        }
//        rankV.push_back(rnk);
//    }
//
//    return rankV;
//}

int main()
{
    
    vector<int> scores, alice;
    scores.push_back(100);
    scores.push_back(90);
    scores.push_back(90);
    scores.push_back(80);
    scores.push_back(75);
    scores.push_back(60);
    
    alice.push_back(50);
    alice.push_back(65);
    alice.push_back(77);
    alice.push_back(90);
    alice.push_back(102);
    vector<int> result = climbingLeaderboard(scores, alice);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        
        if (i != result.size() - 1) {
            cout << "\n";
        }
    }
    
    
    
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    
    input_string.erase(new_end, input_string.end());
    
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    
    vector<string> splits;
    char delimiter = ' ';
    
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    
    return splits;
}

