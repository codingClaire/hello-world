#include<iostream>
using namespace std;
class Clock 
{
public:
	Clock(int h , int m , int s) : m_h(h), m_m(m), m_s(s) {}
	void tick();
	void adjust(int h, int m, int s);
	void show();

private:
	int m_h, m_m, m_s;
};

int main() 
{
	
	int h, m, s;
	cin >> h >> m >> s;
	Clock ck(h,m,s);
	ck.tick();
	ck.show();
	ck.adjust(16, 45, 00);
	ck.show();
	return 0;
}
void Clock::tick()
{
	m_s++;
	if (m_s == 60)
	{
		m_s = 0;
		m_m++;
	}
	if (m_m == 60)
	{
		m_m = 0;
		m_h++;
	}
	if (m_h == 24&&m_m==59&&m_s==59)
	{
		m_s = 0;
		m_h = 0; 
		m_m = 0;
	}
}
void Clock::adjust(int h, int m, int s)
{
	m_s = s;
	m_m = m;
	m_h = h;

}
void Clock::show()
{
	cout << "The time is" << m_h << ":" << m_m << ":" << m_s << endl;
}
