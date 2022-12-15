/**
 * Golden Truck Rentals
 * main.cpp
 * Purpose: To create a truck rental service system.
 *
 * @author Alcedo, Contridas, De Perio, Inocentes, Remperas, Tan, Toreja
 */


#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;


#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
class System {
private:
    /*
     * Since we count an array starting from 0, we will use this to our advantage by using these elements of the array
     * as the categories of our truck list.
     *
     * Same goes for our truck prices, we did not put any price on the first element of the array.
     *
     * Our program did use two types of arrays, 2-dimensional array and 1-dimensional array.
     *
     * Our private variables start with an underscore mainly for separation and formatting.
     */
    string truckList[5][7] = {
            {
                    "Small Truck",
                    "Mini Truck",
            },
            {
                    "Light Truck",
                    "Minivan",
                    "SUV",
                    "Pickup",
                    "Panel Van",
                    "Tow Truck",
            },
            {
                    "Medium Truck",
                    "Box Truck",
                    "White Van",
                    "Medium Duty Truck",
                    "Medium Standard Truck",
                    "Platform Truck",
                    "Flatbed Truck",
            },
            {
                    "Heavy Truck",
                    "Dump Truck",
                    "Garbage Truck",
                    "Refrigerator Truck",
                    "Tractor Unit",
                    "Tank Truck",
            },
            {
                    "Very Heavy Truck",
                    "Haul Truck",
                    "Ballast Tractor",
                    "Heavy Hauler",
            },
    };
    int truckPrice[5][7] = {
            {
                    0,
                    1500,
            },
            {
                    0,
                    2500,
                    3000,
                    3500,
                    4000,
                    4500,
            },
            {
                    0,
                    5500,
                    6000,
                    6500,
                    7000,
                    7500,
                    8000,
            },
            {
                    0,
                    10000,
                    12000,
                    14000,
                    16000,
                    18000,
            },
            {
                    0,
                    20500,
                    30000,
                    25500,
            },
    };

    string branchLocations[17] = {
            "Caloocan",
            "Las Pinas",
            "Makati",
            "Malabon",
            "Mandaluyong",
            "Manila",
            "Marikina",
            "Muntinlupa",
            "Navotas",
            "Paranaque",
            "Pasay",
            "Pasig",
            "Pateros (Municipality)",
            "Quezon City",
            "San Juan",
            "Taguig",
            "Valenzuela",
    };

    string paymentTypes[4] = {
            "Cash",
            "PayPal",
            "MasterCard",
            "Visa",
    };

    int _indexCategory    = 0;
    int _selectedCategory = 0;

    int _indexType        = 0;
    int _selectedType     = 0;

    int _indexBranch      = 0;
    int _selectedBranch   = 0;

    int _indexPayment     = 0;
    int _selectedPayment  = 0;


protected:
    struct orderInvoice {
        // Truck Selection
        string truckCategory;
        string truckType;
        int    truckPrice{};

        // Order Section
        int    rentQuantity{};
        int    rentDays{};
        string rentBranch;
        int    rentPenalty{};

        // Customer Information
        string customerName;
        string customerAddress;
        string customerPhone;
        string customerEmail;

        // Payment Information
        string paymentMode;
        string cardNumber;
        string cardCVV;
        int    expiryMonth{};
        int    expiryYear{};
    };


public:
    // This public variable is used to determine the system closing.
    char _userInput = ' ';

    // Create an structure object to use
    struct orderInvoice invoice = orderInvoice();

    static void welcomeMessage() {
        cout << "|-----------------------------------------|" << endl
             << "|                                         |" << endl
             << "|     Welcome to Golden Truck Rentals     |" << endl
             << "|                                         |" << endl
             << "|    [For all your truck rental needs]    |" << endl
             << "|                                         |" << endl
             << "|-----------------------------------------|" << endl
             << endl
             << endl;
    }

    void truckCategory() {
        cout << "Please select a truck category:" << endl;
        while (_indexCategory < 5) {
            // Print truck categories to console
            cout << "\t> [" << setw(2) << setfill('0') << _indexCategory + 1 << "] "
                 << truckList[_indexCategory][0] << endl;
            _indexCategory++;
        }

        cout << "-------------------------------------------" << endl
             << endl
             << "Enter truck category number: ";
        cin >> _selectedCategory;

        if (_selectedCategory == 0 || _selectedCategory-- > _indexCategory) {
            cout << endl
                 << "|---------------------------------------------------------|" << endl
                 << "|    Please only select from the given truck category!    |" << endl
                 << "|---------------------------------------------------------|" << endl
                 << endl
                 << "-------------------------------------------"                 << endl;

            // Reset variables used
            _indexCategory    = 0;
            _selectedCategory = 0;

            // Call the method
            truckCategory();
        }
        else {
            invoice.truckCategory = truckList[_selectedCategory][0];

            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }
    void truckType() {
        cout << "Please select a truck type:" << endl;
        while (_indexType < 7) {
            if (truckList[_selectedCategory][_indexType] == invoice.truckCategory) {
                // Skip the first element of the array as it is the category
                _indexType++;
            }
            else if (truckList[_selectedCategory][_indexType].empty()) {
                // Decrement the counter and break the loop
                _indexType--;
                break;
            }
            else {
                //Print truck types to console
                cout << "\t> [" << setw(2) << setfill('0') << _indexType << "] "
                     << "Php " << truckPrice[_selectedCategory][_indexType]
                     << " - " << truckList[_selectedCategory][_indexType] << endl;
                _indexType++;
            }
        }

        cout << "-------------------------------------------" << endl
             << endl
             << "Enter truck type number: ";
        cin >> _selectedType;

        if (_selectedType == 0 || _selectedType > _indexType) {
            cout << endl
                 << "|------------------------------------------------------|" << endl
                 << "|    Please only select from the given truck types!    |" << endl
                 << "|------------------------------------------------------|" << endl
                 << endl
                 << "-------------------------------------------"              << endl;

            // Reset the variables used
            _indexType    = 0;
            _selectedType = 0;

            // Call the method
            truckType();
        }
        else {
            invoice.truckType  = truckList[_selectedCategory][_selectedType];
            invoice.truckPrice = truckPrice[_selectedCategory][_selectedType];

            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }

    void billingQuantity() {
        cout << "Enter number of trucks to rent: ";
        cin >> invoice.rentQuantity;
        if (invoice.rentQuantity < 1) {
            cout << endl
                 << "|------------------------------------|"      << endl
                 << "|    Minimum truck/s to rent: [1]    |"      << endl
                 << "|------------------------------------|"      << endl
                 << endl
                 << "-------------------------------------------" << endl;

            billingQuantity();
        }
        else {
            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }
    void billingDays() {
        /*
         * For the number of days to rent, the program's minimum is 7 days,
         * maximum is 30 with support for exceeding days and a penalty is given.
         */

        cout << "Enter number of days to rent: ";
        cin >> invoice.rentDays;
        if (invoice.rentDays < 7) {
            cout << endl
                 << "|----------------------------------|"        << endl
                 << "|    Minimum day/s to rent: [7]    |"        << endl
                 << "|----------------------------------|"        << endl
                 << endl
                 << "-------------------------------------------" << endl;

            billingDays();
        }
        else if (invoice.rentDays > 30) {
            invoice.rentPenalty = invoice.rentDays - 30;
            cout << endl
                 << "|-------------------------------------------|" << endl
                 << "|        Maximum day/s to rent: [30]        |" << endl
                 << "|    1.5% penalty for each exceeding day    |" << endl
                 << "|-------------------------------------------|" << endl
                 << endl
                 << "-------------------------------------------"   << endl;
        }
        else {
            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }
    void billingBranch() {
        cout << "Please select a branch location:" << endl;
        while (_indexBranch < 17) {
            // Print branch locations to console
            cout << "\t> [" << setw(2) << setfill('0') << _indexBranch + 1 << "] "
                 << branchLocations[_indexBranch] << endl;
            _indexBranch++;
        }

        cout << "-------------------------------------------" << endl
             << endl
             << "Enter branch number: ";
        cin >> _selectedBranch;

        if (_selectedBranch == 0 || _selectedBranch-- > _indexBranch) {
            cout << endl
                 << "|---------------------------------------------------|" << endl
                 << "|    Please only select from the given branches!    |" << endl
                 << "|---------------------------------------------------|" << endl
                 << endl
                 << "-------------------------------------------"           << endl;

            // Reset the variables used
            _indexBranch    = 0;
            _selectedBranch = 0;

            // Call the method
            billingBranch();
        }
        else {
            invoice.rentBranch = branchLocations[_selectedBranch];

            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }
    void billingCustomer() {
        /*
         * In order to avoid the user to re-enter the same information again after calling the method because of an
         * invalid input, we check if the variable where we store the customer information is empty or not.
         *
         * If it is not empty, then execute the code inside the statement, if not, then we skip the code.
         */

        // Customer Name
        if (invoice.customerName.empty()) {
            cout << endl;

            cout << "Enter customer full name: ";
            getline(cin, invoice.customerName);

            if (invoice.customerName.length() < 2) {
                cout << endl
                     << "|---------------------------------------------|" << endl
                     << "|    Please input at least two characters!    |" << endl
                     << "|---------------------------------------------|" << endl
                     << endl
                     << "-------------------------------------------"     << endl;

                // Reset the variables used
                invoice.customerName = "";

                // Call the method
                billingCustomer();
            }
        }

        // Customer Address
        if (invoice.customerAddress.empty()) {
            cout << endl;

            cout << "Enter customer address: ";
            getline(cin, invoice.customerAddress);
            if (invoice.customerAddress.length() < 20) {
                cout << endl
                     << "|-------------------------------------|"     << endl
                     << "|    Please input a valid address!    |"     << endl
                     << "|-------------------------------------|"     << endl
                     << endl
                     << "-------------------------------------------" << endl;

                // Reset the variables used
                invoice.customerAddress = "";

                // Call the method
                billingCustomer();
            }
        }

        // Customer Phone
        if (invoice.customerPhone.empty()) {
            cout << endl;

            cout << "Enter customer phone number: ";
            getline(cin, invoice.customerPhone);
            if (invoice.customerPhone.length() < 11) {
                cout << endl
                     << "|------------------------------------------|" << endl
                     << "|    Please input a valid phone number!    |" << endl
                     << "|------------------------------------------|" << endl
                     << endl
                     << "-------------------------------------------"  << endl;

                // Reset the variables used
                invoice.customerPhone = "";

                // Call the method
                billingCustomer();
            }
        }

        // Customer E-mail
        if (invoice.customerEmail.empty()) {
            cout << endl;

            cout << "Enter customer e-mail address: ";
            getline(cin, invoice.customerEmail);
            if (invoice.customerEmail.length() < 7) {
                cout << endl
                     << "|--------------------------------------------|" << endl
                     << "|    Please input a valid e-mail address!    |" << endl
                     << "|--------------------------------------------|" << endl
                     << endl
                     << "-------------------------------------------"    << endl;

                // Reset the variables used
                invoice.customerEmail = "";

                // Call the method
                billingCustomer();
            }
            else {
                cout << endl
                     << "-------------------------------------------" << endl;
            }
        }
    }
    void billingPayment() {
        /*
         * Similar to our customer information, our code block for mode of payment works in a similar fashion.
         *
         * It checks whether the user has made a selection. If not, execute the code. If yes, skip the code.
         */

        if (_selectedPayment == 0) {
            cout << "Please select a mode of payment:" << endl;
            while (_indexPayment < 4) {
                // Print payment modes to console
                cout << "\t> [" << setw(2) << setfill('0') << _indexPayment + 1 << "] "
                     << paymentTypes[_indexPayment] << endl;
                _indexPayment++;
            }

            cout << "-------------------------------------------" << endl
                 << endl
                 << "Enter mode of payment number: ";
            cin >> _selectedPayment;

            if (_selectedPayment == 0 || _selectedPayment-- > _indexPayment) {
                cout << endl
                     << "|-----------------------------------------------------------|" << endl
                     << "|    Please only select from the given mode of payments!    |" << endl
                     << "|-----------------------------------------------------------|" << endl
                     << endl
                     << "-------------------------------------------"                   << endl;

                // Reset the variables used
                _indexPayment    = 0;
                _selectedPayment = 0;

                // Call the method
                billingPayment();
            }
            else {
                invoice.paymentMode = paymentTypes[_selectedPayment];

                /*
                 * The way cin works is that it terminates the console input once it detects any whitespace and
                 * break the following getline() after it. To prevent that behavior, we will ignore whitespaces
                 * on our cin before proceeding to using the getline() function.
                 */
                cin.ignore(256, '\n');

                cout << endl
                     << "-------------------------------------------" << endl;
            }
        }

        if (_selectedPayment > 0) {
            if (invoice.cardNumber.empty()) {
                // Non-Cash payment mode
                /*
                 * If the user selected the non-cash mode, the program will now start asking the user for its
                 * credit card information.
                 */

                cout << endl;

                cout << "Enter card number: (spaces included) ";
                getline(cin, invoice.cardNumber);

                // Credit Card Number
                if (invoice.cardNumber.length() != 19) {
                    cout << endl
                         << "|---------------------------------------------|" << endl
                         << "|    Please input the correct card number!    |" << endl
                         << "|---------------------------------------------|" << endl
                         << endl
                         << "-------------------------------------------"     << endl;

                    // Reset the variables used
                    invoice.cardNumber = "";

                    // Call the method
                    billingPayment();
                }
            }

            // Credit Card Expiry Month
            if (invoice.expiryMonth == 0) {
                cout << endl;

                cout << "Enter card expiry month: (MM) ";
                cin >> invoice.expiryMonth;

                if (invoice.expiryMonth < 0 || invoice.expiryMonth > 12) {
                    cout << endl
                         << "|---------------------------------------------------|" << endl
                         << "|    Please input the correct card expiry month!    |" << endl
                         << "|---------------------------------------------------|" << endl
                         << endl
                         << "-------------------------------------------"           << endl;

                    // Reset the variables used
                    invoice.expiryMonth = 0;

                    // Call the method
                    billingPayment();
                }
            }

            // Credit Card Expiry Year
            if (invoice.expiryYear == 0) {
                cout << endl;

                cout << "Enter card expiry year: (YY) ";
                cin >> invoice.expiryYear;

                if (invoice.expiryYear < 22) {
                    cout << endl
                         << "|--------------------------------------------------|" << endl
                         << "|    Please input the correct card expiry year!    |" << endl
                         << "|--------------------------------------------------|" << endl
                         << endl
                         << "-------------------------------------------" << endl;

                    // Reset the variables used
                    invoice.expiryYear = 0;

                    // Call the method
                    billingPayment();
                }
            }

            // Credit Card CVV
            if (invoice.cardCVV.empty()) {
                cout << endl;

                cout << "Enter card CVV: ";
                cin >> invoice.cardCVV;

                if (invoice.cardCVV.length() != 3) {
                    cout << endl
                         << "|------------------------------------------|" << endl
                         << "|    Please input the correct card CVV!    |" << endl
                         << "|------------------------------------------|" << endl
                         << endl
                         << "-------------------------------------------" << endl;

                    // Reset the variables used
                    invoice.cardCVV = "";

                    // Call the method
                    billingPayment();
                }
                else {
                    cout << endl
                         << "-------------------------------------------" << endl;
                }
            }
        }
        else {
            // Cash payment mode
            /*
             * If the user selected the cash method. They will need to print and present the Official Receipt.
             *
             * They will need to process the payment in person.
             */

            cout << endl
                 << "|-------------------------------------------------------------------|" << endl
                 << "|    Please print and present the receipt at your chosen branch.    |" << endl
                 << "|-------------------------------------------------------------------|" << endl
                 << endl
                 << "-------------------------------------------"                           << endl;
        }
    }

    void officialReceipt() {
        /*
         * The official receipt contains the overview of the following:
         *
         * - Order Overview
         * - Basic Customer Information
         * - Mode of Payment
         * - Miscellaneous Fees
         * - Price Summary
         */

        const int MIN_CODE   = 111111;
        const int MAX_CODE   = 999999;
        long int receiptCode = MIN_CODE + (rand() % (MAX_CODE - MIN_CODE + 1));

        /*
         * Below is the code for computing the price summary of the order.
         *
         * We compute the rent price per truck individually not as a whole.
         * We have 1.5% for every succeeding day for renting a truck.
         * 0.1 and 0.5 are quantifiers on how to compute the price amount per day of renting a truck.
         * We take 40% of the overall price of all the trucks rented as its insurance as a whole not individually.
         * We take a 12% sales tax added on the computed price in pre-total.
         */
        double rentPrice     = invoice.rentQuantity * invoice.truckPrice;
        double rentPenalty   = 0;
        if (invoice.rentPenalty != 0) {
            rentPenalty      = ((0.1 * sqrt(invoice.rentPenalty * 1.5)) / 0.5) * rentPrice;
        }
        double rentTotal     = ((0.1 * sqrt(invoice.rentDays)) / 0.5) * rentPrice;
        double rentInsurance = (40 * rentPrice) / 100;
        double preTotal      = rentPrice + rentTotal + rentPenalty + rentInsurance;
        double addedTax      = preTotal * 0.12;
        double finalTotal    = preTotal + addedTax;

        cout << "\tOverview"                                                                        << endl
             << "\t\tReceipt Number:    " << receiptCode                                            << endl
             << "\t\tTruck Selection:   " << invoice.truckCategory
             << " - " << invoice.truckType
             << " (Php " << invoice.truckPrice << ")"                                               << endl
             << "\t\tTruck Quantity:    " << invoice.rentQuantity << " truck/s "                    << endl
             << "\t\tDays to rent:      " << invoice.rentDays << " day/s (Php " << rentTotal << ")" << endl
             << "\t\tBranch Location:   " << invoice.rentBranch                                     << endl
             << endl;

        cout << "\tCustomer Info"                                    << endl
             << "\t\tName:              " << invoice.customerName    << endl
             << "\t\tAddress:           " << invoice.customerAddress << endl
             << "\t\tPhone Number:      " << invoice.customerPhone   << endl
             << "\t\tEmail Address:     " << invoice.customerEmail   << endl
             << endl;

        if (_selectedPayment > 0) {
            // Non-Cash payment mode
            /*
             * We will not show the entirety of the credit card number, just the last 4 digits of it.
             *
             * We will not show the card CVV also for security and privacy reasons.
             */

            cout << "\tMode of Payment"                                                               << endl
                 << "\t\tPayment via:       " << invoice.paymentMode                                  << endl
                 << "\t\tCard Number:       ends in " << invoice.cardNumber.substr(15, 4)     << endl
                 << "\t\tCard Expiry Date:  " << setw(2) << setfill('0') << invoice.expiryMonth
                 << "/" << invoice.expiryYear                                                         << endl
                 << endl;
        }
        else {
            // Cash payment mode

            cout << "\tMode of Payment"                              << endl
                 << "\t\tPayment via:       " << invoice.paymentMode << endl
                 << endl;
        }

        cout << "\tMiscellaneous Fees"                         << endl
             << "\t\tInsurance:         Php " << rentInsurance << endl;

        if (invoice.rentPenalty != 0) {
            // If the user has exceeded the maximum amount of days, this line of code will be shown in the receipt.

            cout << "\t\tPenalty (+" << invoice.rentPenalty << " days)  Php " << rentPenalty << endl;
        }

        cout << endl;

        cout << "\tSummary"                                   << endl
             << "\t\tPre-total:         Php " << preTotal     << endl
             << "\t\tTax:               Php " << addedTax     << endl
             << "\t\tFinal Total:       Php " << finalTotal   << endl
             << endl
             << endl
             << "-------------------------------------------" << endl;
    }

    static void closingMessage() {
        cout << "|-----------------------------------------|" << endl
             << "|                                         |" << endl
             << "|        Thank you for renting at         |" << endl
             << "|                                         |" << endl
             << "|          Golden Truck Rentals           |" << endl
             << "|                                         |" << endl
             << "|-----------------------------------------|" << endl;
    }
};
#pragma clang diagnostic pop


int main () {
    // Create an system object for our program
    System system;


    // Print the welcome message
    System::welcomeMessage();


    cout << "----------    Truck Selection    ----------" << endl;
    system.truckCategory();
    system.truckType();
    cout << endl << endl;


    cout << "-----------    Order Section    -----------" << endl;
    system.billingQuantity();
    system.billingDays();
    system.billingBranch();
    /*
     * The way cin works is that it terminates the console input once it detects any whitespace and
     * break the following getline() after it. To prevent that behavior, we will ignore whitespaces on our cin
     * before proceeding to using the getline() function.
     */
    cin.ignore(256, '\n');
    system.billingCustomer();
    system.billingPayment();
    cout << endl << endl;


    cout << "----------    Official Receipt    ---------" << endl;
    system.officialReceipt();
    cout << endl << endl;


    // System Closing
    cout << "Would like to rent another truck? (Y/N) ";
    cin >> system._userInput;
    if (system._userInput == 'Y' || system._userInput == 'y') {
        // Reset the variable used
        system._userInput = ' ';

        // Console spacer
        cout << endl << endl << endl << endl;

        // Call the main() method
        main();

        // In case it does not call the main() method, return 0 the program for redundancy to end the program.
        return 0;
    }
    else {
        // We only check of the user inputs Y or y to the program, any other input will be counted as "no".
        cout << endl
             << "-------------------------------------------" << endl
             << endl
             << endl;

        // Print the closing message
        System::closingMessage();
    }


    // Finally, return 0 to end the program.
    return 0;
}
