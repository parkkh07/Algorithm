#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
#define X first
#define Y second 
int vis[102][102];
int n ,m,t ,spc =0;

string board[102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    cin >> t;
    for(int w = 0 ; w < t ; w++){
        
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> board[i];
        }
        for(int i = 0; i < n; i++){fill(vis[i] , vis[i] + m ,-1);}

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '.' || vis[i][j] >= 0) continue;
                Q.push(make_pair(i,j));
                vis[i][j] = 0;
                spc ++;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){ 
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; 
                        if(nx < 0 || ny < 0 || ny >= m || nx >= n) continue; 
                        if(vis[nx][ny] >= 0 || board[nx][ny] == '.') continue;
                        vis[nx][ny] = 0;                    
                        Q.push(make_pair(nx,ny));
                    }
                }  
            }    
        }
        cout << spc << endl;
        spc = 0;
    }   
}