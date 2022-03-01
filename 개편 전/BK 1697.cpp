#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
int dist[100002];
int n ,m;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill(dist,dist + 100001 ,-1);
    dist[n] = 0;
    queue<int> Q;
    Q.push(n); 
    while(dist[m] == -1){
        int cur = Q.front(); Q.pop();
        for(int nx : {cur -1, cur + 1 , cur * 2}){ 
            if(nx < 0 || nx > 100000) continue; 
            if(dist[nx] != -1 ) continue; 
            dist[nx] = dist[cur]+1; 
            Q.push(nx);
        }
    }
    cout<< dist[m] << endl;
}

