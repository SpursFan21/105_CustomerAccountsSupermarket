#include <iostream>
#include <string>
#include <stdexcept> // Include for exception handling

class Customer {
private:
    int customerID;
    std::string name;
    double balance;

public:
    // Constructor to initialize customer attributes
    Customer(int id, const std::string& n, double initialBalance)
        : customerID(id), name(n), balance(initialBalance) {}

    // Deposit function to add money to the customer's balance
    void deposit(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("Deposit amount cannot be negative.");
        }
        balance += amount;
    }

    // Purchase function to deduct money from the customer's balance if there are sufficient funds
    void purchase(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("Purchase amount cannot be negative.");
        }
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Purchase successful.\n";
        }
        else {
            throw std::runtime_error("Insufficient funds. Purchase failed.");
        }
    }

    // Get the current customer's balance
    double getBalance() const {
        return balance;
    }

    // Display customer information
    void displayCustomerInfo() const {
        std::cout << "Customer ID: " << customerID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};

int main() {
    Customer* customers[3]; // Array of pointers to Customer objects

    // Initialize customer accounts
    customers[0] = new Customer(1, "Alice", 1000.0);
    customers[1] = new Customer(2, "Bob", 750.0);
    customers[2] = new Customer(3, "Charlie", 500.0);

    char choice;
    int customerIndex;

    // Main program loop
    while (true) {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Deposit" << std::endl;
        std::cout << "2. Purchase" << std::endl;
        std::cout << "3. Display Customer Info" << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::cin >> choice;

        try {
            switch (choice) {
            case '1':
                std::cout << "Enter customer index (0, 1, or 2): ";
                std::cin >> customerIndex;
                if (customerIndex >= 0 && customerIndex < 3) {
                    double amount;
                    std::cout << "Enter deposit amount: $";
                    std::cin >> amount;
                    customers[customerIndex]->deposit(amount);
                    std::cout << "Deposit successful.\n";
                }
                else {
                    std::cout << "Invalid customer index.\n";
                }
                break;
            case '2':
                std::cout << "Enter customer index (0, 1, or 2): ";
                std::cin >> customerIndex;
                if (customerIndex >= 0 && customerIndex < 3) {
                    double amount;
                    std::cout << "Enter purchase amount: $";
                    std::cin >> amount;
                    customers[customerIndex]->purchase(amount);
                }
                else {
                    std::cout << "Invalid customer index.\n";
                }
                break;
            case '3':
                std::cout << "Enter customer index (0, 1, or 2): ";
                std::cin >> customerIndex;
                if (customerIndex >= 0 && customerIndex < 3) {
                    customers[customerIndex]->displayCustomerInfo();
                }
                else {
                    std::cout << "Invalid customer index.\n";
                }
                break;
            case '4':
                std::cout << "Exiting the program.\n";
                // Deallocate memory for Customer objects
                for (int i = 0; i < 3; ++i) {
                    delete customers[i];
                }
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const std::exception& ex) {
            // Handle exceptions and display error messages
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }
}
