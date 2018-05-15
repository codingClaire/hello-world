#include <string>

class Chapter2 {

public:

  Chapter2(){}

  Chapter2(std::string &title, int pages):pages(pages),title(title) {}

  void show() const {}
  void operator+(){
  } //运算符重载  
  Book operator+(Chapter2 &obj){
  }
  Book add(Chapter2 &obj){
  } //章节加起来成为新的类 
  bool operator()(...){
  }//重载了括号  function object函数对象STL 
private:

  const string title; //章节标题固定的字符串

  const int pages; //章节页数固定，不能改变

  //复制章节对象没有意义，所以禁止

  Chapter2(const Chapter2 &obj) {}

}
int main()
{
	chapter2 a,b;
	Book book; 
	Book book=a+b;
	Book book=a.add(b);//算数运算 两个对象的算术运算 
    book.add(a);
    book.add(b);
 } 
