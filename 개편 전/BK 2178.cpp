#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
#define X first
#define Y second 
int dist[102][102];
int n ,m;
string board[102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    for(int i = 0; i < n; i++){fill(dist[i] , dist[i] + m ,-1);}
    dist[0][0] = 0; 
    Q.push(make_pair(0,0)); 
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ 
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; 
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue; 
                dist[nx][ny] = dist[cur.X][cur.Y]+1; 
                Q.push(make_pair(nx,ny));
        }
    }
    cout<< dist[n-1][m-1] + 1 << endl;
    return 0;
}