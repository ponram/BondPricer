#ifndef YIELDCURVE_H
#define YIELDCURVE_H
#include "Standards.h"
#include "DayCounter.h"
#include <map>

/**
The design of YieldCurve class was done considering the standard practice of quoting Bond Equivalent Yields
in the Bond market. Below are some FAQs taken from https://www.treasury.gov/resource-center/faqs/Interest-Rates/Pages/faq.aspx#4

1) Does the yield curve use a day count based on actual days in a year or a 30/360 year basis?

Yields on all Treasury securities are based on actual day counts on a 365- or 366-day year basis, 
not a 30/360 basis, and the yield curve is based on securities that pay semiannual interest.  
All yield curve rates are considered "bond-equivalent" yields.

2) Does the yield curve assume semiannual interest payments or is it a zero-coupon curve?

The yield curve is based on securities that pay interest on a semiannual basis, the yields are 
considered "bond-equivalent"  yields and the yield curve is considered a Par Yield Curve.  
Treasury does not create or publish daily zero-coupon curve rates.
*
*
**/



namespace BondPricer
{
	class YieldCurve
	{
	public:
		YieldCurve(const DateVector& vDates
		,const DoubleVector& vRates
		, const boost::gregorian::date& anchorDate
		,const std::string& sDayCountConvention
		,CompoundingMethod cmpMethod
		);
		YieldCurve();
		~YieldCurve();
		boost::gregorian::date GetAnchorDate() const;
		std::vector<double> GetRates() const;
		std::vector<boost::gregorian::date> GetDates() const;
		double GetYearFraction(boost::gregorian::date d1, boost::gregorian::date d2) const;
		CompoundingMethod GetCompoundingMethod() const;
	private:
		std::map<boost::gregorian::date, double> yieldCurve;
		boost::gregorian::date anchorDate;
		DayCounter dayCounter;
		CompoundingMethod cmpMethod;
				
	};

	inline YieldCurve::YieldCurve()
	{

	}

	inline YieldCurve::~YieldCurve()
	{

	}

	inline boost::gregorian::date YieldCurve::GetAnchorDate() const
	{
		return anchorDate;
	}

	inline CompoundingMethod YieldCurve::GetCompoundingMethod() const
	{
		return cmpMethod;
	}

}//namespace BondPricer


#endif // !YIELDCURVE_H
