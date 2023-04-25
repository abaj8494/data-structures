#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// defines the type of data going into the struct
// does not initialise.
struct node {
	struct node *next;
	int			 data;
};


// takes in a 2D array of strings and returns a linked list.
struct node *strings_to_list(int len, char *strings[]);

// takes in head of list and prints list. returns nothing.
void print_list(struct node *head);

// takes in head of list and returns sum.
int sum_list(struct node *head);

// takes in head of list with item to find - returns pointer to item.
struct node *find_item(struct node *head, int item);

// takes in head of list and returns data of last element.
int find_last(struct node *head);

// takes in head of list and returns data of nth element.
int find_nth(struct node *head, int nth);

// takes in head of list and item to add. adds item to end of list 
// and returns pointer to head
struct node *add_last(struct node *head, int item);

// takes in head of list and removes first element.
// returns pointer to head of list.
struct node *remove_first(struct node *head);

// takes in head of list and removes last element.
// returns pointer to head of list.
struct node *remove_last(struct node *head);

// takes in head of list with item to remove. 
// removes the item and returns a pointer to head.
struct node *remove_item(struct node *head, int item);

// takes in head of list and iterates through list freeing all nodes 
// and then frees the list itself.
void free_list(struct node *head);

///////////////////////////////////////////////////////////////////////////////

// main written below due to the presence of above prototype functions.

int main(void) 
{
	
	// creating a couple of arrays of strings.
	char *list1[] = {"2", "4", "8", "16"};
	char *list2[] = {"1", "2", "3", "4"};
	// sending arrays to be converted into linked lists.
	struct node *head1 = strings_to_list(4, list1);
	struct node *head2 = strings_to_list(4, list2);
	// printing out the linked lists
	print_list(head2);
	print_list(head1);
	// printing out sum of linked lists
	printf("LL1 Sum: %d\n", sum_list(head1));
	printf("LL2 Sum: %d\n", sum_list(head2));
	// printing out item with value 4
	printf("LL1 Address of item with value 4: %p\n", find_item(head1, 4));
	printf("LL1 Dereferencing pointer to check %d\n", (*find_item(head1, 4)).data);
	printf("LL2 Address of item with value 4: %p\n", find_item(head2, 4));
	printf("LL2 Dereferencing pointer to check %d\n", (*find_item(head2, 4)).data);
	// printing out last item
	printf("LL1 Last item: %d\n", find_last(head1)); 
	printf("LL2 Last item: %d\n", find_last(head2)); 
	// printing out 2nd item
	printf("LL1 Nth item, where N is 2: %d\n", find_nth(head1, 2)); 
	printf("LL2 Nth item, where N is 2: %d\n", find_nth(head2, 2)); 
	// adding 7 to end of list
	printf("Adding item with value 7 to end of linked list 1: ");
	print_list(add_last(head1, 7));
	printf("Adding item with value 7 to end of linked list 2: ");
	print_list(add_last(head2, 7));
	
	/* can't get this one to work for some reason...
	// removing first item
	printf("Removing first item from linked list 1: ");
	print_list(remove_first(head1));
	printf("Removing first item from linked list 2: ");
	print_list(remove_first(head2));
	*/
	
	//removing item based on value
	printf("Removing item with value 4 from linked list 1: ");
	print_list(remove_item(head1, 4));
	printf("Removing item with value 4 from linked list 1: ");
	print_list(remove_item(head2, 4));

	//removing last item
	printf("Removing last item from linked list 1: ");
    print_list(remove_last(head1));	
	printf("Removing last item from linked list 2: ");
    print_list(remove_last(head2));	
	// freeing list
	free_list(head1);
	free_list(head2);
	
	return 0;
}


// creates a linked list from array of strings.
// inserts from last array index to first.
struct node *strings_to_list(int len, char *strings[])
{
	struct node *head = NULL;
	int i = len - 1; // i for index
	// run loop when there are elements in the passed array
	while (i >= 0) {
		// creating a section in memory for node n
		struct node *n = malloc(sizeof(struct node));
		assert(n != NULL); //checking we haven't run out of memory
		n->next = head; // pointing next member of n struct to head
		n->data = atoi(strings[i]); // filling data member of n
		head = n; 
		i--;
	}
	return head;
}


// print linked list in python style
void print_list(struct node *head)
{
	assert(head != NULL);
	struct node *current = head;
	printf("[");
	while (current->next != NULL) {
		printf("%d, ", current->data);
		current = current->next;
	}
	printf("%d]\n", current->data);
}


// calculate sum of a list
int sum_list(struct node *head)
{
	struct node *current = head;
	int sum = 0;
	while (current != NULL) {
		sum += current->data;
		current = current->next;
	}
	return sum;
}


// find item in list. returns pointer to item.
struct node *find_item(struct node *head, int item)
{
	struct node *current = head;
	while (current != NULL) {
		if (current->data == item) return current;
		current = current->next;
	}
	return NULL;
}


// returns value of last item in list.
int find_last(struct node *head)
{
	if (head == NULL) return -69;
	struct node *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	return current->data;
}


// returns value of nth item in list.
int find_nth(struct node *head, int nth)
{
	if (head == NULL) return -69;
	struct node *current = head;
	
	while (current != NULL && nth > 0) {
		current = current->next;
		nth--;
	}
	return current->data;
}


// add item to end of list. returns pointer to head of list.
struct node *add_last(struct node *head, int item)
{
	struct node *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	struct node *new_item = malloc(sizeof(struct node));
	new_item->data = item;
	new_item->next = NULL;
	current->next = new_item;
	return head;
}


// remove first item from list. returns pointer to head of list.
struct node *remove_first(struct node *head)
{
	if (head == NULL) return NULL;
	if (head->next == NULL) {
		free(head);
		return NULL;
	}
	struct node *tmp = head;
	head = head->next;
	free(tmp);
	return head;	
}


// remove last item from list. returns pointer to head of list.
struct node *remove_last(struct node *head)
{
	if (head == NULL) return NULL;
	if (head->next == NULL) {
		free(head);
		return NULL;
	}
	struct node *stop = head;
	while (stop->next != NULL) {
		stop = stop->next;
	}
	struct node *current = head;
	while (current->next != stop) {
		current = current->next;
	}
	current->next = NULL;
	free(stop);
	return head;
}


// remove given item from list. returns pointer to head of list.
struct node *remove_item(struct node *head, int item)
{
	if (head->next == NULL || head == NULL) return NULL;
	struct node *stop = head;
	while (stop->next->data != item) {
		stop = stop->next;
	}
	struct node *kill = stop->next;
	stop->next = stop->next->next;
	free(kill);
	return head;
}


// free linked list
void free_list(struct node *head) 
{
	struct node *current = head;
	while (current != NULL) {
		struct node *item = current;
		current = current->next;
		free(item);
	}
}
