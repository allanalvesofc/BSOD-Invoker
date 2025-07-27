---

# BSOD Invoker

Este projeto contém implementações em **C++** e **VB.NET** de uma função que força a ocorrência do Blue Screen of Death (BSOD) no Windows, utilizando chamadas nativas do sistema.

> ⚠️ **Aviso importante:**
> Esta função força um crash crítico no sistema operacional, causando perda de dados não salvos e reinicialização imediata do computador. Use somente para fins educacionais e em ambientes controlados.

---

## Funcionalidades

* Habilita o privilégio necessário (`SeShutdownPrivilege`) para disparar o BSOD.
* Chama a função nativa `NtRaiseHardError` para forçar o erro crítico.
* Implementação nas linguagens C++ e VB.NET.

---

## Como usar

### C++

1. Compile o arquivo `InvokeBSOD.cpp` usando um compilador compatível (Visual Studio, MinGW, etc).
2. Execute o programa (não precisa de adm)
3. A função `InvokeBSOD()` irá causar o BSOD.

### VB.NET

1. Adicione o código da função `InvokeBSOD()` no seu projeto VB.NET.
2. Execute o programa (não precisa de adm)
3. Chame `InvokeBSOD()` para disparar o BSOD.

---

## Código exemplo

### C++

```cpp
// Código completo disponível no arquivo InvokeBSOD.cpp
void InvokeBSOD()
{
    // implementação conforme descrita
}
```

### VB.NET

```vbnet
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
```

---

## Requisitos

* Sistema operacional Windows.
* Permissões administrativas para que a função funcione corretamente.
* Para a versão C++, o compilador deve suportar chamadas às APIs do Windows.
* Para VB.NET, ambiente .NET Framework compatível.

---

## Licença

Este projeto está licenciado sob a licença MIT. Sinta-se à vontade para usar e modificar o código conforme necessário, mas **use com responsabilidade**.

---

## Aviso Legal

Este código pode causar perda de dados e falhas no sistema. Use somente para fins educativos e em máquinas de teste. Não nos responsabilizamos por danos causados pelo uso indevido.

---
