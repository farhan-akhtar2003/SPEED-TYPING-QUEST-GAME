#include <iostream>
#include <windows.h>
#include <curses.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include <time.h>
#include <string.h>
#include <unistd.h>
using namespace std;
void clear_()
{
    ofstream file("write.txt", ios::out);
    file << "                                  ----------------------------------------\n"
         << "                                 |:::::::::HISTORY OF LAST SESSIONS:::::::|\n"
         << "                                  ----------------------------------------\n";
}
time_t end_time = time(NULL);
int main();
char arr[30];
int set_keys()
{
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 97 + i;
    }
    arr[26] = 10;
    arr[27] = 32;
    arr[28] = 8;
    arr[29] = 13;
}
class keyboard_single_line
{

public:
    void set(int c, int j, int k)
    {

        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hconsole, c);
        COORD d;
        d.X = 20 + j;
        d.Y = 12 + k;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
    }
    void print_ist_part(string s, string f, int length)
    {
        for (int j = 0; j < length; j++)
        {
            if (f[j] == s[j])
            {

                set(2, -5 + j, -10);
                cout << s[j];
                cout << "\xDB";
            }
            else
            {
                set(4, -5 + j, -10);
                cout << s[j];
                cout << "\xDB";
            }
        }
    }
    void print_2nd_part(int i, string s, int length)
    {
        for (int j = i + 1; j < length; j++)
        {
            set(0, -5 + j, -10);
            cout << s[j];
        }
    }
    void printkeys(char arr[], int i)
    {
        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hconsole, 240);
        cout << "  " << arr[i] << "  ";
        SetConsoleTextAttribute(hconsole, 1);
        cout << " ";
    }
    void print_main_keyboard(char arr[])
    {
        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        printkeys(arr, 16);
        printkeys(arr, 22);
        printkeys(arr, 4);
        printkeys(arr, 17);
        printkeys(arr, 19);
        printkeys(arr, 24);
        printkeys(arr, 20);
        printkeys(arr, 8);
        printkeys(arr, 14);
        printkeys(arr, 15);
        cout << " ";
        SetConsoleTextAttribute(hconsole, 240);
        cout << " <- backspace " << arr[28] << " ";
        SetConsoleTextAttribute(hconsole, 1);
        cout << "   \n\n\n                           ";
        printkeys(arr, 0);
        printkeys(arr, 18);
        printkeys(arr, 3);
        printkeys(arr, 5);
        printkeys(arr, 6);
        printkeys(arr, 7);
        printkeys(arr, 9);
        printkeys(arr, 10);
        printkeys(arr, 11);
        cout << " ";
        SetConsoleTextAttribute(hconsole, 240);
        cout << " enter ";
        SetConsoleTextAttribute(hconsole, 1);
        cout << "   \n\n\n                           ";
        cout << "      ";
        SetConsoleTextAttribute(hconsole, 240);
        cout << " Shift  ";
        SetConsoleTextAttribute(hconsole, 1);
        cout << " ";
        printkeys(arr, 25);
        printkeys(arr, 23);
        printkeys(arr, 2);
        printkeys(arr, 21);
        printkeys(arr, 1);
        printkeys(arr, 13);
        printkeys(arr, 12);
        cout << " \n\n\n                                     ";
        SetConsoleTextAttribute(hconsole, 240);
        cout << "                  SPACE                    ";
        SetConsoleTextAttribute(hconsole, 1);
        cout << "   \n\n\n                           ";
    }
    void check_key_pressed(char arr[], char c, int i)
    {
        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

        if (c - 97 == i)
        {
            SetConsoleTextAttribute(hconsole, 192);
            cout << "  " << arr[i] << "  ";
            SetConsoleTextAttribute(hconsole, 1);
            cout << " ";
        }
        else
        {

            SetConsoleTextAttribute(hconsole, 240);
            cout << "  " << arr[i] << "  ";
            SetConsoleTextAttribute(hconsole, 1);
            cout << " ";
        }
    }
    void print_red_key(char arr[], char c)
    {
        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        check_key_pressed(arr, c, 16);
        check_key_pressed(arr, c, 22);
        check_key_pressed(arr, c, 4);
        check_key_pressed(arr, c, 17);
        check_key_pressed(arr, c, 19);
        check_key_pressed(arr, c, 24);
        check_key_pressed(arr, c, 20);
        check_key_pressed(arr, c, 8);
        check_key_pressed(arr, c, 14);
        check_key_pressed(arr, c, 15);
        if (c == 8)
        {
            cout << " ";
            SetConsoleTextAttribute(hconsole, 192);
            cout << " <- backspace " << arr[28] << " ";
            SetConsoleTextAttribute(hconsole, 1);
            cout << "   \n\n\n                           ";
        }
        else
        {

            cout << " ";
            SetConsoleTextAttribute(hconsole, 240);
            cout << " <- backspace " << arr[28] << " ";
            SetConsoleTextAttribute(hconsole, 1);
            cout << "   \n\n\n                           ";
        }
        check_key_pressed(arr, c, 0);
        check_key_pressed(arr, c, 18);
        check_key_pressed(arr, c, 3);
        check_key_pressed(arr, c, 5);
        check_key_pressed(arr, c, 6);
        check_key_pressed(arr, c, 7);
        check_key_pressed(arr, c, 9);
        check_key_pressed(arr, c, 10);
        check_key_pressed(arr, c, 11);
        if (c == 13)
        {
            cout << " ";
            SetConsoleTextAttribute(hconsole, 192);
            cout << " enter ";
            SetConsoleTextAttribute(hconsole, 1);
            cout << "   \n\n\n                                ";
        }
        else
        {
            cout << " ";
            SetConsoleTextAttribute(hconsole, 240);
            cout << " enter ";
            SetConsoleTextAttribute(hconsole, 1);
            cout << "   \n\n\n                                ";
        }
        if (c == 14)
        {
            cout << " ";
            SetConsoleTextAttribute(hconsole, 192);
            cout << " Shift  ";
            SetConsoleTextAttribute(hconsole, 1);
            cout << " ";
        }
        else
        {

            cout << " ";
            SetConsoleTextAttribute(hconsole, 240);
            cout << " Shift  ";
            SetConsoleTextAttribute(hconsole, 1);
            cout << " ";
        }
        check_key_pressed(arr, c, 25);
        check_key_pressed(arr, c, 23);
        check_key_pressed(arr, c, 2);
        check_key_pressed(arr, c, 21);
        check_key_pressed(arr, c, 1);
        check_key_pressed(arr, c, 13);
        check_key_pressed(arr, c, 12);
        if (c == 32)
        {
            cout << " \n\n\n                                     ";
            SetConsoleTextAttribute(hconsole, 192);
            cout << "                  SPACE                    ";
            SetConsoleTextAttribute(hconsole, 1);
            cout << "   \n\n\n                           ";
        }
        else
        {

            cout << " \n\n\n                                     ";
            SetConsoleTextAttribute(hconsole, 240);
            cout << "                  SPACE                    ";
            SetConsoleTextAttribute(hconsole, 1);
            cout << "   \n\n\n                           ";
        }
    }
};
class Typing_Test : protected keyboard_single_line
{
protected:
    clock_t start, end;
    double time_used;
    void set_parameters();
    void check(char c[], char input[], int j);
    void check(char c[], int times);
    void check_for_time(char c[]);

public:
    string fin_inp = "";
    int length = 0;
    int count = 0;
    int checkcount = 0;
    int wrong_chracters = 0;
    int count_back = 0;
};

void Typing_Test::set_parameters()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    system("cls");
    system("color 0F");
}
void Typing_Test::check(char c[], char input[], int j)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    set_parameters();
    cout << c << endl;
    for (int i = 0; i <= j; i++)
    {
        if (c[i] == input[i])
        {
            SetConsoleTextAttribute(hConsole, 2);
            cout << input[i];
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << input[i];
        }
    }
}

void Typing_Test ::check(char c[], int times)
{
    checkcount++;
    if (checkcount == 1)
    {
        start = clock();
    }
    char input[strlen(c)];
    string f;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < strlen(c) - 1; i++)
    {

    label:

        input[i] = getch();
        f += input[i];
        if (input[i] == '\r')
        {
            length--;
            break;
        }

        if (input[i] == 8)
        {
            if (i == 0)
            {
                f.pop_back();
                set(2, 0, 0);
                print_red_key(arr, input[i]);
                set(0, -5 + i, -10);
                // usleep(33333);
                // set(2, 0, 0);
                // print_main_keyboard(arr);
                // set(0, -5 + i, -10);
                goto label;
            }

            length--;
            f.pop_back();
            f.pop_back();
            set(0, -5 + i - 1, -10);
            print_ist_part(c, f, f.length());
            print_2nd_part(i, c, strlen(c) - 1);
            set(2, 0, 0);
            print_red_key(arr, input[i]);
            set(0, -5 + i - 1, -10);
            // usleep(33333);
            print_ist_part(c, f, f.length());
            print_2nd_part(i, c, strlen(c) - 1);
            // set(2, 0, 0);
            // print_main_keyboard(arr);
            // set(0, -5 + i - 1, -10);
            i--;
            count_back++;
            goto label;
        }

        else
        {
            length++;
            if (input[i] == c[i])
            {
                count++;
                set(0, -5 + i + 1, -10);
                print_ist_part(c, f, f.length());
                print_2nd_part(i, c, strlen(c) - 1);
                set(2, 0, 0);
                print_red_key(arr, input[i]);
                set(0, -5 + i + 1, -10);
                // usleep(33333);
                // print_ist_part(c, f, f.length());
                // print_2nd_part(i, c, strlen(c) - 1);
                // set(2, 0, 0);
                // print_main_keyboard(arr);
                // set(0, -5 + i + 1, -10);
            }
            else
            {
                set(0, -5 + i + 1, -10);
                print_ist_part(c, f, f.length());
                print_2nd_part(i, c, strlen(c) - 1);
                set(2, 0, 0);
                print_red_key(arr, input[i]);
                set(0, -5 + i + 1, -10);
                // usleep(33333);
                // print_ist_part(c, f, f.length());
                // print_2nd_part(i, c, strlen(c) - 1);
                // set(2, 0, 0);
                // print_main_keyboard(arr);
                // set(0, -5 + i + 1, -10);
            }
        }
    }

    if (checkcount == times)
    {
        end = clock();
    }
    if (length == strlen(c) - 1)
    {

        wrong_chracters = (length + count_back) - count;
    }
    else
    {

        wrong_chracters = (length + 1 + count_back) - count;
    }
}
void Typing_Test::check_for_time(char c[])
{
    char input[strlen(c)];
    string f;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < strlen(c) - 1; i++)
    {

    label:
        if (time(NULL) > end_time)
        {
            length--;
            break;
        }
        input[i] = getch();
        f += input[i];
        if (input[i] == '\r')
        {
            system("cls");
            system("color 0F");
            cout << "\n\n                   YOUR PERFORMANCE IS NOT RECORDED AS YOU DID NOT COMPLETE THE TIME !! \n";
            sleep(3);
            main();
        }
        if (time(NULL) > end_time)
        {
            break;
        }

        if (input[i] == 8)
        {
            if (i == 0)
            {
                f.pop_back();
                set(2, 0, 0);
                print_red_key(arr, input[i]);
                // sleep(1);
                set(0, -5 + i, -10);
                // usleep(33333);
                // set(2, 0, 0);
                // print_main_keyboard(arr);
                // set(0, -5 + i, -10);
                // goto label;
            }

            length--;
            f.pop_back();
            f.pop_back();
            set(0, -5 + i - 1, -10);
            print_ist_part(c, f, f.length());
            set(0, -5 + i - 1, -10);
            print_2nd_part(i, c, strlen(c) - 1);
            set(2, 0, 0);
            print_red_key(arr, input[i]);
            // sleep(10);
            set(0, -5 + i - 1, -10);
            // usleep(33333);
            // set(0, -5 + i - 1, -10);
            // print_ist_part(c, f, f.length());
            // set(0, -5 + i - 1, -10);
            // print_2nd_part(i, c, strlen(c) - 1);
            // set(2, 0, 0);
            // print_main_keyboard(arr);
            // set(0, -5 + i - 1, -10);
            i--;
            count_back++;
            goto label;
        }

        else
        {
            length++;
            if (input[i] == c[i])
            {
                count++;
                set(0, -5 + i + 1, -10);
                print_ist_part(c, f, f.length());
                print_2nd_part(i, c, strlen(c) - 1);
                set(2, 0, 0);
                print_red_key(arr, input[i]);
                set(0, -5 + i + 1, -10);
                // usleep(33333);
                // print_ist_part(c, f, f.length());
                // print_2nd_part(i, c, strlen(c) - 1);
                // set(2, 0, 0);
                // print_main_keyboard(arr);
                // set(0, -5 + i + 1, -10);
            }
            else
            {
                set(0, -5 + i + 1, -10);
                print_ist_part(c, f, f.length());
                print_2nd_part(i, c, strlen(c) - 1);
                set(2, 0, 0);
                print_red_key(arr, input[i]);
                set(0, -5 + i + 1, -10);
                // usleep(33333);
                // sleep(10);
                // print_ist_part(c, f, f.length());
                // print_2nd_part(i, c, strlen(c) - 1);
                // set(2, 0, 0);
                // print_main_keyboard(arr);
                // set(0, -5 + i + 1, -10);
            }
        }
    }

    if (length == strlen(c) - 1)
    {

        wrong_chracters = (length + count_back) - count;
    }
    else
    {

        wrong_chracters = (length + 1 + count_back) - count;
    }
}
class Sentence_formation : public Typing_Test
{
    string line;
    vector<string> lines;

public:
    int process_count = 0;
    int session_count = 0;
    int round_count = 0;
    void store_words(int a, float tym);
    void process(int c, int d);
    void word_const();
    void time_const();
};
void Sentence_formation ::store_words(int a, float tym)
{
    session_count++;
    round_count++;
    ifstream file("p.txt");

    while (getline(file, line))
    {

        lines.push_back(line);
    }
    if (a == 1)
    {
        word_const();
        set_parameters();
        ofstream wfile("write.txt", ios::app);
        time_used = (((double)(end - start)) / CLOCKS_PER_SEC);
        wfile << "\n\n\n\nSESSION " << session_count;
        wfile << "\n\nROUND " << round_count;
        wfile << "\n\nTOTAL TIME USED = " << time_used << " SECONDS";
        wfile << "\n\nNO. OF KEYSTROKES STRIKED = " << length + 1;
        wfile << "\n\nWRONG CHRACTERS = " << wrong_chracters;
        wfile << "\n\nBACKSPACED CHRACTERS = " << count_back;
        wfile << "\n\nSPEED = " << (((length + 1) / 10) / (time_used / 60)) * 2 << "WPM ";
        wfile << "\n\nSPEED = " << (((length + 1)) / (time_used / 60)) << "CHPM ";
        wfile << "\n\nACCURACY = " << (double)((double)((double)(length + 1 - count_back - wrong_chracters) / (double)(length + 1))) * 100 << " % ";
        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hconsole, 10);
        cout << "\n\nTOTAL TIME USED = " << time_used << " SECONDS";
        cout << "\n\nNO. OF KEYSTROKES STRIKED = " << length + 1;
        cout << "\n\nWRONG CHRACTERS = " << wrong_chracters;
        cout << "\n\nBACKSPACED CHRACTERS = " << count_back;
        cout << "\n\nSPEED = " << (((length + 1) / 10) / (time_used / 60)) * 2 << "WPM ";
        cout << "\n\nSPEED = " << (((length + 1)) / (time_used / 60)) << "CHPM ";
        cout << "\n\nACCURACY = " << (double)((double)((double)(length + 1 - count_back - wrong_chracters) / (double)(length + 1))) * 100 << " % ";
        SetConsoleTextAttribute(hconsole, 7);
        cout << "\n\nRETURNING TO MAIN MENU IN FEW SECONDS ... \n";
        // cout << "\n\nFor returning to main menu press"
        //      << "\x1B[31m"
        //      << " ENTER"
        //      << "\x1B[0m"
        //      << " ...";
        // getch();
    }
    else if (a == 2)
    {
        time_const();
        set_parameters();
        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hconsole, 4);
        cout << "\n                                 TIME OVER !! DISPLAYING YOUR SCORES... ";
        sleep(2);
        ofstream wfile("write.txt", ios::app);
        wfile << "\n\n\n\nSESSION " << session_count;
        wfile << "\n\nROUND " << round_count;
        wfile << "\n\nNO. OF KEYSTROKES STRIKED = " << length + 1;
        wfile << "\n\nWRONG CHRACTERS = " << wrong_chracters - 1;
        wfile << "\n\nBACKSPACED CHRACTERS = " << count_back;
        wfile << "\n\nSPEED = " << (double)(((length + 1) / 10) / tym) * (2) << "WPM ";
        wfile << "\n\nSPEED = " << (double)(((length + 1)) / tym) << "CHPM ";
        wfile << "\n\nACCURACY = " << (double)((double)((double)(length + 1 - count_back - wrong_chracters) / (double)(length + 1))) * 100 << " % ";
        SetConsoleTextAttribute(hconsole, 10);
        cout << "\n\nNO. OF KEYSTROKES STRIKED = " << length + 1;
        cout << "\n\nWRONG CHRACTERS = " << wrong_chracters;
        cout << "\n\nBACKSPACED CHRACTERS = " << count_back;
        cout << "\n\nSPEED = " << (double)(((length + 1) / 10) / tym) * (2) << "WPM ";
        cout << "\n\nSPEED = " << (double)(((length + 1)) / tym) << "CHPM ";
        cout << "\n\nACCURACY = " << (double)((double)((double)(length + 1 - count_back - wrong_chracters) / (double)(length + 1))) * 100 << " % ";
        SetConsoleTextAttribute(hconsole, 7);
        cout << "\n\nRETURNING TO MAIN MENU IN FEW SECONDS ... \n";
        // cout << "\n\nFor returning to main menu press"
        //      << "\x1B[31m"
        //      << " ENTER"
        //      << "\x1B[0m"
        //      << " ...";
        // getch();
    }
    file.close();
    sleep(6);
}
void Sentence_formation::process(int c, int d)
{
    process_count++;
    system("cls");
    string s;

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {

        int random_number = rand() % 500;
        s += lines[random_number] + " ";
    }

    char arr1[s.length()];

    for (int i = 0; i <= s.length(); i++)
    {
        arr1[i] = s[i];
    }

    if (process_count == 1)
    {
        for (int i = 4; i > 0; i--)
        {

            set(0, -5, -10);
            cout << s;
            set(4, -5, -7);
            cout << "Your Typing Test will start in " << i << " seconds...";
            set(170, 0, 0);
            print_main_keyboard(arr);
            set(0, -5, -10);
            sleep(1);
        }
    }
    system("cls");
    set(0, -5, -10);
    cout << s;
    cout << endl;
    set(170, 0, 0);
    print_main_keyboard(arr);
    set(0, -5, -10);
    if (c == 1)
    {

        check(arr1, d);
        cout << endl;
    }
    else
    {
        check_for_time(arr1);
        cout << endl;
    }
}
void Sentence_formation::time_const()
{
    while (time(NULL) < end_time)
    {
        process(2, 0);
    }
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(hConsole, 4);
    // cout << "\n                                 TIME OVER !! ";
    // sleep(2);
}
void Sentence_formation::word_const()
{
    int t;

    cout << "        \n\n   HOW MANY WORDS YOU WANT TO TYPE (CHOSE MULTIPLE OF 10 LESS THAN 500): ";
choice:
    cin >> t;
    if (t % 10 != 0 || t == 0 || t > 500)
    {
        cout << "\n   ENTER VALID CHOICE : ";
        goto choice;
    }

    int b = t / 10;

    while (b--)
    {
        process(1, t / 10);
    }
}

int main()
{
    clear_();
    Sentence_formation s;
    set_keys();
start:
    system("cls");
    system("color 0F");
    cout << "                 |-----------------------------------------------------------------------------------------------------|\n";
    cout << "\n                    --------------------------:)!! TYPING TEST SOFTWARE WELCOMES YOU !!:)---------------------------\n\n ";
    cout << "                  |-------------------------------------------------------------------------------------------------|\n";
    system("color 0E");
    cout << "     \n\n                                        HERE ARE SOME BASIC FEATURES OF THIS SOFTWARE!! \n ";
    cout << "                    \n\n    1. YOU CAN PRACTICE TYPING IN WORD CONSTRAINED SESSIONS \n"
         << "    2. YOU CAN PRACTICE TYPING IN TIME CONSTRAINED SESSIONS\n";
    cout << "\n    PRESS 1 OR 2 ACCORDINGLY : ";
label:
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:

        s.store_words(1, 0);
        s.process_count = 0;
        s.checkcount = 0;
        s.fin_inp = "";
        s.count_back = 0;
        s.session_count = 0;
        s.length = 0;
        s.count = 0;
        goto start;
    case 2:
        cout << "\n\n                           THERE ARE 3 MODES IN TIME CONSTRAINED SESSION :\n\n"
             << "                              (YOU CAN WRITE ANY NUMBER OF WORDS IN THE GIVEN TIME)\n\n"
             << "                            1. 30 SEC TIMER \n"
                "                            2. 1  MIN TIMER \n"
                "                            3. 2  MIN TIMER \n";
        cout << "\n\n                         PRESS MODE NUMBER ACCORDINGLY : ";
    mode1:
        int mode;
        cin >> mode;
        if (mode > 3 || mode < 1)
        {
            cout << "\n                          ENTER VALID MODE : ";
            goto mode1;
        }
        float tym;
        if (mode == 1)
        {
            tym = 0.5;
            end_time = time(NULL) + 34;
            s.store_words(2, tym);
        }
        else if (mode == 2)
        {
            tym = 1;
            end_time = time(NULL) + 63;
            s.store_words(2, tym);
        }
        else
        {
            tym = 2;
            end_time = time(NULL) + 123;
            s.store_words(2, tym);
        }
        s.process_count = 0;
        s.checkcount = 0;
        s.fin_inp = "";
        s.count_back = 0;
        s.session_count = 0;
        s.count = 0;
        s.length = 0;
        goto start;

    default:
        cout << " \n\n    INVALID CHOICE ENTER AGAIN : ";
        goto label;
    }

    return 0;
}