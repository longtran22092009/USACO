#include <bits/stdc++.h>
using namespace std;
#define ll long long

int field[2001][2001], curr_time = 1, x = INT32_MAX;
  
void move(char direction, int step, int &curr_x, int &curr_y) {
    if (direction == 'N') {
        for (int i = 0; i < step; i++) {
            --curr_x;

            if (field[curr_x][curr_y] != -1) {
                x = min(x, curr_time - field[curr_x][curr_y]);
            }

            field[curr_x][curr_y] = curr_time;
            ++curr_time;
        }
    }
    if (direction == 'S') {
        for (int i = 0; i < step; i++) {
            ++curr_x;

            if (field[curr_x][curr_y] != -1) {
                x = min(x, curr_time - field[curr_x][curr_y]);
            }
            
            field[curr_x][curr_y] = curr_time;
            ++curr_time;
        }
    }
    if (direction == 'W') {
        for (int i = 0; i < step; i++) {
            --curr_y;

            if (field[curr_x][curr_y] != -1) {
                x = min(x, curr_time - field[curr_x][curr_y]);
            }
            
            field[curr_x][curr_y] = curr_time;
            ++curr_time;
        }
    }
    if (direction == 'E') {
        for (int i = 0; i < step; i++) {
            ++curr_y;

            if (field[curr_x][curr_y] != -1) {
                x = min(x, curr_time - field[curr_x][curr_y]);
            }
            
            field[curr_x][curr_y] = curr_time;
            ++curr_time;
        }
    }
}  

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;
    int curr_x = 1000, curr_y = 1000;
    memset(field, -1, sizeof(field));
    field[curr_x][curr_y] = 0;

    for (int i = 0; i < n; i++) {
        char dir; cin >> dir;
        int step; cin >> step;

        move(dir, step, curr_x, curr_y);
    }
    
    if (x == INT32_MAX) cout << -1;
    else cout << x;
}

 