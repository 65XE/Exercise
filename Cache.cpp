#include "Cache.h"
#include <algorithm>

namespace Exercise
{
	Cache::Cache(const Order& order) : 
		orders_{ {order.order_id_, order.params_} } {}
	
	Cache::~Cache() {}
	
	void Cache::add(const Order& order)
	{
		orders_.insert_or_assign(order.order_id_, order.params_);
	}
	void Cache::operator+=(const Order& order)
	{
		orders_.insert_or_assign(order.order_id_, order.params_);
	}

	//pk-test to remove
	void Cache::print()
	{
		std::cout << "\n-----------------\n";
		std::cout << "\nPrint from Cache:\n";

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
	}

	/*template<typename T>
	void Cache::cancel_field(const T& t)
	{
		for (auto it = orders_.begin(); it != orders_.end();)
		{
			if (it->second.t == t)
			{
				it = orders_.erase(it);
			}
			else
				++it;
		}
	}*/


	Quantity Cache::match(const SecurityId& securityId) const
	{
		Quantity total_quant = 0;
		std::map<OrderId, Params> tmp;

		for (auto&& e : orders_)
		{
			if (e.second.security_id_ == securityId)
			{
				tmp.insert_or_assign(e.first, e.second);
			}
		}

		for (auto it = tmp.begin(); it != tmp.end();)
		{
			if (it->second.sell_ == "Buy")
			{
				++it;
				continue;
			}
			for (auto it2 = tmp.begin(); it2 != tmp.end();)
			{
				if (it->first == it2->first 
					|| it->second.sell_ == it2->second.sell_ 
					|| it->second.c_name_ == it2->second.c_name_)
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