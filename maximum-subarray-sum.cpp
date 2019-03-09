#include <bits/stdc++.h>

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
    LL n = 0, sum = 0, best = 0, in = 0;
    pair<LL, LL> p = {0, 0};
    cin >> n;
    // only sum
    // for (LL i = 0; i < n; i++) {
    //     cin >> in;
    //     sum = max(sum+in, in);
    //     best = max(sum, best);
    // }
    // cout << best << endl;
    //
    // sum with index from to
    for (LL i = 0; i < n; i++) {
        cin >> in;
        if (in >= sum + in) {
            sum = in;
            if (sum >= best) {
                p = {i, i};
                best = sum;
            }
        } else {
            sum += in;
            if (sum >= best) {
                best = sum;
                p = {p.first, i};
            }
        }
    }
    cout << best << " " << p.first << " " << p.second << endl;
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
