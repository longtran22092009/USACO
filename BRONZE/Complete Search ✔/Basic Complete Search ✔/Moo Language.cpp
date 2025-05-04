#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    ll T; cin >> T;
    while (T--) {
        ll N, C, P; cin >> N >> C >> P;
        vector <string> nouns;
        vector <string> transitive_verbs;
        vector <string> intransitive_verbs;
        vector <string> conjunctions;

        for (ll i = 0; i < N; i++) {
            string word, type; cin >> word >> type;
            if (type == "noun") nouns.push_back(word);
            else if (type == "transitive-verb") transitive_verbs.push_back(word);
            else if (type == "intransitive-verb") intransitive_verbs.push_back(word);
            else conjunctions.push_back(word);
        }

        ll total_nouns = nouns.size(), total_intransitive_verbs = intransitive_verbs.size();
        ll total_transitive_verbs = transitive_verbs.size(), total_conjunctions = conjunctions.size();

        ll x = 0, y = 0, F = 0, used_comma = 0;

        if (total_nouns == 0 || (total_transitive_verbs == 0 && total_intransitive_verbs == 0) || P == 0) {
            F = 0;
        }

        else if (total_nouns == 1 && total_intransitive_verbs != 0) {
            F = 2;
            x = 1;
        }

        else {
            for (ll curr_x = 0; curr_x <= min(total_nouns, total_intransitive_verbs); curr_x++) {
                for (ll curr_y = 0; curr_y <= min(total_nouns / 2, total_transitive_verbs); curr_y++) {
                    if (curr_x + curr_y <= (min(total_conjunctions, P) + P) && (curr_x + curr_y*2) <= total_nouns) {

                        ll unused_nouns = total_nouns - curr_x - curr_y * 2;
                        if (unused_nouns > C) unused_nouns = C;
                        if (curr_y == 0 || total_transitive_verbs == 0) unused_nouns = 0;
                        ll used_conjuctions = (total_conjunctions == 0)? 0 : (curr_x + curr_y) / 2;
                        used_conjuctions = min(used_conjuctions, total_conjunctions);
                        
                        ll tmp_F = curr_x*2 + curr_y*3 + unused_nouns + used_conjuctions;
                        if (tmp_F > F) {
                            F = tmp_F;
                            x = curr_x;
                            y = curr_y;
                            used_comma = unused_nouns;
                        }
                    }
                }
            }
        }

        cout << F << endl;
        
        ll nouns_idx = 0, intransitive_verbs_idx = 0, transitive_verbs_idx = 0, conjunctions_idx = 0;
        bool odd = true;
        if ((x + y) % 2 == 0) odd = false;
        
        for (int i = 0; i < x+y; i++) {
            if (i != 0) cout << " ";

            if (i < x) {
                cout << nouns[nouns_idx] << " " << intransitive_verbs[intransitive_verbs_idx];
                ++nouns_idx;
                ++intransitive_verbs_idx;

                if (conjunctions_idx < total_conjunctions && total_conjunctions != 0 && ((odd && i % 2 != 0) || (!odd && i % 2 == 0))) {
                    cout << " " << conjunctions[conjunctions_idx];
                    ++conjunctions_idx;
                } else {
                    cout << ".";
                }
            }

            if (total_transitive_verbs != 0 && i >= x) {
                cout << nouns[nouns_idx] << " " << transitive_verbs[transitive_verbs_idx] << " ";
                ++nouns_idx;
                ++transitive_verbs_idx;
                cout << nouns[nouns_idx];
                ++nouns_idx;

                if (i == x+y-1) {
                    for (int j = 0; j < used_comma; j++) {
                        cout << ", " << nouns[nouns_idx];
                        ++nouns_idx;
                    }
                }

                if (conjunctions_idx < total_conjunctions && total_conjunctions != 0 && ((odd && i % 2 != 0) || (!odd && i % 2 == 0))) {
                    cout << " " << conjunctions[conjunctions_idx];
                    ++conjunctions_idx;
                } else {
                    cout << ".";
                }
            }
        }

        cout << endl;
    }
}
