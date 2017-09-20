#ifndef ZERORATECURVE_H
#define ZERORATECURVE_H

#include "YieldCurve.h"
#include <map>

/**
* ZeroRateCurve was designed to avoid confusion regarding YTM vs zero-rates. The rates will be maintained as
* continuously compounded rates for ease of calculating discount factors. 
* This is consistent with industry practice  
*
**/

namespace BondPricer
{
	class ZeroRateCurve
	{
	public:
		ZeroRateCurve(const YieldCurve& yc);

	private:
		std::map<int, double> zeroRates;
	};


}




#endif // !ZERORATECURVE_H
