#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
#define X first
#define Y second 
int dist1[1002][1002];
int dist2[1002][1002];
int n ,m;
string board[1002];

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

    int yx,yy,fx,fy;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (board[i][j] == '.'){
                dist1[i][j] = -1;
                dist2[i][j] = -1;
            }
            if(board[i][j] == 'J'){
                yx = i;
                yy = j;    
            }
            if(board[i][j] == 'F'){
                Q.push(make_pair(i,j));  
            }
        }
    }

    
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ 
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; 
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue; 
                dist1[nx][ny] = dist1[cur.X][cur.Y]+1; 
                Q.push(make_pair(nx,ny));
        }
    }
    Q.push(make_pair(yx,yy));
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ 
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; 
                if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                    cout << dist2[cur.X][cur.Y]+1 << endl;
                    return 0;
                } 
                if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue; 
                dist2[nx][ny] = dist2[cur.X][cur.Y]+1; 
                if(dist1[nx][ny] != 0 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1){
                    continue; 
                }
                dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
                Q.push(make_pair(nx,ny));
        }
    }    
    cout << "IMPOSSIBLE" << endl;
    

}