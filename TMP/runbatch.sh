#!/bin/bash
export ALIBUILD_WORK_DIR="/data/alice/mjongerh/alice/sw"
eval "`alienv shell-helper`"
#source /data/alice/mjongerh/alice/sw
#cd /data/alice/mjongerh/alice

#eval "alienv printenv DelphesO2/latest-master-o2"
#eval "alienv printenv VO_ALICE@DelphesO2::v20210929-1, VO_ALICE@O2::v21.14-1"
#alienv enter DelphesO2/latest-master-o2
cd /data/alice/mjongerh/alice/DelphesO2/examples/scripts

echo ${TMPDIR}
echo ${PBS_O_WORKDIR}

outdir=${PBS_O_WORKDIR}/job_${PBS_ARRAYID}

mkdir -p ${outdir}
echo "Attempting to run job"
eval "alienv setenv DelphesO2/latest-master-o2 -c ./createO2tables.py default_configfile.ini --entry BBBAR_BDforced -l -c --output-path ${outdir} --nruns 10 --njobs 1 --nevents 500"
echo "Attempt done"
#eval "./createO2tables.py default_configfile.ini --entry BBBAR_BDforced -l -c --output-path ${outdir} --nruns 1 --njobs 1 --nevents 500"
