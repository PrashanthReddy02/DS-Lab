/*C Program to implement a circular queue using arrays*/
#include <stdio.h>
#include <stdlib.h>
#define N 4
int queue[N];
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
void display();
void main()
{
    while (1)
    {
        int choice;
        printf("enter the choice 1.enqueue 2. dequeue 3.display 4. exit\n");
        scanf("%d", &choice); // reads the option from the user
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
}
void enqueue()//function for inserting an element in circular queue
{
    int x;
    if ((rear + 1) % N == front)
    {
        printf("overflow\n");
    }
    else
    {
        printf("enter the value to be inserted :\n");
        scanf("%d", &x);
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = x;
        }
        else
        {
            rear = (rear + 1) % N;
            queue[rear] = x;
        }
    }
}
void dequeue()//function for deleting an element from the circiular queue
{
    if (front == -1 && rear == -1)
    {
        printf("underflow\n");
    }
    else if (front == rear)
    {
        printf("the dequeued element is %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("the dequeued element is %d\n", queue[front]);
        front = (front + 1) % N;
    }
}
void display()//function for displaying the elements present in circular queue
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("underflow\n");
    }
    else
    {
        while (i != rear)
        {
            printf("%d|", queue[i]);
             i = (i + 1) % N;
        }
    }
}
