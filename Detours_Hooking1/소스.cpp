#include <stdio.h>
#include <Windows.h>
#include "C:\\Users\\root\\Desktop\\Reversing\\Detours-master\\include\\detours.h"

#pragma comment(lib, "C:\\Users\\root\\Desktop\\Reversing\\Detours-master\\lib.X86\\detours.lib")

void targetFunction()
{
	printf("타겟 함수\n");
}

void (*mytargetFunction)() = targetFunction;

void hookingFunction()
{
	printf("함수 가로채기\n");
}

int main()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourSetIgnoreTooSmall(TRUE);

	DetourAttach((PVOID*)&mytargetFunction, hookingFunction);

	DetourTransactionCommit();
	targetFunction();

	return 0;
}