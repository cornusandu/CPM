#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>   // for system()
#include <cstring>   // for strcpy

namespace fs = std::filesystem;

char* downloadFile(char* filename) {
    std::string fileNameStr(filename);
    std::string remoteUrl = "https://raw.githubusercontent.com/cornusandu/CPM/main/packages/" 
                            + fileNameStr + ".cso";
    std::string localDir = "./tmp";
    std::string localPath = localDir + "/" + fileNameStr + ".cso";

    // Ensure ./tmp directory exists
    if (!fs::exists(localDir))
        fs::create_directories(localDir);

    // Build the shell command: works cross-platform (Windows, Linux, macOS)
#ifdef _WIN32
    std::string command = "curl -L -o \"" + localPath + "\" \"" + remoteUrl + "\" >nul 2>&1";
#else
    std::string command = "curl -L -o \"" + localPath + "\" \"" + remoteUrl + "\" >/dev/null 2>&1";
#endif

    int result = std::system(command.c_str());
    if (result != 0) {
        std::cerr << "Error: failed to download " << remoteUrl << "\n";
        return nullptr;
    }

    // Return the local path
    char* resultPath = new char[localPath.size() + 1];
    std::strcpy(resultPath, localPath.c_str());
    return resultPath;
}