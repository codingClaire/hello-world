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
	tmp.insert(std::make_pair("chi",8));//��
	tmp.insert(std::make_pair("cun",9));//��
	tmp.insert(std::make_pair("zhang",10));//��
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

