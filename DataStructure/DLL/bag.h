#include "dnode.h"

class bag {
public:
	//TypeDef
	typedef size_t size_type;
	typedef dnode::value_type value_type;

	// Constructor
	//Postcondition: The bag is empty.
	bag();
	// Postcondition: The bag that is being constructed has been initialized
	// with the same items and capacity as source.
	bag(const bag& source);

	//Destructor
	//Postcondition: delete the contents of all bag
	~bag();

	//Postcondition: If target was in the bag, then one copy of target has been removed from
	// the bag; otherwise the bag is unchanged. A true return value indicates that one copy
	// was removed; false indicates that nothing was removed.
	bool erase_one(const value_type& target);

	//Postcondition: A new copy of entry has been inserted into the bag.
	void insert(const value_type& entry);

	//Postcondition: Each item in addend has been added to the bag
	void operator +=(const bag& addend);

	// Postcondition: The bag that activated this function has the same items
	// and capacity as source.
	void operator =(const bag& source);

	//Postcondition: The return value is true if 
	// all the data this has and all the data in source are the same.
	bool operator ==(const bag& source);

	//Postcondition: The return value is true if 
	// the data of this and the data of source are different.
	bool operator !=(const bag& source);

	//Postcondition: The return value is the total number of items in the bag.
	size_t size() const;
	
	//Postcondition: The return value is the number of times target is in the bag.
	size_type count(const value_type& target) const;

	//Precondition: size( ) > 0.
	//Postcondition: The return value is a randomly selected item from the bag.
	value_type grab() const;

	//Postcondition: prints this data contents on the standard output.
	void show_contents()const;

	//Postcondition: changes the order of data items stored in the bag to ascending order.
	void sort();

private:
	dnode* head_ptr;// List head pointer
	dnode* tail_ptr;// List tail pointer
	size_type many_nodes;	// Number of nodes on the list
};

//Postcondition: The bag returned is the union of b1 and b2.
bag operator +(const bag& b1, const bag& b2);
