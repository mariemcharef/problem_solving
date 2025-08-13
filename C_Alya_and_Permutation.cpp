
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void run(int n)
{
    bool power_of_two = 1;
    int biggest_power = 0;

    for (int i = 31; i >= 0; i--)
    {
        if ((n & (1 << i)) == (1 << i))
        {
            biggest_power = i;
            break;
        }
    }

    for (int i = biggest_power - 1; i >= 0; i--)
    {
        if ((n & (1 << i)) != 0)
        {
            power_of_two = 0;
            break;
        }
    }

    if (power_of_two)
    {
        ll k = (1LL << (biggest_power + 1)) - 2;
        cout << k << endl;
        for (int i = 1; i < n; i++)
        {
            if (!(i == (1LL << biggest_power) - 1 || i == (1LL << biggest_power) - 2))
                cout << i << " ";
        }
        cout << (1LL << biggest_power) - 1 << " " << (1LL << biggest_power) - 2 << " " << n;
    }
    else
    {
        ll k = (1LL << (biggest_power + 1)) - 1;
        cout << k << endl;
        int x = 0;
        for (int i = biggest_power - 1; i >= 0; i--)
        {
            if ((n & (1 << i)) == 0)
            {
                x += (1 << i);
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (!(i == x || i == (1LL << biggest_power) - 1))
            {
                cout << i << " ";
            }
        }
        cout << (1LL << biggest_power) - 1 << " " << x << n;
    }
}

bool isPowerOfTwo(long long n)
{
    return n > 0 && (n & (n - 1)) == 0;
}
int highestBitPos(long long n)
{
    if (n == 0)
        return -1;
    return (int)log2(n);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n, 0);
    if (isPowerOfTwo(n))
    {
        ans[n - 1] = n;
        ans[n - 2] = n - 1;
        ans[n - 3] = n - 2;
        ans[n - 4] = 1;
        int a = 2;
        for (int i = 0; i < n - 4; i++)
        {
            ans[i] = a;
            a++;
        }
    }
    else if (isPowerOfTwo(n - 1))
    {
        ans[n - 1] = n;
        ans[n - 2] = n - 1;
        ans[n - 3] = n - 2;
        ans[n - 4] = 1;
        int a = 2;
        for (int i = 0; i < n - 4; i++)
        {
            ans[i] = a;
            a++;
        }
    }
    else if (n % 2 == 0)
    {
        ans[n - 1] = n;
        int big_bit = highestBitPos(n);
        int c = (1ll << big_bit) - 1;
        ans[n - 2] = c;

        int b = 0;
        for (int i = 0; i < big_bit; i++)
        {
            if ((n & (1LL << i)) == 0)
            {
                b += (1LL << i);
            }
        }
        ans[n - 3] = b;
        int a = 1;

        for (int i = 0; i < n - 3; i++)
        {
            if (a != n && a != c && a != b)
            {
                ans[i] = a;
            }
            else
            {
                i--;
            }
            a++;
        }
    }
    else
    {
        ans[n - 1] = n;
        ans[n - 2] = n - 1;
        n--;
        int big_bit = highestBitPos(n);
        int c = (1ll << big_bit) - 1;
        ans[n - 2] = c;

        int b = 0;
        for (int i = 0; i < big_bit; i++)
        {
            if ((n & (1LL << i)) == 0)
            {
                b += (1LL << i);
            }
        }
        ans[n - 3] = b;
        int a = 1;

        for (int i = 0; i < n - 3; i++)
        {
            if (a != n && a != c && a != b)
            {
                ans[i] = a;
            }
            else
            {
                i--;
            }
            a++;
        }
        n++;
    }
    int k=0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            k = k & ans[i];
        else
            k = k | ans[i];
    }
    

    cout << k << endl;
    for (int i : ans)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
