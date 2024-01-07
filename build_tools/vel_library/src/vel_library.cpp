#include "../include/vel_library/vel_library.hpp"

void display_vel(float linear, float angular) {
     
    float l_vel = linear;
    float a_vel = angular;
    std::cout << "Linear Velocity: " << l_vel << "Angular Velocity : " << a_vel << std::endl;
     
}