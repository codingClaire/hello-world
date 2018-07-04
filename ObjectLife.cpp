#include<iostream>
using namespace std;
class A1
{
	public:
	A1()
	{
		cout<<"constructing A1"<<endl;
	}
	~A1()
	{
		cout<<"destructing A1"<<endl;
	}
};
class A2
{
		public:
	A2()
	{
		cout<<"constructing A2"<<endl;
	}
	~A2()
	{
		cout<<"destructing A2"<<endl;
	}
};
class B:public A1
{
	public:
	B()
	{
		cout<<"constructing B"<<endl;
	}
	~B()
	{
		cout<<"destructing B"<<endl;
	}
	
};
class C:public B,public A2
{
		public:
	C()
	{
		cout<<"constructing C"<<endl;
	}
	~C()
	{
		cout<<"destructing C"<<endl;
	}
};

int main()
{
	C obj;
	return 0;
}
