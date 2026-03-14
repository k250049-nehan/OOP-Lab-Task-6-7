#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double a, string code, string symbol, double rate) {
        amount = a;
        currencyCode = code;
        currencySymbol = symbol;
        exchangeRate = rate;
    }

    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    double convertTo(Currency &target) {
        double base = convertToBase();
        return base / target.exchangeRate;
    }

    virtual void displayCurrency() {
        cout << "Currency: " << currencyCode << endl;
        cout << "Amount: " << currencySymbol << amount << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double a) : Currency(a, "USD", "$", 1.0) {}

    double convertToBase() {
        return amount * exchangeRate;
    }

    void displayCurrency() {
        cout << "US Dollar: $" << amount << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double a) : Currency(a, "EUR", "€", 1.1) {}

    double convertToBase() {
        return amount * exchangeRate;
    }

    void displayCurrency() {
        cout << "Euro: €" << amount << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double a) : Currency(a, "PKR", "Rs ", 0.0036) {}

    double convertToBase() {
        return amount * exchangeRate;
    }

    void displayCurrency() {
        cout << "Rupee: Rs " << amount << endl;
    }
};

int main() {
    Dollar d(100);
    Euro e(100);
    Rupee r(10000);

    d.displayCurrency();
    cout << "In Euro: " << d.convertTo(e) << endl;
    cout << "In Rupee: " << d.convertTo(r) << endl;

    cout << endl;

    e.displayCurrency();
    cout << "In Dollar: " << e.convertTo(d) << endl;
    cout << "In Rupee: " << e.convertTo(r) << endl;

    cout << endl;

    r.displayCurrency();
    cout << "In Dollar: " << r.convertTo(d) << endl;
    cout << "In Euro: " << r.convertTo(e) << endl;

    return 0;
}
