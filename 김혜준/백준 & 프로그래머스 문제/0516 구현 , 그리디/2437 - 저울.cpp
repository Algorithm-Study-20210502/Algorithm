#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int arr[1000];

void input();
void solve();

int main() {
  input();
  solve();
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin >> N;
  for(int i=0;i<N;i++)
  {
    cin >> arr[i];
  }
}

void solve()
{
  sort(arr,arr+N);
  int low=0;
  
  for(int i=0;i<N;i++)
  {
    if(arr[i] <= low+1)
    {
      low=arr[i]+low;
      // cout << low << endl;
    }
    else
    {
      cout << low+1;
      return;
    }
  }

  cout << low+1;
}