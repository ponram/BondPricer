#include "YieldCurve.h"

using namespace boost::gregorian;

namespace BondPricer
{
	
	YieldCurve::YieldCurve(const DateVector& vDates
		, const DoubleVector& vRates
		, const date& anchorDate
		, const std::string& sDayCountConvention
		,CompoundingMethod cmpMethod
	):dayCounter(sDayCountConvention),cmpMethod(cmpMethod),anchorDate(anchorDate)
	{
		yieldCurve.insert(std::make_pair(anchorDate, 0)); //set a default rate of zero 
		
		if (vRates.size() != vDates.size())
		{
			//throw exception if size is different
		}

		for (unsigned int i = 0; i < vDates.size(); ++i)
			yieldCurve.insert(std::make_pair(vDates[i], vRates[i]));
	}

	
	std::vector<date> YieldCurve::GetDates() const
	{
		std::vector<date> vDates;
		for(m_Date_Const_Iter it = yieldCurve.begin(); it != yieldCurve.end(); ++it)
			vDates.push_back(it->first);

			return vDates;
	}
	
	std::vector<double> YieldCurve::GetRates() const
	{
		std::vector<double> vRates;
		for (m_Date_Const_Iter it = yieldCurve.begin(); it != yieldCurve.end(); ++it)
			vRates.push_back(it->second);

		return vRates;
	}

	double YieldCurve::GetYearFraction(date d1, date d2) const
	{
		std::string sDayCountConv = dayCounter.GetDayCountConvention();
		
		if (sDayCountConv == "30/360")
			return dayCounter.GetDayCount(d1, d2) / 360;
		else if (sDayCountConv == "ACT/365" || sDayCountConv == "Act/365" || sDayCountConv == "act/365")
			return dayCounter.GetDayCount(d1, d2) / 365;
		else
			return 1;//need to throw exception
	}
}