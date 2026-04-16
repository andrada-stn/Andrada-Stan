#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to print the ASCII hangman drawing based on the number of errors
void printHangman(int errors) {
    // Array of strings representing each stage of the hangman (0 to 6 errors)
    const std::string stages[] = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n"
    };

    // Ensure errors is within bounds
    if (errors < 0) errors = 0;
    if (errors > 6) errors = 6;
    // Print the corresponding stage
    std::cout << stages[errors];
}

int main() {
    // List of words for the game
    std::string cuvinte[] = {"calculator", "programare", "algoritm", "variabila", "functie"};
    int numarCuvinte = 5;

    // Welcome message
    std::cout << "Bine ai venit la Spanzuratoarea!\n";

    // Variable to count wins
    int castigate = 0;
    // Number of rounds to play
    const int numarRunde = 5;

    // Loop through each round
    for (int runda = 0; runda < numarRunde; ++runda) {
        // Select the word for this round (cycles through the list)
        std::string cuvant = cuvinte[runda % numarCuvinte];
        // Create a display string with underscores for unguessed letters
        std::string afisat(cuvant.length(), '_');
        // String to keep track of guessed letters
        std::string ghicite = "";
        // Counter for wrong guesses
        int greseli = 0;
        // Maximum allowed wrong guesses
        const int maxGreseli = 6;

        // Display the round number and initial word display
        std::cout << "\nRunda " << (runda + 1) << ": Ghiceste cuvantul: " << afisat << "\n";

        // Main game loop: continue until max errors or word is guessed
        while (greseli < maxGreseli && afisat != cuvant) {
            // Prompt for a letter input
            char litera;
            std::cout << "Introdu o litera: ";
            std::cin >> litera;

            // Check if the letter was already guessed
            if (ghicite.find(litera) != std::string::npos) {
                std::cout << "Ai ghicit deja aceasta litera!\n";
                continue;  // Skip to next iteration
            }

            // Add the letter to the guessed list
            ghicite += litera;

            // Check if the letter is in the word
            bool gasit = false;
            for (size_t i = 0; i < cuvant.length(); ++i) {
                if (cuvant[i] == litera) {
                    // Reveal the letter in the display
                    afisat[i] = litera;
                    gasit = true;
                }
            }

            // If letter not found, increment errors and show hangman
            if (!gasit) {
                greseli++;
                std::cout << "Litera gresita! Greseli: " << greseli << "/" << maxGreseli << "\n";
                printHangman(greseli);  // Display the hangman drawing
            } else {
                // Correct letter
                std::cout << "Litera corecta!\n";
            }

            // Show current state of the word
            std::cout << "Cuvant: " << afisat << "\n";
        }

        // Check if the round was won or lost
        if (afisat == cuvant) {
            std::cout << "Felicitari! Ai ghicit cuvantul: " << cuvant << "\n";
            castigate++;  // Increment win counter
        } else {
            std::cout << "Ai pierdut aceasta runda! Cuvantul era: " << cuvant << "\n";
        }
    }

    // Final score display
    std::cout << "\nJoc terminat! Ai castigat " << castigate << " din " << numarRunde << " runde.\n";

    return 0;
}