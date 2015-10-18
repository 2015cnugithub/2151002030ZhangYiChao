class Worker{
protected:
	char  name[10];
	int age;
	char sex;
	int pay_per_hour;
public:
	virtual double Compute_pay(double hours)=0;
	friend ostream& operator<<(ostream &out, Worker&worker);
};

class HourlyWorker : public Worker{
public:
	HourlyWorker(){}
	HourlyWorker(char n[10],int a,char s, int pay);
    virtual double Compute_pay(double hours);
};

class SalariedWorker: public Worker{
public:
	SalariedWorker(){}
	SalariedWorker(char n[10],int a,char s, int pay);
	virtual double Compute_pay(double hours);
};
