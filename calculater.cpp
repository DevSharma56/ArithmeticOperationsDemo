#include <iostream>
#include <string>

class Addition {
public:
    // Integer addition
    int add(int a, int b) {
        return a + b;
    }
    
    // String concatenation
    std::string add(const std::string& a, const std::string& b) {
        return a + b;
    }
};

class Subtraction {
public:
    // Integer subtraction
    int subtract(int a, int b) {
        return a - b;
    }
    
    // String subtraction (removes first occurrence)
    std::string subtract(std::string a, const std::string& b) {
        size_t index = a.find(b);
        if (index != std::string::npos) {
            a.erase(index, b.length());
        }
        return a;
    }
};

class Calculator {
public:
    // Integer multiplication
    int multiply(int a, int b) {
        return a * b;
    }
    
    // String multiplication (repetition)
    std::string multiply(const std::string& a, int b) {
        if (b < 0) return "Error: Cannot multiply string by negative number";
        std::string result;
        for (int i = 0; i < b; i++) {
            result += a;
        }
        return result;
    }
    
    // Integer division
    std::string divide(int a, int b) {
        if (b == 0) return "Error: Division by zero is not allowed.";
        return std::to_string(static_cast<double>(a) / b);
    }
    
    // String division (returns substring of divided length)
    std::string divide(const std::string& a, int b) {
        if (b == 0) return "Error: Division by zero is not allowed.";
        size_t newLength = a.length() / b;
        return a.substr(0, newLength);
    }
};

int main() {
    Addition addition;
    Subtraction subtraction;
    Calculator calculator;
    
    int num1, num2;
    std::string str1, input2;
    
    // Numeric operations
    std::cout << "Numeric Operations:" << std::endl;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    
    std::cout << "\nNumeric Results:" << std::endl;
    std::cout << "Add: " << addition.add(num1, num2) << std::endl;
    std::cout << "Subtract: " << subtraction.subtract(num1, num2) << std::endl;
    std::cout << "Multiply: " << calculator.multiply(num1, num2) << std::endl;
    std::cout << "Divide: " << calculator.divide(num1, num2) << std::endl;
    
    // Clear input buffer
    std::cin.ignore();
    
    // String operations
    std::cout << "\nString Operations:" << std::endl;
    std::cout << "Enter first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter second input (string for + and -, number for * and /): ";
    std::getline(std::cin, input2);
    
    std::cout << "\nString Results:" << std::endl;
    std::cout << "Add: " << addition.add(str1, input2) << std::endl;
    std::cout << "Subtract: " << subtraction.subtract(str1, input2) << std::endl;
    
    try {
        int num = std::stoi(input2);
        std::cout << "Multiply: " << calculator.multiply(str1, num) << std::endl;
        std::cout << "Divide: " << calculator.divide(str1, num) << std::endl;
    } catch (std::exception&) {
        std::cout << "Multiply: Error - Second input must be a number" << std::endl;
        std::cout << "Divide: Error - Second input must be a number" << std::endl;
    }
    
    return 0;
}
