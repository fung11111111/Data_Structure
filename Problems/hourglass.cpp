#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    
    
    
    int upper = INT_MIN;
    int Rmov = 0;
    int m =3;
    
    while (m<=6) {
        int Cmov = 0;
        int n = 3;
        while(n<=6){
            int sum = 0;
            int s = 1;
            for(int i = Rmov; i<m;i++){
                for(int j=Cmov;j<n;j++){
                    if(s != 4 && s != 6){
                        sum += arr[i][j];
                    }
                    s++;
                }
            }
            upper = max(sum, upper);
            Cmov++;
            n++;
        }
        Rmov++;
        m++;
    }
    
    
    
    return upper;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));
    
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);
        
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    int result = hourglassSum(arr);
    
    
    cout << result << endl;
    
    return 0;
}
