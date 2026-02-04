/* Problem: Vending Machine Change Maker

Write a C++ program that simulates a vending machine making change.

Requirements

Print a short welcome message.

Ask the user for:

priceCents (an integer, 1 to 500)

paidCents (an integer, 0 to 10000)

If paidCents < priceCents, print:

Insufficient payment.

Also print how many more cents are needed.

Otherwise:

Compute changeCents = paidCents - priceCents

Print the total change in cents

Break the change into coins using the fewest coins:

quarters (25), dimes (10), nickels (5), pennies (1)

Print the number of each coin. */

#include <iostream>

int main()
{   
    int priceCents, paidCents, changeCents, quarters, dimes, nickels, pennies;
    
    std::cout << "Welcome! Please choose a beverage!\n";
    
    std::cout << "How much does the beverage cost in cents?\n";
    std::cin >> priceCents;

    std::cout << "How many cents are you using to pay?\n";
    std::cin >> paidCents;

    if (paidCents < priceCents) {
        std::cout << "Insufficient payment.\n";
        std::cout << priceCents-paidCents << " more cents are needed.\n";
    } else {
        changeCents = paidCents - priceCents;

        quarters = changeCents/25;
        changeCents = changeCents - (quarters * 25);

        dimes = changeCents/10;
        changeCents = changeCents - (dimes * 10);

        nickels = changeCents/5;
        changeCents = changeCents - (nickels * 5);

        pennies = changeCents;

        std::cout << "Total Change:\n" << quarters << " quarters\n" << dimes << " dimes\n" << nickels << " nickels\n" << pennies << " pennies\n";
    return 0;
    }
}