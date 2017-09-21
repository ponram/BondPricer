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
	
	/***Load below yield curve obtained from https://www.treasury.gov/resource-center/data-chart-center/interest-rates/Pages/TextView.aspx?data=yield/ ***/
	
	/* Date	   1 Mo	   3 Mo	   6 Mo	   1 Yr	    2 Yr	3 Yr	5 Yr	7 Yr	10 Yr	20 Yr	30 Yr
     09/01/17	0.96	1.02	1.10	1.24	1.35	1.46	1.73	1.99	2.16	2.51	2.77***/
	
	
	date anchordate(2017, 9, 8); //2017-Sep-08
		
	int aMonthNodes[] = { 1,3,6 };
	int aYearNodes[] = { 1,2,3,5,7,10,20,30 };
	double aRates[] = { 0.96,1.04,1.14,1.22,1.27,1.39,1.64,1.89,2.06,2.41,2.67 };
	std::vector<int> vMonthNodes(aMonthNodes, aMonthNodes + (sizeof(aMonthNodes) / sizeof(aMonthNodes[0])));
	std::vector<int> vYearNodes(aYearNodes, aYearNodes + (sizeof(aYearNodes) / sizeof(aYearNodes[0])));
	DoubleVector vRates(aRates, aRates + (sizeof(aRates) / sizeof(aRates[0])));
	
	DateVector vDates;
	for (unsigned int i = 0; i < vMonthNodes.size(); ++i)
		vDates.push_back(anchordate + months(vMonthNodes[i]));
	for (unsigned int i = 0; i < vYearNodes.size(); ++i)
		vDates.push_back(anchordate + years(vYearNodes[i]));

	YieldCurve yc(vDates, vRates, anchordate,"Act/365",SEMIANNUAL); //create an yield curve object
	ZeroRateCurve zc(yc);
	
	
	return 0;

}