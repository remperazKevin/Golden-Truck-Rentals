//
//  main.cpp
//  Golden Truck Rentals	
//

#include <cctype>
#include <ctime>
#include <iostream>
#include <fstream>

bool is_number(char pSrc[]) {
    bool boolRetVal = false;
    for (int i = 0; i < strlen(pSrc); i++) {
        if (iscntrl(pSrc[i])) {
            break;
        }
        else if (isdigit(pSrc[i])) {
            boolRetVal = true;
        }
    }
    return boolRetVal;
};

bool is_valid_input(char pSrc[]) {
    bool boolRetVal = false;
    for (int i = 0; i < strlen(pSrc); i++) {
        if (iscntrl(pSrc[i])) {
            break;
        }
        else if (isprint(pSrc[i])) {
            boolRetVal = true;
        }
    }
    return boolRetVal;
};

std::string get_time() {
    time_t tt;
    struct tm* ti;
    time(&tt);
    ti = localtime(&tt);
    return asctime(ti);
};

// Store Class
class Store {
public:
    Store() {
        puts("\n[Step 1 of 5 - Store Location]");
        store();
    };
    std::string get() {
        return _mStoLoc[stoi(mStoLoc)-1];
    };
private:
    void store() {
        puts("\t[Select Store Location]");
        displayStoreLocations();
        puts("Enter selection:");
        std::cin.getline(tmp, 3);
        if (is_number(tmp)) {
            std::string tmpStr = tmp;
            if (stoi(tmpStr) > 0 && stoi(tmpStr) <= 17) {
                set(tmp);
            } else {
                store();
                return;
            }
        }
        else {
            store();
            return;
        }
    };
    char tmp[3];
    std::string mStoLoc;
    std::string _mStoLoc[17] {
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
    void displayStoreLocations() {
        int i = 0;
        for (std::string loc : _mStoLoc) {
            printf("\t%02.2i\t%s\n", i+1, loc.c_str());
            i++;
        }
    };
    void set(std::string pVal) {
        mStoLoc = pVal;
    };
};

// Truck Selection Class
class Selection {
public:
    Selection() {
        puts("\n[Step 2 of 5 - Truck Selection]");
        selection();
    };
    std::string get() {
        return _mTrkSel[stoi(mTrkSel)-1];
    };
    int getTruckPrice() {
        return _mTrkSelPr[stoi(mTrkSel)-1];
    };
    int getTruckDays() {
        return stoi(mTrkDays);
    };
private:
    void selection() {
        if (mTrkSel.empty()) {
            puts("\t[Select Truck Type]");
            displayTruckTypes();
            puts("Enter selection:");
            std::cin.getline(tmp, 2);
            if (is_number(tmp)) {
                std::string tmpStr = tmp;
                if (stoi(tmpStr) > 0 && stoi(tmpStr) <= 6) {
                    set(tmp);
                } else {
                    selection();
                    return;
                }
            }
            else {
                selection();
                return;
            }
        }
        
        // Days
        puts("Enter number of days to rent: [Maximum of 30 Days]");
        std::cin.getline(tmp, 3);
        if (is_number(tmp)) {
            std::string tmpStr = tmp;
            if (stoi(tmpStr) > 0 && stoi(tmpStr) <= 30) {
                setDays(tmp);
            } else {
                selection();
                return;
            }
        }
        else {
            selection();
            return;
        }
    };
    char tmp[3];
    std::string mTrkSel;
    std::string _mTrkSel[6] {
        "Box Truck",
        "White Van",
        "Medium Duty Truck",
        "Medium Standard Truck",
        "Platform Truck",
        "Flatbed Truck",
    };
    int _mTrkSelPr[6] {
        5500,
        6000,
        6500,
        7000,
        7500,
        8000,
    };
    void displayTruckTypes() {
        int i = 0;
        for (std::string sel : _mTrkSel) {
            printf("\t%02.2i\t%-23s(Php %i)\n", i+1, sel.c_str(), _mTrkSelPr[i]);
            i++;
        }
    };
    void set(std::string pVal) {
        mTrkSel = pVal;
    };
    std::string mTrkDays;
    void setDays(std::string pVal) {
        mTrkDays = pVal;
    };
};

// Billing Class
class Billing {
public:
    Billing() {
        puts("\n[Step 3 of 5 - Billing]");
        billing();
    };
    
    // Customer
    std::string getCustomerName() {
        return _mName;
    }
    std::string getCustomerAddress() {
        return _mAddr;
    }
    std::string getCustomerEmail() {
        return _mEmail;
    }
    
    // Payment
    std::string getPaymentType() {
        return _mPmtType[stoi(_mPmt)-1];
    }
    std::string getCardNumber() {
        return _mCardNum;
    }
    std::string getCardExpiry() {
        return _mCardExp;
    }
    std::string getCardCVV() {
        return _mCardCVV;
    }
private:
    void billing() {
        // Customer
        if (_mName.empty()) {
            prompt("Enter customer name:", &_mName);
        }
        if (_mAddr.empty()) {
            prompt("Enter customer address:", &_mAddr);
        }
        if (_mEmail.empty()) {
            prompt("Enter customer email:", &_mEmail);
        }
        
        //Payment
        if (_mPmt.empty()) {
            puts("\t[Select Payment Method]");
            displayPaymentTypes();
            puts("Enter selection:");
            std::cin.getline(tmp, 33);
            if (is_number(tmp)) {
                std::string tmpStr = tmp;
                if (stoi(tmpStr) > 0 && stoi(tmpStr) <= 4) {
                    _mPmt = tmp;
                } else {
                    billing();
                    return;
                }
            }
            else {
                billing();
                return;
            }
        }
        if (stoi(_mPmt) > 1 && !_mPmt.empty()) {
            if (_mCardNum.empty()) {
                puts("Enter card number:");
                std::cin.getline(tmp, 20);
                if (is_number(tmp)) {
                    _mCardNum = tmp;
                }
                else {
                    billing();
                    return;
                }
            }
            if (_mCardExp.empty()) {
                puts("Enter card expiry: [mm/yy]");
                std::cin.getline(tmp, 6);
                std::string tmpStr = tmp;
                if (tmpStr.find('/') != std::string::npos) {
                    time_t tmpT = time(nullptr);
                    tm *const pTInfo = localtime(&tmpT);
                    int currMnth = 1 + pTInfo->tm_mon;
                    int currYr = pTInfo->tm_year - 100;

                    int tmpMnth(0);
                    int tmpYr(0);
                    sscanf(tmpStr.c_str(), "%i/%i", &tmpMnth, &tmpYr);
                    
                    if (!tmpMnth || !tmpYr) {
                        puts("-Invalid Format-");
                        billing();
                        return;
                    }
                    if (tmpYr < currYr) {
                        puts("-Expired card-");
                        billing();
                        return;
                    }
                    if (tmpYr == currYr) {
                        if (tmpMnth < currMnth) {
                            puts("-Expired card-");
                            billing();
                            return;
                        }
                    }
                    if (tmpMnth > 12) {
                        puts("-Invalid Format-");
                        billing();
                        return;
                    }
                    _mCardExp = tmpStr;
                }
                else {
                    puts("-Invalid format-");
                    billing();
                    return;
                }
            }
            if (_mCardCVV.empty()) {
                puts("Enter card CVV:");
                std::cin.getline(tmp, 4);
                if (is_number(tmp)) {
                    _mCardCVV = tmp;
                }
                else {
                    billing();
                    return;
                }
            }
        }
    };
    char tmp[65];
    // Customer
    std::string _mName;
    std::string _mAddr;
    std::string _mEmail;
    // Payment
    std::string _mPmt;
    std::string _mCardNum;
    std::string _mCardExp;
    std::string _mCardCVV;
    std::string _mPmtType[4] {
        "Cash",
        "PayPal",
        "MasterCard",
        "Visa",
    };
    void displayPaymentTypes() {
        int i = 0;
        for (std::string pmt : _mPmtType) {
            printf("\t%02.2i\t%s\n", i+1, pmt.c_str());
            i++;
        }
    };
    void prompt(std::string pPrmpt, std::string* pSrcStr) {
        puts(pPrmpt.c_str());
        std::cin.getline(tmp, 65);  // 64
        if (is_valid_input(tmp)) {
            *pSrcStr = tmp;
        }
        else {
            billing();
            return;
        }
    };
};

int main() {
    puts("[Golden Truck Rentals]");
    Store store;
    Selection selection;
    Billing billing;
    
    puts("\n[Step 4 of 5 - Receipt]");
    printf("Golden Truck Rentals - %s Branch\n", store.get().c_str());
    printf("%s\n", get_time().c_str());
    printf("\tPhp %-8i%2.2i Days    %s\n", selection.getTruckPrice(), selection.getTruckDays(), selection.get().c_str());
    int total = selection.getTruckPrice() * selection.getTruckDays();
    if (billing.getPaymentType() != "Cash") {
        int cardFee = (0.02) * total;
        printf("\tPhp %-19iCard Fee\n", cardFee);
        total += cardFee;
    }
    printf("\tPhp %i\n", total);
    puts("");
    printf("Name:\t\t\t%s\n", billing.getCustomerName().c_str());
    printf("Address:\t\t%s\n", billing.getCustomerAddress().c_str());
    printf("Email:\t\t\t%s\n", billing.getCustomerEmail().c_str());
    puts("");
    printf("Payment:\t\t%s\n", billing.getPaymentType().c_str());
    if (billing.getPaymentType() != "Cash") {
        std::string hashedCardNumber = "**" + billing.getCardNumber().substr(billing.getCardNumber().length() - 2) + "";
        printf("Card Number:\t%s\n", hashedCardNumber.c_str());
        printf("Card Expiry:\t%s\n", billing.getCardExpiry().c_str());
    }
    
    puts("\n[Step 5 of 5 - Closing]");
    puts("Thank you for patronage at Golden Truck Rentals!");
    
    return 0;
}
