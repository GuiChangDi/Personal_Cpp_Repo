#include "../Header/OOP00.h"
#include <iostream>

//Stock function definition
void Stock::acquire(const std::string & co,long n, double pr)
{
    company = co;
    if(n < 0)
    {
        std::cout<<"Number of shares can't be negative; "
                 <<company<<" shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
    if(num < 0)
        std::cout<<"Number of buying shares can't be negative;\n";
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num,double price)
{
    if( num > shares || num < 0 )
        std::cout<<"Invalid sell numbers\n";
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig=
        cout.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout<<"Company: "<<company
        <<" Shares: "<<shares<<'\n';
    cout<<" Share Price: $"<<share_val;

    cout.precision(2);
    cout<<"  Total Worth: $"<<total_val<<'\n';

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

Stock::Stock(const std::string &co,long n,double pr)
{
    company = co;
    std::cout<<"Constructor called!"<<std::endl;
    if(n<0)
    {
        std::cout<<"Number of shares can't be negative;"
                 << company<<" shares set to 0.\n";
        shares;
    }
    else
    {
        shares = n;
        share_val = pr;
        set_tot();
    }
    
}

Stock::Stock()
{
    std::cout<<"Default constructor called!\n";
    company = "None";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::~Stock()
{
    std::cout<<"Destructor called!"<<std::endl;
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}

//Time function definition
Time::Time()
{
    hours = minute = 0;
}

Time::Time(int h,int m)
{
    hours = h;
    minute = m;
}

void Time::AddMin(int m)
{
    minute += m;
    hours += (minute/60);
    minute %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h,int m)
{
    hours = h;
    minute = m;
}

Time Time::Sum(const Time & t) const
{
    Time result;
    result.minute = minute + t.minute;
    result.hours = hours + t.hours + (t.minute)/60;
    result.minute %= 60;
    return result;
}

void Time::Show() const 
{
    std::cout<<"Time: "<<hours<<" hours "<<minute<<" minutes\n";
}

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minute = t.minute + minute;
    sum.hours = t.hours + hours + sum.minute/60;
    sum.minute %= 60;
    return sum;
}

int main()
{
    Time a(2,30);
    Time b(3,20);
    Time c = a+b;
    c.Show();
    Time d;
    d = d.Sum(a);
    d.Show();
    return 0;
}