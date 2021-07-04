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
	//private:
		OrderId order_id_;
		Params	params_;
		std::map<OrderId, Params> order_map_;

	//public:
		Order(OrderId order_id, SecurityId security_id, Sell sell, Quantity quantity,
			UserId user_id, CompanyName c_name);

		~Order();

		//pk-test to remove!
		void print() const;

		std::map<OrderId, Params> get_order_map();

		void remove_me();
	};
}

