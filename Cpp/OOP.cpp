#include "../Header/OOP00.h"
#include <iostream>

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

void Stock::show()
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
    std::cout<<"Default constructor called\n";
    company = "None";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

int main()
{
    Stock p("Intel",20,20);
    //p.acquire("Intel",20,20);
    p.show();
    p.buy(23,15);
    p.show();
    p.sell(23,15);
    p.show();
    return 0;
}