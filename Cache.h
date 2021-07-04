#pragma once
#include "Order.h"
#include <vector>

namespace Exercise
{
	class Cache
	{
	private:
		std::vector<Order> orders_;

	public:
		Cache(const Order& order);
		
		~Cache();

		std::vector<Order> get_orders() const;

		void add(const Order& order);

		void operator +=(const Order& order);

		void print();

		void cancel(const OrderId& order_id);

		//void cancel_all(const UserId& userId);

		//void cancel_all(const SecurityId& securityId);

		void cancel_all_securities(const SecurityId& val);

		void cancel_all_for_user_id(const UserId& val);

		Quantity match(const SecurityId& securityId) const;
	};
}

