#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int x, y; cin >> x >> y;
    int curr_pos = x, far = 1, dis = 0;

    if (x == y) {
        cout << 0;
    } 
    else if (x < y) {
        while ((x + far) < y) {
            dis += (x + far) - curr_pos;
            curr_pos = x + far;
            far *= 2;

            dis += curr_pos - (x - far);
            curr_pos = x - far;
            far *= 2;
        }
        dis += y - curr_pos;

        cout << dis;
    } else {
        while ((x - far*2) > y) {
            dis += (x + far) - curr_pos;
            curr_pos = x + far;
            far *= 2;

            dis += curr_pos - (x - far);
            curr_pos = x - far;
            far *= 2;
        }
        dis += (x + far) - curr_pos;
        curr_pos = x + far;
        dis += curr_pos - y;
        
        cout << dis;
    }
}
