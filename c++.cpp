#include <Windows.h>
#include <iostream>

// Definições dos tipos das funções não documentadas
typedef NTSTATUS (NTAPI *RtlAdjustPrivilegeFunc)(
    ULONG Privilege,
    BOOLEAN Enable,
    BOOLEAN CurrentThread,
    PBOOLEAN Enabled);

typedef NTSTATUS (NTAPI *NtRaiseHardErrorFunc)(
    NTSTATUS ErrorStatus,
    ULONG NumberOfParameters,
    ULONG UnicodeStringParameterMask,
    PULONG_PTR Parameters,
    ULONG ValidResponseOption,
    PULONG Response);

// Função que invoca o BSOD
void InvokeBSOD()
{
    HMODULE ntdll = LoadLibraryW(L"ntdll.dll");
    if (!ntdll) {
        std::cerr << "Erro ao carregar ntdll.dll\n";
        return;
    }

    auto RtlAdjustPrivilege = (RtlAdjustPrivilegeFunc)GetProcAddress(ntdll, "RtlAdjustPrivilege");
    auto NtRaiseHardError = (NtRaiseHardErrorFunc)GetProcAddress(ntdll, "NtRaiseHardError");

    if (!RtlAdjustPrivilege || !NtRaiseHardError) {
        std::cerr << "Erro ao obter funções nativas\n";
        FreeLibrary(ntdll);
        return;
    }

    BOOLEAN prevState = FALSE;
    ULONG response = 0;

    // Habilita o privilégio SeShutdownPrivilege (19)
    NTSTATUS status = RtlAdjustPrivilege(19, TRUE, FALSE, &prevState);
    if (status != 0) {
        std::cerr << "Falha ao ajustar privilégio\n";
        FreeLibrary(ntdll);
        return;
    }

    // Dispara o BSOD
    status = NtRaiseHardError(0xC0000022, 0, 0, nullptr, 6, &response);

    // Normalmente, se o BSOD for acionado, o processo não continua daqui

    FreeLibrary(ntdll);
}
