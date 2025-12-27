// DATE: 26/12/2025
// SET NUMBER: 2
// 1. NAME: SHASYA SHAFIEQAH BINTI SHAHARUDDIN
//    MATRICS NUMBER: A25CS0350
// 2. NAME: FARAH AISYA BINTI JAAFAR
//    MATRICS NUMBER: A25CS0218

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
void getInput(int &, int &, int &);
void carInfo(int, int, int, float &);
float getPrice(int, int, int);
void inputPayment(float &, float &, int &);
float calculateMonthlyRepayment(float, float, int);

int main()
{

    int model, variant, region, loanPeriod;
    float price, downPayment, interestRate, monthlyRepayment, totalLoan;
    char p;

    for (int n = 0; n >= 0; n++)
    {

        cout << "Proton Car Loan Calculator\n";
        getInput(model, variant, region);
        carInfo(model, variant, region, price);
        inputPayment(downPayment, interestRate, loanPeriod);

        while (downPayment / price < 0 || downPayment / price > 100)
        {
            cout << "Invalid Down Payment." << endl;
            cout << "Please enter the right down payment between 0-100: ";
            inputPayment(downPayment, interestRate, loanPeriod);
        }

        totalLoan = price - downPayment;
        monthlyRepayment = calculateMonthlyRepayment(totalLoan, interestRate, loanPeriod);

        cout << endl;
        cout << "MONTHLY INSTALLMENT (MYR): " << monthlyRepayment << endl;

        cout << endl;
        cout << "Do you want to enter other data? [Y @ N]: ";
        cin >> p;

        if (p == 'n' || p == 'N')
        {
            break;
        }
    }

    cout << endl;
    cout << "Thank you :)";

    return 0;
}

void getInput(int &model, int &variant, int &region)
{

    cout << "Model [1-X50, 2-Exora, 3-Persona]: ";
    cin >> model;
    cout << "Variants [1-1.6L Standard CVT, 2-1.6L Premium CVT]: ";
    cin >> variant;
    cout << "Region [1-Peninsular Malaysia, 2-East Malaysia]: ";
    cin >> region;
}

void carInfo(int model, int variant, int region, float &price)
{
    cout << endl;
    cout << "Car Info" << endl;

    switch (model)
    {
    case 1:
        cout << "Model: X50" << endl;
        break;
    case 2:
        cout << "Model: Exora" << endl;
        break;
    case 3:
        cout << "Model: Persona" << endl;
        break;
    }

    switch (variant)
    {
    case 1:
        cout << "Variant: 1.6L Standard CVT" << endl;
        break;
    case 2:
        cout << "Variant: 1.6L Premium CVT " << endl;
        break;
    }

    switch (region)
    {
    case 1:
        cout << "Region: Peninsular Malaysia" << endl;
        break;
    case 2:
        cout << "Region: East Malaysia" << endl;
        break;
    }

    switch (variant)
    {
    case 1:
        cout << "Paint Type: Solid" << endl;
        break;
    case 2:
        cout << "Paint Type: Metallic" << endl;
        break;
    }

    price = getPrice(model, variant, region);

    cout << fixed << setprecision(2);
    cout << "Price (MYR): " << price << endl;
}

float getPrice(int model, int variant, int region)
{
    float price;
    if (model == 1)
        price = (variant == 1 ? (region == 1 ? 79200 : 81200) : (region == 1 ? 93200 : 95200));
    else if (model == 2)
        price = (variant == 1 ? (region == 1 ? 59800 : 61800) : (region == 1 ? 66800 : 68800));
    else
        price = (variant == 1 ? (region == 1 ? 44600 : 46600) : (region == 1 ? 54600 : 56600));
    return price;
}

void inputPayment(float &downPayment, float &interestRate, int &loanPeriod)
{
    cout << endl;
    cout << "Down Payment (MYR): ";
    cin >> downPayment;
    cout << "Interest Rate (%): ";
    cin >> interestRate;
    interestRate /= 100;
    cout << "Repayment period (in years): ";
    cin >> loanPeriod;
}

float calculateMonthlyRepayment(float totalLoan, float interestRate, int loanPeriod)
{

    float totalRepay, monthlyRepay;

    totalRepay = totalLoan + (totalLoan * interestRate * loanPeriod);
    monthlyRepay = totalRepay / (loanPeriod * 12);

    return monthlyRepay;
}