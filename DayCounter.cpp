#include "DayCounter.h"
#include <exception>
#include "boost/exception/all.hpp"
#include <algorithm>
using namespace boost::gregorian;

namespace BondPricer
{

	DayCounter::DayCounter(const std::string& dcConvention)
	{
		/*if (!(dcConvention == "30/360"
			|| dcConvention == "Act/360"
			|| dcConvention == "act/360"
			|| dcConvention == "ACT/360"
			|| dcConvention == "act/act"
			|| dcConvention == "ACT/ACT"
			))
			throw BOOST_THROW_EXCEPTION("Invalid arguments"); ***/
		sDayCountConvention = dcConvention; 
	}

	double DayCounter::GetDayCount(date d1, date d2) const
	{
		double daycount = 0;
		
		if (sDayCountConvention == "30/360")//Following ISDA2006 definition of 30-360 rule 
		{
			int day1 = d1.day();
			int day2 = d2.day();
			
			if (day1 == 31)
				day1 = 30;

			if (day2 == 31 && (day1 == 30 || day1 == 31))
				day2 = 30;
			else
				day2 = std::min(31, day2);

			daycount = (d2.year() - d1.year()) * 360 \
				+ (d2.month() - d1.month()) * 30 \
				+ (day2 - day1);
						
		}
		else if (sDayCountConvention == "ACT/365"
			|| sDayCountConvention == "Act/365"
			|| sDayCountConvention == "act/365")
		{
			date_duration dd = d1 - d2;
			daycount = dd.days();

		}

		return daycount;
	}

}