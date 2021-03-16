/*
 Умный калькулятор 2.0. Реализовать калькулятор кредитов, вкладов и конвертер валют из BYN в USD, EUR, RUB и обратно. Приложение должно иметь удобный и понятный интерфейс пользовательского меню
 Подсказки:
 1) процентные ставки с названием кредита или вклада, а так же текущий курс лучше всего выносить в define;
 2) пользовательское меню реализовать через if-else if- else if- else (или switch-case)
 3) дать пользователю возможность работать с программой бесконечное количество раз (бесконечный цикл)
 4) main() должен содержать в идеале только вызовы функций, if-else if- else if- else и цикл while()
 */

#include <iostream>
using namespace std;

#define A_YEAR 12.0
#define MONTH_6 6.0
//#define MONTH_3 3.0
//#define MONTH_1 1.0

#define USD 2.65
#define EUR 3.10
#define RUB 0.35

void printOnConsole(string massage);
void printOnConsole(string massege, double parametr);

double doCreditByn (double a);
double doCreditUsd (double a);
double doCreditEur (double a);
double doCreditRub (double a);

double doDepositByn (double a, double b);
double doDepositUsd (double a, double b);
double doDepositEur (double a, double b);
double doDepositRub (double a, double b);

double doСonversFromBynToUsd (double a);
double doСonversFromBynToEur (double a);
double doСonversFromBynToRub (double a);

int main()
{
    int numTransaction = 0, numCurrOper = 0;
    double numCreditByn = 0.0, numCreditUsd = 0.0, numCreditEur = 0.0, numCreditRub = 0.0;
    double sumDepositByn = 0.0, sumDepositUsd = 0.0, sumDepositEur = 0.0, sumDepositRub = 0.0;
    double month = 0.0;
    double sumCurrToConvert = 0;
    
    printOnConsole("\tThank you for choosing our bank");
    printOnConsole("\nOur bank offers the following services:\n  1. Credits;\n  2. Deposits;\n  3. Converting;");
    printOnConsole("\nPlease select one of the transaction numbers: ");
    cin >> numTransaction;
    
    if (numTransaction < 1 or numTransaction > 3) {
        printOnConsole("Error! You entered the wrong transaction number. Еry to enter again:\n  1. Credits;\n  2. Deposits;\n  3. Converting;\n");
        
        return -1;
    }
    // Credit_operation.
    if (numTransaction == 1) {
        printOnConsole("\n\t1. Credit operation");
        printOnConsole("\nChoose a credit  in currency: 1. BYN; 2. USD; 3. EUR; 4. RUB;");
        printOnConsole("\nEnter the currency operation number: ");
        cin >> numCurrOper;
        
        if (numCurrOper < 1 or numCurrOper > 4) {
            printOnConsole("Error! You entered the wrong currency number. Еry to enter again: 1. BYN; 2. USD; 3. EUR; 4. RUB;");
            
            return -2;
        }
        // Credit_BYN
        if (numCurrOper == 1) {
            printOnConsole("\n\tCredit comfort in BYN rubls. \n\nCredit  rate 11% in a year. \nMaximum credit amount up to 5000 BYN");
            printOnConsole("\nEnter the amount credita in BYN: ");
            cin >> numCreditByn;
            
            if (numCreditByn < 0 or numCreditByn > 5000) {
                printOnConsole("Error! Incorrect credit amount.\nEnter the amount again.\n");
                
                return -3;
            } else {
                printOnConsole("Your credit payment per month will be: ", doCreditByn(numCreditByn));
                printOnConsole(" BYN rubl(s).\n");
            }
        // Credit_USD
        } else if (numCurrOper == 2) {
            printOnConsole("\n\tCredit comfort in USD dollars. \n\nCredit  rate 19.5% in a year. \nMaximum credit amount up to 2000 USD");
            printOnConsole("\nEnter the amount credita in USD: ");
            cin >> numCreditUsd;
            
            if (numCreditUsd < 0 or numCreditUsd > 2000) {
                printOnConsole("Error! Incorrect credit amount.\nEnter the amount again.\n");
                
                return -4;
            } else {
                printOnConsole("Your credit payment per month will be: ", doCreditUsd (numCreditUsd));
                printOnConsole(" USD dollars.\n");
            }
        // Credit_EUR
        } else if (numCurrOper == 3) {
            printOnConsole("\n\tCredit comfort in EUR euro. \n\nCredit  rate 21.5% in a year. \nMaximum credit amount up to 1500 EUR");
            printOnConsole("\nEnter the amount credita in EUR: ");
            cin >> numCreditEur;
            
            if (numCreditEur < 0 or numCreditEur > 1500) {
                printOnConsole("Error! Incorrect credit amount.\nEnter the amount again.\n");
                
                return -5;
            } else {
                printOnConsole("Your credit payment per month will be: ", doCreditEur (numCreditEur));
                printOnConsole(" EUR euro.\n");
            }
        // Credit_RUB
        } else {
            printOnConsole("\n\tCredit comfort in RUB rubls. \n\nCredit  rate 13.5% in a year. \nMaximum credit amount up to 140000 RUB");
            printOnConsole("\nEnter the amount credita in RUB: ");
            cin >> numCreditRub;
            
            if (numCreditRub < 0 or numCreditRub > 140000) {
                printOnConsole("Error! Incorrect credit amount.\nEnter the amount again.\n");
                
                return -6;
            } else {
                printOnConsole("Your credit payment per month will be: ", doCreditRub (numCreditRub));
                printOnConsole(" RUB rubl(s).\n");
            }
        }
    // Deposit_operation.--------------------------------------->
    } else if (numTransaction == 2) {
        printOnConsole("\n\t2. Deposit operation ");
        printOnConsole("\nSelect currency deposit: 1. BYN; 2. USD; 3. EUR; 4. RUB;");
        printOnConsole("\nEnter the currency deposit number: ");
        cin >> numCurrOper;
        
        if (numCurrOper < 1 or numCurrOper > 4) {
            printOnConsole("Error! You entered the wrong currency deposit number. Еry to enter again: 1. BYN; 2. USD; 3. EUR; 4. RUB;");
            
            return -7;
        }
        
        // Deposit_BYN
        if (numCurrOper == 1) {
            printOnConsole("\n\tDeposit in BYN rubls. \n\nDeposit  rate 13.5% in a year.");
            printOnConsole("\nСhoose the term of the deposit in: 6 month; 12 month;");
            printOnConsole("\nEnter the term of the deposit 6 or 12: ");
            cin >> month;
            
            if (month != 6 and month != 12) {
                printOnConsole("Error! The term of the deposit is incorrect.\nEnter the amount again.\n");
                
                return -8;
            } else if (month == 6) {
                printOnConsole("Enter the amount of the deposit in BYN rubles: ");
                cin >> sumDepositByn;
                printOnConsole("The amount of the deposit for 6 months will be: ", doDepositByn (sumDepositByn, month));
                printOnConsole(" BYN rubl(s)\n");
                
            } else if (month == 12) {
                printOnConsole("Enter the amount of the deposit in BYN rubles: ");
                cin >> sumDepositByn;
                printOnConsole("The amount of the deposit for 12 months will be: ", doDepositByn (sumDepositByn, month));
                printOnConsole(" BYN rubl(s)\n");
            }
            // Deposit_USD
        } else if (numCurrOper == 2) {
            printOnConsole("\n\tDeposit in USD dollars. \n\nDeposit  rate 2.5% in a year.");
            printOnConsole("\nСhoose the term of the deposit in: 6 month; 12 month;");
            printOnConsole("\nEnter the term of the deposit 6 or 12: ");
            cin >> month;
            
            if (month != 6 and month != 12) {
                printOnConsole("Error! The term of the deposit is incorrect.\nEnter the amount again.\n");
                
                return -9;
            } else if (month == 6) {
                printOnConsole("Enter the amount of the deposit in USD dollars: ");
                cin >> sumDepositUsd;
                printOnConsole("The amount of the deposit for 6 months will be: ", doDepositUsd (sumDepositUsd, month));
                printOnConsole(" USD dollars\n");
                
            } else if (month == 12) {
                printOnConsole("Enter the amount of the deposit in USD dollars: ");
                cin >> sumDepositUsd;
                printOnConsole("The amount of the deposit for 12 months will be: ", doDepositUsd (sumDepositUsd, month));
                printOnConsole(" USD dollars\n");
            }
            // Deposit_EURO
        } else if (numCurrOper == 3) {
            printOnConsole("\n\tDeposit in EUR euro. \n\nDeposit  rate 1.5% in a year.");
            printOnConsole("\nСhoose the term of the deposit in: 6 month; 12 month;");
            printOnConsole("\nEnter the term of the deposit 6 or 12: ");
            cin >> month;
            
            if (month != 6 and month != 12) {
                printOnConsole("Error! The term of the deposit is incorrect.\nEnter the amount again.\n");
                
                return -10;
            } else if (month == 6) {
                printOnConsole("Enter the amount of the deposit in EUR euro: ");
                cin >> sumDepositEur;
                printOnConsole("The amount of the deposit for 6 months will be: ", doDepositEur (sumDepositEur, month));
                printOnConsole(" EUR euro\n");
                
            } else if (month == 12) {
                printOnConsole("Enter the amount of the deposit in EUR euro: ");
                cin >> sumDepositEur;
                printOnConsole("The amount of the deposit for 12 months will be: ", doDepositEur (sumDepositEur, month));
                printOnConsole(" EUR euro\n");
            }
            // Deposit_RUB
        } else {
            printOnConsole("\n\tDeposit in RUB rubls. \n\nDeposit  rate 4.5% in a year.");
            printOnConsole("\nСhoose the term of the deposit in: 6 month; 12 month;");
            printOnConsole("\nEnter the term of the deposit 6 or 12: ");
            cin >> month;
            
            if (month != 6 and month != 12) {
                printOnConsole("Error! The term of the deposit is incorrect.\nEnter the amount again.\n");
                
                return -11;
            } else if (month == 6) {
                printOnConsole("Enter the amount of the deposit in RUB rubles: ");
                cin >> sumDepositRub;
                printOnConsole("The amount of the deposit for 6 months will be: ", doDepositRub (sumDepositRub, month));
                printOnConsole(" RUB rubl(s)\n");
                
            } else if (month == 12) {
                printOnConsole("Enter the amount of the deposit in RUB rubles: ");
                cin >> sumDepositRub;
                printOnConsole("The amount of the deposit for 12 months will be: ", doDepositRub (sumDepositRub, month));
                printOnConsole(" BYN rubl(s)\n");
            }
        }
            
     //--------------------------------------------------------------------
    // Operation_converting.
    //-----------------------
        //----------------------
            //---------------------
    } else {
        printOnConsole("\n\t3. Currency conversion ");
        printOnConsole("\nSelect currency converting: 1. BYN; 2. USD; 3. EUR; 4. RUB;");
        printOnConsole("\nEnter the currency converting number: ");
        cin >> numCurrOper;
        
        if (numCurrOper < 1 or numCurrOper > 4) {
            printOnConsole("Error! You entered the wrong currency deposit number. Еry to enter again: 1. BYN; 2. USD; 3. EUR; 4. RUB;");
            
            return -12;
        }
        
        // BYN_converting
        if(numCurrOper == 1) {
            printOnConsole("\n\tFirst currency to convert: 1. BYN rubles");
            //cin >> numCurrOper;
            printOnConsole("\n\tEnter the amount in BYN ruble(s): ");
            cin >> sumCurrToConvert;
            printOnConsole("\nSelect second currency to convert: 2. USD; 3. EUR; 4. RUB; ");
            printOnConsole("\nEnter second currency to convert: ");
            cin >> numCurrOper;
            
            if (numCurrOper < 2 or numCurrOper > 4) {
                printOnConsole("Error! You entered the wrong currency deposit number. Еry to enter again: 2. USD; 3. EUR; 4. RUB;");
                
                return -13;
            }
            
            if (numCurrOper == 2) {
                printOnConsole("\n\tCurrency to be converted are: 2. USD dollars");
                printOnConsole("\n\tYour amount are: ", doСonversFromBynToUsd (sumCurrToConvert));
                printOnConsole(" USD dollars\n\n");
                
            }
            
        } // else if ()
        
    
    }
    
    
    
    return 0;
}

// Credits operation.
// BYN
double doCreditByn (double a) {
    return (a * A_YEAR * 0.11) / A_YEAR;
}
// USD
double doCreditUsd (double a) {
    return (a * A_YEAR * 0.195) / A_YEAR;
}
// EUR
double doCreditEur (double a) {
    return (a * A_YEAR * 0.215) / A_YEAR;
}
// RUB
double doCreditRub (double a) {
    return (a * A_YEAR * 0.135) / A_YEAR;
}
    
// Deposit operation
// BYN
double doDepositByn (double a, double b) {
    return a + (a * b * 0.135);
}
// USD
double doDepositUsd (double a, double b) {
    return a + (a * b * 0.025);
}
// EUR
double doDepositEur (double a, double b) {
    return a + (a * b * 0.015);
}
// RUB
double doDepositRub (double a, double b) {
    return a + (a * b * 0.045);
}

// Сonversion_operation
// BYN --> USD
double doСonversFromBynToUsd (double a) {
    return a / USD;
}
// BYN --> EUR
double doСonversFromBynToEur (double a) {
    return a / EUR;
}
// BYN --> RUB
double doСonversFromBynToRub (double a) {
    return a / RUB;
}



void printOnConsole(string massage) {
    cout << massage;
}

void printOnConsole(string massege, double parametr) {
    cout << massege << parametr;
}


