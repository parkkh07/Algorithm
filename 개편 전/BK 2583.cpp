#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define X first
#define Y second 

int vis[102][102]; 
int n ,m, k;
int a,b,c,d;
int board[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){fill(vis[i] , vis[i] + m ,-1);}
    for(int i = 0; i < n; i++){fill(board[i] , board[i] + m ,1);}
    
    for(int t = 0; t < k ; t++){
        cin >> a >> b >> c >> d;
        for(int i = n - d; i < n- b; i++){
            for(int j = a; j < c; j++){
                cout << i << " " << j << endl;
                board[i][j] = 0;
            }
        }

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }


    vector<int>  mxp;
    
    int mxc = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int mx = 0;
            if(board[i][j] == 0 || vis[i][j] >= 0) { continue; }
            else{
                mxc ++;
                int area = 0;
                vis[i][j] = 0; 
                Q.push(make_pair(i,j)); 
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    area ++;
                    for(int dir = 0; dir < 4; dir++){ 
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; 
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                        if(vis[nx][ny] >= 0 || board[nx][ny] == 0) continue; 
                        vis[nx][ny] = 0; 
                        Q.push(make_pair(nx,ny));
                    }
                    mx = max(mx, area);
                }
            }

            mxp.push_back(mx);
        }
    }
    sort(mxp.begin(),mxp.end());
    cout << mxc << '\n';
    for(int i : mxp){
        cout << i << " ";
    }

}