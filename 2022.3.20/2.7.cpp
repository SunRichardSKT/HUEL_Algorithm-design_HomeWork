#include<bits/stdc++.h>
using namespace std ;
int flag ;
int Findmax(int node[] , int length)
{
	int max = node[0] ; flag = 0 ;
	for( int i = 1 ; i < length ; i++ )
	{
		if( max < node[i] ) max = node[i] ; flag = i ;
	}
	return max ;
}

int main()
{
	int num[100] ; int count ;
	cin >> count ;
	for( int i = 0 ; i < count ; i++ )
	{
		cin >> num[i] ;
	}
	cout << Findmax(num,sizeof(num)) << ' ' << flag ;
	
 } 
