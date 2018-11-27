#include <bits/stdc++.h> // all c++ libraries

// defines
#define faster_io       ios_base::sync_with_stdio(false);cin.tie()
#define rep(i,a)        for(int i=0;i<a;i++)
#define rrep(i,a)       for(int i=a-1,i>=0;i--)
#define range(i,a,b)    for(int i=a;i<=b;i++)
#define rrange(i,a,b)   for(int i=a;i>=b;i--)
#define rangev(i,a)     for(int i=0;i<a.size();i++)
#define rrangev(i,a)    for(int i=a.size()-1;i>=0;i--)
#define clr(a)          memset(a, 0, sizeof(a))
#define all(a)          a.begin(), a.end()
#define mp              make_pair
#define pb              push_back
#define st              first
#define nd              second
#define MX              200005


using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <pii> vii;
typedef pair <int, pii> pip;

const ll INF = 1e9 + 100;
const ll MOD = 1e9 + 7;


string word;
int N;
int dp[MX];

void check() {
    int len = word.size();
    range(i, 1, len - 1) {
        dp[i] = (word[i] == word[i - 1]) ? dp[i - 1] + 1 : dp[i - 1];
    }
}

int main() {

    faster_io;

    cin >> word >> N;
    check();
    range(i, 1, N) {
        int ll, rr;
        cin >> ll >> rr;
        cout << dp[--rr] - dp[--ll] << "\n";
    }

    return 0;
}
