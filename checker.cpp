#include <bits/stdc++.h>
using namespace std;

ifstream is("divide-sol.txt");

int main()
{
    int n; is >> n;
    for (int cas = 0; cas < n; cas++) {
        int a[6][16], cnt = 0;
        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 6; j++) {
                is >> a[j][i];

                cnt += a[j][i];
            }
        if (cnt < 23 || cnt > 25) {
            cout << cas << " ";
        }
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 5; j++)
            if (a[j][i] && a[j][i + 1] && a[j + 1][i] && a[j + 1][i + 1]) {
                cout << cas << " " << i << " - " << j << "\n";
            }
    }
    is.close();

    return 0;
}
