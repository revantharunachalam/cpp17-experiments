#include <iostream>
#include <string>
#include <vector>

void Print(int arg)
{
    std::cout << "Value: " << arg << std::endl;
}

void forEach(const std::vector<int16_t>& values, void(*function)(int))
{
    for (int value : values){
        function(value);
    }
}

int main()
{
    // Since using a function pointer like this is not good approch, We can use auto or type defs
    typedef void(*funcPtrStr)(int);

    // void (*function)(std::string arg) = HelloWorld;

    funcPtrStr function = Print;

    // auto function = HelloWorld;
    function(1);
    function(2);
    function(3);

    std::vector<int16_t> array = {3, 5, 6, 1, 23, 22};
    forEach(array, [](int value){ std::cout << "Lanbda Value: " << value << std::endl;});

    return 0;
}