// TODO Code Review
// TODO Code Cleanup

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


// Global Variable
char userInput;

// Ignore CLion complex data-flow analysis
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
// Truck Selection
struct truckSelection {
    int truckCategory = 0;
    int truckType = 0;

    string selectedCategory;
    string selectedType;
    int selectedPrice = 0;
};
#pragma clang diagnostic pop

// Billing Section
struct orderInvoice {
    int rentDays = 0;

    int branchLocation = 0;
    string selectedBranch;
};
struct customerInformation {
    string customerName;
    string customerAddress;
    string customerPhone;
    string customerEmail;
};
struct paymentInfo {
    int paymentMode = 0;
    string selectedPayment;

    string cardNumber;
    int cardExpiryMonth = 0;
    int cardExpiryYear = 0;
    string cardCVV;
};


int main() {
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

    string paymentModes[4] = {
            "Cash",
            "PayPal",
            "MasterCard",
            "Visa",
    };


    // System Welcome Message
    cout << "Welcome to [Truck Rental System]" << endl
         << "   Your number one place for all your truck rental needs!" << endl << endl;


    // Truck Selection
    struct truckSelection selection = truckSelection();

    cout << "[Truck Selection - Truck Category]" << endl;
    cout << "Please select a truck category" << endl;
    int category;
    for (category = 0; category < 5; category++) {
        cout << "[" << category + 1 << "] " << truckList[category][0] << endl;
    }
    cout << "Enter truck category number: ";
    cin >> selection.truckCategory;
    if (selection.truckCategory > category) {
        cout << "Please only select from the given truck category!";
        return 0;
    }
    else {
        selection.selectedCategory = truckList[--selection.truckCategory][0];
    }
    cout << "You have selected [" << selection.selectedCategory << "]" << endl << endl;

    cout << "[Truck Selection - Truck Type]" << endl;
    cout << "Please select a truck type" << endl;
    int type;
    for (type = 0; type < 7; type++) {
        if (type == 0 || truckList[selection.truckCategory][type] == "\u200b") {
            // Skip element of array
            continue;
        }
        else {
            cout << "[" << type << "] Php " << truckPrice[selection.truckCategory][type] << " - " << truckList[selection.truckCategory][type] << endl;
        }
    }
    cout << "Enter truck type number: ";
    cin >> selection.truckType;
    if (selection.truckType > type) {
        cout << "Please only select from the given truck types!";
        return 0;
    }
    else {
        selection.selectedType = truckList[selection.truckCategory][selection.truckType];
        selection.selectedPrice = truckPrice[selection.truckCategory][selection.truckType];
    }
    cout << "You have selected [" << selection.selectedType << "] Php " << selection.selectedPrice << endl << endl;


    // Billing Section
    struct orderInvoice invoice;

    cout << "[Billing Section - Order Invoice]" << endl;
    cout << "Enter number of days to rent: ";
    cin >> invoice.rentDays;
    if (invoice.rentDays < 1) {
        cout << "Minimum days to rent is [1]";
        return 0;
    }
    else {
        cout << "You have chosen to rent for [" << invoice.rentDays << "] days" << endl << endl;
    }

    cout << "[Billing Section - Branch Location]" << endl;
    cout << "Please select a branch near you" << endl;
    int branches;
    for (branches = 0; branches < 17; ++branches) {
        cout << "[" << branches << "] " << branchLocations[branches] << endl;
    }
    cout << "Enter branch number: ";
    cin >> invoice.branchLocation;
    if (invoice.branchLocation > --branches) {
        cout << "Please only select from the given branches!";
        return 0;
    }
    else {
        invoice.selectedBranch = branchLocations[--invoice.branchLocation];
    }
    cout << "You have selected [" << invoice.selectedBranch << "] Branch" << endl << endl;

    // Clean and ignore trailing '\n' newline for the next getline() to work
    cin.ignore(256, '\n');


    struct customerInformation profile;

    cout << "[Billing Section - Customer Information]" << endl;
    cout << "Enter customer full name: ";
    getline(cin, profile.customerName);
    if (profile.customerName.length() < 2) {
        cout << "Please input at least two characters!";
        return 0;
    }

    cout << "Enter customer address: ";
    getline(cin, profile.customerAddress);

    cout << "Enter customer phone number: ";
    getline(cin, profile.customerPhone);
    if (profile.customerPhone.length() < 11) {
        cout << "Please input valid phone number!";
        return 0;
    }

    cout << "Enter customer email address: ";
    getline(cin, profile.customerEmail);

    cout << endl << "[Customer Information Overview]" << endl;
    cout << "Customer Name:          " << profile.customerName << endl;
    cout << "Customer Address:       " << profile.customerAddress << endl;
    cout << "Customer Phone Number:  " << profile.customerPhone << endl;
    cout << "Customer Email Address: " << profile.customerEmail << endl << endl;


    struct paymentInfo payment = paymentInfo();

    cout << "[Billing Section - Mode of Payment]" << endl;
    cout << "Please select a mode of payment (Additional Php 50 fee if non-cash)" << endl;
    int mode;
    for (mode = 0; mode < 4; mode++) {
        cout << "[" << mode + 1 << "] " << paymentModes[mode] << endl;
    }
    cout << "Enter mode of payment number: ";
    cin >> payment.paymentMode;
    if (payment.paymentMode > mode) {
        cout << "Please only select from the given mode of payments!";
        return 0;
    }
    else {
        payment.selectedPayment = paymentModes[--payment.paymentMode];
    }
    cout << "You have selected [" << payment.selectedPayment << "] as mode of payment" << endl << endl;

    // Clean and ignore trailing '\n' newline for the next getline() to work
    cin.ignore(256, '\n');

    cout << "[Mode of Payment - " << payment.selectedPayment << "]" << endl;
    switch (payment.paymentMode) {
        case 0:
            cout << "Please print and present the receipt at your chosen branch to process the payment" << endl << endl;
            break;
        default:
            cout << "Enter card number: (spaces included) ";
            getline(cin, payment.cardNumber);
            if (payment.cardNumber.length() != 19) {
                cout << "Please input the correct card number!";
                return 0;
            }

            cout << "Enter card expiry month: (MM) ";
            cin >> payment.cardExpiryMonth;
            if (payment.cardExpiryMonth < 0 || payment.cardExpiryMonth > 12) {
                cout << "Please input the correct card expiry month!";
                return 0;
            }
            cout << "Enter card expiry year: (YY) ";
            cin >> payment.cardExpiryYear;
            if (payment.cardExpiryYear < 22) {
                cout << "Please input the correct card expiry year!";
                return 0;
            }

            cout << "Enter card CVV: ";
            cin >> payment.cardCVV;
            if (payment.cardCVV.length() != 3) {
                cout << "Please input the correct card CVV!";
                return 0;
            }

            cout << "[" << payment.selectedPayment << " Payment Overview" << endl;
            cout << "Card Number:      ends in " << payment.cardNumber.substr(15, 4) << endl;
            cout << "Card Expiry Date: " << setw(2) << setfill('0') << payment.cardExpiryMonth << "/" << payment.cardExpiryYear << endl;
            cout << "Card CVV:         " << payment.cardCVV << endl << endl;
    }


    // Receipt
    const int MIN_RECEIPT_NUMBER = 111111;
    const int MAX_RECEIPT_NUMBER = 999999;
    // For now we use the old method of creating a random number in between a range
    long int receiptNumber  = MIN_RECEIPT_NUMBER + (rand() % (MAX_RECEIPT_NUMBER - MIN_RECEIPT_NUMBER + 1));

    double invoiceRentDays  = ((0.1 * sqrt(invoice.rentDays)) / 0.5) * selection.selectedPrice;
    double invoiceInsurance = (40 * (double) selection.selectedPrice) / 100;
    const double CARD_FEE   = (payment.paymentMode > 0) ? 50 : 0;
    double invoicePreTotal  = selection.selectedPrice + invoiceRentDays + invoiceInsurance + CARD_FEE;
    double invoiceTax       = invoicePreTotal * 0.10;
    double invoicePostTotal = invoicePreTotal + invoiceTax;

    // Print receipt (invoice, customer invoice, mode of payment)
    cout << "[Truck Rental System - Official Receipt]" << endl;
    cout << "   Order Invoice" << endl
         << "       Receipt Number:    " << receiptNumber << endl
         << "       Truck Selection:   " << selection.selectedCategory << " - " << selection.selectedType << " (Php " << selection.selectedPrice << ")" << endl
         << "       Days to rent:      " << invoice.rentDays << " day/s (Php " << invoiceRentDays << ")"<< endl
         << "       Branch Location:   " << invoice.selectedBranch << endl << endl;
    cout << "   Customer Info" << endl
         << "       Name:              " << profile.customerName << endl
         << "       Address:           " << profile.customerAddress << endl
         << "       Phone Number:      " << profile.customerPhone << endl
         << "       Email Address:     " << profile.customerEmail << endl << endl;
    if (payment.paymentMode > 0) {
        cout << "   Mode of Payment" << endl
             << "       Payment via:       " << payment.selectedPayment << endl
             << "       Card Number:       ends in " << payment.cardNumber.substr(15, 4) << endl
             << "       Card Expiry Date:  " << setw(2) << setfill('0') << payment.cardExpiryMonth << "/" << payment.cardExpiryYear << endl << endl;
        cout << "   Misc." << endl
             << "       Insurance:         Php " << invoiceInsurance << endl
             << "       Card Fee:          Php " << CARD_FEE << endl << endl;
        cout << "   Summary" << endl
             << "       Pre-total:         Php " << invoicePreTotal << endl
             << "       Tax:               Php " << invoiceTax << endl
             << "       Final Total:       Php " << invoicePostTotal << endl << endl;
    }
    else {
        cout << "   Mode of Payment" << endl
             << "       Payment via:       " << payment.selectedPayment << endl << endl;
        cout << "   Misc." << endl
             << "       Insurance:         Php " << invoiceInsurance << endl << endl;
        cout << "   Summary" << endl
             << "       Pre-total:         Php " << invoicePreTotal << endl
             << "       Tax:               Php " << invoiceTax << endl
             << "       Final Total:       Php " << invoicePostTotal << endl << endl;
    }


    // System Closing
    cout << "Would you like to rent another truck? (Y/N) ";
    cin >> userInput;
    if (userInput == 'Y' || userInput == 'y') {
        // Recursive call to main()
        main();

        // Just in case it failed to call main() return the program to end.
        //  We do not want a non-ending recursive call to main()
        return 0;
    }
    else {
        cout << endl << "Thank you for renting at [Truck Rental System]!" << endl;
    }


    // Never forget to return the program for safety
    return 0;
}
