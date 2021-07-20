// File Name: assign1_sam234.cpp
//
// Auther Samuel Manzanares
// Date: 06/02/2021
// Assignment Number: 1
// CS 2308.501 Summer 2021
// Instructor: Dr. J. Marcos Palacios

//****************This is the line of 80 characters in length*******************
// Virgin Spaceways(VS) is developinga Vending App, for its commercial space
// excursions, which will offer various menu items.
// We are tasked to write a C++ program that takes product orders 
// based on this menu, 
// produce each order's total (subtotal, tax, and total), and summarize the
// end-of-day information (total order prise, menu 
// item most ordered and how many times ordered) 

#include <iostream>
#include <iomanip>

using namespace std;



struct Item { 
    string menuItem; 
    double price;
    int itemCount;
};


void menuOutput(Item arr[], int size) {
    // void function to display menu

    cout << setprecision(2) << fixed;
    cout << "VS App Menu\n";
    for (int i = 0; i < size; i++) {
        cout << "[" << i+1 << "]" << " "
        << setw(21) << left
        << arr[i].menuItem << "$"
        << setw(7) << right
        << arr[i].price << endl;
    }
}


int highestOrder (Item arr[], int size) {
    // function to find highest ordered menu item

    int high = arr[0].itemCount; // numeric value for index in for loop
    int index = 0; // index of highest order index for function output 
    
    for (int i = 1; i < size; i++) {
        if (high < arr[i].itemCount) {
            high = arr[i].itemCount;
            index = i;
        }
    }

    return index;
}


int singleOrder (Item arr[], int size) {
// function to take single orders and return subtotal 

    double subTotal = 0; // numeric value for subttoal of order
    int orderNum = 0; // numeric value for order; user input
    
    menuOutput(arr, size);
    cout << "Input the item numbers for the order, 0 to quit\n";
    cin >> orderNum;
    
    while (orderNum != 0) {
        // validate orderNum
        subTotal += arr[orderNum - 1].price;
        arr[orderNum - 1].itemCount++;

        cin >> orderNum;
    }
    
    return subTotal;
}


void takeOrder(Item arr[], int size) {
// function to display menu, take individuals orders, and display 
// total order summary 

    double totalSale = 0; // numeric value of total sale summary
    int highestIndex; // numeric value to display highest ordered item
    char newOrder = 'N'; // char value for new order loop

    do {
        double subTotal = 0; // numeric value for subtotal 
        double tax = 0; // numeric value to add tax of total 
        double total = 0; // numeric value to obtain total sale of
        // individual order

        subTotal = singleOrder(arr, size);
        
        tax = subTotal * 0.0825;
        total = subTotal + tax;
        totalSale += total;

        cout << setprecision(2) << fixed;
        cout << "Subtotal...$" << setw(8) << right << subTotal << endl;
        cout << "Tax........$" << setw(8) << right << tax << endl;
        cout << "Total......$" << setw(8) << right << total << endl << endl;

        cout << "Please enter 'N' to take a new order or 'E' to Exit: ";
        cin >> newOrder;

    } while (newOrder == 'N');

    highestIndex = highestOrder(arr, size);

    cout << setprecision(2) << fixed << endl;
    cout << "*** End of Day Totals ***\n"
         << "Total Sales: " << totalSale << endl;
    cout << "Item ordered most often: " << arr[highestIndex].menuItem 
         << " was purchased "
         << arr[highestIndex].itemCount << " times.\n";

}

int main() {

    const int SIZE = 6; // numeric constant for array size decleration 

    Item menuItems[SIZE] = {{"Moon Model Platimun", 1099.00, 0}, 
                            {"Earth Model Enamel", 1299.00, 0}, 
                            {"Mars Model Enamel", 499.00, 0},
                            {"Jupiter Model Enamel", 799.00, 0},
                            {"Sun Model Gold", 999.00, 0},
                            {"Saturn Model Silver", 399.00, 0}};

    takeOrder(menuItems, SIZE);

    return 0;
}


