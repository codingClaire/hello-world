#include <iostream>
#include<string>
using namespace std;

struct TA
{
	int interger;
	string str;
	int intset;
};
/*template <class T>
void set(int c, int r, T a);*/
class Table
{
public:
	Table()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j <10; j++)
			{
				table[i][j].str= "none";
				//table[i][j].interger = 0;
			}
		}
	}//无参时默认表格大小10*10
	Table(int r,int c)
	{
		m_row = r;
		m_column = c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				table[i][j].str = "none";
				//table[i][j].interger = 0;
			}
		}
		
	}//构造函数
	void set(int c,int r,int a)
	{
	    table[c-1][r-1].interger= a;
		table[c-1][r-1].intset = 1;
	}
	void set(int c, int r, string a)
	{
		table[c - 1][r - 1].str= a;
		table[c-1][r-1].intset = 0;
	}
	void show()
	{
		for(int i=0;i<10;i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (table[i][j].intset == 1)
					cout << table[i][j].interger << " ";
				else
					cout << table[i][j].str << " ";
			}
			cout << endl;
		}
	}
	void addRow()
	{
		m_row++;
		for (int i = 0; i < 10; i++)
			table[10][i].str= "none";
	}//无参默认在表的末尾加上一行
    void addColumn()
	{
		m_column++;
		for (int i = 0; i < 10; i++)
			table[i][10].str = "none";
	}//默认在表的末尾加上一列
	void delRow(int i) //删去第i行
	{
		for (int j = i-1; j < m_row; j++)
		{
			for (int k = 0; k < m_column; k++)
				table[j][k] = table[j + 1][k];
		}
	}
	void delColumn(int i)//删去第i列
	{
		for (int j = i-1; j < m_column; j++)
		{
			for (int k = 0; k < m_row; k++)
				table[k][j] = table[k][j + 1];
		}
	}
	~Table(){}
private:
	TA table[20][20];
	int m_column, m_row;
};

int main()
{
		Table tb;
		tb.show();
		tb.addRow();
		tb.show();
		tb.addColumn();
		tb.show();
		Table tb1(5, 5);
		tb1.show();
		tb1.set(1, 1, 30);
		tb1.set(2, 2, "hello");
		tb1.show();
		tb1.delRow(1);
		tb1.show();
		tb1.delColumn(1);
		tb1.show();
	return 0;
}

