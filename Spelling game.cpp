#include <iostream> // Include for input and output operations
#include <vector>   // Include for using the vector container
#include <string>   // Include for using the string type
#include <ctime>    // Include for time functions
#include <cstdlib>  // Include for random number generator functions
#include <fstream>  // include for file handling 

// Define a struct to hold the words and its description
struct Word {
    std::string text;        // Member variable to store the word
    std::string description; // Member variable to store the description of the word
};

// Define a class to encapsulate the game logic
class SpellingGame {
private:   // Private access specifier to prevent the list and score from being affected by other parts of the program
    std::vector<Word> words; // Vector to store the list of words and descriptions
    int score;               // Integer to keep track of the player's score

public: // Public access specifier allows access from anywhere outside the class
    // Constructor to initialize the game
    SpellingGame() : score(0) { // Initialize the game score to 0
        // Populate the words vector with words and their descriptions
        words = {
    {"soccer", "A game played by two teams of eleven players with a round ball that may not be touched with the hands or arms during play except by the goalkeepers."},
    {"basketball", "A game played between two teams of five players in which goals are scored by throwing a ball through a netted hoop fixed above each end of the court."},
    {"volleyball", "A game in which two teams of six players use their hands to bat a ball back and forth over a high net, trying to make the ball touch the court within the opponents' playing area before it can be returned."},
    {"baseball", "A ball game played between two teams of nine on a field with a diamond-shaped circuit of four bases."},
    {"tennis", "A game in which two or four players strike a ball with rackets over a net stretched across a court."},
    {"golf", "A game in which clubs are used to hit a ball into a series of holes on a course in as few strokes as possible."},
    {"hockey", "A game played on an ice rink by two opposing teams of six skaters each, who try to drive a puck into the opponents' goal with a hockey stick."},
    {"cricket", "A game played with a ball and bat by two teams of eleven players; teams take turns to bat and bowl."},
    {"rugby", "A team game played with an oval ball that may be kicked, carried, and passed from hand to hand with the aim of scoring points by touching the ball down behind the opponents' goal line."},
    {"boxing", "A sport in which two participants of similar weight fight each other with their fists in a series of one to three-minute intervals called rounds."}
};

    }

    // Method to run the game
    //void has been used here because no return value is needed
    void run() {
        //time(0) is used to provide a continually changing number every time the program is run
        //static_cast<unsigned int> converts the time value to an unsigned integer to ensure compatibility with  srand 
        //the integer is then used as a starting point for the random word generator
        srand(static_cast<unsigned int>(time(0))); 
        std::cout << "Welcome to the C++ Spelling Game!\n"; // Greet the player
        std::cout << "Type 'exit' to stop playing.\n\n"; // Instructions on how to exit the gane

        std::string guess; // declare a string to capture the player's guesses
        bool isPlaying = true; // Boolean flag to control the game loop

        while (isPlaying) { // Start the game loop

            std::cout << "Type exit to quit"; // instrctions on how the gane works 
            const Word& word = words[rand() % words.size()]; // Select a random word from the list
            std::cout << "Spell the word described as: " << word.description << "\n"; // Prompt user to spell the word
            std::getline(std::cin, guess); // Read the players input from the console

            if (guess == "exit") { // Check if the user wants to exit
                isPlaying = false; // Set isPlaying to false to terminate the loop
                continue; // Skip the rest of the loop and check the condition
            }

            if (guess == word.text) { // Check if the guessed word is correct
                std::cout << "Correct!\n"; // Congratulate the user
                score++; // Increment the score
            }
            else {
                std::cout << "Incorrect! The correct spelling is: " << word.text << "\n"; // Inform the user of the correct spelling
            }

            std::cout << "Current score: " << score << "\n\n"; // Display the current score

            //Exception handling

            try {

                // File handling
                std::ofstream MyFile("result.txt");

                // Write to the file
                MyFile << "Your score is " << score;

                // Close the file
                MyFile.close();
            }

            catch (int MyFile) {
                std::cout << "There is an error saving the file";
            }

        }

        std::cout << "Game over! Your final score was: " << score << ". Thank you for playing!\n"; // End the game and show final score
    }
};

int main() {
    SpellingGame game; // Create an instance of SpellingGame
    game.run(); // Run the game
    return 0; // Exit the program
}