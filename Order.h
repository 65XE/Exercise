#pragma once
#include "Types.h"

namespace Exercise
{

	struct Order
	{
		OrderId order_id_;
		Params	params_;

		Order(OrderId order_id, SecurityId security_id, Sell sell, Quantity quantity,
			UserId user_id, CompanyName c_name);

		~Order();
	};
}

