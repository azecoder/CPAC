#include <bits/stdc++.h> // all c++ libraries

// defines
#define faster_io       ios_base::sync_with_stdio(false);cin.tie()
#define range(i,a,b)    for(size_t i=a;i<=b;i++)
#define rrange(i,a,b)   for(size_t i=a;i>=b;i--)
#define mp              make_pair
#define pb              push_back
#define st              first
#define nd              second
#define MX              400005


using namespace std;

typedef pair <int, int> pii;

int N;
int number, ans[205];
priority_queue < pii > numbers;
set <int> cube;

int main() {

    faster_io;

    cin >> N;
    range(i, 1, 2 * N) {
        cin >> number;
        numbers.push(mp(number, i));
    }
    int ind = 0;
    while(!numbers.empty()) {
        cube.insert(numbers.top().st);
        ans[numbers.top().nd] = 1 + ind++ % 2;
        numbers.pop();
    }
    cout << cube.size() * cube.size() << "\n";
    range(i, 1, 2 * N) {
        cout << ans[i] << " ";
    }

    return 0;
}
