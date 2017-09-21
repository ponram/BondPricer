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
		double ear = 0; // ear is effective annual rate
		double hpy = 0; //hpy is "Holding Period Yield"

		for (unsigned int i = 0; i < vDates.size(); ++i)
		{
			date_duration dd = vDates[i] - anchordate;
			int node = std::abs(dd.days());
			double yearfraction = yc.GetYearFraction(anchordate, vDates[i]);
			 			
			if (vDates[i] < threshold_dt && yearfraction != 0)
			{
				hpy = vRates[i] * yearfraction;
				cont_rate = std::log(1 + hpy)*(1 / yearfraction); 
				zeroRates.insert(std::make_pair(node, cont_rate));
			}
			else if (yearfraction >= 1 && cmpMethod == SEMIANNUAL)
			{
				ear = (1 + vRates[i] / 2) * (1 + vRates[i] / 2);
				cont_rate = std::log(ear);
				zeroRates.insert(std::make_pair(node, cont_rate));
			}
			else //Need to cover other compounding methods
			{
					zeroRates.insert(std::make_pair(node, 0));
			}
		}
	}
		
}//namespace BondPricer