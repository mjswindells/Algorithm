#include "stack.h"

template <class Item>
stack<Item>::stack(const stack<Item>& source)
{
    list_copy(source.top_ptr, top_ptr, tail_ptr);
}

template <class Item>
void stack<Item>::push(const Item& entry)
{
    list_head_insert(top_ptr, entry);
}

template <class Item>
void stack<Item>::pop()
{
    assert(!empty());
    list_head_remove(top_ptr);
}

template <class Item>
void stack<Item>::operator =(const stack<Item>& source)
{
    if (this == &source)
        return;

    list_clear(top_ptr);
    list_copy(source.top_ptr, top_ptr, tail_ptr);
}

template <class Item>
Item stack<Item>::top() const
{
    assert(!empty());
    return top_ptr->data();
}

template class stack<char>;
template class stack<double>;
