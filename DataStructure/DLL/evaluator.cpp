#include "evaluator.h"

string evaluator::read_expression() {
	cout << "Enter your infix expression: ";
	getline(cin, expression);
	return expression;
}

int evaluator:: precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/' )
		return 2;
	return 0;
}

void evaluator::evaluate_stack_tops(stack<double>& numbers, char operation) {
	double operand1, operand2;
	operand2 = numbers.top();
	numbers.pop();
	operand1 = numbers.top();
	numbers.pop();
	switch (operation)
	{
	case '+': numbers.push(operand1 + operand2);
		break;
	case '-': numbers.push(operand1 - operand2);
		break;
	case '*': numbers.push(operand1 * operand2);
		break;
	case '/': numbers.push(operand1 / operand2);
		break;
	}
}

string evaluator::convert_to_postfix(string s) {
	string postFix;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') operations.push(s[i]);
		else if (isalpha(s[i]) ||isdigit(s[i]) || s[i] == '.') {
			string number;
			if (s[i] == '.') number += '0';
			while (i < s.length() && (isalpha(s[i]) || isdigit(s[i]) || s[i] == '.')) {
				number += s[i];
				i++;
			}
			postFix += number + ' ';	i--;
		}
		else if (strchr("+-*/", s[i]) != NULL) {// 2번 해주는 이유는 1+2-3*4/5+4-8 이러한 경우
												//*나/가 나올 경우 처리 위해
			if (!operations.empty() && (precedence(s[i]) <= precedence(operations.top()))) {
				postFix += operations.top();
				postFix += ' ';
				operations.pop();
			}
			if (!operations.empty() && (precedence(s[i]) <= precedence(operations.top()))) {
				postFix += operations.top();
				postFix += ' ';
				operations.pop();
			}
			operations.push(s[i]);
		}
		else if (s[i] == ')') {
			while (operations.top() != '(') {
				postFix += operations.top();
				postFix += ' ';
				operations.pop();
			}
			if (operations.top() == '(') operations.pop();
		}
		else continue;
	}
	while (!operations.empty()) {
		postFix += operations.top();
		postFix += ' ';
		operations.pop();
	}
	return postFix;
}


double evaluator::evaluate_postfix(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i]) || s[i] == '.') {
			string number;
			while ((i < s.length() && isdigit(s[i])) || s[i] == '.') {
				number += s[i];
				i++;
			}
			numbers.push(stod(number));	i--;
		}
		else if (isalpha(s[i])) {
			cout <<"enter the " << s[i] << ": ";
			double in;
			cin >> in;
			cin.ignore();//버퍼를 비워줌
			numbers.push(in);
		}
		else if (strchr("+-*/", s[i]) != NULL) {
			evaluate_stack_tops(numbers, s[i]);
		}
	}
	double answer = numbers.top();
	numbers.pop();
	return answer;
}
