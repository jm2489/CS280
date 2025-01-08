#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// A -> I = E
// E -> P O P | P
// O -> + | - | * | / | **
// P -> I | L | UI | UL | (E)
// U -> + | - | !
// I -> C | CI
// C -> a | b | ... | y | z
// L -> D | DL
// D -> 0 | 1 | ... | 8 | 9

bool A();
bool E();
bool O();
bool P();
bool U();
bool I();
bool C();
bool L();
bool D();

string s;

int main() {
    ifstream file("input.txt");
    string line;

    while (getline(file, line)) {
        s = line;
        string t = s;

        if (A() && s.empty()) {
            cout << "The string \"" << t << "\" is in the language" << endl;
        } else {
            cout << "The string \"" << t << "\" is not in the language" << endl;
        }
    }

    file.close();
    cout << "" << endl;
    cout << "Link to my GitHub repo for CS280: https://github.com/jm2489/CS280" << endl;
    return 0;
}

bool A() {
    if (I() && !s.empty() && s[0] == '=') {
        s = s.substr(1);
        return E();
    }
    return false;
}

bool E() { 
    if (P()) {
        while (!s.empty() && O()) {
            if (!P()) return false;
        }
        return true;
    }
    return false;
}

// O -> + | - | * | / | **
bool O() {
    if (s.substr(0, 2) == "**") {
        s = s.substr(2);
        return true;
    } else if (!s.empty() && (s[0] == '+' || s[0] == '-' || s[0] == '/' || s[0] == '*')) {
        s = s.substr(1);
        return true;
    }
    return false;
}

// P -> I | L | UI | UL | (E)
bool P() {
    if (I() || L()) {
        return true;
    } else if (U()) {
        return I() || L();
    } else if (!s.empty() && s[0] == '(') {
        s = s.substr(1);
        if (E() && !s.empty() && s[0] == ')') {
            s = s.substr(1);
            return true;
        }
        return false;
    }
    return false;
}

 // U -> + | - | !
bool U() {
    if (!s.empty() && (s[0] == '+' || s[0] == '-' || s[0] == '!')) {
        s = s.substr(1);
        return true;
    }
    return false;
}

// I -> C | CI
bool I() {
    if (C()) {
        while (C()) {}
        return true;
    }
    return false;
}

// C -> a | b | ... | y | z
bool C() { 
    if (!s.empty() && 'a' <= s[0] && s[0] <= 'z') {
        s = s.substr(1);
        return true;
    }
    return false;
}

// L -> D | DL
bool L() { 
    if (D()) {
        while (D()) {}
        return true;
    }
    return false;
}

// D -> 0 | 1 | ... | 8 | 9
bool D() { 
    if (!s.empty() && '0' <= s[0] && s[0] <= '9') {
        s = s.substr(1);
        return true;
    }
    return false;
}