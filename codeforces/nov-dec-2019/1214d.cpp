#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

int n,m,x,y;
vector<vector<char>> arr;
vector<vector<bool>> visited, visited2;
map<int, int> grps;

bool valid(int nx, int ny) {
    return nx >= 1 && nx <= n && ny >= 1 && ny <= m;
}

void dfs(ii v) {
    int x,y,nx,ny; tie(x, y) = v;
    visited[x][y] = true;
    vii nxt = {{x + 1, y}, {x, y + 1}};
    for(ii to : nxt) {
        tie(nx,ny) = to;
        if(!valid(nx, ny) || visited[nx][ny] || arr[nx][ny] == '#') continue;
        dfs(to);
    }
}

void dfs2(ii v) {
    int x,y,nx,ny; tie(x, y) = v;
    visited2[x][y] = true;
    vii nxt = {{x - 1, y}, {x, y - 1}};
    for(ii to : nxt) {
        tie(nx,ny) = to;
        if(!valid(nx, ny) || visited2[nx][ny] || arr[nx][ny] == '#') continue;
        dfs2(to);
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>m; arr.resize(n+1, vector<char>(m+1));
    visited.resize(n+1, vector<bool> (m+1, false));
    visited2.resize(n+1, vector<bool> (m+1, false));
    FOR(i, 1, n+1) {
        FOR(j, 1, m+1) {
            cin>>arr[i][j];
        }
    }
    dfs({1, 1});
    if(!visited[n][m]) {
        cout<<0;
        return 0;
    }
    dfs2({n,m});
    FOR(i, 1, n+1) {
        FOR(j, 1, m+1) {
            if(visited[i][j] && visited2[i][j]) {
                grps[i + j - 1]++;
            }
        }
    }
    for(auto itr : grps) {
        if(itr.ss == 1 && itr.ff != 1 && itr.ff != (n + m - 1)) {
            cout<<1;
            return 0;
        }
    }
    cout<<2;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}