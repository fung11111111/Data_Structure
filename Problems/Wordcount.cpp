//
//  main.cpp
//  problem
//
//  Created by Fung Lam on 10/8/2020.
//  Copyright © 2020 Fung Lam. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

void wordCount(string text){
    map<string, int> m;
    map<string, int>::iterator itr;
    string word = "";
    string tmp = "";
    
    for(int i=0;i<text.length();i++){
        if(text[i] != ' ' ){
            tmp += text[i];
        }
        if(text[i] == ' ' || i == text.length()-1){
            word = tmp;
            if(m.find(word) !=m.end()){
                m[word]++;
            }else{
                m[word] = 1;
            }
            tmp = "";
        }
       
    }
    for(itr=m.begin();itr!=m.end();++itr){
        cout << itr->first << ": " << itr->second << endl;
    }
    
}
int main(int argc, const char * argv[]) {
    
   
    string str = "Computer system computer design algorithmn design and analysis quantum computer computer science department";
    
    wordCount(str);
    return 0;
}
