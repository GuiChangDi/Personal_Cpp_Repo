#include "../Header/OOP00.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

// formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

//Brass Methods
Brass::Brass(const string & n,long an,double ba)
{
    Name = n;
    accNum = an;
    balance = ba;
}

void Brass::Deposit(double n)
{
    if(n > 0)
        balance += n;
    else
        cout<<"Negative Deposit not Allowed!"<<endl;
}

void Brass::Withdraw(double mt)
{
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if(mt < 0)
        cout<<"Withdrawal amount must be positive; "
            <<"withdrawal canceled.\n";
    else if ( mt <= balance)
        balance -= mt;
    else
        cout<<"Withdrawal amount of $"<<mt
            <<" exceeds your balance.\n"
            <<"Withdrawal canceled.\n";
    restore(initialState,prec);
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    //set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout<<"Clent: "<< Name<<endl;
    cout<<"Account Number: "<<accNum<<endl;
    cout<<"Balance: $"<<balance<<endl;
    restore(initialState, prec); //restore original format
}

//BrassPlus Methods
BrassPlus::BrassPlus(const string & n,long an,double bal,double ml, double r) : Brass(n,an,bal)// uses implicit copy constructor
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba,double ml,double r) : Brass(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

//redefine how ViewAcct() works
void BrassPlus::ViewAcct() const 
{
    //set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();
    cout<<"Maximum loan: $"<<maxLoan<<endl;
    cout<<"Owed to bank: $"<<owesBank<<endl;
    cout.precision(3);
    cout<<"Loan Rate: "<<100*rate<<"%\n";
    restore(initialState,prec);
}

//redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{
    //set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if( amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout<<"Bank advance: $"<<advance * rate <<endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout<<"Credit limit exceeded. Transaction cancelled.\n";
    restore(initialState,prec);
}

format setFormat()
{
    // set up ###.## format
    return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}