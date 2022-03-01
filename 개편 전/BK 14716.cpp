#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second 

int vis[252][252]; 
int n ,m ;
int board[252][252];
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,-1,1}; 


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            cin >> board[i][j];
        }
    }
    int mxc = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 || vis[i][j]) { continue; }
            else{
                mxc ++;
                vis[i][j] = 1; 
                Q.push(make_pair(i,j)); 
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 8; dir++){ 
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; 
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                        if(vis[nx][ny] || board[nx][ny] != 1) continue; 
                        vis[nx][ny] = 1; 
                        Q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    cout << mxc << '\n';  
}