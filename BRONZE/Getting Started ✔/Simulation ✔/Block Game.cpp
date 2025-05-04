#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    map <char, int> freq;

    for (int i = 0; i < n; i++) {
        string upFace_card, downFace_card;
        cin >> upFace_card >> downFace_card;

        map <char, int> upCnt;
        map <char, int> downCnt;

        for (auto x : upFace_card) upCnt[x]++;
        for (auto x : downFace_card) downCnt[x]++;

        for (auto it : upCnt) {
            if (downCnt.find(it.first) != downCnt.end())
                freq[it.first] += max(it.second, downCnt[it.first]);
            else
                freq[it.first] += it.second;
        }

        for (auto it : downCnt) {
            if (upCnt.find(it.first) == upCnt.end())
                freq[it.first] += it.second;
        }
    }

    for (auto word : alphabet) {
        if (freq.find(word) == freq.end()) cout << 0 << endl;
        else cout << freq[word] << endl;
    }
}

