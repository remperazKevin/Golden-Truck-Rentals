//
//  main.cpp
//  Golden Truck Rentals	
//

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <chrono>
#include <ctime>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T>
void shorten(T &pTgtStr, char* pChToRem) {
    for (int i(0); i < strlen(pChToRem); i++)
        pTgtStr.erase(remove(pTgtStr.begin(), pTgtStr.end(), pChToRem[i]), pTgtStr.end());
}
template <typename T>
void trim_newline(T &pTgtStr) {
    pTgtStr.erase(remove(pTgtStr.begin(), pTgtStr.end(), '\n'), pTgtStr.cend());
}
template <typename T>
T check_min_size(string pTgt, size_t pLenSz) {
    try {
        if (strlen(pTgt.c_str()) < pLenSz)
            throw runtime_error("Must be at least " + to_string(pLenSz) + " characters");
    }
    catch (runtime_error error) {
        string errorMessage("[Error: ]\n");
        puts(errorMessage.insert(8, error.what()).c_str());
        return "";
    }
    
    return pTgt;
}
template <typename T>
T check_max_size(string pTgt, size_t pLenSz) {
    try {
        if (strlen(pTgt.c_str()) > pLenSz)
            throw runtime_error("Must be at least " + to_string(pLenSz) + " characters");
    }
    catch (runtime_error error) {
        string errorMessage("[Error: ]\n");
        puts(errorMessage.insert(8, error.what()).c_str());
        return "";
    }
    
    return pTgt;
}
template <typename T>
T check_min_max_size(string pTgt, size_t pMin, size_t pMax) {
    try {
        if (strlen(pTgt.c_str()) < pMin)
            throw runtime_error("Must be at least " + to_string(pMin) + " characters");
        if (strlen(pTgt.c_str()) > pMax)
            throw runtime_error("Must be at least " + to_string(pMax) + " characters");
    }
    catch (runtime_error error) {
        string errorMessage("[Error: ]\n");
        puts(errorMessage.insert(8, error.what()).c_str());
        return "";
    }
    
    return pTgt;
}
template <typename T>
T check_min_max(string pTgt, int pMin, int pMax) {
    try {
        int tmpTgt = stoi(pTgt);
        if (tmpTgt == 0)
            throw runtime_error("Can not be zero");
        if (tmpTgt < pMin)
            throw runtime_error("Can not be less than " + to_string(pMin) + " days");
        if (tmpTgt > pMax)
            throw runtime_error("Can not be more than " + to_string(pMax) + " days");
    }
    catch (invalid_argument error) {
        string errorMessage("[Error: ]\n");
        puts(errorMessage.insert(8, "Digits only").c_str());
        return NULL;
    }
    catch (runtime_error error) {
        string errorMessage("[Error: ]\n");
        puts(errorMessage.insert(8, error.what()).c_str());
        return NULL;
    }
    
    return stoi(pTgt);
}
template <typename T>
void prompt_input(string pPrmpt, T* pRVal) {
    try {
        size_t sz = pPrmpt.size() + 1024;
        char buf[sz];
        size_t rVal = sz;
        size_t bufSz = sz;
        rVal = snprintf(buf, rVal, "%s:", pPrmpt.c_str());
        if (rVal > 0 && rVal < bufSz)
            puts(buf);
        else
            throw runtime_error("Error writing to buffer");
        char tmpIO[0];
        fgets(tmpIO, 1024, stdin);
        fflush(stdin);
        string toRetStr = tmpIO;
        if (toRetStr.empty() || iscntrl(tmpIO[0]))
            throw runtime_error("Can not be empty");
        *pRVal = tmpIO;
    }
    catch (const runtime_error error) {
        string errorMessage("[Error: ]\n");
        puts(errorMessage.insert(8, error.what()).c_str());
    }
}
template <typename T>
void print_vector(string pTit, vector<string> pCtnr, T* pRVal, size_t pSz) {
    string strTit("\t[Select ]");
    puts(strTit.insert(9, pTit).c_str());
    try {
        for (int i(0); i < pCtnr.size(); i++) {
            char buf[pSz];
            size_t rVal = pSz;
            size_t bufSz = pSz;
            rVal = snprintf(buf, rVal, "\t%02.2d\t%s", i + 1, pCtnr.at(i).c_str());
            if (rVal > 0 && rVal < bufSz)
                puts(buf);
            else
                throw runtime_error("Error writing to buffer");
        }
        string tmpIO;
        prompt_input<string>("Enter selection below", &tmpIO);
        if (tmpIO.empty() || iscntrl(tmpIO[0]))
            return;
        int intIO = stoi(tmpIO);
        if (intIO == 0)
            throw runtime_error("Cannot be zero");
        string trkSel(pCtnr.at(intIO - 1));
        *pRVal = trkSel;
    }
    catch (invalid_argument error) {
        string errorMessage("[Error: ]\n");
        puts(errorMessage.insert(8, "Digits only").c_str());
    }
    catch (out_of_range error) {
        string errorMessage("[Error: ]\n");
        puts(errorMessage.insert(8, "Out of range").c_str());
    }
    catch (runtime_error error) {
        string errorMessage("[Error: ]\n");
        puts(errorMessage.insert(8, error.what()).c_str());
    }
}

class Account {
public:
    string getCategory() {
        return _mCat;
    }
    string getPrice() {
        return _mPx;
    }
    string getDays() {
        return _mDays;
    }
    string getBranchLocation() {
        return _mBrLoc;
    }
    string getPayment() {
        return _mPmt;
    }
    string getCardNumber() {
        return _mCardNum;
    }
    string getCardExpiry() {
        return _mCardExp;
    }
    string getCardCVV() {
        return _mCardCVV;
    }
    string getName() {
        return _mName;
    }
    string getAddress() {
        return _mAddr;
    }
    string getNumber() {
        return _mNum;
    }
    string getEmail() {
        return _mEmail;
    }
    
    void setCategory(const string &pSetVal) {
        _mCat.assign(pSetVal);
    }
    void setPrice(const string &pSetVal) {
        _mPx = pSetVal;
    }
    void setDays(const string &pSetVal) {
        _mDays = pSetVal;
    }
    void setBranchLocation(const string &pSetVal) {
        _mBrLoc.assign(pSetVal);;
    }
    void setPayment(const string &pSetVal) {
        _mPmt.assign(pSetVal);
    }
    void setCardNumber(const string &pSetVal) {
        _mCardNum.assign(pSetVal);
    }
    void setCardExpiry(const string &pSetVal) {
        _mCardExp.assign(pSetVal);
    }
    void setCardCVV(const string &pSetVal) {
        _mCardCVV.assign(pSetVal);
    }
    void setName(const string &pSetVal) {
        _mName.assign(pSetVal);
    }
    void setAddress(const string &pSetVal) {
        _mAddr.assign(pSetVal);
    }
    void setNumber(const string &pSetVal) {
        _mNum.assign(pSetVal);
    }
    void setEmail(const string &pSetVal) {
        _mEmail.assign(pSetVal);
    }
private:
    string _mCat;
    string _mPx;
    string _mDays;
    string _mBrLoc;
    string _mPmt;
    string _mCardNum;
    string _mCardExp;
    string _mCardCVV;
    string _mName;
    string _mAddr;
    string _mNum;
    string _mEmail;
};
class Truck {
public:
    vector<string> getCategory() {
        return _mTrkCat;
    }
private:
    vector<string> _mTrkCat {
        "Php 5500 - Box Truck",
        "Php 6000 - White Van",
        "Php 6500 - Medium Duty Truck",
        "Php 7000 - Medium Standard Truck",
        "Php 7500 - Platform Truck",
        "Php 8000 - Flatbed Truck",
    };
};
class Location {
public:
    vector<string> getBranchLocation() {
        return _mBrLoc;
    }
private:
    vector<string> _mBrLoc {
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
};
class Payment {
public:
    vector<string> getPayment() {
        return _mPmtType;
    }
private:
    vector<string> _mPmtType {
        "Cash",
        "MasterCard",
        "Visa",
    };
};
class System {
public:
    const void system_opening() {
        puts("Welcome to Golden Truck Rentals\n");
    };
    const void system_ordering() {
        do {
            print_vector<string>("Category", truck.getCategory(), &tmpInput, 64);
            if (tmpInput.empty()) {
                system_ordering();
                break;
            }
            trim_newline<string>(tmpInput);
            char chToRem[] = " -";
            shorten<string>(tmpInput, chToRem);
            tmpInput = tmpInput.substr(3);
            int trkPx;
            char trkCat[32];
            sscanf(tmpInput.c_str(), "%i%s", &trkPx, trkCat);
            tmpInput.clear();
            account.setCategory(trkCat);
            account.setPrice(to_string(trkPx));
        }
        while (account.getCategory().empty() && account.getPrice().empty());
        puts("");
        do {
            prompt_input<string>("Enter amount of days to rent", &tmpInput);
            if (tmpInput.empty()) {
                system_ordering();
                continue;
            }
            trim_newline<string>(tmpInput);
            int days = check_min_max<int>(tmpInput, 7, 30);
            tmpInput.clear();
            if (days)
                account.setDays(to_string(days));
        }
        while (account.getDays().empty());
        puts("");
        do {
            print_vector<string>("Branch Location", location.getBranchLocation(), &tmpInput, 64);
            if (tmpInput.empty()) {
                system_ordering();
                continue;
            }
            trim_newline<string>(tmpInput);
            char chToRem[] = " ";
            shorten<string>(tmpInput, chToRem);
            string brLoc = tmpInput;
            tmpInput.clear();
            account.setBranchLocation(brLoc);
        }
        while (account.getBranchLocation().empty());
        puts("");
    };
    const void system_payment() {
        do {
            print_vector<string>("Payment", payment.getPayment(), &tmpInput, 16);
            if (tmpInput.empty()) {
                system_payment();
                continue;
            }
            trim_newline<string>(tmpInput);
            account.setPayment(tmpInput);
        }
        while (account.getPayment().empty());
        if (account.getPayment().find("MasterCard") != string::npos || account.getPayment().find("Visa") != string::npos) {
            do {
                prompt_input<string>("Enter card number", &tmpInput);
                if (tmpInput.empty()) {
                    system_payment();
                    continue;
                }
                trim_newline<string>(tmpInput);
                string cardNum = check_min_max_size<string>(tmpInput, 16, 19);
                tmpInput.clear();
                account.setCardNumber(cardNum);
            }
            while (account.getCardNumber().empty());
            do {
                prompt_input<string>("Enter card expiry (mm/yy)", &tmpInput);
                if (tmpInput.empty()) {
                    system_payment();
                    continue;
                }
                trim_newline<string>(tmpInput);
                try {
                    if (tmpInput.find('/') != string::npos){
                        time_t tmpT = time(nullptr);
                        tm *const pTInfo = localtime(&tmpT);
                        int currMnth = 1 + pTInfo->tm_mon;
                        int currYr = pTInfo->tm_year - 100;
                        int tmpMnth(0);
                        int tmpYr(0);
                        sscanf(tmpInput.c_str(), "%i/%i", &tmpMnth, &tmpYr);
                        if (!tmpMnth || !tmpYr)
                            throw runtime_error("Invalid Format");
                        if (tmpYr < currYr)
                            throw runtime_error("Expired card");
                        if (tmpYr == currYr)
                            if (tmpMnth < currMnth)
                                throw runtime_error("Expired card");
                        if (tmpMnth > 12)
                            throw runtime_error("Invalid Format");
                    }
                    else {
                        throw runtime_error("Invalid format");
                    }
                }
                catch (runtime_error error) {
                    string errorMessage("[Error: ]\n");
                    puts(errorMessage.insert(8, error.what()).c_str());
                    continue;
                }
                string cardExp = tmpInput;
                tmpInput.clear();
                account.setCardExpiry(cardExp);
            }
            while (account.getCardExpiry().empty());
            do {
                prompt_input<string>("Enter card CVV", &tmpInput);
                if (tmpInput.empty()) {
                    system_payment();
                    continue;
                }
                trim_newline<string>(tmpInput);
                string cardCVV = check_min_max_size<string>(tmpInput, 3, 3);
                tmpInput.clear();
                account.setCardCVV(cardCVV);
            }
            while (account.getCardCVV().empty());
        }
        puts("");
    };
    const void system_customer() {
        do {
            prompt_input<string>("Enter full name", &tmpInput);
            if (tmpInput.empty()) {
                system_customer();
                continue;
            }
            trim_newline<string>(tmpInput);
            string custName = check_min_size<string>(tmpInput, 2);
            tmpInput.clear();
            account.setName(custName);
        }
        while (account.getName().empty());
        do {
            prompt_input<string>("Enter full address", &tmpInput);
            if (tmpInput.empty()) {
                system_customer();
                continue;
            }
            trim_newline<string>(tmpInput);
            string custAddres = check_min_size<string>(tmpInput, 20);
            tmpInput.clear();
            account.setAddress(custAddres);
        }
        while (account.getAddress().empty());
        do {
            prompt_input<string>("Enter phone number", &tmpInput);
            if (tmpInput.empty()) {
                system_customer();
                continue;
            }
            trim_newline<string>(tmpInput);
            string custNumber = check_min_max_size<string>(tmpInput, 11, 11);
            tmpInput.clear();
            account.setNumber(custNumber);
        }
        while (account.getNumber().empty());
        do {
            prompt_input<string>("Enter working email", &tmpInput);
            if (tmpInput.empty()) {
                system_customer();
                continue;
            }
            trim_newline<string>(tmpInput);
            string custEmail = check_min_size<string>(tmpInput, 7);
            tmpInput.clear();
            account.setEmail(custEmail);
        }
        while (account.getEmail().empty());
    };
    const void system_receipt() {
        puts("");
        printf("Golden Truck Rentals [%s Branch]\n", account.getBranchLocation().c_str());
        puts("");
        printf("Name:\t\t%s\n", account.getName().c_str());
        printf("Address:\t%s\n", account.getAddress().c_str());
        printf("Phone:\t\t%s\n", account.getNumber().c_str());
        printf("Email:\t\t%s\n", account.getEmail().c_str());
        puts("");
        const string days = "(" + account.getDays() + " Days)";
        printf("%-32s%s/day %s\n", account.getCategory().c_str(), account.getPrice().c_str(), days.c_str());
        const int total = stoi(account.getDays()) * stoi(account.getPrice());
        if (account.getPayment().find("Cash") != string::npos) {
            printf("%-31sP%i\n", account.getPayment().c_str(), total);
        }
        if (account.getPayment().find("Mastercard") != string::npos) {
            printf("%s ", account.getPayment().c_str());
            const string hashedCardNumber = "(**" + account.getCardNumber().substr(account.getCardNumber().length() - 2) + ")";
            printf("%-20s", hashedCardNumber.c_str());
            printf("P%i\n", total);
        }
        if (account.getPayment().find("Visa") != string::npos) {
            printf("%s ", account.getPayment().c_str());
            const string hashedCardNumber = "(**" + account.getCardNumber().substr(account.getCardNumber().length() - 2) + ")";
            printf("%-26s", hashedCardNumber.c_str());
            printf("P%i\n", total);
        }
        puts("");
        time_t tempTime = time(0);
        printf("Time:\t\t%s", ctime(&tempTime));
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 9999);
        printf("Trans ID:\t%i\n", dis(gen));
        puts("");
        puts("This serves as your Sales Invoice");
    };
private:
    Account account;
    Truck truck;
    Location location;
    Payment payment;
    string tmpInput;
};

int main() {
    System GoldenTruckRentals;
    GoldenTruckRentals.system_opening();
    GoldenTruckRentals.system_ordering();
    GoldenTruckRentals.system_payment();
    GoldenTruckRentals.system_customer();
    GoldenTruckRentals.system_receipt();
    return 0;
}
