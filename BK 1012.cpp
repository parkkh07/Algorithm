#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second 


int n ,m ,k ,t;
int a,b;
int vis[51][51]; 
int board[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 


void init(int a[51][51]){
    for (int i = 0; i < 51; i++){
        for (int j = 0; j < 51; j++){
            a[i][j] = 0;
        }
    }
}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int z = 0; z < t; z++){
        
        queue<pair<int,int> > Q;
        cin >> m >> n >> k;
        for (int i = 0; i <k; i++){
            cin >> a >> b;
            board[b][a] = 1;
        }
        int mxc = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0 || vis[i][j] == 1) { continue; }
                else{
                    mxc ++;
                    vis[i][j] = 1; 
                    Q.push(make_pair(i,j)); 
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){ 
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir]; 
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                            if(vis[nx][ny] || board[nx][ny] == 0) continue; 
                            vis[nx][ny] = 1; 
                            Q.push(make_pair(nx,ny));
                        }
                    }
                }
            }
        }
        cout << mxc <<endl;
        mxc = 0;
        init(board);
        init(vis);
    } 
}