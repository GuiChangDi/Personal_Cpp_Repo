#pragma once
#include <string>
#include <iostream>
using namespace std;

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val;}
public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num,double price);
    void update(double price);
    void show() const;
    Stock();//Default constructor
    Stock(const std::string & co, long n=0,double pr = 0.0);
    ~Stock();
    const Stock & topval(const Stock & s) const;
};

class Time
{
private:
    int hours;
    int minute;
public:
    Time();
    Time(int h,int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0,int m = 0);
    Time Sum(const Time & t) const;
    void Show() const;
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double mult) const;
    friend Time operator*(double m, const Time & t);
    friend ostream & operator<<(ostream & os, const Time & t);
};

using std::string;
class Tennis
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    Tennis(const string & fn = "None",const string & ln = "None",bool ht = false);
    void Name();
    bool HasTable() {return hasTable;};
    void ResetTable(bool v) {hasTable = v;};
};

class RatedPlayer:public Tennis
{
private:
    unsigned int rating;
public:
    RatedPlayer ( unsigned int r = 0, const string & fn = "None",const string & ln = "None", bool ht = false);
    RatedPlayer( unsigned int r, const Tennis & tp);
    unsigned int Rating() const { return rating;};
    void ResetRating ( unsigned int r) {rating = r;};
};

class Brass
{
private:
    string Name;
    long accNum;
    double balance;
public:
    Brass(const string & n = "None",long an = -1,double ba = 0.0);
    void Deposit(double n);
    virtual void Withdraw(double n);
    double Balance() const;
    virtual void ViewAcct() const;
    virtual ~Brass() {};
};

class BrassPlus: public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;//money owe to bank
public:
    BrassPlus(const string & n = "None", long an = -1,double bal = 0.0, double ml = 500,double r = 0.11125);
    BrassPlus(const Brass & ba, double ml = 500,double r = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) {maxLoan = m;};
    void ResetRate(double r) {rate = r;};
    void ResetOwes() { owesBank = 0;};
};