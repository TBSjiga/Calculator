#include <stdio.h>
#include <stdlib.h>

int *stack;
int num = 0;

void push(int result)
{
    stack[num++] = result;
}

int pop(void)
{
	if (num > 0)
	{
                return stack[--num];
        }
        else 
	{
                printf("Stack is empty!\n");
                return 0;
        }
}

int main(int argc, char *argv[])
{
        int  i,x,y,z;
        stack =(int *) malloc ( sizeof(int) * argc );
        if ( stack == NULL )
        {
		exit (1);
	}
        for( i = 1; i < argc; i++ )
        {
                switch ( (int) argv[i][0] )
		{
                case '+':
                        push(pop() + pop());
                        break;
                case '-':
			x=pop();
			y=pop();
			z=y-x;
                        push(z);
                break;
                case 'x':
                        push(pop() * pop());
                break;
		case '/':
			x=pop();
			y=pop();
			z=y/x;
                push(z);
                break;
		case '=':
                        printf("Result: %d", pop());
                break;
                default:
                        push( atoi(argv[i]));
                        break;
                }
        }
return 0;
}
