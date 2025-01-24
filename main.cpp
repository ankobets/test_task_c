#include <iostream>

#include "Logger.h"


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0]<<"Usage: <log file> <log level>";
    }

    std::string log_file = argv[1];
    std::string log_level = argv[2];

    Logger temp("file.txt", Logger::Level::INFO);

    temp.log(Logger::Level::ERROR, "Hello World!");

    // // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // // <b>lang</b> variable name to see how CLion can help you rename it.
    // auto lang = "C++";
    // std::cout << "Hello and welcome to " << lang << "!\n";
    //
    // for (int i = 1; i <= 5; i++)
    // {
    //     // TIP Press <shortcut actionId="Debug"/> to start debugging your code.
    //     // We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/>
    //     // breakpoint for you, but you can always add more by pressing
    //     // <shortcut actionId="ToggleLineBreakpoint"/>.
    //     std::cout << "i = " << i << std::endl;
    // }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
