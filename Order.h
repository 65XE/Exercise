#pragma once
#include "Types.h"


namespace Exercise
{
	/*
	* Actually this structure is not needed for satisfy this exercise
	* It is only added to show various options for adding orders into 
	* cache.
	*/
	struct Order
	{
		OrderId order_id_;
		Params	params_;

		Order(OrderId order_id, SecurityId security_id, Side sell, Quantity quantity,
			UserId user_id, CompanyName c_name);
	};
}

