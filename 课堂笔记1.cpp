#include <string>

class Chapter2 {

public:

  Chapter2(){}

  Chapter2(std::string &title, int pages):pages(pages),title(title) {}

  void show() const {}
  void operator+(){
  } //���������  
  Book operator+(Chapter2 &obj){
  }
  Book add(Chapter2 &obj){
  } //�½ڼ�������Ϊ�µ��� 
  bool operator()(...){
  }//����������  function object��������STL 
private:

  const string title; //�½ڱ���̶����ַ���

  const int pages; //�½�ҳ���̶������ܸı�

  //�����½ڶ���û�����壬���Խ�ֹ

  Chapter2(const Chapter2 &obj) {}

}
int main()
{
	chapter2 a,b;
	Book book; 
	Book book=a+b;
	Book book=a.add(b);//�������� ����������������� 
    book.add(a);
    book.add(b);
 } 
