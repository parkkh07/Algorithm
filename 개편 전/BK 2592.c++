#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


int main(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    cout << accumulate(v.begin(), v.end(),0) / v.size() << endl;
    int b = 0;
    int c;
    sort(v.begin(), v.end());
    for (int i = 0; i < 10; i++){
        if (b <= upper_bound(v.begin(), v.end(), v[i]) - lower_bound(v.begin(), v.end(), v[i])){
            b = upper_bound(v.begin(), v.end(), v[i]) - lower_bound(v.begin(), v.end(), v[i]);
            c = v[i];
        }
    }
    cout << c << endl;
}