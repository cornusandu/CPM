#include <iostream>
#include <windows.h>

void install(char* name) {
    HMODULE module = LoadLibraryA("./install.dll");
    auto _install = GetProcAddress(module, 'install');

    char* install_path = _install(name);
}

int main(size_t argc, char* argv[]) {

    if (argc == 3) {
        if (*argv[1] == 'install') {
            install(argv[2]);
        }
    }
}