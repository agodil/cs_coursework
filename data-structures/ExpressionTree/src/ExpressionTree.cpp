#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct tree {
	int item;
	tree *left;
	tree *right;
};
//each element of the stack is a tree.
struct stacktree {
	struct tree *item;
	stacktree *previous;
};

void push(stacktree *&top, tree *value);
tree* pop(stacktree *&top);
bool isOperator(char item);
double eval(double left, double right, char op);
tree* expressionTree(string postfix);
double evaluateExpression(struct tree *item);
string infix(tree *expression);

tree* newTree(char value) {
	tree *node = new tree;
	node->item = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int main() {
	cout
			<< "Enter postfix expression (numbers 0-9, operators +-*/^, no whitespace)"
			<< endl;
	//expression string
	string s;
	cin >> s;
	tree *expression = expressionTree(s);
	cout << infix(expression) << endl << evaluateExpression(expression) << endl;
}

void push(stacktree *&top, tree *value) {
	stacktree *nn = new stacktree;
	nn->item = value;
	nn->previous = top;
	top = nn;
}

tree* pop(stacktree *&top) {
	stacktree *temp;
	tree *value = NULL;
	if (top) {
		value = top->item;
		temp = top;
		top = top->previous;
		delete temp;
	}
	return value;
}

bool isOperator(char item) {
	string s = "+-*/^";
	return s.find(item) != -1;
}

double eval(double left, double right, char op) {
	double result = -99999999;
	switch (op) {
	case '*':
		result = left * right;
		break;
	case '/':
		result = left / right;
		break;
	case '+':
		result = left + right;
		break;
	case '-':
		result = left - right;
		break;
	case '^':
		result = pow(left, right);
		break;
	}
	return result;
}

tree* expressionTree(string postfix) {
	//stack
	stacktree *top = NULL;
	for (unsigned int i = 0; i < postfix.length(); i++) {
		if (isdigit(postfix[i])) {
			push(top, newTree(postfix[i] - '0'));
		} else if (postfix[i] != '=') {
			tree *tree = newTree(postfix[i]);
			tree->right = pop(top);
			tree->left = pop(top);
			push(top, tree);
		}
	}
	return pop(top);
}

double evaluateExpression(struct tree *item) {
	if (item == NULL)
		return 0;
	double left = evaluateExpression(item->left);
	double right = evaluateExpression(item->right);
	if (isOperator(item->item))
		return (eval(left, right, item->item)); //evaluate expression
	else
		return item->item; //convert to a number
}

string infix(tree *expression) {
	string str = "";
	if (expression) {
		if (isOperator(expression->item)) {
			str += '(' + infix(expression->left) + (char) expression->item
					+ infix(expression->right) + ')';
		} else {
			str += infix(expression->left) + to_string(expression->item)
					+ infix(expression->right);
		}
	}
	return str;
}
