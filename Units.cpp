//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
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
lenMap["foot"] = 4;//英尺
lenMap["inch"] = 5;//英寸
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
