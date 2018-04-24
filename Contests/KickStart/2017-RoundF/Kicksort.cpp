#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 1000000+10
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

// void print(vi &v){
// 	F(i, 0, v.size()){
// 		cout<<v[i]<<" ";
// 	}
// 	cout<<endl;
// }

bool findAns(vi &v, int maxm,int minm){
	int n = v.size();
	if (n==2)
	{
		return true;
	}
	int mid = (n-1)/2;
	if (v[mid]==maxm || v[mid]==minm)
	{
		if (v[mid]==minm)
		{
			v.erase(v.begin()+mid);
			// print(v);
			return findAns(v,maxm,minm+1);
		}else{
			v.erase(v.begin()+mid);
			// print(v);
			return findAns(v,maxm-1,minm);
		}
		
	}else{
		return false;
	}

}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	int t,n;
	cin>>t;

	F(tn, 1, t+1){
		cin>>n;
		vi v(n);

		F(i, 0, n){
			cin>>v[i];
		}

		bool poss = findAns(v,n,1);
		cout<<"Case #"<<tn<<": ";
		if (poss)
		{
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}

	return 0;
}