#include "bag.h"

bag::bag() {
	head_ptr = NULL;
	tail_ptr = NULL;
	many_nodes = 0;
}

bag::bag(const bag& source) {
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}

bag::~bag() {
	list_clear(head_ptr);
	many_nodes = 0;
}

bool bag::erase_one(const value_type& target) {
	dnode* target_ptr;
	target_ptr = list_search(head_ptr, target);
	if (target_ptr == NULL) return false;
	else {
		if (target_ptr == head_ptr) {
			list_head_remove(head_ptr);
			many_nodes--;
			return true;
		}
		else if (target_ptr == tail_ptr) {
			list_tail_remove(tail_ptr);
			many_nodes--;
			return true;
		}
		else{
			list_remove(target_ptr);
			many_nodes--;
			return true;
		}
	}
}

void bag::insert(const value_type& entry) {
	list_head_insert(head_ptr,entry);
	many_nodes++;
	if (many_nodes == 1) tail_ptr = head_ptr;
}

void bag::operator +=(const bag& addend) {
	dnode* copy_head_ptr;
	dnode* copy_tail_ptr;
	if (addend.many_nodes > 0) {
		list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
		many_nodes += addend.many_nodes;
		if (head_ptr == NULL) {
			head_ptr = copy_head_ptr;
			tail_ptr = copy_tail_ptr;
		}
		else {
			tail_ptr->set_fore(copy_head_ptr);
			copy_head_ptr->set_back(tail_ptr);
			tail_ptr = copy_tail_ptr;
		}
	}
}

void bag::operator =(const bag& source) {
	if (this == &source) return;
	list_clear(head_ptr);
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}

bag operator +(const bag& b1, const bag& b2) {
	bag A;
	A += b1;
	A += b2;
	return A;
}

bool bag::operator ==(const bag& source) {

	if (many_nodes == source.many_nodes) {
		bag copy_bag = source;
		dnode* cursor = head_ptr;
		while (cursor!=NULL) {
			if (copy_bag.erase_one(cursor->data()) == true) {
				cursor=cursor->fore();
			}
			else return false;
		}
		return true;
	}
	return false;
}

bool bag::operator !=(const bag& source) {

	if (many_nodes == source.many_nodes) {
		bag copy_bag = source;
		dnode* cursor = head_ptr;
		while (cursor != NULL) {
			if (copy_bag.erase_one(cursor->data()) == true) {
				cursor=cursor->fore();
			}
			else return true;
		}
		return false;
	}

	return true;
}

size_t bag::size() const {
	return many_nodes;
}

bag::size_type bag::count(const value_type& target) const {
	size_t count = 0;
	const dnode* cursor;

	cursor = list_search(head_ptr, target);
	while (cursor != NULL) {
		count++;
		cursor = cursor->fore();
		cursor = list_search(cursor, target);
	}
	return count;
}

bag::value_type bag::grab() const {
	size_type i;
	const dnode* cursor; 
	assert(size() > 0);
	i = (rand() % size()) + 1;
	cursor = list_locate(head_ptr, i);
	return cursor->data();
}

void bag::show_contents() const{
	dnode* cursor = head_ptr;
	for (cursor; cursor != NULL; cursor = cursor->fore()) {
		cout << cursor->data() << "  ";
	}
	cout << endl;
}

void bag::sort() {
	dnode* cursor = head_ptr;
	dnode* compare = NULL;
	value_type temp;
	if (head_ptr == NULL) return;

	while (cursor->fore() != NULL) {
		compare = cursor->fore();
		while (compare != NULL) {
			if (cursor->data() > compare->data()) {
				temp = cursor->data();
				cursor->set_data(compare->data());
				compare->set_data(temp);
			}
			compare = compare->fore();
		}
		cursor = cursor->fore();
	}
}
