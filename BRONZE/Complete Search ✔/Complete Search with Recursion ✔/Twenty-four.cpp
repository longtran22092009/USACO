#include <bits/stdc++.h>
using namespace std;
#define ll long long

int calculator (int option, int a, int b) {
    if (option == 1) return a + b;
    else if (option == 2) return a - b;
    else if (option == 3) return a * b;
    else {
        if (b == 0 || a % b != 0) return INT32_MAX;
        return a / b;
    }
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int N; cin >> N;

    while (N--) {
        vector <int> cards(4);
        for (auto &x : cards) cin >> x;
        sort(cards.begin(), cards.end());

        int maxAns = INT32_MIN;
        do {
            for (int op1 = 1; op1 <= 4; op1++) {
                for (int op2 = 1; op2 <= 4; op2++) {
                    for (int op3 = 1; op3 <= 4; op3++) {
                        // Case (a,b)(c,d);
                        int a = calculator(op1, cards[0], cards[1]);
                        if (a == INT32_MAX) continue;

                        int b = calculator(op2, cards[2], cards[3]);
                        if (b == INT32_MAX) continue;

                        int c = calculator(op3, a, b);
                        if (c == INT32_MAX) continue;

                        if (c <= 24) maxAns = max(maxAns, c);
                    }
                }
            }

            for (int op1 = 1; op1 <= 4; op1++) {
                for (int op2 = 1; op2 <= 4; op2++) {
                    for (int op3 = 1; op3 <= 4; op3++) {
                        // Case (((a,b),c),d);
                        int a = calculator(op1, cards[0], cards[1]);
                        if (a == INT32_MAX) continue;

                        int b = calculator(op2, a, cards[2]);
                        if (b == INT32_MAX) continue;

                        int c = calculator(op3, b, cards[3]);
                        if (c == INT32_MAX) continue;

                        if (c <= 24) maxAns = max(maxAns, c);
                    }
                }
            }
        }
        while (next_permutation(cards.begin(), cards.end()));

        cout << maxAns << endl;
    }
}
