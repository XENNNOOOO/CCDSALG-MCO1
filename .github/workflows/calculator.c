#include "algorithms/shunting_yard_algo.c"

int main() {
    char tempString[50] = {"1+2*3/4-5"};
    infixToPostfix(tempString);
}