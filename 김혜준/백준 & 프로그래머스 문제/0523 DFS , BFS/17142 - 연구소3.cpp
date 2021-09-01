#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstring>

using namespace std;

int temp[51][51];
int arr[51][51];
int visit[51][51];

int N,M,ret,num_infect,num_blank,num_2,ans=INT_MAX;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

queue<pair<int,int>> q;
vector<pair<int,int>> v;
vector<int> k;

void input();
void solve();
void start();
void infect(int,int);
bool check(int,int);
bool flag1,flag2;

int main()
{
  input();
  start();
  if(ans==INT_MAX)
    cout << -1;
  else
    cout << ans;
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
      cin >> temp[i][j];
      if(temp[i][j]==2)
      {
        num_2++;
        v.push_back({i,j});
      }
      else if(temp[i][j]==0)
        num_blank++;
    }
  }

  for(int i=0;i<M;i++)
  {
    k.push_back(1);
  }
  for(int i=0;i<num_2-M;i++)
  {
    k.push_back(0);
  }

  sort(k.begin(),k.end());
}

void start()
{
  do{
    memset(visit,0,sizeof(visit));
    for(int i=0;i<k.size();i++)
    {
      if(k[i])
      {
        q.push(v[i]);
        visit[v[i].first][v[i].second]=1;
      }
    }
    
    copy(&temp[0][0],&temp[0][0]+51*51,&arr[0][0]);
    solve();
    
  }while(next_permutation(k.begin(),k.end()));
}

void solve()
{
  // cout << q.size() << endl;
  num_infect=0;
  ret=0;
  while(!q.empty())
  {
    flag1=false;
    flag2=false;

    int size = q.size();
    
    while(size--)
    {
      int x=q.front().first;
      int y=q.front().second;
      q.pop();

      for(int i=0;i<4;i++)
      {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(check(nx,ny))
        {
          infect(nx,ny);
        }
      }
    }
    
    if(flag1)
      ret++;
    else if(flag2&&!(num_infect==num_blank))
      ret++;
    else
    {
      while(!q.empty())
        q.pop();
    }
  }
  if(num_infect==num_blank)
    ans=min(ans,ret);
}

bool check(int x,int y)
{
  if(x>=1&&x<=N&&y>=1&&y<=N)
    return true;
  return false;
}

void infect(int x,int y)
{
  if(arr[x][y]==0)
  {
    arr[x][y]=3;
    q.push({x,y});
    num_infect++;
    flag1=true;
  }
  else if(arr[x][y]==2&&!visit[x][y])
  {
    visit[x][y]=1;
    q.push({x,y});
    flag2=true;
  }
}