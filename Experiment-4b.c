#include <stdio.h>
int main() {
    char s[10] = {'(','a','/','b','^','c','+','d',')'};
    char e[10];
    char stack[10];
    int tops = -1;
    int tope = -1;
    for (int i=0; i<9; i++){
        char a = s[i];
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
            tope++;
            e[tope] = a;
        }
        else {
            switch (a){
                case '(':
                    tops++;
                    stack[tops] = a;
                    break;
                case '+':
                case '-':
                    while (1){
                        if (stack[tops]=='+' || stack[tops]=='-' || stack[tops]=='*' || stack[tops]=='/' || stack[tops]=='^'){
                            tope++;
                            e[tope] = stack[tops];
                            tops--;
                        }
                        else {
                            break;
                        }
                    }
                    tops++;
                    stack[tops] = a;
                    break;
                case '*':
                case '/':
                    while (1){
                        if (stack[tops]=='*' || stack[tops]=='/' || stack[tops]=='^'){
                            tope++;
                            e[tope] = stack[tops];
                            tops--;
                        }
                        else {
                            break;
                        }
                    }
                    tops++;
                    stack[tops] = a;
                    break;
                case '^':
                    while (1){
                        if (stack[tops]=='^'){
                            tope++;
                            e[tope] = stack[tops];
                            tops--;
                        }
                        else {
                            break;
                        }
                    }
                    tops++;
                    stack[tops] = a;
                    break;
                case ')':
                    while (1){
                        if (stack[tops]=='('){
                            break;
                        }
                        tope++;
                        e[tope] = stack[tops];
                        tops--;
                    }
                    break;
            }
        }
    }
    for (int i=0; i<tope+1; i++){
        printf("%c",e[i]);
    }
    return 0;
}
