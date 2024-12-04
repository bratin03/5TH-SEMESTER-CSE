/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

int MAX_SIZE = 100;

int stack[MAX_SIZE];
int top = -1;

void push(int item)
{
    if (top == MAX_SIZE - 1)
    {
        return;
    }
    stack[++top] = item;
}

int pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top];
}

int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

int isFull()
{
    if (top == MAX_SIZE - 1)
        return 1;
    return 0;
}

int main()
{
    push(10);
    push(20);
    push(30);
    int empty = isEmpty();
    int full = isFull();
    int top_element = peek();
    pop();
    int top_element_after_pop = peek();
}
