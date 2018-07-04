#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/*初始化 四种方法*/ 
    vector<int> v;//1
    for (int i=0; i<10;i++)
	{
      v.push_back(i);
    }

    vector<int> v1(v);//2
    
    vector<int> v2(10, 1);//3
    
    vector<int> v3(10);//4

    cout<<"first:";
	int ix,ix1,ix2,ix3;
	//vector<int>::size_type ix,ix1,ix2,ix3;
    for ( ix = 0; ix != v.size(); ix ++)
	{
        cout<<v[ix];
    }
    cout<<endl;
    cout<<"second: ";
    for (ix1 = 0; ix1 != v1.size(); ix1 ++)
	{
        cout<<v1[ix1]; 
    }
    cout<<endl;
    cout<<"third: ";
    for (ix2 = 0; ix2 != v2.size(); ix2 ++)
	{
        cout<<v2[ix2];
    }
    cout<<endl;
    cout<<"forth: ";
    for (ix3 = 0; ix3 != v3.size(); ix3 ++){
            cout<<v3[ix3];
    }
    cout<<endl;
    /*clear()方法和pop_back()方法*/ 
	//v.clear();
	for ( ix = 0; ix != v.size(); ix ++)
	{
        cout<<v[ix];
    }
    cout<<endl;
	
	v1.pop_back();
	for (ix1 = 0; ix1 != v1.size(); ix1 ++)
	{
        cout<<v1[ix1]; 
    }
    cout<<endl;
    v1.pop_back();
	for (ix1 = 0; ix1 != v1.size(); ix1 ++)
	{
        cout<<v1[ix1]; 
    }
    cout<<endl; 
    /*迭代器相关*/
	/*for(vector<int>::iterator i=v.begin();i!=v.end();++i)
	{
		*i=2;
	 } */
	v.insert(v.begin(),4);
    for(vector<int>::iterator m =v.begin();m!=v.begin();m++)
    {
    	if(*m==2)
		{
	     	v.insert(m,5);	
		 } 
	}//??????为什么没有执行？？？？ 
	for ( ix = 0; ix != v.size(); ix++)
	{
        cout<<v[ix];
    }
    cout<<endl;
    
    return 0;
}
