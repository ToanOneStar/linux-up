#include <stdio.h>
#include <stdint.h>
struct MyStruct
{
    int id;
    float value;
};
int main()
{

    struct MyStruct obj;
    // Declare a structure variable
    struct MyStruct *ptr = &obj; // Pointer to the structure
    ptr->id = 10;                // Equivalent to (*ptr).id = 10;
    ptr->value = 20.5;           // Equivalent to (*ptr).value = 20.5;
    printf("ID: %d, Value: %.2f\n", ptr->id, ptr->value);
}