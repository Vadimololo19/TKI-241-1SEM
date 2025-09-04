#include "car.h"
#include <memory>

int main()
{
    std::shared_ptr<Car> carPtr (new Car("Toyota", 2025));
    std::cout << *carPtr;

    std::shared_ptr<Car> carPtr2;
    carPtr2 = carPtr;
    std::cout << *carPtr2;
    std::cout << *carPtr;
    
    return 0;
}
