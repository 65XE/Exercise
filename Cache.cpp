#include "Cache.h"

namespace Exercise
{
	Cache::Cache(const Order& order) : 
		orders_{ {order.order_id_, order.params_} } {}

	Cache::Cache(OrderId order_id, SecurityId security_id, Sell sell, Quantity quantity,
		UserId user_id, CompanyName c_name) :
		orders_{ {order_id, {security_id, sell, quantity, user_id, c_name}} } {}

	void Cache::add(OrderId order_id, SecurityId security_id, Sell sell, Quantity quantity,
		UserId user_id, CompanyName c_name)
	{
		const Params& p{ security_id, sell, quantity, user_id, c_name };
		orders_.insert_or_assign(order_id, p);
	}

	void Cache::operator+=(const Order& order)
	{
		orders_.insert_or_assign(order.order_id_, order.params_);
	}

	void Cache::print() const
	{
		std::cout << "\n-----------------\n";
		std::cout << "\nCache content :\n";

		for (const auto& e : orders_)
		{
			
			std::cout << e.first << " " << e.second.security_id_
				<< " " << e.second.sell_
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
		for (auto it = orders_.begin(); it != orders_.end();)
		{
			if (it->second.security_id_ == security && it->second.quantity_ >= quantity)
			{
				it = orders_.erase(it);
			}
			else
				++it;
		}
		/*for (const auto& e : orders_)
		{
			if (e.second.security_id_ == security && e.second.quantity_ >= quantity)
			{
				orders_.erase(orders_.find(e.first));
			}
		}*/
	}

	void Cache::cancel_all_for_user_id(const UserId& user_id)
	{
		for (auto it = orders_.begin(); it != orders_.end();)
		{
			if (it->second.user_id_ == user_id)
			{
				it = orders_.erase(it);
			}
			else
				++it;
		}
		/*for (const auto& e : orders_)
		{
			if (e.second.user_id_ == user_id) { orders_.erase(orders_.find(e.first)); }
		}*/
	}

	bool Cache::check_if_order_exist(const OrderId& order_id) const
	{
		return (orders_.find(order_id) != orders_.end()) ? true : false;
	}

	Quantity Cache::match(const SecurityId& security_id)
	{
		Quantity total_quant = 0;

		for (auto it = orders_.begin(); it != orders_.end();)
		{
			if (it->second.sell_ == "Buy" || it->second.security_id_ != security_id )
			{
				++it;
				continue;
			}
			for (auto it2 = orders_.begin(); it2 != orders_.end();)
			{
				if (it->first == it2->first
					|| it->second.sell_ == it2->second.sell_
					|| it->second.c_name_ == it2->second.c_name_
					|| it2->second.security_id_ != security_id)
				{
					++it2;
					continue;
				}
				total_quant += it2->second.quantity_;
				if (it->second.quantity_ >= it2->second.quantity_)
				{
					it->second.quantity_ -= it2->second.quantity_;
					it2->second.quantity_ = 0;
				}
				else
				{
					it->second.quantity_ = 0;
					it2->second.quantity_ -= it->second.quantity_;
				}
				++it2;
			}
			++it;
		}
		return total_quant;
	}
}