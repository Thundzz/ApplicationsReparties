# In order to install MPJ :
* Download from the website.
* Extract somewhere. (In my case I did extract it in /home/USERNAME/vendor/)
* Add following exports to .bashrc:

> export MPJ_HOME="/home/USERNAME/vendor/mpj-v0_43" # Add Env var for MPJ
> export PATH="$MPJ_HOME/bin:$PATH" # Add MPJ to path

* Compile HelloWorld using:

> make

* Run using:

> mpjrun.sh -np 4 HelloWorld
