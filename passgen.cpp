#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include<conio.h> // this is a windows only library!!

int main() {
    using namespace std;
    string pass;
    string charsFull = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+";
    string charsNoSpecial = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string chars;
    int passLength;
    cout << "How many characters should the password be: " << endl;
    cin >> passLength;
    cout << "Should the password contain special characters? (y/n)" << endl;
    char special;
    cin >> special;
    if (special == 'y') {
        chars = charsFull;
    } else {
        chars = charsNoSpecial;
    }
    string userSeed;
    cout << "Please type a lot of random characters" << endl;
    bool init = false;
    while (userSeed.length() < 50) {
        if(init == false && userSeed.length() > 0){
            cout << "Keep typing..." << endl;
            init = true;
        }
        char c;
        c = getch();
        userSeed += c;
    }
    cout << "Thank you..." << endl;
    cout << "Generating password..." << endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, chars.length() - 1);
    for (int i = 0; i < passLength; i++) {
        pass += chars[dis(gen)];
    }
    //turn userSeed into a number
    int userSeedNum = 0;
    for (int i = 0; i < userSeed.length(); i++) {
        userSeedNum += (userSeed[i] * (userSeedNum + 1));

    }
    // shuffle the password using userSeedNum
    shuffle(pass.begin(), pass.end(), default_random_engine(userSeedNum));
    cout << "Your password is: " << pass << endl;
    cout << "Would you like to make another password? (y/n)" << endl;
    char again;
    cin >> again;
    if (again == 'y') {
        main();
    } else {
        cout << "Goodbye!" << endl;
        return 0;
    }
}