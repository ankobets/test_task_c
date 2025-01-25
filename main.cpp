#include <iostream>
#include "Logger.h"


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0]<<"<log file> <log level>";
        return 1;
    }

    std::string log_file = argv[1];
    std::string log_level = argv[2];

    Logger temp(log_file, log_level);

    temp.log("ERROR", "Hello World!");

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
