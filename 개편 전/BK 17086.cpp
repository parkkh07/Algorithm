#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
#define X first
#define Y second 
int dist[51][51];
int n ,m;
int board[51][51];
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,-1,1}; 


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    cin >> n >> m;
    for(int i = 0; i < n; i++){fill(dist[i] , dist[i] + m ,-1);}
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                dist[i][j] = 0; 
                Q.push(make_pair(i,j));  
            }
        }
    }

    int mx = -100;
    
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 8; dir++){ 
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; 
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                if(dist[nx][ny] >= 0 || board[nx][ny] == 1) continue; 
                dist[nx][ny] = dist[cur.X][cur.Y]+1; 
                Q.push(make_pair(nx,ny));
                mx = max(mx,dist[nx][ny]);
        }
    }

    cout<< mx << endl;
}