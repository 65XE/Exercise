// Exercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Cache.h"

Exercise::Cache prepare_cache()
{
	Exercise::Cache cache("OrdId1", "US9128473801", "Buy", 1000, "User1", "CompanyA");
	cache.add("OrdId2", "US5422358DA3", "Sell", 3000, "User2", "CompanyB");
	cache.add("OrdId3", "US9128473801", "Sell", 500, "User3", "CompanyA");
	cache.add("OrdId4", "US5422358DA3", "Buy", 600, "User4", "CompanyC");
	cache.add("OrdId5", "US5422358DA3", "Buy", 100, "User5", "CompanyB");
	cache.add("OrdId6", "US19635GY645", "Buy", 1000, "User6", "CompanyD");
	cache.add("OrdId7", "US5422358DA3", "Buy", 2000, "User7", "CompanyE");
	cache.add("OrdId8", "US5422358DA3", "Sell", 5000, "User8", "CompanyE");
	cache.add("OrdId9", "US19635GY645", "Sell", 1000, "User1", "CompanyD");
	cache.add("OrdId999", "US19635GY999", "Buy", 10000, "User1", "CompanyX");

	Exercise::Order order("OrdId65", "US19635GY999", "Sell", 10000, "User10", "CompanyY");
	cache.add(order);

	return cache;
}

int main()
{
    std::cout << "Starting Demonstration of exercise.\n";

	//only for below demonstration purpose.
	auto cache = prepare_cache();

	std::cout << "All orders : \n";
	cache.print();

	std::cout << "\nAccording to exercise requirements:\n";
	std::cout << "\nPoint 1. match func: \nResult of cache.match(\"US5422358DA3\") = "
		<< cache.match("US5422358DA3") << "\n";

	std::cout << "\nPoint 2. cancel* functionalities:\n";

	std::cout << "\nAfter cancel OrdId3:\n";
	cache.cancel("OrdId3");
	cache.print();

	std::cout << "\nAfter cancel all orders for a given Security ID "
		<< "\nat or above a given quantity"
		<< "\nf.e. Security ID = \"US19635GY999\", quantity = 1200:\n";
	cache.cancel_all_securities("US19635GY999", 1200);
	cache.print();

	std::cout << "\nAfter cancel all orders for given user id "
		<< "\nf.e. User1\n";
	cache.cancel_all_for_user_id("User1");
	cache.print();

	std::cout << "\nDemo end. Thank you.\n";
}