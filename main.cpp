#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void print_numbers();
void add_numbers();
void mean_numbers();
void largest_number();
void smallest_number();

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
                cout << "Display smallest number." << endl; // Console out test. TO-DO: Replace with proper function.
                break;
            case 'L':
            case 'l':
                cout << "Display largest number." << endl; // Console out test. TO-DO: Replace with proper funciton.
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

}

void largest_number()
{

}