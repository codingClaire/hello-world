//��λת����������ֵ��ԭ��λ���µ�λ�������µ�λ�µ�ֵ��
//������λ��Kg, g, lb, gr,......
//ѹ����λ��Pa, MPa, psi,......
//���ȵ�λ��m, km, ft, in,......
//������λ��md, cp,......
//���кܶ൥λת������Щ��λ��������λ��ϳ�����
/*��λת����
  С���Ա���ܾ�����������*/ 

#include<iostream>
#include<string>
#include<map>
#include<cstdio>

class Unit {
public:
	Unit(double num, std::string unit) : data(num), unit(unit) {}
	virtual ~Unit() {}
	virtual double convert(std::string unit) = 0;
	virtual double _from() = 0;
	virtual double _to(double num, std::string unit) = 0;
	double getData() {
		return data;
	}
	std::string getUnit() {
		return unit;
	}
private:
	double data;
	std::string unit;
};

class Mass : virtual public Unit {
public:
	Mass(double num, std::string unit) : Unit(num, unit) {}
	virtual ~Mass() {}
	double convert(std::string toUnit);
	double _from();
	double _to(double num, std::string unit);
private:
	static std::map<std::string, int> massMap;
};

class Length : virtual public Unit {
public:
	Length(double num, std::string unit) : Unit(num, unit) {}
	~Length() {}
	double convert(std::string toUnit);
private:
	double _from();
	double _to(double num, std::string unit);
	static std::map<std::string, int> lenMap;
};

class Time :virtual public Unit {
public:
	Time(double num, std::string unit) :Unit(num, unit) {}
	~Time() {}
	double convert(std::string toUnit);
private:
	double _from();
	double _to(double num, std::string unit);
	static std::map<std::string, int> TimeMap;
};

class Velocity {
public:
	Velocity(double _data, std::string unit) :data(_data), len(1, unit.substr(0, unit.find('/'))), t(1, unit.substr(unit.find('/') + 1, unit.length() - 1)) {}
	~Velocity() {}
	double convert(std::string toUnit);
private:
	double data;
	Length len;
	Time t;
};


class Force
{
public:
	Force(double data,std::string unit):m_data(data),weight(1,unit.substr(0,unit.find('f'))){}
	
	~Force(){}
	double convert(std::string toUnit);
private:
	double m_data;
	Mass weight;
};


/*
class Stress : virtual public Unit{
public:
Stress(double num, std::string unit) : Unit(num, unit){}
~Stress(){}
private:
static std::map<std::string, int> stressMap;
};
*/

std::map<std::string, int>initial_length()
{
	std::map<std::string, int> tmp;
	tmp.insert(std::make_pair("m", 1));
	tmp.insert(std::make_pair("km", 2));
	tmp.insert(std::make_pair("mile", 3));
	tmp.insert(std::make_pair("foot", 4));
	tmp.insert(std::make_pair("inch", 5));
	tmp.insert(std::make_pair("mm", 6));
	tmp.insert(std::make_pair("cm", 7));
	tmp.insert(std::make_pair("chi", 8));//��
	tmp.insert(std::make_pair("cun", 9));//��
	tmp.insert(std::make_pair("zhang", 10));//��
	return tmp;
}

std::map<std::string, int> initial_mass() {
	std::map<std::string, int> temp;
	temp.insert(std::make_pair("kg", 1));
	temp.insert(std::make_pair("g", 2));
	temp.insert(std::make_pair("mg", 3));
	temp.insert(std::make_pair("gr", 4));
	temp.insert(std::make_pair("lb", 5));
	temp.insert(std::make_pair("ct", 6));
	temp.insert(std::make_pair("t", 7));
	temp.insert(std::make_pair("oz", 8));
	temp.insert(std::make_pair("q", 9));
	temp.insert(std::make_pair("point", 10));
	return temp;
}

std::map<std::string, int>initial_time()
{
	std::map<std::string, int>tmp;
	tmp.insert(std::make_pair("s", 1));
	tmp.insert(std::make_pair("min", 2));
	tmp.insert(std::make_pair("h", 3));
	tmp.insert(std::make_pair("day", 4));
	tmp.insert(std::make_pair("ms", 5));
	return tmp;
}

std::map<std::string, int> Mass::massMap(initial_mass());
std::map<std::string, int> Length::lenMap(initial_length());
std::map<std::string, int>Time::TimeMap(initial_time());

int main() {
	int typeNum;
	double data;
	char yOrn;
	std::string unit, toUnit;
	while (true) {
		std::cout << "*************************" << std::endl;
		std::cout << "��ѡ��Ҫת���ĵ�λ��" << std::endl;
		std::cout << "1�����ȣ�֧��ת����λ��m��km��mile��foot��inch��mm��cm��chi��cun��zhang)" << std::endl;
		std::cout<< "2��������֧��ת����λ��kg��g��mg��gr��lb��ct��t��oz��q��point)" << std::endl;
		std::cout<< "3��ʱ�䣨֧��ת����λ��s��min��h��day��ms)" << std::endl;
		std::cout <<"4���ٶȣ�֧��ת����λ������/ʱ����������)" << std::endl;
		std::cout<<"5������֧��ת����λ��kgf��gf��lbf��tf)"<<std::endl;
		std::cout<< "������ţ�";
		std::cin >> typeNum;
		std::cout << "�����ת�����ݣ���С����λ����" << std::endl;
		std::cin >> data >> unit;
		std::cout << "Ҫת��Ϊ����λ����" << std::endl;
		std::cin >> toUnit;
		switch (typeNum) {
		case 1:
		{
			Length len(data, unit);
			std::printf("����ǣ�%lf", len.convert(toUnit));
			std::cout << toUnit << std::endl;
			break;
		}
		case 2:
		{
			Mass weight(data, unit);
			std::printf("����ǣ�%lf", weight.convert(toUnit));
			std::cout << toUnit << std::endl;
			break;
		}
		case 3:
		{
			Time t(data, unit);
			std::printf("����ǣ�%lf", t.convert(toUnit));
			std::cout << toUnit << std::endl;
			break;
		}
		case 4:
		{
			Velocity v(data, unit);
			std::printf("����ǣ�%lf", v.convert(toUnit));
			std::cout << toUnit << std::endl;
			break;
		}
		case 5:
			{
				Force f(data,unit);
				std::printf("����ǣ�%lf",f.convert(toUnit));
				std::cout<<toUnit<<std::endl;
				break;
			}
		}
		std::cout << "�Ƿ����(y/n):" << std::endl;
		std::cin >> yOrn;
		if (yOrn == 'n') {
			break;
		}
	}
	return 0;
}

double Mass::_from() {
	switch (massMap.at(Unit::getUnit())) {
	case 1:return Unit::getData();
	case 2:return Unit::getData() / 1000;
	case 3:return Unit::getData() / 1000000;
	case 4:return Unit::getData()*0.45359237 / 7000;
	case 5:return Unit::getData()*0.45359237;
	case 6:return Unit::getData()*0.0002;
	case 7:return Unit::getData() * 1000;
	case 8:return Unit::getData()*0.02835;
	case 9:return Unit::getData() * 100;
	case 10:return Unit::getData()*2.0 / 1000000;
	default:return 0;
	}
}

double Mass::_to(double num, std::string unit) {
	switch (massMap.at(unit)) {
	case 1:return num;
	case 2:return num * 1000;
	case 3:return num * 1000000;
	case 4:return num * 7000 / 0.45359237;
	case 5:return num / 0.45359237;
	case 6:return num / 0.0002;
	case 7:return num / 1000;
	case 8:return num / 0.02835;
	case 9:return num / 100;
	case 10:return num / 2.0 * 1000000;
	default:return 0;
	}
}

double Mass::convert(std::string toUnit) {
	return this->_to(this->_from(), toUnit);
}

double Length::_from()
{
	switch (lenMap.at(Unit::getUnit()))
	{
	case 1:return Unit::getData();
	case 2:return 1000 * Unit::getData();
	case 3:return 1609.3448*Unit::getData();
	case 4:return 0.3048*Unit::getData();
	case 5:return 0.0254*Unit::getData();
	case 6:return 0.001*Unit::getData();
	case 7:return 0.01*Unit::getData();
	case 8:return Unit::getData() / 3;
	case 9:return Unit::getData() / 30;
	case 10:return Unit::getData() * 10 / 3;
	default:return 0;
	}
}

double Length::_to(double num, std::string unit)
{
	switch (lenMap.at(unit))
	{
	case 1: return num;
	case 2:return num / 1000;
	case 3:return num / 1609.3448;
	case 4:return num / 0.3048;
	case 5:return num / 0.0254;
	case 6:return num / 0.001;
	case 7:return num / 0.01;
	case 8:return Unit::getData() * 3;
	case 9:return Unit::getData() * 30;
	case 10:return Unit::getData() *0.3;
	default:return 0;
	}
}

double Length::convert(std::string toUnit)
{
	return _to(this->_from(), toUnit);
}

double Time::_from()
{
	switch (TimeMap.at(Unit::getUnit()))
	{
	case 1:return Unit::getData();
	case 2:return Unit::getData() * 60;
	case 3:return Unit::getData() * 3600;
	case 4:return Unit::getData() * 24 * 3600;
	case 5:return  Unit::getData() / 1000;
	default:return 0;
	}
}

double Time::_to(double num, std::string unit)
{
	switch (TimeMap.at(unit))
	{
	case 1:return num;
	case 2:return num / 60;
	case 3:return num / 3600;
	case 4:return num / (24 * 3600);
	case 5:return num * 1000;
	default:return 0;
	}
}

double Time::convert(std::string toUnit)
{
	return _to(this->_from(), toUnit);
}

double Velocity::convert(std::string toUnit) {
	return data * len.convert(toUnit.substr(0, toUnit.find('/'))) / t.convert(toUnit.substr(toUnit.find('/') + 1, toUnit.length() - 1));
}
double Force::convert(std::string toUnit) 
{
	return m_data*weight.convert(toUnit. substr(0, toUnit.find('f')));
}

