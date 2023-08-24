#pragma once
#include "Order.h"
#include <unordered_map>
#include "Types.h"

namespace Exercise
{
	class Cache
	{
	private:
		Orders orders_;

		Quantity compute_quantity(std::pair<OrderId, Params> order, const SecurityId& security_id);

	public:
		Cache(const Order& order);

		Cache(OrderId order_id, SecurityId security_id, Side sell, Quantity quantity,
			UserId user_id, CompanyName c_name);

		void add(OrderId order_id, SecurityId security_id, Side sell, Quantity quantity,
			UserId user_id, CompanyName c_name);

		void add(const Order& order);

		void print() const;

		void cancel(const OrderId& order_id);

		void cancel_all_securities(const SecurityId& security, const Quantity quantity);

		void cancel_all_for_user_id(const UserId& user_id);

		bool check_if_order_exist(const OrderId& order_id) const;

		size_t get_size() const;

		Quantity match(const SecurityId& security_id);
	};
}

