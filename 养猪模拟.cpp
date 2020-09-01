using namespace std;
#include<bits/stdc++.h>
#define random(a,b) (rand()%(b-a+1))+a
struct pig
{
	int species; //黑猪为1 小花猪为2 大白花猪为3 
	int id; 	//编号 
	int gday; 	//成长天数 
	int gmonth; //成长月份 (每月都按30天计算,一年360天) 
	//int isInfected; //被感染为1 没被感染为2 
	double weight; //体重 
	pig *next;
};
class pigsty
{
	private:
		pig *head;
		int isblack;
		int sum;
	public:
		pigsty();				//初始化 
		int getspecies(int i);	//获取种类信息 
		int getgday(int i);		//获取成长天数信息 
		double getweight(int i);//获取重量 
		//double getprice();		//获取价钱
		//void print();			//打印猪圈信息 
		//void clear();			//清空猪圈 
		void addpig(pig*p);		//加猪 
		void setisblack(int i);	//设置黑猪圈,1为黑猪圈，0为非黑猪圈 
		int getsumspecies(int i);	//获取某种猪的数量 
		int getsum()
		{
			return sum;
		}
		int getisblack()
		{
			return isblack;
		}                
		pig* gethead()
		{
			return head;
		}
};
pigsty::pigsty()
{
	int sum=0;
	int isblack=0;
	head=NULL;
}
int pigsty::getspecies(int i) 
{
	pig *p=head;
	for(int k=0;k<i&&p!=NULL;k++)
	{
		p=p->next;
	}
	return p->species;
}
int pigsty::getgday(int i)
{
	int sumday;
	pig *p=head;
	for(int k=0;k<i&&p!=NULL;k++)
	{
		p=p->next;
	}
	sumday=p->gmonth*30+p->gday;
	return sumday;
}
double pigsty::getweight(int i)
{
	pig *p=head;
	for(int k=0;k<i&&p!=NULL;k++)
	{
		p=p->next;
	}
	return p->weight;
}
void pigsty::addpig(pig *p)
{
	sum++;
	p->next=NULL;
	if(head==NULL)
	{
		head=p;
	}
	else 
	{
		pig*p1=head;
		while(p1->next)
		{
			p1=p1->next;
		}
	p1->next=p;
	}
}
void pigsty::setisblack(int i)
{
	isblack=i;	
}
int pigsty::getsumspecies(int i)
{
	int count;
	pig *p=head;
	for(int k=0;k<sum&&p!=NULL;k++)
	{
		if(p->species==i)
		count++;
		p=p->next;
	}
	return count;
}
void start(pigsty ps[])//程序开始，猪圈初始化 
{
	int count=300;	//开始先放300只猪 
	pig *p;
	while(count--)
	{
		p=new pig;
		p->species=random(1,3);
		p->weight=random(20,50);
		p->gmonth=0;
		p->gday=0;
		for(int i=0;i<100;i++)
		{
			if(p->species==1&&(ps[i].getisblack()==1||ps[i].gethead()==NULL)&&ps[i].getsum()<10)
			{
				p->id=ps[i].getsum();
				ps[i].addpig(p);
				ps[i].setisblack(1);
				break;
			}
			if(p->species!=1&&ps[i].getisblack()==0&&ps[i].getsum()<5)
			{
				p->id=ps[i].getsum();
				ps[i].addpig(p);
				break;
			}
		}
	}
}
void oneday(pigsty ps[])
{
	for(int i=0;i<100;i++)
	{
		pig *p;
		p=ps[i].gethead();
		while(p)
		{
			int w1=random(0,12);
			double w2=double(w1)/10.0;
			p->weight+=w2;
			p->gday++;
			p=p->next;
		}	
	} 
}
int main()
{
	pigsty ps[100];
	start(ps);
	while(true)
	{
		int n;
		cin>>n;
		if(n==0)
		break;
		char s;
		cin>>s;
		if(s=='d')
		{
			oneday(ps);
		}
		if(s=='m')
		{
			for(int i=0;i<30;i++)
			oneday(ps);
		}
	}
	return 0;
}
