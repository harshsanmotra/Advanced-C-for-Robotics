#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    std::vector<int>::iterator it = myVector.end();

    // Get iterator pointing to the element 2 positions before the current iterator
    auto prevIterator = std::prev(it, 2);

    // Print the value at the previous iterator
    std::cout << "Value at the iterator 2 positions before: " << *prevIterator << std::endl;

    return 0;
}
