/*
count no of digit form 0 to n where it does not contain digit 4
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> digits;
int dp[20][2][2];
int len;
int dfs(int pos, int tight, int leadingZero)
{
    if (pos == len)
    {
        return 1;
    }
    int &res = dp[pos][tight][leadingZero];
    if (res != -1)
        return res;
    res = 0;

    int limit = tight ? digits[pos] : 9;
    for (int d = 0; d <= limit; ++d)
    {
        if (d == 4)
        {
            continue;
            // forbid digit 4
        }
        int nextTight = tight && (d == limit);
        int nextLeadingZero = leadingZero && (d == 0);
        res += dfs(pos + 1, nextTight, nextLeadingZero);
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    digits.clear();
    while (n > 0)
    {
        int rem = n % 10;
        digits.push_back(rem);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    len = digits.size();
    for (int pos = 0; pos <= 19; pos++)
    {
        for (int tight = 0; tight <= 1; tight++)
        {
            for (int leadingZero = 0; leadingZero <= 1; leadingZero++)
            {
                dp[pos][tight][leadingZero] = -1;
            }
        }
    }

    cout << f(0, 1, 1);
}
int main()
{
    solve()

        return 0;
}