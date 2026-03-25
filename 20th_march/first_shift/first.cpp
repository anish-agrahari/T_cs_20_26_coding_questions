#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    // key = "sender receiver amount"
    map<string, vector<int>> mp;

    for (int i = 0; i < N; i++) {
        string sender, receiver;
        int amount, time;

        cin >> sender >> receiver >> amount >> time;

        string key = sender + " " + receiver + " " + to_string(amount);
        mp[key].push_back(time);
    }

    set<string> result;

    for (auto &it : mp) {
        string key = it.first;
        vector<int> times = it.second;

        sort(times.begin(), times.end());

        for (int i = 1; i < times.size(); i++) {
            if (times[i] - times[i - 1] <= 60) {
                result.insert(key + " " + to_string(times[i - 1]));
                result.insert(key + " " + to_string(times[i]));
            }
        }
    }

    // print result
    for (auto &r : result) {
        cout << r << endl;
    }

    return 0;
}
