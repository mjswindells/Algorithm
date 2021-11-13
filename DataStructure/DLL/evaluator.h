#include "stack.h"

class evaluator {
public:
	 
	//Postcondition: reads in the expression from the standard input and returns the 
	//string representing the user - provided expression.
	string read_expression();

	//Postcondition: Return the priority of all operators to int.
	int precedence(char op);

	//Postcondition: Calculate according to each operation by calculating 
	// two items in the numbers and pushing it on the top of the numbers.
	void evaluate_stack_tops(stack<double>& numbers, char operation);

	//Postcondition:  function that converts s (an infix arithmetic expression) into a postfix 
	// notationand returns the result string.
	string convert_to_postfix(string s);

	//Precondition: string s is a well-formed postfix arithmetic expression
	//Postcondition: the evaluation result for s has been returned
	double evaluate_postfix(string s);

private:
	stack<double> numbers;
	stack<char> operations;
	string expression;
};
