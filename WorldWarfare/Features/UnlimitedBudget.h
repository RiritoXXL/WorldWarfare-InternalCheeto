#pragma once
#include <Windows.h>
#include "UnityResolve.hpp"
typedef unsigned long ulong;
namespace Budget 
{
	unsigned long GetBudget()
	{
		try {
			static UnityResolve::Method* method;
			if (!method) method = UnityResolve::Get("WWE.dll")->Get("Countries")->Get<UnityResolve::Method>("get_Budget");
			if (method) return method->Invoke<ulong>();
			return (ulong)0i64;
		}
		catch (std::exception& ex) 
		{
			MessageBoxA(0, ex.what(), "ERROR!!!", MB_OK | MB_ICONERROR);
			int mbox = MessageBoxA(0, "DO YOU WANT TO EXIT THIS GAME???", "ERROR!!!", MB_YESNO | MB_ICONERROR);
			if (mbox == IDYES) {
				ExitProcess(343);
			}
			else {
				ExitProcess(1554);
			}
		}
	}
	void SetBudget(ulong value) 
	{
		try {
			static UnityResolve::Method* method;
			if (!method) method = UnityResolve::Get("WWE.dll")->Get("Countries")->Get<UnityResolve::Method>("set_Budget");
			if (method) return method->Invoke<void>(value);
		}
		catch (std::exception& ex) {
			MessageBoxA(0, ex.what(), "ERROR!!!", MB_OK | MB_ICONERROR);
		}
	}
};
