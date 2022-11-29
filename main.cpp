/**
 * Truck Rental System
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


int main() {
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


    // Order Invoice structure initialization
    struct orderInvoice invoice = orderInvoice();


    // System Welcome Message
    cout << "Welcome to [Truck Rental System]" << endl
         << "Your number one place for all your truck rental needs!" << endl << endl;


    // Truck Selection
    /*
     * This section handles the truck selection of the rental system.
     * Contains information on truck categories, types, and prices accordingly.
     */
    int _indexCategory{};
    int _selectedCategory;
    cout << "[Truck Selection - Truck Category]" << endl;
    cout << "Please select a truck category" << endl;
    // Print out truck categories to the console
    while (_indexCategory < 5) {
        cout << "[" << _indexCategory + 1 << "] " << truckList[_indexCategory][0] << endl;
        _indexCategory++;
    }
    cout << "Enter truck category number: ";
    cin >> _selectedCategory;
    if (_selectedCategory == 0 || _selectedCategory-- > _indexCategory) {
        cout << "Please only select from the given truck category!";
        return 0;
    }
    else {
        invoice.truckCategory = truckList[_selectedCategory][0];
        cout << "You have selected [" << invoice.truckCategory << "]" << endl << endl;
    }

    int _indexType{};
    int _selectedType;
    cout << "[Truck Selection - Truck Type]" << endl;
    cout << "Please select a truck type" << endl;
    // Print out truck types to the console
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
            break;
        }
        else {
            cout << "[" << _indexType << "] Php " << truckPrice[_selectedCategory][_indexType]
                 << " - " << truckList[_selectedCategory][_indexType] << endl;
            _indexType++;
        }
    }
    cout << "Enter truck type number: ";
    cin >> _selectedType;
    if (_selectedType == 0 || _selectedType > _indexType) {
        cout << "Please only select from the given truck types!";
        return 0;
    }
    else {
        invoice.truckType  = truckList[_selectedCategory][_selectedType];
        invoice.truckPrice = truckPrice[_selectedCategory][_selectedType];
        cout << "You have selected [" << invoice.truckType << "] Php " << invoice.truckPrice << endl << endl;
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
    cout << "[Billing Section - Order Invoice]" << endl;
    cout << "Enter number of trucks to rent: ";
    cin >> invoice.rentQuantity;
    if (invoice.rentQuantity < 1) {
        cout << "Minimum trucks to rent is [1]";
        return 0;
    }
    else {
        cout << "You have chosen to rent [" << invoice.rentQuantity << "] " << invoice.truckType << endl << endl;
    }

    cout << "Enter number of days to rent: ";
    cin >> invoice.rentDays;
    if (invoice.rentDays < 1) {
        cout << "Minimum days to rent is [1]";
        return 0;
    }
    else {
        cout << "You have chosen to rent for [" << invoice.rentDays << "] day/s" << endl << endl;
    }

    int _indexBranch{};
    int _selectedBranch;
    cout << "[Billing Section - Branch Location]" << endl;
    cout << "Please select a branch near your current location" << endl;
    // Print out branch locations to the console
    while (_indexBranch < 17) {
        cout << "[" << _indexBranch + 1 << "] " << branchLocations[_indexBranch] << endl;
        _indexBranch++;
    }
    cout << "Enter branch number: ";
    cin >> _selectedBranch;
    if (_selectedBranch == 0 || _selectedBranch-- > _indexBranch) {
        cout << "Please only select from the given branches!";
        return 0;
    }
    else {
        invoice.rentBranch = branchLocations[_selectedBranch];
        cout << "You have selected [" << invoice.rentBranch << "] Branch" << endl << endl;

        // Clean and ignore trailing '\n' newline for the next getline() to work
        cin.ignore(256, '\n');
    }

    cout << "[Billing Section - Customer Information]" << endl;
    cout << "Enter customer full name: ";
    getline(cin, invoice.customerName);
    if (invoice.customerName.length() < 2) {
        cout << "Please input at least two characters!";
        return 0;
    }
    cout << "Enter customer address: ";
    getline(cin, invoice.customerAddress);
    cout << "Enter customer phone number: ";
    getline(cin, invoice.customerPhone);
    if (invoice.customerPhone.length() < 11) {
        cout << "Please input valid phone number!";
        return 0;
    }
    cout << "Enter customer email address: ";
    getline(cin, invoice.customerEmail);
    // TODO Add email validation check
    //  Check whether customer email is of correct format
    cout << endl << "[Customer Information Overview]"                   << endl;
    cout << "Customer Name:          " << invoice.customerName          << endl;
    cout << "Customer Address:       " << invoice.customerAddress       << endl;
    cout << "Customer Phone Number:  " << invoice.customerPhone         << endl;
    cout << "Customer Email Address: " << invoice.customerEmail << endl << endl;

    int _indexPayment{};
    int _selectedPayment;
    cout << "[Billing Section - Mode of Payment]" << endl;
    cout << "Please select a mode of payment (Additional Php 50 fee if non-cash)" << endl;
    // Print out modes of payment to the console
    while (_indexPayment < 4) {
        cout << "[" << _indexPayment + 1 << "] " << paymentTypes[_indexPayment] << endl;
        _indexPayment++;
    }
    cout << "Enter mode of payment number: ";
    cin >> _selectedPayment;
    if (_selectedPayment == 0 || _selectedPayment-- > _indexPayment) {
        cout << "Please only select from the given mode of payments!";
        return 0;
    }
    else {
        invoice.paymentMode = paymentTypes[_selectedPayment];
        cout << "You have selected [" << invoice.paymentMode << "] as mode of payment" << endl << endl;

        // Clean and ignore trailing '\n' newline for the next getline() to work
        cin.ignore(256, '\n');
    }
    cout << "[Mode of Payment - " << invoice.paymentMode << "]" << endl;
    if (_selectedPayment > 0) {
        // Non-cash mode of payment
        cout << "Enter card number: (spaces included) ";
        getline(cin, invoice.cardNumber);
        if (invoice.cardNumber.length() != 19) {
            cout << "Please input the correct card number!";
            return 0;
        }
        cout << "Enter card expiry month: (MM) ";
        cin >> invoice.expiryMonth;
        if (invoice.expiryMonth < 0 || invoice.expiryMonth > 12) {
            cout << "Please input the correct card expiry month!";
            return 0;
        }
        cout << "Enter card expiry year: (YY) ";
        cin >> invoice.expiryYear;
        if (invoice.expiryYear < 22) {
            cout << "Please input the correct card expiry year!";
            return 0;
        }
        cout << "Enter card CVV: ";
        cin >> invoice.cardCVV;
        if (invoice.cardCVV.length() != 3) {
            cout << "Please input the correct card CVV!";
            return 0;
        }
        cout << "[" << invoice.paymentMode << " Payment Overview]"                          << endl;
        cout << "Card Number:      ends in " << invoice.cardNumber.substr(15, 4)    << endl;
        cout << "Card Expiry Date: " << setw(2) << setfill('0') << invoice.expiryMonth
                                     << "/" << invoice.expiryYear                           << endl;
        cout << "Card CVV:         " << invoice.cardCVV                             << endl << endl;
    }
    else {
        // Cash mode of payment
        cout << "Please print and present the receipt at your chosen branch to process the payment" << endl << endl;
    }


    // Receipt
    /*
     * Below is the overall formula for calculating the summary of invoice:
     * - MIN and MAX values for receipt number.
     * - For now we use the old method of creating a random number in between a range.
     * - Both [0.1] and [0.5] are quantifiers that can be customized
     *    which dictates how much a truck can be rented for the squared root of any amount of days.
     * - By default [40] is the percent of our insurance for renting any kind of truck.
     * - By default [0.10] is the percent of tax.
     */
    const int MIN_RECEIPT_NUMBER = 111111;
    const int MAX_RECEIPT_NUMBER = 999999;
    long int receiptNumber       = MIN_RECEIPT_NUMBER + (rand() % (MAX_RECEIPT_NUMBER - MIN_RECEIPT_NUMBER + 1));

    double invoiceRentQuantity   = invoice.rentQuantity * invoice.truckPrice;
    double invoiceRentDays       = ((0.1 * sqrt(invoice.rentDays)) / 0.5) * invoiceRentQuantity;
    double invoiceInsurance      = (40 * invoiceRentQuantity) / 100;
    const double CARD_FEE        = (_selectedPayment > 0) ? 50 : 0;
    double invoicePreTotal       = invoiceRentQuantity + invoiceRentDays + invoiceInsurance + CARD_FEE;
    double invoiceTax            = invoicePreTotal * 0.10;
    double invoicePostTotal      = invoicePreTotal + invoiceTax;

    // Print receipt (invoice, customer info, mode of payment, misc., and summary)
    cout << "[Truck Rental System - Official Receipt]"                                                      << endl;
    cout << "   Order Invoice"                                                                              << endl
         << "       Receipt Number:    " << receiptNumber                                                   << endl
         << "       Truck Selection:   " << invoice.truckCategory
                                         << " - "<< invoice.truckType
                                         << " (Php " << invoice.truckPrice << ")"                           << endl
         << "       Truck Quantity:    " << invoice.rentQuantity << " truck/s "                             << endl
         << "       Days to rent:      " << invoice.rentDays << " day/s (Php " << invoiceRentDays << ")"    << endl
         << "       Branch Location:   " << invoice.rentBranch                                      << endl << endl;
    cout << "   Customer Info"                                                                              << endl
         << "       Name:              " << invoice.customerName                                            << endl
         << "       Address:           " << invoice.customerAddress                                         << endl
         << "       Phone Number:      " << invoice.customerPhone                                           << endl
         << "       Email Address:     " << invoice.customerEmail                                   << endl << endl;
    if (_selectedPayment > 0) {
        // Non-cash mode of payment
        cout << "   Mode of Payment"                                                                        << endl
             << "       Payment via:       " << invoice.paymentMode                                         << endl
             << "       Card Number:       ends in " << invoice.cardNumber.substr(15, 4)            << endl
             << "       Card Expiry Date:  " << setw(2) << setfill('0') << invoice.expiryMonth
                                             << "/" << invoice.expiryYear                           << endl << endl;
        cout << "   Misc."                                                                                  << endl
             << "       Insurance:         Php " << invoiceInsurance                                        << endl
             << "       Card Fee:          Php " << CARD_FEE                                        << endl << endl;
        cout << "   Summary"                                                                                << endl
             << "       Pre-total:         Php " << invoicePreTotal                                         << endl
             << "       Tax:               Php " << invoiceTax                                              << endl
             << "       Final Total:       Php " << invoicePostTotal                                << endl << endl;
    }
    else {
        // Cash mode of payment
        cout << "   Mode of Payment"                                                                        << endl
             << "       Payment via:       " << invoice.paymentMode                                 << endl << endl;
        cout << "   Misc."                                                                                  << endl
             << "       Insurance:         Php " << invoiceInsurance                                << endl << endl;
        cout << "   Summary"                                                                                << endl
             << "       Pre-total:         Php " << invoicePreTotal                                         << endl
             << "       Tax:               Php " << invoiceTax                                              << endl
             << "       Final Total:       Php " << invoicePostTotal                                << endl << endl;
    }


    // System Closing
    /*
     * We ask the user if in case they want to rent another type of truck before returning the program
     */
    char userInput;
    cout << "Would you like to rent another truck? (Y/N) ";
    cin >> userInput;
    if (userInput == 'Y' || userInput == 'y') {
        // Recursive call to main()
        main();

        /*
         * Just in case it failed to call main()
         * return the program to end as we do not want a non-ending recursive call to main().
         */
        return 0;
    }
    else {
        // System Closing Message
        cout << endl << "Thank you for renting at [Truck Rental System]!" << endl;
    }


    // Never forget to return the program for safety
    return 0;
}
