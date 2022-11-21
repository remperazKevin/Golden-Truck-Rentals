// TODO Code Review
// TODO Code Cleanup

#include <iostream>
#include <cmath>

using namespace std;


// Global Variable
char userInput;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
// Truck Selection
struct truckSelection {
    int indexCategory = 0;
    int indexType = 0;

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

    int indexBranch = 0;
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
    int indexPayment = 0;
    int paymentMode = 0;
    string selectedPayment;
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
                    3000,
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
    for (auto & category : truckList) {
        cout << "[" << ++selection.indexCategory << "] " << category[0] << endl;
    }
    cout << "Enter truck category number: ";
    cin >> selection.truckCategory;
    if (selection.truckCategory > selection.indexCategory) {
        cout << "Please only select from the given truck category!";
        return 0;
    }
    else {
        selection.selectedCategory = truckList[--selection.truckCategory][0];
    }
    cout << "You have selected [" << selection.selectedCategory << "]" << endl << endl;

    cout << "[Truck Selection - Truck Type]" << endl;
    cout << "Please select a truck type" << endl;
    for (auto & type : truckList[selection.truckCategory]) {
        if (type == truckList[selection.truckCategory][0] || type == "\u200b") {
            // Skip first element of array
            continue;
        }
        else {
            cout << "[" << ++selection.indexType << "] Php " << truckPrice[selection.truckCategory][selection.indexType] << " - " << type << endl;
        }
    }
    cout << "Enter truck type number: ";
    cin >> selection.truckType;
    if (selection.truckType > selection.indexType) {
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
    for (auto & branch : branchLocations) {
        cout << "[" << ++invoice.indexBranch << "] " << branch << endl;
    }
    cout << "Enter branch number: ";
    cin >> invoice.branchLocation;
    if (invoice.branchLocation > invoice.indexBranch) {
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
    // TODO Add name format

    cout << "Enter customer address: ";
    getline(cin, profile.customerAddress);
    // TODO Add address format

    cout << "Enter customer phone number: ";
    getline(cin, profile.customerPhone);
    // TODO Add number check

    cout << "Enter customer email address: ";
    getline(cin, profile.customerEmail);
    // TODO Add email check

    cout << endl << "[Customer Information Overview]" << endl;
    cout << "Customer Name:          " << profile.customerName << endl;
    cout << "Customer Address:       " << profile.customerAddress << endl;
    cout << "Customer Phone Number:  " << profile.customerPhone << endl;
    cout << "Customer Email Address: " << profile.customerEmail << endl << endl;


    struct paymentInfo payment = paymentInfo();

    cout << "[Billing Section - Mode of Payment]" << endl;
    cout << "Please select a mode of payment" << endl;
    for (auto & mode : paymentModes) {
        cout << "[" << ++payment.indexPayment << "] " << mode << endl;
    }
    cout << "Enter mode of payment number: ";
    cin >> payment.paymentMode;
    if (payment.paymentMode > payment.indexPayment) {
        cout << "Please only select from the given mode of payments!";
        return 0;
    }
    else {
        payment.selectedPayment = paymentModes[--payment.paymentMode];
    }
    cout << "You have selected [" << payment.selectedPayment << "] as mode of payment" << endl << endl;


    // Receipt
    // TODO create random receipt number generator

    double invoiceRentDays  = ((0.1 * sqrt(invoice.rentDays)) / 0.5) * selection.selectedPrice;
    double invoiceInsurance = (40 * (double) selection.selectedPrice) / 100;
    double invoicePreTotal  = selection.selectedPrice + invoiceRentDays + invoiceInsurance;
    double invoiceTax       = invoicePreTotal * 0.10;
    double invoicePostTotal = invoicePreTotal + invoiceTax;

    // Print receipt (invoice, customer invoice, mode of payment)
    cout << "[Truck Rental System - Official Receipt]" << endl;
    cout << "   Order Invoice" << endl
         << "       Truck Selection:   " << selection.selectedCategory << " - " << selection.selectedType << " (Php " << selection.selectedPrice << ")" << endl
         << "       Days to rent:      " << invoice.rentDays << " days (Php " << invoiceRentDays << ")"<< endl
         << "       Branch Location:   " << invoice.selectedBranch << endl << endl;
    cout << "   Customer Info" << endl
         << "       Name:              " << profile.customerName << endl
         << "       Address:           " << profile.customerAddress << endl
         << "       Phone Number:      " << profile.customerPhone << endl
         << "       Email Address:     " << profile.customerEmail << endl << endl;
    cout << "   Mode of Payment" << endl
         << "       Payment via:       " << payment.selectedPayment << endl << endl;
    cout << "   Misc." << endl
         << "       Insurance:         Php " << invoiceInsurance << endl << endl;
    cout << "   Summary" << endl
         << "       Pre-total:         Php " << invoicePreTotal << endl
         << "       Tax:               Php " << invoiceTax << endl
         << "       Final Total:       Php " << invoicePostTotal << endl << endl;


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
