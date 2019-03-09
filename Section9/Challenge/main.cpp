// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!
 * 
 * print the options
 * get input
 * 

*/
#include <iostream>
# include <vector>
using namespace std;

void print_numbers(vector<int> &numbers);
void add_number(int number, vector<int> &numbers);
void display_mean(vector<int> &numbers);
void process_selection(char selection, vector<int> &numbers);
char get_selection();
void print_menu();

void print_numbers(vector<int> &numbers) {

    if (numbers.empty()) {
        cout << "The collection is empty, nothing to print.";
    }
    else {
        for (auto number: numbers) {
            cout << number << " ";
        }
        //cout << "size is " << numbers.size();
    }
    cout << endl;
}

void add_number(vector<int> &numbers) {

    
    int number;
    
    while (!(cin >> number))
    {
        //cout << "number, numbers[0]: " << number << numbers[0];
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid! Enter an interger: ";
        
    }
    
    //cout << "number, numbers[0]: " << number << numbers[0];
    numbers.push_back(number);
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Added " << number << " to the collection.\n\n";
}

void display_mean(vector<int> &numbers) {
    //cout << "------> numbers is " << numbers << " of size " << numbers.size();
   // cout << "size is " << numbers.size();

    
    for (int i = 0, total{}; i < numbers.size(); i++)
    {
        total += numbers[i];
        if (i == numbers.size() - 1) 
        {
        //cout << "size is " << numbers.size();
        //cout << "total is " << total;
        cout << "The mean is " << total/numbers.size() << endl;
        }
    }
}

void process_selection(char selection, vector<int> &numbers) {
        switch(selection) {
        case 'P' :
        case 'p' :
            cout << "You selected '" << selection << "' - Print numbers.\nRESULT: ";
            print_numbers(numbers);
            break;
            
        case 'A' :
        case 'a' :
            cout << "You selected '" << selection << "' - Add number. \n" << "Enter an integer: ";
            add_number(numbers);
            break;

        case 'M' :
        case 'm' :
            cout << "You selected '" << selection << "' - Display mean." << endl;
            display_mean(numbers);
            break;
            
        case 'S' :
        case 's' :
            cout << "You selected '" << selection << "' - Display smallest." << endl; 
            cout << "The smallest number is " << *min_element(numbers.begin(),numbers.end()) << endl;
            break;
           
        case 'L' :
        case 'l' :
            cout << "You selected '" << selection << "' - Display largest." << endl; 
            cout << "The largest number is " << *max_element(numbers.begin(),numbers.end()) << endl;
            break;
            
        case 'Q' :
        case 'q' :
            cout << "Goodbye." << endl;
            break;
            
        default :
           cout << "Invalid selection. ";
    }
}

char get_selection() {
    
    char selection;
    string user_selection;
    cout << "\nSelection: ";
        
    cin >> user_selection;

    selection = user_selection[0];
        
    //cout << "------> get_selection returning " << selection;

    return selection;
    
}

void print_menu() {
    
    cout << "Select from the following options:\n";
    cout << "P - Print numbers\n";
    cout << "A - Add a number\n";
    cout << "M - Display mean of the numbers\n";
    cout << "S - Display the smallest number\n";
    cout << "L - Display the largest number\n";
    cout << "Q - Quit\n";
}




int main() {
    
    vector<int> numbers {1,2,3};
    char selection;
    
    do {
    
        print_menu();
        
        //selection = get_selection();
    
        process_selection(get_selection(), numbers);
        
        cout << endl; 
        
    } while (get_selection() != 'q' && get_selection() != 'Q');
        
    return 0;
}

