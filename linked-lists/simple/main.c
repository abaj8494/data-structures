#include "linked_list.h"

int main(void)
{
    Node list1 = create_list(7);
    print_list(list1);
    print_list(rec_reverseList(list1));
    print_list(reverseList(list1));

    return 0;
}

