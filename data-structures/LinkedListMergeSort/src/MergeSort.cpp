#include <iostream>
#include <fstream>
using namespace std;

struct node {
	int data;
	node* next;
};

void add(node*& head, int data);
void Traverse(node* head);
void split (node* head, node*&a, node*&b);
node* merge(node* a, node* b);
node* mergeSort(node* head);

int main() {
	int l = 7;
	int a[] = {8, 4, 1, 34, 21, 3, 10};
	node* list = NULL;
	//populate LinkedList
	for(int i = 0; i < l; i++) {
		add(list, a[i]);
	}

	Traverse(list);
	cout << endl;
	//traverse sorted list
	Traverse(mergeSort(list));
}

void add(node*& head, int data) {
	node *nn = new node;
	nn->data = data;
	nn->next = NULL;
	if(!head) {
		head = nn;
	} else {
		node *curr = head;
		while(curr->next) {
			curr = curr->next;
		}
		curr->next = nn;
	}
}

void Traverse(node* head) {
	while(head) {
		cout << head->data << " ";
		head = head->next;
	}
}

node* merge(node* a, node* b) {
	node *curr = new node;
	node *temp = curr;

	//connect smallest nodes
	while(a && b) {
		if(a->data < b->data) {
			curr->next = a;
			a = a->next;
		} else {
			curr->next = b;
			b = b->next;
		}
		curr = curr->next;
	}
	while(a) {
		curr->next = a;
		a = a->next;
		curr = curr->next;
	}
	while(b) {
		curr->next = b;
		b = b->next;
		curr = curr->next;
	}
	curr = NULL;

	node *c = temp->next;
	delete temp;

	return c;
}

node* mergeSort(node* head) {
	//base cases
	if(!head) return NULL;
	if(!head->next) return head;

	//partition LinkedList
	node *a, *b = NULL;
	split(head, a, b);

	//Merge Sort lists
	a = mergeSort(a);
	b = mergeSort(b);
	//merge lists
	node *c = merge(a, b);
	return c;
}

void split(node* head, node*&a, node*&b) {
	a = head;
	b = head;
	int count = 0;
	//count nodes
	while(head) {
		count++;
		head = head->next;
	}
	//find middle node, beginning of list b
	for(int i = 0; i < count / 2; i++) {
		b = b->next;
	}
	//find node preceding middle node, end of list a, set next pointer to null
	head = a;
	for(int i = 0; i < count / 2 - 1; i++) {
		head = head->next;
	}
	head->next = NULL;
}
