#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;
#define X first
#define Y second 

int vis[102][102]; 
int n ,m,w = 0,b = 0;
string board[102];
int dx[8] = {1,0,-1,0};
int dy[8] = {0,1,0,-1}; 


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    cin >> m >> n;

    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    int wwc = 0;
    int bwc = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 || vis[i][j]) { continue; }
            else{
                if(board[i][j] == 'W'){
                    wwc ++;
                    vis[i][j] = 1;
                    Q.push(make_pair(i,j)); 
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 8; dir++){ 
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir]; 
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                            if(vis[nx][ny] || board[nx][ny] == 'B') continue; 
                            vis[nx][ny] = 1;
                            wwc ++;
                            Q.push(make_pair(nx,ny));
                        }
                    }
                }else{
                    vis[i][j] = 1;
                    bwc ++;
                    Q.push(make_pair(i,j)); 
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 8; dir++){ 
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir]; 
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                            if(vis[nx][ny] || board[nx][ny] == 'W') continue; 
                            vis[nx][ny] = 1;
                            bwc ++;
                            Q.push(make_pair(nx,ny));
                        }
                    }
                }
                w += pow(wwc,2);
                b += pow(bwc,2);
                wwc = 0;
                bwc = 0;
            }
        }
    }
    cout << w << " " << b << endl;
    
}