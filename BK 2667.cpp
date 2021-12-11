#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second 

bool vis[26][26]; 
int n;
string board[26];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
vector<int> VArea;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> board[i];
    }


    int mxp = 0;
    int mxc = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '0' || vis[i][j]) { continue; }
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
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 
                        if(vis[nx][ny] || board[nx][ny] != '1') continue; 
                        vis[nx][ny] = 1; 
                        Q.push(make_pair(nx,ny));
                    }
                }
                VArea.push_back(area);
            }
        }
    }
    cout << mxc << endl;
    sort(VArea.begin(), VArea.end());
    for (int i : VArea){
        cout << i << '\n';
    }
    
}