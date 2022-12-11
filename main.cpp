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


/*
 * CLion IDE complains that it cannot perform complex data-flow analysis for the structure below.
 * We suppress that for now.
 */
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
struct orderInvoice {
    // Truck Information
    string truckCategory   = "";
    string truckType       = "";
    int    truckPrice      = 0;

    // Rent Information
    int    rentQuantity    = 0;
    int    rentDays        = 0;
    string rentBranch      = "";
    int    rentPenalty     = 0;

    // Customer Information
    string customerName    = "";
    string customerAddress = "";
    string customerPhone   = "";
    string customerEmail   = "";

    // Payment Information
    string paymentMode     = "";
    string cardNumber      = "";
    string cardCVV         = "";
    int    expiryMonth     = 0;
    int    expiryYear      = 0;
};
#pragma clang diagnostic pop


class System {
private:
    // First element per array row is designated as the truck category
    string truckList[5][7] = {
            {
                    "Small Truck",
                    "Mini Truck",
                    "\u200b",
                    "\u200b",
                    "\u200b",
                    "\u200b",
                    "\u200b",
            },
            {
                    "Light Truck",
                    "Minivan",
                    "SUV",
                    "Pickup",
                    "Panel Van",
                    "Tow Truck",
                    "\u200b",
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
                    "\u200b",
            },
            {
                    "Very Heavy Truck",
                    "Haul Truck",
                    "Ballast Tractor",
                    "Heavy Hauler",
                    "\u200b",
                    "\u200b",
                    "\u200b",
            },
    };
    int truckPrice[5][7] = {
            {
                    0,
                    1500,
                    0,
                    0,
                    0,
                    0,
                    0,
            },
            {
                    0,
                    2500,
                    3000,
                    3500,
                    4000,
                    4500,
                    0,
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
                    0,
            },
            {
                    0,
                    20500,
                    30000,
                    25500,
                    0,
                    0,
                    0,
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


public:
    // One and only public variable used it control system closing
    char _userInput = ' ';


    // Order Invoice structure initialization
    struct orderInvoice invoice = orderInvoice();


    // System Welcome Message
    static void welcomeMessage() {
        cout << "|-----------------------------------------|"    << endl
             << "|                                         |"    << endl
             << "|     Welcome to Golden Truck Rentals     |"   << endl
             << "|                                         |"    << endl
             << "|    \"For all your truck rental needs\"    |" << endl
             << "|                                         |"    << endl
             << "|-----------------------------------------|"    << endl
             << endl
             << endl;
    }


    // Truck Selection
    /*
     * This section handles the truck selection of the rental system.
     *
     * Contains information on truck categories, types, and prices accordingly.
     */
    void truckCategory() {
        cout << "Please select a truck category:" << endl;
        while (_indexCategory < 5) {
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
                 << "-------------------------------------------" << endl;

            // Reset variables before calling truckCategory()
            _indexCategory    = 0;
            _selectedCategory = 0;

            // Call truckCategory()
            truckCategory();
        }
        else {
            invoice.truckCategory = truckList[_selectedCategory][0];

            // Spacer
            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }
    void truckType() {
        cout << "Please select a truck type:" << endl;
        while (_indexType < 7) {
            // Skip truck category
            if (truckList[_selectedCategory][_indexType] == invoice.truckCategory) {
                // Increment the index counter
                _indexType++;
            }
                // Skip empty elements in array
            else if (truckList[_selectedCategory][_indexType] == "\u200b") {
                // Decrement the index counter
                _indexType--;

                // End the loop
                break;
            }
            else {
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
                 << "-------------------------------------------" << endl;

            // Reset variables before calling truckType()
            _indexType    = 0;
            _selectedType = 0;

            // Call truckType()
            truckType();
        }
        else {
            invoice.truckType  = truckList[_selectedCategory][_selectedType];
            invoice.truckPrice = truckPrice[_selectedCategory][_selectedType];

            // Spacer
            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }


    // Billing Section
    /*
     * This section handles the bulk of the order invoice.
     * It contains the following:
     * - Further Truck Order Invoice
     * - Branch Location
     * - Customer Information
     * - Mode of Payment
     */
    void billingQuantity() {
        cout << "Enter number of trucks to rent: ";
        cin >> invoice.rentQuantity;
        if (invoice.rentQuantity < 1) {
            cout << endl
                 << "|------------------------------------|" << endl
                 << "|    Minimum truck/s to rent: [1]    |" << endl
                 << "|------------------------------------|" << endl
                 << endl
                 << "-------------------------------------------" << endl;

            // Call billingQuantity()
            billingQuantity();
        }
        else {
            // Spacer
            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }
    void billingDays() {
        cout << "Enter number of days to rent: ";
        cin >> invoice.rentDays;
        if (invoice.rentDays < 7) {
            cout << endl
                 << "|----------------------------------|" << endl
                 << "|    Minimum day/s to rent: [7]    |" << endl
                 << "|----------------------------------|" << endl
                 << endl
                 << "-------------------------------------------" << endl;

            // Call billingDays()
            billingDays();
        }
        else if (invoice.rentDays > 30) {
            invoice.rentPenalty = invoice.rentDays - 30;
            cout << "Maximum day/s to rent: [30] (There will be a 1.5% rent penalty for each exceeding day)" << endl;
            cout << endl
                 << "|-------------------------------------------|" << endl
                 << "|        Maximum day/s to rent: [30]        |" << endl
                 << "|    1.5% penalty for each exceeding day    |"
                 << "|-------------------------------------------|" << endl
                 << endl
                 << "-------------------------------------------" << endl;
        }
        else {
            // Spacer
            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }
    void billingBranch() {
        cout << "Please select a branch location:" << endl;
        while (_indexBranch < 17) {
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
                 << "-------------------------------------------" << endl;

            // Reset variables before calling billingBranch()
            _indexBranch    = 0;
            _selectedBranch = 0;

            // Call billingBranch()
            billingBranch();
        }
        else {
            invoice.rentBranch = branchLocations[_selectedBranch];

            // Spacer
            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }
    void billingCustomer() {
        // Customer Name
        if (invoice.customerName.empty()) {
            // Spacer
            cout << endl;

            cout << "Enter customer full name: ";
            getline(cin, invoice.customerName);

            if (invoice.customerName.length() < 2) {
                cout << endl
                     << "|---------------------------------------------|" << endl
                     << "|    Please input at least two characters!    |" << endl
                     << "|---------------------------------------------|" << endl
                     << endl
                     << "-------------------------------------------" << endl;

                // Reset variables before calling billingCustomer()
                invoice.customerName = "";

                // Call billingCustomer()
                billingCustomer();
            }
        }

        // Customer Address
        if (invoice.customerAddress.empty()) {
            // Spacer
            cout << endl;

            cout << "Enter customer address: ";
            getline(cin, invoice.customerAddress);
            if (invoice.customerAddress.length() < 20) {
                cout << endl
                     << "|-------------------------------------|" << endl
                     << "|    Please input a valid address!    |" << endl
                     << "|-------------------------------------|" << endl
                     << endl
                     << "-------------------------------------------" << endl;

                // Reset variables before calling billingCustomer()
                invoice.customerAddress = "";

                // Call billingCustomer()
                billingCustomer();
            }
        }

        // Customer Number
        if (invoice.customerPhone.empty()) {
            // Spacer
            cout << endl;

            cout << "Enter customer phone number: ";
            getline(cin, invoice.customerPhone);
            if (invoice.customerPhone.length() < 11) {
                cout << endl
                     << "|------------------------------------------|" << endl
                     << "|    Please input a valid phone number!    |" << endl
                     << "|------------------------------------------|" << endl
                     << endl
                     << "-------------------------------------------" << endl;

                // Reset variables before calling billingCustomer()
                invoice.customerPhone = "";

                // Call billingCustomer()
                billingCustomer();
            }
        }


        // Customer E-mail
        if (invoice.customerEmail.empty()) {
            // Spacer
            cout << endl;

            cout << "Enter customer e-mail address: ";
            getline(cin, invoice.customerEmail);
            // TODO Add email validation check
            if (invoice.customerEmail.length() < 7) {
                cout << endl
                     << "|--------------------------------------------|" << endl
                     << "|    Please input a valid e-mail address!    |" << endl
                     << "|--------------------------------------------|" << endl
                     << endl
                     << "-------------------------------------------" << endl;

                // Reset variables before calling billingCustomer()
                invoice.customerEmail = "";

                // Call billingCustomer()
                billingCustomer();
            }
            else {
                // Spacer
                cout << endl
                     << "-------------------------------------------" << endl;
            }
        }
    }
    void billingPayment() {
        if (_selectedPayment == 0) {
            cout << "Please select a mode of payment:" << endl;
            while (_indexPayment < 4) {
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
                     << "-------------------------------------------" << endl;

                // Reset variables before calling billingPayment()
                _indexPayment    = 0;
                _selectedPayment = 0;

                // Call billingPayment()
                billingPayment();
            }
            else {
                invoice.paymentMode = paymentTypes[_selectedPayment];

                // Clean and ignore trailing '\n' newline for the next block of code to work
                cin.ignore(256, '\n');

                // Spacer
                cout << endl
                     << "-------------------------------------------" << endl;
            }
        }

        // Card Information
        if (_selectedPayment > 0) {
            // Non-cash mode of payment

            // Card Number
            if (invoice.cardNumber.empty()) {
                // Spacer
                cout << endl;

                cout << "Enter card number: (spaces included) ";
                getline(cin, invoice.cardNumber);

                if (invoice.cardNumber.length() != 19) {
                    cout << endl
                         << "|---------------------------------------------|" << endl
                         << "|    Please input the correct card number!    |" << endl
                         << "|---------------------------------------------|" << endl
                         << endl
                         << "-------------------------------------------" << endl;

                    // Reset variables before calling billingPayment()
                    invoice.cardNumber = "";

                    // Call billingPayment()
                    billingPayment();
                }
            }

            // Card Expiry Month
            if (invoice.expiryMonth == 0) {
                // Spacer
                cout << endl;

                cout << "Enter card expiry month: (MM) ";
                cin >> invoice.expiryMonth;

                if (invoice.expiryMonth < 0 || invoice.expiryMonth > 12) {
                    cout << endl
                         << "|---------------------------------------------------|" << endl
                         << "|    Please input the correct card expiry month!    |" << endl
                         << "|---------------------------------------------------|" << endl
                         << endl
                         << "-------------------------------------------" << endl;

                    // Reset variables before calling billingPayment()
                    invoice.expiryMonth = 0;

                    // Call billingPayment()
                    billingPayment();
                }
            }

            // Card Expiry Year
            if (invoice.expiryYear == 0) {
                // Spacer
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

                    // Reset variables before calling billingPayment()
                    invoice.expiryYear = 0;

                    // Call billingPayment()
                    billingPayment();
                }
            }

            // Card CVV
            if (invoice.cardCVV.empty()) {
                // Spacer
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

                    // Reset variables before calling billingPayment()
                    invoice.cardCVV = "";

                    // Call billingPayment()
                    billingPayment();
                }
                else {
                    // Spacer
                    cout << endl
                         << "-------------------------------------------" << endl;
                }
            }
        }
        else {
            // Cash mode of payment
            cout << endl
                 << "|-------------------------------------------------------------------|" << endl
                 << "|    Please print and present the receipt at your chosen branch.    |" << endl
                 << "|-------------------------------------------------------------------|" << endl;

            // Spacer
            cout << endl
                 << "-------------------------------------------" << endl;
        }
    }


    // Receipt
    /*
     * Below is the overall formula for calculating the summary of invoice:
     * - MIN and MAX values for receipt number.
     * - For now we use the old method of creating a random number in between a range.
     * - Both [0.1] and [0.5] are quantifiers that can be customized
     *    which dictates how much a truck can be rented for the squared root of any amount of days.
     * - By default [40] is the percent of our insurance for renting any kind of truck.
     * - By default [0.12] is the percent of tax.
     */
    void officialReceipt() const {
        const int MIN_CODE   = 111111;
        const int MAX_CODE   = 999999;
        long int receiptCode = MIN_CODE + (rand() % (MAX_CODE - MIN_CODE + 1));

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

        // Print receipt (invoice, customer info, mode of payment, misc., and summary)
        cout << "\tOverview" << endl
             << "\t\tReceipt Number:    " << receiptCode << endl
             << "\t\tTruck Selection:   " << invoice.truckCategory
             << " - " << invoice.truckType
             << " (Php " << invoice.truckPrice << ")" << endl
             << "\t\tTruck Quantity:    " << invoice.rentQuantity << " truck/s " << endl
             << "\t\tDays to rent:      " << invoice.rentDays << " day/s (Php " << rentTotal << ")" << endl
             << "\t\tBranch Location:   " << invoice.rentBranch                                      << endl << endl;

        cout << "\tCustomer Info"                                                                              << endl
             << "\t\tName:              " << invoice.customerName                                            << endl
             << "\t\tAddress:           " << invoice.customerAddress                                         << endl
             << "\t\tPhone Number:      " << invoice.customerPhone                                           << endl
             << "\t\tEmail Address:     " << invoice.customerEmail                                   << endl << endl;

        if (_selectedPayment > 0) {
            // Non-cash mode of payment
            cout << "\tMode of Payment"                                                                        << endl
                 << "\t\tPayment via:       " << invoice.paymentMode                                         << endl
                 << "\t\tCard Number:       ends in " << invoice.cardNumber.substr(15, 4)            << endl
                 << "\t\tCard Expiry Date:  " << setw(2) << setfill('0') << invoice.expiryMonth
                 << "/" << invoice.expiryYear                           << endl << endl;
        }
        else {
            // Cash mode of payment
            cout << "\tMode of Payment"                                                                        << endl
                 << "\t\tPayment via:       " << invoice.paymentMode                                 << endl << endl;
        }

        cout << "\tMisc." << endl
             << "\t\tInsurance:         Php " << rentInsurance << endl;

        if (invoice.rentPenalty != 0) {
            cout << "\t\tPenalty (+" << invoice.rentPenalty << " days)  Php " << rentPenalty << endl;
        }

        // Spacer
        cout << endl;

        cout << "\tSummary" << endl
             << "\t\tPre-total:         Php " << preTotal << endl
             << "\t\tTax:               Php " << addedTax << endl
             << "\t\tFinal Total:       Php " << finalTotal << endl << endl;

        // Spacer
        cout << endl
             << "-------------------------------------------" << endl;
    }


    // System Closing
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


int main () {
    // Initialize System class
    System system;


    // System Welcome Message
    System::welcomeMessage();


    // Truck Selection
    cout << "----------    Truck Selection    ----------" << endl;
    system.truckCategory();
    system.truckType();


    // Spacer
    cout << endl << endl;


    // Billing Section
    cout << "-----------    Order Section    -----------" << endl;
    system.billingQuantity();
    system.billingDays();
    system.billingBranch();

    // Clean and ignore trailing '\n' newline for the next method to work
    cin.ignore(256, '\n');
    system.billingCustomer();
    system.billingPayment();


    // Spacer
    cout << endl << endl;


    // Receipt
    cout << "----------    Official Receipt    ---------" << endl;
    system.officialReceipt();


    // Spacer
    cout << endl << endl;


    // System Closing
    /*
     * We ask the user if in case they want to rent another type of truck before returning the program
     */
    cout << "Would like to rent another truck? (Y/N) ";
    cin >> system._userInput;
    if (system._userInput == 'Y' || system._userInput == 'y') {
        // Reset variables before calling main()
        system._userInput = ' ';

        // Spacer
        cout << endl << endl;

        // Call main()
        main();

        // Return the program just in case it failed to call main()
        return 0;
    }
    else {
        // Spacer
        cout << endl
             << "-------------------------------------------" << endl;

        // Spacer
        cout << endl << endl;

        System::closingMessage();
    }


    // Return the program to close
    return 0;
}
