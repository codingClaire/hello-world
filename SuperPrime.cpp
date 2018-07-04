#include<iostream>
using namespace std;

class Prime
{
	public:
		Prime(int num);
		bool isPrime();
		Prime sum();
		Prime multi();
		Prime squaresum();
		void Show();
	private:
		const int m_num;
};

Prime::Prime(int num):m_num(num){}

bool Prime::isPrime()
{
	if(m_num==0)
	  return false;
	for(int i=2;i<m_num/i;i++)
	{
		if (m_num%i==0)
		  return false;
		}	
		return true;
}

Prime Prime::sum()
{
	int a=(m_num/1000)+(m_num%1000/100)+(m_num%100/10)+(m_num%10);
	Prime p(a);
	return p;
}
Prime Prime::multi()
{
	int a=m_num%10;
	int m=m_num;
	int n;
	while(m!=0)
	{
		n=m%10;
		a=a*n;
		m=m/10;
	}
	Prime p(a);
	return p;
}

Prime Prime::squaresum()
{
	int a = (m_num/1000)*(m_num/1000)+(m_num%1000/100)*(m_num%1000/100)+(m_num%100/10)*(m_num%100/10)+(m_num%10)*(m_num%10);
	Prime p(a);
	return p;
}
void Prime::Show()
{
	cout<<m_num;
}


int main()
{
	Prime sp(113);
	for(int i=100;i<9999;i++)
	{
		Prime sp(i);
		Prime sm=sp.sum();
		Prime mt=sp.multi();
		Prime sq=sp.squaresum();
	 if(sp.isPrime()&&sm.isPrime()&&mt.isPrime()&&sq.isPrime())
	 {
	 	 sp.Show();
		 cout<<" is a superprime!"<<endl;
	 }
	   	
	}
	return 0;
}
