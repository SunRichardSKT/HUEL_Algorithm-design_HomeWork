#include<cstdio>
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

void FindMaxMin( int *a, int left , int right , int *max , int *min )
{
    int mid ;
    int lmax=0 , lmin = inf ,rmax = 0 , rmin = inf ;
    if( left == right )
    {
        *max = a[ left ] ;
        *min = a[ right ] ;
        return ;
    }
    mid = ( left + right ) / 2 ;
    FindMaxMin( a , left , mid , &lmax , &lmin ) ;
    FindMaxMin( a , mid+1 , right , &rmax , &rmin ) ;
    if( lmax > rmax )
    {
        *max=lmax;
    }
    else
    {
        *max=rmax;
    }
    if(lmin<rmin)
    {
        *min=lmin;
    }
    else
    {
        *min=rmin;
    }
    return ;
}
int main()
{
    int max , min , k , a[ 200 ] ;  
    int count ;
    while( cin >> k && k )
    {
        for( count=0 ; count<k ; count++ )
            cin >> a[count] ;
        FindMaxMin( a , 0 , k - 1 , &max , &min ) ;
       cout << max << ' ' << min << endl ;
    }

}
