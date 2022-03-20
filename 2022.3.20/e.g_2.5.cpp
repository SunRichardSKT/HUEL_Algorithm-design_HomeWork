#include<bits/stdc++.h>

using namespace std ;

typedef struct node
{
	int x ;
	int y ;
} poi ;
 
poi point[20] ;//结构体存点集 
int flag[20] ; //距中线范围内点集序号集 

bool rule_x ( poi num_1 , poi num_2 )
{
return num_1.x < num_2.x ;
} //定义sort关于x排序规则 
bool rule_y ( int a , int b  )
{
return point[a].y < point[b].y ;
} //定义sort关于y排序规则 

double Distance( int i , int j )
{
	return sqrt( ( point[i].x - point[j].x ) * ( point[i].x - point[j].x ) + (point[i].y - point[j].y ) * (point[i].y - point[j].y ) ) ;
}//两点距离计算函数 

double finds( int left , int right )
{
	int mid = (left+right)>>1 ;
	double ans = 2<<20 ;
	if( left == right ) return ans ;
	if( left+1 == right ) 
		{
			return Distance( left , right ) ;
		}
	double left_ans = finds(left , mid) ;
	double right_ans = finds(mid+1 , right) ;
	ans = min( left_ans , right_ans ) ; 
/*————————————————计算左右区间——————————————*/	
	double mid_ans ;
	int finds_count = 0 ;
	for(int i = left ; i <= right ; i++ )
	{
		if( fabs(point[i].y - point[mid].y ) <= ans )
		{
			flag[finds_count] = i ;
			finds_count ++ ;
		} 
	}
	sort( flag , flag+finds_count , rule_y ) ;
	for( int i = 0 ; i < finds_count ; i ++ )
	{
		for( int j = i+ 1 ; j < finds_count && point[flag[j]].y - point[flag[i]].y < ans ; j++ )
		{
			mid_ans = Distance( flag[i] , flag[j] ) ;
			ans = min( ans , mid_ans);
		}
	}
return ans ;
}


int main()
{

	int count ;
	cin >> count ;
	for ( int i = 0 ; i < count ; i++ )
	{
		cin >> point[i].x >> point[i].y ;
	}
	sort(point , point+count , rule_x) ;
/*	for ( int j = 0 ; j < count ; j++ )
	{
		cout << point[j].x << ' ' << point[j].y << endl ;
	} *///测试用代码 
	cout << finds( 0  , count-1 ) ;
} 
