#include <iostream>
#include <string>
using namespace std;
string ones(int b)
{
	switch(b)
	{
		case 1:return "One";
		case 2:return "Two";
		case 3:return "Three";
		case 4:return "Four";
		case 5:return "Five";
		case 6:return "Six";
		case 7:return "Seven";
		case 8:return "Eight";
		case 9:return "Nine";
		default : return "";
	}
}
string tens(int b)
{
	int c;
	b>19?c=1:c=0;
	if(c==1)
	{
		switch(b/10)
		{
		case 2:return "Twenty "+ones(b%10);
		case 3:return "Thirty "+ones(b%10);
		case 4:return "Forty "+ones(b%10);
		case 5:return "Fifty "+ones(b%10);
		case 6:return "Sixty" +ones(b%10);
		case 7:return "Seventy "+ones(b%10);
		case 8:return "Eighty "+ones(b%10);
		case 9:return "Ninety "+ones(b%10);
	    }
	}
	switch(b)
	{
		case 10:return "Ten";
		case 11:return "Eleven";
		case 12:return "Twelve";
		case 13:return "Thirteen";
		case 14:return "Fourteen";
		case 15:return "Fifteen";
		case 16:return "Sixteen";
		case 17:return "Seventeen";
		case 18:return "Eighteen";
		case 19:return "Nineteen";
		case 20:return "Twenty";
		default:return ones(b);
	}
}
string hundreds(int b)
{
	if(b<100)
	{
		return tens(b);
	}
	return ones(b/100)+" Hundred "+tens(b%100);
}
string thousands(int b)
{
	if(b<1000)
	{
		return hundreds(b);
	}
	if(b>=1000 && b<=9999)
	{
		return ones(b/1000)+" Thousand "+hundreds(b%1000);
	}
	return tens(b/1000)+" Thousand "+hundreds(b%1000);
}
string lakhs(int b)
{
	if(b<100000)
	{
		return thousands(b);
	}
	if(b>=100000 && b<=999999)
	{
		return ones(b/100000)+" lakh "+thousands(b%10000);
	}
	return tens(b/100000)+" lakhs "+thousands(b%100000);
}
string crores(int b)
{
	if(b<10000000)
	{
		return lakhs(b);
	}
	int v=b/10000000;
	if(v>100)
	{
		cout<<"Working Limit Exceeded by Given Code!!!";
	}
	if(v<=9)
	{
		return ones(b/10000000)+" crore "+lakhs(b%10000000);
	}
	else if(v<=99)
	{
		return tens(b/10000000)+" crores "+lakhs(b%10000000);
	}
	else if(v<=100)
	{
		return hundreds(b/10000000)+" crores "+lakhs(b%10000000);
	}
}
string convert(int b)
{
	if(b<=9) return ones(b);
	if(b<=99) return tens(b);
	if(b<=999) return hundreds(b);
	if(b<=99999) return thousands(b);
	if(b<=999999) return lakhs(b);
	if(b<=1000000000) return crores(b);
}
int main()
{
	long int a;
	cout<<"Welcome To The Capstone Project";
	cout<<"\nThe Code Can Convert Number to word upto 100 CR";
	cout<<"\nEnter The Number To Proceed=";
	cin>>a;
	if(a>1000000000){cout<<"working limit exceeded!!"; return 0;}
	cout<<convert(a)+".";
}

