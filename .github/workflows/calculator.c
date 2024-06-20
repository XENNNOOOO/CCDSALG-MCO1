#include "./algorithms/shunting_yard_algo.c"
#include "./algorithms/rpn_calculator.c"
#include "datastructures/queue.c"

int main() {
    char input[STRING_LEN] = "3 + 5 * ( 10 - 4 )";
    Queue result;
    result = infixToPostfix(input);
    printf("%d", evaluatePostfix(result));
    printf("this code runs");
    return 0;
}