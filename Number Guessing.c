#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   
    srand(time(0));

    int min, max;
    int guessnum;
    int attempt = 4; 
    int guessed_correctly = 0; 
    
    printf("==========================================\n");
    printf("   WELCOME TO THE NUMBER GUESSING GAME!   \n");
    printf("==========================================\n");
    printf("Enter the range of numbers you'd like to play with.\n");
    printf("Enter the first number of the range (Min): ");
    
    if (scanf("%d", &min) != 1 || min < 0) {
        printf("Error: Please enter a valid non-negative starting number.\n");
        return 1;
    }
    
    printf("Enter the last number of the range (Max): ");
    scanf("%d", &max);

    if (min >= max) {
        printf("\n🚫 Invalid Range! The first number must be smaller than the last number.\n");
        return 1;
    }

    int secretNumber = (rand() % (max - min + 1)) + min;

    printf("\n--- GAME STARTED ---\n");
    printf("I have selected a secret number between %d and %d.\n", min, max);
    printf("You have %d attempts to guess it. Good luck!\n", attempt);

    while (attempt > 0) {
        printf("\n------------------------------------------\n");
        printf("Remaining Attempts: %d. Enter your guess: ", attempt);
        
        if (scanf("%d", &guessnum) != 1) {
            printf("⚠️ Invalid input! Please enter a whole number.\n");
            while (getchar() != '\n');
            continue; 
        }

        if (guessnum == secretNumber) {
            printf("\n🎉 CONGRATULATIONS! YOU WON! 🎉\n");
            printf("You guessed the secret number (%d) in %d attempts.\n", secretNumber, 4 - (attempt - 1));
            guessed_correctly = 1;
            break; 
        } 
        
        else if (guessnum < min || guessnum > max) {
            printf("🧐 Your guess is OUTSIDE THE RANGE (%d to %d). Try to stay within the limits!\n", min, max);
        }
        else if (guessnum > secretNumber) {
            printf("⬇️ Too High! My number is smaller. Try again.\n");
        } 
        else { 
            printf("⬆️ Too Low! My number is larger. Try again.\n");
        }

       
        attempt--;
    }

   
    if (guessed_correctly == 0) {
        printf("\n==========================================\n");
        printf("😞 GAME OVER! You ran out of attempts.");
        printf("\nThe Secret Number was: %d\n", secretNumber);
        printf("==========================================\n");
    }

    return 0;
}