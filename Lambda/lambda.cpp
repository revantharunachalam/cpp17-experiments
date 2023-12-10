/*
Whenever we have a function pointer, we can use the lambda

Ref: https://en.cppreference.com/w/cpp/language/lambda
*/

#include <iostream>
#include <string>
#include <vector>
#include <functional>

// No need to pass a address for func since std::function is used.
void print_vector_elements(std::vector<int16_t> array, std::function<void(int16_t)> func)
{
    for(int16_t value : array)
    {
        func(value);
    }
}

int main()
{
    std::vector<int16_t> array = {1, 2, 13, 54, 122, 61};
    // Lambda: [captures](params){action_block};
    /*
    When a variable is stored in the local scope like the variable a, It is not possible to pass it to the lambda function as it has separate scope.
    pass in the [],
    =  pass all the variables in the outer scope by value
    & pass all the variables in the outer scope by reference
    a individual value
    &a individual reference
    */
    int8_t a = 5;

    auto lambda = [](int16_t value) -> void {
            std::cout << "Simple lambda function passing the value: " << value << std::endl;
        };

    print_vector_elements(array, lambda);
    return 0;
}