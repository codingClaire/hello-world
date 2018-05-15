#include <string>
#include<vector>
#include<iostream>
using namespace std;

class Chapter2 {

public:

  Chapter2():title("N/A"),page(0){std::cout<<"Chapter2"<<std::endl};

  Chapter2(std::string &title, int pages):pages(pages),title(title) {}
 Chapter2(char title[], int pages):pages(pages),title(title) {}
  void show() const {
    std::cout<<title<<"("<<pages<<")"<<std::endl;
  }
  

private:

  const string title; //章节标题固定的字符串

  const int pages; //章节页数固定，不能改变

  //复制章节对象没有意义，所以禁止

  Chapter2(const Chapter2 &obj) {}
 
  /*chapter（）{
  }//私有的无参构造函数 
  std::vector<Chapter> chapters;
  Chapter chapters[10];
  
  这两个的区别？ 第一个chapters是一个vector对象 而第二个是十个chapter对象 
  Chapter *chapters[20];有限个 
  但vector自动会分配*/ 
};

class Book
{
  public:
     Book()
	 {
	 	int i;
	 	for(i=0;i<10;i++)
	 	 chaps[i]=nullptr;//赋成空指针 chaps[i]=0
	  } 
	 Book add(Chapter2 *obj){
	 	int i=0;
	 	while(chaps[i]!=nullptr)
	 	  i++;
	 	chaps[i]=obj;
	 	return *this;
	 }//传统的编程方法 
	 Book add(Chapter2 &obj){
	    chapsv.push_back(obj);
     }
	 void show(){
	 	for(i=0;i<10;i++)
	 	if(chaps[i]!=nullptr)
	 	  chaps[i]->show();
	 	  /*for(std::vector<Chapter2&>::iterator
		        it=chapsv.begin();
				it!=chapsv.end();it++)
				(*it).show(); */
		/*for(Chapter2 chap:chapsv)
				(*it).show();*/
	 }
	 Book add(Chapter2 obj);
	 
  private:
    Chapter2 *chaps[10];//数组   指针chapter类型的指针数组
	//Chapter2 chaps[10];//认为有十个对象 构造函数要调用 
	//这里声明的chapter2数组并不是实际的对象 
 std::vector<Chapter2&> chapsv;
 };//Book和Chapter2两个类之间的差别？ 

int main()
{
	Book book;//new book 调用构造函数 如果自己写了有参的构造函数 自动生成的无参构造函数就不存在了
	//没有参数不要在后面加括号 
	std::string tilt("hello");
	Chapter2 *obj=new Chapter2(tilt,1);//创建一个新对象章节名称hello 页数为1 
	/*Chapter2 obj("hello",1);
	book.add(obj);*/
	book.add(obj);
    Book book1=book.add(obj);//book和book1是同一个对象 
	book.show(); 
	delete obj; 
 } 
//设计模式 工厂方法 
