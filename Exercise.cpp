// Exercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Cache.h"

int main()
{
    std::cout << "Hello World!\n";

	/*std::vector<Exercise::Order> orders{
		{"OrdId1", "US9128473801", "Buy",  1000, "User1", "CompanyA"},
		{"OrdId2", "US5422358DA3", "Sell", 3000, "User2", "CompanyB"},
		{"OrdId3", "US9128473801", "Sell",  500, "User3", "CompanyA"},
		{"OrdId4", "US5422358DA3", "Buy", 600, "User4", "CompanyC"},
		{"OrdId5", "US5422358DA3", "Buy", 100, "User5", "CompanyB"},
		{"OrdId6", "US19635GY645", "Buy", 1000, "User6", "CompanyD"},
		{"OrdId7", "US5422358DA3", "Buy", 2000, "User7", "CompanyE"},
		{"OrdId8", "US5422358DA3", "Sell", 5000, "User8", "CompanyE"}
	};*/
	Exercise::Order order1("OrdId1", "US9128473801", "Buy", 1000, "User1", "CompanyA");
	Exercise::Order order2("OrdId2", "US5422358DA3", "Sell", 3000, "User2", "CompanyB");
	Exercise::Order order3("OrdId3", "US9128473801", "Sell", 500, "User3", "CompanyA");
	Exercise::Order order4("OrdId4", "US5422358DA3", "Buy", 600, "User4", "CompanyC");
	Exercise::Order order5("OrdId5", "US5422358DA3", "Buy", 100, "User5", "CompanyB");
	Exercise::Order order6("OrdId6", "US19635GY645", "Buy", 1000, "User6", "CompanyD");
	Exercise::Order order7("OrdId7", "US5422358DA3", "Buy", 2000, "User7", "CompanyE");
	Exercise::Order order8("OrdId8", "US5422358DA3", "Sell", 5000, "User8", "CompanyE");
	Exercise::Order order9("OrdId9", "US19635GY645", "Sell", 1000, "User1", "CompanyD");

	Exercise::Cache cache(order1);
	cache += order2;
	cache.add(order3);
	cache += order4;
	cache.add(order5);
	cache += order6;
	cache.add(order7);
	cache += order8;
	cache.add(order9);

	auto result = cache.get_orders();

	for (auto&& e : result)
		e.print();

	std::cout << "Before cancel OrdId4:\n";
	cache.print();
	cache.cancel("OrdId4");

	std::cout << "After cancel OrdId4:\n";
	cache.print();

	std::cout << "After cancel_all_securities US5422358DA3:\n";
	cache.cancel_all_securities("US5422358DA3");
	cache.print();

	std::cout << "After cancel_all_for_user_id User1:\n";
	cache.cancel_all_for_user_id("User1");
	cache.print();

	std::cout << "Exercise end\n";

}