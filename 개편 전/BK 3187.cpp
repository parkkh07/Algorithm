#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
#define X first
#define Y second 
int vis[251][251];
int n ,m , o = 0 ,v = 0;
int fo = 0;
int fv = 0;
string board[251];
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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'k'){
                o ++;
            }else if(board[i][j] =='v' ){
                v ++;
            }
        }
    }
    int foae = 0;

    for(int i = 0; i < n; i++){fill(vis[i] , vis[i] + m ,-1);}

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == '.' || board[i][j] == '#' || vis[i][j] >= 0) continue;
            Q.push(make_pair(i,j));
            if(board[i][j] == 'k') fo ++;
            if(board[i][j] == 'v') fv ++;
            vis[i][j] = 0;
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){ 
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir]; 
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                    if(vis[nx][ny] >= 0 || board[nx][ny] == '#') continue; 
                    vis[nx][ny] = 0;
                    if(board[nx][ny] == 'k') fo ++;
                    if(board[nx][ny] == 'v') fv ++;
                    
                    Q.push(make_pair(nx,ny));
                }
            }
            if(fo > fv){
                v -= fv;
            }else{
                o -= fo;
            }
            fo = 0;
            fv = 0;
            
        }
    }
    cout << o << " " << v << endl;
}