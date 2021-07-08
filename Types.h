#pragma once
#include <string>

using OrderId = std::string;
using SecurityId = std::string;
using Sell = std::string;
using Quantity = int;
using UserId = std::string;
using CompanyName = std::string;

struct Params
{
	SecurityId  security_id_;
	Sell		sell_;
	Quantity	quantity_;
	UserId		user_id_;
	CompanyName c_name_;
};

