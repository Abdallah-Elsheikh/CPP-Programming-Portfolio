#include <iostream>
#include <cmath>
using namespace std;


double calculateMonthlyPayment(double p, double r, int t, int n) {
    double ratePerPeriod = r / (n * 100);
    int totalPayments = t * n;
    return (p * ratePerPeriod) / (1 - pow(1 + ratePerPeriod, -totalPayments));
}

double calculateTotalPayments(double mp, int t, int n) {
    return mp * t * n;
}


double calculateTotalInterest(double tp, double p) {
    return tp - p;
}


double calculateTotalPayments(double p, double r, int t, int n) {
    double mp = calculateMonthlyPayment(p, r, t, n);
    return calculateTotalPayments(mp, t, n);
}


double calculateTotalInterest(double p, double r, int t, int n) {
    double tp = calculateTotalPayments(p, r, t, n);
    return calculateTotalInterest(tp, p);
}

int main() {
    double p, r;
    int t, n;

    cout << "Enter loan amount (P): ";
    cin >> p;
    cout << "Enter interest rate (R) in %: ";
    cin >> r;
    cout << "Enter loan term in years (T): ";
    cin >> t;
    cout << "Enter number of payments per year (N): ";
    cin >> n;

    double mp = calculateMonthlyPayment(p, r, t, n);
    double tp = calculateTotalPayments(mp, t, n);
    double ti = calculateTotalInterest(tp, p);

    cout << "Monthly Payment (MP): " << mp << endl;
    cout << "Total Payments (TP): " << tp << endl;
    cout << "Total Interest (TI): " << ti << endl;

    return 0;
}
