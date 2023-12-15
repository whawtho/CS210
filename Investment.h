#pragma once
#include <iostream>
#include <math.h>

class Investment
{
private:
	double initialInvestment, monthlyDeposit, rate, time;

public:
	void setinitialInvestment(double); //mutators to update private fields
	void setmonthlyDeposit(double);
	void setrate(double);
	void settime(double);

	double getinitialInvestment() const; //accessors to return varible stored in object
	double getmonthlyDeposit() const;
	double getrate() const;
	double gettime() const;

	double compoundInterest() {
		return (initialInvestment + ((monthlyDeposit * 12) * time)) * pow((1 + rate / 100), time);
	}
};

