#include <windows.h>
#include <iostream>

int main(void)
{

	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi = {0};

	if (!CreateProcessW(L"C:\\Windows\\notepad.exe",
		NULL,
		NULL,
		NULL,
		FALSE,
		BELOW_NORMAL_PRIORITY_CLASS,
		NULL,
		NULL,
		&si,
		&pi)) 
	{

		printf("(-) failed to create process, error: %ld", GetLastError());
		return EXIT_FAILURE;
	}
	printf("(+) Process started! pid: %ld", pi.dwProcessId);

	if(OpenProcess(PROCESS_VM_READ, TRUE, -11)) printf("\nAccess granted"); // -1 for safety

	return EXIT_SUCCESS;
}