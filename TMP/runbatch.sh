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
outdir=/data/alice/mjongerh/alice/data/BatchTest/Job_${JOB_ID}/
mkdir -p ${outdir}

# create temp subfolder
tempfol=/data/alice/mjongerh/alice/data/BatchTest/Job_${JOB_ID}/temp/
mkdir -p ${tempfol}

# cp /scripts into temp folder
cp /data/alice/mjongerh/alice/DelphesO2/examples/scripts/* ${tempfol}

# run job from temp folder + send output to job folder
cd ${tempfol}
echo "Attempting to run job"
eval "alienv setenv DelphesO2/latest-master-o2 -c ./createO2tables.py default_configfile.ini --entry BBBAR_BDforced -l -c --output-path ${outdir} --nruns 1 --njobs 1 --nevents 5000"
echo "Attempt done"

# once done, delete temp folder
cd ${outdir}
rm -r ./temp

# job complete


#cd /data/alice/mjongerh/alice/DelphesO2/examples/scripts


#eval "./createO2tables.py default_configfile.ini --entry BBBAR_BDforced -l -c --output-path ${outdir} --nruns 1 --njobs 1 --nevents 500"