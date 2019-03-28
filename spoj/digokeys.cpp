#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
vi g[N];
int parent[N],u, visited[N], dist[N], cnt;

void output(int curr) {
	if(curr < 0) return;
	output(parent[curr]);
	cout<<curr+1<<" ";
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n;
    cin>>t;

    while(t--) {
    	memset(parent, -1, sizeof(parent));
    	cin>>n;
    	FOR(i, 0, n-1) {
    		g[i].clear();
    		cin>>cnt;
    		FOR(j, 0, cnt) {
    			cin>>u; u--;
    			g[i].push_back(u);
    		}
    		sort(g[i].begin(), g[i].end());
    	}

    	queue<int> q;
    	q.push(0);
    	parent[0]=-1;
    	memset(visited, false, sizeof(visited));
    	memset(dist, 0, sizeof(dist));
    	visited[0]=true; bool done = false;
    	while(!q.empty()) {
    		if(done) break;
    		int curr = q.front(); q.pop();
    		for(auto num: g[curr]) {
    			if(!visited[num]) {
    				visited[num] = true;
    				dist[num] = dist[curr]+1;
    				parent[num] = curr;
    				if(num == n-1) {
    					done = true;
    					break;
    				}
    				q.push(num);
    			}
    		}
    	}
    	if (!done)
    	{
    		cout<<"-1";
    	} else {
    		cout<<dist[n-1]<<endl;
    		output(parent[n-1]);
    	}
    	cout<<endl<<endl;
    }

    return 0;
}