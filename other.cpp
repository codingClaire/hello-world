
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include<iostream>
#include<cmath>
using namespace std;


int findpow(int n)
{

}

int division(int n)
{
	int power;
	for (power = 0; power <= 15; power++)
	{
		if (n > pow(2, power) && n < pow(2, power + 1))
		{
			n = n - pow(2, power);
		}
		while (n != 1)
		{

		}
	}
	int next = pow(2, power);
	cout << "2(" << division（pow（2，power）） << ")" << endl;
	
}




int main()
{
	int n;
	cin >> n;


}

/*火星*/
#include<iostream>
#include<string>
#include<string.h>
#include<cstdio>
using namespace std;

int main()
{
	int primer[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
	string str1, str2;
	int h1[30], h2[30];
	while (cin >> str1 >> str2)
	{
		memset(h1, 0, sizeof h1);
		memset(h2, 0, sizeof h2);
		int len1 = str1.length(),len2 = str2.length();
		int num1 = 0, num2 = 0;
		for (int i = 0; i <=len1; i++)
		{
			if (str1[i] != ','&&str1[i + 1] == ',')
			{
				h1[num1] = str1[i] - '0';
				num1++;
			}
				
			else if (str1[i] != ','&&str1[i + 1] != ',')
			{
				h1[num1] = (str1[i] - '0') * 10 + str1[i + 1] - '0';			
				num1++;
			}
		}
		for (int i = 0; i <=len2; i--)
		{
			if (str2[i] != ','&&str2[i + 1] == ',')
			{
				h2[num2] = str2[i] - '0';
				num2++;
			}

			else if (str2[i] != ','&&str2[i + 1] != ',')
			{
				h2[num2] = (str2[i] - '0') * 10 + str2[i + 1] - '0';
				num2++;
			}
		}
		int max = num1;
		if (max < num2) max = num2;
		for (int j = 0; j < num1; j++)
		{
			int cmp = h1[j]; h1[j] = h1[num1 - j - 1];  h1[j]=cmp;
		}
		for (int j = 0; j < num2; j++)
		{
			int cmp = h2[j]; h2[j] = h2[num2 - j - 1];  h2[j] = cmp;
		}
		//交换元素
		int result[30];
		for (int i = 0; i < max; i++)
		{
			result[i] = h1[i] + h2[i];
			if (result[i] > primer[i])
			{
                result[i+1]++;
				result[i] = result[i] - primer[i];
			}
		}
		for (int i = max - 1; i > 0; i++)
		{
			cout << result[i] << ",";
		}
		cout << result[0] << endl;
	}
	return 0;
}





#include <iostream>

#include <algorithm>

#include <cstring>

#include <string>

#include <cmath>

#include <iomanip>

#include <stdio.h>


	string s1, s2;

	int a[100], b[100], s[100];

	int cnt = 0, flag, ch[25]= { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };

	while (cin >> s1 >> s2)

	{

		memset(a, 0, sizeof a);

		memset(b, 0, sizeof b);

		memset(s, 0, sizeof s);

		int k = 0, l1 = 0, l2 = 0, maxlen = 0, minlen = 0, cnt = 0, ans = 0, t = 0;

		l1 = s1.length();

		l2 = s2.length();

		for (int i = 0; i < l1; i++)

		{

			if (s1[i] != ',')

				a[cnt] = a[cnt] * 10 + (s1[i] - '0');

			else if (s1[i] == ',')

				cnt++;

		}

		for (int i = 0; i < l2; i++)

		{

			if (s2[i] != ',')

				b[ans] = b[ans] * 10 + (s2[i] - '0');

			else if (s2[i] == ',')

				ans++;

		}//字符串s1、s2装换为int型并存入数组a、b

		if (cnt == 0 && ans == 0 && a[0] == 0 && b[0] == 0)

			break;

		for (int i = 0, j = cnt; i < j; i++, j--)

		{

			int mid = a[i];

			a[i] = a[j];

			a[j] = mid;

		}

		for (int i = 0, j = ans; i < j; i++, j--)

		{

			int mid = b[i];

			b[i] = b[j];

			b[j] = mid;

		}//将数组a、b的类容倒置

		maxlen = max(cnt, ans);

		for (int i = 0; i <= maxlen; i++)

		{

			s[t] = k + a[i] + b[i];

			if (s[t] >= ch[t])

			{

				s[t] = s[t] - ch[t];

				k = 1;

				t++;

			}

			else if (s[t] < ch[t])

			{

				k = 0;

				t++;

			}

		}

		if (k != 0)

			s[t] = k;

		else

			t = t - 1;//判断最后一位是否有进位

		for (int i = t; i >= 0; i--)

		{

			if (i > 0)

				cout << s[i] << ",";

			else if (i == 0)

				cout << s[i] << endl;

		}

	}

	return 0;

}

//最大子矩阵和
#include<iostream>
using namespace std;

int maxarea(int *a,int n)
{
	int area = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		if (b > 0) b = b + a[i];
		else b = a[i];
		if (b > area) area = b;
	}
	return area;
}

int minarr(int n,int k)
{
	int start = 0; end = 0, sum = 0;
	int len = n;
	int ans = len + 1;
	int flag = 0;
	while (end < len)
	{
		if (sum < k)
		{
			
		}
	}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int mat[100][100];
	int tmp[100];
	int area = -1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
			sum = sum + mat[i][j];
		}
	}
	if (sum < K)
		cout << -1 << endl;
	else
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mat[j][i] += mat[j - 1][i];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				for (int k = 0; k < m; k++)
					tmp[k] = mat[j][k] - mat[i][k];//压缩矩阵，降低维度
			}
		}
	}
	if (maxiarea < k) cout << -1 << endl;
	return 0;
}



