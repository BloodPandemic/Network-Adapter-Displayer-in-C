# Network-Adapter-Displayer-in-C
Just a Simple C Script to Display your current network adapters and the corresponding IP's 

build it with

```
gcc -o netAdp net_Adp.c
./netAdp
```
if you want to make it a terminal command where u would want to constantly call this you can do this:
1) create a folder where you keep your scripts (for the sake of explanation i'll suppose u have a folder named ~/scripts
2) `sudo vim ~/.bashrc`
3) add the following line at the end `export PATH=$PATH:~/scripts` where ~/scripts is the folder u will keep your scripts
4) move your built ELF executable into that folder and , `chmod +x netAdp` 
5) run `source ~/.bashrc` to reload the configuration file

no go to any location on the shell and try it out



#### you can also automate this process with the autoMate.sh script 
just `chmod +x autoMate.sh && ./autoMate.sh`

