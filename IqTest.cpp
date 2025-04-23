#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Question {
    string question;
    string options[4];
    char correctAnswer;
};

int main() {
    vector<Question> questions = {
        // Pytania logiczne
        {"1. Co dalej w ciągu: 2, 4, 8, 16, ?", {"A) 18", "B) 24", "C) 32", "D) 20"}, 'C'},
        {"2. Jeśli dzisiaj jest wtorek, to pojutrze będzie:", {"A) środa", "B) czwartek", "C) piątek", "D) sobota"}, 'B'},
        {"3. Które słowo nie pasuje: jabłko, gruszka, śliwka, marchewka?", {"A) jabłko", "B) gruszka", "C) marchewka", "D) śliwka"}, 'C'},
        {"4. Jakie jest przeciwieństwo słowa 'trudny'?", {"A) zły", "B) prosty", "C) mocny", "D) krótki"}, 'B'},
        {"5. Co ma więcej nóg: pająk czy kot?", {"A) pająk", "B) kot", "C) tyle samo", "D) zależy"}, 'A'},

        // Matematyczne
        {"6. Ile to 7 * 6?", {"A) 36", "B) 42", "C) 48", "D) 56"}, 'B'},
        {"7. Jaka liczba jest większa: 0.9 czy 0.89?", {"A) 0.89", "B) są równe", "C) 0.9", "D) 0"}, 'C'},
        {"8. Jeśli mama ma 3 dzieci, każde ma po 2 jabłka, ile mają razem?", {"A) 6", "B) 8", "C) 5", "D) 3"}, 'A'},
        {"9. Ile wynosi pierwiastek z 49?", {"A) 6", "B) 8", "C) 7", "D) 9"}, 'C'},
        {"10. Która liczba jest nieparzysta?", {"A) 22", "B) 14", "C) 7", "D) 28"}, 'C'},

        // Pamięć i sekwencje
        {"11. Zapamiętaj: 3, 6, 1. Jaka była druga liczba?", {"A) 1", "B) 3", "C) 6", "D) 9"}, 'C'},
        {"12. Która litera jest czwarta w słowie 'psychologia'?", {"A) c", "B) h", "C) o", "D) s"}, 'D'},
        {"13. Jeśli dodasz 10 do 15 i odejmiesz 5, otrzymasz?", {"A) 20", "B) 15", "C) 25", "D) 18"}, 'A'},
        {"14. Co nie pasuje: czerwony, zielony, niebieski, kwadrat?", {"A) czerwony", "B) zielony", "C) niebieski", "D) kwadrat"}, 'D'},
        {"15. Przeciwieństwo: 'szybki'", {"A) wolny", "B) duży", "C) nowy", "D) mały"}, 'A'},

        // Skojarzenia i abstrakcja
        {"16. Co wspólnego mają pociąg i samolot?", {"A) latają", "B) przewożą ludzi", "C) mają koła", "D) są niebieskie"}, 'B'},
        {"17. Co pasuje: 1, 4, 9, 16, ?", {"A) 20", "B) 25", "C) 36", "D) 18"}, 'B'},
        {"18. Ile dni ma tydzień?", {"A) 6", "B) 7", "C) 5", "D) 8"}, 'B'},
        {"19. Która godzina po 23:00?", {"A) 0:00", "B) 1:00", "C) 24:00", "D) 22:00"}, 'A'},
        {"20. Jeśli alfabet zaczyna się od A, B, C... to jaka jest 5. litera?", {"A) D", "B) E", "C) F", "D) G"}, 'B'},

        // Dodatkowe
        {"21. Co jest cięższe: kilogram żelaza czy kilogram pierza?", {"A) żelazo", "B) pierze", "C) tyle samo", "D) zależy"}, 'C'},
        {"22. Jakie zwierzę miauczy?", {"A) pies", "B) kot", "C) koń", "D) mysz"}, 'B'},
        {"23. Która planeta jest najbliżej Słońca?", {"A) Wenus", "B) Ziemia", "C) Mars", "D) Merkury"}, 'D'},
        {"24. Które zwierzę to ssak?", {"A) kura", "B) żaba", "C) delfin", "D) ryba"}, 'C'},
        {"25. W jakim kraju leży Paryż?", {"A) Niemcy", "B) Włochy", "C) Francja", "D) Hiszpania"}, 'C'},
        {"26. Co pasuje: zimny – ciepły, czarny – biały, szybki – ?", {"A) duży", "B) wolny", "C) krótki", "D) nowy"}, 'B'},
        {"27. Który kształt ma 3 boki?", {"A) kwadrat", "B) trójkąt", "C) pięciokąt", "D) koło"}, 'B'},
        {"28. Jaka liczba jest mniejsza: 2/3 czy 3/4?", {"A) 2/3", "B) 3/4", "C) są równe", "D) nie wiadomo"}, 'A'},
        {"29. Które z poniższych jest warzywem?", {"A) jabłko", "B) banan", "C) pomidor", "D) winogrono"}, 'C'},
        {"30. Ile to 100 - (10 * 3)?", {"A) 70", "B) 80", "C) 60", "D) 90"}, 'A'}
    };

    int score = 0;
    char answer;

    cout << "==== TEST IQ (wersja demo, 30 pytan) ====\n\n";

    for (int i = 0; i < questions.size(); ++i) {
        cout << questions[i].question << "\n";
        for (int j = 0; j < 4; ++j) {
            cout << questions[i].options[j] << "\n";
        }
        cout << "Twoja odpowiedź (A/B/C/D): ";
        cin >> answer;
        answer = toupper(answer);

        if (answer == questions[i].correctAnswer) {
            cout << "✅ Poprawnie!\n\n";
            score++;
        }
        else {
            cout << "❌ Błędnie. Poprawna: " << questions[i].correctAnswer << "\n\n";
        }
    }

    // Prosty system IQ
    int iq;
    if (score <= 5) iq = 80;
    else if (score <= 10) iq = 90;
    else if (score <= 20) iq = 100;
    else if (score <= 25) iq = 110;
    else if (score <= 28) iq = 120;
    else iq = 130;

    cout << "==== KONIEC TESTU ====\n";
    cout << "Twój wynik: " << score << "/30 punktów\n";
    cout << "Szacowane IQ: " << iq << "\n";

    return 0;
}
