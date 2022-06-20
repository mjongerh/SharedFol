#!/bin/bash
export ALIBUILD_WORK_DIR="/data/alice/mjongerh/alice/sw"
eval "`alienv shell-helper`"
#source /data/alice/mjongerh/alice/sw
#cd /data/alice/mjongerh/alice

#eval "alienv printenv DelphesO2/latest-master-o2"
#eval "alienv printenv VO_ALICE@DelphesO2::v20210929-1, VO_ALICE@O2::v21.14-1"
#alienv enter DelphesO2/latest-master-o2

echo ${TMPDIR}
echo ${PBS_O_WORKDIR}

# create job folder
JOB_ID=$(echo $PBS_JOBID | cut -d'.' -f 1)
#outdir=/data/alice/mjongerh/alice/data/pp14TeV_bbbar_50M_2T/Job_${JOB_ID}/
outdir=/data/alice/mjongerh/alice/data/Lb_BRtest/Job_${JOB_ID}/
mkdir -p ${outdir}

# create temp subfolder
tempfol=/data/alice/mjongerh/alice/data/pp14TeV_bbbar_50M_2T/Job_${JOB_ID}/temp/
mkdir -p ${tempfol}

# cp /scripts into temp folder
cp /data/alice/mjongerh/alice/DelphesO2/examples/scripts/* ${tempfol}

# run job from temp folder + send output to job folder
cd ${tempfol}
echo "Attempting to run job"
eval "alienv setenv DelphesO2/latest-master-o2 -c ./createO2tables.py default_configfile.ini --entry BBBAR_BDforced -l -c --output-path ${outdir} --nruns 20 --njobs 1 --nevents 5000"
echo "Attempt 1 done"
SleepTimer=$(expr ${JOB_ID} % 17 + 3)
if [ ! -f ../AODRun5.0.root ]; then 
        echo "Failed, trying again"
        sleep ${SleepTimer}
        eval "alienv setenv DelphesO2/latest-master-o2 -c ./createO2tables.py default_configfile.ini --entry BBBAR_BDforced -l -c --output-path ${outdir} --nruns 20 --njobs 1 --nevents 5000"
fi 
if [ ! -f ../AODRun5.0.root ]; then 
        echo "Failed yet again. Third time's the charm" 
        sleep ${SleepTimer}
        eval "alienv setenv DelphesO2/latest-master-o2 -c ./createO2tables.py default_configfile.ini --entry BBBAR_BDforced -l -c --output-path ${outdir} --nruns 20 --njobs 1 --nevents 5000" 
fi 
if [ ! -f ../AODRun5.0.root ]; then 
        echo "Failed yet again. Fourth time's the charm" 
        sleep ${SleepTimer}
        eval "alienv setenv DelphesO2/latest-master-o2 -c ./createO2tables.py default_configfile.ini --entry BBBAR_BDforced -l -c --output-path ${outdir} --nruns 20 --njobs 1 --nevents 5000" 
fi 
if [ ! -f ../AODRun5.0.root ]; then 
        echo "Forget it. Clean tree output up, this is bogus, sorry" 
fi 

# once done, delete temp folder
echo "cleaning temp folder"
cd ${outdir}
rm -r ./temp

# job complete
echo "Job complete"

#cd /data/alice/mjongerh/alice/DelphesO2/examples/scripts


#eval "./createO2tables.py default_configfile.ini --entry BBBAR_BDforced -l -c --output-path ${outdir} --nruns 1 --njobs 1 --nevents 500"
