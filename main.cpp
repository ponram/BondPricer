#include <iostream>
#include "Bond.h"
#include "DayCounter.h"
#include "YieldCurve.h"
#include "ZeroRateCurve.h"

using namespace std;
using namespace boost::gregorian;
using namespace BondPricer;

int main()
{
	
	/*********Create Bond Objects***********/
	Bond d;
	
	date issue_date(2017, 8, 10);
	date maturity(2018, 8, 10);
   	double notional = 1000;
	double redemption_price = 100;
	std::string currency = "USD";
	double rate = 0.05;
	int freq = 6;

	Bond bond(notional, redemption_price,currency, rate, freq, issue_date, maturity);

	DayCounter dc("30/360");
	date d1(2007, 8, 31);
	date d2(2008, 2, 29);
	dc.GetDayCount(d1, d2);

	/***Yield Curve Object************/
	date anchordate(2017, 9, 8);
		
	int aNodes[] = { 30,90,180,360,720,1080,1800,2520,360,720,1080 };
	double aRates[] = { 0.96,1.04,1.14,1.22,1.27,1.39,1.64,1.89,2.06,2.41,2.67 };
	std::vector<int> vNodes(aNodes, aNodes + (sizeof(aNodes) / sizeof(aNodes[0])));
	DoubleVector vRates(aRates, aRates + (sizeof(aRates) / sizeof(aRates[0])));
	
	DateVector vDates;
	for (unsigned int i = 0; i < vNodes.size(); ++i)
		vDates.push_back(anchordate + date_duration(vNodes[i]));

	YieldCurve yc(vDates, vRates, anchordate,"Act/365",SEMIANNUAL); //create an yield curve object
	ZeroRateCurve zc(yc);
	
	
	return 0;

}