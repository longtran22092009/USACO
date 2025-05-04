#include <bits/stdc++.h>
using namespace std;
#define ll long long

int myComp(pair <string, int> &a, pair <string, int> &b) {
    return a.second > b.second;
} 

void check(int &cnt, string &leader, vector <pair <string, int>> cow_milk) {
    if (cow_milk[0].second == cow_milk[1].second) {
        if (cow_milk[1].second == cow_milk[2].second && leader != "Three") {
            ++cnt;
            leader = "Three";
        } else if (cow_milk[1].second != cow_milk[2].second && leader != cow_milk[0].first + cow_milk[1].first) {
            ++cnt;
            leader = cow_milk[0].first + cow_milk[1].first;
        }
    } else {
        if (leader != cow_milk[0].first) {
            ++cnt;
            leader = cow_milk[0].first;
        }
    }
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int n; cin >> n;
    vector <pair <string, int>> cow_milk = {{"Bessie", 7}, {"Elsie", 7}, {"Mildred", 7}};
    set <tuple <int, string, int>> input;

    int cnt = 0;
    string curr_display = "Three";

    for (int i = 0; i < n; i++) {
        int day, change;
        string cow;
        cin >> day >> cow >> change;

        input.insert({day, cow, change});
    }

    for (auto x : input) {
        if (cow_milk[0].first == get<1>(x)) 
            cow_milk[0].second += get<2>(x);
        else if (cow_milk[1].first == get<1>(x)) 
            cow_milk[1].second += get<2>(x);
        else 
            cow_milk[2].second += get<2>(x);

        sort(cow_milk.begin(), cow_milk.end(), myComp);
        check(cnt, curr_display, cow_milk);
    }

    cout << cnt;
}
