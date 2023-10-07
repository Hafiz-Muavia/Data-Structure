#include <iostream>

extern "C" void delay(unsigned int milliseconds);

int main() {
    std::cout << "Program started." << std::endl;

    // Call the assembly delay function
    delay(2000); // Delay for 2 seconds

    std::cout << "Two seconds have passed." << std::endl;

    return 0;
}
