#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
#define X first
#define Y second 
int vis[602][602];
int n ,m;

string board[602];
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
    for(int i = 0; i < n; i++){fill(vis[i] , vis[i] + m ,-1);}

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'I'){
                Q.push(make_pair(i,j));
                vis[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ 
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; 
            if(nx < 0 || ny < 0 || ny >= m || nx >= n) continue; 
            if(vis[nx][ny] > 0 || board[nx][ny] == 'X') continue;
            vis[nx][ny] = 1; 
            if(board[nx][ny] == 'P') cnt++;                   
            Q.push(make_pair(nx,ny));
        }
              
    }
    if(cnt > 0){
        cout << cnt << endl;
    }else{
        cout << "TT" << endl;
    }
    
}