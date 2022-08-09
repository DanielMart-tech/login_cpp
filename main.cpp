#include <iostream>
#include <fstream>

bool isLoggedIn()
{
    std::string username;
    std::string password;
    std::string un;
    std::string pw;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password)
    {
        return true;
    } else
    {
        return false;
    }
}

int main()
{
    int choice;

    std::cout << "1: Register\n2: Login\nYour choice: ";
    std::cin >> choice;

    if(choice == 1)
    {
        std::string username;
        std::string password;

        std::cout << "Select a username: ";
        std::cin >> username;

        std::cout << "Select a password: ";
        std::cin >> password;

        std::ofstream file(username + ".txt");
        file << username << std::endl << password;
        file.close();

        main();
    } else if(choice == 2)
    {
        bool status = isLoggedIn();

        if(!status)
        {
            std::cout << "False login" << std::endl;
            return 0;
        } else
        {
            std::cout << "Successful logged in!" << std::endl;
            return 1;
        }
    }

}