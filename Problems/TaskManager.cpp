#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


struct task{
    int tn;
    int r;
    int w;
    int p;
};

void taskManager(queue<task> hq, queue<task> lq){
    map<int,int> m;
    map<int,int>::iterator itr;
    int time =0;
    
    while(true){
        if(!hq.empty() && !lq.empty()){
            task thq = hq.front();
            task tlq = lq.front();
            
            if(thq.r <= time && tlq.r <= time){
                time += thq.w;
                m[thq.tn] = time;
                hq.pop();
            }else if((thq.r > time && tlq.r <= time) || (tlq.r > time && thq.r <= time)){
                if(thq.r <= tlq.r){
                    time += thq.w;
                    m[thq.tn] = time;
                    hq.pop();
                }else{
                    time += tlq.w;
                    m[tlq.tn] = time;
                    lq.pop();
                }
            }else{
                if(thq.r <= tlq.r){
                    time = thq.r + thq.w;
                    m[thq.tn] = time;
                    hq.pop();
                }else{
                    time = tlq.r + tlq.w;
                    m[tlq.tn] = time;
                    lq.pop();
                }
            }
        }
        else if(!hq.empty() && lq.empty()){
            task thq = hq.front();
            if(thq.r <= time){
                time += thq.w;
            }else{
                time = thq.r + thq.w;
            }
            m[thq.tn] = time;
            hq.pop();
        }
        else if(hq.empty() && !lq.empty()){
            task tlq = lq.front();
            if(tlq.r <= time){
                time += tlq.w;
            }else{
                time = tlq.r + tlq.w;
            }
             m[tlq.tn] = time;
            lq.pop();
        }
        else{
            break;
        }
    }
    
    for(itr = m.begin();itr!=m.end();++itr){
        cout << itr->second << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    queue<task> hq;
    queue<task> lq;
    
    int n; //number of tasks
    int ri;
    int wi;
    int pi;
    int tn = 0;
    cout << "input numbers of tasks: ";
    cin >> n;
    while(n-- > 0){
        tn++;
        cin >> ri >> wi >> pi;
        if(pi == 0){
            hq.push({tn,ri,wi,pi});
        }else{
            lq.push({tn,ri,wi,pi});
        }
        
    }
    
    taskManager(hq,lq);
    
    
    
    
    return 0;
}
