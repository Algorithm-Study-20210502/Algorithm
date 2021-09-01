#include <string>
#include <iostream>
#include <cstring>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

string answer;
string invalid;
string P;
string temp;
bool visit[26];

bool isLower(char c){
    if(c>='a'&&c<='z')
        return true;
    return false;
}

void init(){
    temp="";
    answer="";
    invalid="invalid";
    memset(visit,false,sizeof(visit));
    
}

bool check1(string s){
    
    char start = s[0];
    char end = s[s.length()-1];
    if(s.length()%2==0) return false;
    char c = s[1];
    if(visit[c-'a']) return false;
    visit[c-'a']=true;
    temp="";
    for(int i=0;i<s.length()-1;i++){ 
        if(i%2==0){ // 0,2,4,6...  대문자
            if(isLower(s[i])){
                return false;
                temp.push_back(s[i]);
            }
        }else{ // 1,3,5,7. .. 소문자
            if(s[i]!=c){
                return false;
            }
            if(!isLower(s[i])){
                return false;
            }
        }
    }
    return true;
    
} // 대문자,소문자 1개 이상인 문자열 대상, 규칙1이 적용되는지 확인하는 함수

string solution(string sentence) {
    init();
    
    while(sentence!=""){
        cout << sentence << endl;
        char start = sentence[0];
        if(isLower(start)){ // 첫글자가 소문자일 경우
            // 맨앞 문자열이
            // 1. 규칙 2만 만족하는 경우와
            // 2. 규칙 1,2둘다 만족하는 경우
            if(visit[start-'a']) return invalid;
            visit[start-'a']=true;
            int cnt=0,CNT=0;
            int idx=-1;
            for(int i=1;i<sentence.length();i++){
                
                if(sentence[i]==start){
                    idx=i;
                    break;
                }
                if(isLower(sentence[i])){
                    cnt++;
                }else{
                    CNT++;
                }
            }
            if(idx==-1){ // 첫글자와 같은 문자를 찾지 못한 경우
                return invalid;
            }else{ // 찾은 경우
                if(CNT==0)  // 소문자 연속
                    return invalid;
                if(cnt==0){ // cOPOSADSPc 사이의 문자열이 대문자, 위에서의 1. 규칙 2만 만족하는 경우
                    answer.append(sentence.substr(1,idx-1)); // 1~idx-1
                    answer.push_back(' ');
                    if(sentence.length()-1!=idx) // 문자열 끝이 아님
                        sentence=sentence.substr(idx+1,sentence.length()-1-idx); // idx+1 ~~ sentence.length()-1
                    else //문자열 끝
                        sentence="";
                }else{ // 규칙 1,2 둘다 만족하는 경우
                    if(check1(sentence.substr(1,idx-1))){ // 만약 규칙2를 만족하는 경우 (대문자 소문자 섞여있고 규칙1일 수는 없음)
                        // 소문자1개 이상 대문자1개이상인 문자열임
                        answer.append(temp);
                        answer.push_back(' ');
                        temp="";
                        if(sentence.length()-1!=idx) // 문자열 끝이 아님
                            sentence=sentence.substr(idx+1,sentence.length()-1-idx); // idx+1 ~~ sentence.length()-1
                        else //문자열 끝
                            sentence="";
                    }else{ // 만족하지 않으면
                        return invalid;
                    }
                }
            }
            
        }else{ // 첫문자가 대문자인 경우
            
            int idx;
            for(int i=0;i<sentence.length();i++){
                if(isLower(sentence[i])){
                    if(i==1){ //앞에 대문자가 1개인 경우 ex)    Aa...
                        idx=i-1;
                        break;
                    }else{ // 앞에 대문자가 2개이상인 경우 ex) A Ba...
                        answer.append(sentence.substr(0,i-1)); // 0~i-2
                        answer.push_back(' ');
                        idx=i-1;
                        sentence = sentence.substr(idx);
                        break;
                    }
                }// 처음 소문자를 발견했을 때
            }
            
            // 현재 sentence는 규칙1을 만족하거나 sentence[1] 부터 시작해 규칙 2를 만족할 수 있음
            char c = sentence[1];
            cout << "##" << c;
            if(visit[c-'a']) return invalid;
            visit[c-'a']=true;
            int cnt=0;
            // 규칙 1을 만족하는지를 먼저 확인
            // AbA // AbCbE .. 
            idx=-1;
            temp="";
            for(int i=0;i<sentence.length();i++){ // 대소.... 
                if(isLower(sentence[i])){
                    if(i%2==0){
                        idx=i;
                        break;
                    }
                    if(sentence[i]==c){
                        cnt++;
                    }else{
                        idx=i;
                        break;
                    }
                }else{
                    if(i%2==1){
                        idx=i;
                        break;
                    }
                    temp.push_back(sentence[i]);
                }
            }
            
            if(idx==-1){
                if(isLower(sentence[sentence.length()-1])){
                    return invalid;   
                }else{
                    answer.append(temp);
                    sentence="";    
                }
            }else{
                //0~idx-1
                if(cnt>=2){ // 
                    answer.append(temp);
                    answer.push_back(' ');
                    sentence = sentence.substr(idx);
                }else{// cnt==1
                    answer.append(temp);
                    answer.push_back(' ');
                    idx=-1;
                    int cnt=0,CNT=0;
                    for(int i=1;i<sentence.length();i++){
                        if(sentence[i]==c){
                            idx=i;
                            break;
                        }
                        if(isLower(sentence[i])){
                            cnt++;
                        }else{
                            CNT++;
                        }
                    }
                    
                    if(idx==-1){
                        cout <<"@@@"<< sentence << endl;
                        if(sentence.length()>=3){
                            if(!isLower(sentence[2])){
                                answer[answer.length()-1]=sentence[2];
                                answer.push_back(' ');
                                if(sentence.length()==3)
                                    sentence="";
                                else
                                    sentence = sentence.substr(3);
                            }else{
                                return invalid;
                            }
                        }else{
                            return invalid;
                        }
                    }else{
                        if(CNT==0) return invalid;
                        if(cnt==0){
                            answer.append(sentence.substr(1,idx-1));
                            answer.push_back(' ');
                            if(idx+1<sentence.length()){
                                sentence = sentence.substr(idx+1);
                            }else{
                                sentence = "";
                            }
                        }else{
                            if(check1(sentence.substr(1,idx-1))){//1~idx-1
                                answer.append(temp);
                                answer.push_back(' ');
                                temp="";
                                if(sentence.length()-1!=idx) // 문자열 끝이 아님
                                    sentence=sentence.substr(idx+1); // idx+1 ~~ sentence.length()-1
                                else //문자열 끝
                                    sentence="";
                            }else{
                                return invalid;
                            }    
                        }
                }
            }
        }
        
        }
    }
    if(answer.at(answer.length()-1)==' '){
        answer = answer.substr(0,answer.length()-1);
    }
    
    
    return answer;
}