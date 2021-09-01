#include <iostream>
#include <queue>

using namespace std;
int N,M,bX,bY,rX,rY;
char arr[11][11];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void input();
int solve();
int visit[11][11][11][11];

int main() {

  input();
  // cout << solve();
  if(solve()==-1)
    cout << 0;
  else
    cout << 1;
}
void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=M;j++)
    {
      cin >> arr[i][j];
      if(arr[i][j]=='B')
      {
        bX=i,bY=j;
        arr[i][j]='.';
      }
      if(arr[i][j]=='R')
      {
        rX=i,rY=j;
        arr[i][j]='.';
      }
    }
    
  }
}

int solve(){
  queue<pair<int,int>> B;
  queue<pair<int,int>> R;

  B.push({bX,bY});
  R.push({rX,rY});

  int ret=0;

  while(!B.empty()){
    int size = B.size();
    while(size--)
    {
      rX = R.front().first;
      rY = R.front().second;
      bX = B.front().first;
      bY = B.front().second;

      B.pop();
      R.pop();

      
      for(int i=0;i<4;i++)
      {
        int nrX=rX,nrY=rY,nbX=bX,nbY=bY;

        

        while(arr[nrX+dx[i]][nrY+dy[i]]=='.')
        {
          nrX+=dx[i];
          nrY+=dy[i];
        }

        while(arr[nbX+dx[i]][nbY+dy[i]]=='.')
        {
          nbX+=dx[i];
          nbY+=dy[i];
        }

        if(arr[nbX+dx[i]][nbY+dy[i]]=='O')
          continue;
        
        if(arr[nrX+dx[i]][nrY+dy[i]]=='O')
        {
          return ret+1;
        }


        if(nrX==nbX&&nrY==nbY)
        {
          if(abs(nrX-rX)+abs(nrY-rY) < abs(nbX-bX) + abs(nbY-bY))
          {
            // rX = nrX;
            // rY = nrY;
            //rX,rY를 변화시키면 안됨..

            nbX-=dx[i];
            nbY-=dy[i];
          }
          else
          {
            // bX = nbX;
            // bY = nbY;
            nrX-=dx[i];
            nrY-=dy[i];
          }
        }
        if(visit[nrX][nrY][nbX][nbY]==1)
          continue;
        B.push({nbX,nbY});
        R.push({nrX,nrY});
        visit[nrX][nrY][nbX][nbY]=1;

      }
    }
    
    ret++;
    // cout << ret;
    if(ret==10)
      return -1;
  }
  
  return -1;
}