#include<stdio.h>
#include<stdlib.h>

// Define a structure for the doubly linked list. //
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}dll;

// Initialise the head instance. //
dll *head = NULL;

void insert( int item ){
    /* First check if head is null. */
    if( head == NULL ){
        /* Now take a random address for head. */
        head = ( dll * )malloc( sizeof( dll ) );
        head -> prev = NULL; // First element in dll always has prev pointer = null. //
        head -> data = item;
        head -> next = NULL;
    }
    else{
        /* Initialise a pointer temp to traverse the list till end
        and insert the element at last. */
        dll *temp;
        temp = head;

        // Now start the while loop. //
        dll *previous;
        while( temp != NULL ){
            previous = temp;
            temp = temp -> next;
        }
        // Now previous contains the second last node. //
        // Now take the new element and place it in random address. //
        dll *var;
        var = ( dll * )malloc( sizeof( dll ) );
        var -> next = NULL;
        var -> data = item;
        var -> prev = previous;
        previous -> next = var;
        // Element is now inserted. //
    }
    printf("Element is inserted.\n");
} // End of insert() function. //

void insertmid( int item, int index ){
    /* If the list is empty, then whatever positive index the user provides, the
    element will be inserted at 0th position. So, simple insert() function will
    suffice. */
    if( head == NULL ){
        insert( item );
    }
    else{
        // Initialise a pos of type integer to count the position. //
        int pos = 0;
        dll *temp = head;
        dll *previous;

        while( temp != NULL ){
            if( pos == index ){
                dll *var = ( dll * )malloc( sizeof( dll ) );
                var -> data = item;
                previous -> next = var;
                var -> next = temp;
                var -> prev = previous;
                temp -> prev = var;
                break;
                // Element inserted at approprite index. //
            }
            else{
                pos += 1;
                previous = temp;
                temp = temp -> next;
            }
        }
        /* If temp becomes null, that means user enetered an index out of
        range. */
        if( temp == NULL ){
            dll *var = ( dll * )malloc( sizeof( dll ) );
            var -> data = item;
            previous -> next = var;
            var -> next = temp;
            var -> prev = previous;
        }
    }
} // End of insertmind() function. //

void del_at_pos( int index ){
    // First check the empty list condition. //
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        // Initialise a temp pointer to traverse the list. //
        dll *temp = head;
        int pos = 0;
        dll *previous;

        while( temp != NULL ){
            if( pos == index ){
                if( temp == head ){
                    head = head -> next;
                    head -> prev = NULL;
                    free( temp );
                    break;
                }
                else{
                    dll *prev_node = temp -> prev;
                    dll *next_node = temp -> next;
                    prev_node -> next = next_node;
                    next_node -> prev = prev_node;
                    free( temp );
                    break;
                }
            }
            else{
                pos += 1;
                previous = temp;
                temp = temp -> next;
            }
        }
        // Now if temp is NULL, then the item is not present. //
        if( temp == NULL ){
            printf("You are out of range, can't delete the element.\n");
        }
    }
} // end of del_at_pos() function. //

void delete( int item ){
    /* First check if the list is empty or not. */
    if( head == NULL ){
        printf("List is empty.\n");
    }
    else{
        /* Initialise a temp pointer to traverse the list. */
        dll *temp;
        temp = head;

        // initialise the while loop now. //
        while( temp != NULL ){
            if( temp -> data == item ){
                /* Here first check if the item found is at
                first node. */
                if( temp == head ){
                    /* Initialise another pointer variable temp1. */
                    dll *temp1;
                    temp1 = temp;
                    head = head -> next;
                    temp = head;
                    /* To again continue with while loop from starting and check
                    if there are other same items also to be deleted. */
                    free( temp1 );
                }
                else{
                    dll *previous = temp -> prev;
                    previous -> next = temp -> next;
                    dll *temp1;
                    temp1 = temp;
                    temp = head;
                    free( temp1 );
                }
            }
            else{
                temp = temp -> next;
            }
        }
    }
} // End of delete() function. //

void search( int item ){
    /* First check if the list is empty or not. */
    if( head == NULL ){
        printf("List is empty.\n");
    }
    else{
        /* Now initialise a pointer temp to traverse the list. */
        dll *temp;
        temp = head;

        // Also initialise an integer type pointer index to hold the index of founded element. //
        int index = -1;

        // Now start the while loop. //
        while( temp != NULL ){
            index += 1;
            if( temp -> data == item ){
                printf("Item found at index %d.\n", index);
            }
            temp = temp -> next;
        }
    }
} // End of search() function. //

void display(){
    /* This is a simple function to traverse the list
    and print each and every element in the list.
    But first check if the list is empty or not. */
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        /* Initialise pointer temp to traverse the list. */
        dll *temp = head;

        // Initialise the while loop now. //
        while( temp != NULL ){
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }
    }
} // End of display() function. //

void main(){
    /* To make a menu driven program initialise ch with 1. */
    int ch = 1;

    while( ch == 1 ){
        printf("Enter 1 to insert.\n");
        printf("Enter 2 to delete.\n");
        printf("Enter 3 to search.\n");
        printf("Enter 4 to display.\n");
        printf("Enter 5 to exit.\n");
        printf("Enter 6 to insert at position.\n");
        printf("Enter 7 to delete at position.\n");

        // Initialise a choice variable. //
        int x;
        printf("Enter your choice: ");
        scanf("%d", &x);

        if( x == 1 ){
            // Ask user for the element. //
            int elem;
            printf("Enter the element: ");
            scanf("%d", &elem);

            // Now make a simple call to the function insert(). //
            insert( elem );
        }
        else if( x == 2 ){
            // Ask user for the element. //
            int elem;
            printf("Enter the element to be deleted: ");
            scanf("%d", &elem);

            // Now make a simple call to the function delete(). //
            delete( elem );
        }
        else if( x == 3 ){
            // Ask user for the element. //
            int elem;
            printf("Enter the element to be searched: ");
            scanf("%d", &elem);

            // Now make a simple call to the function serach(). //
            search( elem );
        }
        else if( x == 4 ){
            // Here simply make a call to the function display(). //
            display();
        }
        else if( x == 5 ){
            // Change ch from 1 to 0 to halt the while loop. //
            ch = 0;
        }
        else if( x == 6 ){
            // Take element and position. //
            int elem, pos;
            printf("Enter element: ");
            scanf("%d", &elem);
            printf("Enter position: ");
            scanf("%d", &pos);
            // make a call to insertmid() function. //
            insertmid( elem, pos );
        }
        else if( x == 7 ){
            // Take position. //
            int pos;
            printf("Enter position: ");
            scanf("%d", &pos);
            // make a call to del_at_pos() function. //
            del_at_pos( pos );
        }
        else{
            printf("Invalid choice.\n");
        }
    }
} // End of main() function. //
