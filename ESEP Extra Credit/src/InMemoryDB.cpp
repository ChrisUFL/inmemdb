#include "InMemoryDB.h"
#include <iostream>
#include <exception>


int InMemoryDB::get(std::string key)
{
	if (DB.find(key) != DB.end())
	{
		return DB.at(key);
	}
	return NULL;
}

void InMemoryDB::put(std::string key, int val)
{
	if (!transactionInit)
	{
		throw std::runtime_error("Transaction not initialized");
	}

	if (transactions.find(key) != transactions.end())
	{
		transactions.at(key) = val;
	}
	else
	{
		transactions.insert(std::make_pair(key, val));
	}
}

void InMemoryDB::commit()
{
	if (transactions == DB)
	{
		throw std::runtime_error("No pending transactions");
	}

	DB = transactions;
	transactionInit = false;
}

void InMemoryDB::rollback()
{
	if (transactions == DB)
	{
		throw std::runtime_error("No pending transactions");
	}

	transactions = DB;
	transactionInit = false;
}
