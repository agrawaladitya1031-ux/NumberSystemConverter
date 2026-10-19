
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    int choice;
    string input;
    long long decimal;

    do {
        cout << "\n=== Number System Converter ===\n";
        cout << "1. Binary to Decimal\n";
        cout << "2. Decimal to Binary\n";
        cout << "3. Decimal to Octal\n";
        cout << "4. Decimal to Hexadecimal\n";
        cout << "5. Octal to Decimal\n";
        cout << "6. Hexadecimal to Decimal\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter binary number: ";
                cin >> input;

                if (input.empty() ||
                    input.find_first_not_of("01") != string::npos) {
                    cout << "Invalid binary number.\n";
                    break;
                }

                decimal = 0;
                for (char bit : input) {
                    decimal = decimal * 2 + (bit - '0');
                }
                cout << "Decimal: " << decimal << "\n";
                break;
            }

            case 2: {
                cout << "Enter non-negative decimal number: ";
                cin >> decimal;

                if (decimal < 0) {
                    cout << "Negative numbers are not supported.\n";
                    break;
                }

                if (decimal == 0) {
                    cout << "Binary: 0\n";
                    break;
                }

                string binary;
                while (decimal > 0) {
                    binary = char('0' + decimal % 2) + binary;
                    decimal /= 2;
                }
                cout << "Binary: " << binary << "\n";
                break;
            }

            case 3: {
                cout << "Enter non-negative decimal number: ";
                cin >> decimal;

                if (decimal < 0) {
                    cout << "Negative numbers are not supported.\n";
                    break;
                }

                cout << "Octal: " << oct << decimal << dec << "\n";
                break;
            }

            case 4: {
                cout << "Enter non-negative decimal number: ";
                cin >> decimal;

                if (decimal < 0) {
                    cout << "Negative numbers are not supported.\n";
                    break;
                }

                cout << "Hexadecimal: " << uppercase
                     << hex << decimal << dec << nouppercase << "\n";
                break;
            }

            case 5: {
                cout << "Enter octal number: ";
                cin >> input;

                if (input.empty() ||
                    input.find_first_not_of("01234567") != string::npos) {
                    cout << "Invalid octal number.\n";
                    break;
                }

                decimal = 0;
                for (char digit : input) {
                    decimal = decimal * 8 + (digit - '0');
                }
                cout << "Decimal: " << decimal << "\n";
                break;
            }

            case 6: {
                cout << "Enter hexadecimal number: ";
                cin >> input;

                decimal = 0;
                bool valid = !input.empty();

                for (char ch : input) {
                    int digit;

                    if (ch >= '0' && ch <= '9')
                        digit = ch - '0';
                    else if (ch >= 'A' && ch <= 'F')
                        digit = ch - 'A' + 10;
                    else if (ch >= 'a' && ch <= 'f')
                        digit = ch - 'a' + 10;
                    else {
                        valid = false;
                        break;
                    }

                    decimal = decimal * 16 + digit;
                }

                if (valid)
                    cout << "Decimal: " << decimal << "\n";
                else
                    cout << "Invalid hexadecimal number.\n";
                break;
            }

            case 7:
                cout << "Exiting converter.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
