#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long type;

type gcd(type a, type b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	type num, p1, p2, i;

	while(cin>>num && num!=0)
	{
		if(i == -2147483648)
		{
			cout<<"31\n";
			continue;
		}
		bool negative = false;

		if(num < 0)
		{
			num = num * -1;
			negative = true;
		}

		p1 = 0;
		while(num%2 == 0)
		{
			num /= 2;
			p1++;
		}

		type sq = sqrtl(num) + 1;

		for(i=3;i<sq && num!=1;i+=2)
		{
			p2 = 0;
			while(num%i == 0)
			{
				num /= i;
				p2++;
			}
			p1 = gcd(p1, p2);
		}

		if(negative )
			for(int s = 1;s < 32 && p1%2 == 0 ;s++) //while(!(p1&1) )	= even == (p1%2)==0  [-16, -64,..] 
				p1 /= 2;	//I do not know why while give tle

		if(num != 1 || p1==0)
			p1 = 1;
		cout<<p1<<"\n";
	}
	return 0;
}
