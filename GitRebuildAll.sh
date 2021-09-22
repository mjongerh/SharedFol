cd /data/alice/mjongerh/alice
aliBuild build AliPhysics --defaults o2
aliBuild build O2 --defaults o2 --disable DebugGUI
aliBuild build O2Physics --defaults o2
aliBuild clean
cd /data/alice/mjongerh/alice/SharedFol
