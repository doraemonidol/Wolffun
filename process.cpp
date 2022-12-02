#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
ofstream os("solution.txt");
//ofstream os("divide-sol.txt");

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l, long long h) {
    return l + rd() % (h - l + 1);
}

int nmax = 0;
void go(vector <ii> p, int x, int y, bool l, bool r, bool u, int pMove, int ppMove)
{
    if (y == 15)
    {
        if (p.size() > 23)
        {
            int res[16][6];
            for (int i = 0; i < 16; i++)
                for (int j = 0; j < 6; j++)
                    res[i][j] = 0;

            for (auto e:p)
                res[e.second][e.first] = 1;

            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    os << res[i][j] << " ";
                }
            }
            nmax++;
            if (nmax == 5000) exit(0);
            os << endl;
        }
        return;
    }
    if (p.size() >= 25) return;
    int type = Rand(1, 3);
    switch (type)
    {
    case 1:
    {
        if (l && x != 0 && ppMove != 2)
        {
            p.push_back(make_pair(x - 1, y));
            go(p, x - 1, y, true, false, true, 1, pMove);
            p.pop_back();
        }
        int t2 = Rand(1, 2);
        switch(t2)
        {
        case 1:
        {
            if (r && x != 5 && ppMove != 1)
            {
                p.push_back(make_pair(x + 1, y));
                go(p, x + 1, y, false, true, true, 2, pMove);
                p.pop_back();
            }
            break;
        }
        case 2:
        {
            if (u && y != 15)
            {
                p.push_back(make_pair(x, y + 1));
                go(p, x, y + 1, true, true, true, 3, pMove);
                p.pop_back();
            }
            break;
        }
        }
        break;
    }
    case 2:
    {
        if (r && x != 5 && ppMove != 1)
        {
            p.push_back(make_pair(x + 1, y));
            go(p, x + 1, y, false, true, true, 2, pMove);
            p.pop_back();
        }
        int t2 = Rand(1, 2);
        switch(t2)
        {
        case 1:
        {
            if (l && x != 0 && ppMove != 2)
            {
                p.push_back(make_pair(x - 1, y));
                go(p, x - 1, y, true, false, true, 1, pMove);
                p.pop_back();
            }
            break;
        }
        case 2:
        {
            if (u && y != 15)
            {
                p.push_back(make_pair(x, y + 1));
                go(p, x, y + 1, true, true, true, 3, pMove);
                p.pop_back();
            }
            break;
        }
        }
        break;
    }
    case 3:
    {
        if (u && y != 15)
        {
            p.push_back(make_pair(x, y + 1));
            go(p, x, y + 1, true, true, true, 3, pMove);
            p.pop_back();
        }
        int t2 = Rand(1, 2);
        switch(t2)
        {
        case 1:
        {
            if (r && x != 5 && ppMove != 1)
            {
                p.push_back(make_pair(x + 1, y));
                go(p, x + 1, y, false, true, true, 2, pMove);
                p.pop_back();
            }
            break;
        }
        case 2:
        {
            if (l && x != 0 && ppMove != 2)
            {
                p.push_back(make_pair(x - 1, y));
                go(p, x - 1, y, true, false, true, 1, pMove);
                p.pop_back();
            }
            break;
        }
        }
        break;
    }
    }
}

int main()
{
    srand(time(NULL));
    os << "5000\n";
    vector <ii> p;
    for (int i = 0; i < 6; i++)
    {
        p.push_back({i, 0});
        go(p, i, 0, false, false, true, -1, -1);
        p.pop_back();
    }
    os.close();
    return 0;
}
