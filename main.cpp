#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;
    cout << "Please enter your username: " << endl;
    cin >> username;
    cout << "Please enter your password :" << endl;
    cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read ,pw);

    if (un == username && pw == password){
        return true;
    }else{
        return false;
    }

}

int main()
{
    int choice;

    cout << "1: Register\n 2: Login\n Your choice: ";
    cin >> choice;
    if( choice == 1 ){
        string username, password;

        cout << "select a usernmae: \n";
        cin >> username;
        cout << "select a password: \n";
        cin >> password;

        ofstream file;
        file.open("data\\" + username + ".txt");
        file << username << endl; 
        file << password << endl;
        file.close();
        main();
    }else if( choice == 2)
    {
        bool status = IsLoggedIn();
        if (!status){
            cout << "False Login!" << endl;
            main();
        }else{
            cout << "Successfully logged in!" << endl;
            return 1;
        }
        
    }
}