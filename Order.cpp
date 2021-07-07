#include "Order.h"

namespace Exercise
{
	Order::Order(OrderId order_id, SecurityId security_id, Sell sell, Quantity quantity,
		UserId user_id, CompanyName c_name) 
		: order_id_(order_id),
		params_{security_id, sell, quantity, user_id, c_name}{}

	Order::~Order() {}
}