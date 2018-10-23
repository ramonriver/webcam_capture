# webcam_capture
Just webcam capture

## Tips
https://wiki.archlinux.org/index.php/webcam_setup

http://www.linuxintro.org/wiki/Set_up_a_Webcam_with_Linux

### Instructions
Firstly, install **OpenCV** in case you do not have it:

```sudo apt-get install libopencv-dev```

To copy the repository to your account, you need to be logged in GitHub.

Then *fork* this repository by clicking to the "**Fork**" button at the right top of the GitHub page.

Once you have done it, you will have a copy of the *webcam_capture* repository in your account.

Now, clone it to your local machine:

```git clone https://github.com/user_name/webcam_capture.git```

Make a **Build** directory where to build the project:
```
mkdir build && cd build
cmake ..
make
```


You are ready to run the software:

```./webcam_capture```

And your webcam does the job :+1:
