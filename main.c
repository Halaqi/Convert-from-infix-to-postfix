#include <stdio.h>
#include <stdlib.h>
char stk[20];
int top = -1;

void push(char x)
{
        stk[++top] = x;
}

int pop()
{
      return stk[top--];
}

int priority(char x) {
      if(x == '(')
       return 0;
      if(x == '+' || x == '-')
       return 1;
      if(x == '*' || x == '/')
       return 2;
}
int main()
{     int n=0;

while(n==0)
{

      char exp[20];
      char *e, x;
        printf("Enter the expression :: \n ");
        scanf("%s", exp);
        e = exp;
    while (*e != '\0')
      {
    if(isalnum (*e))
          printf("%c",*e);
      else if(*e == '(')
          push(*e);
      else if(*e == ')')
      {
       while((x = pop()) != '(')
       printf("%c", x);
      }
   else
      {
   while(priority(stk [20]) >= priority(*e))
    printf("%c\n", pop());
    push(*e);

      }
         e++;
     }
   while(top != -1)
     {
    printf("%c\n", pop());
     }
      printf("press '0' to enter a new expression or '1' to terminate the program::\n");
      scanf("%d",&n);
}


    return 0;
}
