import re


raw = """33 C9             xor     ecx, ecx
tlopo.exe:00007FF6838F4FB3 48 89 48 50       mov     [rax+50h], rcx
tlopo.exe:00007FF6838F4FB7 48 FF 45 00       inc     qword ptr [rbp+0]
tlopo.exe:00007FF6838F4FBB 48 89 68 10       mov     [rax+10h], rbp
tlopo.exe:00007FF6838F4FBF 48 FF 06          inc     qword ptr [rsi]
tlopo.exe:00007FF6838F4FC2 48 89 70 18       mov     [rax+18h], rsi
tlopo.exe:00007FF6838F4FC6 48 8B 45 50       mov     rax, [rbp+50h]
tlopo.exe:00007FF6838F4FCA 48 89 43 40       mov     [rbx+40h], rax
tlopo.exe:00007FF6838F4FCE 48 FF 00"""

matches = re.findall(r'([0-9A-F]{2})[ \n\+]{1}', raw)


for match in matches:
	print(f"0x{match}, ", end="")


	