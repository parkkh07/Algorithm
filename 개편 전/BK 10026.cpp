#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;
#define X first
#define Y second 
int vis[102][102];
int vis2[102][102];
int n;
string board[102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    queue<pair<int,int> > Q2;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == 0){
                Q.push(make_pair(i,j)); 
                k ++;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){ 
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; 
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 
                        if(vis[nx][ny] > 0) continue; 
                        if(board[i][j] == 'B'){
                            if(board[nx][ny] == 'R' || board[nx][ny] == 'G') continue;
                        }
                        if(board[i][j] == 'G' || board[i][j] == 'R'){
                            if(board[nx][ny] == 'B') continue;
                        }
                        vis[nx][ny] = 1;
                        Q.push(make_pair(nx,ny));

                    }
                }
            }
        }
    }

    int m = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis2[i][j] == 0){
                Q2.push(make_pair(i,j)); 
                m ++;
                while(!Q2.empty()){
                    pair<int,int> cur = Q2.front(); Q2.pop();
                    for(int dir = 0; dir < 4; dir++){ 
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; 
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 
                        if(vis2[nx][ny] > 0) continue; 
                        if(board[i][j] != board[nx][ny]) continue;
                        vis2[nx][ny] = 1;
                        Q2.push(make_pair(nx,ny));

                    }
                }
            }
        }
    }

    cout << m << " " << k << endl;
}