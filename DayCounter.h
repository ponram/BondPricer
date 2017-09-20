#ifndef DAYCOUNTER_H
#define DAYCOUNTER_H
#include <string>
#include "boost/date_time/gregorian/gregorian.hpp"

namespace BondPricer
{
	class DayCounter
	{
	public:
		DayCounter();
		DayCounter(const std::string& dcconvention);
		void SetDayCountConvention(std::string& dcconvention);
		std::string GetDayCountConvention() const;
		double GetDayCount(boost::gregorian::date d1, boost::gregorian::date d2) const;
		~DayCounter();
		
	private:
		std::string sDayCountConvention;

	};

	inline DayCounter::DayCounter()
	{
		sDayCountConvention = "ACT/365";
	}

	inline std::string DayCounter::GetDayCountConvention() const
	{
		return sDayCountConvention;
	}

	inline void DayCounter::SetDayCountConvention(std::string& dcConvention)
	{
		sDayCountConvention = dcConvention;
	}

	inline DayCounter::~DayCounter() {}

	
}//namespace BondPricer


#endif // !DAYCOUNTER_H
