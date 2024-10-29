/*
                                    ██╗     ██╗██████╗ ██████╗  █████╗ ██████╗ ██╗   ██╗
                                    ██║     ██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝
                                    ██║     ██║██████╔╝██████╔╝███████║██████╔╝ ╚████╔╝
                                    ██║     ██║██╔══██╗██╔══██╗██╔══██║██╔══██╗  ╚██╔╝
                                    ███████╗██║██████╔╝██║  ██║██║  ██║██║  ██║   ██║
                                    ╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝
 */
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>

/*
                                    ██████╗ ███████╗███████╗██╗███╗   ██╗███████╗███████╗
                                    ██╔══██╗██╔════╝██╔════╝██║████╗  ██║██╔════╝██╔════╝
                                    ██║  ██║█████╗  █████╗  ██║██╔██╗ ██║█████╗  ███████╗
                                    ██║  ██║██╔══╝  ██╔══╝  ██║██║╚██╗██║██╔══╝  ╚════██║
                                    ██████╔╝███████╗██║     ██║██║ ╚████║███████╗███████║
                                    ╚═════╝ ╚══════╝╚═╝     ╚═╝╚═╝  ╚═══╝╚══════╝╚══════╝
 */

using namespace std;

typedef string str;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<str> vstr;
typedef vector<pair<ll, ll>> v_p_ll_a_ll;
typedef vector<pair<ll, str>> v_p_ll_a_str;
typedef vector<pair<ll, char>> v_p_ll_a_char;
typedef vector<long long> vll;
typedef vector<db> vdb;
typedef vector<vector<long long>> vvll;
typedef vector<vector<int>> vvi;
typedef vector<vector<str>> vvstr;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef unordered_set<str> u_s_str;
typedef unordered_set<ll> u_s_ll;

#define sz(x) x.size()
#define re return
#define all(x) x.begin(), x.end()
#define lb(a, ele) lower_bound(a.begin(), a.end(), ele) - a.begin()
#define ub(a, ele) upper_bound(a.begin(), a.end(), ele) - a.begin()
#define hehe cout << "hehe" << "\n";
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define ln '\n'
#define endl '\n'

int mex(const vll &a)
{
    vector<bool> cnt(sz(a) + 1);
    for (auto &i : a)
    {
        if (i > sz(a) || i < 0)
            continue;
        cnt[i] = true;
    }
    for (int i = 0; i < sz(cnt); i++)
        if (!cnt[i])
            re i;
    re sz(a);
}

bool isPrime(ll n)
{
    if (n % 2 && n != 2)
        re false;
    for (ll i = 2; i * i <= n; i += 2)
        if (n % i == 0)
            re false;
    re true;
}

/*
                            ███╗   ███╗ █████╗ ██╗███╗   ██╗     ██████╗ ██████╗ ██████╗ ███████╗
                            ████╗ ████║██╔══██╗██║████╗  ██║    ██╔════╝██╔═══██╗██╔══██╗██╔════╝
                            ██╔████╔██║███████║██║██╔██╗ ██║    ██║     ██║   ██║██║  ██║█████╗
                            ██║╚██╔╝██║██╔══██║██║██║╚██╗██║    ██║     ██║   ██║██║  ██║██╔══╝
                            ██║ ╚═╝ ██║██║  ██║██║██║ ╚████║    ╚██████╗╚██████╔╝██████╔╝███████╗
                            ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝     ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
 */
void solves()
{
    ll n;
    cin >> n;
    vll a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(a[i], a[maxIndex]);
    }
    for (ll i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main()
{
    // freopen("samples.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    fast
    // ll t = 1;
    // cin >> t;
    // while (t--)
    solves();
}
