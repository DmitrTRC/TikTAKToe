Implement menu system 



class Menu {
public:
 void Show();


}

cout <<  "1. Show Score" << endl;
cout <<  "2. Select 1-st Player" << endl;
cout <<  "3. Select 2-nd Player" << endl;
cout <<  "4. Start Game" << endl;
cout <<  "5. Reset Score" << endl;
cout <<  "6. Exit" << endl;

while ( true ) {
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch ( choice ) {
        case 1:
            cout << "Show Score" << endl;
            ShowScore();
            break;
        case 2:
            cout << "Select 1-st Player" << endl;
            break;
        case 3:
            cout << "Select 2-nd Player" << endl;
            break;
        case 4:
            cout << "Start Game" << endl;
            break;
        case 5:
            cout << "Reset Score" << endl;
            break;
        case 6:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}
/----------------------------

typedef void (*Menu_Processing_Function_Ptr)();

struct Menu_Item
{
unsigned int  number;
const char *  text;
Menu_Processing_Function_Ptr p_processing_function;
};


/--------------------------
map <unsigned int, Menu_Processing_Function_Ptr> menu_items;
