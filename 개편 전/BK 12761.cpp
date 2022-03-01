#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> dist(1000002);
int a,b,n,m;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> n >> m;

    fill(dist.begin(),dist.end(),-1);
    dist[n] = 0;
    queue<int> Q;
    Q.push(n); 
    for(int i = 0; i <100002;i++){
        int cur = Q.front(); Q.pop();
        for(int nx : {cur + 1, cur - 1 , cur * a , cur * b}){ 
            if(nx < 0 || nx > 100000) continue; 
            if(dist[nx] != -1 ) continue; 
            dist[nx] = dist[cur]+1; 
            Q.push(nx);
        }
    }
    cout << dist[m] << endl;
    
}


