// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include "includes.hpp"
DWORD WINAPI ThreadCheeto(HMODULE hMod) {
	bool init_hook = false;
	CreateConsole();
	I::Init(GetModuleHandleW((LPCWSTR)L"mono-2.0-bdwgc.dll"), I::Mode::Mono);
	I::ThreadAttach();
	cout << "Mono is Now Successfully Attached to Current Game!!!" << endl;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
			cout << "Kiero is Initializated!!!" << endl;
		}
		else {
			cout << "Kiero is not Initializated" << endl;
			Sleep(4500);
			exit(122);
		}
	} while (!init_hook);
    return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ThreadCheeto, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

