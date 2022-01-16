#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string.h>

using namespace std;

class dnode {
public:
	//TypeDef
	typedef double value_type;

	// Constructor
	//Postcondition: The dnode contains the specified data, link_fore and link_back.
	dnode(const value_type& init_data = value_type(),
		dnode* init_fore = NULL,
		dnode* init_back = NULL)
	{data_field = init_data; link_fore = init_fore; link_back = init_back;}

	//Postcondition: The dnode now contains the specified new data
	void set_data(const value_type& new_data) { data_field = new_data; }

	//Postcondition: The dnode now contains the specified new link_fore.
	void set_fore(dnode* new_fore) { 
		if (this == NULL) return; 
		link_fore = new_fore; }
	
	//Postcondition: The dnode now contains the specified new link_back.
	void set_back(dnode* new_back) {
		if (this == NULL) return;
		link_back = new_back;
	}

	//Postcondition: The return value is the data from this dnode.
	value_type data() const {return data_field;}

	//Postcondition: The return value is the link_fore from this dnode.(const or non-const)
	const dnode* fore() const { return link_fore; }
	dnode* fore() { return link_fore; }
	
	//Postcondition: The return value is the link_back from this dnode.(const or non-const)
	const dnode* back() const { return link_back; }
	dnode* back() { return link_back; }
private:
	value_type data_field;
	dnode* link_fore;
	dnode* link_back;
};

//Precondition: head_ptr is the head pointer of a DLL.
//Postcondition: The value returned is the number of dnodes in the DLL.
size_t list_length(const dnode* head_ptr);

//Precondition: head_ptr is the head pointer of a DLL.
//Postcondition: A new dnode containing the given entry has been added at the head of
//the DLL; head_ptr now points to the head of the new, longer DLL.
//and next of head_ptr contains link_back that head_ptr
void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry);

//Precondition: target_ptr points to a dnode in a DLL.
//Postcondition: A new dnode containing the given entry has been added after the dnode
//that target_ptr points to.
void list_insert(dnode* target_ptr, const dnode::value_type& entry);

//Precondition: tail_ptr is the tail pointer of a DLL.
//Postcondition: A new dnode containing the given entry has been added at the tail of
//the DLL; tail_ptr now points to the tail of the new, longer DLL.
//and before of tail_ptr contains link_fore that tail_ptr
void list_tail_insert(dnode*& tail_ptr, const dnode::value_type& entry);

//Precondition: head_ptr is the head pointer of a DLL.
//Postcondition: The pointer returned points to the first dnode containing the specified
//target in its data field. If there is no such dnode, the null pointer is returned. 
//const or non-const
dnode* list_search(dnode* head_ptr, const dnode::value_type& target);
const dnode* list_search(const dnode* head_ptr, const dnode::value_type& target);

//Precondition: head_ptr is the head pointer of a DLL, and position > 0.
// Postcondition: The pointer returned points to the dnode at the specified position in the
//list. (The head dnode is position 1, the next dnode is position 2, and so on.) If there is no
//such position, then the null pointer is returned.
//const or non-const
dnode* list_locate(dnode* head_ptr, size_t position);
const dnode* list_locate(const dnode* head_ptr, size_t position);

//Precondition: head_ptr is the head pointer of a DLL, with at least one node.
//Postcondition: The head dnode has been removed and returned to the heap;
//head_ptr is now the head pointer of the new, shorter linked list.
void list_head_remove(dnode*& head_ptr);

//Precondition: target_ptr points to a dnode in a DLL
//Postcondition: The dnode has been removed from the DLL.
void list_remove(dnode* target_ptr);

//Precondition: tail_ptr is the tail pointer of a DLL, with at least one node.
//Postcondition: The tail dnode has been removed and returned to the heap;
//tail_ptr is now the tail pointer of the new, shorter linked list.
void list_tail_remove(dnode*& tail_ptr);

//Precondition: head_ptr is the head pointer of a DLL.
//Postcondition: All dnodes of the list have been returned to the heap, and the head_ptr is 
//now NULL.
void list_clear(dnode*& head_ptr);

//Precondition: source_ptr is the head pointer of a DLL.
//Postcondition: head_ptr and tail_ptr are the head and tail pointers for a new list that
//contains the same items as the list pointed to by source_ptr.
void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr);
