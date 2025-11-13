#include <iostream>
#include <limits>
using namespace std;

double celsiusToFahrenheit(double c) { return (c * 9 / 5) + 32; }
double fahrenheitToCelsius(double f) { return (f - 32) * 5 / 9; }
double celsiusToKelvin(double c) { return c + 273.15; }
double kelvinToCelsius(double k) { return k - 273.15; }

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int choice;
    double value;

    cout << "=== Temperature Converter ===" << endl;
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "3. Celsius to Kelvin\n";
    cout << "4. Kelvin to Celsius\n";
    cout << "0. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            clearInput();
            continue;
        }

        if (choice == 0) {
            cout << "Exiting program. Stay cool 😎\n";
            break;
        }

        cout << "Enter temperature value: ";
        if (!(cin >> value)) {
            cout << "Invalid input! Please enter a number.\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                cout << value << "°C = " << celsiusToFahrenheit(value) << "°F\n";
                break;
            case 2:
                cout << value << "°F = " << fahrenheitToCelsius(value) << "°C\n";
                break;
            case 3:
                cout << value << "°C = " << celsiusToKelvin(value) << "K\n";
                break;
            case 4:
                cout << value << "K = " << kelvinToCelsius(value) << "°C\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
