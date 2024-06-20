#include "algorithms/shunting_yard_algo.h"
#include "algorithms/rpn_calculator.h"
#include "data_structures/queue.h"

int main() {
    char input[STRING_LEN] = "3 + 5 * ( 10 - 4 )";
    Queue* result = infixToPostfix(input);
    printf("%d", evaluatePostfix(*result));
    free(result);
    return 0;
}