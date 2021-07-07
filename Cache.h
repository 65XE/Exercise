#pragma once
#include "Order.h"
#include <map>

namespace Exercise
{
	class Cache
	{
	private:
		std::map<OrderId, Params> orders_;

		template<typename T>
		void cancel_field(const T& t);

	public:
		Cache(const Order& order);
		
		~Cache();

		//std::vector<Order> get_orders() const;

		void add(const Order& order);

		void operator +=(const Order& order);

		//pk-test to remove
		void print();

		void cancel(const OrderId& order_id);

		void cancel_all_securities(const SecurityId& security, const Quantity quantity);

		void cancel_all_for_user_id(const UserId& user_id);

		Quantity match(const SecurityId& security_id) const;

	};
}

