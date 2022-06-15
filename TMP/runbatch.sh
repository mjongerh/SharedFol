#!/bin/bash
#export ALIBUILD_WORK_DIR="/data/alice/mjongerh/alice/sw"
source /data/alice/mjongerh/alice/sw
eval $(DelphesO2/latest-master-o2)
cd /data/alice/mjongerh/alice/DelphesO2/examples/scripts
echo ${TMPDIR}
echo ${PBS_O_WORKDIR}

outdir=${PBS_O_WORKDIR}/job_${PBS_ARRAYID}

mkdir -p ${outdir}

./createO2tables.py default_configfile.ini --entry BBBAR_BDforced -l -c --output-path /data/alice/mjongerh/alice/data/BBbar_test//job_${PBS_ARRAYID} --nruns 1 --njobs 1 --nevents 500
echo "Doing master cleanup"

echo "Anything left?" 
ls
echo "Done! Enjoy!"