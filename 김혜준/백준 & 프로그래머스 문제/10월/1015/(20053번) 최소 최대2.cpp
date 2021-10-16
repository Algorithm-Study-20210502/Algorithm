#include <iostream>
#include <cstring>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  int N;
  while(T--){
    cin >> N;
    int input;
    int retM=-1000001,retm=1000001;
    for(int i=0;i<N;i++){
      cin >> input;
      retM=max(retM,input);
      retm=min(retm,input);

    }
    cout << retm << " " << retM << "\n";
  }

}