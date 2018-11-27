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


int N;
int arr[MX];

int main() {

    faster_io;

    cin >> N;
    range(i, 1, N) {
        cin >> arr[i];
    }

    int a_ind = 1, b_ind = N;
    int a_cnt = 0, b_cnt = 0;
    int last = 1;
    while(a_ind < b_ind) {
        int tm = min(arr[a_ind], arr[b_ind]);
        arr[a_ind] -= tm;
        arr[b_ind] -= tm;
        if(arr[a_ind] == 0) {
            a_ind++;
            a_cnt++;
            last = 0;
        }
        if(arr[b_ind] == 0) {
            b_ind--;
            b_cnt++;
            last = 1;
        }
    }
    if(arr[a_ind] + arr[b_ind] > 0) {
        if(last) {
            a_cnt++;
        } else {
            b_cnt++;
        }
    }

    cout << a_cnt << " " << b_cnt;

    return 0;
}
