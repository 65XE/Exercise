#include "Cache.h"
#include <algorithm>

namespace Exercise
{
	Cache::Cache(const Order& order) : orders_{order} {}
	
	Cache::~Cache() {}
	
	std::vector<Order> Cache::get_orders() const 
	{
		return orders_;
	}
	void Cache::add(const Order& order)
	{
		orders_.push_back(order);
	}
	void Cache::operator+=(const Order& order)
	{
		orders_.push_back(order);
	}
	void Cache::print()
	{
		std::cout << "\n-----------------\n";
		std::cout << "\nPrint from Cache:\n";

		for (const auto& e : orders_)
		{
			for (const auto& [key, value] : e.order_map_)
			{
				std::cout << key << " " << value.security_id_
					<< " " << value.sell_
					<< " " << value.quantity_
					<< " " << value.user_id_
					<< " " << value.c_name_ << std::endl;
			}
		}
	}
	void Cache::cancel(const OrderId& order_id)
	{
		auto itr = std::remove_if(orders_.begin(), orders_.end(), [&order_id](Order& o) {return o.order_id_ == order_id; });
		orders_.erase(itr, orders_.end());
	}
	void Cache::cancel_all_securities(const SecurityId& val)
	{
		auto itr = std::remove_if(orders_.begin(), orders_.end(), [&val](Order& o) {return o.params_.security_id_ == val; });
		orders_.erase(itr, orders_.end());
	}

	void Cache::cancel_all_for_user_id(const UserId& val)
	{
		auto itr = std::remove_if(orders_.begin(), orders_.end(), [&val](Order& o) {return o.params_.user_id_ == val; });
		orders_.erase(itr, orders_.end());
	}

	Quantity Cache::match(const SecurityId& securityId) const
	{
		//todo
		return Quantity();
	}
}