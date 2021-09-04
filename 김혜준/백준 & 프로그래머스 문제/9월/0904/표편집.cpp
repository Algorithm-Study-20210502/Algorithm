#include <string>
#include <vector>
#include <set>
#include <stack>
#include <iostream>
using namespace std;


string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    // vector<info> V;
    // for(int i=0;i<n;i++){
    //     info cur;
    //     cur.pre=i-1;
    //     cur.next=i+1;
    //     V.push_back(cur);
    // }
    
//     list <int> l;
    set<int> l;
    stack<int> s;
    for(int i=0;i<n;i++)
        l.insert(i);
    auto it = l.begin();
    for(int i=0;i<k;i++){
        it++;
    }
    
    
    for(auto w:cmd){
        int d;

        switch(w[0]){
            case 'U':
                d = stoi(w.substr(2));
                for(int i=0;i<d;i++)
                    it--;
                break;
            case 'D':
                d = stoi(w.substr(2));
                for(int i=0;i<d;i++)
                    it++;
                break;
            case 'C':
                s.push(*it);
                if(it==--l.end()){
                    it = l.erase(it);
                    it--;
                }else{
                    it = l.erase(it);
                }
                break;
            case 'Z':
                int cur = s.top();
                s.pop();
                l.insert(cur);
                break;
        }
    }
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
    for(auto w:l){
        arr[w]=1;
    }
    for(int i=0;i<n;i++){
        if(arr[i])
            answer+='O';
        else
            answer+='X';
    }
    
    return answer;
}