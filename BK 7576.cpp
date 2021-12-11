#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
#define X first
#define Y second 
int dist[1002][1002];
int n ,m;
int board[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            if (board[i][j]==1){
                Q.push(make_pair(i,j)); 
            }
            if (board[i][j] == 0){
                dist[i][j] = -1;
            }
        }
    }
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ 
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; 
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                if(dist[nx][ny] >= 0) continue; 
                dist[nx][ny] = dist[cur.X][cur.Y]+1; 
                Q.push(make_pair(nx,ny));
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] == -1){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    int mx = -100;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mx = max(mx, dist[i][j]);
        }
    }
    cout << mx << endl;
}