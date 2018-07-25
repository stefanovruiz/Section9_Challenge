/*
 * Author; Stefano Ruiz
 * Date: July 23, 2018
 * Updated: July 25, 2018
 *
 * This program is based on the section 9 challenge on Tim's C++ Beginner series.
 * Does not contain any form of exception handling.
 * Do not use this program without citing it, or without giving credit to the users who created it.
 *
 *
 *
 *
 * Recent Updates:
 * Jul 25: Added functions and function definitions. Check out the history on Github for any changes made.
 */




#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void print_numbers();
/*
 * Prints numbers in vector or tells user if vector is empty.
 *
 * */
void add_numbers();
/*
 * Adds a user defined number to the numbers_list vector.
 * It has no exception handling built in.
 *
 * */
void mean_numbers();
/*
 * Calculates the mean (average) of the numbers inside the numbers_list vector.
 *
 * */
void largest_number();
/*
 * Displays the largest number in the numbers_list vector. Uses a ranged-based for loop.
 * For training purposes we are not using the built in "max" function.
 * TO-DO: MUST WRITE FUNCTION.
 * */

void smallest_number();
/*
 * Displays the smallest number in the numbers_list vector. Uses a ranged-based for loop.
 * For training purposes we are not using the built in "min" function.
 * */

vector <int> numbers_list {};
int main() {

    bool whileContinue {true};
    while(whileContinue)
    {
        cout << "Please select from the following: " << endl;
        cout << "P\t- Print numbers stored in list." << endl;
        cout << "A\t- Add numbers to the list." << endl;
        cout << "M\t- Calculate the mean of the list." << endl;
        cout << "S\t- Display the smallest number on the list." << endl;
        cout << "L\t- Display the largest number on the list." << endl;
        cout << "Q\t- Quit" << endl << endl;
        cout << "Please enter your selection: ";
        char user_select{};
        cin >> user_select;

        switch(user_select)
        {
            case 'P':
            case 'p':
                print_numbers();
                break;
            case 'A':
            case 'a':
                add_numbers();
                break;
            case 'M':
            case 'm':
                mean_numbers();
                break;
            case 'S':
            case 's':
                smallest_number();

                break;
            case 'L':
            case 'l':
                cout << "Display largest number." << endl; // Console out test. TO-DO: Replace with proper funciton.
                largest_number();
                break;
            case 'Q':
            case 'q':
                cout << "Thank you!";
                whileContinue = false;
                break;
            default:
                cout << "Invalid entry. Try again.\n" << endl;

        }
    }
    return 0;

}

void print_numbers()
{
    if(numbers_list.empty()) {
        cout << "Numbers list is empty." << endl << endl;
    }
    else {
        cout << "The set contains " << "[ ";
        for(int i{0}; i < numbers_list.size(); i++) {
            cout << numbers_list[i] << ' ';
        }
        cout << "]" << endl << endl;
    }
}

void add_numbers()
{
    int user_number_choice{};
    bool add_numbers_continue{true};
    bool isContinue_do {true}; // do-while

    while(add_numbers_continue){
        cout << "Integer to add . . . ";
        cin >> user_number_choice;
        numbers_list.push_back(user_number_choice);

        char user_choice_y_n{};

        do {
            cout << "Would you like to add another integer (Y/N)? ";
            cin >> user_choice_y_n;
            switch(user_choice_y_n){
                case 'Y':
                case 'y':
                    isContinue_do = false;
                    add_numbers_continue = true;
                    break;
                case 'N':
                case 'n':
                    isContinue_do = false;
                    add_numbers_continue = false;
                    break;
                default:
                    cout << "Invalid entry. Try again." << endl;
                    isContinue_do = true;

            }
        } while(isContinue_do);

    }
}

void mean_numbers()
{
    double sum_of_numbers_list{};
    sum_of_numbers_list = accumulate(numbers_list.begin(), numbers_list.end(), 0.0);
    cout << "Mean of the list is " << (sum_of_numbers_list / numbers_list.size()) << endl << endl;
}

void smallest_number()
{
    // Important variable. It grabs the initial vector value at numbers_list[0] for the comparison in the for loop.
    int initial_vector_value {numbers_list[0]};



    for(auto smallest_number_in_vector : numbers_list) // Used a ranged-based for loop instead of the regular to clean up the code a bit.
    {

        if(smallest_number_in_vector < initial_vector_value)
        {
            if(smallest_number_in_vector < initial_vector_value)
                initial_vector_value = smallest_number_in_vector;

        }

    }
    cout << initial_vector_value << endl;
}

void largest_number()
{
    for(int i{0}; i < numbers_list.size(); i++)
    {
        cout << "Test case for Display largest value in numbers: " << numbers_list[i];
        //
    }
}