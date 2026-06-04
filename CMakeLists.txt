cmake_minimum_required(VERSION 4.2)
project(cpp_project_planning_therockets)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_project_planning_therockets main.cpp
        include/Entity.h
        src/Entity.cpp
        src/Account.cpp
        include/Account.h
        src/Client.cpp
        include/Client.h
        src/currentAccount.cpp
        include/currentAccount.h
        src/SavingsAccount.cpp
        include/SavingsAccount.h
 "include/Bank.h" "include/Transaction.h" "src/Bank.cpp" "src/Transaction.cpp" "src/CLICMD.cpp" "include/CLICMD.h" "include/BankController.h" "src/BankController.cpp" "src/Utils.cpp" "include/Utils.h" "include/services/PrintService.h" "src/services/PrintService.cpp")
