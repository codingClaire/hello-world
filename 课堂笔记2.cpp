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

  const string title; //�½ڱ���̶����ַ���

  const int pages; //�½�ҳ���̶������ܸı�

  //�����½ڶ���û�����壬���Խ�ֹ

  Chapter2(const Chapter2 &obj) {}
 
  /*chapter����{
  }//˽�е��޲ι��캯�� 
  std::vector<Chapter> chapters;
  Chapter chapters[10];
  
  ������������ ��һ��chapters��һ��vector���� ���ڶ�����ʮ��chapter���� 
  Chapter *chapters[20];���޸� 
  ��vector�Զ������*/ 
};

class Book
{
  public:
     Book()
	 {
	 	int i;
	 	for(i=0;i<10;i++)
	 	 chaps[i]=nullptr;//���ɿ�ָ�� chaps[i]=0
	  } 
	 Book add(Chapter2 *obj){
	 	int i=0;
	 	while(chaps[i]!=nullptr)
	 	  i++;
	 	chaps[i]=obj;
	 	return *this;
	 }//��ͳ�ı�̷��� 
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
    Chapter2 *chaps[10];//����   ָ��chapter���͵�ָ������
	//Chapter2 chaps[10];//��Ϊ��ʮ������ ���캯��Ҫ���� 
	//����������chapter2���鲢����ʵ�ʵĶ��� 
 std::vector<Chapter2&> chapsv;
 };//Book��Chapter2������֮��Ĳ�� 

int main()
{
	Book book;//new book ���ù��캯�� ����Լ�д���вεĹ��캯�� �Զ����ɵ��޲ι��캯���Ͳ�������
	//û�в�����Ҫ�ں�������� 
	std::string tilt("hello");
	Chapter2 *obj=new Chapter2(tilt,1);//����һ���¶����½�����hello ҳ��Ϊ1 
	/*Chapter2 obj("hello",1);
	book.add(obj);*/
	book.add(obj);
    Book book1=book.add(obj);//book��book1��ͬһ������ 
	book.show(); 
	delete obj; 
 } 
//���ģʽ �������� 
