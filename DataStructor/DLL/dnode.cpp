#include "dnode.h"

size_t list_length(const dnode* head_ptr) {
	size_t count = 0;
	const dnode* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor=cursor->fore())
		count++;
	return count;
}

void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry) {
	head_ptr = new dnode(entry, head_ptr, NULL);
	head_ptr->fore()->set_back(head_ptr);
}

void list_insert(dnode* target_ptr, const dnode::value_type& entry) {
	dnode* insert_ptr = new dnode(entry, target_ptr->fore(), target_ptr);
	target_ptr->fore()->set_back(insert_ptr);
	target_ptr->set_fore(insert_ptr);
}

void list_tail_insert(dnode*& tail_ptr, const dnode::value_type& entry) {
	tail_ptr = new dnode(entry, NULL, tail_ptr);
	tail_ptr->back()->set_fore(tail_ptr);
}

dnode* list_search(dnode* head_ptr, const dnode::value_type& target) {
	dnode* cursor = head_ptr;
	for (cursor; cursor != NULL; cursor=cursor->fore()) {
		if (cursor->data() == target) {
			return cursor;
		}
	}
	return NULL;
}

const dnode* list_search(const dnode* head_ptr, const dnode::value_type& target) {
	const dnode* cursor = head_ptr;
	for (cursor; cursor != NULL; cursor=cursor->fore()) {
		if (cursor->data() == target) {
			return cursor;
		}
	}
	return NULL;
}

dnode* list_locate(dnode* head_ptr, size_t position) {
	size_t i=1;
	dnode* cursor=head_ptr;

	assert(position > 0);
	while ((cursor != NULL) && (i++ < position))
		cursor = cursor->fore();
	return cursor;
}

const dnode* list_locate(const dnode* head_ptr, size_t position) {
	size_t i = 1;
	const dnode* cursor = head_ptr;

	assert(position > 0);
	while ((cursor != NULL) && (i++ < position))
		cursor=cursor->fore();
	return cursor;
}
void list_head_remove(dnode*& head_ptr) {
	dnode* remove_ptr = head_ptr;
	head_ptr = head_ptr->fore();
	head_ptr->set_back(NULL);
	delete remove_ptr;
}

void list_remove(dnode* target_ptr) {
	dnode* remove_ptr = target_ptr;
	target_ptr->back()->set_fore(target_ptr->fore());
	target_ptr->fore()->set_back(target_ptr->back());
	delete remove_ptr;
}

void list_tail_remove(dnode*& tail_ptr) {
	dnode* remove_ptr = tail_ptr;
	tail_ptr = tail_ptr->back();
	tail_ptr->set_fore(NULL);
	delete remove_ptr;
}

void list_clear(dnode*& head_ptr) {
	while (head_ptr != NULL) {
		list_head_remove(head_ptr);
	}
}

void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr) {
	head_ptr = NULL;
	tail_ptr = NULL;

	if (source_ptr == NULL) return;

	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;

	source_ptr = source_ptr->fore();
	while (source_ptr != NULL) {
		list_tail_insert(tail_ptr, source_ptr->data());
		source_ptr = source_ptr->fore();
	}
}
