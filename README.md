# Usage
Clone the repo

Open `ESEP Extra Credit.sln` with Visual Studio

In main.cpp create a new instance of the InMemoryDB class `InMemoryDB inmem`

To being a new transaction call begin_transaction `inmem.begin_transaction()`

Call required member functions
```
- void begin_transaction()
- int get(std::string key)
- void put(std::string key, int val)
- void commit()
- void rollback()
```

Build and run the application from VS. 


Example main.cpp:

```C++
#include "InMemoryDB.h"
#include <iostream>


int main()
{
	InMemoryDB inmem;
	
	std::cout << inmem.get("A") << "\n";
	
	try
	{
		inmem.put("A", 5);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	inmem.begin_transaction();

	inmem.put("A", 5);

	std::cout << inmem.get("A") << "\n";

	inmem.put("A", 6);

	inmem.commit();

	std::cout << inmem.get("A") << "\n";

	try
	{
		inmem.commit();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		inmem.rollback();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << inmem.get("B") << "\n";

	inmem.begin_transaction();

	inmem.put("B", 10);

	inmem.rollback();

	std::cout << inmem.get("B") << "\n";

	return 0;
}
```
___

# Recommendations for future assignment

As C++ is the primary language taught at UF, this would be a great assignment that could be paired with teaching GTest. The instructions aren't super clear about "running the code" as an example is given for the expected behavior but there is no mention if this should be included in the assignment or not.
If students are expected to include this it should specify that as there isn't anything to run otherwise. As far as the GTest part of the assignment, it would be a good way to introduce students to Google Test. Through my testing, it only took about an additional 15 minutes to implement simple GTest for the expected behavior.
Including this extra step, I completed the assignment in less than an hour. 
