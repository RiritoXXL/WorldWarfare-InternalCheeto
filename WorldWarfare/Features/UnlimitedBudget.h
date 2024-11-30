#pragma once
#include "includes.hpp"
typedef unsigned long ulong;
namespace Budget 
{
	unsigned long GetBudget()
	{
		static UnityResolve::Method* method;
		if (!method) method = UnityResolve::Get("WWE.dll")->Get("Countries")->Get<UnityResolve::Method>("get_Budget");
		if (method) return method->Invoke<ulong>();
		return 0;
	}
	void SetBudget(ulong value) {
		static UnityResolve::Method* method;
		if (!method) method = UnityResolve::Get("WWE.dll")->Get("Countries")->Get<UnityResolve::Method>("set_Budget");
		if (method) return method->Invoke<void>(value);
	}
};