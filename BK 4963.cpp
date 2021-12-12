#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second 
 

int vis[52][52]; 
int n ,m;
int board[52][52];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int mxc = 0;

void Rset(int a[52][52]){
    for(int i = 0; i < 52; i++){
        for(int j = 0; j <52 ; j++){
            a[i][j] = 0;
        }
    }
    return ;
}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    while(true){
        queue<pair<int,int> > Q;
        

        cin >> n >> m;
        if(m == 0 && n == 0){
            return 0;
        }
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 0 || vis[i][j] == 1) continue;
                Q.push(make_pair(i,j));
                vis[i][j] = 1;
                mxc ++;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 8; dir++){ 
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; 
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue; 
                        if(vis[nx][ny] || board[nx][ny] == 0) continue; 
                        vis[nx][ny] = 1;
                        Q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        cout << mxc <<endl;

        mxc = 0;
        Rset(board);
        Rset(vis);
    } 
}