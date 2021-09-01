#include <iostream>

using namespace std;

char board1[101][101];
int visit1[101][101];
char board2[101][101];
int visit2[101][101];


int N,ret1,ret2;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void DFS1(int,int,char);
void DFS2(int,int,char);

int check1(int,int);
int check2(int,int);

void solve1();
void solve2();

void input();

int main() {
  input();
  solve1();
  solve2();
  cout << ret1 << " " << ret2;
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> board1[i][j];
      if(board1[i][j]=='G')
        board2[i][j]='R';
      else
        board2[i][j]=board1[i][j];
    }
  }
}

void solve1()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
      if(!visit1[i][j])
      {
        DFS1(i,j,board1[i][j]);
        ret1++;
      }
    }
  }
}

void DFS1(int x,int y, char c)
{
  visit1[x][y]=1;
  for(int i=0;i<4;i++)
  {
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(!check1(nx,ny))
      continue;
    if(board1[nx][ny]==c)
      DFS1(nx,ny,c);
  }
}

int check1(int x,int y)
{
  if(x>=1&&x<=N&&y>=1&&y<=N&&!visit1[x][y])
    return 1;
  return 0;
}

void solve2()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
      if(!visit2[i][j])
      {
        DFS2(i,j,board2[i][j]);
        ret2++;
      }
    }
  }
}

void DFS2(int x,int y, char c)
{
  visit2[x][y]=1;
  for(int i=0;i<4;i++)
  {
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(!check2(nx,ny))
      continue;
    if(board2[nx][ny]==c)
      DFS2(nx,ny,c);
  }
}

int check2(int x,int y)
{
  if(x>=1&&x<=N&&y>=1&&y<=N&&!visit2[x][y])
    return 1;
  return 0;
}