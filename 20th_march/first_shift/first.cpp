#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    vector<pair<int,int>> pairs;

    for (char &c : line)
        if (c == ',') c = ' ';

    stringstream ss(line);
    string token;

    while (ss >> token) {
        if (token.size() >= 2) {
            int first  = token[0] - '0';
            int second = token[1] - '0';
            pairs.push_back({first, second});
        }
    }

    sort(pairs.begin(), pairs.end());

    for (int i = 0; i < (int)pairs.size(); i++) {
        cout << pairs[i].first << pairs[i].second;
        if (i != (int)pairs.size() - 1) cout << ",";
    }

    return 0;
}
