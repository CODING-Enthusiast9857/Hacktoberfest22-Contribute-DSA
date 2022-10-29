// meet in the middle generally when the number belongs to range 25 to 40, so just
// do operations for half half part then combine them both to get actual answer

// leetcode generate equal element subset sum such that absolute difference remains less
#define full(v1) v1.begin(), v1.end()
#define pb push_back
class Solution
{
public:
        int minimumDifference(vector<int> &ar)
        {
                int n = ar.size();
                int sum = 0;
                for (int i = 0; i < n; i++)
                {
                        sum += ar[i];
                }
                vector<int> first_half[n / 2 + 1];
                vector<int> second_half[n / 2 + 1];
                int x = (1 << (n / 2));
                for (int i = 0; i < x; i++)
                {
                        int ct = 0;
                        int bit = 0;
                        for (int j = 0; j < n / 2; j++)
                        {
                                if (i & (1 << j))
                                {
                                        ct += ar[j];
                                        bit++;
                                }
                        }
                        first_half[bit].pb(ct);
                        ct = 0;
                        for (int j = 0; j < n / 2; j++)
                        {
                                if (i & (1 << j))
                                        ct += ar[j + n / 2];
                        }
                        second_half[bit].pb(ct);
                }
                for (auto &i : second_half)
                        sort(full(i));
                int mn = 1e9;
                for (int i = 0; i <= n / 2; i++)
                {
                        int j = n / 2 - i;
                        for (auto q : first_half[i])
                        {
                                int x = sum / 2 - q;
                                int k = lower_bound(full(second_half[j]), x) - second_half[j].begin();
                                if (k == second_half[j].size())
                                {
                                        int x = q + second_half[j][k - 1];
                                        int x1 = sum - x;
                                        mn = min(mn, abs(x - x1));
                                }
                                else if (k == 0)
                                {
                                        int x = q + second_half[j][k];
                                        int x1 = sum - x;
                                        mn = min(mn, abs(x - x1));
                                }
                                else
                                {
                                        int x = q + second_half[j][k - 1];
                                        int x1 = sum - x;
                                        mn = min(mn, abs(x - x1));
                                        x = q + second_half[j][k];
                                        x1 = sum - x;
                                        mn = min(mn, abs(x - x1));
                                }
                        }
                }
                return mn;
        }
};

// xor paths: total steps would be n+m-2 so just calculate half from 1,1 and then start
// going from n,m to 1,1 and calculating rest steps and check xor if valid add to ans
unordered_map<int, int> mp[20][20];
void calc(int i, int j, int steps, int xr)
{
        if (steps == first)
        {
                // is(xr);
                mp[i][j][xr ^ ar[i][j]]++;
                return;
        }
        if (i + 1 < n)
                calc(i + 1, j, steps + 1, xr ^ ar[i][j]);
        if (j + 1 < m)
                calc(i, j + 1, steps + 1, xr ^ ar[i][j]);
}
void calc1(int i, int j, int steps, int xr)
{
        if (steps == n + m - 2 - first)
        {
                sum += (mp[i][j][k ^ xr]);
                return;
        }
        if (i - 1 >= 0)
                calc1(i - 1, j, steps + 1, xr ^ ar[i][j]);
        if (j - 1 >= 0)
                calc1(i, j - 1, steps + 1, xr ^ ar[i][j]);
}
