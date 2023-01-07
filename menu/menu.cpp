#include "menu.hpp"
#include "..\\function\\function.hpp"

// pictures features
PIC pictures[10000];

void start_menu()
{
    clear_screen();
    system("color 0A");

    // STARTING MENU HEDERS
    cout << "W e l c o m e" << endl
         << " Start menu " << endl
         << "   1.Main menu" << endl
         << "  2.Info " << endl
         << " 3.Exit \n\n"
         << "-->  ";

    // INIT SWITCH KEY
    int switch_key;
    cin >> switch_key;

    switch (switch_key)
    {
    case 1: // IF SWITCH KEY == 1 : GO TO MAIN MENU
        clear_screen();
        main_menu();
        break;

    case 2: // IF SWITCH KEY == 2 : GO TO INFO SECTION
        clear_screen();
        system("color 0B");

        cout << "\t\t I N F O \n"
             << " CLASSIFING IMAGES WITH KNN ALGORITHM\n\n"
             << " Author: Aref Najmaddini \n"
             << " Email: Aref.Najmaddini@gmail.com \n"
             << " Phone-Num: +98-917-066-8815\n"
             << " Tnx to :\n"
             << " \tDr.Yazdian Dehkordi, Dr.Mehrahad\n"
             << " Tas:\n"
             << " \tPooria Azami\n"
             << " \tAhmadreza Kazemi\n"
             << " \tMohsen Gholami \n\n";
        // Info...

        system("PAUSE");
        clear_screen();
        start_menu();

        break;

    case 3: // IF SWITCH KEY == 3 : EXIT THE APP
        clear_screen();
        system("color 0E");

        cout << "Tnx for your attention ^.^\n\n";

        system("PAUSE");
        system("color 0F");
        clear_screen();

        break;

    default: // IF SWITCH KEY != 1,2,3 : ASK TO INPUT SWITCH KEY CORRECTLY
        clear_screen();
        system("color 0E");

        cout << "Please Enter the Correct Entry (*_ *;) \n\n";

        system("PAUSE");
        start_menu();

        break;
    }
}

void main_menu()
{
    system("color 0C");

    // MAIN MENU HERDER
    cout << "M a i n  M e n u\n\n"
         << " 1.Explore images from dataset\n"
         << "   2.Train\n"
         << "    3.Test\n"
         << " 4.Back to Start menu\n\n"
         << "-->  ";

    // INIT SWITCH KEY
    int switch_key;
    int index = -1;
    cin >> switch_key;
    string explor_num = "-1";
    string test_num = "-1";


    switch (switch_key)
    {
    case 1: // IF SWITCH KEY == 1 : GO TO EXPLORING SECTION
        
        clear_screen();
        system("color 0E");

        while (!(stoi(explor_num) >= 0 && stoi(explor_num) <= 9))
        {
            cout << "Please choose your number between 0 and 9\n\n"
                 << "-->  ";
            cin >> explor_num;
            cout << endl << endl;
        }
        clear_screen();
        while (!(index > 0 && index <= 5000))
        {

        cout << "Please input the index number "  
             << "between 1 and 5000"
             << endl << endl
             << "-->  ";
             cin >> index;
             cout << endl << endl;
             clear_screen();
        }

        system("color 0B");
        exploring(explor_num, index, "train");

        system("PAUSE");
        system("color 0F");
        clear_screen();

        main_menu();

        break;

    case 2: // IF SWITCH KEY == 2 : GO TO TRAINING SECTION
        clear_screen();
        system("color 0E");

        
        cout << "Training...\n\n";
        training(pictures);
        

        system("PAUSE");
        system("color 0F");
        clear_screen();

        main_menu();

        break;

    case 3: // IF SWITCH KEY == 3 : GO TO TEST SECTION
        clear_screen();
        system("color 0E");
        
        // get test num
        while (!(stoi(test_num) >= 0 && stoi(test_num) <= 9))
        {
            cout << "Please choose your number between 0 and 9\n\n"
                 << "-->  ";
            cin >> test_num;
            cout << endl << endl;
        }
        clear_screen();

        // get index
        while (!(index > 0 && index <= 800))
        {

        cout << "Please input the index number " 
             << "between 1 and 800"
             << endl << endl
             << "-->  ";
             cin >> index;
             cout << endl << endl;
             clear_screen();
        }

        // testing
        cout << endl << testing(test_num, index, pictures);

        system("PAUSE");
        system("color 0F");
        clear_screen();

        main_menu();

        break;

    case 4: // IF SWITCH KEY == 4 : GO BACK TO START MENU
        clear_screen();
        start_menu();

        break;

    default: // IF SWITCH KEY != 1,2,3 : ASK TO INPUT SWITCH KEY CORRECTLY
        clear_screen();
        system("color 0E");

        cout << "Please Enter the Correct Entry (*_ *;) \n\n";

        system("PAUSE");
        clear_screen();

        main_menu();

        break;
    }
}

