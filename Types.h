#pragma once
#include <string>
#include <unordered_map>

using OrderId = std::string;
using SecurityId = std::string;
using Side = std::string;
using Quantity = int;
using UserId = std::string;
using CompanyName = std::string;

struct Params
{
	SecurityId  security_id_;
	Side		side_;
	Quantity	quantity_;
	UserId		user_id_;
	CompanyName c_name_;
};

using Orders = std::unordered_map<OrderId, Params>;