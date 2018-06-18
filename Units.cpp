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
	virtual double convert(std::string unit) = 0;
	virtual double _from()=0;
	virtual double _to(double num, std::string unit)=0;
	double getData(){
		return data;
	}
	std::string getUnit(){
		return unit;
	}
private:
	double data;
	std::string unit;
};


//长度转换
class Length : virtual public Unit 
{
  public:
	   Length(double num, std::string unit) : Unit(num, unit) {}
	   ~Length() {}
	   double convert(std::string toUnit);
  private:
    double _from();
	double _to(double num, std::string unit);
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
	}
}
double Length::_to(double num, std::string unit) 
{
	switch (lenMap.at(unit)) 
	{
	case 1: return num;
	case 2:return num/1000; 
	case 3:return num/1609.3448;
	case 4:return num/0.3048;
	case 5:return num/0.0254;
	case 6:return num/0.001;
	case 7:return num/0.01;
	}
}

double Length::convert(std::string toUnit) 
{
	return _to(this->_from(), toUnit);
}



int main()
{
	std::string unit1, unit2;
    double num;
	std::cin >> num >> unit1 >> unit2;
	Length a(num, unit1);
	std::cout << a.convert(unit2) << std::endl;
	return 0;
} 
