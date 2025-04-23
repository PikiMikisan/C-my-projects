//Grzegorz Piechowski Grupa D1 Semestr II

//Grzegorz Piechowski Grupa D1 Semestr II

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int SIZE = 5;

// Funkcja generuj¹ca unikalne losowe liczby z zakresu 0-9 i zapisuj¹ca je do tablicy loteria
void generateLotteryNumbers(int lottery[], int size) {
    int allNumbers[10];
    // Wype³nienie tablicy liczbami od 0 do 9
    for (int i = 0; i < 10; i++) {
        allNumbers[i] = i;
    }
    // Tasowanie tablicy, aby uzyskaæ losow¹ kolejnoœæ
    random_shuffle(allNumbers, allNumbers + 10);
    // Przepisanie pierwszych 'size' liczb do tablicy loteria
    for (int i = 0; i < size; i++) {
        lottery[i] = allNumbers[i];
    }
}

// Funkcja pobieraj¹ca od u¿ytkownika 'size' liczb i zapisuj¹ca je do tablicy user, bez duplikatów
void getUserNumbers(int user[], int size) {
    cout << "Podaj " << size << " liczb (od 0 do 9), bez powtarzania:" << endl;
    for (int i = 0; i < size; i++) {
        int num;
        bool duplicate;
        do {
            duplicate = false;
            cout << "Podaj liczbe #" << (i + 1) << ": ";
            cin >> num;

            // Sprawdzenie, czy liczba jest w zakresie 0-9
            if (num < 0 || num > 9) {
                cout << "Blad: liczba musi byc z zakresu 0-9. Wprowadz ponownie." << endl;
                duplicate = true; // wymusza ponowne pobranie liczby
                continue;
            }

            // Sprawdzenie, czy liczba ju¿ zosta³a podana
            for (int j = 0; j < i; j++) {
                if (user[j] == num) {
                    cout << "Blad: Ta liczba juz zostala podana. Wprowadz inna liczbe." << endl;
                    duplicate = true;
                    break;
                }
            }
        } while (duplicate);

        user[i] = num;
    }
}

// Funkcja porównuj¹ca elementy obu tablic i zliczaj¹ca zgodne liczby
int countMatches(int lottery[], int user[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (lottery[i] == user[i]) {
            count++;
        }
    }
    return count;
}

// Funkcja wyœwietlaj¹ca zawartoœæ tablicy loteria
void displayLotteryNumbers(int lottery[], int size) {
    cout << "\nTablica loteria:     ";
    for (int i = 0; i < size; i++) {
        cout << lottery[i] << " ";
    }
    cout << endl;
}

// Funkcja wyœwietlaj¹ca zawartoœæ tablicy u¿ytkownika
void displayUserNumbers(int user[], int size) {
    cout << "\nTablica uzytkownika: ";
    for (int i = 0; i < size; i++) {
        cout << user[i] << " ";
    }
}

int main() {
    char choice;
    int test = 1;

    // Inicjalizacja generatora liczb losowych (tylko raz, na pocz¹tku)
    srand(time(NULL));

    do {
        int lottery[SIZE];
        int user[SIZE];

        // Generowanie unikalnych liczb dla loterii
        generateLotteryNumbers(lottery, SIZE);

        // Pobranie liczb od u¿ytkownika (bez duplikatów!)
        getUserNumbers(user, SIZE);
        cout << "Proba: " << test << endl;

        // Zliczenie trafieñ
        int matchCount = countMatches(lottery, user, SIZE);

        // Wyœwietlenie liczb u¿ytkownika
        displayUserNumbers(user, SIZE);

        // Wyœwietlenie wyników
        displayLotteryNumbers(lottery, SIZE);
        cout << "Liczba zgodnych cyfr: " << matchCount << endl;

        // Sprawdzenie, czy u¿ytkownik trafi³ odpowiedni¹ liczbê
        if (matchCount == SIZE) {
            cout << "Gratulacje! Wygrales glowna nagrode - szczupaka w BBQ!" << endl;
        }
        else if (matchCount == SIZE - 2) {
            cout << "Gratulacje! Wygrales druga nagrode - zestaw do grillowania bez grilla gdybys kiedys wygral nagrode za 1 miejsce!" << endl;
        }
        else if (matchCount == SIZE - 3) {
            cout << "Gratulacje! Wygrales trzecia nagrode - zestaw przypraw z przecen!" << endl;
        }
        else {
            cout << "Niestety, nie wygrales. Sprobuj ponownie!" << endl;
        }

        // Zapytanie u¿ytkownika, czy chce spróbowaæ ponownie
        cout << "\nCzy chcesz sprobowac ponownie? (t/n): ";
        cin >> choice;
        cout << endl;

        if (choice == 't' || choice == 'T') {
            test++;
            cout << "Proba: " << test << endl;
        }

    } while (choice == 't' || choice == 'T');

    return 0;
}
// Koniec programu
