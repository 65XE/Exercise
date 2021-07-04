#include "Cache.h"

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
	void Cache::cancel(const OrderId& orderId)
	{
		//todo
	}
	void Cache::cancel_all(const std::string& val)
	{
		//todo
	}
	Quantity Cache::match(const SecurityId& securityId) const
	{
		//todo
		return Quantity();
	}
}