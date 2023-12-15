#include "Investment.h"

//mutators
void Investment::setinitialInvestment(double P) {
	initialInvestment = P;
}

void Investment::setmonthlyDeposit(double m) {
	monthlyDeposit = m;
}

void Investment::setrate(double r) {
	rate = r;
}

void Investment::settime(double t) {
	time = t;
}

//accessors
double Investment::getinitialInvestment() const {
	return initialInvestment;
}

double Investment::getmonthlyDeposit() const {
	return monthlyDeposit;
}

double Investment::getrate() const {
	return rate;
}

double Investment::gettime() const {
	return time;
}


