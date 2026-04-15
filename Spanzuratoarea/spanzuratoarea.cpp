#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

void printHangman(int errors) {
    const std::string stages[] = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n"
    };

    if (errors < 0) errors = 0;
    if (errors > 6) errors = 6;
    std::cout << stages[errors];
}

int main() {
    // Lista de cuvinte
    std::string cuvinte[] = {"calculator", "programare", "algoritm", "variabila", "functie"};
    int numarCuvinte = 5;

    std::cout << "Bine ai venit la Spanzuratoarea!\n";

    int castigate = 0;
    const int numarRunde = 5;

    for (int runda = 0; runda < numarRunde; ++runda) {
        std::string cuvant = cuvinte[runda % numarCuvinte];
        std::string afisat(cuvant.length(), '_');
        std::string ghicite = "";
        int greseli = 0;
        const int maxGreseli = 6;

        std::cout << "\nRunda " << (runda + 1) << ": Ghiceste cuvantul: " << afisat << "\n";

        while (greseli < maxGreseli && afisat != cuvant) {
            char litera;
            std::cout << "Introdu o litera: ";
            std::cin >> litera;

            // Verifica daca litera a fost deja ghicita
            if (ghicite.find(litera) != std::string::npos) {
                std::cout << "Ai ghicit deja aceasta litera!\n";
                continue;
            }

            ghicite += litera;

            // Verifica daca litera este in cuvant
            bool gasit = false;
            for (size_t i = 0; i < cuvant.length(); ++i) {
                if (cuvant[i] == litera) {
                    afisat[i] = litera;
                    gasit = true;
                }
            }

            if (!gasit) {
                greseli++;
                std::cout << "Litera gresita! Greseli: " << greseli << "/" << maxGreseli << "\n";
                printHangman(greseli);
            } else {
                std::cout << "Litera corecta!\n";
            }

            std::cout << "Cuvant: " << afisat << "\n";
        }

        if (afisat == cuvant) {
            std::cout << "Felicitari! Ai ghicit cuvantul: " << cuvant << "\n";
            castigate++;
        } else {
            std::cout << "Ai pierdut aceasta runda! Cuvantul era: " << cuvant << "\n";
        }
    }

    std::cout << "\nJoc terminat! Ai castigat " << castigate << " din " << numarRunde << " runde.\n";

    return 0;
}