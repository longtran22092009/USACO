#include <bits/stdc++.h>
using namespace std;
#define ll long long

void pour(ll &a_bucket, ll &a_milk, ll &b_bucket, ll &b_milk) {
    int pour_amount = min(a_milk, b_bucket - b_milk);
    a_milk -= pour_amount;
    b_milk += pour_amount;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    ll bucket1, milk1, bucket2, milk2, bucket3, milk3;
    for (int i = 0; i <= 3; i++) 
        cin >> bucket1 >> milk1 >> bucket2 >> milk2 >> bucket3 >> milk3;
    
    for (int i = 1; i <= 33; i++) {
        pour(bucket1, milk1, bucket2, milk2);
        pour(bucket2, milk2, bucket3, milk3);
        pour(bucket3, milk3, bucket1, milk1);
    }
    pour(bucket1, milk1, bucket2, milk2);

    cout << milk1 << endl << milk2 << endl << milk3;
}