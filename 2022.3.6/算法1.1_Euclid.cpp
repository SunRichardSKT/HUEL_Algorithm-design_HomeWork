#include<bits/stdc++.h>

using namespace std;

int Euclid( int m , int n )
{
	int r = 0 ;
		while( m > 0 )
	{
		r = n % m ;
		n = m ;
		m = r ;
	}
	return n ;
} // Euclid 算法实现部分

int main()
{
	int x , y , ans ;
	cin >> x >> y ;
	ans = Euclid( x , y );
	cout << ans ;
}
