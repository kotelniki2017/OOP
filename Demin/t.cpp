 #include <iostream>
using namespace std;
class Time
{
	public:
	Time();
	void setTime(int, int, int);
	void printTime();
	private:
	int hour;
	int minute;
	int second;
};
Time::Time() {hour=minute=second=0;}
void Time::setTime(int h, int m, int s)
{
hour=(h>=0 && h<24)? h : 0;
minute=(m>=0 && m<60)? m : 0;
second=(s>=0 && s<60)? s : 0;
}
void Time::printTime()
{
cout<<((hour==0 || hour==12)? 12 : hour%12)
	<<":"<<(minute<10 ? "0":"")<<minute
	<<":"<<(second<10 ? "0":"")<<second
	<<(hour<12 ? "AM" : "PM");
}
int main()
{
Time t;
	cout<<"Нач. знач t"<<endl;
	t.printTime(); cout<<endl;
	t.setTime(14, 63, 17);
	cout<<"Изменения"<<endl;
	t.printTime(); cout<<endl;
	return 0;
}
