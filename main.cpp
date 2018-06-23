#include <iostream>
#include <vector> 
#include "Me.h"
#include "Color.h"


std::string userVar  = "";
std::string userIncl = " #include <iostream> \n";
std::string userCmd  = "";
std::string userNameSpace = " using namespace std; \n";

Color::Modifier blue(Color::BG_BLUE);
Color::Modifier defa(Color::BG_DEFAULT);
Color::Modifier red(Color::FG_GREEN);

bool isVar(std::string cmd) {
    if (cmd != "") {
        std::vector<std::string> typeVar;
        typeVar.push_back("int");
        typeVar.push_back("float");
        typeVar.push_back("double");
        typeVar.push_back("char");
        typeVar.push_back("std::vector");
        typeVar.push_back("std::string");
        for (int i = 0; i <= typeVar.size(); i++) {
            if (Me::search(cmd, typeVar[i])) {
                return true;
            }
        }
    }
    return false;
}
bool isLib(std::string cmd) {
    if (cmd != "") {
        if (Me::search(cmd, "#include")) {
            return true;
        }
    }
    return false;
}
bool isNameSpace(std::string cmd) {
    if (cmd != "") {
        if (Me::search(cmd, "using namespace")) {
            return true;
        }
    }
    return false;
}
void addLib(std::string cmd) {
    if(cmd != "") {
        userIncl += " " + cmd + '\n';
    }
} 
void addVar(std::string cmd) {
    if(cmd != "") {
        userVar += " " + cmd + '\n';
    }
}
void addNameSpace(std::string cmd) {
    if(cmd != "") {
        userNameSpace += " " + cmd + '\n';
    }
}
void showUser() {
    std::cout << blue << "* Include :" << defa << std::endl;
    std::cout << userIncl;
    std::cout << blue << "* Var     :" << defa << std::endl;
    std::cout << userVar;
}
void handleFileOutput(std::string cmd) {
    std::string buf;
    buf += userIncl;
    buf += userVar;
    buf += userNameSpace;
    buf += " int main() {";
    buf +=      cmd;
    buf += "           }";
    Me::writeFile("Cs.cpp", buf);
}
void Run() {
    system("g++ -o Cs Cs.cpp");
    system("./Cs");
    system("rm -R Cs.cpp Cs");
}

int main() {
    std::string cmd;
    showUser();
    while(true) {
        cmd = "";
        std::cout << red << ">>> " << defa;
        std::getline(std::cin, cmd);
        if (cmd == "") {
            // NULL
        } else if (isLib(cmd)) {
            addLib(cmd);
            showUser();
        } else if (isVar(cmd)) {
            addVar(cmd);
            showUser();
        } else if (isNameSpace(cmd)) {
            addNameSpace(cmd);
        } else {
            handleFileOutput(cmd);
            Run();
        }
    }
    return 0;
}













