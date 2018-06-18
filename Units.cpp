//��λת����������ֵ��ԭ��λ���µ�λ�������µ�λ�µ�ֵ��
//������λ��Kg, g, lb, gr,......
//ѹ����λ��Pa, MPa, psi,......
//���ȵ�λ��m, km, ft, in,......
//������λ��md, cp,......
//���кܶ൥λת������Щ��λ��������λ��ϳ�����
#include<iostream>
#include<string>
#include<map>

class Unit {
public:
	Unit(double num, std::string unit) : data(num), unit(unit) {}
	~Unit() {}
	virtual double convert(Unit &obj);
	virtual double _from(double num, std::string unit, std::map<std::string, int>& unitMap);
	virtual double _to(double num, std::string unit, std::map<std::string, int>& unitMap);
private:
	double data;
	std::string unit;
};


class Length : virtual public Unit {
public:
	Length(double num, std::string unit) : Unit(num, unit) {}
	~Length() {}
private:
	static std::map<std:: string, int> lenMap;

};
lenMap["m"] = 1;
lenMap["km"] = 2;
lenMap["mile"] = 3;
lenMap["foot"] = 4;//Ӣ��
lenMap["inch"] = 5;//Ӣ��
lenMap["mm"] = 6;
lenMap["cm"] = 7;



/*
class Mass: virtual public Unit{
public:
Mass(double num, std::string unit) : Unit(num, unit){}
~Mass(){}
private:
static std::vector<std::vector<double(*)(double)> > Formula;
};

class Stress : virtual public Unit{
public:
Stress(double num, std::string unit) : Unit(num, unit){}
~Stress(){}
private:
static std::vector<std::vector<double(*)(double)> > Formula;
};

class Force : virtual public Unit{
public:
Force(double num, std::string unit) : Unit(num, unit){}
~Force(){}
private:
static std::vector<std::vector<double(*)(double)> > Formula;
};
*/

double Unit::_from(double num, std::string unit, std::map<std::string, int>& unitMap) {
	switch (unitMap.at(unit)) {
	case 1:break;
	case 2:return 1000 * num; break;
	case 3:return 1609.3448*num; break;
	case 4:return 0.3048*num; break;
	case 5:return 0.2254*num; break;
	case 6:return 0.001*num; break;
	case 7:return 0.01*num; break;
	}
}
double Unit::_to(double num, std::string unit, std::map<std::string, int>& unitMap) {
	switch (unitMap.at(unit)) {
	case 1: break;
	case 2:return num/1000; break;
	case 3:return num/1609.3448; break;
	case 4:return num/0.3048; break;
	case 5:return num/0.2254; break;
	case 6:return num/0.001; break;
	case 7:return num/0.01; break;
	}
}

int main()
{
	std::string unit1, unit2;
	int num;
	std::cin >> num >> unit1 >> unit2;
	std::cout << convert() << std::endl;
	return 0;
