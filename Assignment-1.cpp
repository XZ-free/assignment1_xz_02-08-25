// Assignment 1 - skeleton code

// Program to calculate transition energy using simple Bohr formula

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>


// take input and check if it is in integer. if not so ask user to redo the input.
int input_integer(int type) {
    std::vector<std::string> array = {
        "atomic number Z",
        "principle quantum number n_i",
        "principle quantum number n_j"
    };

    int int_input;
    
    while (true) {
        std::cout<<"Please enter the "<<array[type] << ": ";
        std::cin>>int_input;

        // check failed input, clear fail state and ignore invalid input
        if (std::cin.fail()) {
            std::cout<<"Sorry, your input was not valid. Please enter an integer for "<<array[type]<<": ";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            continue; //restart the loop if not valid
        }

        // check if negative values
        if (int_input < 0) {
            std::cout << array[type]<<" cannot be negative. Please enter a positive value.\n";
            continue;
        }

        return int_input;  // return if input is valid
    }
}


int main()
{
    while (true) { // Start of loop level a
        // Declare variables here
        // Ask user to enter initial and final quantum numbers
        int Z = input_integer(0);
        int n_i = input_integer(1);
        int n_j = input_integer(2);

        // calculate the proper answer and compute photon energy, Delta E = 13.6*(Z^2)*(1/n_j^2 - 1/n_i^2) eV
        double energy = 13.6 * (Z * Z) * (1.0 / (n_j * n_j) - 1.0 / (n_i * n_i));
        std::cout<<"Here is my answer: "<<energy << std::endl;

        // Ask user if they want to continue
        std::string if_repeat;
        while (true) { // Start of loop level b
            std::cout<<"Would you like to repeat? (y/n): ";
            std::cin>>if_repeat;

            // Convert uppercase to lowercase for easier checking
            if (if_repeat == "Y") if_repeat = "y";
            if (if_repeat == "N") if_repeat = "n";

            if (if_repeat == "y" || if_repeat == "n") {
                break;  // Break out of loop level b
            }
            std::cout<<"Please enter 'y' or 'n' only."<<std::endl;
        }

        // 4. Check if the user wants to continue. If the user refuses, break out of the loop.
        if (if_repeat == "n") {
            break;  // Break out of loop level a, program ends
        }
    }
    std::cout<<"You have successfully ended the program. Thank you for using."<<std::endl;
    return 0;
}

