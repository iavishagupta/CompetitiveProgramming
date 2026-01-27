#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi construct(int N, int C)
{
    vector<int> a(N);
    iota(a.begin(), a.end(), 1);   // [1, 2, 3, ..., N]
    int remaining = C - (N - 1);

    for (int i = N - 2; i >= 0; i--) {
        int reverse_idx = min(N - i - 1, remaining);
        reverse(a.begin() + i, a.begin() + i + reverse_idx + 1);
        remaining -= reverse_idx;
    }
    return a;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, C;
        cin >> N >> C;

        int minCost = N - 1;
        int maxCost = (N * (N + 1)) / 2 - 1;

        cout << "Case #" << tc << ": ";

        if (C < minCost || C > maxCost) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vi ans = construct(N, C);

        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
