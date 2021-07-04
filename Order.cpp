#include "Order.h"

namespace Exercise
{
	Order::Order(OrderId order_id, SecurityId security_id, Sell sell, Quantity quantity,
		UserId user_id, CompanyName c_name) : order_id_(order_id),
		params_{security_id, sell, quantity, user_id, c_name},
		order_map_{ {order_id_, params_} }{}

	Order::~Order() {}

	void Order::print() const {
		std::cout << order_id_ << " " << params_.security_id_
			<< " " << params_.sell_ << " " << params_.quantity_
			<< " " << params_.user_id_ << " " << params_.c_name_ << std::endl;
	}
	std::map<OrderId, Params> Order::get_order_map()
	{
		return order_map_;
	}
	void Order::remove_me()
	{
		std::cout << "please remove me!\n";
	}
}