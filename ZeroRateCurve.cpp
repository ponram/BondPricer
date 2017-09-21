#include "ZeroRateCurve.h"
using namespace boost::gregorian;
namespace BondPricer
{

	ZeroRateCurve::ZeroRateCurve(const YieldCurve& yc)
	{
		DateVector vDates = yc.GetDates();
		DoubleVector vRates = yc.GetRates();
		date anchordate = yc.GetAnchorDate();
		CompoundingMethod cmpMethod = yc.GetCompoundingMethod();
		date threshold_dt = anchordate + years(1); //Threshold date to calculate year fraction <= 1
		double cont_rate = 0; //Continuous annual rate

		for (unsigned int i = 0; i < vDates.size(); ++i)
		{
			date_duration dd = vDates[i] - anchordate;
			double yearfraction = yc.GetYearFraction(anchordate, vDates[i]);
			double hpy = vRates[i] * yearfraction; //hpy is "Holding Period Yield"
			
			if (vDates[i] < threshold_dt)
			{
				if (yearfraction != 0)
				{
					cont_rate = std::log(1 + hpy)*(1 / yearfraction); //something wrong here
					zeroRates.insert(std::make_pair(dd.days(), cont_rate));
				}
				else
					zeroRates.insert(std::make_pair(dd.days(), 0));
		
			}
			else
			{

			}
		}
		
	}



}