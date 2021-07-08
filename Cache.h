#pragma once
#include "Order.h"
#include <map>
#include <iostream>

namespace Exercise
{
	class Cache
	{
	private:
		std::map<OrderId, Params> orders_;

	public:
		Cache(const Order& order);

		Cache(OrderId order_id, SecurityId security_id, Sell sell, Quantity quantity,
			UserId user_id, CompanyName c_name);

		Cache(Cache const& other) = default;
		Cache(Cache&& other) = default;
		Cache& operator=(Cache&& other) = default;
		Cache& operator=(Cache const& other) = default;
		~Cache() = default;

		void add(OrderId order_id, SecurityId security_id, Sell sell, Quantity quantity,
			UserId user_id, CompanyName c_name);

		void operator +=(const Order& order);

		void print() const;

		void cancel(const OrderId& order_id);

		void cancel_all_securities(const SecurityId& security, const Quantity quantity);

		void cancel_all_for_user_id(const UserId& user_id);

		bool check_if_order_exist(const OrderId& order_id) const;

		Quantity match(const SecurityId& security_id);
	};
}

