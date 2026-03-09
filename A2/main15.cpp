/**
 * @file main15.cpp
 * @brief Progamming Assignment 2.19.15
 * @author Hayden Holmes
 * @date February 2025
 * @version 1.0
 * 
 * Use formula F = G * M(1) * M(2) / r^2
 * Use user input for M(1), M(2), and r
 * 
*/

#include <string> // for string datatype
#include "logger/Log.h" // More robust logging
#include "input/InputWrapper.h" // Easy to use inputwrapper that handles edge cases

const double gravity = 6.67e-11; // Define gravitational constant

int main() {

    // Init logger
    //Log::LOG_FILTER = -1; // Comment this out to get rid of debug lines
    Log::defaultLogger(); // Use cout

    double mass1 = InputWrapper::getDouble("Enter the mass of object 1 (kg):");
    Log::debug("mass1 = " + std::to_string(mass1));
    double mass2 = InputWrapper::getInteger("Enter the mass of object 2 (kg):");
    Log::debug("mass2 = " + std::to_string(mass2));
    double distance = InputWrapper::getDouble("Enter distance between the two objects (m): ");

    double force = gravity * mass1 * mass2; // Do first part of eq
    force /= distance * distance; // Divide by r^2

    Log::info("The force is equal to " + std::to_string(force) + " Newtons");
    

    return 0;
}