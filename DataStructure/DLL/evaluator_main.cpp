#include "evaluator.h"

int main() {
	evaluator answer;
	string infix, postfix;
	while (true) {
		cout << "If you enter \"stop\", end the program." << endl;
		infix = answer.read_expression();
		if (infix == "stop") {
			cout << "==========End the program==========" << endl;
			break;
		}
		postfix = answer.convert_to_postfix(infix);
		cout << endl << "your infix expression:\t\t" << infix << endl;
		cout << "convert to your postfix:\t"<< postfix << endl;
		cout << "evaluate your expression:\t" << answer.evaluate_postfix(postfix) << endl << endl;
	}
}

//A+B-C*(D/E)
//(1.03 * x + .4) / y
//9-3/(1/3)+1
//6/2*(1+2)
