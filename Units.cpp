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
    double _from(double num, std::string unit);
	double _to(double num, std::string unit);
	~Length() {}
private:
	static std::map<std:: string, int> lenMap;

};
std::map<std::string, int>initial_map()
{
	std::map<std::string, int> tmp;
	tmp.insert(std::make_pair("m", 1));
	tmp.insert(std::make_pair("km",2));
	tmp.insert(std::make_pair("mile",3));
	tmp.insert(std::make_pair("foot",4));
	tmp.insert(std::make_pair("inch",5));
	tmp.insert(std::make_pair("mm",6));
	tmp.insert(std::make_pair("cm",7)); 
	tmp.insert(std::make_pair("chi",8));//尺
	tmp.insert(std::make_pair("cun",9));//寸
	tmp.insert(std::make_pair("zhang",10));//丈
	return tmp;
}

std::map<std::string, int> Length::lenMap(initial_map());


double Length::_from(double num, std::string unit) {
	switch (lenMap.at(unit)) {
	case 1:break;
	case 2:return 1000 * num; break;
	case 3:return 1609.3448*num; break;
	case 4:return 0.3048*num; break;
	case 5:return 0.2254*num; break;
	case 6:return 0.001*num; break;
	case 7:return 0.01*num; break;
	}
}
double Length::_to(double num, std::string unit) {
	switch (lenMap.at(unit)) {
	case 1:break;
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
	double num;
	std::cin >> num >> unit1 >> unit2;
	std::cout <<Length::_from(num,unit1)<< std::endl;
	return 0;
} 

