#include<bits/stdc++.h>

using namespace std;

int L_num , Find_x ; //L_numΪ�����������ݸ��� Find_xΪ����Ŀ��x

int Search( int L[] , int x )
{
	int j = 1 ;
	while( j <= L_num && x > L[j] )
	{
	 j++ ;
		if ( x < L[j] || j > L_num  )
		{
			j = 0 ;
		}
	}
	return j ;

} 

int main()
{
	int L[100] , ans ;//�ݶ���С������vector���ж�̬����
	cin >> L_num >> Find_x ; 
	for( int i = 1 ; i <= L_num ; i++ )
	{
		cin >> L[i] ;
	}
	ans = Search( L , Find_x) ;
	cout << ans ;
	
}
