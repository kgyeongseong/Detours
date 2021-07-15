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
	// DetourTransactionBegin() : 후킹 또는 후킹 해제하기 위한 준비를 하는 함수입니다.
	DetourTransactionBegin();
	// DetourUpdateThread() : 현재 프로세스의 스레드 핸들을 얻어서 업데이트
	DetourUpdateThread(GetCurrentThread());
	DetourSetIgnoreTooSmall(TRUE);
	// DetourAttach() : Detours 후킹이 실행되는 함수입니다.
	DetourAttach((PVOID*)&mytargetFunction, hookingFunction);

	DetourTransactionCommit();
	targetFunction();

	return 0;
}