#include <iostream>
#include <string>

using namespace std;

// Struct d? bi?u di?n thông tin v? chuy?n bay
struct Flight {
    string flightNumber;
    double ticketPrice;
    int seatsAvailable;
};

// Hàm hi?n th? danh sách các chuy?n bay du?c ch?n
void showSelectedFlights(const string selectedFlights[], int selectedCount) {
    cout << "Danh sách chuy?n bay du?c ch?n:" << endl;
    for (int i = 0; i < selectedCount; i++) {
        cout << selectedFlights[i] << endl;
    }
}

// Hàm quay lui d? ch?n 4 chuy?n bay t? danh sách b
void chooseFlights(const Flight b[], int bSize, string selectedFlights[], int selectedCount, int currentIndex, int remaining) {
    if (remaining == 0) {
        showSelectedFlights(selectedFlights, selectedCount);
        return;
    }
    
    if (currentIndex >= bSize) {
        return;
    }

    // Ch?n chuy?n bay hi?n t?i
    selectedFlights[selectedCount] = b[currentIndex].flightNumber;
    chooseFlights(b, bSize, selectedFlights, selectedCount + 1, currentIndex + 1, remaining - 1);

    // Không ch?n chuy?n bay hi?n t?i
    chooseFlights(b, bSize, selectedFlights, selectedCount, currentIndex + 1, remaining);
}

int main() {
    Flight b[] = {
        {"VN001", 100.0, 150},
        {"VN002", 150.0, 120},
        {"VN003", 200.0, 100},
        {"VN004", 250.0, 80},
        {"VN005", 300.0, 60},
        {"VN006", 350.0, 40}
    };

    int numberOfFlightsToChoose = 4;
    string selectedFlights[numberOfFlightsToChoose];

    chooseFlights(b, sizeof(b) / sizeof(b[0]), selectedFlights, 0, 0, numberOfFlightsToChoose);

    return 0;
}

