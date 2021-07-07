#pragma once
#include "Types.h"
#include <map>

namespace Exercise
{
	struct Params
	{
		SecurityId  security_id_;
		Sell		sell_;
		Quantity	quantity_;
		UserId		user_id_;
		CompanyName c_name_;
	};

	struct Order
	{
		OrderId order_id_;
		Params	params_;

		Order(OrderId order_id, SecurityId security_id, Sell sell, Quantity quantity,
			UserId user_id, CompanyName c_name);

		~Order();
	};
}

