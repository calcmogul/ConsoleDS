#include <iostream>
#include <string>
#include <vector>

#include <QtCore>

#include "ConsoleDS.h"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    if (argc == 1) {
        std::cout << "[ERROR] no team number passed as argument" << std::endl;
        return 0;
    }

    // Pass team number to ConsoleDS
    std::vector<std::string> args(argv + 1, argv + argc);
    ConsoleDS console(std::stoi(args[0]), &app);

    QObject::connect(&console, SIGNAL(finished()), &app, SLOT(quit()));

    QTimer::singleShot(0, &console, SLOT(run()));

    return app.exec();
}
