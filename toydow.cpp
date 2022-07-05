#include <iostream>
#include <Windows.h>
#include <string>
#include <map>

#define HID 0
#define VIS 1
#define DEL 2
#define HID_WAIT 10
#define VIS_WAIT 11
#define DEL_WAIT 12
#define HID_KEEP 20
#define VIS_KEEP 21
#define DEL_KEEP 22


std::map<std::string, int> operations = {
        {std::string("hid"), HID},
        {std::string("vis"), VIS},
        {std::string("del"), DEL},
        {std::string("hid-w"), HID_WAIT},
        {std::string("vis-w"), VIS_WAIT},
        {std::string("del-w"), DEL_WAIT},
        {std::string("hid-k"), HID_KEEP},
        {std::string("vis-k"), VIS_KEEP},
        {std::string("del-k"), DEL_KEEP},
};

HWND get_handle(char* window_name)
{
    HWND WINDOW_HANDLE = nullptr;
    if (std::string(window_name) == "@")
    {
        WINDOW_HANDLE = GetConsoleWindow();
    }
    else
    {
        WINDOW_HANDLE = FindWindow(nullptr, TEXT(window_name));
    }
    return WINDOW_HANDLE;
}


void run_hid(char* window_name)
{
    HWND WINDOW_HANDLE = get_handle(window_name);
    if (WINDOW_HANDLE == nullptr)
    {
        std::cout << "Window \"" << window_name << "\" NOT FOUND" << std::endl;
        exit(300);
    }
    else
    {
        std::cout << "Window \"" << window_name << "\" FOUND" << std::endl;
    }
    ShowWindow(WINDOW_HANDLE, SW_HIDE);
    std::cout << "HIDDEN" << std::endl;
}

void run_vis(char* window_name)
{
    HWND WINDOW_HANDLE = get_handle(window_name);
    if (WINDOW_HANDLE == nullptr)
    {
        std::cout << "Window \"" << window_name << "\" NOT FOUND" << std::endl;
        exit(300);
    }
    else
    {
        std::cout << "Window \"" << window_name << "\" FOUND" << std::endl;
    }
    ShowWindow(WINDOW_HANDLE, SW_SHOW);
    std::cout << "VISION" << std::endl;
}

void run_del(char* window_name)
{
    HWND WINDOW_HANDLE = get_handle(window_name);
    if (WINDOW_HANDLE == nullptr)
    {
        std::cout << "Window \"" << window_name << "\" NOT FOUND" << std::endl;
        exit(300);
    }
    else
    {
        std::cout << "Window \"" << window_name << "\" FOUND" << std::endl;
    }
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
        else if(!TerminateProcess(hProcess, 1))
        {
            CloseHandle(hProcess);
        }
        else
        {
            CloseHandle(hProcess);
        }
    }
    std::cout << "TERMINATED" << std::endl;
}

void run_hid_wait(char* window_name)
{
    HWND WINDOW_HANDLE = nullptr;
    std::cout << "Wait for window \"" << window_name << "\" ..." << std::endl;
    while(!WINDOW_HANDLE)
    {
        WINDOW_HANDLE = get_handle(window_name);
    }
    std::cout << "Window \"" << window_name << "\" FOUND" << std::endl;
    ShowWindow(WINDOW_HANDLE, SW_HIDE);
    std::cout << "HIDDEN" << std::endl;
}

void run_vis_wait(char* window_name)
{
    HWND WINDOW_HANDLE = nullptr;
    std::cout << "Wait for window \"" << window_name << "\" ..." << std::endl;
    while(!WINDOW_HANDLE)
    {
        WINDOW_HANDLE = get_handle(window_name);
    }
    std::cout << "Window \"" << window_name << "\" FOUND" << std::endl;
    ShowWindow(WINDOW_HANDLE, SW_SHOW);
    std::cout << "VISION" << std::endl;
}

void run_del_wait(char* window_name)
{
    HWND WINDOW_HANDLE = nullptr;
    std::cout << "Wait for window \"" << window_name << "\" ..." << std::endl;
    while(!WINDOW_HANDLE)
    {
        WINDOW_HANDLE = get_handle(window_name);
    }
    std::cout << "Window \"" << window_name << "\" FOUND" << std::endl;
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
        else if(!TerminateProcess(hProcess, 1))
        {
            CloseHandle(hProcess);
        }
        else
        {
            CloseHandle(hProcess);
        }
    }
    std::cout << "TERMINATED" << std::endl;
}

void run_hid_keep(char* window_name)
{
    std::cout << "Keep hiding window \"" << window_name << "\" ..." << std::endl;
    while(1)
    {
        run_hid_wait(window_name);
    }
}

void run_vis_keep(char* window_name)
{
    std::cout << "Keep visualizing window \"" << window_name << "\" ..." << std::endl;
    while(1)
    {
        run_vis_wait(window_name);
    }
}

void run_del_keep(char* window_name)
{
    std::cout << "Keep killing window \"" << window_name << "\" ..." << std::endl;
    while(1)
    {
        run_del_wait(window_name);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "number of parameters ERROR" << std::endl;
        exit(100);
    }
    // Operations
    switch(operations[std::string(argv[1])])
    {
        case HID:
            run_hid(argv[2]); break;
        case VIS:
            run_vis(argv[2]); break;
        case DEL:
            run_del(argv[2]); break;
        case HID_WAIT:
            run_hid_wait(argv[2]); break;
        case VIS_WAIT:
            run_vis_wait(argv[2]); break;
        case DEL_WAIT:
            run_del_wait(argv[2]); break;
        case HID_KEEP:
            run_hid_keep(argv[2]); break;
        case VIS_KEEP:
            run_vis_keep(argv[2]); break;
        case DEL_KEEP:
            run_del_keep(argv[2]); break;
        default:
            std::cout << "operation ERROR, got " << argv[1] << std::endl;
            std::cout << "Optional {hid, vis, del [-w|-k]}" << std::endl;
            exit(200);
    }

    return 0;
}
