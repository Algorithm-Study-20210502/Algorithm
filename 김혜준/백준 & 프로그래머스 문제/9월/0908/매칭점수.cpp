#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

typedef struct Page{
    int normal_score;
    string url;
    vector<string> ex_link;
    
}Page;

int solution(string word, vector<string> pages) {
    int answer;
    map<string,double>m;
    int N = pages.size();
    transform(word.begin(),word.end(),word.begin(),::tolower);
    Page p[N];
    for(int i=0;i<N;i++){
        transform(pages[i].begin(),pages[i].end(),pages[i].begin(),::tolower);
        // cout << pages[i];
        
        string temp_str = pages[i];
        vector<string> t;
        string ex_url =  "<a href=\"https://";
        int idx = temp_str.find(ex_url)+ex_url.length();
        temp_str = temp_str.substr(idx);
        int idx2 = temp_str.find("\">");
        t.push_back(temp_str.substr(0,idx2));
        while(temp_str.find(ex_url)!=string::npos){
            idx = temp_str.find(ex_url)+ex_url.length();
            temp_str = temp_str.substr(idx);
            idx2 = temp_str.find("\">");
            t.push_back(temp_str.substr(0,idx2));
        }
        p[i].ex_link = t;
        
        temp_str = pages[i];
        string searchUrl = "<meta property=\"og:url\" content=\"https://";
        idx = temp_str.find(searchUrl)+searchUrl.length();
        temp_str = temp_str.substr(idx);
        idx2= temp_str.find("\"/>");
        p[i].url = temp_str.substr(0,idx2);
        
        idx = temp_str.find("<body>");
        temp_str = temp_str.substr(idx);
        
        string temp="";
        int cnt=0;
        for(int j=0;j<temp_str.length();j++){
            if(isalpha(temp_str.at(j))){
                temp.push_back(temp_str.at(j));
            }else{
                if(temp==word){
                    
                    cnt++;
                }
                temp="";
            }
        }
        p[i].normal_score=cnt;
        
        for(int j=0;j<p[i].ex_link.size();j++){
            m[p[i].ex_link[j]]+=((double)p[i].normal_score/(double)p[i].ex_link.size());
        }
        
    }
    double MMM = -1;
    for(int i=0;i<N;i++){
        if(MMM<p[i].normal_score+m[p[i].url]){
            MMM = p[i].normal_score+m[p[i].url];
            printf("%.3f",MMM);
            answer=i;
        }
    }
    
    
    
    return answer;
    
    
}