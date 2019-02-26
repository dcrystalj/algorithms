#include <stdio.h>
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <assert.h>
#include <stack>
#include <deque>
#include <bits/stdc++.h>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <sstream>  // istringstream buffer(myString);
// #include <boost/functional/hash.hpp>

using namespace std;

#define endl "\n";
#define bit(x, i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x; example: x=12;  1100 => 100 => 4
#define LL long long
#define ULL unsigned long long
#define inf 1000000007
#define mod 1000000007
#define PII pair<int, int>
#define V vector
#define VI vector<int>
#define VS vector<string>
#define ALL(x) x.begin(), x.end() //handy for function like "sort()"
#define pi 3.14159265358979323846
const ULL INF = 1e18L + 5;
// set a to the maximum of a and b
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
// conversion
string removeZeros(string str) { return str.erase(0, min(str.find_first_not_of('0'), str.size()-1)); } // remove leading zeros
#define char2int(c) (c-'0')
#define int2char(i) (static_cast<char>(i))
#define bin2int(bin) (bitset< 1001 >(bin).to_ulong())
#define int2bin(i) removeZeros(bitset< 1001 >( i ).to_string())
// str.erase(0, min(str.find_first_not_of('0'), str.size()-1)); // remove leading zeros


// works for unordered_set, unordered_map..
#define HMAP unordered_map
#define SET unordered_set
#define HAS(umap, key) (umap.find(key) != umap.end())
#define COUNTER(m, j) if (HAS(m, j)) { m[j]++; } else { m[j] = 1; }
// loop
#define FOREACH(vec, i) for (auto i = vec.begin(); i!= vec.end(); i++)
// read line
#define READ_INTS(vec, n) vector<LL> vec(n); for (LL i=0; i<n; i++) { cin >> vec[i]; }; cin.ignore();
#define READ_DOUBLES(vec, n) vector<double> vec (n); FOREACH(vec, i) { cin >> *i; }; cin.ignore();
#define READ_STRING(vec) string vec; getline(cin, vec);
#define READ_INT(i) LL i; cin >> i; cin.ignore();
// #define SPLIT_STRINGS(vec, str) istringstream iss(str); vector<string> vec((istream_iterator<string>(iss)), istream_iterator<string>());
// debug
#define dd(var) cerr << #var << "=" << (var) << " | "
#define ddv(vec) FOREACH(vec, i) { cout << *i << " "; } cout << endl;
#define ddvv(vec) for(auto& i:vec) { for(auto& j:i) { cout <<  j << " "; }; cout << endl };

void solve() {
    READ_INT(N);
    READ_INT(W);
    vector<LL> w(N);
    vector<LL> v(N);
    LL sum_values = 0;
    for (LL i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
        sum_values += v[i];
    }

    vector <LL> dp(sum_values+1, INF);
    dp[0] = 0;
    for (LL i = 0; i < N; i++) {
        for (LL j = sum_values-v[i]; j >= 0; --j) {
            REMIN(dp[j + v[i]], w[i] + dp[j])
        }
    }
    
    LL res = 0;
    for (LL i = 0; i <= sum_values; i++) {
        if (dp[i] <= W) {
            REMAX(res, i);
        }
    }
    cout << res;
}


int main()
{  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
//   READ_INT(t);
//   for (LL i = 0; i < t; i++) {
    solve();
//   }
  return 0;
}
