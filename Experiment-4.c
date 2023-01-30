#include <stdio.h>
#include <ctype.h>
#include <math.h>
int main() {
    char s[13] = {'(','8','7','3','-','/','2','1','5','+','*','+',')'};
    int stack[13];
    int top = 0;
    for (int i=1; i<13; i++){
        char a = s[i];
        if (isdigit(a)==0){
            int x = stack[top-2];
            int y = stack[top-1];
            top--;
            switch (a){
                case '^':
                    stack[top-1] = pow(x,y);
                    break;
                case '*':
                    stack[top-1] = x*y;
                    break;
                case '/':
                    stack[top-1] = x/y;
                    break;
                case '+':
                    stack[top-1] = x+y;
                    break;
                case '-':
                    stack[top-1] = x-y;
                    break;
                case ')':
                    printf("Final value after Postfix Evaluation : %d", stack[0]);
                    break;
            }
        }
        else {
            stack[top] = a-'0';
            top++;
        }
    }
    return 0;
}
