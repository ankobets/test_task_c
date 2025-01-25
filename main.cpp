#include <iostream>
#include "Logger.h"


int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0]<<"<log file> <log level>";
        return 1;
    }

    std::string log_file = argv[1];
    std::string log_level = argv[2];

    Logger logger(log_file, log_level);
    std::string input_message;
    char menu;
    do
    {
        std::cout << "Choose an option: (s)et level, (w)rite log or (e)xit: ";
        std::cin >> menu;
        std::cin.ignore('\n');

        switch (menu)
        {

        case 'w':
            std::cout << "Enter level: ";
            std::getline(std::cin, log_level);

            std::cout << "Enter message: ";
            std::getline(std::cin, input_message);
            logger.log(log_level, input_message);
            break;

        case 's':
            std::cout << "Enter level: ";
            std::getline(std::cin, log_level);
            logger.setLogLevel(log_level);
            break;

        default:
            break;
        }

    }
    while (menu != 'e');


    return 0;
}
