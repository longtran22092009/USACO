#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    char board[3][3];
    set <char> win_1_cow;
    set <pair <char, char>> win_2_cow;

    // Parse the input;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }

    // Check for individual cows and two-cow teams win in rows;
    for (int i = 0; i < 3; i++) {
        set <char> diff_char;
        for (int j = 0; j < 3; j++) {
            diff_char.insert(board[i][j]);
        }

        if (diff_char.size() == 1) win_1_cow.insert(*diff_char.begin());
        if (diff_char.size() == 2) {
            win_2_cow.insert({*diff_char.begin(), *prev(diff_char.end())});
        }
    }

    // Check for individual cows and two-cow teams win in columns;
    for (int i = 0; i < 3; i++) {
        set <char> diff_char;
        for (int j = 0; j < 3; j++) {
            diff_char.insert(board[j][i]);
        }
        
        if (diff_char.size() == 1) win_1_cow.insert(*diff_char.begin());
        if (diff_char.size() == 2) {
            win_2_cow.insert({*diff_char.begin(), *prev(diff_char.end())});
        }
    }

    // Check for individual cows and two-cow teams win in diagonals;
    set <char> diff_char;
    diff_char.insert(board[0][0]);
    diff_char.insert(board[1][1]);
    diff_char.insert(board[2][2]);

    if (diff_char.size() == 1) win_1_cow.insert(*diff_char.begin());
    if (diff_char.size() == 2) {
        win_2_cow.insert({*diff_char.begin(), *prev(diff_char.end())});
    }
    
    diff_char.clear();
    diff_char.insert(board[0][2]);
    diff_char.insert(board[1][1]);
    diff_char.insert(board[2][0]);

    if (diff_char.size() == 1) win_1_cow.insert(*diff_char.begin());
    if (diff_char.size() == 2) {
        win_2_cow.insert({*diff_char.begin(), *prev(diff_char.end())});
    }

    cout << win_1_cow.size() << endl << win_2_cow.size();
}

 