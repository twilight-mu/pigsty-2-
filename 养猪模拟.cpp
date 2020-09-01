using namespace std;
#include<bits/stdc++.h>
#define random(a,b) (rand()%(b-a+1))+a
struct pig
{
	int species; //����Ϊ1 С����Ϊ2 ��׻���Ϊ3 
	int id; 	//��� 
	int gday; 	//�ɳ����� 
	int gmonth; //�ɳ��·� (ÿ�¶���30�����,һ��360��) 
	//int isInfected; //����ȾΪ1 û����ȾΪ2 
	double weight; //���� 
	pig *next;
};
class pigsty
{
	private:
		pig *head;
		int isblack;
		int sum;
	public:
		pigsty();				//��ʼ�� 
		int getspecies(int i);	//��ȡ������Ϣ 
		int getgday(int i);		//��ȡ�ɳ�������Ϣ 
		double getweight(int i);//��ȡ���� 
		//double getprice();		//��ȡ��Ǯ
		//void print();			//��ӡ��Ȧ��Ϣ 
		//void clear();			//�����Ȧ 
		void addpig(pig*p);		//���� 
		void setisblack(int i);	//���ú���Ȧ,1Ϊ����Ȧ��0Ϊ�Ǻ���Ȧ 
		int getsumspecies(int i);	//��ȡĳ��������� 
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
void start(pigsty ps[])//����ʼ����Ȧ��ʼ�� 
{
	int count=300;	//��ʼ�ȷ�300ֻ�� 
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
