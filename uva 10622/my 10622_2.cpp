/*
 * 10622.cpp
 * Another buggy code by mostafa_saad
 *
 *  Created on: Oct 25, 2009
 */


#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n) 		for(int i=(j);i>=(int)(n);--i)
#define repa(v)				repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)			repi(i, 0, sz(v))
#define lp(i, cnt)			repi(i, 0, cnt)
#define lpi(i, s, cnt)		repi(i, s, cnt)
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back
#define MP					make_pair

typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef long long         ll;
typedef long double   	  ld;

const int OO = (int)1e8;	//Small -> WRONG, Large -> OVERFLOW

const double PI  = acos(-1.0);
const double EPS = (1e-7);

int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

//evaluate b^p without having overflow
ll mpow_(ll b, ll p) {
	ll ret = 1;
	for (int i = 0; i < p; ++i) {
		if(ret > LONG_LONG_MAX/b)
			return LONG_LONG_MAX;
		ret *= b;
	}
	return ret;
}

ll mpow(ll b, ll p) {
	if(p == 0)	return 1;
	ll sq = mpow(b, p/2);
	if(sq == LONG_LONG_MAX || sq > LONG_LONG_MAX/sq)	return LONG_LONG_MAX;
	sq = sq*sq;

	if(p%2 == 1) {
		if(sq > LONG_LONG_MAX/b)	return LONG_LONG_MAX;
		sq = sq*b;
	}
	return sq;
}

// is there any b such that x = b^p
bool pass(ll x, ll p) {
	ll l = 1, u = 1LL<<32;

	while(l <= u) {	// as increasing b give higher value, we can binary search
		ll mid = (u+l)/2, res = mpow(mid, p);
		if(res == x)	return true;
		if(res < x)		l = mid+1;
		else 			u = mid-1;
	}

	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
#endif

	ll x;
	while(cin>>x && x) {
		ll p;
		if(x >= 0)
			for (p = 32; p >= 1 && !pass(x, p); --p);	// Brute force on all possible powers
		else
			for (p = 31; p >= 1 && !pass(abs(x), p); p -= 2);	// Brute force on all possible odd powers
		cout<<p<<"\n";
	}



	return 0;
}
