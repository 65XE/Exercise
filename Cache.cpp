#include "Cache.h"
#include <iostream>

namespace Exercise
{
	Cache::Cache(const Order& order) :
		orders_{ {order.order_id_, order.params_} } {}

	Cache::Cache(OrderId order_id, SecurityId security_id, Side sell, Quantity quantity,
		UserId user_id, CompanyName c_name) :
		orders_{ {order_id, {security_id, sell, quantity, user_id, c_name}} } {}

	void Cache::add(OrderId order_id, SecurityId security_id, Side sell, Quantity quantity,
		UserId user_id, CompanyName c_name)
	{
		const Params& p{ security_id, sell, quantity, user_id, c_name };
		orders_.insert_or_assign(order_id, p);
	}

	void Cache::add(const Order& order)
	{
		orders_.insert_or_assign(order.order_id_, order.params_);
	}

	void Cache::print() const
	{
		std::cout << "\nCache content :\n";

		for (const auto& e : orders_)
		{

			std::cout << e.first << " " << e.second.security_id_
				<< " " << e.second.side_
				<< " " << e.second.quantity_
				<< " " << e.second.user_id_
				<< " " << e.second.c_name_ << "\n";
		}
	}

	void Cache::cancel(const OrderId& order_id)
	{
		orders_.erase(orders_.find(order_id));
	}

	void Cache::cancel_all_securities(const SecurityId& security, const Quantity quantity)
	{
		//C++20 version
		const auto cnt = std::erase_if(orders_, [&security, quantity](const auto& item) {
			auto const& [key, value] = item;
			if (value.security_id_ == security && value.quantity_ >= quantity)
			{
				return true;
			}
		});

	}

	void Cache::cancel_all_for_user_id(const UserId& user_id)
	{
		//C++20 version
		std::erase_if(orders_, [&user_id](const auto& item) {
			auto const& [key, value] = item;
			if (value.user_id_ == user_id)
			{
				return true;
			}
		});
	}

	bool Cache::check_if_order_exist(const OrderId& order_id) const
	{
		return (orders_.find(order_id) != orders_.end()) ? true : false;
	}

	size_t Cache::get_size() const
	{
		return orders_.size();
	}

	Quantity Cache::match(const SecurityId& security_id)
	{
		Quantity total_quant = 0;
		for (auto& it : orders_)
		{
			if (it.second.side_ == "Buy" || it.second.security_id_ != security_id)
			{
				continue;
			}
			total_quant += compute_quantity(it, security_id);
		}
		return total_quant;
	}
	Quantity Cache::compute_quantity(std::pair<OrderId, Params> order, const SecurityId& security_id) 
	{
		auto quant = 0;
		for (auto& another : orders_)
			{
				if (order.first == another.first
					|| order.second.side_ == another.second.side_
					|| order.second.c_name_ == another.second.c_name_
					|| another.second.security_id_ != security_id)
				{
					continue;
				}
				quant += another.second.quantity_;
				if (order.second.quantity_ >= another.second.quantity_)
				{
					order.second.quantity_ -= another.second.quantity_;
					another.second.quantity_ = 0;
				}
				else
				{
					order.second.quantity_ = 0;
					another.second.quantity_ -= order.second.quantity_;
				}
			}
		return quant;
	}

}