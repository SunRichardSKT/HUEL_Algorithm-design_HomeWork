#include<bits/stdc++.h>
using namespace std ;

int quick_pow(int down , int up )
{
	 if (up == 0)
        return 1;
    else if (up % 2 == 1)
        return quick_pow( down , up - 1) * down;
    else
    {
        int temp = quick_pow( down , up / 2);
        return temp * temp;
    }
}

int main()
{
	int num , pow ;
	cin >> num >> pow ;

	cout <<	quick_pow( num , pow ) ;
 } 
