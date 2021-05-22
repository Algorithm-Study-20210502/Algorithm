#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N,ret,ans=0;
int order[10][51];
int arr[4];
vector <int> v(10);

void input();
void solve();
void select();
void change();
void go(int);
int update(int);
void game();

int main() {
  input();

}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=9;j++)
    {
      cin >> order[j][i];
    }
  }

  

  select();
  cout << ans;
}

void select()
{
  

  for(int i=1;i<=9;i++)
  {
    v[i]=i;
  }

  do{

    if(v[4]==1)//4번 타자가 1번선수인 경우
    {
      game();
    }


  }while(next_permutation(v.begin()+1,v.end()));
}

void game()
{
  
  int present=1;
  int out=0;
  ret=0;
  for(int i=1;i<=N;i++) {
    out=0;
    change();
    while(out<3) {
      if(order[v[present]][i])
        go(order[v[present]][i]);
      else
        out++;
      
      present=update(present);
    }
  }
  // if(v[1]==5&&v[2]==6&&v[3]==7)
  //   cout << "@" << ret << endl;
  
  ans=max(ans,ret);
}

int update(int p)
{
  p++;
  if(p>9)
    p-=9;
  
  return p;
}

void go(int n)
{
  if(arr[3]==1) // 3루주자 이동
  {
    ret++;
    arr[3]=0;
  }
  if(arr[2]==1)// 2루주자 이동
  {
    if(n>=2)
      ret++;   
    else
      arr[3]=1;
    arr[2]=0;
  }
  if(arr[1]==1)// 1루주자 이동
  {
    if(n>=3)
      ret++;
    else if(n==2)
      arr[3]=1;
    else
      arr[2]=1;
    arr[1]=0;
  }

  if(n==4) // 홈런
    ret++;
  else // 홈런이 아닌 경우 타자 이동
    arr[n]=1;
}

void change()
{
  for(int i=0;i<4;i++)
    arr[i]=0;
}