#include <iostream>
#include <iomanip>

class Interest
{
private:
    int principal_;
    int rate_;
    int year_;
    double amount_;
    
public:
    // Constructor with default parameter
    Interest(int principal, int years, int rate = 10);
    
    // Calculate and display interest
    void calculate();
    
    // Getters
    int getPrincipal() const { return principal_; }
    int getRate() const { return rate_; }
    int getYear() const { return year_; }
    double getAmount() const { return amount_; }
};

interest::interest(int p, int n, int r)
{
    principal = p;
    year = n;
    rate = r;
}

void interest::cal(void)
{
    cout << "Principal: " << principal << endl;
    cout << "Rate: " << rate << endl;
    cout << "Year: " << year << endl;
    amount = (float)(principal * year * rate) / 100;
    cout << "Amount: " << amount << endl;
}

int main()
{
    interest i1(1000, 2);
    interest i2(1000, 2, 15);
    i1.cal();
    i2.cal();
    return 0;
}