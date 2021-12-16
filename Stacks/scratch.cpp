#include <iostream>
using namespace std;

struct node

{

    char data;

    struct node *next;

} *top = NULL;

void push(char x)

{

    struct node *t = (struct node *)malloc(sizeof(struct node));

    if (t != NULL)

    {

        t->data = x;

        t->next = top;

        top = t;
    }
}

char pop()

{
    char x;

    struct node *p;

    if (top)

    {

        p = top;

        x = top->data;

        top = top->next;

        free(p);
    }

    return x;
}

int len(char *infix)

{
    int i = 0;

    for (; infix[i] != '\0'; i++)

    {
    }

    return i;
}

int isOperand(char a)

{

    if (a == '+' || a == '-' || a == '*' || a == '/')

        return 0;

    else

        return 1;
}

int prece(char a)

{

    if (a == '+' || a == '-')

    {

        return 1;
    }

    else if (a == '*' || a == '/')

    {

        return 2;
    }

    return 0;
}

char *operation(char *infix)

{

    char *postfix;

    postfix = (char *)malloc((len(infix) + 1) * sizeof(char));

    int i = 0, j = 0;

    while (infix[i] != '\0')

    {

        if (isOperand(infix[i]))

        {

            postfix[j++] = infix[i++];
        }

        else

        {

            if (top == NULL || prece(infix[i]) > prece(top->data)) // changes

                push(infix[i++]);

            else

            {

                postfix[j++] = pop();
            }
        }
    }

    while (top != NULL)

    {

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    return postfix;
}

int main()

{

    char infix[] = "a+b-c*e/f";

    cout << operation(infix);

    return 0;
}