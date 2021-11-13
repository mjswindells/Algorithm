#include "dnode.h"

template <class Item>
class stack
{
public:
    // TYPEDEFS 
    typedef size_t size_type;
    typedef Item value_type;

    // CONSTRUCTORS and DESTRUCTOR
    //Postcondition: The stack has been initialized as an empty stack.
    stack() { top_ptr = NULL; }

    // Postcondition: The stack that is being constructed has been initialized
    // with the same items as source
    stack(const stack<Item>& source);

    //Postcondition: delete the contents of all stack
    ~stack() { list_clear(top_ptr); }

    // MODIFICATION MEMBER FUNCTIONS
    //Postcondition: A new copy of entry has been pushed onto the stack.
    void push(const Item& entry);

    // Postcondition: The top item of the stack has been removed.
    void pop();

    // Postcondition: The stack that activated this function has the same items
    // as source.
    void operator =(const stack<Item>& source);

    // CONSTANT MEMBER FUNCTIONS
    size_type size() const{
        return list_length(top_ptr);
    }
    //Postcondition: The return value is true if the stack is empty, and false otherwise.
    bool empty() const { return (top_ptr == NULL); }
    //Postcondition: The return value is the top item of the stack, but the stack is unchanged.
    Item top() const;
private:
    dnode<Item>* top_ptr;  // Points to top of stack
    dnode<Item>* tail_ptr;
};

