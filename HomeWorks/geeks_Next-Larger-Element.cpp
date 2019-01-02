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
stack <int> s;

int main() {

    faster_io;

    cin >> N;
    range(i, 1, N) {
        cin >> arr[i];
    }

    s.push(arr[1]);
    range(i, 2, N) {
        while(!s.empty() && s.top() < arr[i]) {
            cout << arr[i] << " ";
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty()) {
        cout << "-1 ";
        s.pop();
    }

    return 0;
}
