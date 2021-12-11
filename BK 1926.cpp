#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second 

bool vis[502][502]; 
int n ,m ;
int board[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 


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
    int mxp = 0;
    int mxc = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 || vis[i][j]) { continue; }
            else{
                mxc ++;
                int area = 0;
                vis[i][j] = 1; 
                Q.push(make_pair(i,j)); 
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    area ++;
                    for(int dir = 0; dir < 4; dir++){ 
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; 
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                        if(vis[nx][ny] || board[nx][ny] != 1) continue; 
                        vis[nx][ny] = 1; 
                        Q.push(make_pair(nx,ny));
                    }
                    mxp = max(mxp,area);
                }
            }
        }
    }
    cout << mxc << '\n' << mxp;
    
}