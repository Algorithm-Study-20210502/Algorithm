#include <iostream>
#include <vector>

using namespace std;

void input();
void update(int x, int y);
int solve(int,int);
int N;

int arr[101][101];

int main()
{
  input();
  int ret=0;
  for(int i=0;i<100;i++)
  {
    for(int j=0;j<100;j++)
    {
      if(solve(i,j))
        ret++;
    }
  }
  cout << ret;
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int x,y,d,g;
  
  for(int i=0;i<N;i++)
  {
    cin >> x >> y >> d >> g;
    
    arr[x][y]=1;
    vector <int> s;
    s.push_back(d);
    for(int j=0;j<g;j++)
    {
      int size = s.size();
      for(int k=size-1;k>=0;k--)
      {
        switch(s[k])
        {
          case 0:
            s.push_back(1);
            break;
          case 1:
            s.push_back(2);
            break;
          case 2:
            s.push_back(3);
            break;
          case 3:
            s.push_back(0);
            break;
        }
      }
    }

    for(int m=0;m<s.size();m++)
    {
      switch(s[m])
      {
        case 0:
          x+=1;
          update(x,y);
          break;
        case 1:
          y-=1;
          update(x,y);
          break;
        case 2:
          x-=1;
          update(x,y);
          break;
        case 3:
          y+=1;
          update(x,y);
      }
    }
  }
}

void update(int x, int y)
{
  if(x<=100&&x>=0&&y>=0&&y<=100)
    arr[x][y]=1;
}

int solve(int x,int y)
{
  if(arr[x][y]&&arr[x+1][y]&&arr[x][y+1]&&arr[x+1][y+1])
    return 1;
  else
    return 0;
}