#pragma once
#include <map>
#include <string>

class InMemoryDB
{
private:
	std::map<std::string, int> DB;
	std::map<std::string, int> transactions;
	bool transactionInit{ false };

public:
	int get(std::string key);

	void put(std::string key, int val);

	inline void begin_transaction()
	{
		transactionInit = true;
		transactions = DB;
	}

	void commit();

	void rollback();

};

