#include <iostream>
#include <Windows.h>
#include <string>


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "args ERROR" << std::endl;
        std::cout << "Optional {hid, vis, del}" << std::endl;
        return 0;
    }
    HWND WINDOW_HANDLE = nullptr;
    if (std::string(argv[2]) == "@")
    {
        WINDOW_HANDLE = GetConsoleWindow();
    }
    else
    {
        WINDOW_HANDLE = FindWindow(nullptr, TEXT(argv[2]));
    }
    if (WINDOW_HANDLE != nullptr)
    {
        std::cout << "Window \"" << argv[2] << "\" FOUND" << std::endl;
        if (std::string(argv[1]) == "hid")
        {
            ShowWindow(WINDOW_HANDLE, SW_HIDE);
            std::cout << "HIDDEN" << std::endl;
        }
        else if (std::string(argv[1]) == "vis")
        {
            ShowWindow(WINDOW_HANDLE, SW_SHOW);
            std::cout << "VISION" << std::endl;
        }
        else if (std::string(argv[1]) == "del")
        {
            DWORD pid;
            GetWindowThreadProcessId(WINDOW_HANDLE, &pid);
            HANDLE hProcess;

            hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
            if (hProcess) {
                hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
                if (hProcess == nullptr)
                {
                    ;
                }
                else if(!TerminateProcess(hProcess, 1)) {
                    CloseHandle(hProcess);
                }
                else
                {
                    CloseHandle(hProcess);
                }
            }
            std::cout << "TERMINATED" << std::endl;
        }
        else
        {
            std::cout << "cmd ERROR, got " << argv[1] << std::endl;
            std::cout << "Optional {hid, vis, del}" << std::endl;
        }
    }
    else
    {
        std::cout << "Window \"" << argv[2] << "\" NOT FOUND" << std::endl;
    }
    return 0;
}
