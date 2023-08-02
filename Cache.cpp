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
		//C++1x version
		/*for (auto it = orders_.begin(); it != orders_.end();)
		{
			if (it->second.security_id_ == security && it->second.quantity_ >= quantity)
			{
				it = orders_.erase(it);
			}
			else
				++it;
		}*/

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
		////C++1x version
		/*for (auto it = orders_.begin(); it != orders_.end();)
		{
			if (it->second.user_id_ == user_id)
			{
				std::cout << "Usuwam " << it->second.user_id_ << " poniewaz argumentem do funkcji bylo " << user_id << std::endl;
				it = orders_.erase(it);
			}
			else
				++it;
		}*/

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
			for (auto& it2 : orders_)
			{
				if (it.first == it2.first
					|| it.second.side_ == it2.second.side_
					|| it.second.c_name_ == it2.second.c_name_
					|| it2.second.security_id_ != security_id)
				{
					continue;
				}
				total_quant += it2.second.quantity_;
				if (it.second.quantity_ >= it2.second.quantity_)
				{
					it.second.quantity_ -= it2.second.quantity_;
					it2.second.quantity_ = 0;
				}
				else
				{
					it.second.quantity_ = 0;
					it2.second.quantity_ -= it.second.quantity_;
				}
			}
		}
		return total_quant;
	}
}