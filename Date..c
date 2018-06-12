#include<stdio.h> 

struct Date 
{
  int year;
  int month;
  int day;
};//����ṹ�� 

int isleapyear(struct Date day)
{
	int judge;
	if((day.year%4==0&&day.year%100!=0)||day.year%400==0)
	judge=1;
	else judge=0;
	return judge;
}//�ж��ǲ������� 

int monthday[13]={31,31,28,31,30,31,30,31,31,30,31,30,31};
void next_day(struct Date day)
{
	if (isleapyear(day)==1)
	{
		monthday[2]++;
	}//������ͼ�һ�� 
	if(day.day==31&&day.month==12)
	{
		day.year++;
		day.day=1;
		day.month=1;
	}//�������� 
	int i;
	for (i=1;i<=11;i++)
	{
	  if(day.month==i)
	  {
	    if (day.day==monthday[i])
	    {
	      day.month++;
		  day.day=1;
		}//���µ����
		else  
	    {
		 day.day++;
		 break;
	    } 
	  }
    }
    return day;
}
void previous_day(struct Date day)
{ 
  if (isleapyear(day)==1)
	{
		monthday[2]++;
	}//������ͼ�һ�� 
  if(day.day==1&&day.month==1)
  {
  	day.year--;
  	day.day=31;
  	day.month=12;
  }
  int i;
  for (i=1;i<=11;i++)
	{
	  if(day.month==monthday[i])
	  {
	    if (day.day==1)
	    {
	      day.month--;
		  day.day=monthday[i-1];
		}//���µ����
		else  
	    {
		 day.day--;
		 break;
	    } 
	  }
    }
	return day;	
}


int equal(struct Date one, struct Date day)
{
	if(one.day==day.day&&one.month==day.month&&one.year==day.year)
	  return 1;
   return 0;
}
    

void show(struct Date day) 
{
  printf("%d nian %d yue %d ri",day.year,day.month,day.day);
  printf("\n");
}

int main() 
{
  struct Date today = {2018,3,20};
  struct Date day = {2018,3,20};
  
  show(day);
  int i;
  for(i=0;i<30;i++)
  {
  	day=next_day(day);
    show(day); //��ӡ��30������� 
  }
    
  
  for(i=0;i<30;i++)
    day=previous_day(day);
  show(day);//��ӡǰ30������� 
  
  if(equal(today, day))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}








