#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
#define X first
#define Y second 
int vis[1000][1000];
int n ,m;

string board[250];
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

    for(int i = 0; i < m; i++){
        if(board[0][i] == '1' || vis[0][i] >= 0) continue;
        Q.push(make_pair(0,i));
        vis[0][i] = 0;
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++){ 
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; 
                if(nx >= n){
                    cout << "YES" << endl;
                    return 0;
                }
                if(nx < 0 || ny < 0 || ny >= m) continue; 
                if(vis[nx][ny] >= 0 || board[nx][ny] == '1') continue;
                vis[nx][ny] = 0;                    
                Q.push(make_pair(nx,ny));
            }
        }      
    }
    cout << "NO" << endl;
    

}