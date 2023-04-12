# import libs
import re
import json
import os
from datetime import datetime


###
### SET DEFAULTS
###

os.system('lsblk')

# default device name
defaultDevice = 'mmcblk0p1'

# if mounted device is under another name
deviceNamePrompt = input("write if device name is not the default" + "default: "
                         + defaultDevice + "... ")

if deviceNamePrompt == '':
    defaultDevice = defaultDevice
else:
    defaultDevice = deviceNamePrompt

# set default mount point
defaultMountPoint = 'drive'

# if mount point is under another name
mountPoint = input("write if mount point is not the default" + "default: " +
                   defaultMountPoint + "... ")

if mountPoint == '':
    defaultMountPoint = defaultMountPoint
else:
    defaultMountPoint = mountPoint

# this variable is re-defined when later on when microsd is opened
animalNumber = '000'



###
### IMPORTANT COMMANDS
###

# get home variable
home = os.environ['HOME']

# show connected devices
showDevices = 'lsblk'

# create dir for raw data storage
createDirectory = 'mkdir -p ../raw_data/' + animalNumber

# show mounted devices in dev
mountDevices = 'sudo mount /dev/' + defaultDevice + ' ~/drive'

# list all files in the mounted drive
lsMountDevices = 'ls ~/drive'

# show experimental configuration
lsExperimental = 'cat ~/drive/config.txt'





print('Selected device name is: ' + defaultDevice)

# later on implement a selection prompt
# mmcblk0p1 corresponds to the micro sd adapter
mountPrompt = input("Code to run  " + mountDevices + "(y/n) : ")

if mountPrompt == 'y':
    os.system(mountDevices)
    print("### LISTING FILES BELOW ###")
    os.system(lsMountDevices)
    print("### EXPERIMENTAL PARAMETERS ###")
    os.system(lsExperimental)
    # load json file
    f = open(home + '/drive/config.txt').read()
    pattern = re.compile("[0-9]{3}")
    animalNumber = pattern.search(f)[0]
    # animal number
    print(animalNumber)
    # create folder based on animal name if it does not exists
    os.system(createDirectory)
    # copy animal data .CSV into the folder
    copyCSV = 'sudo cp ~/drive/' + animalNumber + '.CSV' + ' ../raw_data/' + animalNumber + '/'
    os.system(copyCSV)
    # git add file
    gitAdd = 'git add ../raw_data/' + animalNumber + '/'
    os.system(gitAdd)
    # create commit
    now = datetime.now()
    now = now.strftime("%m/%d/%Y, %H:%M:%S")
    createCommit = 'git commit -m "' + now + ' ' + animalNumber + '"'
    os.system(createCommit)
    # unmount micro sd
    unmountSd = 'sudo umount /dev/mmcblk0p1'
    os.system(unmountSd)
else:
    print(":c")
    exit(0)
