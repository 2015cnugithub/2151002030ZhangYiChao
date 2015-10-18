#include"iostream.h"
#include"1.h"
#include"string.h"
ostream& operator<<(ostream &out, Worker& worker)
{
	out<<"姓名 "<<worker.name<<"  ";
	out<<"年龄 "<<worker.age<<"   ";
	out<<"性别 "<<worker.sex<<"   ";
	out<<"工资/小时  "<<worker.pay_per_hour<<"   "<<endl;
		 
	return out;
}
HourlyWorker::HourlyWorker(char n[10],int a,char s, int pay)
{
	strcpy(name,n);
	age=a;
	sex=s;
	pay_per_hour=pay;
}
 double HourlyWorker::Compute_pay(double hours)
{
	if (hours<=40)
		return hours*pay_per_hour;
	else
		return pay_per_hour*40+1.5*pay_per_hour*(hours-40);
}
 SalariedWorker:: SalariedWorker(char n[10],int a,char s, int pay)
{
	strcpy(name,n);
	age=a;
	sex=s;
	pay_per_hour=pay;
}
 double SalariedWorker::Compute_pay(double hours)
 {
	 if (hours>=35)
		return 40*pay_per_hour;
	else
		return pay_per_hour*hours+0.5*pay_per_hour*(35-hours);
 }

 void input(Worker *q[5])
 {
	 cout<<"请输入"<<endl;
	 char n[10];
	 int  a;
	 char s;
	 int pay;
	 for(int i=0;i<3;i++)
	 {
		 cin>>n>>a>>s>>pay;
		 q[i]=new HourlyWorker(n,a,s,pay);
	 }
	  for(int j=3;j<5;j++)
	  {
		   cin>>n>>a>>s>>pay;
		  q[j]= new SalariedWorker(n,a,s,pay);
	  }
 }
void print_salary(Worker *q[5])
{
	cout<<"请选择工人号（1—5） （以0退出）"<<endl;
	int c;
	double t;
	cin>>c;
	while(c<=5&&c>=1)
	{
		cout<<*q[c-1];
		cout<<"请输入工作时间: ";
		cin>>t;
		cout<<"该工人的工资为 "<<q[c-1]->Compute_pay(t)<<endl;
		cout<<"请选择工人号（1—5） （以0退出）"<<endl;
		cin>>c;
	}
}


int main()
{
	int i;
	HourlyWorker h("aaa",34,'n',20);
	SalariedWorker w;
	HourlyWorker c;
	Worker * q[5];
	input(q);
//	q[0]=&h;
	for(i=0;i<5;i++)
		cout<<*q[i];
//	cout<<q[4]->Compute_pay(18.5);
	print_salary(q);
	return 0;
}
/*
aaa 34 m 10
bbb 35 m 20
ccc 36 m 40
ddd 37 m 30
eee 38 m 50
*/