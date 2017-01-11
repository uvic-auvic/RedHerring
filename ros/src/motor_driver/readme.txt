Kyle Jordan
motor driver node is on the svn under RedHerring
mostly untested apart from some basic virtual serial back-and-forth
not much error checking, so don't give it bad data. If that ends up being a problem I can go back and add some in
general format of its service call follows Andy's motor driver interface pretty closely
https://engrauvic.engr.uvic.ca/wiki/doku.php?id=elec:motor_driver&s[]=motor&s[]=driver
service call parameters are:
command: the alphabetical characters of the command
motor: the target motor
param: a one byte parameter
it echos back those values in its response, as well as a char (boolean) success flag and a string containing any response it got back from the driver
so for example, the equivalent of Andy's  M5F20 command would be
command = "MF"
motor = 5
param = 20
and response would be an empty string
CL2 would be:
command: "CL"
param: [anything]
motor: 2
response: "GOOD" (if that's what the driver sends back)
unused parameters (like param and motor for some commands) are just ignored
shouldn't be too difficult to set up; it's mainly just a ros wrapper over Andy's interface
I'm a bit uncertain about RVX's response size, so right now it might cause a 1 sec delay while it waits for a longer response, I can fix it pretty easily once I know the exact response size (it's just an int hardcoded into the source)
when you go to run it, just give it the port (/dev/???) and baud rate you want it to use. client_node is just there if you need to interface through a terminal for whatever reason, just passes the arguments you give it to that service
