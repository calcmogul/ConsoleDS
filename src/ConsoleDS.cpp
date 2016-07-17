#include "ConsoleDS.h"

#include <cstdlib>
#include <iostream>

ConsoleDS::ConsoleDS(int teamNumber, QObject* parent) : QObject(parent) {
    m_ds.setTeam(teamNumber);

    // Update robot status
    connect(&m_ds, &DriverStation::statusChanged,
            [] (QString str) {
                std::cout << "[INFO] " << str.toStdString() << std::endl;
            });

    // Print messages from robot to console
    connect(&m_ds, &DriverStation::newMessage,
            [] (QString str) {
                std::cout << "[INFO] " << str.toStdString() << std::endl;
            });

    // Initialize protocol and DS
    m_ds.init();
    m_ds.setProtocolType(DriverStation::kFRC2016);
}

void ConsoleDS::enableDS(bool enable) {
    if (enable) {
        if (m_ds.canBeEnabled()) {
            // The DS allows us to enable the robot
            m_ds.enableRobot();
            std::cout << "[INFO] enabled" << std::endl;
        }
        else {
            // There is something preventing robot enable
            m_ds.disableRobot();
            std::cout << "[ERROR] Robot cannot be enabled" << std::endl;
        }
    }
    else {
        m_ds.disableRobot();
        std::cout << "[INFO] disabled" << std::endl;
    }
}

void ConsoleDS::run() {
    std::string input;

    while (1) {
        std::cout << "\r> ";
        std::cin >> input;

        if (!std::cin) {
            std::cout << "[ERROR] Input broke" << std::endl;
            std::cin.clear();
        }

        if (input == "enable") {
            enableDS(true);
        }
        else if (input == "disable") {
            enableDS(false);
        }
        else if (input == "test") {
            m_ds.setControlMode(DS::kControlTest);
        }
        else if (input == "auto") {
            m_ds.setControlMode(DS::kControlAutonomous);
        }
        else if (input == "operator") {
            m_ds.setControlMode(DS::kControlTeleoperated);
        }
        else if (input == "quit") {
            std::exit(0);
        }
    }

    emit finished();
}
