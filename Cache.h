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

		void cancel(const OrderId& orderId);

		//void cancel_all(const UserId& userId);

		//void cancel_all(const SecurityId& securityId);

		void cancel_all(const std::string& val);

		Quantity match(const SecurityId& securityId) const;
	};
}

