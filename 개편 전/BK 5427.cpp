#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
#define X first
#define Y second 
int t;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int w = 0; w < t; w++){
        int o = 0;
        int dist1[1002][1002];
        int dist2[1002][1002];
        int n ,m;
        string board[1002];
        queue<pair<int,int> > Q1;
        queue<pair<int,int> > Q2;
        cin >> m >> n;
    
        for (int i = 0; i < n; i++){
            fill(dist1[i], dist1[i]+m,-1);
            fill(dist2[i], dist2[i]+m,-1);
        }
        for(int i = 0; i < n; i++){
            cin >> board[i];
        }
        int yx,yy,fx,fy;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '@'){
                    dist2[i][j] = 0;  
                    Q2.push(make_pair(i,j));
                }
                if(board[i][j] == '*'){
                    dist1[i][j] = 0;
                    Q1.push(make_pair(i,j));  
                }
            }
        }
        while(!Q1.empty()){
            pair<int,int> cur = Q1.front(); Q1.pop();
            for(int dir = 0; dir < 4; dir++){ 
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir]; 
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                    if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue; 
                    dist1[nx][ny] = dist1[cur.X][cur.Y]+1; 
                    Q1.push(make_pair(nx,ny));
            }
        }
        while(!Q2.empty()){
            pair<int,int> cur = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 4; dir++){ 
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir]; 
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                        cout << dist2[cur.X][cur.Y]+1 << endl;
                        o = 1;
                        break;
                    } 
                    if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue; 
                    if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1){
                        continue; 
                    }
                    dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
                    Q2.push(make_pair(nx,ny));
            }
            if(o) break;
        }    
        if(o) continue;
        cout << "IMPOSSIBLE" << endl;
    }
}