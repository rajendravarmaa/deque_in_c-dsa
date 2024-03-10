#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the deque
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Define a structure for the deque
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Function to initialize a deque
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(Deque* deque) {
    return (deque->front == NULL);
}

// Function to add an element to the front of the deque (enqueue in queue)
void addToFront(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;
    if (isEmpty(deque)) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
}

// Function to add an element to the rear of the deque (enqueue in stack)
void addToRear(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;
    if (isEmpty(deque)) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
}

// Function to remove an element from the front of the deque (dequeue in queue)
int removeFromFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    Node* temp = deque->front;
    int data = temp->data;
    deque->front = temp->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
    return data;
}

// Function to remove an element from the rear of the deque (pop in stack)
int removeFromRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    Node* temp = deque->rear;
    int data = temp->data;
    deque->rear = temp->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
    return data;
}

// Function to display the contents of the deque
void displayDeque(Deque* deque) {
    Node* current = deque->front;
    printf("Deque: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Deque* deque = createDeque();
    int choice, data;

    do {
        printf("\n1. Add to Front (enqueue in queue)\n");
        printf("2. Add to Rear (enqueue in stack)\n");
        printf("3. Remove from Front (dequeue in queue)\n");
        printf("4. Remove from Rear (pop in stack)\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add to front: ");
                scanf("%d", &data);
                addToFront(deque, data);
                break;
            case 2:
                printf("Enter data to add to rear: ");
                scanf("%d", &data);
                addToRear(deque, data);
                break;
            case 3:
                printf("Removed from front: %d\n", removeFromFront(deque));
                break;
            case 4:
                printf("Removed from rear: %d\n", removeFromRear(deque));
                break;
            case 5:
                displayDeque(deque);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}

